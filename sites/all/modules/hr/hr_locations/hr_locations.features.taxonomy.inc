<?php
/**
 * @file
 * hr_locations.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_locations_taxonomy_default_vocabularies() {
  return array(
    'hr_location' => array(
      'name' => 'Location',
      'machine_name' => 'hr_location',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
