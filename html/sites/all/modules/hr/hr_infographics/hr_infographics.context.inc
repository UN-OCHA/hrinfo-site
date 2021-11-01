<?php

/**
 * @file
 * hr_infographics.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_infographics_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_infographics_global';
  $context->description = 'Infographics global page';
  $context->tag = 'Infographics';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_infographics:global_list' => 'hr_infographics:global_list',
        'hr_infographics:global_master' => 'hr_infographics:global_master',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        '35099122474bc9c43a02271db18a15f9' => array(
          'delta' => '35099122474bc9c43a02271db18a15f9',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
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
          'weight' => '-3',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o' => array(
          'delta' => 'LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'search_api_sorts-search-sorts' => array(
          'delta' => 'search-sorts',
          'module' => 'search_api_sorts',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'delta' => 'main-menu',
          'module' => 'system',
          'region' => 'navigation',
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
  t('Infographics');
  t('Infographics global page');
  $export['hr_infographics_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_infographics_global_table';
  $context->description = 'Infographics global table';
  $context->tag = 'Infographics';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_infographics:global_table' => 'hr_infographics:global_table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ade7fd0a639142c5d84fcf2915cf5990' => array(
          'delta' => 'ade7fd0a639142c5d84fcf2915cf5990',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
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
          'weight' => '-3',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o' => array(
          'delta' => 'LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
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
  t('Infographics');
  t('Infographics global table');
  $export['hr_infographics_global_table'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_infographics_space';
  $context->description = 'Infographics page per space';
  $context->tag = 'Infographics';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_infographics:list' => 'hr_infographics:list',
        'hr_infographics:master' => 'hr_infographics:master',
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
          'weight' => '-2',
        ),
        'facetapi-LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o' => array(
          'delta' => 'LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'search_api_sorts-search-sorts' => array(
          'delta' => 'search-sorts',
          'module' => 'search_api_sorts',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-hr_infographics-master' => array(
          'delta' => '-exp-hr_infographics-master',
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
  t('Infographics');
  t('Infographics page per space');
  $export['hr_infographics_space'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_infographics_space_table';
  $context->description = 'Infographics table per space';
  $context->tag = 'Infographics';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_infographics:table' => 'hr_infographics:table',
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
          'weight' => '-2',
        ),
        'facetapi-LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o' => array(
          'delta' => 'LFGijFQMu0hPG4mZyIhp0L6nfnWD1f2o',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS' => array(
          'delta' => 'ufw6LRur6Vw9VcpuZ4VayzbcSrlX1VMS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'views--exp-hr_infographics-table' => array(
          'delta' => '-exp-hr_infographics-table',
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
  t('Infographics');
  t('Infographics table per space');
  $export['hr_infographics_space_table'] = $context;

  return $export;
}
