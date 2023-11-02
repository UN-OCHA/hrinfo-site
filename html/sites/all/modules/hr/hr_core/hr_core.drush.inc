<?php

/**
 * @file
 * Hr_core module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_core_drush_command() {
  $items = array();

  $items['hr-core-average-file-size'] = array(
    'description' => "Display the average file size and median of the files",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  $items['hr-core-operation-avg-file-size'] = array(
    'description' => "Display the average file size and median of the files for an operation",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  $items['hr-core-rwr-392'] = array(
    'description' => "Extract meta data",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Get the average file size of all files uploaded on HR.info.
 */
function drush_hr_core_rwr_392() {
  $file = fopen('/var/www/rwr_links.csv', 'r');
  $counter = 0;

  // Skip header.
  $row = fgetcsv($file);

  while (($row = fgetcsv($file)) !== FALSE && $counter < 50) {
    $counter++;
    if ($row[8] == 'The linked content originates from a prior revision of a paragraph.') {
      continue;
    }

    $url = $row[0];

    // Check if it's a link to a node.
    if (strpos($url, '/node/') !== FALSE) {
      // Extract last part as nid.
      $path = ltrim(parse_url($url, PHP_URL_PATH), '/');
      $parts = explode('/', $path);
      $nid = array_pop($parts);
    }
    // Lookup using alias.
    else {
      $url = parse_url($url, PHP_URL_PATH);
      $parts = explode('/', $url);

      // Remove language.
      if ($parts[1] === 'en' || $parts[1] === 'es' || $parts[1] === 'fr' || $parts[1] === 'ru') {
        unset($parts[1]);
        $parts = array_values($parts);
      }
      $url = implode('/', $parts);

      $nid = _hr_core_get_id_from_alias($url);

      // If not found, search by title.
      if (!$nid) {
        // Extract last part as title.
        $path = ltrim(parse_url($url, PHP_URL_PATH), '/');
        $parts = explode('/', $path);
        $title = array_pop($parts);
        $title = urldecode($title);

        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->propertyCondition('title', $title);
        $result = $query->execute();

        if ($result && isset($result['node'])) {
          $nid = reset($result['node'])->nid;
        }
      }

      // Replace dashes.
      // If not found, search by title.
      if (!$nid) {
        // Extract last part as title.
        $path = ltrim(parse_url($url, PHP_URL_PATH), '/');
        $parts = explode('/', $path);
        $title = array_pop($parts);
        $title = urldecode($title);
        $title = str_replace('-', ' ', $title);

        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->propertyCondition('title', $title);
        $result = $query->execute();

        if ($result && isset($result['node'])) {
          $nid = reset($result['node'])->nid;
        }
      }

    }

    drush_print_r([
      $url,
      $nid
    ]);
  }
  fclose($file);
}

/**
 * Get Id from alias.
 */
function _hr_core_get_id_from_alias($url) {
  $path = ltrim(parse_url($url, PHP_URL_PATH), '/');

  // Check redirects and get final path.
  if (function_exists('redirect_load_by_source')) {
    if ($redirect = redirect_load_by_source($path)) {
      $path = $redirect['redirect'];
    }
  }

  $node_path = drupal_lookup_path('source', $path);

  if (!$node_path) {
    return FALSE;
  }

  $node = menu_get_object('node', 1, $node_path);

  return $node->nid;
}

/**
 * Get the average file size of all files uploaded on HR.info.
 */
function drush_hr_core_average_file_size() {

  $result = db_query('SELECT AVG(filesize) FROM drupal.file_managed');
  foreach ($result as $record) {
    print_r($record);
  }

  $result = db_query('SELECT percentile_disc(0.5) within group (order by filesize) FROM drupal.file_managed;');
  foreach ($result as $record) {
    print_r($record);
  }
}

/**
 * Get the average file size of all files uploaded to an operation.
 */
function drush_hr_core_operation_avg_file_size() {
  // Get arguments passed in command, Ex: drush nc page blog.
  $args = func_get_args();
  if ($args) {
    $id = $args[0];
    $types = array('hr_document', 'hr_infographic', 'hr_assessment');
    // Get all the nodes of an operation.
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $types, 'IN')
      ->fieldCondition('og_group_ref', 'target_id', $id)
      ->execute();
    if (isset($results['node'])) {
      $nodes = entity_load('node', array_keys($results['node']));
      $fc_ids = array();
      foreach ($nodes as $node) {
        if (($node->type == 'hr_document' || $node->type == 'hr_infographic') && !empty($node->field_files_collection[LANGUAGE_NONE])) {
          foreach ($node->field_files_collection[LANGUAGE_NONE] as $fc) {
            $fc_ids[] = $fc['value'];
          }
        }
        if ($node->type == 'hr_assessment' && !empty($node->field_asst_data[LANGUAGE_NONE])) {
          foreach ($node->field_asst_data[LANGUAGE_NONE] as $fc) {
            $fc_ids[] = $fc['value'];
          }
        }
        if ($node->type == 'hr_assessment' && !empty($node->field_asst_questionnaire[LANGUAGE_NONE])) {
          foreach ($node->field_asst_questionnaire[LANGUAGE_NONE] as $fc) {
            $fc_ids[] = $fc['value'];
          }
        }
        if ($node->type == 'hr_assessment' && !empty($node->field_asst_report[LANGUAGE_NONE])) {
          foreach ($node->field_asst_report[LANGUAGE_NONE] as $fc) {
            $fc_ids[] = $fc['value'];
          }
        }
      }
      // Get documents and infographics file IDs.
      $results = db_select('field_data_field_file', 'f')
        ->fields('f')
        ->condition('entity_id', $fc_ids, 'IN')
        ->condition('bundle', 'field_files_collection')
        ->execute()
        ->fetchAll();
      $file_ids = array();
      foreach ($results as $result) {
        $file_ids[] = $result->field_file_fid;
      }
      // Get assessment file IDs.
      $fc_types = array(
        'field_asst_data',
        'field_asst_questionnaire',
        'field_asst_report',
      );
      $results = db_select('field_data_field_asst_file', 'f')
        ->fields('f')
        ->condition('entity_id', $fc_ids, 'IN')
        ->condition('bundle', $fc_types, 'IN')
        ->execute()
        ->fetchAll();
      foreach ($results as $result) {
        $file_ids[] = $result->field_asst_file_fid;
      }

      // Compute average file size.
      $result = db_query("SELECT AVG(filesize) FROM drupal.file_managed WHERE fid IN (:fids)", array(':fids' => $file_ids));
      foreach ($result as $record) {
        print_r($record);
      }

      // Compute median file size.
      $result = db_query('SELECT percentile_disc(0.5) within group (order by filesize) FROM drupal.file_managed WHERE fid IN (:fids);', array(
        ':fids' => $file_ids,
      ));
      foreach ($result as $record) {
        print_r($record);
      }

    }
  }
  // If no type passed then return total count.
  else {
    drush_print('No operation provided');
  }
}
