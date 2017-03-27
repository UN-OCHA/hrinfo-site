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
  while ($record = $result->fetchAssoc()) {
    $contact = hid_profiles_get_contact_by_id($record['field_hid_contact_ref_cid']);
    print_r($contact);
  }
}
