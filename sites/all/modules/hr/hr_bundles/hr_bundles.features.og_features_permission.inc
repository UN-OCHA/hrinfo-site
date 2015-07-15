<?php
/**
 * @file
 * hr_bundles.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_bundles_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_bundle:add user'
  $permissions['node:hr_bundle:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:administer og menu'
  $permissions['node:hr_bundle:administer og menu'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:administer panelizer og_group content'
  $permissions['node:hr_bundle:administer panelizer og_group content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:approve and deny subscription'
  $permissions['node:hr_bundle:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:assign editor role'
  $permissions['node:hr_bundle:assign editor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:assign manager role'
  $permissions['node:hr_bundle:assign manager role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:assign contributor role'
  $permissions['node:hr_bundle:assign contributor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:create hr_contact content'
  $permissions['node:hr_bundle:create hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:delete any hr_contact content'
  $permissions['node:hr_bundle:delete any hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:delete own hr_contact content'
  $permissions['node:hr_bundle:delete own hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:manage members'
  $permissions['node:hr_bundle:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:update any hr_contact content'
  $permissions['node:hr_bundle:update any hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:update group'
  $permissions['node:hr_bundle:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:update own hr_contact content'
  $permissions['node:hr_bundle:update own hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:create hr_bundle content'
  $permissions['node:hr_operation:create hr_bundle content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:delete any hr_bundle content'
  $permissions['node:hr_operation:delete any hr_bundle content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:delete own hr_bundle content'
  $permissions['node:hr_operation:delete own hr_bundle content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:update any hr_bundle content'
  $permissions['node:hr_operation:update any hr_bundle content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own hr_bundle content'
  $permissions['node:hr_operation:update own hr_bundle content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:publish any content'
  $permissions['node:hr_bundle:publish any content'] = array(
    'roles' => array(
      'manager' => 'manager',
      'editor' => 'editor',
    ),
  );

  // Exported og permission: 'node:hr_bundle:unpublish any content'
  $permissions['node:hr_bundle:unpublish any content'] = array(
    'roles' => array(
      'manager' => 'manager',
      'editor' => 'editor',
    ),
  );


  return $permissions;
}
