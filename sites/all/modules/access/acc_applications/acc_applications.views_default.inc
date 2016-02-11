<?php
/**
 * @file
 * acc_applications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function acc_applications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'acc_application_repots';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Access Application Repots';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Access Application By Status';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_pivot';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_acc_submission_status' => 'field_acc_submission_status',
    'field_how_many_days' => 'field_how_many_days',
    'field_sector' => 'field_sector',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_acc_submission_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_how_many_days' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_sector' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
  );
  $handler->display->display_options['style_options']['pivot_col'] = 'field_acc_submission_status';
  $handler->display->display_options['style_options']['pivot_row'] = 'field_sector';
  $handler->display->display_options['style_options']['pivot_mode_multi_values'] = '0';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_acc_application_types_target_id']['id'] = 'field_acc_application_types_target_id';
  $handler->display->display_options['relationships']['field_acc_application_types_target_id']['table'] = 'field_data_field_acc_application_types';
  $handler->display->display_options['relationships']['field_acc_application_types_target_id']['field'] = 'field_acc_application_types_target_id';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_acc_application_types_target_id';
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of reports';
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Contextual filter: Content: Space(s) (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'default';
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Restrictions on movement within country';

  /* Display: Res By Status */
  $handler = $view->new_display('block', 'Res By Status', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'pie';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
    'field_acc_submission_status' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_acc_submission_status',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of reports';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Space(s) (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Restrictions on movement within country';
  $handler->display->display_options['block_description'] = 'Res By Status';

  /* Display: XLS Res By Status */
  $handler = $view->new_display('views_data_export', 'XLS Res By Status', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of reports';
  $handler->display->display_options['path'] = 'node/%/access/applications/xls';
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );

  /* Display: Res By Org n Status */
  $handler = $view->new_display('block', 'Res By Org n Status', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Application By Org Type and Status';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_pivot';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_acc_submission_status' => 'field_acc_submission_status',
    'field_acc_submitted_by_org_type' => 'field_acc_submitted_by_org_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_submission_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_submitted_by_org_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
  );
  $handler->display->display_options['style_options']['pivot_col'] = 'field_acc_submission_status';
  $handler->display->display_options['style_options']['pivot_row'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['style_options']['pivot_mode_multi_values'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Submitted By Organization Type */
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['id'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['table'] = 'field_data_field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['field'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['label'] = 'Organization Type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'Res By Org n Status';

  /* Display: Res By District n Status */
  $handler = $view->new_display('block', 'Res By District n Status', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Application By District and Status';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_pivot';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_acc_geo_location_dest' => 'field_acc_geo_location_dest',
    'field_acc_submission_status' => 'field_acc_submission_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_geo_location_dest' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_submission_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
  );
  $handler->display->display_options['style_options']['pivot_col'] = 'field_acc_submission_status';
  $handler->display->display_options['style_options']['pivot_row'] = 'field_acc_geo_location_dest';
  $handler->display->display_options['style_options']['pivot_mode_multi_values'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Geographical Location (Destination) */
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['id'] = 'field_acc_geo_location_dest';
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['table'] = 'field_data_field_acc_geo_location_dest';
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['field'] = 'field_acc_geo_location_dest';
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['block_description'] = 'Res By District n Status';

  /* Display: Res By Sector n Status */
  $handler = $view->new_display('block', 'Res By Sector n Status', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Application By Sector And Status';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Global Cluster */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sector']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'Res By Sector n Status';

  /* Display: Res Num of days */
  $handler = $view->new_display('block', 'Res Num of days', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of days to get an answer';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_acc_submission_status' => 'field_acc_submission_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_acc_submission_status' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: AVG(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days']['id'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_how_many_days']['label'] = 'Avg number of days to get an answer';
  $handler->display->display_options['fields']['field_how_many_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: MAX(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days_1']['id'] = 'field_how_many_days_1';
  $handler->display->display_options['fields']['field_how_many_days_1']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_1']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_how_many_days_1']['label'] = 'Maximum number of days to get an answer';
  $handler->display->display_options['fields']['field_how_many_days_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: MIN(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days_2']['id'] = 'field_how_many_days_2';
  $handler->display->display_options['fields']['field_how_many_days_2']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_2']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_2']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_how_many_days_2']['label'] = 'Minimum number of days to get an answer';
  $handler->display->display_options['fields']['field_how_many_days_2']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['block_description'] = 'Res Num of days';

  /* Display: Res Avg Num Day by Org */
  $handler = $view->new_display('block', 'Res Avg Num Day by Org', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Average number of to get an answer by organization type';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_pivot';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_acc_submission_status' => 'field_acc_submission_status',
    'field_how_many_days' => 'field_how_many_days',
    'field_acc_submitted_by_org_type' => 'field_acc_submitted_by_org_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_acc_submission_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_how_many_days' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_submitted_by_org_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
  );
  $handler->display->display_options['style_options']['pivot_col'] = 'field_acc_submission_status';
  $handler->display->display_options['style_options']['pivot_row'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['style_options']['pivot_mode_multi_values'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: AVG(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days']['id'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_how_many_days']['label'] = '';
  $handler->display->display_options['fields']['field_how_many_days']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_how_many_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Submitted By Organization Type */
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['id'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['table'] = 'field_data_field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['field'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['label'] = 'Organization Type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'Res Avg Num Day by Org';

  /* Display: Res Avg Num Day by Sector */
  $handler = $view->new_display('block', 'Res Avg Num Day by Sector', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Average number of days to get an answer by sectors';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: AVG(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days']['id'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_how_many_days']['label'] = '';
  $handler->display->display_options['fields']['field_how_many_days']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_how_many_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Global Cluster */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sector']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'Res Avg Num Day by Sector';

  /* Display: Imp By Status */
  $handler = $view->new_display('block', 'Imp By Status', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Application By Status';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'pie';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
    'field_acc_submission_status' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_acc_submission_status',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of reports';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Impediments on entry into country';
  $handler->display->display_options['block_description'] = 'Imp By Status';

  /* Display: XLS Imp By Status */
  $handler = $view->new_display('views_data_export', 'XLS Imp By Status', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of reports';
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Impediments on entry into country';
  $handler->display->display_options['path'] = 'node/%/access/applications/xls';
  $handler->display->display_options['displays'] = array(
    'block_7' => 'block_7',
    'default' => 0,
    'block' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
  );

  /* Display: Imp By Org n Status */
  $handler = $view->new_display('block', 'Imp By Org n Status', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Application By Org Type and Status';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_pivot';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_acc_submission_status' => 'field_acc_submission_status',
    'field_acc_submitted_by_org_type' => 'field_acc_submitted_by_org_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_submission_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_submitted_by_org_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
  );
  $handler->display->display_options['style_options']['pivot_col'] = 'field_acc_submission_status';
  $handler->display->display_options['style_options']['pivot_row'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['style_options']['pivot_mode_multi_values'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Submitted By Organization Type */
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['id'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['table'] = 'field_data_field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['field'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['label'] = 'Organization Type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['delta_offset'] = '0';
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Impediments on entry into country';
  $handler->display->display_options['block_description'] = 'Imp By Org n Status';

  /* Display: Imp By Sector n Status */
  $handler = $view->new_display('block', 'Imp By Sector n Status', 'block_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Application By Sector And Status';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Global Cluster */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sector']['delta_offset'] = '0';
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Impediments on entry into country';
  $handler->display->display_options['block_description'] = 'Imp By Sector n Status';

  /* Display: Imp Num of days */
  $handler = $view->new_display('block', 'Imp Num of days', 'block_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of days to get an answer';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_acc_submission_status' => 'field_acc_submission_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_acc_submission_status' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: AVG(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days']['id'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_how_many_days']['label'] = 'Avg number of days to get an answer';
  $handler->display->display_options['fields']['field_how_many_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: MAX(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days_1']['id'] = 'field_how_many_days_1';
  $handler->display->display_options['fields']['field_how_many_days_1']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_1']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_how_many_days_1']['label'] = 'Maximum number of days to get an answer';
  $handler->display->display_options['fields']['field_how_many_days_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: MIN(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days_2']['id'] = 'field_how_many_days_2';
  $handler->display->display_options['fields']['field_how_many_days_2']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_2']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days_2']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_how_many_days_2']['label'] = 'Minimum number of days to get an answer';
  $handler->display->display_options['fields']['field_how_many_days_2']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Impediments on entry into country';
  $handler->display->display_options['block_description'] = 'Imp Num of days';

  /* Display: Imp Avg Num Day by Org */
  $handler = $view->new_display('block', 'Imp Avg Num Day by Org', 'block_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Average number of to get an answer by organization type';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_pivot';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_acc_submission_status' => 'field_acc_submission_status',
    'field_how_many_days' => 'field_how_many_days',
    'field_acc_submitted_by_org_type' => 'field_acc_submitted_by_org_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_acc_submission_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_how_many_days' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
    'field_acc_submitted_by_org_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
    ),
  );
  $handler->display->display_options['style_options']['pivot_col'] = 'field_acc_submission_status';
  $handler->display->display_options['style_options']['pivot_row'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['style_options']['pivot_mode_multi_values'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: AVG(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days']['id'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_how_many_days']['label'] = '';
  $handler->display->display_options['fields']['field_how_many_days']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_how_many_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Submitted By Organization Type */
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['id'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['table'] = 'field_data_field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['field'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['label'] = 'Organization Type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['delta_offset'] = '0';
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Impediments on entry into country';
  $handler->display->display_options['block_description'] = 'Imp Avg Num Day by Org';

  /* Display: Imp Avg Num Day by Sector */
  $handler = $view->new_display('block', 'Imp Avg Num Day by Sector', 'block_13');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Average number of days to get an answer by sectors';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'field_data_field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['settings'] = array(
    'link' => 0,
  );
  /* Field: AVG(Content: How many days to get an answer?) */
  $handler->display->display_options['fields']['field_how_many_days']['id'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['table'] = 'field_data_field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_how_many_days']['label'] = '';
  $handler->display->display_options['fields']['field_how_many_days']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_how_many_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Global Cluster */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sector']['delta_offset'] = '0';
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
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'Impediments on entry into country';
  $handler->display->display_options['block_description'] = 'Imp Avg Num Day by Sector';
  $translatables['acc_application_repots'] = array(
    t('Master'),
    t('Access Application By Status'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Taxonomy term entity referenced from field_acc_application_types'),
    t('Parent'),
    t('Number of reports'),
    t('Submission Status'),
    t('All'),
    t('Res By Status'),
    t('XLS Res By Status'),
    t('Res By Org n Status'),
    t('Access Application By Org Type and Status'),
    t('Organization Type'),
    t('Res By District n Status'),
    t('Access Application By District and Status'),
    t('Geographical Location (Destination)'),
    t('Res By Sector n Status'),
    t('Access Application By Sector And Status'),
    t('Global Cluster'),
    t('Res Num of days'),
    t('Number of days to get an answer'),
    t('Avg number of days to get an answer'),
    t('Maximum number of days to get an answer'),
    t('Minimum number of days to get an answer'),
    t('Res Avg Num Day by Org'),
    t('Average number of to get an answer by organization type'),
    t('Res Avg Num Day by Sector'),
    t('Average number of days to get an answer by sectors'),
    t('Imp By Status'),
    t('XLS Imp By Status'),
    t('Imp By Org n Status'),
    t('Imp By Sector n Status'),
    t('Imp Num of days'),
    t('Imp Avg Num Day by Org'),
    t('Imp Avg Num Day by Sector'),
  );
  $export['acc_application_repots'] = $view;

  $view = new view();
  $view->name = 'acc_applications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_acc_search';
  $view->human_name = 'Access Applications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'create acc_application content';
  $handler->display->display_options['access']['group_id_arg'] = '1';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Contextual filter: Indexed Node: Space(s) */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    188284353 => 0,
    235660466 => 0,
    229782242 => 0,
    147444660 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'acc_application' => 'acc_application',
  );

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'master');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Application Types */
  $handler->display->display_options['fields']['field_acc_application_types']['id'] = 'field_acc_application_types';
  $handler->display->display_options['fields']['field_acc_application_types']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_application_types']['field'] = 'field_acc_application_types';
  $handler->display->display_options['fields']['field_acc_application_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_application_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_application_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_acc_date']['id'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_date']['field'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['settings'] = array(
    'format_type' => 'hr_2',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_submission_status']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_submission_status']['bypass_access'] = 0;
  /* Field: Indexed Node: Submitted By Organization Type */
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['id'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['field'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['bypass_access'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'view';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<a href="[url]">view</a>';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'node/%/access/applications';

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Application Types */
  $handler->display->display_options['fields']['field_acc_application_types']['id'] = 'field_acc_application_types';
  $handler->display->display_options['fields']['field_acc_application_types']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_application_types']['field'] = 'field_acc_application_types';
  $handler->display->display_options['fields']['field_acc_application_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_application_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_application_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_acc_date']['id'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_date']['field'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_submission_status']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_submission_status']['bypass_access'] = 0;
  /* Field: Indexed Node: Submitted By Organization Type */
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['id'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['field'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['bypass_access'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'view';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<a href="[url]">view</a>';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'node/%/access/applications/table';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: XLS */
  $handler = $view->new_display('views_data_export', 'XLS', 'xls');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Application Types */
  $handler->display->display_options['fields']['field_acc_application_types']['id'] = 'field_acc_application_types';
  $handler->display->display_options['fields']['field_acc_application_types']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_application_types']['field'] = 'field_acc_application_types';
  $handler->display->display_options['fields']['field_acc_application_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_application_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_application_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Report Date » Start date */
  $handler->display->display_options['fields']['field_asst_date_value']['id'] = 'field_asst_date_value';
  $handler->display->display_options['fields']['field_asst_date_value']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_asst_date_value']['field'] = 'field_asst_date_value';
  $handler->display->display_options['fields']['field_asst_date_value']['label'] = 'Start date';
  $handler->display->display_options['fields']['field_asst_date_value']['date_format'] = 'short';
  $handler->display->display_options['fields']['field_asst_date_value']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['field_asst_date_value']['link_to_entity'] = 0;
  /* Field: Indexed Node: Report Date » End date */
  $handler->display->display_options['fields']['field_asst_date_value2']['id'] = 'field_asst_date_value2';
  $handler->display->display_options['fields']['field_asst_date_value2']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_asst_date_value2']['field'] = 'field_asst_date_value2';
  $handler->display->display_options['fields']['field_asst_date_value2']['label'] = 'End date';
  $handler->display->display_options['fields']['field_asst_date_value2']['date_format'] = 'short';
  $handler->display->display_options['fields']['field_asst_date_value2']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['field_asst_date_value2']['link_to_entity'] = 0;
  /* Field: Indexed Node: Submitted By Organization Type */
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['id'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['field'] = 'field_acc_submitted_by_org_type';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_submitted_by_org_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Submitted By */
  $handler->display->display_options['fields']['field_acc_submitted_by']['id'] = 'field_acc_submitted_by';
  $handler->display->display_options['fields']['field_acc_submitted_by']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_submitted_by']['field'] = 'field_acc_submitted_by';
  $handler->display->display_options['fields']['field_acc_submitted_by']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_submitted_by']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_submitted_by']['bypass_access'] = 0;
  /* Field: Indexed Node: Submitted To */
  $handler->display->display_options['fields']['field_submitted_to']['id'] = 'field_submitted_to';
  $handler->display->display_options['fields']['field_submitted_to']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_submitted_to']['field'] = 'field_submitted_to';
  $handler->display->display_options['fields']['field_submitted_to']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_submitted_to']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_submitted_to']['bypass_access'] = 0;
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Geographical Location (Destination) */
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['id'] = 'field_acc_geo_location_dest';
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['field'] = 'field_acc_geo_location_dest';
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_geo_location_dest']['bypass_access'] = 0;
  /* Field: Indexed Node: How many days to get an answer? */
  $handler->display->display_options['fields']['field_how_many_days']['id'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_how_many_days']['field'] = 'field_how_many_days';
  $handler->display->display_options['fields']['field_how_many_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: Nationality */
  $handler->display->display_options['fields']['field_nationality']['id'] = 'field_nationality';
  $handler->display->display_options['fields']['field_nationality']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_nationality']['field'] = 'field_nationality';
  $handler->display->display_options['fields']['field_nationality']['delta_offset'] = '0';
  /* Field: Indexed Node: Submission Status */
  $handler->display->display_options['fields']['field_acc_submission_status']['id'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_submission_status']['field'] = 'field_acc_submission_status';
  $handler->display->display_options['fields']['field_acc_submission_status']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_submission_status']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_submission_status']['bypass_access'] = 0;
  /* Field: Indexed Node: If denied, by whom? */
  $handler->display->display_options['fields']['field_if_denied_by_whom_']['id'] = 'field_if_denied_by_whom_';
  $handler->display->display_options['fields']['field_if_denied_by_whom_']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_if_denied_by_whom_']['field'] = 'field_if_denied_by_whom_';
  $handler->display->display_options['fields']['field_if_denied_by_whom_']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_if_denied_by_whom_']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_if_denied_by_whom_']['bypass_access'] = 0;
  /* Field: Indexed Node: Global Cluster */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_sector']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_sector']['bypass_access'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['id'] = 'field_acc_impacts_field_acc_impact_type';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['field'] = 'field_acc_impacts_field_acc_impact_type';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['label'] = 'Impacts Type';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['id'] = 'field_acc_impacts_field_acc_impact_value';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['field'] = 'field_acc_impacts_field_acc_impact_value';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['label'] = 'Impact Value';
  /* Field: Indexed Node: Attach file */
  $handler->display->display_options['fields']['field_acc_attach_file']['id'] = 'field_acc_attach_file';
  $handler->display->display_options['fields']['field_acc_attach_file']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_attach_file']['field'] = 'field_acc_attach_file';
  $handler->display->display_options['fields']['field_acc_attach_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_acc_attach_file']['delta_offset'] = '0';
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  /* Field: Indexed Node: Space(s) */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['og_group_ref']['view_mode'] = 'full';
  $handler->display->display_options['fields']['og_group_ref']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'node/%/access/applications/xls';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'table' => 'table',
    'default' => 0,
    'map' => 0,
    'res_reports' => 0,
    'imp_reports' => 0,
  );

  /* Display: Data Overlay */
  $handler = $view->new_display('openlayers', 'Data Overlay', 'app_map_layer');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'field_acc_geo_location_dest_field_geofield_lat',
    'other_lon' => 'field_acc_geo_location_dest_field_geofield_lon',
    'wkt' => 'nid',
    'other_top' => 'nid',
    'other_right' => 'nid',
    'other_bottom' => 'nid',
    'other_left' => 'nid',
    'name_field' => 'title',
    'description_field' => '',
    'style_field' => '',
    'projection' => 'EPSG:4326',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Geographical Location (Destination) » Geofield: Latitude (indexed) */
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lat']['id'] = 'field_acc_geo_location_dest_field_geofield_lat';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lat']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lat']['field'] = 'field_acc_geo_location_dest_field_geofield_lat';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lat']['label'] = 'Latitude';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lat']['precision'] = '0';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lat']['link_to_entity'] = 0;
  /* Field: Geographical Location (Destination) » Geofield: Longitude (indexed) */
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lon']['id'] = 'field_acc_geo_location_dest_field_geofield_lon';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lon']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lon']['field'] = 'field_acc_geo_location_dest_field_geofield_lon';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lon']['label'] = 'Longitude';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lon']['precision'] = '0';
  $handler->display->display_options['fields']['field_acc_geo_location_dest_field_geofield_lon']['link_to_entity'] = 0;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_acc_date']['id'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_date']['field'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['label'] = '';
  $handler->display->display_options['fields']['field_acc_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_acc_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_acc_date']['settings'] = array(
    'format_type' => 'hr_2',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([field_acc_date])';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    188284353 => 0,
    235660466 => 0,
    229782242 => 0,
    147444660 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'acc_application' => 'acc_application',
  );
  /* Filter criterion: Geographical Location (Destination) » Geofield: Latitude (indexed) */
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lat']['id'] = 'field_acc_geo_location_dest_field_geofield_lat';
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lat']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lat']['field'] = 'field_acc_geo_location_dest_field_geofield_lat';
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lat']['operator'] = 'not empty';
  /* Filter criterion: Geographical Location (Destination) » Geofield: Longitude (indexed) */
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lon']['id'] = 'field_acc_geo_location_dest_field_geofield_lon';
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lon']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lon']['field'] = 'field_acc_geo_location_dest_field_geofield_lon';
  $handler->display->display_options['filters']['field_acc_geo_location_dest_field_geofield_lon']['operator'] = 'not empty';

  /* Display: Map */
  $handler = $view->new_display('page', 'Map', 'map');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'acc_applications';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/access/applications/map';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Res Reports */
  $handler = $view->new_display('page', 'Res Reports', 'res_reports');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/access/applications/res_reports';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Restriction Reports ';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Imp Reports */
  $handler = $view->new_display('page', 'Imp Reports', 'imp_reports');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/access/applications/imp_reports';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Impediment Report';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['acc_applications'] = array(
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
    t('Node ID'),
    t('.'),
    t(','),
    t('All'),
    t('Search'),
    t('Application Types'),
    t('Date'),
    t('Submission Status'),
    t('Submitted By Organization Type'),
    t('view'),
    t('<a href="[url]">view</a>'),
    t('Table'),
    t('XLS'),
    t('Title'),
    t('Start date'),
    t('End date'),
    t('Submitted By'),
    t('Submitted To'),
    t('Locations'),
    t('Geographical Location (Destination)'),
    t('How many days to get an answer?'),
    t('Nationality'),
    t('If denied, by whom?'),
    t('Global Cluster'),
    t('Impacts Type'),
    t('Impact Value'),
    t('Attach file'),
    t('Description'),
    t('Space(s)'),
    t('Data Overlay'),
    t('Latitude'),
    t('Longitude'),
    t('[title] ([field_acc_date])'),
    t('Map'),
    t('Res Reports'),
    t('Imp Reports'),
  );
  $export['acc_applications'] = $view;

  return $export;
}
