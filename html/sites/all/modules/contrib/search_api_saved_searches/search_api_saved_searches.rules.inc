<?php

/**
 * @file
 * Rules integration for the Search API Saved Searches module.
 */

/**
 * Implements hook_rules_action_info().
 */
function search_api_saved_searches_rules_action_info() {
  return array(
    'search_api_saved_searches_rules_index_results' => array(
      'label' => t('Fetch the saved searches'),
      'parameter' => array(
        'index_id' => array(
          'type' => 'integer',
          'label' => t('Index for which to retrieve searches'),
          'description' => t('Select the search index for which saved searches should be retrieved.'),
          'options list' => '_search_api_saved_searches_settings_options_list',
        ),
      ),
      'provides' => array(
        'search_api_saved_search' => array(
          'type' => 'list<integer>',
          'label' => t('List of the IDs of the saved searches that require executing.'),
        ),
      ),
      'group' => t('Search API Saved Searches'),
    ),
    'search_api_saved_searches_rules_get_saved_search_new_items' => array(
      'label' => t('Fetch the new results for a saved search'),
      'parameter' => array(
        'index_id' => array(
          'type' => 'integer',
          'label' => t('Saved search ID'),
          'description' => t('The ID of the saved search for which to retrieve new results.'),
        ),
      ),
      'provides' => array(
        'search' => array(
          'type' => 'search_api_saved_search',
          'label' => t('The executed search.'),
        ),
        'result_count' => array(
          'type' => 'integer',
          'label' => t('The count of results that were found.'),
        ),
        'results' => array(
          'type' => 'list<integer>',
          'label' => t('The list of new results for the saved search since it was last executed.'),
        ),
      ),
      'group' => t('Search API Saved Searches'),
    ),
  );
}

/**
 * Retrieves the options list for selecting a saved search settings entity.
 *
 * @return string[]
 *   An associative array mapping saved search settings IDs to index names.
 */
function _search_api_saved_searches_settings_options_list() {
  // Fetch the list of saved searches setting and make a list of values.
  $entities = entity_load('search_api_saved_searches_settings');
  $ids = array();
  foreach ($entities as $entity) {
    $ids[$entity->index_id][] = $entity->id;
  }

  $indexes = search_api_index_load_multiple(array_keys($ids));
  $options = array();
  foreach ($indexes as $index_id => $index) {
    foreach ($ids[$index_id] as $settings_id) {
      $options[$settings_id] = $index->label();
    }
  }
  return $options;
}

/**
 * Callback: Implements the "Fetch the saved searches" rules action.
 *
 * @param int|null $settings_id
 *   (optional) The ID of the saved search settings entity for which to retrieve
 *   searches. NULL to retrieve for all.
 *
 * @return array
 *   An associative array with key "search_api_saved_search" containing the IDs
 *   of all searches that should be executed.
 */
function search_api_saved_searches_rules_index_results($settings_id) {
  return array(
    'search_api_saved_search' => search_api_saved_searches_get_searches_to_be_executed($settings_id),
  );
}

/**
 * Callback: Implements the "Fetch the new results for a search" rules action.
 *
 * @param int $search_id
 *   The ID of the saved search setting entity.
 *
 * @return array
 *   Array of the results count and the results list for the given search ID.
 */
function search_api_saved_searches_rules_get_saved_search_new_items($search_id) {
  $search = search_api_saved_search_load($search_id);
  return search_api_saved_search_fetch_search_results($search);
}
