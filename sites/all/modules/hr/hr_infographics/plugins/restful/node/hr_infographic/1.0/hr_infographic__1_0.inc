<?php

$plugin = array(
  'label' => t('Infographics'),
  'resource' => 'infographics',
  'name' => 'hr_infographic__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_infographic',
  'description' => t('Export the infographics.'),
  'class' => 'RestfulEntityNodeInfographics',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
