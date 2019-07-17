<?php
/**
 * @file
 * hr_sectors.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_sectors_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_sector:add user'
  $permissions['node:hr_sector:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:administer og menu'
  $permissions['node:hr_sector:administer og menu'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:administer panelizer og_group content'
  $permissions['node:hr_sector:administer panelizer og_group content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:approve and deny subscription'
  $permissions['node:hr_sector:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:assign contributor role'
  $permissions['node:hr_sector:assign contributor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:assign editor role'
  $permissions['node:hr_sector:assign editor role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:assign manager role'
  $permissions['node:hr_sector:assign manager role'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:edit group features'
  $permissions['node:hr_sector:edit group features'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:manage members'
  $permissions['node:hr_sector:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:publish any content'
  $permissions['node:hr_sector:publish any content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:subscribe'
  $permissions['node:hr_sector:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:subscribe without approval'
  $permissions['node:hr_sector:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:unpublish any content'
  $permissions['node:hr_sector:unpublish any content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:update group'
  $permissions['node:hr_sector:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
