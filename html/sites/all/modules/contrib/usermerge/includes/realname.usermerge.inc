<?php
/**
 * @file
 * Adds support for Real Name.
 * Supplemental include loaded via usermerge_load_includes().
 *
 */

/**
 * Implements hook_usermerge_account_properties_alter() on behalf of realname.
 * Disables actions on the realname property.
 */
function realname_usermerge_account_properties_alter(&$properties, $user_to_delete, $user_to_keep, $action) {
  $properties['other']['items']['realname']['criterion'] = 'no_merge';
}

/**
 * Implements hook_usermerge_merge_accounts_alter() on behalf of realname.
 * Removes the Real Name, which will be recreated automatically.
 */
function realname_usermerge_merge_accounts_alter($merged_account, $user_to_delete, $user_to_keep) {
  $merged_account['realname'] = NULL;

  return $merged_account;
}
