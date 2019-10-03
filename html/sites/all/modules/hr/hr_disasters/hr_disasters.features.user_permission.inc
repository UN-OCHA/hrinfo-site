<?php

/**
 * @file
 * hr_disasters.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_disasters_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_reliefweb_id'.
  $permissions['create field_reliefweb_id'] = array(
    'name' => 'create field_reliefweb_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reliefweb_id'.
  $permissions['edit field_reliefweb_id'] = array(
    'name' => 'edit field_reliefweb_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reliefweb_id'.
  $permissions['edit own field_reliefweb_id'] = array(
    'name' => 'edit own field_reliefweb_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reliefweb_id'.
  $permissions['view field_reliefweb_id'] = array(
    'name' => 'view field_reliefweb_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reliefweb_id'.
  $permissions['view own field_reliefweb_id'] = array(
    'name' => 'view own field_reliefweb_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
