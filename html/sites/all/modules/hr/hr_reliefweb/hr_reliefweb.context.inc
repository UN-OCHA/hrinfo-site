<?php

/**
 * @file
 * hr_reliefweb.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_reliefweb_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE;
  $context->api_version = 3;
  $context->name = 'hr_reliefweb_context_documents';
  $context->description = 'Search box for RW Documents.';
  $context->tag = 'HR Reliefweb';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/reliefweb' => 'node/*/reliefweb',
        'node/*/reliefweb/*' => 'node/*/reliefweb/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hr_reliefweb-hr_reliefweb_search' => array(
          'module' => 'hr_reliefweb',
          'delta' => 'hr_reliefweb_search',
          'region' => 'header_search',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  t('HR Reliefweb');
  t('Search box for RW Documents.');

  $export['hr_reliefweb_context_documents'] = $context;

  return $export;
}
