<?php

/**
 * @file
 * hr_locations.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_locations_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__hr_location';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'exclude_language_none' => 0,
    'hide_language_selector' => 1,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__hr_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hr_location_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_hr_location_pattern'] = $strongarm;

  return $export;
}
