<?php

/**
 * @file
 * hr_spaces.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_spaces_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_space_categories';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import space categories from a CSV file',
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
    'name' => 'Space Categories',
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
        'bundle' => 'hr_space_category',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Name:en',
            'target' => 'name_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name:fr',
            'target' => 'name_field:et:fr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Name:es',
            'target' => 'name_field:et:es',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '2',
        'vocabulary' => 0,
      ),
      'plugin_key' => 'FeedsTermProcessor',
    ),
    'update' => 0,
  );
  $export['hr_space_categories'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_spaces';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import spaces from a CSV file',
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
    'name' => 'Spaces',
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
        'bundle' => 'hr_space',
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
            'source' => 'Type',
            'target' => 'field_space_type',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Category',
            'target' => 'field_space_category:label',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Icon',
            'target' => 'field_image:uri',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Website',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          8 => array(
            'pathauto_override' => 1,
            'source' => 'URL',
            'target' => 'path_alias',
          ),
          9 => array(
            'source' => 'Email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Mailchimp API key',
            'target' => 'field_mailchimp_api_key',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Mailchimp List',
            'target' => 'field_mailchimp_list',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Visibility',
            'target' => 'group_access',
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
  $export['hr_spaces'] = $feeds_importer;

  return $export;
}
