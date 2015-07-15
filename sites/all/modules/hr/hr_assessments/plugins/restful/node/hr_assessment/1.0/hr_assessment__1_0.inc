<?php

$plugin = array(
  'label' => t('Assessments'),
  'resource' => 'assessments',
  'name' => 'hr_assessment__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_assessment',
  'description' => t('Export the assessments.'),
  'class' => 'RestfulEntityNodeAssessments',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
