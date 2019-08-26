<?php

/**
 * @file
 * File Chooser Field API.
 */

/**
 * Implements hook_file_chooser_field_plugins().
 */
function hook_file_chooser_field_plugins() {
  return array(
    '[plugin-machine-name]' => array(
      'name' => t('Human readable name'),
      'phpClassName' => '[PHP Class Name (extends `FileChooserFieldPlugin` class)]',
      // Add extended class to your module's .info file
      // files[] = [path to plugin class file]
      // `weight` negative value at the top of the list.
      'weight' => 10,
    ),
  );
}

/**
 * Implements hook_file_chooser_field_plugins_alter().
 */
function hook_file_chooser_field_plugins_alter(&$plugins) {
  // Alter File Chooser Field plugins.
}

/**
 * Implements hook_file_chooser_field_download().
 */
function hook_file_chooser_field_download($phpClassName, $remote_file, $local_file) {
  // This could be used to track file downloades.
  // @todo add better description.
}
