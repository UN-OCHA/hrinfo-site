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
    'name' => 'Bundles',
    'description' => 'Import bundles from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
            'source' => 'Lead Agencies',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Partners',
            'target' => 'field_partners:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'NGO Participation',
            'target' => 'field_ngo_participation',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Government Participation',
            'target' => 'field_government_participation',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Intercluster',
            'target' => 'field_inter_cluster',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Path',
            'target' => 'path_alias',
            'pathauto_override' => 1,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_bundle',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_bundles'] = $feeds_importer;

  return $export;
}
