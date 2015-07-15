<?php
/**
 * @file
 * hr_disasters.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_disasters_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_disaster:administer og menu'
  $permissions['node:hr_disaster:administer og menu'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_disaster:administer panelizer og_group content'
  $permissions['node:hr_disaster:administer panelizer og_group content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_disaster:edit group features'
  $permissions['node:hr_disaster:edit group features'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_disaster:update group'
  $permissions['node:hr_disaster:update group'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access authoring options of hr_disaster content'
  $permissions['node:hr_operation:access authoring options of hr_disaster content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of hr_disaster content'
  $permissions['node:hr_operation:access publishing options of hr_disaster content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access revisions options of hr_disaster content'
  $permissions['node:hr_operation:access revisions options of hr_disaster content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:create hr_disaster content'
  $permissions['node:hr_operation:create hr_disaster content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:delete any hr_disaster content'
  $permissions['node:hr_operation:delete any hr_disaster content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:delete own hr_disaster content'
  $permissions['node:hr_operation:delete own hr_disaster content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:update any hr_disaster content'
  $permissions['node:hr_operation:update any hr_disaster content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own hr_disaster content'
  $permissions['node:hr_operation:update own hr_disaster content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished hr_disaster content'
  $permissions['node:hr_operation:view any unpublished hr_disaster content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
