<?php

/**
 * @file
 * hr_wysiwyg.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_wysiwyg_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format hr_wysiwyg'.
  $permissions['use text format hr_wysiwyg'] = array(
    'name' => 'use text format hr_wysiwyg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format panopoly_html_text'.
  $permissions['use text format panopoly_html_text'] = array(
    'name' => 'use text format panopoly_html_text',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
