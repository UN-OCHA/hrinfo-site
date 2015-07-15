<?php
/**
 * @file
 * hr_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_help_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bootstrap_tour" && $api == "bootstrap_tour_tour") {
    return array("version" => "1");
  }
}
