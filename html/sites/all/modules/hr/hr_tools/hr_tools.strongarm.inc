<?php

/**
 * @file
 * hr_tools.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_tools_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hr_toolbox_category';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'language' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hr_toolbox_item';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'language' => array(
          'weight' => '8',
        ),
        'path' => array(
          'weight' => '10',
        ),
        'redirect' => array(
          'weight' => '9',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_hr_toolbox_category';
  $strongarm->value = '4';
  $export['language_content_type_hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_hr_toolbox_item';
  $strongarm->value = '4';
  $export['language_content_type_hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hr_toolbox_category';
  $strongarm->value = array();
  $export['menu_options_hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hr_toolbox_item';
  $strongarm->value = array();
  $export['menu_options_hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hr_toolbox_category';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hr_toolbox_item';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hr_toolbox_category';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hr_toolbox_item';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hr_toolbox_category';
  $strongarm->value = '1';
  $export['node_preview_hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hr_toolbox_item';
  $strongarm->value = '1';
  $export['node_preview_hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hr_toolbox_category';
  $strongarm->value = 0;
  $export['node_submitted_hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hr_toolbox_item';
  $strongarm->value = 0;
  $export['node_submitted_hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_hr_toolbox_category';
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
  $export['panelizer_defaults_node_hr_toolbox_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_hr_toolbox_item';
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
        'default' => 1,
        'status' => 1,
      ),
      'teaser' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_hr_toolbox_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_toolbox_item_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:hr_toolbox_item_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_toolbox_item_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:hr_toolbox_item_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_toolbox_item_default';
  $strongarm->value = array(
    'bean_pane' => 'bean_pane',
    'block' => 'block',
    'custom' => 'custom',
    'entity_field' => 'entity_field',
    'entity_field_extra' => 'entity_field_extra',
    'entity_form_field' => 'entity_form_field',
    'entity_view' => 'entity_view',
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'flag_link' => 'flag_link',
    'openlayers_map' => 'openlayers_map',
    'other' => 'other',
    'panels_mini' => 'panels_mini',
    'token' => 'token',
    'views' => 'views',
    'views_panes' => 'views_panes',
  );
  $export['panelizer_node:hr_toolbox_item_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_category_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_category_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_category_es_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_category_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_category_fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_category_fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_category_pattern';
  $strongarm->value = '[node:og-group-ref:0:url:path]/category/[node:title]';
  $export['pathauto_node_hr_toolbox_category_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_category_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_category_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_item_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_item_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_item_es_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_item_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_item_fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_item_fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_item_pattern';
  $strongarm->value = '[node:og-group-ref:0:url:path]/toolbox-item/[node:title]';
  $export['pathauto_node_hr_toolbox_item_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_toolbox_item_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_toolbox_item_und_pattern'] = $strongarm;

  return $export;
}
