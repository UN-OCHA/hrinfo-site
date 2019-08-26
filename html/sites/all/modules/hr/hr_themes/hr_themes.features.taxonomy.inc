<?php
/**
 * @file
 * hr_themes.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_themes_taxonomy_default_vocabularies() {
  return array(
    'hr_theme' => array(
      'name' => 'Theme',
      'machine_name' => 'hr_theme',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
