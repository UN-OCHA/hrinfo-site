<?php
/**
 * @file
 * hr_tools.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_tools_taxonomy_default_vocabularies() {
  return array(
    'hr_toolbox_category' => array(
      'name' => 'Toolbox Category',
      'machine_name' => 'hr_toolbox_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
