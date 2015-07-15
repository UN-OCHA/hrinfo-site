<?php
/**
 * @file
 * hr_translations.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hr_translations_user_default_roles() {
  $roles = array();

  // Exported role: translator.
  $roles['translator'] = array(
    'name' => 'translator',
    'weight' => 4,
    'machine_name' => 'translator',
  );

  return $roles;
}
