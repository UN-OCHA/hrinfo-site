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
        'views--exp-hr_documents-global_master' => array(
          'module' => 'views',
          'delta' => '-exp-hr_documents-global_master',
          'region' => 'branding',
          'weight' => '-9',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'search_api_sorts-search-sorts' => array(
          'module' => 'search_api_sorts',
          'delta' => 'search-sorts',
          'region' => 'content',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'module' => 'facetapi',
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'module' => 'facetapi',
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-3quDa8MFI2Sa9usljzl0qr3fbusfVG93' => array(
          'module' => 'facetapi',
          'delta' => '3quDa8MFI2Sa9usljzl0qr3fbusfVG93',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'module' => 'facetapi',
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
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
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'module' => 'facetapi',
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
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
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
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
        'views--exp-hr_documents-global_table' => array(
          'module' => 'views',
          'delta' => '-exp-hr_documents-global_table',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'module' => 'facetapi',
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'module' => 'facetapi',
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-3quDa8MFI2Sa9usljzl0qr3fbusfVG93' => array(
          'module' => 'facetapi',
          'delta' => '3quDa8MFI2Sa9usljzl0qr3fbusfVG93',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'module' => 'facetapi',
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
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
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'module' => 'facetapi',
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
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
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
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
        'views--exp-hr_documents-master' => array(
          'module' => 'views',
          'delta' => '-exp-hr_documents-master',
          'region' => 'branding',
          'weight' => '-9',
        ),
        'search_api_sorts-search-sorts' => array(
          'module' => 'search_api_sorts',
          'delta' => 'search-sorts',
          'region' => 'content',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'module' => 'facetapi',
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'module' => 'facetapi',
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v' => array(
          'module' => 'facetapi',
          'delta' => '9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'module' => 'facetapi',
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
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
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
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
        'views--exp-hr_documents-table' => array(
          'module' => 'views',
          'delta' => '-exp-hr_documents-table',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS' => array(
          'module' => 'facetapi',
          'delta' => '2VJqM7IlPMSIoTIQrsoqy1dgG563hXbS',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-w7XuwcVu1l6DNu4aCenMydri96KBLxYh' => array(
          'module' => 'facetapi',
          'delta' => 'w7XuwcVu1l6DNu4aCenMydri96KBLxYh',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v' => array(
          'module' => 'facetapi',
          'delta' => '9GGN5HfHaQpjLAfMWHJknvdGmR74ha9v',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S' => array(
          'module' => 'facetapi',
          'delta' => 'SEcKjZK5tfurGpvrhp6Z9y3447HT7e2S',
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
        'hr_layout-hr_layout_search_rss' => array(
          'delta' => 'hr_layout_search_rss',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '3',
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
