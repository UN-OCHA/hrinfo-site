<?php
/**
 * @file
 * hr_contacts.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_contacts_taxonomy_default_vocabularies() {
  return array(
    'hr_functional_role' => array(
      'name' => 'Functional Role',
      'machine_name' => 'hr_functional_role',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
