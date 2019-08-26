<?php
/**
 * @file
 * hr_spaces.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_spaces_ctools_plugin_api($module = NULL, $api = NULL) {
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
function hr_spaces_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hr_spaces_node_info() {
  $items = array(
    'hr_space' => array(
      'name' => t('Space'),
      'base' => 'node_content',
      'description' => t('A generic space content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
