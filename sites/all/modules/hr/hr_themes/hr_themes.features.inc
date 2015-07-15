<?php
/**
 * @file
 * hr_themes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_themes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_directory().
 */
function hr_themes_ctools_plugin_directory($module, $plugin) {
  if ($module == 'restful') {
    return 'plugins/' . $plugin;
  }
}

/**
 * Implements hook_views_api().
 */
function hr_themes_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
