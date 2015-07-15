<?php

$plugin = array(
  'label' => t('Indicator types'),
  'resource' => 'indicator_types',
  'name' => 'hr_indicator_type__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_indicator_type',
  'description' => t('Export the "Indicator Types" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermIndicatorTypes',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
