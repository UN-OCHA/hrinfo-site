<?php
/**
 * @file
 * hr_operations.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_operations_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_operation:bundle member'.
  $roles['node:hr_operation:bundle member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'bundle member',
  );

  // Exported OG Role: 'node:hr_operation:contributor'.
  $roles['node:hr_operation:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'contributor',
  );

  // Exported OG Role: 'node:hr_operation:editor'.
  $roles['node:hr_operation:editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'editor',
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
