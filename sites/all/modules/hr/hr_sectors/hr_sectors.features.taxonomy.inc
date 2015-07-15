<?php
/**
 * @file
 * hr_sectors.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_sectors_taxonomy_default_vocabularies() {
  return array(
    'hr_sector' => array(
      'name' => 'Sector',
      'machine_name' => 'hr_sector',
      'description' => 'Standard list of sectors',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
