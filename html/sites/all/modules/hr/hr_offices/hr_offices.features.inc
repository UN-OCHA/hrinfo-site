<?php
/**
 * @file
 * hr_offices.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_offices_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_directory().
 */
function hr_offices_ctools_plugin_directory($module, $plugin) {
  if ($module == 'restful') {
    return 'plugins/' . $plugin;
  }
}

/**
 * Implements hook_views_api().
 */
function hr_offices_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hr_offices_node_info() {
  $items = array(
    'hr_office' => array(
      'name' => t('Office'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
