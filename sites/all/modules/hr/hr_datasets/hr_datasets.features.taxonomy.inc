<?php
/**
 * @file
 * hr_datasets.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_datasets_taxonomy_default_vocabularies() {
  return array(
    'hr_dataset_category' => array(
      'name' => 'Dataset Category',
      'machine_name' => 'hr_dataset_category',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_dataset_type' => array(
      'name' => 'Dataset Type',
      'machine_name' => 'hr_dataset_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
