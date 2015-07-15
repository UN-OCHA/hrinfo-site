<?php
/**
 * @file
 * hr_spaces.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_spaces_taxonomy_default_vocabularies() {
  return array(
    'hr_space_category' => array(
      'name' => 'Space Category',
      'machine_name' => 'hr_space_category',
      'description' => 'Categories for spaces',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
