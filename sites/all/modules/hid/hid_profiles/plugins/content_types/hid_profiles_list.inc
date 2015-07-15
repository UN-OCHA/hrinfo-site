<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('HID Contacts'),
  'description' => t('Display contacts coming from HID in a pane.'),
  'category' => t('Humanitarian ID'),
  'edit form' => 'hid_profiles_list_edit_form',
  'render callback' => 'hid_profiles_list_render',
  'defaults' => array(
    'gid' => '',
    'contacts' => '',
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
  }

  // Add a wrapper for the contacts and more button.
  $form['contacts_wrapper'] = array(
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix" id="hid-profiles-contacts-wrapper">',
    '#suffix' => '</div>',
  );

  // Container for just the poll choices.
  $form['contacts_wrapper']['contacts'] = array(
    '#prefix' => '<div id="hid-profiles-contacts">',
    '#suffix' => '</div>',
  );

  for ($delta = 0; $delta < $contacts_count; $delta++) {
    $form['contacts_wrapper']['contacts'][$delta] = _hid_profiles_list_form_contact($conf, $delta);
  }

  // We name our button 'hid_profiles_list_more' to avoid conflicts with other modules using
  // Ajax-enabled buttons with the id 'more'.
  $form['contacts_wrapper']['hid_profiles_list_more'] = array(
    '#type' => 'submit',
    '#value' => t('Add another item'),
  );

  return $form;
}

function _hid_profiles_list_form_contact($conf, $delta) {
  $elt = array(
    '#type' => 'textfield',
    '#title' => t('Contact'),
    '#autocomplete_path' => 'hid/autocomplete',
    '#default_value' => $conf['contacts'][$delta],
    '#parents' => array('contacts', $delta),
  );
  return $elt;
}

/**
 * The submit form stores the data in $conf.
 */
function hid_profiles_list_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  if ($form_state['values']['hid_profiles_list_more']) {
    $form_state['contacts_count'] = count($form_state['values']['contacts']) + 1;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hid_profiles_list_render($subtype, $conf, $panel_args, $context = NULL) {
  global $user;
  $block = new stdClass();
  $block->title = t('Contacts');
  $block->content = '';
  foreach ($conf['contacts'] as $cid) {
    if (!empty($cid)) {
      $variables['query'] = array(
        '_id' => $cid,
      );
      $response = hid_profiles_restclient_post('v0/contact/view', $variables);
      if ($response->code === "200") {
        $return_data = json_decode($response->data);
        if ($return_data->{'count'} > 0) {
          $contact = $return_data->{'contacts'}[0];
          $gid = str_replace('hrinfo:', '', $contact->locationId);
          $block->content .= '<address><strong>'.l($contact->nameGiven.' '.$contact->nameFamily, 'node/'.$gid.'/hid_contacts', array('fragment' => 'contact/'.$contact->{'_id'})).'</strong><br />';
          $block->content .= '&nbsp;&nbsp;&nbsp;'.$contact->organization[0]->{'name'}.'<br />';
          $block->content .= '&nbsp;&nbsp;&nbsp;'.$contact->jobtitle.'<br />';
          $block->content .= '&nbsp;&nbsp;&nbsp;'.$contact->email[0]->address.'<br />';
          if (!empty($contact->phone)) {
            foreach ($contact->phone as $phone) {
              $block->content .= '&nbsp;&nbsp;&nbsp;'.$phone->number.' ('.$phone->type.') '.'<br />';
            }
          }
          $block->content .= '</address>';
        }
      }
    }
  }

  return $block;
}
