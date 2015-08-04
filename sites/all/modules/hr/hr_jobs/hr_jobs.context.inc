<?php
/**
 * @file
 * hr_jobs.context.inc
 */
/**
 * Implements hook_context_default_contexts().
 */
function hr_jobs_context_default_contexts() {
  $export = array();
  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_jobs';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/jobs' => 'node/*/jobs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hr_jobs-hr_jobs_filters' => array(
          'module' => 'hr_jobs',
          'delta' => 'hr_jobs_filters',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['hr_jobs'] = $context;
  return $export;
}