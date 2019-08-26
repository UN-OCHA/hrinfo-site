<?php

/**
 * @file
 * Hooks provided by the Search API saved searches module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Acts on saved searches being loaded from the database.
 *
 * This hook is invoked during saved search loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param array $searches
 *   An array of saved search entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_search_api_saved_search_load(array $searches) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($searches)));
  foreach ($result as $record) {
    $searches[$record->pid]->foo = $record->foo;
  }
}

/**
 * Responds when a saved search is inserted.
 *
 * This hook is invoked after the saved search is inserted into the database.
 *
 * @param SearchApiSavedSearch $search
 *   The saved search that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_search_api_saved_search_insert(SearchApiSavedSearch $search) {
  db_insert('mytable')
    ->fields(array(
      'id' => entity_id('search_api_saved_search', $search),
      'extra' => print_r($search, TRUE),
    ))
    ->execute();
}

/**
 * Acts on a saved search being inserted or updated.
 *
 * This hook is invoked before the saved search is saved to the database.
 *
 * @param SearchApiSavedSearch $search
 *   The saved search that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_search_api_saved_search_presave(SearchApiSavedSearch $search) {
  $search->name = 'foo';
}

/**
 * Responds to a saved search being updated.
 *
 * This hook is invoked after the saved search has been updated in the database.
 *
 * @param SearchApiSavedSearch $search
 *   The saved search that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_search_api_saved_search_update(SearchApiSavedSearch $search) {
  db_update('mytable')
    ->fields(array('extra' => print_r($search, TRUE)))
    ->condition('id', entity_id('search_api_saved_search', $search))
    ->execute();
}

/**
 * Responds to saved search deletion.
 *
 * This hook is invoked after the saved search has been removed from the database.
 *
 * @param SearchApiSavedSearch $search
 *   The saved search that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_search_api_saved_search_delete(SearchApiSavedSearch $search) {
  db_delete('mytable')
    ->condition('pid', entity_id('search_api_saved_search', $search))
    ->execute();
}

/**
 * Acts on saved search settings being loaded from the database.
 *
 * This hook is invoked during settings entity loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param array $entities
 *   An array of settings entity entities being loaded, keyed by delta.
 *
 * @see hook_entity_load()
 */
function hook_search_api_saved_search_settings_load(array $entities) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Responds when a settings entity is inserted.
 *
 * This hook is invoked after the settings entity is inserted into the database.
 *
 * @param SearchApiSavedSearchSettings $settings
 *   The settings entity that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_search_api_saved_search_settings_insert(SearchApiSavedSearchSettings $settings) {
  db_insert('mytable')
    ->fields(array(
      'id' => entity_id('search_api_saved_search_settings', $settings),
      'extra' => print_r($settings, TRUE),
    ))
    ->execute();
}

/**
 * Acts on a settings entity being inserted or updated.
 *
 * This hook is invoked before the settings entity is saved to the database.
 *
 * @param SearchApiSavedSearchSettings $settings
 *   The settings entity that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_search_api_saved_search_settings_presave(SearchApiSavedSearchSettings $settings) {
  $settings->options['foo'] = 'bar';
}

/**
 * Responds to a settings entity being updated.
 *
 * This hook is invoked after the settings entity has been updated in the
 * database.
 *
 * @param SearchApiSavedSearchSettings $settings
 *   The settings entity that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_search_api_saved_search_settings_update(SearchApiSavedSearchSettings $settings) {
  db_update('mytable')
    ->fields(array('extra' => print_r($settings, TRUE)))
    ->condition('id', entity_id('search_api_saved_search_settings', $settings))
    ->execute();
}

/**
 * Responds to settings entity deletion.
 *
 * This hook is invoked after the settings entity has been removed from the
 * database.
 *
 * @param SearchApiSavedSearchSettings $settings
 *   The settings entity that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_search_api_saved_search_settings_delete(SearchApiSavedSearchSettings $settings) {
  db_delete('mytable')
    ->condition('pid', entity_id('search_api_saved_search_settings', $settings))
    ->execute();
}

/**
 * Define default settings entity configurations.
 *
 * @return
 *   An array of default saved search settings, keyed by deltas.
 *
 * @see hook_default_search_api_saved_search_settings_alter()
 */
function hook_default_search_api_saved_search_settings() {
  $defaults['main'] = entity_create('search_api_saved_search_settings', array(
    // …
  ));
  return $defaults;
}

/**
 * Alter default settings entity configurations.
 *
 * @param array $defaults
 *   An array of default saved search settings, keyed by deltas.
 *
 * @see hook_default_search_api_saved_search_settings()
 */
function hook_default_search_api_saved_search_settings_alter(array &$defaults) {
  $defaults['main']->options['foo'] = 'bar';
}

/**
 * Alter or react on new results found for a saved search.
 *
 * The results will then be used to send a mail to the saved search's creator.
 *
 * @param array $results
 *   An array of items representing new results for the search. The items that
 *   would be sent to the user are passed as loaded items, all others are passed
 *   only by ID.
 * @param SearchApiSavedSearch $search
 *   The saved search that was executed.
 */
function hook_search_api_saved_searches_new_results_alter(array &$results, SearchApiSavedSearch $search) {
  // Remove all results with an ID that is a multiple of 6.
  foreach ($results as $id => $result) {
    // Use is_scalar() to make sure we only remove loaded items that would be
    // sent to the user.
    if (!is_scalar($result) && $id % 6 == 0) {
      unset($results[$id]);
    }
  }
}

/**
 * Alters the name assigned to a newly created saved search.
 *
 * @param string $name
 *   The suggested name of the saved search. Likely the search term, or
 *   the translated string "Saved search".
 * @param array $query
 *   An associative array with the following keys:
 *   - index_id: The machine name of the index the search was run on.
 *   - keys: The parsed search keys.
 *   - original_keys: The keys as entered by the user.
 *   - fields: The fulltext fields searched by the query.
 *   - filters: An array of filters set for the query, as returned by
 *     SearchApiQueryFilterInterface::getFilters().
 *   - options: All options set on the query.
 */
function hook_search_api_saved_search_create_name_alter(&$name, array $query) {
  $name = 'foo';
}

/**
 * @} End of "addtogroup hooks".
 */
