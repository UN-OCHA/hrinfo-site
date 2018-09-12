<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('HID Contacts'),
  'description' => t('Display contacts coming from HID in a pane.'),
  'category' => t('Humanitarian ID'),
  'edit form' => 'hid_profiles_list_edit_form',
  'render callback' => 'hid_profiles_list_render',
  'required context' => new ctools_context_required(t('Panelized entity'), 'entity'),
  'defaults' => array(
    'contacts' => array(),
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hid_profiles_list_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  if (isset($form_state['contacts_count'])) {
    $contacts_count = $form_state['contacts_count'];
  }
  else {
    $contacts_count = count($conf['contacts']);
    $contacts_count++;
  }

  // Add a wrapper for the contacts and more button.
  $form['contacts_wrapper'] = array(
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix" id="hid-profiles-contacts-wrapper">',
    '#suffix' => '</div>',
  );

  // Container for the contacts.
  $form['contacts_wrapper']['contacts'] = array(
    '#prefix' => '<div id="hid-profiles-contacts">',
    '#suffix' => '</div>',
  );

  for ($delta = 0; $delta < $contacts_count; $delta++) {
    $form['contacts_wrapper']['contacts'][$delta] = _hid_profiles_list_form_contact($conf, $delta);
  }

  // We name our button 'hid_profiles_list_more' to avoid conflicts with other
  // modules using ajax-enabled buttons with the id 'more'.
  $form['contacts_wrapper']['hid_profiles_list_more'] = array(
    '#type' => 'submit',
    '#value' => t('Add another item'),
  );

  return $form;
}

/**
 * Form to add contacts to the content type.
 */
function _hid_profiles_list_form_contact($conf, $delta) {
  $default_value = '';
  if (!empty($conf['contacts'][$delta])) {
    if (variable_get('hid_profiles_v2', FALSE)) {
      $contact = hid_profiles_get_contact($conf['contacts'][$delta]);
      $default_value = $contact->name." [id: $contact->_id]";
    }
    else {
      if ($contact = hid_profiles_get_contact_by_id($conf['contacts'][$delta])) {
        $location = !empty($contact->location) ? $contact->location : t(
          'Global profile'
        );
        $label = "$contact->nameGiven $contact->nameFamily ($location)";
        $default_value = "$label [id: $contact->_id]";
      }
    }
  }

  $elt = array(
    '#type' => 'textfield',
    '#title' => t('Contact'),
    '#autocomplete_path' => 'hid/autocomplete/local',
    '#default_value' => $default_value,
    '#parents' => array('contacts', $delta),
  );
  return $elt;
}

/**
 * The submit form stores the data in $conf.
 */
function hid_profiles_list_edit_form_submit($form, &$form_state) {
  $contexts = isset($form_state['contexts']) ? $form_state['contexts'] : NULL;

  foreach ($form_state['values']['contacts'] as $key => $contact) {
    preg_match('/\[id: (.+)\]/', $contact, $matches);
    $form_state['conf']['contacts'][$key] = $matches[1];
  }

  if ($form_state['values']['hid_profiles_list_more']) {
    $form_state['contacts_count'] = count($form_state['values']['contacts']) + 1;
  }
  $form_state['rebuild'] = TRUE;

  // Clear the relevant render cache.
  $node = $contexts['panelizer']->data;
  cache_clear_all('hid_contact:' . $node->type . ':' . $node->nid . ':', 'cache', TRUE);
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hid_profiles_list_render($subtype, $conf, $panel_args, $context = NULL) {
  $theme = 'hid_profiles_single_contact';
  if (variable_get('hid_profiles_v2', FALSE)) {
    $theme = 'hid_profiles_single_contact_v2';
  }

  $block = new stdClass();
  $block->title = t('Contacts');
  $block->content = array();
  $settings = array(
    'show_name' => true,
    'show_organization' => true,
    'show_job_title' => true,
    'show_email' => true,
    'show_phone_number' => true
  );

  foreach ($conf['contacts'] as $cid) {
    if (!empty($cid)) {
      if ($contact = hid_profiles_get_contact($cid)) {
        $block->content[$cid] = array(
          '#theme' => $theme,
          '#contact' => $contact,
          '#cache' => array(
            'keys' => array(
              'hid_contact',
              $context->data->type,
              $context->data->nid,
              $cid
            ),
            'bin' => 'cache',
            'expire' => time() + 3600,
            'granularity' => DRUPAL_CACHE_PER_PAGE,
          ),
        );
      }
    }
  }

  return $block;
}
