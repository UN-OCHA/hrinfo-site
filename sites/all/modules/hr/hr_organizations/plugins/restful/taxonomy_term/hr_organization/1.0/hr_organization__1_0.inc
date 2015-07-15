<?php

$plugin = array(
  'label' => t('Organizations'),
  'resource' => 'organizations',
  'name' => 'hr_organization__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_organization',
  'description' => t('Export the "organizations" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermOrganizations',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
