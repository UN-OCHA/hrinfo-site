<?php

$plugin = array(
  'label' => t('Datasets'),
  'resource' => 'datasets',
  'name' => 'hr_dataset__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_dataset',
  'description' => t('Export the datasets.'),
  'class' => 'RestfulEntityNodeDatasets',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
