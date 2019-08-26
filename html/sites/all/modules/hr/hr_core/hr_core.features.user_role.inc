<?php
/**
 * @file
 * hr_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hr_core_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
    'machine_name' => 'administrator',
  );

  return $roles;
}
