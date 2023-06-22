<?php
/**
 * @file
 * Adds support for Profile.
 * Supplemental include loaded via usermerge_load_includes().
 */

/**
 * Implements hook_usermerge_actions_supported().
 */
function profile_usermerge_actions_supported() {
  return array(
    'profile' => t('Merging profile data using the new account where it is populated.'),
  );
}

/**
 * Implements hook_usermerge_merge_accounts() on behalf of profile module.
 */
function profile_usermerge_merge_accounts($user_to_delete, $user_to_keep, $review) {
  // retrieve kept-user's user field values
  $result = db_query("SELECT fid FROM {profile_value} WHERE uid = :uid AND VALUE <> ''", array(':uid' => $user_to_keep->uid));
  $kept = array();
  foreach ($result as $record) {
    $kept[] = $record->fid;
  }
  if (!empty($kept)) {
    // Remove profile values for blocked-user that kept-user has.
    db_delete('profile_value')
      ->condition('uid', $user_to_delete->uid)
      ->condition('fid', $kept, 'IN')
      ->execute();
  }

  // Remove empty profile values for kept-user.
  db_delete('profile_value')
    ->condition('uid', $user_to_keep->uid)
    ->condition('VALUE', '')
    ->execute();

  // Change uid.
  db_update('profile_value')
    ->fields(array(
    'uid' => $user_to_keep->uid,
  ))
    ->condition('uid', $user_to_delete->uid)
    ->execute();
}