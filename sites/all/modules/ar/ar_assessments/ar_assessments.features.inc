<?php

/**
 * @file
 * ar_assessments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ar_assessments_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
