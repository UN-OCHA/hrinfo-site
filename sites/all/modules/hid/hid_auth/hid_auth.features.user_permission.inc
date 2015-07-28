<?php
/**
 * @file
 * hid_auth.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hid_auth_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'connect with oauthconnector_hid_oauth'.
  $permissions['connect with oauthconnector_hid_oauth'] = array(
    'name' => 'connect with oauthconnector_hid_oauth',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'connector',
  );

  return $permissions;
}
