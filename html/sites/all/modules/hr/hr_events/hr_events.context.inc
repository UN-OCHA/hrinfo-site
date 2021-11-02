<?php

/**
 * @file
 * hr_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_events_global';
  $context->description = 'Events list';
  $context->tag = 'Events';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_events:global_master' => 'hr_events:global_master',
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
        'facetapi-3quDa8MFI2Sa9usljzl0qr3fbusfVG93' => array(
          'delta' => '3quDa8MFI2Sa9usljzl0qr3fbusfVG93',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v' => array(
          'delta' => '9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-gPcXdpo5VXMKRnf2peK1lJwTKU9F3IAh' => array(
          'delta' => 'gPcXdpo5VXMKRnf2peK1lJwTKU9F3IAh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU' => array(
          'delta' => 'hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'system-main-menu' => array(
          'delta' => 'main-menu',
          'module' => 'system',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'views--exp-hr_events-global_master' => array(
          'delta' => '-exp-hr_events-global_master',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'outside_space' => 'outside_space',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Events');
  t('Events list');
  $export['hr_events_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_events_space_list';
  $context->description = 'Events list per space';
  $context->tag = 'Events';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_events:list' => 'hr_events:list',
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
        'facetapi-9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v' => array(
          'delta' => '9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-gPcXdpo5VXMKRnf2peK1lJwTKU9F3IAh' => array(
          'delta' => 'gPcXdpo5VXMKRnf2peK1lJwTKU9F3IAh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU' => array(
          'delta' => 'hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'views--exp-hr_events-list' => array(
          'delta' => '-exp-hr_events-list',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Events');
  t('Events list per space');
  $export['hr_events_space_list'] = $context;

  return $export;
}
