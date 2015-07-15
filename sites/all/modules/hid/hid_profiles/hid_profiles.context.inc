<?php
/**
 * @file
 * hid_profiles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hid_profiles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hid_contacts';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/hid_contacts' => 'node/*/hid_contacts',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hid_profiles-hid_profiles_search' => array(
          'module' => 'hid_profiles',
          'delta' => 'hid_profiles_search',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'hid_profiles-hid_profiles_sidebar' => array(
          'module' => 'hid_profiles',
          'delta' => 'hid_profiles_sidebar',
          'region' => 'sidebar_first',
          'weight' => '-20',
        ),
        'hid_profiles-hid_profiles_filters' => array(
          'module' => 'hid_profiles',
          'delta' => 'hid_profiles_filters',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'hid_profiles-hid_profiles_powered_by' => array(
          'module' => 'hid_profiles',
          'delta' => 'hid_profiles_powered_by',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['hid_contacts'] = $context;

  return $export;
}
