<?php

/**
 * @file
 * hr_core module drush integration.
 *
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_core_drush_command() {
  $items = array();

  $items['hr-core-average-file-size'] = array(
    'description' => "Display the average file size and median of the files",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Get the average file size of all files uploaded on HR.info.
 */
function drush_hr_core_average_file_size() {

  $result = db_query('SELECT AVG(filesize) FROM drupal.file_managed');
  foreach ($result as $record) {
    print_r($record);
  }

  $result = db_query('SELECT percentile_disc(0.5) within group (order by filesize) FROM drupal.file_managed;');
  foreach ($result as $record) {
    print_r($record);
  }
}
