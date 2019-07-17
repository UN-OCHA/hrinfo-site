<?php
/**
 * @file
 * hr_bookmarks.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_bookmarks_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag hr_favorite_space'.
  $permissions['flag hr_favorite_space'] = array(
    'name' => 'flag hr_favorite_space',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag hr_favorite_space'.
  $permissions['unflag hr_favorite_space'] = array(
    'name' => 'unflag hr_favorite_space',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
