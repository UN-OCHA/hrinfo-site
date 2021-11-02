<?php

/**
 * @file
 * hr_documents.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_documents_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_document_types';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import document types from a CSV file',
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
    'name' => 'Document Types',
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
        'bundle' => 'hr_document_type',
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
          4 => array(
            'source' => 'Parent',
            'target' => 'parent',
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
  $export['hr_document_types'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_documents';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import documents from a CSV file',
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
    'name' => 'Documents',
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
        'bundle' => 'hr_document',
        'expire' => '-1',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Guid',
            'target' => 'guid',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'Title:en',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Title:fr',
            'target' => 'title_field:et:fr',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Title:es',
            'target' => 'title_field:et:es',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Description',
            'target' => 'body:et:und',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Description',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Type',
            'target' => 'field_document_type:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'File',
            'target' => 'field_files_collection:field_file:uri',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Language',
            'target' => 'field_files_collection:field_language',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Sectors',
            'target' => 'field_sectors:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Clusters/Sectors',
            'target' => 'field_bundles:label',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Publication Date',
            'target' => 'field_publication_date:start',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Organization',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Coordination hubs',
            'target' => 'field_coordination_hubs:label',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Locations',
            'target' => 'field_locations:label',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Fundings',
            'target' => 'field_fundings:label',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'Themes',
            'target' => 'field_themes:label',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Disasters',
            'target' => 'field_disasters:label',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'Spaces',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Post date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'Author',
            'target' => 'user_mail',
            'unique' => FALSE,
          ),
          22 => array(
            'pathauto_override' => 1,
            'source' => 'Path',
            'target' => 'path_alias',
          ),
        ),
        'skip_hash_check' => 0,
        'update_existing' => '0',
        'update_non_existent' => 'skip',
      ),
      'plugin_key' => 'FeedsNodeProcessor',
    ),
    'update' => 0,
  );
  $export['hr_documents'] = $feeds_importer;

  return $export;
}
