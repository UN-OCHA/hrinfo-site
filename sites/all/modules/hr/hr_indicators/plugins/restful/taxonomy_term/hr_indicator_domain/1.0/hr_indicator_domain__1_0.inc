<?php

$plugin = array(
  'label' => t('Indicator domains'),
  'resource' => 'indicator_domains',
  'name' => 'hr_indicator_domain__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_indicator_domain',
  'description' => t('Export the "Indicator Domains" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermIndicatorDomains',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
