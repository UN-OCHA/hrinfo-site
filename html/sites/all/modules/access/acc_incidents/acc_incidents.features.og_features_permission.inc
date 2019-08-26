<?php
/**
 * @file
 * acc_incidents.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function acc_incidents_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_bundle:access authoring options of acc_incident content'
  $permissions['node:hr_bundle:access authoring options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:access publishing options of acc_incident content'
  $permissions['node:hr_bundle:access publishing options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:access revisions options of acc_incident content'
  $permissions['node:hr_bundle:access revisions options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:administer panelizer node acc_incident defaults'
  $permissions['node:hr_bundle:administer panelizer node acc_incident defaults'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:create acc_incident content'
  $permissions['node:hr_bundle:create acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:delete any acc_incident content'
  $permissions['node:hr_bundle:delete any acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:delete own acc_incident content'
  $permissions['node:hr_bundle:delete own acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:update any acc_incident content'
  $permissions['node:hr_bundle:update any acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:update own acc_incident content'
  $permissions['node:hr_bundle:update own acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:view any unpublished acc_incident content'
  $permissions['node:hr_bundle:view any unpublished acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access authoring options of acc_incident content'
  $permissions['node:hr_operation:access authoring options of acc_incident content'] = array(
    'roles' => array(
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of acc_incident content'
  $permissions['node:hr_operation:access publishing options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access revisions options of acc_incident content'
  $permissions['node:hr_operation:access revisions options of acc_incident content'] = array(
    'roles' => array(
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:administer panelizer node acc_incident defaults'
  $permissions['node:hr_operation:administer panelizer node acc_incident defaults'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:create acc_incident content'
  $permissions['node:hr_operation:create acc_incident content'] = array(
    'roles' => array(
      'access-editor' => 'access-editor',
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete any acc_incident content'
  $permissions['node:hr_operation:delete any acc_incident content'] = array(
    'roles' => array(
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete own acc_incident content'
  $permissions['node:hr_operation:delete own acc_incident content'] = array(
    'roles' => array(
      'access-editor' => 'access-editor',
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update any acc_incident content'
  $permissions['node:hr_operation:update any acc_incident content'] = array(
    'roles' => array(
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own acc_incident content'
  $permissions['node:hr_operation:update own acc_incident content'] = array(
    'roles' => array(
      'access-editor' => 'access-editor',
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished acc_incident content'
  $permissions['node:hr_operation:view any unpublished acc_incident content'] = array(
    'roles' => array(
      'access-manager' => 'access-manager',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access authoring options of acc_incident content'
  $permissions['node:hr_sector:access authoring options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:access publishing options of acc_incident content'
  $permissions['node:hr_sector:access publishing options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:access revisions options of acc_incident content'
  $permissions['node:hr_sector:access revisions options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:administer panelizer node acc_incident defaults'
  $permissions['node:hr_sector:administer panelizer node acc_incident defaults'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:create acc_incident content'
  $permissions['node:hr_sector:create acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:delete any acc_incident content'
  $permissions['node:hr_sector:delete any acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:delete own acc_incident content'
  $permissions['node:hr_sector:delete own acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:update any acc_incident content'
  $permissions['node:hr_sector:update any acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:update own acc_incident content'
  $permissions['node:hr_sector:update own acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:view any unpublished acc_incident content'
  $permissions['node:hr_sector:view any unpublished acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access authoring options of acc_incident content'
  $permissions['node:hr_space:access authoring options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access publishing options of acc_incident content'
  $permissions['node:hr_space:access publishing options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access revisions options of acc_incident content'
  $permissions['node:hr_space:access revisions options of acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:administer panelizer node acc_incident defaults'
  $permissions['node:hr_space:administer panelizer node acc_incident defaults'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:create acc_incident content'
  $permissions['node:hr_space:create acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:delete any acc_incident content'
  $permissions['node:hr_space:delete any acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:delete own acc_incident content'
  $permissions['node:hr_space:delete own acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:update any acc_incident content'
  $permissions['node:hr_space:update any acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:update own acc_incident content'
  $permissions['node:hr_space:update own acc_incident content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:view any unpublished acc_incident content'
  $permissions['node:hr_space:view any unpublished acc_incident content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
