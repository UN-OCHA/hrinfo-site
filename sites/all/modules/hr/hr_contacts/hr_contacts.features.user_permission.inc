<?php
/**
 * @file
 * hr_contacts.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_contacts_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_functional_roles'.
  $permissions['create field_functional_roles'] = array(
    'name' => 'create field_functional_roles',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create fieldable hr_contacts'.
  $permissions['create fieldable hr_contacts'] = array(
    'name' => 'create fieldable hr_contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable hr_contacts'.
  $permissions['delete fieldable hr_contacts'] = array(
    'name' => 'delete fieldable hr_contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit field_functional_roles'.
  $permissions['edit field_functional_roles'] = array(
    'name' => 'edit field_functional_roles',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit fieldable hr_contacts'.
  $permissions['edit fieldable hr_contacts'] = array(
    'name' => 'edit fieldable hr_contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit own field_functional_roles'.
  $permissions['edit own field_functional_roles'] = array(
    'name' => 'edit own field_functional_roles',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_functional_roles'.
  $permissions['view field_functional_roles'] = array(
    'name' => 'view field_functional_roles',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_functional_roles'.
  $permissions['view own field_functional_roles'] = array(
    'name' => 'view own field_functional_roles',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
