<?php
/**
 * @file
 * hr_translations.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_translations_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'provide translation services'.
  $permissions['provide translation services'] = array(
    'name' => 'provide translation services',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'translator' => 'translator',
    ),
    'module' => 'tmgmt_local',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
      'translator' => 'translator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
      'translator' => 'translator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate fieldable_panels_pane entities'.
  $permissions['translate fieldable_panels_pane entities'] = array(
    'name' => 'translate fieldable_panels_pane entities',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
      'translator' => 'translator',
    ),
    'module' => 'i18n_string',
  );

  return $permissions;
}
