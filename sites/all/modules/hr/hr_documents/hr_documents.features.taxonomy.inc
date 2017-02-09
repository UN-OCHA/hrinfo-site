<?php
/**
 * @file
 * hr_documents.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_documents_taxonomy_default_vocabularies() {
  return array(
    'hr_document_type' => array(
      'name' => 'Document Type',
      'machine_name' => 'hr_document_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'path' => array(
        'pathauto' => 0,
      ),
    ),
  );
}
