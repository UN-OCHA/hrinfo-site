<?php

$plugin = array(
  'label' => t('Document Types'),
  'resource' => 'document_types',
  'name' => 'hr_document_type__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_document_type',
  'description' => t('Export the "document types" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermDocumentTypes',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
