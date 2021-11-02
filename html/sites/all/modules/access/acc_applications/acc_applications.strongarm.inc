<?php

/**
 * @file
 * acc_applications.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function acc_applications_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_acc_application';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_acc_application';
  $strongarm->value = ' [node:field_acc_application_types] [node:field_acc_geo_location_dest]';
  $export['auto_entitylabel_pattern_node_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_acc_application';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__acc_application';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'path' => array(
          'weight' => '17',
        ),
        'redirect' => array(
          'weight' => '18',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(),
  );
  $export['field_bundle_settings_node__acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_acc_application';
  $strongarm->value = '0';
  $export['language_content_type_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_acc_application';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_acc_application';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_acc_application';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_acc_application';
  $strongarm->value = '1';
  $export['node_preview_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_acc_application';
  $strongarm->value = 0;
  $export['node_submitted_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_acc_application';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'default' => array(
        'choice' => 0,
        'default' => 1,
        'status' => 1,
      ),
      'page_manager' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'search_result' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'teaser' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_acc_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_acc_application_submission_status';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(
      'default' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'diff_standard' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'full' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'ical' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'page_manager' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'token' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_taxonomy_term_acc_application_submission_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_acc_application_types';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(
      'default' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'diff_standard' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'full' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'ical' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'page_manager' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
      'token' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_taxonomy_term_acc_application_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_acc_application_pattern';
  $strongarm->value = '[node:og-group-ref:0:url:path]/access-application/[node:title]';
  $export['pathauto_node_acc_application_pattern'] = $strongarm;

  return $export;
}
