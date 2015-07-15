<?php

$plugin = array(
  'label' => t('Population Types'),
  'resource' => 'population_types',
  'name' => 'hr_population_type__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_population_type',
  'description' => t('Export the "population types" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermPopulationTypes',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
