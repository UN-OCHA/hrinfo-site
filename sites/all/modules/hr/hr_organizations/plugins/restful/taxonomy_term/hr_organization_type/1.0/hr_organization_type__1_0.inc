<?php

$plugin = array(
  'label' => t('Organization types'),
  'resource' => 'organization_types',
  'name' => 'hr_organization_type__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_organization_type',
  'description' => t('Export the "organization types" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermOrganizationTypes',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
