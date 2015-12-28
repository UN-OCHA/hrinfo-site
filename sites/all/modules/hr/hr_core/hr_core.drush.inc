<?php
/**
 * @file
 * hr_core module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 * @see drush_parse_command()
 */
function hr_core_drush_command() {
  $items = array();

  // Command to fix og menus.
  // @TODO make this specific per node or content type.
  $items['hr-core-fix-og-menus'] = array(
    'description' => "Fixes operation and cluster menus",
    'options' => array(
    ),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Run through all nodes that are groups and executes
 */
function drush_hr_core_fix_og_menus() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', array('hr_operation', 'hr_bundle', 'hr_disaster', 'hr_sector', 'hr_space'), 'IN')
    ->propertyCondition('status', 1);
  $result = $query->execute();

  if (empty($result['node'])) {
    drush_log('No nodes found', 'ok');
    return;
  }

  $registry = og_features_get_registry();

  $batch = array(
    'operations' => array(
      array(
        'drush_hr_core_fix_og_menus_callback',
        array(
          array_keys($result['node']),
          $registry
        ),
      ),
    ),
    'finished' => 'drush_hr_core_fix_og_menus_batch_finished',
    'title' => t('Fixing menus'),
    'init_message' => t('Preparing fix...'),
    'progress_message' => t('Fixing menus...'),
    'error_message' => t('Menu fixes resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

function drush_hr_core_fix_og_menus_callback($node_ids, $registry, &$context) {
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
      if (!empty($enabled_features)) {
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

function drush_hr_core_fix_og_menus_batch_finished($success, $results, $operations) {
  drush_log('Process finished');
}
