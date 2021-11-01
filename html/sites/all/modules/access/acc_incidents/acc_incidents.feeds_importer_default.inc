<?php

/**
 * @file
 * acc_incidents.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function acc_incidents_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_csv_impact';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'To import Access Impact Types in csv',
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
    'name' => 'CSV Access Impact',
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
        'bundle' => 'acc_impact_types',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => FALSE,
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
        'update_existing' => '1',
        'vocabulary' => 0,
      ),
      'plugin_key' => 'FeedsTermProcessor',
    ),
    'update' => 0,
  );
  $export['acc_csv_impact'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_csv_incident';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'To import Access Incidents in csv',
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
    'name' => 'CSV Access Incident',
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
        'bundle' => 'acc_incident',
        'expire' => '-1',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Type',
            'target' => 'field_acc_type:label',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Location',
            'target' => 'field_locations:label',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Start Date',
            'target' => 'field_acc_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'End date',
            'target' => 'field_acc_date:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Responsible Actors',
            'target' => 'field_responsible_actors:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Affected organizations',
            'target' => 'field_affected_organizations:label',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Responsible Actors Type',
            'target' => 'field_responsible_organization_t:label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Affected organization type',
            'target' => 'field_affected_organization_type:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Type of affectee',
            'target' => 'field_type_of_affectee:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Type of impact',
            'target' => 'field_acc_impacts:field_acc_impact_type:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Impact Value',
            'target' => 'field_acc_impacts:field_acc_impact_value',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Description',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Sectors',
            'target' => 'field_sectors:label',
            'unique' => FALSE,
          ),
          13 => array(
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
  $export['acc_csv_incident'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_csv_responsible_actor';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'To import terms for Responsible Actor taxonomy for Humanitarian Access Module',
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
    'name' => 'CSV Access Responsible Actor',
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
        'bundle' => 'acc_responsible_actors',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => FALSE,
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
            'source' => 'Type',
            'target' => 'field_organization_type:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Description',
            'target' => 'description',
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
  $export['acc_csv_responsible_actor'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_csv_types';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'To import Access Incident Types in csv',
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
    'name' => 'CSV Access Types',
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
        'bundle' => 'acc_incident_types',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => FALSE,
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
  $export['acc_csv_types'] = $feeds_importer;

  return $export;
}
