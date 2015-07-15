<?php
/**
 * @file
 * hr_locations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_locations_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_directory().
 */
function hr_locations_ctools_plugin_directory($module, $plugin) {
  if ($module == 'restful') {
    return 'plugins/' . $plugin;
  }
}

/**
 * Implements hook_views_api()
 */
function hr_locations_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
