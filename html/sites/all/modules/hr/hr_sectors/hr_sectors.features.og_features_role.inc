<?php
/**
 * @file
 * hr_sectors.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_sectors_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_sector:contributor'.
  $roles['node:hr_sector:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_sector',
    'name' => 'contributor',
  );

  // Exported OG Role: 'node:hr_sector:editor'.
  $roles['node:hr_sector:editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_sector',
    'name' => 'editor',
  );

  // Exported OG Role: 'node:hr_sector:manager'.
  $roles['node:hr_sector:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_sector',
    'name' => 'manager',
  );

  return $roles;
}
