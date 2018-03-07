<?php

/**
 * @file
 * hr_documents module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_documents_drush_command() {
  $items = array();

  $items['hr-documents-migrate'] = array(
    'description' => "Migrate document files from private to public",
    'arguments' => array(
    ),
    'options' => array(
    ),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

function hr_documents_file_move($fid) {
  $file = file_load($fid);
  if (strpos($file->uri, 'private://') === 0) {
    $destination = str_replace('private://', 'public://', $file->uri);
    file_move($file, $destination);
    $initial_url = str_replace('private://', 'system/files/', $file->uri);
    $final_url = str_replace('private://', 'sites/www.humanitarianresponse.info/files/', $file->uri);
    $redirect = new stdClass();
    redirect_object_prepare($redirect);
    $redirect->source = $initial_url;
    $redirect->redirect = $final_url;
    redirect_save($redirect);
  }
}


function drush_hr_documents_migrate() {
  // Load all fids of the documents and infographics
  $result = db_select('field_data_field_file', 'f')
    ->fields('f')
    ->execute();
  while ($record = $result->fetchAssoc()) {
    // Foreach fid, move the file to public
    $fid = $record['field_file_fid'];
    hr_documents_file_move($fid);
  }
}
