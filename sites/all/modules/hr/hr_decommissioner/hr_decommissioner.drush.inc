<?php

/**
 * @file
 * hr_decommissioner module drush integration.
 *
 * KEPT FOR REFERENCE ONLY !! THIS CODE SHOULD NOT BE USED ANYMORE
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_decommissioner_drush_command() {
  $items = array();

  /*$items['hr-decommissioner-export-additional-contacts'] = array(
    'description' => "Export additional contacts in hrinfo",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  $items['hr-decommissioner-remove-contact-menus'] = array(
    'description' => "Remove the contact menus from all groups",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );*/

  return $items;
}

/**
 * Callback to get the contacts that aren't in HID.
 */
function drush_hr_decommissioner_export_additional_contacts() {

  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_users_ref')
    ->execute();
  if (empty($results['field_collection_item'])) {
    return;
  }
  $contacts = array_keys($results['field_collection_item']);

  $batch = array(
    'operations' => array(
      array(
        'drush_hr_decommissioner_get_contacts',
        array(
          $contacts,
        ),
      ),
    ),
    'finished' => 'drush_hr_decommissioner_finished',
    'title' => t('Calculating'),
    'init_message' => t('Preparing contacts calculation...'),
    'progress_message' => t('Calculating contacts...'),
    'error_message' => t('Contacts process resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}
/**
 * Generates a listing of additional contacts.
 */
function drush_hr_decommissioner_get_contacts($contacts, &$context) {
  $limit = 500;
  $context['finished'] = 0;

  if (!isset($context['sandbox']['file'])) {
    $headers = array(
      'Name',
      'Email',
      'Phones',
    );
    // Create the file and print the labels in the header row.
    $file_path = file_directory_temp() . '/additional-contacts-report.csv';
    $handle = fopen($file_path, 'w');
    fputcsv($handle, $headers);
    fclose($handle);
    $context['sandbox']['contacts'] = $contacts;
    $context['sandbox']['total_contacts'] = count($contacts);
    $context['sandbox']['file'] = $file_path;
    $context['results']['count'] = 0;
  }

  $handle = fopen($context['sandbox']['file'], 'a');

  if ($contacts_pending = count($context['sandbox']['contacts'])) {
    drush_log('Pending: ' . $contacts_pending);
    $actual_limit = min($contacts_pending, $limit);
    $contact_info = array_slice(
      $context['sandbox']['contacts'],
      $context['results']['count'],
      $actual_limit,
      TRUE
    );

    // Load all the contacts for the iteration.
    $contact_items = field_collection_item_load_multiple($contact_info);

    foreach ($contact_items as $contact_item) {
      $wrapper = entity_metadata_wrapper('field_collection_item', $contact_item);
      $additional_user = $wrapper->field_users_ref_checkbox->value();

      if (!empty($additional_user)) {
        // Otherwise, add it to the csv.
        $row = array();
        $row[] = $wrapper->field_users_ref_name->value();
        $row[] = $wrapper->field_email->value();
        $phone_values = $wrapper->field_phones->value();
        $phones = array();
        foreach ($phone_values as $value) {
          $phones[] = $value['number'];
        }
        $row[] = implode(',', $phones);
        fputcsv($handle, $row);
      }
    }

    $context['results']['count'] += $actual_limit;
    $context['finished'] = $context['results']['count'] / $context['sandbox']['total_contacts'];
  }
  else {
    $context['finished'] = 1;
  }

  fclose($handle);

  $context['message'] = t(
    'Processed @count of @total contacts.',
    array(
      '@count' => $context['results']['count'],
      '@total' => $context['sandbox']['total_contacts'],
    )
  );
}

/**
 * Drush command to remove the contact menus and replace them by hid ones.
 */
function drush_hr_decommissioner_remove_contact_menus() {
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
        'drush_hr_decommissioner_remove_contact_menus_callback',
        array(
          array_keys($result['node']),
          $registry
        ),
      ),
    ),
    'finished' => 'drush_hr_decommissioner_finished',
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
function drush_hr_decommissioner_remove_contact_menus_callback($node_ids, $registry, &$context) {
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

      // Get rid of the menu for contacts.
      menu_link_delete(NULL, 'node/' . $node->nid . '/contacts');
      // Also of the hid contacts one, we'll recreate it below if necessary.
      menu_link_delete(NULL, 'node/' . $node->nid . '/hid_contacts');

      if (isset($enabled_features['hid_contacts'])) {
        $mlid = og_menu_single_get_link_mlid('node', $node->nid);
        // Create the hid contacts menu.
        $menu_link = array(
          'link_path' => 'node/'.$node->nid.'/hid_contacts',
          'link_title' => 'Contacts',
          'menu_name' => OG_MENU_SINGLE_MENU_NAME,
          'weight' => 2,
          'plid' => $mlid,
        );
        menu_link_save($menu_link);
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
function drush_hr_decommissioner_finished($success, $results, $operations) {
  drush_log('Process finished');
}
