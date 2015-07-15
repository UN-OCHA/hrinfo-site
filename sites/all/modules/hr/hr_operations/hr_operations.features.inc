<?php
/**
 * @file
 * hr_operations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_operations_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
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
function hr_operations_ctools_plugin_directory($module, $plugin) {
  if ($module == 'restful') {
    return 'plugins/' . $plugin;
  }
}

/**
 * Implements hook_views_api().
 */
function hr_operations_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hr_operations_node_info() {
  $items = array(
    'hr_operation' => array(
      'name' => t('Operation'),
      'base' => 'node_content',
      'description' => t('Place where humanitarian actions are involved'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
