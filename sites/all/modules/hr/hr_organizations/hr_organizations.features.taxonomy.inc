<?php
/**
 * @file
 * hr_organizations.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_organizations_taxonomy_default_vocabularies() {
  return array(
    'hr_organization' => array(
      'name' => 'Organization',
      'machine_name' => 'hr_organization',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'hr_organization_type' => array(
      'name' => 'Organization Type',
      'machine_name' => 'hr_organization_type',
      'description' => 'Types of organizations',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
