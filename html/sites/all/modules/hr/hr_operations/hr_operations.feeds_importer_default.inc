<?php

/**
 * @file
 * hr_operations.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_operations_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_operations';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import operations from a CSV file',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'allowed_schemes' => array(
          0 => 'public',
        ),
        'direct' => FALSE,
        'directory' => 'public://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Operations',
    'parser' => array(
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
      'plugin_key' => 'FeedsCSVParser',
    ),
    'process_in_background' => 0,
    'processor' => array(
      'config' => array(
        'author' => '1',
        'authorize' => 1,
        'bundle' => 'hr_operation',
        'expire' => '-1',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Name:en',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name:fr',
            'target' => 'title_field:et:fr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Name:es',
            'target' => 'title_field:et:es',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Country',
            'target' => 'field_country:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Website',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Type',
            'target' => 'field_operation_type',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Region',
            'target' => 'field_operation_region:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Launch Date',
            'target' => 'field_launch_date:start',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Visibility',
            'target' => 'group_access',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Status',
            'target' => 'field_operation_status',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Published',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
      ),
      'plugin_key' => 'FeedsNodeProcessor',
    ),
    'update' => 0,
  );
  $export['hr_operations'] = $feeds_importer;

  return $export;
}
