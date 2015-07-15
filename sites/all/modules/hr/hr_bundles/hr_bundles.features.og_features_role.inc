<?php
/**
 * @file
 * hr_bundles.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_bundles_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_bundle:editor'.
  $roles['node:hr_bundle:editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_bundle',
    'name' => 'editor',
  );

  // Exported OG Role: 'node:hr_bundle:manager'.
  $roles['node:hr_bundle:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_bundle',
    'name' => 'manager',
  );

  // Exported OG Role: 'node:hr_bundle:contributor'.
  $roles['node:hr_bundle:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_bundle',
    'name' => 'contributor',
  );

  return $roles;
}
