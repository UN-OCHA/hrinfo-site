<?php
/**
 * @file
 * hr_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_search';
  $context->description = '';
  $context->tag = 'Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_search:page' => 'hr_search:page',
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
        'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk' => array(
          'module' => 'facetapi',
          'delta' => 'zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'module' => 'facetapi',
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o' => array(
          'module' => 'facetapi',
          'delta' => 'LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-V14egKF141IaMDUK4g0ON2bAIbD6pAjQ' => array(
          'module' => 'facetapi',
          'delta' => 'V14egKF141IaMDUK4g0ON2bAIbD6pAjQ',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v' => array(
          'module' => 'facetapi',
          'delta' => '9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'module' => 'facetapi',
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-b5bh0kCY1bW8OCpa4wz1BXZJB31r0aAK' => array(
          'module' => 'facetapi',
          'delta' => 'b5bh0kCY1bW8OCpa4wz1BXZJB31r0aAK',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'module' => 'facetapi',
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  $export['hr_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_search_space';
  $context->description = '';
  $context->tag = 'Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_search:space' => 'hr_search:space',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_search-space' => array(
          'module' => 'views',
          'delta' => '-exp-hr_search-space',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk' => array(
          'module' => 'facetapi',
          'delta' => 'zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-V14egKF141IaMDUK4g0ON2bAIbD6pAjQ' => array(
          'module' => 'facetapi',
          'delta' => 'V14egKF141IaMDUK4g0ON2bAIbD6pAjQ',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v' => array(
          'module' => 'facetapi',
          'delta' => '9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'module' => 'facetapi',
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  $export['hr_search_space'] = $context;

  return $export;
}
