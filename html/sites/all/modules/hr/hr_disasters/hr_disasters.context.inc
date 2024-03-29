<?php

/**
 * @file
 * hr_disasters.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_disasters_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_disasters';
  $context->description = '';
  $context->tag = 'Disasters';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_disasters:page' => 'hr_disasters:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-hr_current_search' => array(
          'delta' => 'hr_current_search',
          'module' => 'current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-Inq9iHy8F01ng3heTk70PTVUV4G1i5Fh' => array(
          'delta' => 'Inq9iHy8F01ng3heTk70PTVUV4G1i5Fh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-XEALhc8ysZYJYeBGGMrztUfQM1GPRMcl' => array(
          'delta' => 'XEALhc8ysZYJYeBGGMrztUfQM1GPRMcl',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Disasters');
  $export['hr_disasters'] = $context;

  return $export;
}
