<?php

$plugin = array(
  'label' => t('Offices'),
  'resource' => 'offices',
  'name' => 'hr_office__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_office',
  'description' => t('Export the offices.'),
  'class' => 'RestfulEntityNodeOffices',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
