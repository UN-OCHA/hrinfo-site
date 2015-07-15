<?php

/**
 * Page callback for Humanitarian ID user debug page.
 */
function hid_profiles_user_debug($user) {
  $output = 'No Humanitarian ID Profiles data is found for this user.';

  // Get the Humanitarian ID Profiles API _id value for the user
  $cid = db_query("SELECT cid FROM {hid_profiles} WHERE uid = :uid ", array(':uid' => $user->uid))->fetchField();

  if (!empty($cid)) {
    $data = _hid_profiles_get_user_by_cid($cid);

    $output = "<p>User ID: $cid</p>";
    $output .= '<pre>' . var_export($data, TRUE) . '</pre>';
  }

  return array(
    '#markup' => $output,
  );
}

/**
 * Admin form for managing the system variables associated with this module.
 */
function hid_profiles_settings_form($form, &$form_state) {
  $form['hid_profiles_app_url'] = array(
    '#type' => 'textfield',
    '#title' => t('HID App URL'),
    '#description' => t('The base URL of the Humanitarian ID application.'),
    '#default_value' => variable_get('hid_profiles_app_url', NULL),
    '#required' => TRUE,
  );
  $form['hid_profiles_api_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('API endpoint'),
    '#description' => t('The base URL for endpoints of the Humanitarian ID Profiles API.'),
    '#default_value' => variable_get('hid_profiles_api_endpoint', NULL),
    '#required' => TRUE,
  );
  $form['hid_profiles_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API key'),
    '#description' => t('The machine name of this application as defined in the Humanitarian ID Profiles API.'),
    '#default_value' => variable_get('hid_profiles_api_key', NULL),
    '#required' => TRUE,
  );
  $form['hid_profiles_api_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('API secret'),
    '#description' => t('The secret key provided by the Humanitarian ID Profiles API.'),
    '#default_value' => variable_get('hid_profiles_api_secret', NULL),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}


/**
 * Callback function to return an autocomplete JSON object of matching
 * Organizations.
 *
 * @param string $org_names
 *  A keyword for searching Organization names.
 *
 * @param boolean $extended
 *  Option to return extended information about organizations.
 *
 * @return
 *  JSON output of the matching Organizations array.
 */
function hid_organizations_autocomplete($org_names, $extended = FALSE) {
  $matches = array();

  // Get the vocabulary for the Organizations to limit the term query by VID.
  $vocabulary = taxonomy_vocabulary_machine_name_load('hr_organization');

  // Determine the max number of Organizations to return per request.
  $limit = variable_get('hid_organizations_autocomplete_limit', 30);

  // Limit the query to "begins with" or "contains"
  $contains = variable_get('hid_organizations_autocomplete_true', TRUE);
  $contains_delimiter = ($contains) ? '%' : '';

  // Search for hr_organization taxonomy terms, where the term name or
  // organization field value match the given search string.
  $query = db_select('taxonomy_term_data', 't');
  $query->leftJoin('field_data_field_acronym', 'fdfa', '(t.tid = fdfa.entity_id AND fdfa.entity_type = :fdfa_type)', array(':fdfa_type' => 'taxonomy_term'));
  $query->leftJoin('field_data_field_organization_type', 'fot', 't.tid = fot.entity_id');
  $query->leftJoin('field_data_name_field', 'fnf', 'fot.field_organization_type_target_id = fnf.entity_id');

  $query
    ->fields('t')
    ->fields('fdfa')
    ->fields('fot')
    ->fields('fnf')
    ->condition('t.vid', $vocabulary->vid)
    ->condition('fnf.language', 'en');

  $or = db_or();
  $or->condition('t.name', $contains_delimiter . db_like($org_names) . '%', 'LIKE');
  $or->condition('fdfa.field_acronym_value', $contains_delimiter . db_like($org_names) . '%', 'LIKE');

  $return = $query
    ->condition($or)
    ->range(0, $limit)
    ->execute();

  // add matches to $matches
  foreach ($return as $row) {
    $display_name = $row->name;
    $org_type_id = $row->field_organization_type_target_id;
    $org_type_name = $row->name_field_value;
    if (!empty($row->field_acronym_value)) {
      $display_name .= ' (' . $row->field_acronym_value . ')';
    }
    if ($extended) {
      $matches['hrinfo_org_' . $row->tid] = array(
        'name' => $display_name,
        'org_type_id' => 'hrinfo_org_type_' . $org_type_id,
        'org_type_name' => $org_type_name,
      );
    }
    else {
      $matches['hrinfo_org_' . $row->tid] = $display_name;
    }
  }

  // return for JS
  drupal_add_http_header('Access-Control-Allow-Origin', '*');
  drupal_add_http_header('Access-Control-Allow-Methods', 'GET');
  drupal_json_output($matches);
  drupal_exit();
}

/**
 * Callback function to return an autocomplete JSON object of matching
 * Locations.
 *
 * @return
 *  JSON output of all countries for Locations.
 */
function hid_locations_countries() {
  $countries = array();

  // Get the vocabulary for the Locations to limit the term query by VID.
  $vocabulary = taxonomy_vocabulary_machine_name_load('hr_location');

  // Get the top-level terms for the Location vocabulary.
  $terms = taxonomy_get_tree($vocabulary->vid, 0, 1);

  foreach ($terms as $term) {
    $countries['hrinfo_loc_' . $term->tid] = $term->name;
  }

  // return for JS
  drupal_add_http_header('Access-Control-Allow-Origin', '*');
  drupal_add_http_header('Access-Control-Allow-Methods', 'GET');
  drupal_json_output($countries);
  drupal_exit();
}

/**
 * Callback function to return an autocomplete JSON object of matching
 * Locations.
 *
 * @return
 *  JSON output of all countries for Locations.
 */
function hid_location_country($country) {
  // country.country_id
  // country.name
  // country.regions
  // country.regions.region_id.name
  // country.regions.region_id.cities
  // country.regions.region_id.cities.city_id
  $countries = array(
    'country_id'  => $country->tid,
    'name'        => $country->name,
    'regions'     => array(),
  );

  // Get the vocabulary for the Locations to limit the term query by VID.
  $vocabulary = taxonomy_vocabulary_machine_name_load('hr_location');

  // Get the next 2 levels of terms for the Country term as the parent.
  $terms = taxonomy_get_tree($vocabulary->vid, $country->tid, 2);

  foreach ($terms as $term) {
    if (in_array($country->tid, $term->parents)) {
      if (!isset($countries['regions']['hrinfo_loc_' . $term->tid])) {
        $countries['regions']['hrinfo_loc_' . $term->tid] = array(
          'name' => $term->name,
          'cities' => array(),
        );
      }
    }
    else {
      if (!isset($countries['regions']['hrinfo_loc_' . $term->parents[0]])) {
        $countries['regions']['hrinfo_loc_' . $term->parents[0]] = array(
          'name' => $term->name,
          'cities' => array(),
        );
      }
      $countries['regions']['hrinfo_loc_' . $term->parents[0]]['cities']['hrinfo_loc_' . $term->tid] = $term->name;
    }
  }

  // return for JS
  drupal_add_http_header('Access-Control-Allow-Origin', '*');
  drupal_add_http_header('Access-Control-Allow-Methods', 'GET');
  drupal_json_output($countries);
  drupal_exit();
}

function hid_profiles_load_template($file, $id) {
  $template =  DRUPAL_ROOT . '/' . drupal_get_path('module', 'hid_profiles') . '/templates/'.$file.'.html';
  $template = file_get_contents($template);
  $template_elt = array(
    '#tag' => 'script',
    '#attributes' => array(
      'type' => 'text/template',
      'id' => $id,
    ),
    '#value' => $template,
  );
  drupal_add_html_head($template_elt, 'hid_profiles_'.$file);
}

/**
 * Callback function to display the list of local contacts for a node
 *
 * @param integer Operation Id
 *
 */
function hid_profiles_local_contacts($node) {
  $templates = array(
    'contacts_list_table_row',
    'contacts_view',
  );
  context_set('context', 'hr_space_menu', FALSE);
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/underscore.js/1.8.2/underscore-min.js', array('type' => 'external'));
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/backbone.js/1.1.2/backbone-min.js', array('type' => 'external'));
  drupal_add_library('chosen', 'drupal.chosen');
  drupal_add_library('system', 'ui.autocomplete');
  foreach ($templates as $template) {
    hid_profiles_load_template($template, $template);
  }

  $settings = array(
    'operation_id' => $node->nid,
    'bundle' => '',
  );
  if ($node->type == 'hr_bundle') {
    $settings['bundle'] = $node->title;
    $settings['operation_id'] = _hr_bundles_get_operation($node->nid);
  }

  drupal_add_js(drupal_get_path('module', 'hid_profiles') . '/js/hid_profiles_contacts.js');
  drupal_add_js(array('hid_profiles' => $settings), 'setting');

  $html = '<div class="feed-icon text-right"><div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">
   <i class="fa fa-download"></i> <span class="caret"></span>
 </button>
 <ul class="dropdown-menu">
   <li><a id="contacts-list-pdf" href="#" target="_blank">PDF</a></li>
   <li><a id="contacts-list-csv" href="#" target="_blank">CSV</a></li>
 </ul>
</div>
</div>
<div id="contacts-view">
</div>
<div id="contacts-list">
  <table id="contacts-list-table" class="table table-striped">
    <thead>
    <tr>
      <th>Clusters</th>
      <th>Name</th>
      <th>Email</th>
      <th>Job Title</th>
      <th>Organization</th>
      <th>Location</th>
    </tr>
    </thead>
    <tbody>
    </tbody>
  </table>
  <div class="text-center">
    <ul class="pagination">
      <li class="pager-previous"><a id="previous" href="">Previous</a></li>
      <li class="pager-next"> <a id="next" href="">Next</a></li>
    </ul>
  </div>
</div>
<div id="loading"><p class="text-center lead"><i class="fa fa-spinner fa-pulse"></i> Please wait. Data is loading...</p></div>';

  return $html;
}

/**
 * Callback for hid/checkout
 */
function hid_profiles_checkout($form, &$form_state, $cid) {
  global $user;
  $form['cid'] = array(
    '#type' => 'hidden',
    '#value' => $cid,
  );
  $data = hid_profiles_get_user_data($user->uid);
  $location = '';
  foreach ($data->contacts as $contact) {
    if ($contact->{'_id'} == $cid) {
      $location = $contact->location;
    }
  }
  return confirm_form($form, t('Are you sure you want to checkout of @location ?', array('@location' => $location)), 'check-ins');
}

function hid_profiles_checkout_submit($form, &$form_state) {
  global $user;
  $cid = $form_state['values']['cid'];
  // checkout from cid
  $data = hid_profiles_get_user_data($user->uid);
  $location = '';
  foreach ($data->contacts as $contact) {
    if ($contact->{'_id'} == $cid) {
      $location = $contact->location;
    }
  }
  $params = array(
    '_id' => $cid,
    '_profile' => $data->profile->{'_id'},
    'status' => '0',
  );
  if (_hid_profiles_save_contact($data->profile->userid, $params) != FALSE) {
    drupal_set_message('You have successfully checked out of '.$location);
  }
  else {
    drupal_set_message('There was an error checking you out of '.$location, 'error');
  }
  $form_state['redirect'] = 'check-ins';
}

