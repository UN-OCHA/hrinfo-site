<?php

$plugin = array(
  'label' => t('Indicator standards'),
  'resource' => 'indicator_standards',
  'name' => 'hr_indicator_standard__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_indicator_standard',
  'description' => t('Export the "Indicator Standards" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermIndicatorStandards',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
