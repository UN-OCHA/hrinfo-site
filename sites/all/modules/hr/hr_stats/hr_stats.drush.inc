<?php

/**
 * @file
 * hr_stats module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_stats_drush_command() {
  $items = array();

  $items['hr-stats-full-stats'] = array(
    'description' => "Get the full stats for HR.info sites",
    'options' => array(
      'period' => 'Period',
      'date' => 'Date',
    ),
    'drupal dependencies' => array('hr_stats'),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Callback to calculate the stats for a given period.
 *
 * @param $period
 * @param $date
 */
function drush_hr_stats_full_stats($period, $date) {
  $token_auth = variable_get('hr_stats_piwik_token_auth', '');
  $site_id = variable_get('piwik_site_id', '');
  $piwik_url = variable_get('piwik_url_https', '');

  if (empty ($token_auth) || empty($site_id) || empty($piwik_url)) {
    drush_log('Unable to get stats settings. Review the piwik configuration.');
  }
  $segments = drush_hr_stats_get_raw_piwik_segments($token_auth, $site_id, $piwik_url);
  $batch = array(
    'operations' => array(
      array(
        'drush_hr_stats_full_stats_operation',
        array(
          $period,
          $date,
          $segments,
          $token_auth,
          $site_id,
          $piwik_url,
        ),
      ),
    ),
    'finished' => 'drush_hr_stats_full_stats_batch_finished',
    'title' => t('Calculating'),
    'init_message' => t('Preparing stats calculation...'),
    'progress_message' => t('Calculating full stats...'),
    'error_message' => t('Full stats calculation resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

function drush_hr_stats_full_stats_batch_finished($success, $results, $operations) {
  drush_log('Process finished');
}

/**
 * Calculates the full stats report for a period and date.
 *
 * @param $period
 * @param $date
 */
function drush_hr_stats_full_stats_operation($period, $date, $segments, $token_auth, $site_id, $piwik_url, &$context) {
  $limit = 10;
  $context['finished'] = 0;

  if (!isset($context['sandbox']['file'])) {
    $headers = array(
      'Space',
      'Number of visits',
      '% of visits in-country',
      'Total number of downloads',
      'Number of dataset downloads',
      'Number of documents downloads',
      'Number of infographics downloads',
      'Number of assessments downloads'
    );
    // Create the file and print the labels in the header row.
    $file_path = file_directory_temp() . '/tmp-generator-stats-' . time() . '.csv';
    $handle = fopen($file_path, 'w');
    fputcsv($handle, $headers);
    fclose($handle);
    $context['sandbox']['segments'] = $segments;
    $context['sandbox']['total_segments'] = count($segments);
    $context['sandbox']['file'] = $file_path;
    $context['results']['count'] = 0;
  }

  $handle = fopen($context['sandbox']['file'], 'a');
  if ($segments_pending = count($context['sandbox']['segments'])) {
    $actual_limit = min($segments_pending, $limit);
    $segment_info = array_slice(
      $context['sandbox']['segments'],
      $context['results']['count'],
      $actual_limit,
      TRUE
    );

    $processed = drush_hr_stats_full_stats_operation_process($handle, $period, $date, $segment_info, $token_auth, $site_id, $piwik_url);

    $context['results']['count'] += $processed;
    $context['finished'] = $context['results']['count'] / $context['sandbox']['total_segments'];
  }
  else {
    $context['finished'] = 1;
  }

  fclose($handle);

  $context['message'] = t(
    'Processed @count of @total nodes.',
    array(
      '@count' => $context['results']['count'],
      '@total' => $context['sandbox']['total_segments'],
    )
  );

  if ($context['finished'] == 1) {
    $destination = 'public://stats';
    if (file_prepare_directory($destination, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
      $new_file = file_unmanaged_move($context['sandbox']['file'], $destination . '/stats-' . $period . '-' . $date .'.csv');
      drush_print('New file created: ' . $new_file);
      drush_print('File can be downloaded from: ' . file_create_url($new_file));
    }
  }
}

/**
 * Process the full stats calculation.
 */
function drush_hr_stats_full_stats_operation_process($handle, $period, $date, $segment_info, $token_auth, $site_id, $piwik_url) {
  $ids = array();
  foreach ($segment_info as $segment) {
    $defs = explode(';', $segment['definition']);
    foreach ($defs as $def) {
      list($name, $value) = explode('==' , $def);
      if ($name == 'customVariablePageValue1') {
        $ids[$value] = $segment['idsegment'];
      }
    }
  }
  $nodes = node_load_multiple(array_keys($ids));

  $segment_nodes = array();
  foreach ($nodes as $node) {
    $segment_nodes[$ids[$node->nid]] = $node;
  }

  foreach ($segment_info as $segment) {
    if (isset($segment_nodes[$segment['idsegment']])) {
      $row = array();
      $wrapper = entity_metadata_wrapper('node', $segment_nodes[$segment['idsegment']]);
      $row[] = $wrapper->label();

      // Calculate the "in country" visits.
      if (isset($wrapper->field_country) && isset($wrapper->field_country->field_pcode)) {
        $iso2 = $wrapper->field_country->field_pcode->value();
        $url_params = array();
        $segment_definition = $segment['definition'];
        $url_params[] = urlencode(
          "method=API.get&idSite=$site_id&period=$period&date=$date&token_auth=$token_auth&segment=$segment_definition"
        );
        $url_params[] = urlencode(
          "method=API.get&idSite=$site_id&period=$period&date=$date&token_auth=$token_auth&segment=$segment_definition;countryCode==$iso2"
        );
        $url = $piwik_url . 'index.php?module=API&method=API.getBulkRequest&format=json&urls[0]=' . $url_params[0] . '&urls[1]=' . $url_params[1];
        $bulk_results = drupal_http_request($url);
        if (!empty($bulk_results->data)) {
          $bulk_results_data = drupal_json_decode($bulk_results->data);
          $row[] = $bulk_results_data[0]['nb_visits'];
          if ($bulk_results_data[0]['nb_visits'] > 0) {
            $row[] = $bulk_results_data[1]['nb_visits'] / $bulk_results_data[0]['nb_visits'] * 100;
          }
          else {
            $row[] = 0;
          }
        }
      }
      else {
        $visits = drush_hr_stats_get_piwik_stat(
          $token_auth,
          $site_id,
          $piwik_url,
          'API.get',
          $period,
          $date,
          $segment['definition']
        );
        $row[] = $visits['nb_visits'];
        $row[] = ($visits['nb_visits'] > 0) ? -1 : 0;
      }

      // Get the total downloads and for each space.
      $nb_dl= array(
        'total' => 0,
        'hr_dataset' => 0,
        'hr_document' => 0,
        'hr_infographic' => 0,
        'hr_assessment' => 0,
      );
      $hr_downloads = drush_hr_stats_get_hr_downloads($token_auth, $site_id, $piwik_url, $period, $date, $segment['definition']);
      if (!empty($hr_downloads['subtable'])) {
        foreach ($hr_downloads['subtable'] as $hr_download) {
          // Get the file id corresponding to each uri.
          $download_file_name = explode('/', $hr_download['label']);
          $download_file_name = array_pop($download_file_name);
          $file_query = new EntityFieldQuery();
          $file_results = $file_query->entityCondition('entity_type', 'file')
            ->propertyCondition('filename', $download_file_name)
            ->propertyCondition('status', 1)
            ->execute();
          if (!empty($file_results['file'])) {
            // If the file is found, we try to get the node of the type.
            $file_info = reset($file_results['file']);
            if ($node_type = drush_hr_stats_file_belongs_to_valid_type($file_info, $wrapper)) {
              $nb_dl['total'] += $hr_download['nb_visits'];
              $nb_dl[$node_type] += $hr_download['nb_visits'];
            }
          }
        }
      }

      foreach ($nb_dl as $element) {
        $row[] = $element;
      }

      fputcsv($handle, $row);
    }
  }

  return count($segment_info);
}

/**
 * Helper function that searches for the file in the different node types
 * associated with a given space.
 *
 * @param $file_info
 *  File info containing the file id.
 * @param $wrapper
 *  Entity metadata wrapper of the space.
 *
 * @return bool|string
 *  False if the file/url is not found within the nodes, the node type if found.
 */
function drush_hr_stats_file_belongs_to_valid_type($file_info, $wrapper) {
  // Index of types and file fields, this is only for reference as we have field
  // collection in the middle and the way to get the file is different in each
  // case.
  //  'hr_assessment' => array(
  //    'field_asst_questionnaire' => array('field_asst_file'),
  //    'field_asst_report' => array('field_asst_file'),
  //    'field_asst_data' => array('field_asst_file'),
  //  ),
  //  'hr_document'=> array(
  //    'field_files_collection' => array('field_file'),
  //  ),
  //  'hr_infographic'=> array(
  //    'field_files_collection' => array('field_file'),
  //  ),
  //  'hr_dataset' => array(
  //    'field_ds_files' => array(),
  //  )

  // Dataset is the most straightforward.
  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hr_dataset')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('og_group_ref', 'target_id', $wrapper->getIdentifier())
    ->fieldCondition('field_ds_files', 'fid', $file_info->fid)
    ->execute();
  if (!empty($results['node'])) {
    return 'hr_dataset';
  }

  // Assessment is the most complicated but there are not many.
  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_asst_questionnaire')
    ->fieldCondition('field_asst_file', 'fid', $file_info->fid)
    ->execute();
  if (!empty($results['field_collection_item'])) {
    $fc_id = reset($results['field_collection_item']);
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'hr_assessment')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $wrapper->getIdentifier())
      ->fieldCondition('field_asst_questionnaire', 'value', $fc_id->item_id)
      ->execute();
    if (!empty($results['node'])) {
      return 'hr_assessment';
    }
  }

  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_asst_report')
    ->fieldCondition('field_asst_file', 'fid', $file_info->fid)
    ->execute();
  if (!empty($results['field_collection_item'])) {
    $fc_id = reset($results['field_collection_item']);
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'hr_assessment')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $wrapper->getIdentifier())
      ->fieldCondition('field_asst_report', 'value', $fc_id->item_id)
      ->execute();
    if (!empty($results['node'])) {
      return 'hr_assessment';
    }
  }
  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_asst_data')
    ->fieldCondition('field_asst_file', 'fid', $file_info->fid)
    ->execute();
  if (!empty($results['field_collection_item'])) {
    $fc_id = reset($results['field_collection_item']);
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'hr_assessment')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $wrapper->getIdentifier())
      ->fieldCondition('field_asst_data', 'value', $fc_id->item_id)
      ->execute();
    if (!empty($results['node'])) {
      return 'hr_assessment';
    }
  }

  // Infographics and documents share the field collection
  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_files_collection')
    ->fieldCondition('field_file', 'fid', $file_info->fid)
    ->execute();
  if (!empty($results['field_collection_item'])) {
    $fc_id = reset($results['field_collection_item']);
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'hr_infographic')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $wrapper->getIdentifier())
      ->fieldCondition('field_files_collection', 'value', $fc_id->item_id)
      ->execute();
    if (!empty($results['node'])) {
      return 'hr_infographic';
    }

    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'hr_document')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $wrapper->getIdentifier())
      ->fieldCondition('field_files_collection', 'value', $fc_id->item_id)
      ->execute();
    if (!empty($results['node'])) {
      return 'hr_document';
    }
  }

  // File not found.
  return FALSE;
}

/**
 * Get the segments available for the site.
 */
function drush_hr_stats_get_raw_piwik_segments($token_auth, $site_id, $piwik_url) {
  $result = drupal_http_request(
    $piwik_url . 'index.php?module=API&method=SegmentEditor.getAll&idSite=' . (int) $site_id . '&format=JSON&token_auth=' . $token_auth
  );
  if (empty($result->data)) {
    drupal_set_message(t('Please ask your administrator to check Piwik Reports configuration.'), 'warning', FALSE);
    return '';
  }
  else {
    $segments = drupal_json_decode($result->data);
    $segments = reset($segments);
    return array($segments);
  }
}

/**
 * Wrapper function to call Piwik API methods.
 */
function drush_hr_stats_get_piwik_stat($token_auth, $site_id, $piwik_url, $method, $period, $date, $segment = '', $additional = '') {
  $url = $piwik_url . 'index.php?module=API&method=' . $method . '&idSite=' . (int) $site_id . '&period=' . $period . '&date=' . $date . '&format=JSON&token_auth=' . $token_auth;
  if (!empty($segment)) {
    $url .= '&segment=' . $segment;
  }
  if (!empty($additional)) {
    $url .= '&' . $additional;
  }
  $result = drupal_http_request($url);
  if (empty($result->data)) {
    drupal_set_message(t('Please ask your administrator to check Piwik Reports configuration.'), 'warning', FALSE);
    return '';
  }
  else {
    return drupal_json_decode($result->data);
  }
}

/**
 * Helper function to get the HR download data.
 */
function drush_hr_stats_get_hr_downloads($token_auth, $site_id, $piwik_url, $period, $date, $segment = '') {
  $downloads = drush_hr_stats_get_piwik_stat($token_auth, $site_id, $piwik_url, 'Actions.getDownloads', $period, $date, $segment, 'expanded=1');
  foreach ($downloads as $download) {
    if ($download['label'] == 'www.humanitarianresponse.info') {
      return $download;
    }
  }

  return array();
}
