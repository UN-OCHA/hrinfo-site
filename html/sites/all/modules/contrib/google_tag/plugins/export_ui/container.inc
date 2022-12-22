<?php

/**
 * @file
 * Plugin definition for container.
 *
 * @author Jim Berry ("solotandem", http://drupal.org/user/240748)
 */

// @todo There are more plugin keys; read the ctools code to find them.
// See ctools_export_ui_process() for what it looks for in plugin definition.
$plugin = array(
  'schema' => 'gtag_config',
  'access' => 'administer google tag manager',

  'menu' => array(
    'menu prefix' => 'admin/config/system',
    'menu item' => 'google_tag',
    'menu title' => 'Google Tag Manager',
    'menu description' => 'Configure the website integration with GTM and the resultant capturing of website analytics.',
    'items' => array(
      'list' => array(
        'title' => 'Containers',
      ),
      'add' => array(
        'title' => 'Add container',
      ),
      'import' => array(
        'title' => 'Import container',
      ),
    ),
  ),

  'handler' => array(
    'class' => 'GTMContainerExport',
    'file' => 'container.php',
  ),

  'title singular' => t('container'),
  'title singular proper' => t('container'),
  'title plural' => t('containers'),
  'title plural proper' => t('containers'),

  // A '%title' token exists to use in strings; no others.
  // @todo None of the 'title' strings is used
  'strings' => array(
    'title' => array(
      'list' => t('Containers'),
      'add' => t('Add container configuration'),
      // 'edit' => t('Edit container configuration'),
      // 'delete' => t('Delete container configuration'),
      // 'clone' => t('Clone container configuration'),
      // 'export' => t('Export container configuration'),
      // 'import' => t('Import container configuration'),
      'edit' => t('Edit %title container'),
      'delete' => t('Delete %title container'),
      'clone' => t('Clone %title container'),
      'export' => t('Export %title container'),
    ),
    'confirmation' => array(
      'add' => array(
        'success' => t('Container saved.'),
      ),
      'delete' => array(
        'success' => t('Container deleted.'),
      ),
    ),
  ),
);
