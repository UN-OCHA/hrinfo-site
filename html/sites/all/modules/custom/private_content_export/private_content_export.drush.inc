<?php

/**
 * @file
 * Drush commands.
 */

/**
 * Implements hook_drush_help().
 */
function private_content_export_drush_help($section) {
  switch ($section) {
    case 'drush:private-content-export':
      return dt('Export private content listed by the my_private_content::attachment_1 view.');

    case 'drush:private-dataset-export':
      return dt('Export dataset content listed by the my_dataset_content::attachment_1 view.');
  }
}

/**
 * Implements hook_drush_command().
 */
function private_content_export_drush_command() {
  $items = array();

  $items['private-content-export'] = array(
    'description' => 'Rebuild the node access table',
    'callback' => 'private_content_export_export_content',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('pce'),
  );

  $items['private-dataset-export'] = array(
    'description' => 'Export dataset',
    'callback' => 'private_content_export_export_dataset_content',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['private-dataset-delete'] = array(
    'description' => 'Delete dataset',
    'callback' => 'private_content_export_delete_dataset_content',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['private-content-delete'] = array(
    'description' => 'Delete private content',
    'callback' => 'private_content_export_delete_content',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['old-contacts-delete'] = array(
    'description' => 'Delete old contacts',
    'callback' => 'private_content_export_delete_old_contacts',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}
