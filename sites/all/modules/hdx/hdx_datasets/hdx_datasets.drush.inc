<?php

/**
 * @file
 * hdx_datasets module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hdx_datasets_drush_command() {
  $items = array();

  $items['hdx-datasets-enable-hdx-datasets'] = array(
    'description' => "Enable the hdx-dataset feature",
    'drupal dependencies' => array(),
    'aliases' => array(),
    'arguments' => array(
      'bundle' => 'Space type to enable the datasets feature, ej. hr_operation',
    ),
  );

  $items['hdx-datasets-disable-hr-datasets'] = array(
    'description' => "Disable the hr-dataset feature",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  $items['hdx-datasets-features-cleanup'] = array(
    'description' => "Cleanup the hdx features datasets migration",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  $items['hdx-datasets-hr-menus-cleanup'] = array(
    'description' => "Cleanup the hr menus datasets migration",
    'drupal dependencies' => array(),
    'aliases' => array(),
    'arguments' => array(
      'bundle' => 'Space type to clean up the menu, ej. hr_operation',
    ),
  );

  return $items;
}

/**
 * Drush command to disable the hdx datasets for a particular content type.
 */
function drush_hdx_datasets_enable_hdx_datasets($bundle) {
  if (empty($bundle)) {
    drush_log('No space type specified', 'error');
    return;
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle);
  $result = $query->execute();

  if (empty($result['node'])) {
    drush_log('No spaces found', 'ok');
    return;
  }

  $registry = og_features_get_registry();

  $batch = array(
    'operations' => array(
      array(
        'drush_hdx_datasets_enable_callback',
        array(
          array_keys($result['node']),
          $registry
        ),
      ),
    ),
    'finished' => 'drush_hdx_datasets_batch_finished',
    'title' => t('Enable HDX features'),
    'init_message' => t('Preparing...'),
    'progress_message' => t('Enabling features...'),
    'error_message' => t('HDX features enable process resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Callback to enable the HDX datasets.
 */
function drush_hdx_datasets_enable_callback($node_ids, $registry, &$context) {
  $limit = 250;
  $context['finished'] = 0;

  if (!isset($context['sandbox']['node_ids'])) {
    $context['sandbox']['node_ids'] = $node_ids;
    $context['sandbox']['total_nodes'] = count($node_ids);
    $context['results']['count'] = 0;
  }

  if ($nodes_pending = count($context['sandbox']['node_ids'])) {
    $actual_limit = min($nodes_pending, $limit);
    $node_info = array_slice(
      $context['sandbox']['node_ids'],
      $context['results']['count'],
      $actual_limit,
      TRUE
    );
    $nodes = node_load_multiple($node_info);
    foreach($nodes as $node) {
      $disabled_features = isset($node->features_disabled) ? $node->features_disabled : array();
      $enabled_features = drupal_map_assoc(array_keys(array_diff_key($registry, $disabled_features)));
      $enabled_features['hdx_datasets'] = 'hdx_datasets';
      // Save the new settings.
      og_features_save_feature_settings($node->nid, 'node', $enabled_features);
      // Alert other modules about the change.
      module_invoke_all('og_features_toggle', $node, $node->nid, 'node', $enabled_features);
    }

    $context['results']['count'] += $actual_limit;
    $context['finished'] = $context['results']['count'] / $context['sandbox']['total_nodes'];
  }
  else {
    $context['finished'] = 1;
  }

  $context['message'] = t(
    'Processed @count of @total nodes.',
    array(
      '@count' => $context['results']['count'],
      '@total' => $context['sandbox']['total_nodes'],
    )
  );
}

/**
 * Drush command to disable the hr datasets in a batch process.
 */
function drush_hdx_datasets_disable_hr_datasets() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', array('hr_operation', 'hr_bundle', 'hr_disaster', 'hr_sector', 'hr_space'), 'IN');
  $result = $query->execute();

  if (empty($result['node'])) {
    drush_log('No spaces found', 'ok');
    return;
  }

  $registry = og_features_get_registry();

  $batch = array(
    'operations' => array(
      array(
        'drush_hr_datasets_disable_hr_datasets_callback',
        array(
          array_keys($result['node']),
          $registry
        ),
      ),
    ),
    'finished' => 'drush_hdx_datasets_batch_finished',
    'title' => t('Disable HR dataset feature'),
    'init_message' => t('Preparing...'),
    'progress_message' => t('Disabling features...'),
    'error_message' => t('HR datasets disable process resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Callback function to disable the HR datasets.
 */
function drush_hr_datasets_disable_hr_datasets_callback($node_ids, $registry, &$context) {
  $limit = 250;
  $context['finished'] = 0;

  if (!isset($context['sandbox']['node_ids'])) {
    $context['sandbox']['node_ids'] = $node_ids;
    $context['sandbox']['total_nodes'] = count($node_ids);
    $context['results']['count'] = 0;
  }

  if ($nodes_pending = count($context['sandbox']['node_ids'])) {
    $actual_limit = min($nodes_pending, $limit);
    $node_info = array_slice(
      $context['sandbox']['node_ids'],
      $context['results']['count'],
      $actual_limit,
      TRUE
    );
    $nodes = node_load_multiple($node_info);
    foreach($nodes as $node) {
      $disabled_features = isset($node->features_disabled) ? $node->features_disabled : array();
      $enabled_features = drupal_map_assoc(array_keys(array_diff_key($registry, $disabled_features)));
      // Disable the hr_datasets feature, if it wasn't enabled already, there's
      // no need to resave them.
      if (isset($enabled_features['hr_datasets'])) {
        unset($enabled_features['hr_datasets']);
        // Save the new settings.
        og_features_save_feature_settings($node->nid, 'node', $enabled_features);
        // Alert other modules about the change.
        module_invoke_all('og_features_toggle', $node, $node->nid, 'node', $enabled_features);
      }
    }

    $context['results']['count'] += $actual_limit;
    $context['finished'] = $context['results']['count'] / $context['sandbox']['total_nodes'];
  }
  else {
    $context['finished'] = 1;
  }

  $context['message'] = t(
    'Processed @count of @total nodes.',
    array(
      '@count' => $context['results']['count'],
      '@total' => $context['sandbox']['total_nodes'],
    )
  );
}

/**
 * Drush command to disable wrongly enabled hdx datasets for non operations.
 */
function drush_hdx_datasets_features_cleanup() {
  // Make sure the hdx dataset feature is disabled for non operations.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', array('hr_bundle', 'hr_disaster', 'hr_sector', 'hr_space'), 'IN');
  $result = $query->execute();
  if (empty($result['node'])) {
    drush_log('No spaces found', 'ok');
    return;
  }

  $registry = og_features_get_registry();

  $batch = array(
    'operations' => array(
      array(
        'drush_hdx_datasets_features_cleanup_callback',
        array(
          array_keys($result['node']),
          $registry
        ),
      ),
    ),
    'finished' => 'drush_hdx_datasets_batch_finished',
    'title' => t('Cleaning up HDX migration'),
    'init_message' => t('Preparing...'),
    'progress_message' => t('Cleaning up...'),
    'error_message' => t('HR cleanup process resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Callback function to disable the HR datasets.
 */
function drush_hdx_datasets_features_cleanup_callback($node_ids, $registry, &$context) {
  $limit = 500;
  $context['finished'] = 0;

  if (!isset($context['sandbox']['node_ids'])) {
    $context['sandbox']['node_ids'] = $node_ids;
    $context['sandbox']['total_nodes'] = count($node_ids);
    $context['results']['count'] = 0;
  }

  if ($nodes_pending = count($context['sandbox']['node_ids'])) {
    $actual_limit = min($nodes_pending, $limit);
    $node_info = array_slice(
      $context['sandbox']['node_ids'],
      $context['results']['count'],
      $actual_limit,
      TRUE
    );
    $nodes = node_load_multiple($node_info);
    foreach($nodes as $node) {
      $disabled_features = isset($node->features_disabled) ? $node->features_disabled : array();
      $enabled_features = drupal_map_assoc(array_keys(array_diff_key($registry, $disabled_features)));
      // Disable the hdx_datasets feature, if it wasn't enabled already, there's
      // no need to resave them.
      if (isset($enabled_features['hdx_datasets'])) {
        unset($enabled_features['hdx_datasets']);
        // Save the new settings.
        og_features_save_feature_settings($node->nid, 'node', $enabled_features);

        // Force menu cleanup.
        menu_link_delete(NULL, 'node/'.$node->nid.'/hdx-datasets');
      }
    }

    $context['results']['count'] += $actual_limit;
    $context['finished'] = $context['results']['count'] / $context['sandbox']['total_nodes'];
  }
  else {
    $context['finished'] = 1;
  }

  $context['message'] = t(
    'Processed @count of @total nodes.',
    array(
      '@count' => $context['results']['count'],
      '@total' => $context['sandbox']['total_nodes'],
    )
  );
}

/**
 * Drush command to remove unneeded hr dataset menus.
 */
function drush_hdx_datasets_hr_menus_cleanup($bundle = NULL) {
  if (empty($bundle)) {
    drush_log('No space type specified', 'error');
    return;
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle);
  $result = $query->execute();

  if (empty($result['node'])) {
    drush_log('No spaces found', 'ok');
    return;
  }

  $batch = array(
    'operations' => array(
      array(
        'drush_hdx_datasets_hr_menus_cleanup_callback',
        array(
          array_keys($result['node'])
        ),
      ),
    ),
    'finished' => 'drush_hdx_datasets_batch_finished',
    'title' => t('Cleaning up HDX migration'),
    'init_message' => t('Preparing...'),
    'progress_message' => t('Cleaning up...'),
    'error_message' => t('HR cleanup process resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Callback function to disable the HR datasets.
 */
function drush_hdx_datasets_hr_menus_cleanup_callback($node_ids, &$context) {
  $limit = 200;
  $context['finished'] = 0;

  if (!isset($context['sandbox']['node_ids'])) {
    $context['sandbox']['node_ids'] = $node_ids;
    $context['sandbox']['total_nodes'] = count($node_ids);
    $context['results']['count'] = 0;
  }

  if ($nodes_pending = count($context['sandbox']['node_ids'])) {
    $actual_limit = min($nodes_pending, $limit);
    $node_info = array_slice(
      $context['sandbox']['node_ids'],
      $context['results']['count'],
      $actual_limit,
      TRUE
    );
    $nodes = node_load_multiple($node_info);
    foreach($nodes as $node) {
      $disabled_features = isset($node->features_disabled) ? $node->features_disabled : array();
      if (isset($disabled_features['hr_datasets'])) {
        // Force menu cleanup.
        menu_link_delete(NULL, 'node/'.$node->nid.'/datasets');
      }
      if (isset($disabled_features['hr_contacts'])) {
        // Force menu cleanup.
        menu_link_delete(NULL, 'node/'.$node->nid.'/contacts');
      }
    }

    $context['results']['count'] += $actual_limit;
    $context['finished'] = $context['results']['count'] / $context['sandbox']['total_nodes'];
  }
  else {
    $context['finished'] = 1;
  }

  $context['message'] = t(
    'Processed @count of @total nodes.',
    array(
      '@count' => $context['results']['count'],
      '@total' => $context['sandbox']['total_nodes'],
    )
  );
}

/**
 * Batch finished callback.
 */
function drush_hdx_datasets_batch_finished($success, $results, $operations) {
  drush_log('Process finished');
}

