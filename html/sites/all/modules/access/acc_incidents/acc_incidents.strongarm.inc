<?php

/**
 * @file
 * acc_incidents.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function acc_incidents_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_acc_incident';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_acc_incident';
  $strongarm->value = '[node:field_acc_date] [node:field_acc_type] [node:field_locations]';
  $export['auto_entitylabel_pattern_node_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_acc_incident';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__acc_incident';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'path' => array(
          'weight' => '14',
        ),
        'redirect' => array(
          'weight' => '15',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(),
  );
  $export['field_bundle_settings_node__acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_acc_incident';
  $strongarm->value = '0';
  $export['language_content_type_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_acc_incident';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_acc_incident';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_acc_incident';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_acc_incident';
  $strongarm->value = '1';
  $export['node_preview_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_acc_incident';
  $strongarm->value = 0;
  $export['node_submitted_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_acc_incident';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'default' => array(
        'choice' => 0,
        'default' => 1,
        'status' => 1,
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
      'rss' => array(
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
      'token' => array(
        'choice' => 0,
        'default' => 0,
        'status' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:acc_incident_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:27:"panelizer_node:acc_incident";s:23:"allowed_layout_settings";a:33:{s:8:"flexible";b:1;s:14:"twocol_stacked";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:13:"twocol_bricks";b:1;s:6:"onecol";b:1;s:17:"threecol_33_34_33";b:1;s:6:"twocol";b:1;s:17:"threecol_25_50_25";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:14:"radix_bartlett";b:1;s:15:"radix_sanderson";b:1;s:12:"radix_whelan";b:1;s:13:"radix_brenham";b:1;s:20:"radix_bryant_flipped";b:1;s:21:"radix_brenham_flipped";b:1;s:12:"radix_phelan";b:1;s:11:"radix_brown";b:1;s:13:"radix_moscone";b:1;s:22:"radix_bartlett_flipped";b:1;s:14:"radix_mccoppin";b:1;s:18:"radix_burr_flipped";b:1;s:11:"radix_sutro";b:1;s:12:"radix_taylor";b:1;s:12:"radix_harris";b:1;s:11:"radix_geary";b:1;s:12:"radix_boxton";b:1;s:21:"radix_hewston_flipped";b:1;s:21:"radix_moscone_flipped";b:1;s:20:"radix_taylor_flipped";b:1;s:10:"radix_burr";b:1;s:12:"radix_bryant";b:1;s:23:"radix_sanderson_flipped";b:1;s:13:"radix_hewston";b:1;}s:10:"form_state";N;}';
  $export['panelizer_node:acc_incident_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:acc_incident_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:acc_incident_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:acc_incident_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:acc_incident_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:acc_incident_default';
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
  $export['panelizer_node:acc_incident_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_acc_incident_pattern';
  $strongarm->value = '[node:og-group-ref:0:url:path]/access-incident/[node:title]';
  $export['pathauto_node_acc_incident_pattern'] = $strongarm;

  return $export;
}
