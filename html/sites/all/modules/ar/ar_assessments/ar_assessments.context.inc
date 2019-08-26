<?php

/**
 * @file
 * Hid_profiles.context.inc.
 */

/**
 * Implements hook_context_default_contexts().
 */
function ar_assessments_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ar_assessments';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/ar_assessments' => 'node/*/ar_assessments',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ar_assessments-ar_assessments_powered_by' => array(
          'module' => 'ar_assessments',
          'delta' => 'ar_assessments_powered_by',
          'region' => 'sidebar_first',
          'weight' => '-30',
        ),
        'ar_assessments-ar_assessments_sidebar' => array(
          'module' => 'ar_assessments',
          'delta' => 'ar_assessments_sidebar',
          'region' => 'sidebar_first',
          'weight' => '-20',
        ),
        'ar_assessments-ar_assessments_filters' => array(
          'module' => 'ar_assessments',
          'delta' => 'ar_assessments_filters',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['ar_assessments'] = $context;

  return $export;
}
