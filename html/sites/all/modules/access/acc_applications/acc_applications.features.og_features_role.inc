<?php

/**
 * @file
 * acc_applications.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function acc_applications_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_operation:access-manager'.
  $roles['node:hr_operation:access-manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'access-manager',
  );

  // Exported OG Role: 'node:hr_operation:manager'.
  $roles['node:hr_operation:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'manager',
  );

  return $roles;
}
