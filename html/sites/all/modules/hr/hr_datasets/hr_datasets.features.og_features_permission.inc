<?php
/**
 * @file
 * hr_datasets.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_datasets_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_operation:access authoring options of hr_dataset content'
  $permissions['node:hr_operation:access authoring options of hr_dataset content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of hr_dataset content'
  $permissions['node:hr_operation:access publishing options of hr_dataset content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access revisions options of hr_dataset content'
  $permissions['node:hr_operation:access revisions options of hr_dataset content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:create hr_dataset content'
  $permissions['node:hr_operation:create hr_dataset content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete any hr_dataset content'
  $permissions['node:hr_operation:delete any hr_dataset content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete own hr_dataset content'
  $permissions['node:hr_operation:delete own hr_dataset content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update any hr_dataset content'
  $permissions['node:hr_operation:update any hr_dataset content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own hr_dataset content'
  $permissions['node:hr_operation:update own hr_dataset content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished hr_dataset content'
  $permissions['node:hr_operation:view any unpublished hr_dataset content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
