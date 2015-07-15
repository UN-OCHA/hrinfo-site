<?php

$plugin = array(
  'label' => t('Indicator units'),
  'resource' => 'indicator_units',
  'name' => 'hr_indicator_unit__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_indicator_unit',
  'description' => t('Export the "Indicator Units" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermIndicatorUnits',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
