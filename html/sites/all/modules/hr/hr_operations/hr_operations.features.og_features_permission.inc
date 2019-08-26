<?php
/**
 * @file
 * hr_operations.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_operations_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_operation:add user'
  $permissions['node:hr_operation:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:administer og menu'
  $permissions['node:hr_operation:administer og menu'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:administer panelizer og_group content'
  $permissions['node:hr_operation:administer panelizer og_group content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:approve and deny subscription'
  $permissions['node:hr_operation:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:assign contributor role'
  $permissions['node:hr_operation:assign contributor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:assign editor role'
  $permissions['node:hr_operation:assign editor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:assign manager role'
  $permissions['node:hr_operation:assign manager role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:edit group features'
  $permissions['node:hr_operation:edit group features'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:manage members'
  $permissions['node:hr_operation:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:publish any content'
  $permissions['node:hr_operation:publish any content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:subscribe without approval'
  $permissions['node:hr_operation:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:hr_operation:unpublish any content'
  $permissions['node:hr_operation:unpublish any content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update group'
  $permissions['node:hr_operation:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
