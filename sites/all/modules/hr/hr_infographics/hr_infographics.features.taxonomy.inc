<?php
/**
 * @file
 * hr_infographics.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_infographics_taxonomy_default_vocabularies() {
  return array(
    'hr_infographic_type' => array(
      'name' => 'Infographic Type',
      'machine_name' => 'hr_infographic_type',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
