<?php

/**
 * @file
 * hr_layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_nodes';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '0',
      ),
      'values' => array(
        'hr_assessment' => 'hr_assessment',
        'hr_contact' => 'hr_contact',
        'hr_dataset' => 'hr_dataset',
        'hr_discussion' => 'hr_discussion',
        'hr_document' => 'hr_document',
        'hr_event' => 'hr_event',
        'hr_indicator' => 'hr_indicator',
        'hr_infographic' => 'hr_infographic',
        'hr_news' => 'hr_news',
        'hr_office' => 'hr_office',
        'hr_toolbox_item' => 'hr_toolbox_item',
      ),
    ),
    'views' => array(
      'values' => array(
        'hr_events_calendar:day' => 'hr_events_calendar:day',
        'hr_events_calendar:master' => 'hr_events_calendar:master',
        'hr_events_calendar:month' => 'hr_events_calendar:month',
        'hr_events_calendar:week' => 'hr_events_calendar:week',
        'hr_events_calendar:year' => 'hr_events_calendar:year',
        'hr_offices:page' => 'hr_offices:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_search-space' => array(
          'delta' => '-exp-hr_search-space',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'hr_space_menu' => 'hr_space_menu',
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['hr_nodes'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_space_links';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '0',
      ),
      'values' => array(
        'hr_bundle' => 'hr_bundle',
        'hr_operation' => 'hr_operation',
        'hr_sector' => 'hr_sector',
        'hr_space' => 'hr_space',
      ),
    ),
    'path' => array(
      'values' => array(
        '~applications/kiosk' => '~applications/kiosk',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hr_layout-hr_layout_share_links' => array(
          'delta' => 'hr_layout_share_links',
          'module' => 'hr_layout',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'hr_operations-operations_status' => array(
          'delta' => 'operations_status',
          'module' => 'hr_operations',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['hr_space_links'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_space_menu';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~acc_applications' => '~acc_applications',
        '~acc_applications_imp_reports' => '~acc_applications_imp_reports',
        '~acc_applications_map' => '~acc_applications_map',
        '~acc_applications_reports' => '~acc_applications_reports',
        '~acc_applications_table' => '~acc_applications_table',
        '~acc_incidents' => '~acc_incidents',
        '~acc_incidents_graphs' => '~acc_incidents_graphs',
        '~acc_incidents_map' => '~acc_incidents_map',
        '~acc_incidents_table' => '~acc_incidents_table',
        '~hr_assessments_space' => '~hr_assessments_space',
        '~hr_assessments_space_map' => '~hr_assessments_space_map',
        '~hr_assessments_space_table' => '~hr_assessments_space_table',
        '~hr_data' => '~hr_data',
        '~hr_datasets_hdx' => '~hr_datasets_hdx',
        '~hr_datasets_space' => '~hr_datasets_space',
        '~hr_datasets_space_table' => '~hr_datasets_space_table',
        '~hr_documents_space' => '~hr_documents_space',
        '~hr_documents_space_table' => '~hr_documents_space_table',
        '~hr_events_space' => '~hr_events_space',
        '~hr_events_space_list' => '~hr_events_space_list',
        '~hr_indicators' => '~hr_indicators',
        '~hr_infographics_space' => '~hr_infographics_space',
        '~hr_infographics_space_table' => '~hr_infographics_space_table',
        '~hr_jobs' => '~hr_jobs',
        '~hr_news_space' => '~hr_news_space',
        '~hr_search_space' => '~hr_search_space',
      ),
    ),
    'context_og_condition_group_type' => array(
      'options' => array(
        'node_form' => 0,
      ),
      'values' => array(
        '_any_' => '_any_',
      ),
    ),
    'node' => array(
      'options' => array(
        'node_form' => '0',
      ),
      'values' => array(
        'acc_application' => 'acc_application',
        'acc_incident' => 'acc_incident',
        'hr_assessment' => 'hr_assessment',
        'hr_bundle' => 'hr_bundle',
        'hr_disaster' => 'hr_disaster',
        'hr_document' => 'hr_document',
        'hr_event' => 'hr_event',
        'hr_indicator' => 'hr_indicator',
        'hr_infographic' => 'hr_infographic',
        'hr_news' => 'hr_news',
        'hr_office' => 'hr_office',
        'hr_operation' => 'hr_operation',
        'hr_page' => 'hr_page',
        'hr_sector' => 'hr_sector',
        'hr_space' => 'hr_space',
        'hr_toolbox_category' => 'hr_toolbox_category',
        'hr_toolbox_item' => 'hr_toolbox_item',
      ),
    ),
    'path' => array(
      'values' => array(
        '~j2h/contactos' => '~j2h/contactos',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_menu-og_single_menu_block' => array(
          'delta' => 'og_single_menu_block',
          'module' => 'og_menu',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'views--exp-hr_search-space' => array(
          'delta' => '-exp-hr_search-space',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['hr_space_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'outside_space';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'options' => array(
        'node_form' => 0,
      ),
      'values' => array(
        '_none_' => '_none_',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'delta' => 'main-menu',
          'module' => 'system',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'views--exp-hr_search-page' => array(
          'delta' => '-exp-hr_search-page',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['outside_space'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hr_bookmarks-hr_favorite_spaces' => array(
          'delta' => 'hr_favorite_spaces',
          'module' => 'hr_bookmarks',
          'region' => 'header_top',
          'weight' => '-5',
        ),
        'hr_help-hr_help' => array(
          'delta' => 'hr_help',
          'module' => 'hr_help',
          'region' => 'header_top',
          'weight' => '-1',
        ),
        'hr_layout-hr_layout_create_links' => array(
          'delta' => 'hr_layout_create_links',
          'module' => 'hr_layout',
          'region' => 'header_top',
          'weight' => '-3',
        ),
        'hr_layout-hr_layout_login' => array(
          'delta' => 'hr_layout_login',
          'module' => 'hr_layout',
          'region' => 'header_top',
          'weight' => '-2',
        ),
        'system-main-menu' => array(
          'delta' => 'main-menu',
          'module' => 'system',
          'region' => 'header_navigation',
          'weight' => '-10',
        ),
        'system-user-menu' => array(
          'delta' => 'user-menu',
          'module' => 'system',
          'region' => 'header_top',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'within_space';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'options' => array(
        'node_form' => 0,
      ),
      'values' => array(
        '_any_' => '_any_',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hr_layout-hr_layout_create_links' => array(
          'delta' => 'hr_layout_create_links',
          'module' => 'hr_layout',
          'region' => 'top',
          'weight' => '0',
        ),
        'hr_layout-hr_layout_horz_menu' => array(
          'delta' => 'hr_layout_horz_menu',
          'module' => 'hr_layout',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['within_space'] = $context;

  return $export;
}
