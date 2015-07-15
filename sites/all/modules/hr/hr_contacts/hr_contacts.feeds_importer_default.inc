<?php
/**
 * @file
 * hr_contacts.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_contacts_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_contacts';
  $feeds_importer->config = array(
    'name' => 'Contacts',
    'description' => 'Import contacts from a CSV file',
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
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Clusters/Sectors',
            'target' => 'field_bundles:label',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'First name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Last name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Main Email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Phones',
            'target' => 'field_phones',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Organization',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Job Title',
            'target' => 'field_job_title_other',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Location',
            'target' => 'field_location:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Coordination hubs',
            'target' => 'field_coordination_hubs:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Themes',
            'target' => 'field_themes:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Disasters',
            'target' => 'field_disasters:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Spaces',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_contact',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_contacts'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_contacts_1x';
  $feeds_importer->config = array(
    'name' => 'Contacts 1.x',
    'description' => 'Import contacts from a CSV file of the 1.x version',
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
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Clusters',
            'target' => 'field_bundles:label',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'First name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Last name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Email',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Telephones',
            'target' => 'field_phones',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Organization',
            'target' => 'field_organizations:label',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Job Title',
            'target' => 'field_job_title_other',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Location',
            'target' => 'field_location:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Coordination Hub',
            'target' => 'field_coordination_hubs:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Theme(s)',
            'target' => 'field_themes:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Disasters',
            'target' => 'field_disasters:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Spaces',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_contact',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_contacts_1x'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_functional_roles';
  $feeds_importer->config = array(
    'name' => 'Functional Roles',
    'description' => 'Import functional roles from a CSV file',
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
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'hr_functional_role',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_functional_roles'] = $feeds_importer;

  return $export;
}
