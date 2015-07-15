<?php

$plugin = array(
  'label' => t('Clusters/Sectors'),
  'resource' => 'bundles',
  'name' => 'hr_bundle__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_bundle',
  'description' => t('Export the clusters/sectors.'),
  'class' => 'RestfulEntityNodeBundles',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
