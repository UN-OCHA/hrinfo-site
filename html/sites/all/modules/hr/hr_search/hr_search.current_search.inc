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
    'advanced' => array(
      'empty_searches' => '1',
    ),
    'items' => array(
      'reset' => array(
        'classes' => 'reset-all-filters',
        'css' => 1,
        'element' => 'div',
        'id' => 'reset_filters',
        'label' => 'Reset',
        'plural' => 1,
        'plural_condition' => 'facetapi_results:result-count',
        'reset_query_params' => 'search',
        'reset_type' => 1,
        'text' => '<i class="reset"></i> <span>Reset filter</span>',
        'text_plural' => '<i class="reset"></i> <span>Reset filters</span>',
        'weight' => '-48',
        'wrapper' => 1,
      ),
      'results' => array(
        'classes' => 'current-search-filter',
        'css' => 1,
        'element' => 'div',
        'id' => 'text',
        'label' => 'Results',
        'plural' => 1,
        'plural_condition' => 'facetapi_results:result-count',
        'text' => ' <p>Filter: <span class="facetapi-active">[facetapi_results:result-count] item</span> displayed</p>',
        'text_plural' => '<p>Filter: <span class="facetapi-active">[facetapi_results:result-count] items</span> displayed</p>',
        'weight' => '-50',
        'wrapper' => 1,
      ),
      'selected_items' => array(
        'classes' => '.current-selected-item',
        'css' => 1,
        'id' => 'active',
        'keys' => 1,
        'keys_link' => 1,
        'keys_param' => 'search',
        'label' => 'Selected items',
        'nofollow' => 1,
        'pattern' => '[facetapi_active:active-value]',
        'weight' => '-49',
      ),
    ),
  );
  $export['hr_current_search'] = $item;

  return $export;
}
