<?php

$plugin = array(
  'label' => t('Locations'),
  'resource' => 'locations',
  'name' => 'hr_location__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_location',
  'description' => t('Export the "locations" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermLocations',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
