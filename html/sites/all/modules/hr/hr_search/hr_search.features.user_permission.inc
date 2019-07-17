<?php
/**
 * @file
 * hr_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use search_api_sorts'.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_sorts',
  );

  return $permissions;
}
