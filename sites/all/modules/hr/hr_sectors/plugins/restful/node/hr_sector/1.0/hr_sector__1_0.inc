<?php

$plugin = array(
  'label' => t('Global Clusters'),
  'resource' => 'global_clusters',
  'name' => 'hr_sector__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_sector',
  'description' => t('Export the global cluster nodes.'),
  'class' => 'RestfulEntityNodeGlobalClusters',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
