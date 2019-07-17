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
    'name' => 'Locations',
    'description' => 'Import locations from a CSV file',
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
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
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'hr_location',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_locations'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_locations_shp';
  $feeds_importer->config = array(
    'name' => 'Locations Shapefiles',
    'description' => 'Import locations from a shapefile',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'SpatialImportShapefileParser',
      'config' => array(
        'spatial_field_name' => 'geom',
        'srid' => '4326',
        'storage' => 'wkt',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
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
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'hr_location',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_locations_shp'] = $feeds_importer;

  return $export;
}
