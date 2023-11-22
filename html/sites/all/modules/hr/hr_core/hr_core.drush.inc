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

  $items['hr-core-hrinfo-1278'] = array(
    'description' => "Get attachments",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Get the average file size of all files uploaded on HR.info.
 */
function drush_hr_core_rwr_392() {
  $file_in = fopen('/var/www/rwr_links.csv', 'r');
  $file_out = fopen('/var/www/rwr_links_found.csv', 'w');
  $file_skipped = fopen('/var/www/rwr_links_skipped.csv', 'w');
  $counter = 0;
  $max_items = 9999;

  // Add header to skipped.
  $row = fgetcsv($file_in);
  fputcsv($file_skipped, $row);

  // Add new headers to output.
  $row = array_merge($row, [
    'id',
    'type',
    'title',
    'status',
    'language',
    'publication_date',
    'operation',
    'operation_url',
    'cluster',
    'cluster_url',
    'organization',
    'document_type',
  ]);
  fputcsv($file_out, $row);

  while (($row = fgetcsv($file_in)) !== FALSE && $counter < $max_items) {
    $counter++;
    if ($row[8] == 'The linked content originates from a prior revision of a paragraph.') {
      continue;
    }

    $url = urldecode($row[0]);

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

    if ($nid) {
      $meta = _hr_core_get_meta($nid);
      $row = array_merge($row, array_values($meta));
      fputcsv($file_out, $row);

      continue;
    }

    // It might be a file.
    $meta = _hr_core_get_alias_from_filename($url);

    if (!empty($meta)) {
      $row = array_merge($row, array_values($meta));
      fputcsv($file_out, $row);
    }
    else {
      fputcsv($file_skipped, $row);
    }
  }

  fclose($file_in);
  fclose($file_out);
  fclose($file_skipped);
}

/**
 * Get meta data.
 */
function _hr_core_get_meta($nid) {
  $node = node_load($nid);
  if (!$node) {
    return [];
  }

  $wrapper = entity_metadata_wrapper('node', $node);

  $meta = [
    'id' => $wrapper->getIdentifier(),
    'type' => $wrapper->getBundle(),
    'title' => $wrapper->label(),
    'status' => $node->status,
    'language' => $node->language,
    'publication_date' => '',
    'operation' => '',
    'operation_url' => '',
    'cluster' => '',
    'cluster_url' => '',
    'organization' => '',
    'document_type' => '',
  ];

  if (isset($wrapper->og_group_ref) && isset($wrapper->og_group_ref[0])) {
    $meta['operation'] = $wrapper->og_group_ref[0]->label();
    $meta['operation_url'] = url('node/'. $wrapper->og_group_ref[0]->getIdentifier());
  }

  if (isset($wrapper->field_bundles) && isset($wrapper->field_bundles[0])) {
    $meta['cluster'] = $wrapper->field_bundles[0]->label();
    $meta['cluster_url'] = url('node/'. $wrapper->field_bundles[0]->getIdentifier());
  }

  if (isset($wrapper->field_organizations) && isset($wrapper->field_organizations[0])) {
    $meta['organization'] = $wrapper->field_organizations[0]->label();
  }

  if (isset($wrapper->field_publication_date)) {
    $meta['publication_date'] = date('Y-m-d', $wrapper->field_publication_date->value());
  }

  if (isset($wrapper->field_document_type)) {
    $meta['document_type'] = $wrapper->field_document_type->label();
  }

  return $meta;
}

/**
 * Get file from filename.
 */
function _hr_core_get_alias_from_filename($url) {
  $filename = '';
  $fid = FALSE;

  // Private file.
  if (strpos($url, '/system/files/') !== FALSE) {
    $path = ltrim(parse_url($url, PHP_URL_PATH), '/');
    $parts = explode('/', $path);
    $filename = array_pop($parts);
  }
  // Public file.
  elseif (strpos($url, '/files/') !== FALSE) {
    $path = ltrim(parse_url($url, PHP_URL_PATH), '/');
    $parts = explode('/', $path);
    $filename = array_pop($parts);
  }
  // Direct link to file.
  elseif (strpos($url, '/file/') !== FALSE && strpos($url, '/download') !== FALSE) {
    $path = ltrim(parse_url($url, PHP_URL_PATH), '/');
    $parts = explode('/', $path);
    // Skip download part.
    $fid = array_pop($parts);
    $fid = array_pop($parts);
  }
  // Direct link to file.
  elseif (strpos($url, '/file/') !== FALSE) {
    $path = ltrim(parse_url($url, PHP_URL_PATH), '/');
    $parts = explode('/', $path);
    $fid = array_pop($parts);
  }

  if (empty($filename) && !$fid) {
    return [];
  }

  $file = FALSE;
  if (!empty($filename)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'file')
      ->propertyCondition('filename', $filename);
    $result = $query->execute();

    if (empty($result['file'])) {
      return [];
    }

    $files = entity_load('file', array_keys($result['file']));
    $file = reset($files);
  }
  elseif (!empty($fid)) {
    $file = entity_load_single('file', $fid);
  }

  if (!$file) {
    return [];
  }

  $usage = file_usage_list($file);

  if (!isset($usage['file'])) {
    return [];
  }

  $entity_type = array_keys($usage['file']);
  $entity_type = reset($entity_type);

  $entity_id = array_keys($usage['file'][$entity_type]);
  $entity_id = reset($entity_id);

  $entities = entity_load($entity_type, [$entity_id]);
  $entity = reset($entities);

  $parent = $entity;
  while ($parent instanceof FieldCollectionItemEntity) {
    $parent = $entity->hostEntity();
  }

  if ($parent && isset($parent->nid)) {
    return _hr_core_get_meta($parent->nid);
  }

  return [];
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
  if ($node) {
    return $node->nid;
  }

  return FALSE;
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

/**
 * Get all attachments.
 */
function drush_hr_core_hrinfo_1278() {
  $file_in = fopen('/var/www/hrinfo_1278.csv', 'r');
  $base_dir = '/var/www/filelists/';
  $counter = 0;
  $max_items = 999;

  while (($row = fgetcsv($file_in)) !== FALSE && $counter < $max_items) {
    $counter++;
    $last_page = 99;

    $url = trim(strtok($row[0], '?'));
    libxml_use_internal_errors(true);

    $path = parse_url($url, PHP_URL_PATH);
    $path = trim($path, '/');
    $path = preg_replace('/[^a-zA-Z0-9\-]/', '_', $path);
    $path = $base_dir . $path;
    if (!is_dir($path)) {
      mkdir($path);
    }
    else {
      drush_log($path . ' exists, skipping');
      continue;
    }
    $file_out = fopen($path . '/filelist.txt', 'w');

    // Get last page.
    $html = file_get_contents($url);

    $dom = new DOMDocument();
    $dom->loadHTML($html);

    $xpath = new DOMXpath($dom);
    $elements = $xpath->query("//li[contains(@class, 'pager-last')]/a");
    if (!is_null($elements) && !is_bool($elements) && $elements->count() > 0) {
      $element = $elements[0];
      $href = $element->getAttribute('href');
      $query = parse_url($href, PHP_URL_QUERY);
      parse_str($query, $query);
      $last_page = $query['page'] ?? 0;
    }

    foreach (range(0, $last_page) as $page) {
      drush_log($url . '?page=' . $page);
      $html = file_get_contents($url . '?page=' . $page);

      $dom = new DOMDocument();
      $dom->loadHTML($html);

      $xpath = new DOMXpath($dom);
      $elements = $xpath->query("//div[contains(@class, 'pane-node-hr-core-files-download-button')]//a");

      if (!is_null($elements) && !is_bool($elements) && $elements->count() > 0) {
        foreach ($elements as $element) {
          $href = $element->getAttribute('href');
          fputcsv($file_out, [$href]);
        }
      }
      else {
        break;
      }
    }

    fclose($file_out);
  }

  fclose($file_in);
}
