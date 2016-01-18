<?php

/**
 * @file
 * hr_contacts module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_contacts_drush_command() {
  $items = array();

  $items['hr-contacts-disable-hr-contacts'] = array(
    'description' => "Disable the hr-contact feature",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}


/**
 * Drush command to disable the hr contacts in a batch process.
 */
function drush_hr_contacts_disable_hr_contacts() {
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
        'drush_hr_contacts_disable_hr_contacts_callback',
        array(
          array_keys($result['node']),
          $registry
        ),
      ),
    ),
    'finished' => 'drush_hr_contacts_batch_finished',
    'title' => t('Disable HR contacts feature'),
    'init_message' => t('Preparing...'),
    'progress_message' => t('Disabling features...'),
    'error_message' => t('HR contacts disable process resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Callback function to disable the HR contacts.
 */
function drush_hr_contacts_disable_hr_contacts_callback($node_ids, $registry, &$context) {
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
      // Disable the hr_contacts feature, if it wasn't enabled already, there's
      // no need to resave them.
      if (isset($enabled_features['hr_contacts'])) {
        unset($enabled_features['hr_contacts']);
        // Save the new settings.
        og_features_save_feature_settings($node->nid, 'node', $enabled_features);
        // Alert other modules about the change.
        module_invoke_all('og_features_toggle', $node, $node->nid, 'node', $enabled_features);
        // Force removing the menu.
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
function drush_hr_contacts_batch_finished($success, $results, $operations) {
  drush_log('Process finished');
}
