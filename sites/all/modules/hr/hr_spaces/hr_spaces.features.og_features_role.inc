<?php
/**
 * @file
 * hr_spaces.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_spaces_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_space:contributor'.
  $roles['node:hr_space:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_space',
    'name' => 'contributor',
  );

  // Exported OG Role: 'node:hr_space:editor'.
  $roles['node:hr_space:editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_space',
    'name' => 'editor',
  );

  // Exported OG Role: 'node:hr_space:manager'.
  $roles['node:hr_space:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_space',
    'name' => 'manager',
  );

  return $roles;
}
