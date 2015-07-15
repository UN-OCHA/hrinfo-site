<?php
/**
 * @file
 * hr_job_titles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_job_titles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
