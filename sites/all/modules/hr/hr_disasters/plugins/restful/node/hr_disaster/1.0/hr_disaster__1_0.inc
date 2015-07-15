<?php

$plugin = array(
  'label' => t('Disasters'),
  'resource' => 'disasters',
  'name' => 'hr_disaster__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_disaster',
  'description' => t('Export the disasters.'),
  'class' => 'RestfulEntityNodeDisasters',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
