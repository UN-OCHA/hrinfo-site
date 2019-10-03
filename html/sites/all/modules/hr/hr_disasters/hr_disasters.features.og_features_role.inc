<?php

/**
 * @file
 * hr_disasters.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_disasters_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_disaster:manager'.
  $roles['node:hr_disaster:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_disaster',
    'name' => 'manager',
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
