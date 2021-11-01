<?php

/**
 * @file
 * hr_infographics.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_infographics_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_hr_infographic';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_hr_infographic';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_hr_infographic';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__hr_infographic';
  $strongarm->value = array(
    'default_language' => 'xx-et-current',
    'exclude_language_none' => 1,
    'hide_language_selector' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hr_infographic';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'hr_core_files_download_button' => array(
          'default' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'teaser' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
        ),
        'hr_core_read_more_button' => array(
          'default' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'teaser' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
        ),
        'hr_core_share_button' => array(
          'default' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'teaser' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
        ),
      ),
      'form' => array(
        'flag' => array(
          'weight' => '13',
        ),
        'language' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '19',
        ),
        'redirect' => array(
          'weight' => '20',
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
  $export['field_bundle_settings_node__hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_hr_infographic';
  $strongarm->value = '4';
  $export['language_content_type_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hr_infographic';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hr_infographic';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hr_infographic';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
  );
  $export['node_options_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hr_infographic';
  $strongarm->value = '1';
  $export['node_preview_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hr_infographic';
  $strongarm->value = 0;
  $export['node_submitted_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_hr_infographic';
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
        'default' => 1,
        'status' => 1,
      ),
    ),
  );
  $export['panelizer_defaults_node_hr_infographic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_infographic_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:hr_infographic_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_infographic_default';
  $strongarm->value = array(
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
    'token' => 'token',
    'views' => 'views',
    'views_panes' => 'views_panes',
  );
  $export['panelizer_node:hr_infographic_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_infographic_pattern';
  $strongarm->value = '[node:og-group-ref:0:url:path]/infographic/[node:title]';
  $export['pathauto_node_hr_infographic_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hr_infographic_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_hr_infographic_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publishcontent_hr_infographic';
  $strongarm->value = 1;
  $export['publishcontent_hr_infographic'] = $strongarm;

  return $export;
}
