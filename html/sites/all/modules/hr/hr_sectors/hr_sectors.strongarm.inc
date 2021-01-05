<?php

/**
 * @file
 * hr_sectors.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_sectors_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_hr_sector';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_hr_sector';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_hr_sector';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_hr_sector';
  $strongarm->value = 0;
  $export['entity_translation_hide_translation_links_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_hr_sector';
  $strongarm->value = '1';
  $export['entity_translation_node_metadata_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__hr_sector';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 0,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hr_sector';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'language' => array(
          'weight' => '13',
        ),
        'og_menu' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '15',
        ),
        'redirect' => array(
          'weight' => '14',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_hr_sector';
  $strongarm->value = '4';
  $export['language_content_type_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hr_sector';
  $strongarm->value = array();
  $export['menu_options_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hr_sector';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hr_sector';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hr_sector';
  $strongarm->value = '1';
  $export['node_preview_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hr_sector';
  $strongarm->value = 0;
  $export['node_submitted_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_features_settings_node_hr_sector';
  $strongarm->value = array(
    'acc_applications' => '0',
    'acc_incidents' => '0',
    'ev_events' => '0',
    'hdx_datasets' => '0',
    'hr_assessments' => '0',
    'hr_datasets' => '0',
    'hr_disasters' => '0',
    'hr_documents' => '2',
    'hr_events' => '2',
    'hr_infographics' => '3',
    'hr_news' => '0',
    'hr_offices' => '0',
    'hr_pages' => '2',
    'hr_reliefweb_documents' => '0',
    'hr_reliefweb_meeting_documents' => '3',
    'hr_users' => '2',
  );
  $export['og_features_settings_node_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_hr_sector';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'search_result' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_hr_sector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_sector_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:24:"panelizer_node:hr_sector";s:23:"allowed_layout_settings";a:9:{s:8:"flexible";b:1;s:6:"onecol";b:1;s:17:"threecol_33_34_33";b:1;s:14:"twocol_stacked";b:1;s:17:"threecol_25_50_25";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:6:"twocol";b:1;s:13:"twocol_bricks";b:1;}s:10:"form_state";N;}';
  $export['panelizer_node:hr_sector_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_sector_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:hr_sector_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_sector_allowed_types';
  $strongarm->value = array(
    'node_body-node_body' => '1',
    'hr_documents_key_documents-hr_documents_key_documents' => '1',
    'hr_infographics_key_infographics-hr_infographics_key_infographics' => '1',
    'hr_layout_reliefweb-hr_layout_reliefweb' => '1',
    'hr_layout_rss_feeds-hr_layout_rss_feeds' => '1',
    'fieldable_panels_pane-fieldable_panels_pane' => '1',
    'views_panes-hr_documents_panes-list' => '1',
    'views_panes-hr_events_panes-upcoming' => '1',
    'views_panes-hr_news_panes-list' => '1',
  );
  $export['panelizer_node:hr_sector_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_sector_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:hr_sector_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_sector_default';
  $strongarm->value = array(
    'bean_pane' => 0,
    'block' => 0,
    'entity_form_field' => 0,
    'custom' => 0,
    'entity_field_extra' => 0,
    'entity_field' => 0,
    'token' => 0,
    'entity_view' => 0,
    'entity_collection' => 0,
    'fieldable_panels_pane' => 0,
    'flag_link' => 0,
    'openlayers_map' => 0,
    'panels_mini' => 0,
    'views' => 0,
    'views_panes' => 0,
    'other' => 0,
  );
  $export['panelizer_node:hr_sector_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_sector_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_sector_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_sector_es_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_sector_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_sector_fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_sector_fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_sector_pattern';
  $strongarm->value = 'clusters/[node:title]';
  $export['pathauto_node_hr_sector_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_sector_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_sector_und_pattern'] = $strongarm;

  return $export;
}
