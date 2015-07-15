<?php

/**
 * @file
 * hr_stats module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_stats_drush_command() {
  $items = array();

  $items['hr-stats-full-stats'] = array(
    'description' => "Get the full stats for HR.info sites",
    'options' => array(
      'period' => 'Period',
      'date' => 'Date',
    ),
    'drupal dependencies' => array('hr_stats'),
    'aliases' => array(),
  );

  return $items;
}

function drush_hr_stats_full_stats($period, $date) {
  hr_stats_get_full_stats($period, $date);
}
