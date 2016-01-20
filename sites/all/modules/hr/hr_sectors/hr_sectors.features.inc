<?php
/**
 * @file
 * hr_sectors.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_sectors_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
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
 * Implements hook_views_api().
 */
function hr_sectors_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hr_sectors_node_info() {
  $items = array(
    'hr_sector' => array(
      'name' => t('Global bundle'),
      'base' => 'node_content',
      'description' => t('Global cluster/sector/working group'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
