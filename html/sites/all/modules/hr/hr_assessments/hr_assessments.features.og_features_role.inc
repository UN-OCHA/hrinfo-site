<?php

/**
 * @file
 * hr_assessments.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_assessments_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_bundle:contributor'.
  $roles['node:hr_bundle:contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_bundle',
    'name' => 'contributor',
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

  return $roles;
}
