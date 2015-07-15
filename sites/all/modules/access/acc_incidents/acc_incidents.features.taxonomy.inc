<?php
/**
 * @file
 * acc_incidents.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function acc_incidents_taxonomy_default_vocabularies() {
  return array(
    'acc_impact_types' => array(
      'name' => 'Access Impact Types',
      'machine_name' => 'acc_impact_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'acc_incident_types' => array(
      'name' => 'Access Type',
      'machine_name' => 'acc_incident_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'acc_responsible_actors' => array(
      'name' => 'Access Responsible Actors',
      'machine_name' => 'acc_responsible_actors',
      'description' => 'A separate taxonomy ',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'acc_type_of_aid_workers' => array(
      'name' => 'Type of affectee',
      'machine_name' => 'acc_type_of_aid_workers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
