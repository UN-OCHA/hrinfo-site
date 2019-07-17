<?php
/**
 * @file
 * acc_applications.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function acc_applications_taxonomy_default_vocabularies() {
  return array(
    'acc_application_submission_status' => array(
      'name' => 'Access Application Submission Status',
      'machine_name' => 'acc_application_submission_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'acc_application_types' => array(
      'name' => 'Access Application Types',
      'machine_name' => 'acc_application_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
