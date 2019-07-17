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
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'module' => 'facetapi',
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-XEALhc8ysZYJYeBGGMrztUfQM1GPRMcl' => array(
          'module' => 'facetapi',
          'delta' => 'XEALhc8ysZYJYeBGGMrztUfQM1GPRMcl',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-Inq9iHy8F01ng3heTk70PTVUV4G1i5Fh' => array(
          'module' => 'facetapi',
          'delta' => 'Inq9iHy8F01ng3heTk70PTVUV4G1i5Fh',
          'region' => 'sidebar_first',
          'weight' => '-7',
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
