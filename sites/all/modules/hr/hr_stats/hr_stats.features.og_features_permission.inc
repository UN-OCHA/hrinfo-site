<?php
/**
 * @file
 * hr_stats.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_stats_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_disaster:access piwik reports'
  $permissions['node:hr_disaster:access piwik reports'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access piwik reports'
  $permissions['node:hr_operation:access piwik reports'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access piwik reports'
  $permissions['node:hr_sector:access piwik reports'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_space:access piwik reports'
  $permissions['node:hr_space:access piwik reports'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
