<?php

$plugin = array(
  'label' => t('Spaces'),
  'resource' => 'spaces',
  'name' => 'hr_space__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_space',
  'description' => t('Export the global spaces.'),
  'class' => 'RestfulEntityNodeSpaces',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
