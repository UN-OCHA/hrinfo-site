<?php

$plugin = array(
  'label' => t('Indicators'),
  'resource' => 'indicators',
  'name' => 'hr_indicator__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_indicator',
  'description' => t('Export the indicators.'),
  'class' => 'RestfulEntityNodeIndicators',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
