<?php
/**
 * @file
 * hr_datasets.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_datasets_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_data';
  $context->description = '';
  $context->tag = 'Datasets';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'applications/data' => 'applications/data',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_datasets-master' => array(
          'module' => 'views',
          'delta' => '-exp-hr_datasets-master',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'views-hr_datasets-dataset_locations' => array(
          'module' => 'views',
          'delta' => 'hr_datasets-dataset_locations',
          'region' => 'content',
          'weight' => '-10',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'content',
          'weight' => '-8',
        ),
        'og_menu-og_single_menu_block' => array(
          'module' => 'og_menu',
          'delta' => 'og_single_menu_block',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Datasets');
  $export['hr_data'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_datasets_space';
  $context->description = '';
  $context->tag = 'Datasets';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_datasets:master' => 'hr_datasets:master',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_datasets-master' => array(
          'module' => 'views',
          'delta' => '-exp-hr_datasets-master',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-j3HxiZwNJ4R0Ko07V311HTCBQ5Qhvsty' => array(
          'module' => 'facetapi',
          'delta' => 'j3HxiZwNJ4R0Ko07V311HTCBQ5Qhvsty',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-SauzQhZGmFdDfgASiddEFOV7jbT0ifHu' => array(
          'module' => 'facetapi',
          'delta' => 'SauzQhZGmFdDfgASiddEFOV7jbT0ifHu',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-Xgc9MM1xeLYMhx0PgX0XU0N0N0Poh2Lh' => array(
          'module' => 'facetapi',
          'delta' => 'Xgc9MM1xeLYMhx0PgX0XU0N0N0Poh2Lh',
          'region' => 'sidebar_first',
          'weight' => '-6',
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
  t('Datasets');
  $export['hr_datasets_space'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_datasets_space_table';
  $context->description = '';
  $context->tag = 'Datasets';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_datasets:table' => 'hr_datasets:table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_datasets-table' => array(
          'module' => 'views',
          'delta' => '-exp-hr_datasets-table',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-j3HxiZwNJ4R0Ko07V311HTCBQ5Qhvsty' => array(
          'module' => 'facetapi',
          'delta' => 'j3HxiZwNJ4R0Ko07V311HTCBQ5Qhvsty',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-SauzQhZGmFdDfgASiddEFOV7jbT0ifHu' => array(
          'module' => 'facetapi',
          'delta' => 'SauzQhZGmFdDfgASiddEFOV7jbT0ifHu',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-Xgc9MM1xeLYMhx0PgX0XU0N0N0Poh2Lh' => array(
          'module' => 'facetapi',
          'delta' => 'Xgc9MM1xeLYMhx0PgX0XU0N0N0Poh2Lh',
          'region' => 'sidebar_first',
          'weight' => '-6',
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
  t('Datasets');
  $export['hr_datasets_space_table'] = $context;

  return $export;
}
