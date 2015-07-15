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
    'name' => 'Operations',
    'description' => 'Import operations from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
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
            'source' => 'Mailchimp API key',
            'target' => 'field_mailchimp_api_key',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Mailchimp List',
            'target' => 'field_mailchimp_list',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Launch Date',
            'target' => 'field_launch_date:start',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Visibility',
            'target' => 'group_access',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Status',
            'target' => 'field_operation_status',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Published',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_operation',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_operations'] = $feeds_importer;

  return $export;
}
