<?php
/**
 * @file
 * hr_offices.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_offices_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_operation:access authoring options of hr_office content'
  $permissions['node:hr_operation:access authoring options of hr_office content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of hr_office content'
  $permissions['node:hr_operation:access publishing options of hr_office content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access revisions options of hr_office content'
  $permissions['node:hr_operation:access revisions options of hr_office content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:create hr_office content'
  $permissions['node:hr_operation:create hr_office content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete any hr_office content'
  $permissions['node:hr_operation:delete any hr_office content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete own hr_office content'
  $permissions['node:hr_operation:delete own hr_office content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update any hr_office content'
  $permissions['node:hr_operation:update any hr_office content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own hr_office content'
  $permissions['node:hr_operation:update own hr_office content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished hr_office content'
  $permissions['node:hr_operation:view any unpublished hr_office content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
