<?php
/**
 * @file
 * hr_layout.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_layout_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any fts_visualization bean'.
  $permissions['create any fts_visualization bean'] = array(
    'name' => 'create any fts_visualization bean',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create fieldable fieldable_panels_pane'.
  $permissions['create fieldable fieldable_panels_pane'] = array(
    'name' => 'create fieldable fieldable_panels_pane',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete any fts_visualization bean'.
  $permissions['delete any fts_visualization bean'] = array(
    'name' => 'delete any fts_visualization bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete fieldable fieldable_panels_pane'.
  $permissions['delete fieldable fieldable_panels_pane'] = array(
    'name' => 'delete fieldable fieldable_panels_pane',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit any fts_visualization bean'.
  $permissions['edit any fts_visualization bean'] = array(
    'name' => 'edit any fts_visualization bean',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit fieldable fieldable_panels_pane'.
  $permissions['edit fieldable fieldable_panels_pane'] = array(
    'name' => 'edit fieldable fieldable_panels_pane',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'view any fts_visualization bean'.
  $permissions['view any fts_visualization bean'] = array(
    'name' => 'view any fts_visualization bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
