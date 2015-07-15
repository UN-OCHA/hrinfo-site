<?php

$plugin = array(
  'label' => t('Functional Roles'),
  'resource' => 'functional_roles',
  'name' => 'hr_functional_role__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_functional_role',
  'description' => t('Export the "functional roles" taxonomy terms.'),
  'class' => 'RestfulEntityTaxonomyTermFunctionalRoles',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
