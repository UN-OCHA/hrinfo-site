<?php
/**
 * @file
 * hr_assessments.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_assessments_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_assessments';
  $view->description = '';
  $view->tag = 'Assessments';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Assessments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Organization */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Participating Organizations */
  $handler->display->display_options['fields']['field_organizations2']['id'] = 'field_organizations2';
  $handler->display->display_options['fields']['field_organizations2']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations2']['field'] = 'field_organizations2';
  $handler->display->display_options['fields']['field_organizations2']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations2']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations2']['bypass_access'] = 0;
  /* Field: Indexed Node: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_bundles']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bundles']['bypass_access'] = 0;
  /* Field: Indexed Node: Status */
  $handler->display->display_options['fields']['field_asst_status']['id'] = 'field_asst_status';
  $handler->display->display_options['fields']['field_asst_status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_status']['field'] = 'field_asst_status';
  /* Field: Indexed Node: Report Date */
  $handler->display->display_options['fields']['field_asst_date']['id'] = 'field_asst_date';
  $handler->display->display_options['fields']['field_asst_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_date']['field'] = 'field_asst_date';
  $handler->display->display_options['fields']['field_asst_date']['settings'] = array(
    'format_type' => 'hr_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Assessment Report */
  $handler->display->display_options['fields']['field_asst_report']['id'] = 'field_asst_report';
  $handler->display->display_options['fields']['field_asst_report']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_report']['field'] = 'field_asst_report';
  $handler->display->display_options['fields']['field_asst_report']['label'] = 'Report';
  $handler->display->display_options['fields']['field_asst_report']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_asst_report']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_asst_report']['display'] = 'view';
  $handler->display->display_options['fields']['field_asst_report']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_asst_report']['bypass_access'] = 0;
  /* Field: Indexed Node: Assessment Questionnaire */
  $handler->display->display_options['fields']['field_asst_questionnaire']['id'] = 'field_asst_questionnaire';
  $handler->display->display_options['fields']['field_asst_questionnaire']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_questionnaire']['field'] = 'field_asst_questionnaire';
  $handler->display->display_options['fields']['field_asst_questionnaire']['label'] = 'Questionnaire';
  $handler->display->display_options['fields']['field_asst_questionnaire']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_asst_questionnaire']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_asst_questionnaire']['display'] = 'view';
  $handler->display->display_options['fields']['field_asst_questionnaire']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_asst_questionnaire']['bypass_access'] = 0;
  /* Field: Indexed Node: Assessment Data */
  $handler->display->display_options['fields']['field_asst_data']['id'] = 'field_asst_data';
  $handler->display->display_options['fields']['field_asst_data']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_data']['field'] = 'field_asst_data';
  $handler->display->display_options['fields']['field_asst_data']['label'] = 'Data';
  $handler->display->display_options['fields']['field_asst_data']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_asst_data']['alter']['text'] = '<strong>Report</strong>: [field_asst_report]<br />
<strong>Questionnaire</strong>: [field_asst_questionnaire]<br />
<strong>Data</strong>: [field_asst_data]';
  $handler->display->display_options['fields']['field_asst_data']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_asst_data']['display'] = 'view';
  $handler->display->display_options['fields']['field_asst_data']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_asst_data']['bypass_access'] = 0;
  /* Sort criterion: Report Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_asst_date_value']['id'] = 'field_asst_date_value';
  $handler->display->display_options['sorts']['field_asst_date_value']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_asst_date_value']['field'] = 'field_asst_date_value';
  $handler->display->display_options['sorts']['field_asst_date_value']['order'] = 'DESC';
  /* Contextual filter: Indexed Node: Space(s) */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_assessment' => 'hr_assessment',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Assessments';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'master');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/assessments';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/assessments/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_bundles' => 'field_bundles',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_email' => 'field_email',
    'field_job_title' => 'field_job_title',
    'field_organizations' => 'field_organizations',
    'field_location' => 'field_location',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_bundles' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organizations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/assessments/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'csv');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'assessments.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Indexed Node: Assessment Data */
  $handler->display->display_options['relationships']['field_asst_data']['id'] = 'field_asst_data';
  $handler->display->display_options['relationships']['field_asst_data']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['relationships']['field_asst_data']['field'] = 'field_asst_data';
  /* Relationship: Indexed Node: Assessment Questionnaire */
  $handler->display->display_options['relationships']['field_asst_questionnaire']['id'] = 'field_asst_questionnaire';
  $handler->display->display_options['relationships']['field_asst_questionnaire']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['relationships']['field_asst_questionnaire']['field'] = 'field_asst_questionnaire';
  /* Relationship: Indexed Node: Assessment Report */
  $handler->display->display_options['relationships']['field_asst_report']['id'] = 'field_asst_report';
  $handler->display->display_options['relationships']['field_asst_report']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['relationships']['field_asst_report']['field'] = 'field_asst_report';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['label'] = 'Location';
  $handler->display->display_options['fields']['field_locations']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Other location */
  $handler->display->display_options['fields']['field_asst_other_location']['id'] = 'field_asst_other_location';
  $handler->display->display_options['fields']['field_asst_other_location']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_other_location']['field'] = 'field_asst_other_location';
  /* Field: Indexed Node: Organization */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = 'Leading Organizations';
  $handler->display->display_options['fields']['field_organizations']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Participating Organizations */
  $handler->display->display_options['fields']['field_organizations2']['id'] = 'field_organizations2';
  $handler->display->display_options['fields']['field_organizations2']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations2']['field'] = 'field_organizations2';
  $handler->display->display_options['fields']['field_organizations2']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations2']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations2']['bypass_access'] = 0;
  /* Field: Indexed Node: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_bundles']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_bundles']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bundles']['bypass_access'] = 0;
  /* Field: Report Date: Start date (indexed) */
  $handler->display->display_options['fields']['field_asst_date_value']['id'] = 'field_asst_date_value';
  $handler->display->display_options['fields']['field_asst_date_value']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_date_value']['field'] = 'field_asst_date_value';
  $handler->display->display_options['fields']['field_asst_date_value']['label'] = 'Start date';
  $handler->display->display_options['fields']['field_asst_date_value']['date_format'] = 'hr_1';
  $handler->display->display_options['fields']['field_asst_date_value']['link_to_entity'] = 0;
  /* Field: Report Date: End date (indexed) */
  $handler->display->display_options['fields']['field_asst_date_value2']['id'] = 'field_asst_date_value2';
  $handler->display->display_options['fields']['field_asst_date_value2']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_date_value2']['field'] = 'field_asst_date_value2';
  $handler->display->display_options['fields']['field_asst_date_value2']['label'] = 'End date';
  $handler->display->display_options['fields']['field_asst_date_value2']['date_format'] = 'hr_1';
  $handler->display->display_options['fields']['field_asst_date_value2']['link_to_entity'] = 0;
  /* Field: Indexed Node: Status */
  $handler->display->display_options['fields']['field_asst_status']['id'] = 'field_asst_status';
  $handler->display->display_options['fields']['field_asst_status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_status']['field'] = 'field_asst_status';
  /* Field: Indexed Node: Collection Method */
  $handler->display->display_options['fields']['field_asst_collection_method']['id'] = 'field_asst_collection_method';
  $handler->display->display_options['fields']['field_asst_collection_method']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_collection_method']['field'] = 'field_asst_collection_method';
  $handler->display->display_options['fields']['field_asst_collection_method']['delta_offset'] = '0';
  /* Field: Indexed Node: Frequency */
  $handler->display->display_options['fields']['field_asst_freq']['id'] = 'field_asst_freq';
  $handler->display->display_options['fields']['field_asst_freq']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_freq']['field'] = 'field_asst_freq';
  /* Field: Indexed Node: Key findings */
  $handler->display->display_options['fields']['field_asst_key_findings']['id'] = 'field_asst_key_findings';
  $handler->display->display_options['fields']['field_asst_key_findings']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_key_findings']['field'] = 'field_asst_key_findings';
  /* Field: Indexed Node: Methodology */
  $handler->display->display_options['fields']['field_asst_methodology']['id'] = 'field_asst_methodology';
  $handler->display->display_options['fields']['field_asst_methodology']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_methodology']['field'] = 'field_asst_methodology';
  /* Field: Indexed Node: Sample size */
  $handler->display->display_options['fields']['field_asst_sample_size']['id'] = 'field_asst_sample_size';
  $handler->display->display_options['fields']['field_asst_sample_size']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_sample_size']['field'] = 'field_asst_sample_size';
  /* Field: Indexed Node: Level of Representation */
  $handler->display->display_options['fields']['field_geographic_level']['id'] = 'field_geographic_level';
  $handler->display->display_options['fields']['field_geographic_level']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_geographic_level']['field'] = 'field_geographic_level';
  $handler->display->display_options['fields']['field_geographic_level']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_geographic_level']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_geographic_level']['bypass_access'] = 0;
  /* Field: Indexed Node: Subject/Objective */
  $handler->display->display_options['fields']['field_asst_subject']['id'] = 'field_asst_subject';
  $handler->display->display_options['fields']['field_asst_subject']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_subject']['field'] = 'field_asst_subject';
  /* Field: Indexed Node: Population Types */
  $handler->display->display_options['fields']['field_population_types']['id'] = 'field_population_types';
  $handler->display->display_options['fields']['field_population_types']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_population_types']['field'] = 'field_population_types';
  $handler->display->display_options['fields']['field_population_types']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_population_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_population_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_population_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Unit of Measurement */
  $handler->display->display_options['fields']['field_asst_unit']['id'] = 'field_asst_unit';
  $handler->display->display_options['fields']['field_asst_unit']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_asst_unit']['field'] = 'field_asst_unit';
  $handler->display->display_options['fields']['field_asst_unit']['delta_offset'] = '0';
  /* Field: Field collection item: Accessibility */
  $handler->display->display_options['fields']['field_asst_accessibility_2']['id'] = 'field_asst_accessibility_2';
  $handler->display->display_options['fields']['field_asst_accessibility_2']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_accessibility_2']['field'] = 'field_asst_accessibility';
  $handler->display->display_options['fields']['field_asst_accessibility_2']['relationship'] = 'field_asst_report';
  $handler->display->display_options['fields']['field_asst_accessibility_2']['label'] = 'Report Accessibility';
  /* Field: Field collection item: File */
  $handler->display->display_options['fields']['field_asst_file_2']['id'] = 'field_asst_file_2';
  $handler->display->display_options['fields']['field_asst_file_2']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_file_2']['field'] = 'field_asst_file';
  $handler->display->display_options['fields']['field_asst_file_2']['relationship'] = 'field_asst_report';
  $handler->display->display_options['fields']['field_asst_file_2']['label'] = 'Report File';
  $handler->display->display_options['fields']['field_asst_file_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_asst_file_2']['type'] = 'file_url_plain';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['field_asst_url_2']['id'] = 'field_asst_url_2';
  $handler->display->display_options['fields']['field_asst_url_2']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_url_2']['field'] = 'field_asst_url';
  $handler->display->display_options['fields']['field_asst_url_2']['relationship'] = 'field_asst_report';
  $handler->display->display_options['fields']['field_asst_url_2']['label'] = 'Report URL';
  $handler->display->display_options['fields']['field_asst_url_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_asst_url_2']['type'] = 'link_absolute';
  /* Field: Field collection item: Instructions */
  $handler->display->display_options['fields']['field_asst_instructions_2']['id'] = 'field_asst_instructions_2';
  $handler->display->display_options['fields']['field_asst_instructions_2']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_instructions_2']['field'] = 'field_asst_instructions';
  $handler->display->display_options['fields']['field_asst_instructions_2']['relationship'] = 'field_asst_report';
  $handler->display->display_options['fields']['field_asst_instructions_2']['label'] = 'Report Instructions';
  /* Field: Field collection item: Accessibility */
  $handler->display->display_options['fields']['field_asst_accessibility_1']['id'] = 'field_asst_accessibility_1';
  $handler->display->display_options['fields']['field_asst_accessibility_1']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_accessibility_1']['field'] = 'field_asst_accessibility';
  $handler->display->display_options['fields']['field_asst_accessibility_1']['relationship'] = 'field_asst_questionnaire';
  $handler->display->display_options['fields']['field_asst_accessibility_1']['label'] = 'Questionnaire Accessibility';
  /* Field: Field collection item: File */
  $handler->display->display_options['fields']['field_asst_file_1']['id'] = 'field_asst_file_1';
  $handler->display->display_options['fields']['field_asst_file_1']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_file_1']['field'] = 'field_asst_file';
  $handler->display->display_options['fields']['field_asst_file_1']['relationship'] = 'field_asst_questionnaire';
  $handler->display->display_options['fields']['field_asst_file_1']['label'] = 'Questionnaire File';
  $handler->display->display_options['fields']['field_asst_file_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_asst_file_1']['type'] = 'file_url_plain';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['field_asst_url_1']['id'] = 'field_asst_url_1';
  $handler->display->display_options['fields']['field_asst_url_1']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_url_1']['field'] = 'field_asst_url';
  $handler->display->display_options['fields']['field_asst_url_1']['relationship'] = 'field_asst_questionnaire';
  $handler->display->display_options['fields']['field_asst_url_1']['label'] = 'Questionnaire URL';
  $handler->display->display_options['fields']['field_asst_url_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_asst_url_1']['type'] = 'link_absolute';
  /* Field: Field collection item: Instructions */
  $handler->display->display_options['fields']['field_asst_instructions_1']['id'] = 'field_asst_instructions_1';
  $handler->display->display_options['fields']['field_asst_instructions_1']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_instructions_1']['field'] = 'field_asst_instructions';
  $handler->display->display_options['fields']['field_asst_instructions_1']['relationship'] = 'field_asst_questionnaire';
  $handler->display->display_options['fields']['field_asst_instructions_1']['label'] = 'Questionnaire Instructions';
  /* Field: Field collection item: Accessibility */
  $handler->display->display_options['fields']['field_asst_accessibility']['id'] = 'field_asst_accessibility';
  $handler->display->display_options['fields']['field_asst_accessibility']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_accessibility']['field'] = 'field_asst_accessibility';
  $handler->display->display_options['fields']['field_asst_accessibility']['relationship'] = 'field_asst_data';
  /* Field: Field collection item: File */
  $handler->display->display_options['fields']['field_asst_file']['id'] = 'field_asst_file';
  $handler->display->display_options['fields']['field_asst_file']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_file']['field'] = 'field_asst_file';
  $handler->display->display_options['fields']['field_asst_file']['relationship'] = 'field_asst_data';
  $handler->display->display_options['fields']['field_asst_file']['label'] = 'Data File';
  $handler->display->display_options['fields']['field_asst_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_asst_file']['type'] = 'file_url_plain';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['field_asst_url']['id'] = 'field_asst_url';
  $handler->display->display_options['fields']['field_asst_url']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_url']['field'] = 'field_asst_url';
  $handler->display->display_options['fields']['field_asst_url']['relationship'] = 'field_asst_data';
  $handler->display->display_options['fields']['field_asst_url']['label'] = 'Data URL';
  $handler->display->display_options['fields']['field_asst_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_asst_url']['type'] = 'link_absolute';
  /* Field: Field collection item: Instructions */
  $handler->display->display_options['fields']['field_asst_instructions']['id'] = 'field_asst_instructions';
  $handler->display->display_options['fields']['field_asst_instructions']['table'] = 'entity_field_collection_item';
  $handler->display->display_options['fields']['field_asst_instructions']['field'] = 'field_asst_instructions';
  $handler->display->display_options['fields']['field_asst_instructions']['relationship'] = 'field_asst_data';
  $handler->display->display_options['fields']['field_asst_instructions']['label'] = 'Data Instructions';
  $handler->display->display_options['path'] = 'node/%/assessments/csv';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'list' => 'list',
    'table' => 'table',
    'default' => 0,
    'map' => 0,
  );
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Map data */
  $handler = $view->new_display('openlayers', 'Map data', 'map_data');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'field_locations_field_geofield_lat',
    'other_lon' => 'field_locations_field_geofield_lon',
    'wkt' => 'field_locations_field_geofield_lat',
    'projection' => 'EPSG:4326',
    'other_top' => 'field_locations_field_geofield_lat',
    'other_right' => 'field_locations_field_geofield_lat',
    'other_bottom' => 'field_locations_field_geofield_lat',
    'other_left' => 'field_locations_field_geofield_lat',
    'name_field' => 'title',
    'description_field' => 'title',
    'style_field' => '',
  );
  $handler->display->display_options['style_options']['attributes'] = array(
    'display' => array(
      'title' => 'title',
      'name' => 'name',
      'field_locations_field_geofield_lat' => 0,
      'field_locations_field_geofield_lon' => 0,
      'description' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Locations » Geofield: Latitude (indexed) */
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['id'] = 'field_locations_field_geofield_lat';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['field'] = 'field_locations_field_geofield_lat';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['label'] = '';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['precision'] = '0';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['separator'] = '';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['link_to_entity'] = 0;
  /* Field: Locations » Geofield: Longitude (indexed) */
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['id'] = 'field_locations_field_geofield_lon';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['field'] = 'field_locations_field_geofield_lon';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['label'] = '';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['precision'] = '0';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['separator'] = '';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['link_to_entity'] = 0;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Space(s) */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_assessment' => 'hr_assessment',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Assessments';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );

  /* Display: Map */
  $handler = $view->new_display('page', 'Map', 'map');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'hr_assessments';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/assessments/map';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'global_master');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'assessments';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'global_list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'assessments/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'global_table');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_bundles' => 'field_bundles',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_email' => 'field_email',
    'field_job_title' => 'field_job_title',
    'field_organizations' => 'field_organizations',
    'field_location' => 'field_location',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_bundles' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organizations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'assessments/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['hr_assessments'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('There are no results'),
    t('Title'),
    t('Locations'),
    t('Organization'),
    t('Participating Organizations'),
    t('Clusters/Sectors'),
    t('Status'),
    t('Report Date'),
    t('Report'),
    t('Questionnaire'),
    t('Data'),
    t('<strong>Report</strong>: [field_asst_report]<br />
<strong>Questionnaire</strong>: [field_asst_questionnaire]<br />
<strong>Data</strong>: [field_asst_data]'),
    t('All'),
    t('Search Assessments'),
    t('List'),
    t('Table'),
    t('CSV'),
    t('Assessment Data'),
    t('Assessment Questionnaire'),
    t('Assessment Report'),
    t('Location'),
    t('Other location'),
    t('Leading Organizations'),
    t('Start date'),
    t('End date'),
    t('Collection Method'),
    t('Frequency'),
    t('Key findings'),
    t('Methodology'),
    t('Sample size'),
    t('Level of Representation'),
    t('Subject/Objective'),
    t('Population Types'),
    t('Unit of Measurement'),
    t('Report Accessibility'),
    t('Report File'),
    t('Report URL'),
    t('Report Instructions'),
    t('Questionnaire Accessibility'),
    t('Questionnaire File'),
    t('Questionnaire URL'),
    t('Questionnaire Instructions'),
    t('Accessibility'),
    t('Data File'),
    t('Data URL'),
    t('Data Instructions'),
    t('Map data'),
    t('.'),
    t('Map'),
  );
  $export['hr_assessments'] = $view;

  $view = new view();
  $view->name = 'hr_assessments_panes';
  $view->description = '';
  $view->tag = 'Assessments';
  $view->base_table = 'node';
  $view->human_name = 'Assessments Panes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Space(s) (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_document' => 'hr_document',
  );

  /* Display: Custom */
  $handler = $view->new_display('panel_pane', 'Custom', 'list');
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'search';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_assessment' => 'hr_assessment',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Space(s) (og_group_ref) */
  $handler->display->display_options['filters']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['og_group_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator_id'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['label'] = 'Space';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['description'] = 'Please select a space OR a cluster, but NOT BOTH. Selecting both a space and a cluster will not work.';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['identifier'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );
  /* Filter criterion: Content: Clusters/Sectors (field_bundles) (reference filter) */
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['id'] = 'field_bundles_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['table'] = 'og_membership';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['field'] = 'field_bundles_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['expose']['operator_id'] = 'field_bundles_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['expose']['label'] = 'Clusters/Sectors';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['expose']['description'] = 'Please select a space OR a cluster, but NOT BOTH. Selecting both a space and a cluster will not work.';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['expose']['operator'] = 'field_bundles_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['expose']['identifier'] = 'field_bundles_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    200153887 => 0,
    235660466 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_bundles_target_id_entityreference_filter']['reference_display'] = 'hr_bundles:entityreference_1';
  /* Filter criterion: Content: Organization (field_organizations) (reference filter) */
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['id'] = 'field_organizations_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['table'] = 'field_data_field_organizations';
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['field'] = 'field_organizations_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['expose']['operator_id'] = 'field_organizations_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['expose']['label'] = 'Leading Organizations';
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['expose']['operator'] = 'field_organizations_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['expose']['identifier'] = 'field_organizations_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );
  $handler->display->display_options['filters']['field_organizations_target_id_entityreference_filter']['reference_display'] = 'hr_organizations:entityreference_1';
  /* Filter criterion: Content: Participating Organizations (field_organizations2) (reference filter) */
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['id'] = 'field_organizations2_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['table'] = 'field_data_field_organizations2';
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['field'] = 'field_organizations2_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['expose']['operator_id'] = 'field_organizations2_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['expose']['label'] = 'Participating Organizations';
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['expose']['operator'] = 'field_organizations2_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['expose']['identifier'] = 'field_organizations2_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );
  $handler->display->display_options['filters']['field_organizations2_target_id_entityreference_filter']['reference_display'] = 'hr_organizations:entityreference_1';
  /* Filter criterion: Content: Disasters (field_disasters) */
  $handler->display->display_options['filters']['field_disasters_target_id']['id'] = 'field_disasters_target_id';
  $handler->display->display_options['filters']['field_disasters_target_id']['table'] = 'field_data_field_disasters';
  $handler->display->display_options['filters']['field_disasters_target_id']['field'] = 'field_disasters_target_id';
  $handler->display->display_options['filters']['field_disasters_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_disasters_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_disasters_target_id']['expose']['operator_id'] = 'field_disasters_target_id_op';
  $handler->display->display_options['filters']['field_disasters_target_id']['expose']['label'] = 'Disasters';
  $handler->display->display_options['filters']['field_disasters_target_id']['expose']['operator'] = 'field_disasters_target_id_op';
  $handler->display->display_options['filters']['field_disasters_target_id']['expose']['identifier'] = 'field_disasters_target_id';
  $handler->display->display_options['filters']['field_disasters_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );
  /* Filter criterion: Content: Locations (field_locations) */
  $handler->display->display_options['filters']['field_locations_target_id']['id'] = 'field_locations_target_id';
  $handler->display->display_options['filters']['field_locations_target_id']['table'] = 'field_data_field_locations';
  $handler->display->display_options['filters']['field_locations_target_id']['field'] = 'field_locations_target_id';
  $handler->display->display_options['filters']['field_locations_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_locations_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_locations_target_id']['expose']['operator_id'] = 'field_locations_target_id_op';
  $handler->display->display_options['filters']['field_locations_target_id']['expose']['label'] = 'Locations';
  $handler->display->display_options['filters']['field_locations_target_id']['expose']['operator'] = 'field_locations_target_id_op';
  $handler->display->display_options['filters']['field_locations_target_id']['expose']['identifier'] = 'field_locations_target_id';
  $handler->display->display_options['filters']['field_locations_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );
  /* Filter criterion: Content: Themes (field_themes) (reference filter) */
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['id'] = 'field_themes_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['table'] = 'field_data_field_themes';
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['field'] = 'field_themes_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['expose']['operator_id'] = 'field_themes_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['expose']['label'] = 'Themes';
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['expose']['operator'] = 'field_themes_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['expose']['identifier'] = 'field_themes_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    188284353 => 0,
    235660466 => 0,
    229782242 => 0,
    147444660 => 0,
  );
  $handler->display->display_options['filters']['field_themes_target_id_entityreference_filter']['reference_display'] = 'hr_themes:entityreference_1';
  $handler->display->display_options['pane_title'] = 'Assessments';
  $handler->display->display_options['pane_category']['name'] = 'Assessments';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'og_group_ref_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Group',
    ),
  );

  /* Display: Per space */
  $handler = $view->new_display('panel_pane', 'Per space', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Assessments';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'search';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Space(s) (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Clusters/Sectors (field_bundles) */
  $handler->display->display_options['arguments']['field_bundles_target_id']['id'] = 'field_bundles_target_id';
  $handler->display->display_options['arguments']['field_bundles_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['field_bundles_target_id']['field'] = 'field_bundles_target_id';
  $handler->display->display_options['arguments']['field_bundles_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_bundles_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_bundles_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_bundles_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_bundles_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_assessment' => 'hr_assessment',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['pane_title'] = 'Assessments from context';
  $handler->display->display_options['pane_category']['name'] = 'Assessments';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_bundles_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Clusters/Sectors (field_bundles)',
    ),
    'og_group_ref_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Group',
    ),
  );
  $translatables['hr_assessments_panes'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Custom'),
    t('Space'),
    t('Please select a space OR a cluster, but NOT BOTH. Selecting both a space and a cluster will not work.'),
    t('Clusters/Sectors'),
    t('Leading Organizations'),
    t('Participating Organizations'),
    t('Disasters'),
    t('Locations'),
    t('Themes'),
    t('Assessments'),
    t('Per space'),
    t('Latest Assessments'),
    t('Assessments from context'),
  );
  $export['hr_assessments_panes'] = $view;

  $view = new view();
  $view->name = 'hr_geographic_levels';
  $view->description = '';
  $view->tag = 'disasters';
  $view->base_table = 'node';
  $view->human_name = 'Geographic Levels';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
  $handler->display->display_options['cache']['results_min_lifespan'] = '-1';
  $handler->display->display_options['cache']['results_max_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_min_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_max_lifespan'] = '21600';
  $handler->display->display_options['cache']['keys'] = array(
    'comment' => array(
      'changed' => 0,
    ),
    'node' => array(
      'hr_geographic_level' => 'hr_geographic_level',
      'acc_application' => 0,
      'acc_incident' => 0,
      'hr_assessment' => 0,
      'hr_news' => 0,
      'hr_bundle' => 0,
      'hr_contact' => 0,
      'hr_dataset' => 0,
      'hr_disaster' => 0,
      'hr_discussion' => 0,
      'hr_document' => 0,
      'hr_event' => 0,
      'hr_funding' => 0,
      'hr_funding_method' => 0,
      'hr_sector' => 0,
      'hr_indicator' => 0,
      'hr_infographic' => 0,
      'hr_office' => 0,
      'hr_operation' => 0,
      'hr_page' => 0,
      'hr_space' => 0,
      'hr_toolbox_category' => 0,
      'hr_toolbox_item' => 0,
      'webform' => 0,
    ),
    'node_only' => array(
      'node_changed' => 0,
    ),
    'og' => array(
      'current' => 0,
      'user' => 0,
    ),
  );
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Space(s) (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_geographic_level' => 'hr_geographic_level',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['hr_geographic_levels'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('Entity Reference'),
  );
  $export['hr_geographic_levels'] = $view;

  return $export;
}
