<?php

/**
 * @file
 * hr_locations.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_locations_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_locations';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import locations from a CSV file',
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
    'name' => 'Locations',
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
        'bundle' => 'hr_location',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Name',
            'target' => 'name_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'PCode',
            'target' => 'field_pcode',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'Local PCode',
            'target' => 'field_local_pcode',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'PCode',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'WKT',
            'target' => 'field_geofield:wkt',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 1,
        'update_existing' => '2',
        'vocabulary' => 0,
      ),
      'plugin_key' => 'FeedsTermProcessor',
    ),
    'update' => 0,
  );
  $export['hr_locations'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_locations_shp';
  $feeds_importer->config = array(
    'content_type' => '',
    'description' => 'Import locations from a shapefile',
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
    'name' => 'Locations Shapefiles',
    'parser' => array(
      'config' => array(
        'spatial_field_name' => 'geom',
        'srid' => '4326',
        'storage' => 'wkt',
      ),
      'plugin_key' => 'SpatialImportShapefileParser',
    ),
    'process_in_background' => 0,
    'processor' => array(
      'config' => array(
        'bundle' => 'hr_location',
        'input_format' => 'plain_text',
        'mappings' => array(
          0 => array(
            'source' => 'HRName',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'HRName',
            'target' => 'name_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'HRPCode',
            'target' => 'field_pcode',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'HRPCode',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'HRParent',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'geom',
            'target' => 'field_geofield:wkt',
            'unique' => FALSE,
          ),
        ),
        'skip_hash_check' => 1,
        'update_existing' => '2',
        'vocabulary' => 0,
      ),
      'plugin_key' => 'FeedsTermProcessor',
    ),
    'update' => 0,
  );
  $export['hr_locations_shp'] = $feeds_importer;

  return $export;
}
