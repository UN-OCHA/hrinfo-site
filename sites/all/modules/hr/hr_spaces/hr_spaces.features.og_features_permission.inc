<?php
/**
 * @file
 * hr_spaces.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_spaces_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_space:add user'
  $permissions['node:hr_space:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:administer og menu'
  $permissions['node:hr_space:administer og menu'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:administer panelizer og_group content'
  $permissions['node:hr_space:administer panelizer og_group content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:approve and deny subscription'
  $permissions['node:hr_space:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:assign contributor role'
  $permissions['node:hr_space:assign contributor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:assign editor role'
  $permissions['node:hr_space:assign editor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:assign manager role'
  $permissions['node:hr_space:assign manager role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:edit group features'
  $permissions['node:hr_space:edit group features'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:manage members'
  $permissions['node:hr_space:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:publish any content'
  $permissions['node:hr_space:publish any content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:subscribe'
  $permissions['node:hr_space:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:subscribe without approval'
  $permissions['node:hr_space:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:unpublish any content'
  $permissions['node:hr_space:unpublish any content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:update group'
  $permissions['node:hr_space:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
