<?php
/**
 * @file
 */

/**
 * Implements hook_drush_help().
 */
function private_content_export_drush_help($section) {
  switch ($section) {
    case 'drush:private-content-export':
      return dt('Export private content listed by the my_private_content::attachment_1 view.');
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

  return $items;
}
