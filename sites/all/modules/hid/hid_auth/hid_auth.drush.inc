<?php

/**
 * @file
 * hid_auth module Drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hid_auth_drush_command() {
  $items = array();

  $items['hid-auth-migrate-users'] = array(
    'description' => "Migrate Drupal users to the Humanitarian ID Auth system.",
    'drupal dependencies' => array('restclient'),
  );

  return $items;
}

/**
 * Drush command callback for 'hid-auth-migrate-users'.
 */
function drush_hid_auth_migrate_users() {
  // Load all active users who are not linked to an HID auth account.
  $result = db_query("SELECT u.uid, u.mail FROM users u LEFT JOIN authmap am ON u.uid = am.uid WHERE u.status = 1 AND (am.aid IS NULL OR SUBSTRING(am.authname, 0, 26) = 'oauthconnector_hid_oauth__') ORDER BY u.uid");
  foreach ($result as $rec) {
    // Load profile
    $profile = profile2_load_by_user($rec->uid, 'main');
    $name_first = !empty($profile->field_first_name[LANGUAGE_NONE][0]['value']) ? trim($profile->field_first_name[LANGUAGE_NONE][0]['value']) : '';
    $name_last = !empty($profile->field_last_name[LANGUAGE_NONE][0]['value']) ? trim($profile->field_last_name[LANGUAGE_NONE][0]['value']) : '';

    // Send user register request to API.
    $hid_user = hid_auth_register_user($rec->mail, $name_first, $name_last);
    if (!empty($hid_user['user_id'])) {
      // If an auth system user ID is given, link the Drupal user to this ID.
      $rv = _connector_add_connection('oauthconnector_hid_oauth', $hid_user['user_id'], $rec->uid);
      if (!empty($rv)) {
        drush_log('Successfully registered Drupal user ' . $rec->mail . ' (uid ' . $rec->uid . ') as auth user ' . $hid_user['user_id'] . ' and linked accounts.', 'success');
      }
      else {
        drush_log('Successfully registered Drupal user ' . $rec->mail . ' (uid ' . $rec->uid . ') as auth user ' . $hid_user['user_id'] . ', but could not link accounts.', 'error');
      }
    }
    else {
      drush_log('Could not register Drupal user ' . $rec->mail . ' (uid ' . $rec->uid . ') as auth user', 'error');
    }

    // Sleep for one-quarter of a second to limit rate of API calls.
    usleep(250000);
  }
  drush_log('Finished migrating all users', 'notice');
}
