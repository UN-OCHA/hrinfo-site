<?php

/**
 * @file
 * Drush functions.
 */

/**
 * Implements hook_drush_help().
 */
function hr_tools_drush_help($section) {
  switch ($section) {
    case 'drush:node-access-rebuild':
      return dt('Rebuild node access permissions.');
  }
}

/**
 * Implements hook_drush_command().
 */
function hr_tools_drush_command() {
  $items = array();

  $items['hr-tools-access-rebuild'] = array(
    'description' => 'Rebuild the node access table',
    'callback' => 'drush_hr_tools_access_rebuild',
    'options' => array(
      'offset' => array(
        'description' => 'The amount of records to skip. Defaults to 0.',
        'example-value' => '30',
      ),
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('hrnar'),
  );
  $items['hr-tools-truncate-cache-tables'] = array(
    'description' => 'Truncate all database cache tables',
    'callback' => 'drush_hr_tools_truncate_cache_tables',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('hrtct'),
  );

  return $items;
}

/**
 * Access rebuild callback.
 */
function drush_hr_tools_access_rebuild() {
  if (!drush_bootstrap_to_phase(DRUSH_BOOTSTRAP_DRUPAL_DATABASE)) {
    return drush_set_error('DRUPAL_SITE_NOT_FOUND', dt('You need to specify an alias or run this command within a drupal site.'));
  }

  $offset = drush_get_option('offset', 0);

  if (count(module_implements('node_grants'))) {
    $batch = array(
      'title' => t('Rebuilding content access permissions'),
      'operations' => array(
        // @codingStandardsIgnoreLine
        array('_drush_hr_tools__node_access_rebuild_batch_operation', array($offset)),
      ),
      'finished' => '_drush_hr_tools__node_access_rebuild_batch_finished',
    );
    batch_set($batch);
    $batch = & batch_get();
    drush_backend_batch_process();
  }
  if (!isset($batch)) {
    drupal_set_message(t('Content permissions have been rebuilt.'));
    node_access_needs_rebuild(FALSE);
    cache_clear_all();
  }
}

/**
 * Batch handler.
 */
// @codingStandardsIgnoreLine
function _drush_hr_tools__node_access_rebuild_batch_operation($offset = 0, &$context) {
  if (empty($context['sandbox'])) {
    // Initiate multistep processing.
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query('SELECT COUNT(nid) FROM {node}')->fetchField();
    $context['message'] = 'Starting node access rebuild.';

    if ($offset > 0) {
      $record = db_query_range('SELECT nid FROM {node}', $offset, 1)->fetchField();
      if ($record) {
        $context['sandbox']['current_node'] = $record;
        $context['sandbox']['progress'] = $offset;
        $context['message'] = 'Starting node access rebuild from ' . $offset;
      }
      else {
        drush_print('Nothing to process.');
        return;
      }
    }
  }

  // Process the next 20 nodes.
  $limit = 50;
  $nids = db_query_range("SELECT nid FROM {node} WHERE nid > :nid ORDER BY nid ASC", 0, $limit, array(':nid' => $context['sandbox']['current_node']))->fetchCol();
  $nodes = node_load_multiple($nids, array(), TRUE);
  foreach ($nodes as $nid => $node) {
    // To preserve database integrity, only acquire grants if the node
    // loads successfully.
    if (!empty($node)) {
      node_access_acquire_grants($node);
    }
    $context['sandbox']['progress']++;
    $context['sandbox']['current_node'] = $nid;
  }

  // Multistep processing : report progress.
  if ($context['sandbox']['progress'] <= $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    $context['message'] = 'Progress ' . $context['sandbox']['progress'] . '/' . $context['sandbox']['max'];
  }
}

/**
 * Finished callback.
 */
function _drush_hr_tools__node_access_rebuild_batch_finished($success, $results, $operations) {
  if ($success) {
    drush_log(t('The content access permissions have been rebuilt.'));
    node_access_needs_rebuild(FALSE);
  }
  else {
    drush_log(t('The content access permissions have not been properly rebuilt.'), 'error');
  }
  cache_clear_all();
}

/**
 * Callback that explicitly truncates all cache tables.
 */
function drush_hr_tools_truncate_cache_tables() {
  if (!drush_bootstrap_to_phase(DRUSH_BOOTSTRAP_DRUPAL_DATABASE)) {
    return drush_set_error('DRUPAL_SITE_NOT_FOUND', dt('You need to specify an alias or run this command within a drupal site.'));
  }

  $tables = array(
    'cache',
    'cache_advagg_aggregates',
    'cache_advagg_info',
    'cache_block',
    'cache_bootstrap',
    'cache_entity_comment',
    'cache_entity_fieldable_panels_pane',
    'cache_entity_file',
    'cache_entity_node',
    'cache_entity_og_membership',
    'cache_entity_og_membership_type',
    'cache_entity_restful_token_auth',
    'cache_entity_taxonomy_term',
    'cache_entity_taxonomy_vocabulary',
    'cache_entity_user',
    'cache_features',
    'cache_feeds_http',
    'cache_field',
    'cache_filter',
    'cache_form',
    'cache_image',
    'cache_libraries',
    'cache_menu',
    'cache_page',
    'cache_panels',
    'cache_path',
    'cache_restclient',
    'cache_restful',
    'cache_rules',
    'cache_search_api_solr',
    'cache_token',
    'cache_update',
    'cache_variable',
    'cache_views',
    'cache_views_data',
    'ctools_css_cache',
    'ctools_object_cache',
    'restful_cache_fragment',
    'views_content_cache',
    'views_data_export_object_cache',
  );

  foreach ($tables as $table) {
    db_truncate($table)->execute();
    drush_log(t('Truncated table @table.', array('@table' => $table)));
  }

  return;
}
