<?php

/**
 * @file
 * Defines Views hook implementations.
 */

/**
 * Implements hook_views_data_alter().
 *
 * Adds relationships to the creator of a saved search, its settings and the
 * search index, as well as edit and delete links, and changes some field
 * handlers.
 */
function search_api_saved_searches_views_data_alter(array &$data) {
  // Relationship: settings => index.
  $data['search_api_saved_searches_settings']['index_id']['relationship'] = array(
    'base' => 'search_api_index',
    'base field' => 'machine_name',
    'title' => t('Search index'),
    'label' => t('search index'),
  );
  // Relationship: search => user.
  $data['search_api_saved_search']['uid']['relationship'] = array(
    'base' => 'users',
    'base field' => 'uid',
    'title' => t('User'),
    'label' => t('user'),
  );
  // Relationship: search => settings.
  $data['search_api_saved_search']['settings_id']['relationship'] = array(
    'base' => 'search_api_saved_searches_settings',
    'base field' => 'delta',
    'title' => t('Settings'),
    'label' => t('settings'),
  );
  // Proper field type for notify_interval.
  $data['search_api_saved_search']['notify_interval']['field']['handler'] = 'SearchApiSavedSearchesViewsHandlerFieldInterval';
  $data['search_api_saved_search']['notify_interval']['field']['additional fields'] = array('id');
  // Use our own handler so we can link the name to the search results.
  $data['search_api_saved_search']['name']['field']['handler'] = 'SearchApiSavedSearchesViewsHandlerFieldName';
  $data['search_api_saved_search']['name']['field']['additional fields'] = array('id');

  // We have to do this here, not in hook_views_data(), since the table itself
  // comes from another module and one definition would overwrite the other.
  $data['search_api_saved_search']['edit_link']['field'] = array(
    'title' => t('Edit link'),
    'help' => t('Display a link that allows the user to edit the saved search, if they have the necessary permissions.'),
    'handler' => 'SearchApiSavedSearchesViewsHandlerFieldLink',
    'additional fields' => array('id'),
  );
  $data['search_api_saved_search']['delete_link']['field'] = array(
    'title' => t('Delete link'),
    'help' => t('Display a link that allows the user to delete the saved search, if they have the necessary permissions.'),
    'handler' => 'SearchApiSavedSearchesViewsHandlerFieldLink',
    'additional fields' => array('id'),
  );
  $data['search_api_saved_search']['results']['field'] = array(
    'title' => t('Results'),
    'help' => t('The saved search results of this search.'),
    'handler' => 'entity_views_handler_field_text',
    'additional fields' => array('id'),
    'type' => 'list<token>',
  );
}
