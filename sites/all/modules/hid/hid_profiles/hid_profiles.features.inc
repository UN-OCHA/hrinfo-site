<?php
/**
 * @file
 * hid_profiles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hid_profiles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
