<?php

$plugin = array(
  'label' => t('Documents'),
  'resource' => 'documents',
  'name' => 'hr_document__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_document',
  'description' => t('Export the documents.'),
  'class' => 'RestfulEntityNodeDocuments',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
