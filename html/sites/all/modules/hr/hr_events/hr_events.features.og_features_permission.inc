<?php
/**
 * @file
 * hr_events.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_events_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_bundle:access authoring options of hr_event content'
  $permissions['node:hr_bundle:access authoring options of hr_event content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:access publishing options of hr_event content'
  $permissions['node:hr_bundle:access publishing options of hr_event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:access revisions options of hr_event content'
  $permissions['node:hr_bundle:access revisions options of hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:create hr_event content'
  $permissions['node:hr_bundle:create hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:delete any hr_event content'
  $permissions['node:hr_bundle:delete any hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:delete own hr_event content'
  $permissions['node:hr_bundle:delete own hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:update any hr_event content'
  $permissions['node:hr_bundle:update any hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:update own hr_event content'
  $permissions['node:hr_bundle:update own hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:view any unpublished hr_event content'
  $permissions['node:hr_bundle:view any unpublished hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access authoring options of hr_event content'
  $permissions['node:hr_operation:access authoring options of hr_event content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of hr_event content'
  $permissions['node:hr_operation:access publishing options of hr_event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access revisions options of hr_event content'
  $permissions['node:hr_operation:access revisions options of hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:create hr_event content'
  $permissions['node:hr_operation:create hr_event content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete any hr_event content'
  $permissions['node:hr_operation:delete any hr_event content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete own hr_event content'
  $permissions['node:hr_operation:delete own hr_event content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update any hr_event content'
  $permissions['node:hr_operation:update any hr_event content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own hr_event content'
  $permissions['node:hr_operation:update own hr_event content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished hr_event content'
  $permissions['node:hr_operation:view any unpublished hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access authoring options of hr_event content'
  $permissions['node:hr_sector:access authoring options of hr_event content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access publishing options of hr_event content'
  $permissions['node:hr_sector:access publishing options of hr_event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:access revisions options of hr_event content'
  $permissions['node:hr_sector:access revisions options of hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:create hr_event content'
  $permissions['node:hr_sector:create hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:delete any hr_event content'
  $permissions['node:hr_sector:delete any hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:delete own hr_event content'
  $permissions['node:hr_sector:delete own hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:update any hr_event content'
  $permissions['node:hr_sector:update any hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:update own hr_event content'
  $permissions['node:hr_sector:update own hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:view any unpublished hr_event content'
  $permissions['node:hr_sector:view any unpublished hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:access authoring options of hr_event content'
  $permissions['node:hr_space:access authoring options of hr_event content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:access publishing options of hr_event content'
  $permissions['node:hr_space:access publishing options of hr_event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access revisions options of hr_event content'
  $permissions['node:hr_space:access revisions options of hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:create hr_event content'
  $permissions['node:hr_space:create hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:delete any hr_event content'
  $permissions['node:hr_space:delete any hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:delete own hr_event content'
  $permissions['node:hr_space:delete own hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:update any hr_event content'
  $permissions['node:hr_space:update any hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:update own hr_event content'
  $permissions['node:hr_space:update own hr_event content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:view any unpublished hr_event content'
  $permissions['node:hr_space:view any unpublished hr_event content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
