<?php
/**
 * @file
 * hr_webforms.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_webforms_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_operation:access authoring options of webform content'
  $permissions['node:hr_operation:access authoring options of webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of webform content'
  $permissions['node:hr_operation:access publishing options of webform content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access revisions options of webform content'
  $permissions['node:hr_operation:access revisions options of webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:create webform content'
  $permissions['node:hr_operation:create webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete any webform content'
  $permissions['node:hr_operation:delete any webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete own webform content'
  $permissions['node:hr_operation:delete own webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update any webform content'
  $permissions['node:hr_operation:update any webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own webform content'
  $permissions['node:hr_operation:update own webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished webform content'
  $permissions['node:hr_operation:view any unpublished webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access authoring options of webform content'
  $permissions['node:hr_sector:access authoring options of webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access publishing options of webform content'
  $permissions['node:hr_sector:access publishing options of webform content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:access revisions options of webform content'
  $permissions['node:hr_sector:access revisions options of webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:create webform content'
  $permissions['node:hr_sector:create webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:delete any webform content'
  $permissions['node:hr_sector:delete any webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:delete own webform content'
  $permissions['node:hr_sector:delete own webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:update any webform content'
  $permissions['node:hr_sector:update any webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:update own webform content'
  $permissions['node:hr_sector:update own webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:view any unpublished webform content'
  $permissions['node:hr_sector:view any unpublished webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:access authoring options of webform content'
  $permissions['node:hr_space:access authoring options of webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:access publishing options of webform content'
  $permissions['node:hr_space:access publishing options of webform content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access revisions options of webform content'
  $permissions['node:hr_space:access revisions options of webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:create webform content'
  $permissions['node:hr_space:create webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:delete any webform content'
  $permissions['node:hr_space:delete any webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:delete own webform content'
  $permissions['node:hr_space:delete own webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:update any webform content'
  $permissions['node:hr_space:update any webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:update own webform content'
  $permissions['node:hr_space:update own webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:view any unpublished webform content'
  $permissions['node:hr_space:view any unpublished webform content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
