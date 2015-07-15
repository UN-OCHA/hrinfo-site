<?php
/**
 * @file
 * hr_infographics.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_infographics_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable hr_infographics'.
  $permissions['create fieldable hr_infographics'] = array(
    'name' => 'create fieldable hr_infographics',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable hr_infographics'.
  $permissions['delete fieldable hr_infographics'] = array(
    'name' => 'delete fieldable hr_infographics',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable hr_infographics'.
  $permissions['edit fieldable hr_infographics'] = array(
    'name' => 'edit fieldable hr_infographics',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
