<?php
/**
 * @file
 * hr_assessments.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_assessments_taxonomy_default_vocabularies() {
  return array(
    'hr_population_type' => array(
      'name' => 'Population Type',
      'machine_name' => 'hr_population_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
