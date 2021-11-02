<?php

/**
 * @file
 * acc_applications.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function acc_applications_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_submission_status';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'To import Access Submission Status in csv',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'use_pubsubhubbub' => FALSE,
      ),
      'plugin_key' => 'FeedsHTTPFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'CSV Access Submission Status',
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
        'bundle' => 'acc_application_submission_status',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Parent',
            'target' => 'parent',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '0',
        'vocabulary' => 0,
      ),
      'plugin_key' => 'FeedsTermProcessor',
    ),
    'update' => 0,
  );
  $export['acc_submission_status'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_acc_application';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'To import Access Applications in csv',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'direct' => FALSE,
        'directory' => 'private://feeds',
      ),
      'plugin_key' => 'FeedsFileFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'CSV Access Applications',
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
        'bundle' => 'acc_application',
        'expire' => '-1',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Application Types',
            'target' => 'field_acc_application_types:label',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Date Start',
            'target' => 'field_acc_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Date End',
            'target' => 'field_acc_date:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Organization Type',
            'target' => 'field_acc_submitted_by_org_type:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Submitted By',
            'target' => 'field_acc_submitted_by:label',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Submitted To',
            'target' => 'field_submitted_to:label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Submission Status',
            'target' => 'field_acc_submission_status:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'If denied, by whom?',
            'target' => 'field_if_denied_by_whom_:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'How many days to get an answer?',
            'target' => 'field_how_many_days',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Sectors',
            'target' => 'field_sector:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Geograpical Location Destination',
            'target' => 'field_acc_geo_location_dest:label',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Geograpical Location Origin',
            'target' => 'field_locations:label',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Nationality of traveler',
            'target' => 'field_nationality',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Type of impact',
            'target' => 'field_acc_impacts:field_acc_impact_type:label',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Impact value',
            'target' => 'field_acc_impacts:field_acc_impact_value',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Description',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'Groups audience',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '0',
      ),
      'plugin_key' => 'FeedsNodeProcessor',
    ),
    'update' => 0,
  );
  $export['csv_acc_application'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_acc_application_types';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'To import Access Application Types in csv',
    'expire_period' => 3600,
    'fetcher' => array(
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'use_pubsubhubbub' => FALSE,
      ),
      'plugin_key' => 'FeedsHTTPFetcher',
    ),
    'import_on_create' => 1,
    'import_period' => '-1',
    'name' => 'Access Application Types',
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
        'bundle' => 'acc_application_types',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Parent',
            'target' => 'parent',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '0',
        'vocabulary' => 0,
      ),
      'plugin_key' => 'FeedsTermProcessor',
    ),
    'update' => 0,
  );
  $export['csv_acc_application_types'] = $feeds_importer;

  return $export;
}
