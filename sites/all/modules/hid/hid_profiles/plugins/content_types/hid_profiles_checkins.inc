<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('HID Check-ins'),
  'description' => t('Shows the contact lists the current user is checked into.'),
  'category' => t('Humanitarian ID'),
  'edit form' => 'hid_profiles_checkins_edit_form',
  'render callback' => 'hid_profiles_checkins_render',
  'defaults' => array(
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hid_profiles_checkins_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hid_profiles_checkins_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hid_profiles_checkins_render($subtype, $conf, $panel_args, $context = NULL) {
  global $user;
  $block = new stdClass();
  $block->title = t('Humanitarian ID check-ins');
  $block->content = t('You have not checked in through Humanitarian ID yet.');

  $cid = _hid_profiles_get_cid_by_uid($user->uid);

  if (!empty($cid)) {
    $data = _hid_profiles_get_user_by_cid($cid);
    if (!empty($data->contacts)) {
      $locals = array();
      foreach ($data->contacts as $contact) {
        if ($contact->{'type'} == 'local' && $contact->status == 1) {
          $locals[] = $contact;
        }
      }
      if (!empty($locals)) {
        $headers = array(
          'Contact list',
          'Operations'
        );
        $rows = array();
        foreach ($locals as $local) {
          $nid = str_replace('hrinfo:', '', $local->locationId);
          $link = l($local->location, 'node/'.$nid.'/hid_contacts');
          $edit = l('Edit', variable_get('hid_profiles_app_url', NULL).'/#/profile/'.$local->{'_id'});
          $checkout = l('Checkout', 'hid/checkout/'.$local->{'_id'});
          
          $cell = array($link, $edit.' - '.$checkout);
          $rows[] = $cell;
        }
        $table = array('header' => $headers, 'rows' => $rows, 'attributes' => array());
        $block->content = theme_table($table);
      }
    }
  }  

  return $block;
}
