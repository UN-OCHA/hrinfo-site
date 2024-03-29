<?php

/**
 * @file
 * hr_organizations.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_organizations_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__hr_organization';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'exclude_language_none' => 1,
    'hide_language_selector' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__hr_organization'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__hr_organization_type';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'exclude_language_none' => 1,
    'hide_language_selector' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__hr_organization_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hr_organization_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_hr_organization_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hr_organization_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_hr_organization_type_pattern'] = $strongarm;

  return $export;
}
