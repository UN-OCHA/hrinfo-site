<?php
/**
 * @file
 * hr_documents.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_documents_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fieldable hr_documents'.
  $permissions['create fieldable hr_documents'] = array(
    'name' => 'create fieldable hr_documents',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable hr_documents'.
  $permissions['delete fieldable hr_documents'] = array(
    'name' => 'delete fieldable hr_documents',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable hr_documents'.
  $permissions['edit fieldable hr_documents'] = array(
    'name' => 'edit fieldable hr_documents',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
