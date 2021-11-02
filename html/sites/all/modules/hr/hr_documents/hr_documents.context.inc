<?php

/**
 * @file
 * hr_documents.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_documents_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_documents_global';
  $context->description = 'Documents global page';
  $context->tag = 'Documents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_documents:global_list' => 'hr_documents:global_list',
        'hr_documents:global_master' => 'hr_documents:global_master',
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
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
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
        'views--exp-hr_documents-global_master' => array(
          'delta' => '-exp-hr_documents-global_master',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-9',
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
  t('Documents');
  t('Documents global page');
  $export['hr_documents_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_documents_global_table';
  $context->description = 'Documents table global';
  $context->tag = 'Documents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_documents:global_table' => 'hr_documents:global_table',
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
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
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
        'views--exp-hr_documents-global_table' => array(
          'delta' => '-exp-hr_documents-global_table',
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
  t('Documents');
  t('Documents table global');
  $export['hr_documents_global_table'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_documents_space';
  $context->description = 'Documents page per space';
  $context->tag = 'Documents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_documents:list' => 'hr_documents:list',
        'hr_documents:master' => 'hr_documents:master',
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
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
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
        'views--exp-hr_documents-master' => array(
          'delta' => '-exp-hr_documents-master',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');
  t('Documents page per space');
  $export['hr_documents_space'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_documents_space_table';
  $context->description = 'Documents table per space';
  $context->tag = 'Documents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_documents:table' => 'hr_documents:table',
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
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
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
        'views--exp-hr_documents-table' => array(
          'delta' => '-exp-hr_documents-table',
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
  t('Documents');
  t('Documents table per space');
  $export['hr_documents_space_table'] = $context;

  return $export;
}
