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

/**
 * Migrate v1 contacts to v2
 */
function drush_hid_profiles_migrate_v1() {
  $results = db_select('field_data_field_hid_contact_ref', 'f')
    ->fields('f')
    ->execute();
  while ($record = $results->fetchAssoc()) {
    $v1_id = $record['field_hid_contact_ref_cid'];
    $contact = hid_profiles_get_contact_by_id($v1_id, array(), 1);
    $userid = $contact->_profile ? $contact->_profile->userid : '';
    if ($userid) {
      $contact = hid_profiles_v2_get_contact(array('user_id' => $userid));
      if ($contact) {
        $v2_id = $contact->_id;
        db_update('field_data_field_hid_contact_ref')
          ->fields(array(
            'field_hid_contact_ref_cid' => $v2_id
          ))
          ->condition('field_hid_contact_ref_cid', $v1_id)
          ->execute();
          echo "Updated ".$v2_id."\n";
      }
    }
    else {
      echo "Could not find ".$v1_id."\n";
    }
  }
}
