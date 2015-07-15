<?php

$plugin = array(
  'label' => t('Operations'),
  'resource' => 'operations',
  'name' => 'hr_operation__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_operation',
  'description' => t('Export the operations.'),
  'class' => 'RestfulEntityNodeOperations',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
