<?php

/**
 * @file
 * hr_datasets module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_datasets_drush_command() {
  $items = array();

  $items['hr-datasets-migrate'] = array(
    'description' => "Migrate the datasets to HDX",
    'arguments' => array(
      'path' => 'Path to the CSV file containing the migration output',
    ),
    'options' => array(
    ),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

function _hr_datasets_csv_to_array($filename='', $delimiter=',') {
    $data = array();
    if (($handle = fopen($filename, 'r')) !== FALSE)
    {
        while (($row = fgetcsv($handle, 1000, $delimiter)) !== FALSE)
        {
            $data[] = array_map('trim', $row);
        }
        fclose($handle);
    }
    return $data;
}

function drush_hr_datasets_migrate($path) {
  // Load the CSV file
  $datasets = _hr_datasets_csv_to_array($path, '|');
  foreach ($datasets as $dataset) {
    if ($dataset[2] == 'COMPLETE') {
      // Set the redirect
      $nid = $dataset[4];
      // Try to load redirect
      $redirect = redirect_load_by_source('node/'.$nid, 'en');
      if (!$redirect) {
        $redirect = new stdClass();
        redirect_object_prepare($redirect);
      }
      $redirect->source = 'node/'.$nid;
      $redirect->redirect = $dataset[10];
      $redirect->language = 'en';
      redirect_save($redirect);
      // Set the summary
      $node = node_load($nid);
      $node->field_ds_summary[LANGUAGE_NONE][0]['value'] = '<p>This dataset is now maintained on the <a href="'.$dataset[10].'">Humanitarian Data Exchange</a>.</p>';
      $node->field_ds_summary[LANGUAGE_NONE][0]['format'] = 'panopoly_wysiwyg_text';
      $node->field_ds_files = array();
      $node->field_ds_abstract = array();
      $node->field_languages = array();
      $node->field_dataset_types = array();
      $node->field_ds_instructions = array();
      node_save($node);
    }
    elseif ($dataset[2] == 'NOMIGRATE-INTENT') {
      $nid = $dataset[4];
      $node = node_load($nid);
      $node->status = NODE_NOT_PUBLISHED;
      node_save($node);
    }
  }
}

