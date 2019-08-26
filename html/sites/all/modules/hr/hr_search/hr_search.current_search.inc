<?php

/**
 * @file
 * hr_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function hr_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'hr_current_search';
  $item->label = 'Humanitarianresponse';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => ' <p>Filter: <span class="facetapi-active">[facetapi_results:result-count] item</span> displayed</p>',
        'plural' => 1,
        'text_plural' => '<p>Filter: <span class="facetapi-active">[facetapi_results:result-count] items</span> displayed</p>',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'div',
        'css' => 1,
        'classes' => 'current-search-filter',
        'weight' => '-50',
      ),
      'selected_items' => array(
        'id' => 'active',
        'label' => 'Selected items',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'keys_link' => 1,
        'keys_param' => 'search',
        'css' => 1,
        'classes' => '.current-selected-item',
        'nofollow' => 1,
        'weight' => '-49',
      ),
      'reset' => array(
        'id' => 'reset_filters',
        'label' => 'Reset',
        'reset_type' => 1,
        'reset_query_params' => 'search',
        'text' => '<i class="reset"></i> <span>Reset filter</span>',
        'plural' => 1,
        'text_plural' => '<i class="reset"></i> <span>Reset filters</span>',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'div',
        'css' => 1,
        'classes' => 'reset-all-filters',
        'weight' => '-48',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );
  $export['hr_current_search'] = $item;

  return $export;
}
