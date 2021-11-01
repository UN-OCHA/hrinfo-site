<?php

/**
 * @file
 * hr_offices.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_offices_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_offices';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import offices from a CSV file',
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
    'name' => 'Offices',
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
        'author' => 0,
        'authorize' => 1,
        'bundle' => 'hr_office',
        'expire' => '-1',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Telephone',
            'target' => 'field_phones',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Location',
            'target' => 'field_location:label',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Address 1',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Address 2',
            'target' => 'field_address:premise',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'City',
            'target' => 'field_address:locality',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Postal Code',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'State',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Country',
            'target' => 'field_address:country',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Organization',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Coordination Hub',
            'target' => 'field_is_coordination_hub',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Spaces',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
          13 => array(
            'pathauto_override' => 1,
            'source' => 'Path',
            'target' => 'path_alias',
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '0',
      ),
      'plugin_key' => 'FeedsNodeProcessor',
    ),
    'update' => 0,
  );
  $export['hr_offices'] = $feeds_importer;

  return $export;
}
