<?php

/**
 * @file
 * hr_bundles.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_bundles_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_bundles';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import bundles from a CSV file',
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
    'name' => 'Bundles',
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
        'bundle' => 'hr_bundle',
        'expire' => '-1',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'title',
            'unique' => FALSE,
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
            'source' => 'Sector',
            'target' => 'field_sector:label',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Operation',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Type',
            'target' => 'field_bundle_type',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Lead Agencies',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Partners',
            'target' => 'field_partners:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'NGO Participation',
            'target' => 'field_ngo_participation',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Government Participation',
            'target' => 'field_government_participation',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Intercluster',
            'target' => 'field_inter_cluster',
            'unique' => FALSE,
          ),
          12 => array(
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
  $export['hr_bundles'] = $feeds_importer;

  return $export;
}
