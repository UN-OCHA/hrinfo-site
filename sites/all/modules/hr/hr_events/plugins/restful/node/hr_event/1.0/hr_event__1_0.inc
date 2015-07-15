<?php

$plugin = array(
  'label' => t('Events'),
  'resource' => 'events',
  'name' => 'hr_event__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_event',
  'description' => t('Export the events.'),
  'class' => 'RestfulEntityNodeEvents',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
