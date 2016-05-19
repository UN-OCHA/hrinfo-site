<?php

$plugin = array(
  'label' => t('Datasets'),
  'resource' => 'datasets',
  'name' => 'hr_dataset__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_dataset',
  'description' => t('Datasets are now provided by HDX.'),
  'class' => 'RestfulEntityBaseNode',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
  'menu_item' => variable_get('humdata_base_url', 'https://data.humdata.org') . '/faq#body-faq-HDX_API'
);
