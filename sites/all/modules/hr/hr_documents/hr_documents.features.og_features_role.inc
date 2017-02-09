<?php
/**
 * @file
 * hr_documents.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_documents_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_bundle:contributor'.
  $roles['node:hr_bundle:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_bundle',
    'name' => 'contributor',
  );

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
