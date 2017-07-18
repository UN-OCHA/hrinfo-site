<?php

/**
 * @file
 * Admin.
 */

/**
 * Import locations form.
 */
function hr_tools_import_locations($form, &$form_state) {
  if (!variable_get('file_private_path')) {
    $form['private_path'] = array(
      '#type' => 'markup',
      '#markup' => t('You must specify a private file system path in the !settings so we can save the created files there.', array('!settings' => l(t('file system settings'), 'admin/config/media/file-system'))),
    );
  }
  else {
    $form['csv'] = array(
      '#type' => 'file',
      '#title' => t('Upload csv file'),
      '#size' => 48,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Import locations'),
    );
  }
  $form['#validate'] = array('hr_tools_import_locations_validate');
  $form['#submit'] = array('hr_tools_import_locations_submit');
  return $form;
}

/**
 * Form validate callback.
 */
function hr_tools_import_locations_validate($form, &$form_state) {
  $validators['file_validate_extensions'] = array('csv');
  // Upload to the temp directory, we only need to read it. Afterwards it can be
  // deleted.
  $file = file_save_upload('csv', $validators, FALSE, FILE_EXISTS_REPLACE);
  if (!$file) {
    form_error($form['csv'], t('Something went wrong while uploading the file.'));
    return;
  }
  $form_state['values']['csv'] = $file;
}

/**
 * Form submit callback.
 */
function hr_tools_import_locations_submit($form, $form_state) {
  $file = $form_state['values']['csv'];
  hr_tools_import_locations_populate_queue($file->uri);
}

/**
 * Populate queue.
 */
function hr_tools_import_locations_populate_queue($csv_file) {
  $batch = array(
    'operations' => array(),
    'title' => t('Importing'),
    'init_message' => t('Initializing.'),
    'progress_message' => t('Processed @current out of @total.'),
    'file' => drupal_get_path('module', 'hr_tools') . '/hr_tools.import.inc',
    'finished' => 'hr_tools_import_locations_finished',
  );

  // Check file for UTF-8 and BOM.
  check_csv_file_utf8_bom($csv_file);

  $encoding_list[] = "UTF-8";
  $encoding_list[] = "ASCII";
  $encoding_list[] = "ISO-8859-1";

  $handle = fopen($csv_file, 'r');
  // Assume 1 header line.
  $header = fgetcsv($handle, 0, ';', '"');
  $header_lowercase = array_map('drupal_strtolower', $header);

  while ($row = fgetcsv($handle, 0, ';', '"')) {
    $data = array();
    for ($i = 0; $i < count($row); $i++) {
      $content = $row[$i];
      if (mb_detect_encoding($content, $encoding_list, TRUE) == 'ISO-8859-1') {
        $row[$i] = utf8_encode($content);
      }
      elseif (!mb_check_encoding($content, 'UTF-8') || !($content === mb_convert_encoding(mb_convert_encoding($content, 'UTF-32', 'UTF-8'), 'UTF-8', 'UTF-32'))) {
        $content = mb_convert_encoding($content, 'UTF-8');
        if (mb_check_encoding($content, 'UTF-8')) {
          $row[$i] = $content;
        }
      }
      $data[$header_lowercase[$i]] = $row[$i];
    }

    $batch['operations'][] = array(
      'hr_tools_import_locations_line',
      array($data),
    );
  }
  fclose($handle);
  batch_set($batch);
  batch_process(current_path());
}

/**
 * Import location data.
 */
function hr_tools_import_locations_line($data, &$context) {
  if (!isset($data['admin0_pcode']) || empty($data['admin0_pcode'])) {
    watchdog('hr_tools_importer', 'Admin0_Pcode not set');
    return;
  }

  $voc = taxonomy_vocabulary_machine_name_load('hr_location');
  $terms = array();

  $terms[] = array(
    'name' => $data['admin0_name'],
    'pcode' => $data['admin0_pcode'],
    'admin' => 0,
  );

  if (isset($data['admin1_pcode']) && isset($data['admin1_pcode'])) {
    $terms[] = array(
      'name' => $data['admin1_name'],
      'pcode' => $data['admin1_pcode'],
      'admin' => 1,
    );
    if (isset($data['admin2_pcode']) && isset($data['admin2_pcode'])) {
      $terms[] = array(
        'name' => $data['admin2_name'],
        'pcode' => $data['admin2_pcode'],
        'admin' => 2,
      );
      if (isset($data['admin3_pcode']) && isset($data['admin3_pcode'])) {
        $terms[] = array(
          'name' => $data['admin3_name'],
          'pcode' => $data['admin3_pcode'],
          'admin' => 3,
        );
      }
    }
  }

  $term = hr_tools_create_terms_location($terms, $voc);

  unset($context['results']['failures'][$data['admin3_pcode']]);
  $context['results']['succes'][$data['admin3_pcode']] = 'Imported row ' . $data['admin3_pcode'];
}

function hr_tools_import_locations_finished($success, $results, $operations) {
  if ($success) {
    if (!isset($results['succes'])) {
      $results['succes'] = array();
    }
    $message = t('@count locations successfully imported', array('@count' => count($results['succes'])));
    drupal_set_message($message);

    if (!empty($results['failures'])) {
      $message = t('Failed to import @count locations', array('@count' => count($results['failures'])));
      drupal_set_message($message);
    }
  }
}

/**
 * Export locations form.
 */
function hr_tools_export_locations($form, &$form_state) {
  if (!variable_get('file_private_path')) {
    $form['private_path'] = array(
      '#type' => 'markup',
      '#markup' => t('You must specify a private file system path in the !settings so we can save the created files there.', array('!settings' => l(t('file system settings'), 'admin/config/media/file-system'))),
    );
  }
  else {
    $options = array();
    $locations = taxonomy_get_tree(3, 0, 1);
    foreach ($locations as $location) {
      $options[$location->tid] = $location->name;
    }

    $form['location'] = array(
      '#type' => 'select',
      '#title' => t('Select Admin 0 level to export'),
      '#options' => $options,
      '#required' => TRUE,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Export locations'),
    );
  }

  $form['#submit'] = array('hr_tools_export_locations_submit');
  return $form;
}

/**
 * Form submit callback.
 */
function hr_tools_export_locations_submit($form, $form_state) {
  $admin0 = $form_state['values']['location'];
  $locs = taxonomy_get_tree(3, $admin0);

  // Gatter all tids, add admin0 as well.
  $tids = array();
  $tids[$admin0] = $admin0;
  foreach ($locs as $location) {
    $tids[$location->tid] = $location->tid;
  }

  // Load full terms.
  $terms = taxonomy_term_load_multiple(array_keys($tids));

  // Key locations by tid, add admin0.
  $locations = array();
  $locations[$admin0] = new stdClass();
  $locations[$admin0]->parents[0] = 0;
  $locations[$admin0]->tid = $admin0;
  foreach ($locs as $location) {
    $locations[$location->tid] = $location;
  }

  // Clear locs.
  $locs = array();

  $data = array();
  foreach ($locations as $location) {
    $hierarchy = array();

    // Add location.
    $hierarchy[] = array(
      'name' => $terms[$location->tid]->name,
      'pcode' => $terms[$location->tid]->field_pcode['und'][0]['value'],
      'admin' => $terms[$location->tid]->field_loc_admin_level['und'][0]['value'],
    );

    // Get parent.
    $parent_tid = isset($location->parents[0]) ? $location->parents[0] : 0;
    $count = 0;
    while ($parent_tid != 0 && $count < 3) {
      $count++;
      $hierarchy[] = array(
        'name' => $terms[$parent_tid]->name,
        'pcode' => $terms[$parent_tid]->field_pcode['und'][0]['value'],
        'admin' => $terms[$parent_tid]->field_loc_admin_level['und'][0]['value'],
      );

      // Remove parents from results.
      if (isset($data[$parent_tid])) {
        unset($data[$parent_tid]);
      }

      // Find new parent.
      if (isset($locations[$parent_tid]->parents[0])) {
        $parent_tid = $locations[$parent_tid]->parents[0];
      }
      else {
        $parent_tid = 0;
      }
    }

    $data[$location->tid] = array_reverse($hierarchy);
  }

  $headers = array(
    'Admin0_Name',
    'Admin0_Pcode',
    'Admin1_Name',
    'Admin1_Pcode',
    'Admin2_Name',
    'Admin2_Pcode',
    'Admin3_Name',
    'Admin3_Pcode',
  );
  $output[] = $headers;
  foreach ($data as $info) {
    $row = array();
    foreach ($info as $admin) {
      $row[] = $admin['name'];
      $row[] = $admin['pcode'];
    }
    $output[] = $row;
  }

  // Stream output to user.
  $file_name = 'export_locations.csv';

  header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
  header('Content-Description: File Transfer');
  header("Content-type: text/csv");
  header("Content-Disposition: attachment; filename={$file_name}");
  header("Expires: 0");
  header("Pragma: public");

  $fh = @fopen('php://output', 'w');
  foreach ($output as $row) {
    fputcsv($fh, $row, ';');
  }
  fclose($fh);

  drupal_exit();
}

/**
 * Import locations form.
 */
function hr_tools_import_nodes_tag($form, &$form_state) {
  if (!variable_get('file_private_path')) {
    $form['private_path'] = array(
      '#type' => 'markup',
      '#markup' => t('You must specify a private file system path in the !settings so we can save the created files there.', array('!settings' => l(t('file system settings'), 'admin/config/media/file-system'))),
    );
  }
  else {
    $form['csv_separator'] = array(
      '#type' => 'radios',
      '#title' => t('CSV separator'),
      '#required' => TRUE,
      '#options' => array(
        ',' => ', (comma)',
        ';' => '; (semicolon)',
      ),
    );

    $form['csv'] = array(
      '#type' => 'file',
      '#title' => t('Upload csv file'),
      '#size' => 48,
    );

    $form['strategy'] = array(
      '#type' => 'radios',
      '#title' => t('Import strategy'),
      '#required' => TRUE,
      '#options' => array(
        'overwrite' => 'Overwrite all location terms',
        'append' => 'Append location defined in csv',
      ),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Import nodes with new pcode'),
    );
  }
  $form['#validate'] = array('hr_tools_import_nodes_tag_validate');
  $form['#submit'] = array('hr_tools_import_nodes_tag_submit');
  return $form;
}

/**
 * Form validate callback.
 */
function hr_tools_import_nodes_tag_validate($form, &$form_state) {
  $validators['file_validate_extensions'] = array('csv');
  // Upload to the temp directory, we only need to read it. Afterwards it can be
  // deleted.
  $file = file_save_upload('csv', $validators, FALSE, FILE_EXISTS_REPLACE);
  if (!$file) {
    form_error($form['csv'], t('Something went wrong while uploading the file.'));
    return;
  }
  $form_state['values']['csv'] = $file;
}

/**
 * Form submit callback.
 */
function hr_tools_import_nodes_tag_submit($form, $form_state) {
  $file = $form_state['values']['csv'];
  hr_tools_import_nodes_tag_populate_queue($file->uri, $form_state['values']['strategy'], $form_state['values']['csv_separator']);
}

/**
 * Populate queue.
 */
function hr_tools_import_nodes_tag_populate_queue($csv_file, $strategy, $csv_separator) {
  $batch = array(
    'operations' => array(),
    'title' => t('Importing'),
    'init_message' => t('Initializing.'),
    'progress_message' => t('Processed @current out of @total.'),
    'file' => drupal_get_path('module', 'hr_tools') . '/hr_tools.import.inc',
    'finished' => 'hr_tools_import_nodes_tag_finished',
  );

  // Check file for UTF-8 and BOM.
  check_csv_file_utf8_bom($csv_file);

  $encoding_list[] = "UTF-8";
  $encoding_list[] = "ASCII";
  $encoding_list[] = "ISO-8859-1";

  $handle = fopen($csv_file, 'r');
  // Assume 1 header line.
  $header = fgetcsv($handle, 0, $csv_separator, '"');
  $header_lowercase = array_map('drupal_strtolower', $header);

  while ($row = fgetcsv($handle, 0, $csv_separator, '"')) {
    $data = array();
    for ($i = 0; $i < count($row); $i++) {
      $content = $row[$i];
      if (mb_detect_encoding($content, $encoding_list, TRUE) == 'ISO-8859-1') {
        $row[$i] = utf8_encode($content);
      }
      elseif (!mb_check_encoding($content, 'UTF-8') || !($content === mb_convert_encoding(mb_convert_encoding($content, 'UTF-32', 'UTF-8'), 'UTF-8', 'UTF-32'))) {
        $content = mb_convert_encoding($content, 'UTF-8');
        if (mb_check_encoding($content, 'UTF-8')) {
          $row[$i] = $content;
        }
      }
      $data[$header_lowercase[$i]] = $row[$i];
    }

    $batch['operations'][] = array(
      'hr_tools_import_nodes_tag_line',
      array($data, $strategy),
    );
  }
  fclose($handle);
  batch_set($batch);
  batch_process(current_path());
}

/**
 * Import node data.
 */
function hr_tools_import_nodes_tag_line($data, $strategy, &$context) {
  if (!isset($data['nid']) || empty($data['nid'])) {
    watchdog('hr_tools_importer', 'Nid not set');
    return;
  }

  // Assume it fails.
  $context['results']['failures'][$data['nid']] = TRUE;

  if (!isset($data['new_pcode']) || empty($data['new_pcode'])) {
    $context['results']['failures'][$data['nid']] = 'Missing pcode';
    return;
  }

  // Load term by pcodes.
  $pcodes = array();
  foreach (explode(',', $data['new_pcode']) as $pcode) {
    $pcodes[] = trim($pcode);
  }

  $tids = FALSE;
  $efq = new EntityFieldQuery();
  $results = $efq->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'hr_location')
    ->fieldCondition('field_pcode', 'value', $pcodes, 'IN')
    ->execute();
  if (isset($results['taxonomy_term'])) {
    $tids = array_keys($results['taxonomy_term']);
  }

  if (!$tids) {
    $context['results']['failures'][$data['nid']] = 'No location terms found for ' . $data['new_pcode'];
    return;
  }

  // Load node by nid, reset cache.
  $node = node_load($data['nid'], NULL, TRUE);
  if (!$node) {
    $context['results']['failures'][$data['nid']] = 'Missing node for ' . $data['nid'];
    return;
  }

  // Make sure node has field_locations or field_location.
  $cardinality = -1;
  $location_field_name = '';
  if (isset($node->field_locations)) {
    $cardinality = 0;
    $location_field_name = 'field_locations';
  }
  elseif (isset($node->field_location)) {
    $cardinality = 1;
    $location_field_name = 'field_location';
  }
  else {
    $context['results']['failures'][$data['nid']] = 'Missing location(s) field for ' . $data['nid'];
    return;
  }

  // Check if new pcode is different location.
  $original_locations = array();
  foreach($node->{$location_field_name}['und'] as $loc_id) {
    $original_locations[] = $loc_id['target_id'];
  }

  // Skip if it already exists.
  if (empty(array_diff($tids, $original_locations))) {
    unset($context['results']['failures'][$data['nid']]);
    $context['results']['succes'][$data['nid']] = 'Node already has the same pcodes - ' . $data['nid'];
    return;
  }

  // Check update strategy.
  switch ($strategy) {
    case 'overwrite':
      $node->{$location_field_name}['und'] = array();
      foreach ($tids as $tid) {
        $node->{$location_field_name}['und'][] = array(
          'target_id' => $tid,
        );
      }
      break;

    case 'append':
      foreach (array_diff($tids, $original_locations) as $tid) {
        $node->{$location_field_name}['und'][] = array(
          'target_id' => $tid,
        );
      }
      break;

  }
  node_save($node);

  unset($context['results']['failures'][$data['nid']]);
  $context['results']['succes'][$data['nid']] = 'Imported row ' . $data['nid'];
}

function hr_tools_import_nodes_tag_finished($success, $results, $operations) {
  if ($success) {
    if (!isset($results['succes'])) {
      $results['succes'] = array();
    }
    $message = t('@count locations successfully imported', array('@count' => count($results['succes'])));
    drupal_set_message($message);

    if (!empty($results['failures'])) {
      $message = t('Failed to import @count locations', array('@count' => count($results['failures'])));
      drupal_set_message($message, 'error');
      drupal_set_message(implode('<br>', $results['failures']), 'error');
    }
  }
}

/**
 * Recursively create terms.
 */
function hr_tools_create_terms_location($terms, $voc) {
  $parent = 0;
  foreach ($terms as $term_info) {
    if (!empty($term_info['name'])) {
      $q = db_select('taxonomy_term_data', 't')->fields('t', array('tid'));
      $q->join('taxonomy_term_hierarchy', 'hierarchy', 't.tid = hierarchy.tid');
      $q->join('field_data_field_pcode', 'pcode', 't.tid = pcode.entity_id');
      $existing = $q->condition('pcode.field_pcode_value', $term_info['pcode'])
        ->condition('vid', $voc->vid)
        ->condition('parent', $parent)
        ->range(0, 1)
        ->execute()
        ->fetchField();

      if ($existing) {
        // Check if we need to update.
        $term = taxonomy_term_load($existing);
        if ($term->name != $term_info['name']) {
          $term->name = $term_info['name'];
          $term->name_field['en'][0]['value'] = $term_info['name'];
          $wrapped = entity_metadata_wrapper('taxonomy_term', $term);
          taxonomy_term_save($term);
        }
        $parent = $existing;
        continue;
      }

      $term = new stdClass();
      $term->language = 'en';
      $term->name = $term_info['name'];
      $term->name_field['en'][0]['value'] = $term_info['name'];
      $term->field_pcode['und'][0]['value'] = $term_info['pcode'];
      $term->field_loc_admin_level['und'][0]['value'] = $term_info['admin'];
      $term->vid = $voc->vid;
      $term->parent = $parent;
      $term->vocabulary_machine_name = $voc->machine_name;
      $wrapped = entity_metadata_wrapper('taxonomy_term', $term);
      taxonomy_term_save($term);
      $parent = $term->tid;
    }
  }
  return $parent;
}

/**
 * Check file for UTF-8 and BOM.
 */
function check_csv_file_utf8_bom($csv_file) {
  // Make sure it's UTF-8.
  $contents = file_get_contents($csv_file);
  if (!mb_check_encoding($contents, 'UTF-8')) {
    $encoding_list[] = "UTF-8";
    $encoding_list[] = "ASCII";
    $encoding_list[] = "ISO-8859-1";
    file_put_contents($csv_file, mb_convert_encoding($contents, 'UTF-8', mb_detect_encoding($contents, $encoding_list, TRUE)));
  }

  // Make sure it's has no BOM.
  $contents = file_get_contents($csv_file);
  $bom = pack('CCC', 0xEF, 0xBB, 0xBF);
  if (strncmp($contents, $bom, 3) === 0) {
    $contents = substr($contents, 3);
    file_put_contents($csv_file, $contents);
  }
}
