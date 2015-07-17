<?php

/**
 * @file
 * Drush commands for Feeds module.
 */

/**
 * Implements hook_drush_command().
 *
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return array
 *   An associative array describing your command(s).
 */
function feeds_drush_command() {
  $items = array();

  $items['feeds-list-importers'] = array(
    'description' => 'Displays the configs of all importers.',
    'examples' => array(
      'drush feeds-list',
    ),
  );

  $items['feeds-list-feeds'] = array(
    'description' => 'Displays all instances of all Feeds of a given importer (passed as arg).',
    'arguments' => array(
      'importer' => 'The name of the Feeds importer whose instances will be listed. Optional.',
    ),
    'examples' => array(
      'drush feeds-list-all' => 'List all instances of all feeds.',
      'drush feeds-list-all rss_feed' => 'List all feed instances of the rss_feed importer.',
    ),
    'options' => array(
      'limit' => 'Only list [limit] feeds. Optional.',
    ),
  );

  $items['feeds-import'] = array(
    'description' => 'Imports a feed.',
    'arguments' => array(
      'importer' => 'The name of the Feeds importer that will be refreshed. Mandatory.',
    ),
    'options' => array(
      'nid' => 'The nid of the Feeds importer that will be refreshed. Optional.',
      'file' => 'The file to import. Optional.',
      'url' => 'The URL to import. Optional.',
      'stdin' => 'Read the file to import from stdin. Optional.',
    ),
    'examples' => array(
      'drush feeds-import my_importer' => 'Import the feed my_importer.',
      'drush feeds-import my_importer --nid=2' => 'Import my_importer associated with nid 2.',
    ),
  );

  $items['feeds-import-all'] = array(
    'description' => 'Import all instances of feeds of the given type.',
    'arguments' => array(
      'importer' => 'The name of the Feeds importer that will be refreshed. Omitting the importer will cause all instances of all feeds to be imported.',
    ),
    'examples' => array(
      'drush feeds-import-all' => 'Import all instances of all feeds.',
      'drush feeds-import-all my_importer' => 'Import all instances of the importer my_importer.',
      'drush feeds-import-all my_importer --limit 10' => 'Import 10 instances the feed my_importer.',
    ),
    'options' => array(
      'limit' => 'Only import [limit] Feeds importers. Optional.',
    ),
  );

  $items['feeds-clear'] = array(
    'description' => 'Clears a feed.',
    'arguments' => array(
      'importer' => 'The name of the Feeds importer that will be cleared. Mandatory.',
    ),
    'options' => array(
      'nid' => 'The nid of the Feeds importer that will be clear. Optional.',
    ),
    'examples' => array(
      'drush feeds-clear my_importer',
      'drush feeds-clear my_importer --nid=2',
    ),
  );

  $items['feeds-enable'] = array(
    'description' => 'Enables one or more Feeds importers.',
    'arguments' => array(
      'importers' => 'A space delimited list of Feeds importers. Mandatory.',
    ),
    'examples' => array(
      'drush feeds-enable importer_1 importer_2',
    ),
  );

  $items['feeds-disable'] = array(
    'description' => 'Disable one or more Feeds importers.',
    'arguments' => array(
      'importers' => 'A space delimited list of Feeds importers. Mandatory.',
    ),
    'examples' => array(
      'drush feeds-disable importer_1 importer_2',
    ),
  );

  $items['feeds-delete'] = array(
    'description' => 'Deletes one or more Feeds importers.',
    'arguments' => array(
      'importers' => 'A space delimited list of Feeds importers. Mandatory.',
    ),
    'examples' => array(
      'drush feeds-delete importer_1 importer_2',
    ),
  );

  $items['feeds-revert'] = array(
    'description' => 'Reverts one or more Feeds importers.',
    'arguments' => array(
      'importers' => 'A space delimited list of Feeds importers. Mandatory.',
    ),
    'examples' => array(
      'drush feeds-revert importer_1 importer_2',
    ),
  );

  return $items;
}

/**
 * Prints a list of all Feeds importers.
 */
function drush_feeds_list_importers() {
  if (!$importers = feeds_importer_load_all(TRUE)) {
    drush_print(dt('No importers available.'));
    return;
  }

  $rows = array();

  $rows[] = array(
    dt('Name'),
    dt('Description'),
    dt('Attached to'),
    dt('Status'),
    dt('State'),
  );

  foreach ($importers as $importer) {
    if ($importer->export_type == EXPORT_IN_CODE) {
      $state = dt('Default');
    }
    else if ($importer->export_type == EXPORT_IN_DATABASE) {
      $state = dt('Normal');
    }
    else if ($importer->export_type == (EXPORT_IN_CODE | EXPORT_IN_DATABASE)) {
      $state = dt('Overridden');
    }

    $rows[] = array(
      $importer->config['name'] . ' (' . $importer->id . ')',
      $importer->config['description'],
      $importer->config['content_type'] ? dt(node_type_get_name('name', $importer->config['content_type'])) : dt('none'),
      $importer->disabled ? dt('Disabled') : dt('Enabled'),
      $state,
    );
  }

  drush_print_table($rows, TRUE);
}

/**
 * Lists all feeds.
 *
 * @param string $importer
 *   (optional) The importer id.
 */
function drush_feeds_list_feeds($importer = NULL) {
  if (!$limit = drush_get_option('limit')) {
    $limit = 2147483647;
  }

  $rows = array();

  $rows[] = array(
    dt('ID'),
    dt('Feed NID'),
    dt('Imported'),
    dt('Feed Source'),
    dt('Process in Background'),
  );

  foreach (_drush_feeds_get_all($importer, $limit) as $feed) {
    $feed_config = feeds_source($feed->id, $feed->feed_nid)->importer->getConfig();

    $rows[] = array(
      $feed->id,
      $feed->feed_nid,
      $feed->imported ? date('Y-m-d H:i:s', $feed->imported) : dt('Never'),
      is_scalar($feed->source) ? $feed->sorce : gettype($feed->source),
      !empty($feed_config['process_in_background']) ? dt('Yes') : dt('No'),
    );
  }

  drush_print_table($rows, TRUE);
}

/**
 * Imports a given importer/source.
 *
 * @param string $importer
 *   (optional) The importer id to filter on.
 */
function drush_feeds_import($importer = NULL) {
  if (!strlen($importer)) {
    drush_print(dt('The importer importer is required.'));
    return FALSE;
  }

  if (!$feed_nid = drush_get_option('nid')) {
    $feed_nid = 0;
  }

  try {
    $source = feeds_source($importer, $feed_nid)->existing();
  }
  catch (FeedsNotExistingException $e) {
    drush_print(dt('The feed @importer: @nid does not exist.', array('@importer' => $importer, '@nid' => $feed_nid)));
    return FALSE;
  }

  if ($filename = drush_get_option('file')) {
    if (!is_file($filename)) {
      drush_print(dt('The file @file does not exist.', array('@file' => $filename)));
      return FALSE;
    }
    $result = new FeedsFileFetcherResult($filename);
  }
  elseif ($url = drush_get_option('url')) {
    $result = new FeedsHTTPFetcherResult($url);
  }
  elseif (drush_get_option('stdin')) {
    $result = new FeedsFetcherResult(file_get_contents('php://stdin'));
  }
  else {
    _drush_feeds_create_import_batch($importer, $feed_nid);
    drush_backend_batch_process();
    return;
  }

  try {
    $source->pushImport($result);
  }
  catch (Exception $e) {
    drush_print($e->getMessage());
    return FALSE;
  }
}

/**
 * Imports all feeds.
 *
 * @param string $importer
 *   (optional) The importer id to filter on.
 */
function drush_feeds_import_all($importer = NULL) {
  if (!$limit = drush_get_option('limit')) {
    $limit = 2147483647;
  }

  foreach (_drush_feeds_get_all($importer, $limit) as $feed) {
    if (!isset($feed->source) || !strlen($feed->source)) {
      continue;
    }

    try {
      $source = feeds_source($feed->id, $feed->feed_nid)->existing();
    }
    catch (FeedsNotExistingException $e) {
      continue;
    }

    _drush_feeds_create_import_batch($feed->id, $feed->feed_nid);
  }

  drush_backend_batch_process();
}

/**
 * Creates a batch job for an import.
 *
 * @param string $importer
 *   The importer id.
 * @param int $feed_nid
 *   The feed node id.
 */
function _drush_feeds_create_import_batch($importer, $feed_nid) {
  $feed_node = FALSE;
  if ($feed_nid) {
    if (!$feed_node = node_load($feed_nid)) {
      drush_print(dt('The feed node @importer: @nid does not exist.', array('@importer' => $importer, '@nid' => $feed_nid)));
      return FALSE;
    }
  }

  $title = $feed_node ? $feed_node->title . ' (' . $importer . ')' : $importer;

  drush_log(dt('Importing: @title', array('@title' => $title)), 'ok');

  $batch = array(
    'title' => '',
    'operations' => array(
      array('feeds_batch', array('import', $importer, $feed_nid)),
    ),
    'progress_message' => '',
  );

  batch_set($batch);
}

/**
 * Clears a Feeds importer.
 *
 * @param string $importer
 *   The importer id to clean.
 */
function drush_feeds_clear($importer = NULL) {
  if (!strlen($importer)) {
    drush_print(dt('The importer importer is required.'));
    return FALSE;
  }

  if (!$feed_nid = drush_get_option('nid')) {
    $feed_nid = 0;
  }

  try {
    feeds_source($importer, $feed_nid)->existing();
  }
  catch (FeedsNotExistingException $e) {
    drush_print(dt('The feed @importer: @nid does not exist.', array('@importer' => $importer, '@nid' => $feed_nid)));
    return FALSE;
  }

  $batch = array(
    'title' => dt('Clearing !importer', array('!importer' => $importer)),
    'operations' => array(
      array('feeds_batch', array('clear', $importer, $feed_nid)),
    ),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Deletes a set of Feeds importers.
 */
function drush_feeds_delete() {
  $all = feeds_importer_load_all(TRUE);
  $to_delete = array_intersect_key($all, array_flip(func_get_args()));
  $missing = array_diff(func_get_args(), array_keys($all));

  if ($missing) {
    drush_print(dt('The following importers are missing: !importers', array('!importers' => implode(', ', $missing))));
  }

  if ($to_delete) {
    drush_print(dt('The following feeds will be deleted: !importers', array('!importers' => implode(', ', array_keys($to_delete)))));
  }
  else {
    return drush_print(dt('There are no importers to delete.'));
  }

  if (!drush_confirm(dt('Do you really want to continue?'))) {
    return drush_log(dt('Aborting.'));
  }

  foreach ($to_delete as $importer) {
    $importer->delete();
    drush_log(dt('!importer was deleted successfully.', array('!importer' => $importer->id)), 'ok');
  }

  feeds_cache_clear();
}

/**
 * Reverts a set of feeds.
 */
function drush_feeds_revert() {
  $all = feeds_importer_load_all(TRUE);
  $missing = array_diff(func_get_args(), array_keys($all));
  $to_revert = array_intersect_key($all, array_flip(func_get_args()));
  $cant_revert = array();

  // Filter out non-overridden importers.
  foreach ($to_revert as $delta => $importer) {
    if ($importer->export_type !== (EXPORT_IN_CODE | EXPORT_IN_DATABASE)) {
      unset($to_revert[$delta]);
      $cant_revert[$importer->id] = $importer->id;
    }
  }

  if ($missing) {
    drush_print(dt('The following importers are missing: !importers', array('!importers' => implode(', ', $missing))));
  }

  if ($cant_revert) {
    drush_print(dt('The following feeds will be cannot be reverted: !importers', array('!importers' => implode(', ', array_keys($cant_revert)))));
  }

  if ($to_revert) {
    drush_print(dt('The following feeds will be reverted: !importers', array('!importers' => implode(', ', array_keys($to_revert)))));
  }
  else {
    return drush_print(dt('There are no importers to revert.'));
  }

  if (!drush_confirm(dt('Do you really want to continue?'))) {
    return drush_log(dt('Aborting.'));
  }

  foreach ($to_revert as $importer) {
    $importer->delete();
    drush_log(dt('!importer was reverted successfully.', array('!importer' => $importer->id)), 'ok');
  }

  feeds_cache_clear();
}

/**
 * Enables a set of Feeds importers.
 */
function drush_feeds_enable() {
  $all = array_keys(feeds_importer_load_all(TRUE));
  $enabled = array_keys(feeds_importer_load_all());
  $missing = array_diff(func_get_args(), $all);
  $to_enable = array_diff(func_get_args(), $enabled, $missing);
  $already_enabled = array_intersect(func_get_args(), $enabled);

  if ($missing) {
    drush_print(dt('The following importers are missing: !importers', array('!importers' => implode(', ', $missing))));
  }

  if ($already_enabled) {
    drush_print(dt('The following importers are already enabled: !importers', array('!importers' => implode(', ', $already_enabled))));
  }

  if ($to_enable) {
    drush_print(dt('The following importers will be enabled: !importers', array('!importers' => implode(', ', $to_enable))));
  }
  else {
    return drush_print(dt('There are no importers to enable.'));
  }

  if (!drush_confirm(dt('Do you really want to continue?'))) {
    return drush_log(dt('Aborting.'));
  }

  $disabled = variable_get('default_feeds_importer', array());

  foreach ($to_enable as $importer) {
    unset($disabled[$importer]);
    drush_log(dt('!importer has been enabled.', array('!importer' => $importer)), 'ok');
  }

  variable_set('default_feeds_importer', $disabled);
}

/**
 * Disables a set of Feeds importers.
 */
function drush_feeds_disable() {
  $all = array_keys(feeds_importer_load_all(TRUE));
  $enabled = array_keys(feeds_importer_load_all());
  $to_disable = array_intersect(func_get_args(), $enabled);
  $missing = array_diff(func_get_args(), $all);
  $already_disabled = array_diff(func_get_args(), $enabled, $missing);

  if ($missing) {
    drush_print(dt('The following importers are missing: !importers', array('!importers' => implode(', ', $missing))));
  }

  if ($already_disabled) {
    drush_print(dt('The following importers are already disabled: !importers', array('!importers' => implode(', ', $already_disabled))));
  }

  if ($to_disable) {
    drush_print(dt('The following importers will be disabled: !importers', array('!importers' => implode(', ', $to_disable))));
  }
  else {
    return drush_print(dt('There are no importers to disable.'));
  }

  if (!drush_confirm(dt('Do you really want to continue?'))) {
    return drush_log(dt('Aborting.'));
  }

  $disabled = variable_get('default_feeds_importer', array());
  foreach ($to_disable as $importer) {
    $disabled[$importer] = TRUE;
    drush_log(dt('!importer has been disabled.', array('!importer' => $importer)), 'ok');
  }
  variable_set('default_feeds_importer', $disabled);
  feeds_cache_clear();
}

/**
 * Returns all feed instances filtered by an optional importer.
 *
 * @param string $importer
 *   (optional) The importer id.
 * @param int $limit
 *   (optional) The number of feeds to return.
 *
 * @return DatabaseStatementInterface
 *   A list of feeds objects.
 */
function _drush_feeds_get_all($importer = NULL, $limit = 2147483647) {
  if (isset($importer)) {
    return db_query_range("SELECT * FROM {feeds_source} WHERE id = :importer ORDER BY imported ASC", 0, $limit, array(':importer' => $importer));
  }

  return db_query_range("SELECT * FROM {feeds_source} ORDER BY imported ASC", 0, $limit);
}
