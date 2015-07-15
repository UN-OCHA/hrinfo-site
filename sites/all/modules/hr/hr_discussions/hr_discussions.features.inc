<?php
/**
 * @file
 * hr_discussions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_discussions_ctools_plugin_api($module = NULL, $api = NULL) {
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
function hr_discussions_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hr_discussions_node_info() {
  $items = array(
    'hr_discussion' => array(
      'name' => t('Discussion'),
      'base' => 'node_content',
      'description' => t('A content type to initiate a forum discussion'),
      'has_title' => '1',
      'title_label' => t('Subject'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
