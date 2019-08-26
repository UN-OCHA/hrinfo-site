<?php
/**
 * @file
 * hr_fundings.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_fundings_taxonomy_default_vocabularies() {
  return array(
    'hr_funding_type' => array(
      'name' => 'Funding Type',
      'machine_name' => 'hr_funding_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
