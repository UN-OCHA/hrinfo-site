<?php
/**
 * @file
 * hr_stats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_stats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_account';
  $strongarm->value = 'UA-70934930-1';
  $export['googleanalytics_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_custom_dimension';
  $strongarm->value = array(
    1 => array(
      'index' => 1,
      'value' => '[node:spaces]',
    ),
    2 => array(
      'index' => 2,
      'value' => '[node:bundles]',
    ),
    3 => array(
      'index' => 3,
      'value' => '[node:type]',
    ),
  );
  $export['googleanalytics_custom_dimension'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'piwik_custom_var';
  $strongarm->value = array(
    'slots' => array(
      1 => array(
        'slot' => 1,
        'name' => 'spaces',
        'value' => '[node:spaces]',
        'scope' => 'page',
      ),
      2 => array(
        'slot' => 2,
        'name' => 'bundles',
        'value' => '[node:bundles]',
        'scope' => 'page',
      ),
      3 => array(
        'slot' => 3,
        'name' => 'type',
        'value' => '[node:type]',
        'scope' => 'page',
      ),
      4 => array(
        'slot' => 4,
        'name' => '',
        'value' => '',
        'scope' => 'visit',
      ),
      5 => array(
        'slot' => 5,
        'name' => '',
        'value' => '',
        'scope' => 'visit',
      ),
    ),
  );
  $export['piwik_custom_var'] = $strongarm;

  return $export;
}
