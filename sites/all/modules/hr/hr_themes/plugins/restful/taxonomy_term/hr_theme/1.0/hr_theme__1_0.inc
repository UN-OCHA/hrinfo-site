<?php

$plugin = array(
  'label' => t('Themes'),
  'resource' => 'themes',
  'name' => 'hr_theme__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'hr_theme',
  'description' => t('Export the "themes" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermThemes',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
