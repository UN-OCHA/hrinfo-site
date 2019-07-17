<?php
/**
 * @file
 * acc_applications.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function acc_applications_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_acc_application-impact_value-explode';
  $feeds_tamper->importer = 'csv_acc_application';
  $feeds_tamper->source = 'Impact value';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_acc_application-impact_value-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_acc_application-nationality_of_traveler-explode';
  $feeds_tamper->importer = 'csv_acc_application';
  $feeds_tamper->source = 'Nationality of traveler';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['csv_acc_application-nationality_of_traveler-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_acc_application-nationality_of_traveler-strtotime';
  $feeds_tamper->importer = 'csv_acc_application';
  $feeds_tamper->source = 'Nationality of traveler';
  $feeds_tamper->plugin_id = '';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['csv_acc_application-nationality_of_traveler-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_acc_application-organization_type-explode';
  $feeds_tamper->importer = 'csv_acc_application';
  $feeds_tamper->source = 'Organization Type';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_acc_application-organization_type-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_acc_application-sectors-explode';
  $feeds_tamper->importer = 'csv_acc_application';
  $feeds_tamper->source = 'Sectors';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_acc_application-sectors-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_acc_application-submitted_by-explode';
  $feeds_tamper->importer = 'csv_acc_application';
  $feeds_tamper->source = 'Submitted By';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_acc_application-submitted_by-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_acc_application-type_of_impact-explode';
  $feeds_tamper->importer = 'csv_acc_application';
  $feeds_tamper->source = 'Type of impact';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_acc_application-type_of_impact-explode'] = $feeds_tamper;

  return $export;
}
