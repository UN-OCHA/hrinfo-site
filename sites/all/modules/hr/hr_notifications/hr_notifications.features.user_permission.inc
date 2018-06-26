<?php
/**
 * @file
 * hr_notifications.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_notifications_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag hr_follow'.
  $permissions['flag hr_follow'] = array(
    'name' => 'flag hr_follow',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag hr_follow'.
  $permissions['unflag hr_follow'] = array(
    'name' => 'unflag hr_follow',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
