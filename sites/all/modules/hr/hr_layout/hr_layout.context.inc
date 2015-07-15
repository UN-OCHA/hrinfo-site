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
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'hr_events_calendar:master' => 'hr_events_calendar:master',
        'hr_events_calendar:day' => 'hr_events_calendar:day',
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
          'module' => 'views',
          'delta' => '-exp-hr_search-space',
          'region' => 'branding',
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
      'values' => array(
        'hr_operation' => 'hr_operation',
        'hr_sector' => 'hr_sector',
        'hr_space' => 'hr_space',
        'hr_bundle' => 'hr_bundle',
      ),
      'options' => array(
        'node_form' => '0',
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
        'hr_operations-operations_status' => array(
          'module' => 'hr_operations',
          'delta' => 'operations_status',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'hr_layout-hr_layout_share_links' => array(
          'module' => 'hr_layout',
          'delta' => 'hr_layout_share_links',
          'region' => 'sidebar_first',
          'weight' => '0',
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
        '~hr_contacts_space' => '~hr_contacts_space',
        '~hr_contacts_space_list' => '~hr_contacts_space_list',
        '~hr_contacts_space_map' => '~hr_contacts_space_map',
        '~hr_contacts_space_graphs' => '~hr_contacts_space_graphs',
        '~hr_documents_space' => '~hr_documents_space',
        '~hr_documents_space_table' => '~hr_documents_space_table',
        '~hr_news_space' => '~hr_news_space',
        '~hr_events_space' => '~hr_events_space',
        '~hr_events_space_list' => '~hr_events_space_list',
        '~hr_data' => '~hr_data',
        '~hr_datasets_space' => '~hr_datasets_space',
        '~hr_datasets_space_table' => '~hr_datasets_space_table',
        '~hr_indicators' => '~hr_indicators',
        '~hr_search_space' => '~hr_search_space',
        '~hr_infographics_space' => '~hr_infographics_space',
        '~hr_infographics_space_table' => '~hr_infographics_space_table',
        '~hr_assessments_space' => '~hr_assessments_space',
        '~hr_assessments_space_table' => '~hr_assessments_space_table',
        '~hr_assessments_space_map' => '~hr_assessments_space_map',
        '~acc_incidents' => '~acc_incidents',
        '~acc_incidents_graphs' => '~acc_incidents_graphs',
        '~acc_incidents_map' => '~acc_incidents_map',
        '~acc_incidents_table' => '~acc_incidents_table',
        '~acc_applications' => '~acc_applications',
        '~acc_applications_imp_reports' => '~acc_applications_imp_reports',
        '~acc_applications_map' => '~acc_applications_map',
        '~acc_applications_reports' => '~acc_applications_reports',
        '~acc_applications_table' => '~acc_applications_table',
      ),
    ),
    'context_og_condition_group_type' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 0,
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
        'views--exp-hr_search-space' => array(
          'module' => 'views',
          'delta' => '-exp-hr_search-space',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'og_menu-og_single_menu_block' => array(
          'module' => 'og_menu',
          'delta' => 'og_single_menu_block',
          'region' => 'sidebar_first',
          'weight' => '-5',
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
      'values' => array(
        '_none_' => '_none_',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-hr_search-page',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
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
        'hr_layout-hr_layout_login' => array(
          'module' => 'hr_layout',
          'delta' => 'hr_layout_login',
          'region' => 'top',
          'weight' => '-8',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'top',
          'weight' => '-7',
        ),
        'hr_help-hr_help' => array(
          'module' => 'hr_help',
          'delta' => 'hr_help',
          'region' => 'top',
          'weight' => '-5',
        ),
        'locale-language' => array(	
          'module' => 'locale',	
          'delta' => 'language',	
          'region' => 'top',
          'weight' => 10,
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
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hr_layout-hr_layout_create_links' => array(
          'module' => 'hr_layout',
          'delta' => 'hr_layout_create_links',
          'region' => 'top',
          'weight' => '0',
        ),
        'hr_layout-hr_layout_checkin' => array(
          'module' => 'hr_layout',
          'delta' => 'hr_layout_checkin',
          'region' => 'top',
          'weight' => '2',
        ),
        'og_menu_single-menu' => array(
          'module' => 'og_menu_single',
          'delta' => 'menu',
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
