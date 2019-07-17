<?php
/**
 * @file
 * acc_users.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function acc_users_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_operation:access-editor'.
  $roles['node:hr_operation:access-editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'access-editor',
  );

  // Exported OG Role: 'node:hr_operation:access-manager'.
  $roles['node:hr_operation:access-manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'access-manager',
  );

  return $roles;
}
