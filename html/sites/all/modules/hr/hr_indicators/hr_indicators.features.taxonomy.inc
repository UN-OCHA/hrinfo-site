<?php

/**
 * @file
 * hr_indicators.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_indicators_taxonomy_default_vocabularies() {
  return array(
    'hr_indicator_domain' => array(
      'name' => 'Indicator Domain',
      'machine_name' => 'hr_indicator_domain',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_indicator_standard' => array(
      'name' => 'Indicator Standard',
      'machine_name' => 'hr_indicator_standard',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_indicator_type' => array(
      'name' => 'Indicator Type',
      'machine_name' => 'hr_indicator_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_indicator_unit' => array(
      'name' => 'Indicator Unit',
      'machine_name' => 'hr_indicator_unit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
