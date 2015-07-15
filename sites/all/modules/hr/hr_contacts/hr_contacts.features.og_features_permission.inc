<?php
/**
 * @file
 * hr_contacts.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_contacts_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_operation:access authoring options of hr_contact content'
  $permissions['node:hr_operation:access authoring options of hr_contact content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of hr_contact content'
  $permissions['node:hr_operation:access publishing options of hr_contact content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access revisions options of hr_contact content'
  $permissions['node:hr_operation:access revisions options of hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:create hr_contact content'
  $permissions['node:hr_operation:create hr_contact content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete any hr_contact content'
  $permissions['node:hr_operation:delete any hr_contact content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete own hr_contact content'
  $permissions['node:hr_operation:delete own hr_contact content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update any hr_contact content'
  $permissions['node:hr_operation:update any hr_contact content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own hr_contact content'
  $permissions['node:hr_operation:update own hr_contact content'] = array(
    'roles' => array(
      'bundle member' => 'bundle member',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished hr_contact content'
  $permissions['node:hr_operation:view any unpublished hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:create hr_contact content'
  $permissions['node:hr_bundle:create hr_contact content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:update any hr_contact content'
  $permissions['node:hr_bundle:update any hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:update own hr_contact content'
  $permissions['node:hr_bundle:update own hr_contact content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:delete any hr_contact content'
  $permissions['node:hr_bundle:delete any hr_contact content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_bundle:delete own hr_contact content'
  $permissions['node:hr_bundle:delete own hr_contact content'] = array(
    'roles' => array(
      'contributor' => 'contributor',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
  );

  return $permissions;
}
