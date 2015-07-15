<?php

$plugin = array(
  'label' => t('Infographic Types'),
  'resource' => 'infographic_types',
  'name' => 'hr_infographic_type__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_infographic_type',
  'description' => t('Export the "infographic types" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermInfographicTypes',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
