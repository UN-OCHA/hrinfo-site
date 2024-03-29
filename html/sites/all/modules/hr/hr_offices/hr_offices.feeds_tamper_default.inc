<?php

/**
 * @file
 * hr_offices.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function hr_offices_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_offices-organization-explode';
  $feeds_tamper->importer = 'hr_offices';
  $feeds_tamper->source = 'Organization';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['hr_offices-organization-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_offices-spaces-explode';
  $feeds_tamper->importer = 'hr_offices';
  $feeds_tamper->source = 'Spaces';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ';',
    'separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['hr_offices-spaces-explode'] = $feeds_tamper;

  return $export;
}
