<?php

/**
 * @file
 * hid_profiles module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hid_profiles_drush_command() {
  $items = array();

  $items['hid-profiles-migrate-v1'] = array(
    'description' => "Migrate v1 contacts to v2",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

function hid_profiles_v2_get_contact($params) {
  $req = hid_profiles_restclient_get('api/v2/user', array(
    'query' => $params,
    'headers' => array(
      'Authorization' => 'Bearer '.variable_get('hid_profiles_v2_api_key', NULL)
    )
  ));
  $contacts = json_decode($req->data);
  return $contacts;
}

/**
 * Migrate v1 contacts to v2
 */
function drush_hid_profiles_migrate_v1() {
  $results = db_select('field_data_field_hid_contact_ref', 'f')
    ->fields('f')
    ->execute();
  while ($record = $results->fetchAssoc()) {
    $contact = hid_profiles_get_contact_by_id($record['field_hid_contact_ref_cid'], array(), 1);
    $userid = $contact->_profile ? $contact->_profile->userid : '';
    if ($userid) {
      $contacts = hid_profiles_v2_get_contact(array('userid' => $userid));
      print_r($contacts);
    }
  }
}
