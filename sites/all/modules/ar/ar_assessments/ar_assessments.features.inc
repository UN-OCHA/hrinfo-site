<?php
/**
 * @file
 * ar_assessments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ar_assessments_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && ($api == "plugins" || $api == "context")) {
    return array("version" => "3");
  }
}

/**
 * Implements hook_ctools_plugin_directory().
 */
function ar_assessments_ctools_plugin_directory($module, $plugin) {
  if ($module == 'ctools' && $plugin == 'content_types') {
    return 'plugins/' . $plugin;
  }
}
