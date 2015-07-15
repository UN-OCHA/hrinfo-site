<?php
/**
 * @file
 * hr_bundles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_bundles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_bundles_pages';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'coordination/clusters/countries' => 'coordination/clusters/countries',
        'coordination/clusters/global' => 'coordination/clusters/global',
      ),
    ),
  );
  $context->reactions = array(
    'disable_context' => array(
      'disabled' => array(
        'hr_space_menu' => 'hr_space_menu',
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['hr_bundles_pages'] = $context;

  return $export;
}
