<?php

/**
 * @file
 * Hr_core module drush integration.
 */

/**
 * Implements hook_drush_command().
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

  $items['hr-core-docstore-create-vocab'] = array(
    'description' => "Create a vocabulary in the docstore via its API, and
      associated fields on the document bundle.",
    'drupal dependencies' => array(),
    'options' => array(
      'vocab' => array(
        'description' => 'Vocabulary to create',
        'example-value' => 'Document type',
      ),
      'cardinality' => array(
        'description' => 'Whether documents can have multiple terms from this
          vocabulary',
        'example-value' => 'multiple',
      ),
    ),
    'aliases' => array("hr-docs-voc"),
  );

  $items['hr-core-docstore-add-field'] = array(
    'description' => "Add a field to documents in the docstore via its API.
      Not needed for fields which reference vocabularies.",
    'drupal dependencies' => array(),
    'arguments' => array(
      'label' => array(
        'description' => 'Name of field to add',
        'example-value' => 'Document type',
      ),
      'type' => array(
        'description' => '"target" or "type" for other fields field',
        'example-value' => 'type',
      ),
      'value' => array(
        'description' => 'Target name for vocab, or type',
        'example-value' => 'integer',
      ),
    ),
    'options' => array(
      'cardinality' => array(
        'description' => 'Whether documents can have multiple terms from this
          vocabulary',
        'example-value' => 'multiple',
      ),
    ),
    'aliases' => array("hr-docs-field"),
  );

  $items['hr-core-docstore-populate'] = array(
    'description' => "Put documents in the docstore via its API.
      First, create relevant vocabularies and fields.
      N.B. Make sure to clear the docstore site cache before running this!",
    'drupal dependencies' => array(),
    'options' => array(
      'bundle' => array(
        'description' => 'The node type to push',
        'example-value' => 'hr_document',
      ),
      'offset' => array(
        'description' => 'The number of documents to skip',
        'example-value' => '20',
      ),
      'limit' => array(
        'description' => 'The number of documents to push',
        'example-value' => '20',
      ),
    ),
    'aliases' => array("hr-docs-pop"),
  );

  return $items;
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
 * Create a docstore vocabulary.
 */
function drush_hr_core_docstore_create_vocab() {

  drush_log(t('Will create vocab on docstore.'));

  $vocab_name = drush_get_option('vocab', '');
  if (empty($vocab_name)) {
    drush_log(t('You need to specify a vocabulary name to create.'));
  }
  $cardinality = drush_get_option('cardinality', 'single');

  $prefix = variable_get('docstore_property_prefix', 'hrinfo_');
  $exists = hr_docstore_call_api('GET', 'vocabularies/' . $prefix . strtolower($vocab_name));
  if (empty($exists['uuid'])) {
    $json = new \stdClass();
    $json->label = $vocab_name;
    $json->author = 'hrinfo';

    $result = hr_docstore_call_api('POST', 'vocabularies', json_encode($json));

    if (!empty($result['machine_name'])) {
      drush_hr_core_docstore_add_field($vocab_name, 'target', $result['machine_name'], $cardinality);
    }
  }
}

/**
 * Add a field to document.
 */
function drush_hr_core_docstore_add_field($label, $type, $value, $cardinality = 'single') {

  if (empty($label)) {
    drush_log(t('You need to specify a name for the field to add.'));
  }
  if (empty($type)) {
    drush_log(t('You need to specify "type" or "target".'));
  }
  if (empty($value)) {
    drush_log(t('You need to specify the type value, or the target.'));
  }
  $cardinality_option = drush_get_option('cardinality', 'single');

  $fields = hr_docstore_call_api('GET', 'fields/documents');
  if (!in_array($value, array_keys($fields))) {
    $json = new \stdClass();
    $json->label = $label;
    $json->author = 'hrinfo';
    $json->$type = $value;
    if ($cardinality === 'multiple' || $cardinality_option === 'multiple') {
      $json->multiple = TRUE;
    }
    hr_docstore_call_api('POST', 'fields/documents', json_encode($json));
  }
}

/**
 * Push documents to the docstore.
 */
function drush_hr_core_docstore_populate() {
  if (!drush_bootstrap_to_phase(DRUSH_BOOTSTRAP_DRUPAL_DATABASE)) {
    return drush_set_error('DRUPAL_SITE_NOT_FOUND',
      dt('You need to specify an alias or run this command within a site.')
    );
  }

  $bundle = drush_get_option('bundle', 'hr_document');
  $offset = drush_get_option('offset', '0');
  $default_limit = db_query("
    SELECT nid
    FROM node
    WHERE type = :bundle", array(':bundle' => $bundle)
  )->rowCount();
  $limit = drush_get_option('limit', $default_limit);

  $batch = array(
    'title' => t('Pushing documents to docstore'),
    'operations' => array(
      array(
        'drush_hr_core_docstore_push_batch_operation',
        array($bundle, $offset, $limit),
      ),
    ),
    'finished' => 'drush_hr_core_docstore_push_batch_finished',
  );
  batch_set($batch);
  $batch =& batch_get();
  drush_backend_batch_process();
}

/**
 * Batch handler.
 */
function drush_hr_core_docstore_push_batch_operation($bundle, $offset, $limit, &$context) {

  // Initiate multistep processing.
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    // Index more recent documents first.
    $start = db_query_range("
      SELECT nid
      FROM {node}
      WHERE type = :bundle
      ORDER BY nid
      DESC", $offset, 1, array(':bundle' => $bundle)
    )->fetchField();
    $context['sandbox']['current_entity_id'] = $start;
    $context['sandbox']['max'] = $limit;
    $context['sandbox']['terms'] = array();
    $context['message'] = 'Starting push of documents to docstore.';
    $prefix = variable_get('docstore_property_prefix', 'hrinfo_');
    $context['sandbox']['prefix'] = $prefix;
    // Get all the fields for the property.
    $fields = hr_docstore_call_api('GET', 'fields/documents');

    $prefix = $context['sandbox']['prefix'];
    $field_array = array();
    $property_fields = array_filter(array_map(function ($field) use ($prefix) {
      return (strpos($field, $prefix) === 0 || strpos($field, 'base_') === 0) ? $field : NULL;
    }, array_keys($fields)));
    $context['sandbox']['property_fields'] = $property_fields;
    foreach ($property_fields as $field) {
      $field_info = hr_docstore_call_api('GET', 'fields/documents/' . $field);
      $field_array[$field] = $field_info;
    }
    $context['sandbox']['field_array'] = $field_array;
  }

  $property_fields = $context['sandbox']['property_fields'];
  $field_array = $context['sandbox']['field_array'];

  // Select the next batch.
  $batch_limit = $limit > 50 ? 50 : $limit;
  $results = db_query_range(
    "SELECT nid FROM {node}
    WHERE nid < :entity_id
      AND type = :bundle
    ORDER BY nid
    DESC", 0, $batch_limit, array(
      ':entity_id' => $context['sandbox']['current_entity_id'],
      ':bundle' => $bundle,
    ))->fetchAll();

  foreach ($results as $result) {
    $wrapper = entity_metadata_wrapper('node', $result->nid);

    hr_docstore_create($property_fields, $field_array, $wrapper);

    $context['sandbox']['progress']++;
    $context['sandbox']['current_entity_id'] = $result->nid;
  }

  // Multistep processing : report progress.
  if (!empty($results) && $context['sandbox']['progress'] <= $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    $context['message'] = 'Progress ' . $context['sandbox']['progress'] . '/' . $context['sandbox']['max'];
  }
  else {
    $context['finished'] = TRUE;
  }
}

/**
 * Finished callback.
 */
function drush_hr_core_docstore_push_batch_finished($success, $results, $operations) {
  if ($success) {
    drush_log(t('The documents have been pushed to the docstore.'));
  }
  else {
    drush_log(t('There was an error pushing documents to the docstore.'), 'error');
  }
  cache_clear_all();
}
