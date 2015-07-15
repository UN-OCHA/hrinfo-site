<?php
/**
 * @file
 * hr_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hr_users_user_default_roles() {
  $roles = array();

  // Exported role: contributor.
  $roles['contributor'] = array(
    'name' => 'contributor',
    'weight' => 4,
    'machine_name' => 'contributor',
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 2,
    'machine_name' => 'editor',
  );

  // Exported role: trusted.
  $roles['trusted'] = array(
    'name' => 'trusted',
    'weight' => 3,
    'machine_name' => 'trusted',
  );

  return $roles;
}
