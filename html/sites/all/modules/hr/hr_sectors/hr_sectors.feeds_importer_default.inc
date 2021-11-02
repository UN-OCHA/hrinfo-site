<?php

/**
 * @file
 * hr_sectors.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_sectors_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_sectors';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import sectors from a CSV file',
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
    'name' => 'Sectors',
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
        'bundle' => 'hr_sector',
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
            'source' => 'Icon',
            'target' => 'field_image:uri',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Website',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Mailchimp API key',
            'target' => 'field_mailchimp_api_key',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Mailchimp List',
            'target' => 'field_mailchimp_list',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Visibility',
            'target' => 'group_access',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Acronym:en',
            'target' => 'field_acronym:et:en',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Acronym:fr',
            'target' => 'field_acronym:et:fr',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Acronym:es',
            'target' => 'field_acronym:et:es',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'update_non_existent' => 'skip',
      ),
      'plugin_key' => 'FeedsNodeProcessor',
    ),
    'update' => 0,
  );
  $export['hr_sectors'] = $feeds_importer;

  return $export;
}
