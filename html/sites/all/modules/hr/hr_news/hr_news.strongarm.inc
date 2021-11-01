<?php

/**
 * @file
 * hr_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_hr_news';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_hr_news';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_hr_news';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__hr_news';
  $strongarm->value = array(
    'default_language' => 'xx-et-current',
    'exclude_language_none' => 1,
    'hide_language_selector' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hr_news';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'language' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '15',
        ),
        'redirect' => array(
          'weight' => '16',
        ),
        'title' => array(
          'weight' => '0',
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
  $export['field_bundle_settings_node__hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_hr_news';
  $strongarm->value = '4';
  $export['language_content_type_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hr_news';
  $strongarm->value = array();
  $export['menu_options_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hr_news';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hr_news';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
  );
  $export['node_options_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hr_news';
  $strongarm->value = '1';
  $export['node_preview_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hr_news';
  $strongarm->value = 0;
  $export['node_submitted_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_hr_news';
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
  $export['panelizer_defaults_node_hr_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_news_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_news_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_news_es_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_news_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_news_fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_news_fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_news_pattern';
  $strongarm->value = '[node:og-group-ref:0:url:path]/article/[node:title]';
  $export['pathauto_node_hr_news_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_news_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_news_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publishcontent_hr_news';
  $strongarm->value = '1';
  $export['publishcontent_hr_news'] = $strongarm;

  return $export;
}
