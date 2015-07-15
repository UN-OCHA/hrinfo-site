<?php
/**
 * @file
 * acc_incidents.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function acc_incidents_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'acc_incident_graphs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Access Incident Graphs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'By Types';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_acc_impact_type' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'field_acc_impact_value' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of units affected',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_acc_impact_type',
    'invert' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'acc_incident' => 'acc_incident',
  );

  /* Display: By Type */
  $handler = $view->new_display('block', 'By Type', 'graph_by_type');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_acc_type']['id'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['table'] = 'field_data_field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['field'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['block_description'] = 'Incidents Graph by Type';

  /* Display: XLS By Type */
  $handler = $view->new_display('views_data_export', 'XLS By Type', 'xls_by_incident_type');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_acc_type']['id'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['table'] = 'field_data_field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['field'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['path'] = 'node/%/access/incidents_by_type/xls';
  $handler->display->display_options['displays'] = array(
    'graph_by_type' => 'graph_by_type',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: By Acc Constraint */
  $handler = $view->new_display('block', 'By Acc Constraint', 'graph_by_acc_constr');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Incidents by Access Constraints';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'name' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of Incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'name',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_acc_type_target_id']['id'] = 'field_acc_type_target_id';
  $handler->display->display_options['relationships']['field_acc_type_target_id']['table'] = 'field_data_field_acc_type';
  $handler->display->display_options['relationships']['field_acc_type_target_id']['field'] = 'field_acc_type_target_id';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_acc_type_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name']['label'] = 'Access Constraint';
  $handler->display->display_options['block_description'] = 'Incidents by Access Constraints';

  /* Display: By Sector */
  $handler = $view->new_display('block', 'By Sector', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Incidents by sector';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  /* Field: Field: Global Clusters */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['label'] = 'Sectors';
  $handler->display->display_options['fields']['field_sectors']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'Incident by sector';

  /* Display: XLS By Acc Constraint */
  $handler = $view->new_display('views_data_export', 'XLS By Acc Constraint', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Acc Constraint ';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_acc_type_target_id']['id'] = 'field_acc_type_target_id';
  $handler->display->display_options['relationships']['field_acc_type_target_id']['table'] = 'field_data_field_acc_type';
  $handler->display->display_options['relationships']['field_acc_type_target_id']['field'] = 'field_acc_type_target_id';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_acc_type_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name']['label'] = 'Access Constraint';
  $handler->display->display_options['path'] = 'node/%/access/incidents_by_acc_const';
  $handler->display->display_options['displays'] = array(
    'graph_by_acc_constr' => 'graph_by_acc_constr',
    'default' => 0,
    'graph_by_type' => 0,
    'block_2' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS By Sector */
  $handler = $view->new_display('views_data_export', 'XLS By Sector', 'views_data_export_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Sector';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Field: Global Clusters */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['label'] = 'Sectors';
  $handler->display->display_options['fields']['field_sectors']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'node/%/access/incidents_by_sector';
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
    'graph_by_type' => 0,
    'graph_by_acc_constr' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: By Location */
  $handler = $view->new_display('block', 'By Location', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Location';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incident';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_locations']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'Incidents By Location';

  /* Display: By Responsible Actor */
  $handler = $view->new_display('block', 'By Responsible Actor', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Responsible Actor';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_responsible_organization_t' => array(
      'enabled' => 0,
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_responsible_organization_t',
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
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Responsible Organization Type */
  $handler->display->display_options['fields']['field_responsible_organization_t']['id'] = 'field_responsible_organization_t';
  $handler->display->display_options['fields']['field_responsible_organization_t']['table'] = 'field_data_field_responsible_organization_t';
  $handler->display->display_options['fields']['field_responsible_organization_t']['field'] = 'field_responsible_organization_t';
  $handler->display->display_options['fields']['field_responsible_organization_t']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_responsible_organization_t']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'By Responsible Actor';

  /* Display: By Aff Org */
  $handler = $view->new_display('block', 'By Aff Org', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Affected Organization';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_affected_organization_type' => array(
      'enabled' => 0,
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_affected_organization_type',
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
  $handler->display->display_options['fields']['nid']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Affected Organization Type */
  $handler->display->display_options['fields']['field_affected_organization_type']['id'] = 'field_affected_organization_type';
  $handler->display->display_options['fields']['field_affected_organization_type']['table'] = 'field_data_field_affected_organization_type';
  $handler->display->display_options['fields']['field_affected_organization_type']['field'] = 'field_affected_organization_type';
  $handler->display->display_options['fields']['field_affected_organization_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_affected_organization_type']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'By Aff Org';

  /* Display: By Impacts */
  $handler = $view->new_display('block', 'By Impacts', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Impacts';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Impacts (field_acc_impacts) */
  $handler->display->display_options['relationships']['field_acc_impacts_value']['id'] = 'field_acc_impacts_value';
  $handler->display->display_options['relationships']['field_acc_impacts_value']['table'] = 'field_data_field_acc_impacts';
  $handler->display->display_options['relationships']['field_acc_impacts_value']['field'] = 'field_acc_impacts_value';
  $handler->display->display_options['relationships']['field_acc_impacts_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Impacts */
  $handler->display->display_options['fields']['field_acc_impact_type']['id'] = 'field_acc_impact_type';
  $handler->display->display_options['fields']['field_acc_impact_type']['table'] = 'field_data_field_acc_impact_type';
  $handler->display->display_options['fields']['field_acc_impact_type']['field'] = 'field_acc_impact_type';
  $handler->display->display_options['fields']['field_acc_impact_type']['relationship'] = 'field_acc_impacts_value';
  /* Field: Field collection item: Value */
  $handler->display->display_options['fields']['field_acc_impact_value']['id'] = 'field_acc_impact_value';
  $handler->display->display_options['fields']['field_acc_impact_value']['table'] = 'field_data_field_acc_impact_value';
  $handler->display->display_options['fields']['field_acc_impact_value']['field'] = 'field_acc_impact_value';
  $handler->display->display_options['fields']['field_acc_impact_value']['relationship'] = 'field_acc_impacts_value';
  $handler->display->display_options['fields']['field_acc_impact_value']['label'] = 'Sum';
  $handler->display->display_options['fields']['field_acc_impact_value']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $translatables['acc_incident_graphs'] = array(
    t('Master'),
    t('By Types'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Number of incidents'),
    t('All'),
    t('By Type'),
    t('Type'),
    t('Incidents Graph by Type'),
    t('XLS By Type'),
    t('By Acc Constraint'),
    t('Incidents by Access Constraints'),
    t('Taxonomy term entity referenced from field_acc_type'),
    t('Parent'),
    t('Access Constraint'),
    t('By Sector'),
    t('Incidents by sector'),
    t('Sectors'),
    t('Incident by sector'),
    t('XLS By Acc Constraint'),
    t('By Acc Constraint '),
    t('XLS By Sector'),
    t('By Location'),
    t('Number of incident'),
    t('Locations'),
    t('Incidents By Location'),
    t('By Responsible Actor'),
    t('Responsible Organization Type'),
    t('By Aff Org'),
    t('By Affected Organization'),
    t('Affected Organization Type'),
    t('By Impacts'),
    t('field collection item from field_acc_impacts'),
    t('Impacts'),
    t('Sum'),
  );
  $export['acc_incident_graphs'] = $view;

  $view = new view();
  $view->name = 'acc_incidents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_acc_search';
  $view->human_name = 'Access Incidents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'create acc_incident content';
  $handler->display->display_options['access']['group_id_arg'] = '1';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Sort criterion: Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_acc_date_value']['id'] = 'field_acc_date_value';
  $handler->display->display_options['sorts']['field_acc_date_value']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['sorts']['field_acc_date_value']['field'] = 'field_acc_date_value';
  $handler->display->display_options['sorts']['field_acc_date_value']['order'] = 'DESC';
  /* Contextual filter: Indexed Node: Groups audience */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'not found';
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
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Access Incidents';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
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
    'acc_incident' => 'acc_incident',
  );

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'master');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'acc_incidents';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_acc_date']['id'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_date']['field'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['settings'] = array(
    'format_type' => 'hr_2',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_acc_date']['delta_offset'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_locations_parent']['id'] = 'field_locations_parent';
  $handler->display->display_options['fields']['field_locations_parent']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations_parent']['field'] = 'field_locations_parent';
  $handler->display->display_options['fields']['field_locations_parent']['label'] = 'Admin Level 1';
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['label'] = 'Admin Level 2';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_acc_type']['id'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_type']['field'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_type']['bypass_access'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'View';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<a href="[url]">view</a>';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'node/%/access/incidents';

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<a href="[url]">view</a>';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_acc_date']['id'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_date']['field'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_acc_date']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_acc_date']['settings'] = array(
    'format_type' => 'hr_2',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_acc_date']['delta_offset'] = '0';
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['label'] = 'Location';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_acc_type']['id'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_type']['field'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_type']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'node/%/access/incidents/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '1';
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_acc_type_parent']['id'] = 'field_acc_type_parent';
  $handler->display->display_options['fields']['field_acc_type_parent']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_type_parent']['field'] = 'field_acc_type_parent';
  $handler->display->display_options['fields']['field_acc_type_parent']['label'] = 'Access Constraint';
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_acc_type']['id'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_type']['field'] = 'field_acc_type';
  $handler->display->display_options['fields']['field_acc_type']['label'] = 'Incident Type';
  $handler->display->display_options['fields']['field_acc_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_acc_date']['id'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_date']['field'] = 'field_acc_date';
  $handler->display->display_options['fields']['field_acc_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_locations_parent']['id'] = 'field_locations_parent';
  $handler->display->display_options['fields']['field_locations_parent']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations_parent']['field'] = 'field_locations_parent';
  $handler->display->display_options['fields']['field_locations_parent']['label'] = 'Admin Level 1';
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Responsible Organization Type */
  $handler->display->display_options['fields']['field_responsible_organization_t']['id'] = 'field_responsible_organization_t';
  $handler->display->display_options['fields']['field_responsible_organization_t']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_responsible_organization_t']['field'] = 'field_responsible_organization_t';
  $handler->display->display_options['fields']['field_responsible_organization_t']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_responsible_organization_t']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_responsible_organization_t']['bypass_access'] = 0;
  /* Field: Indexed Node: Responsible actor */
  $handler->display->display_options['fields']['field_responsible_actors']['id'] = 'field_responsible_actors';
  $handler->display->display_options['fields']['field_responsible_actors']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_responsible_actors']['field'] = 'field_responsible_actors';
  $handler->display->display_options['fields']['field_responsible_actors']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_responsible_actors']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_responsible_actors']['bypass_access'] = 0;
  /* Field: Indexed Node: Affected Organization Type */
  $handler->display->display_options['fields']['field_affected_organization_type']['id'] = 'field_affected_organization_type';
  $handler->display->display_options['fields']['field_affected_organization_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_affected_organization_type']['field'] = 'field_affected_organization_type';
  $handler->display->display_options['fields']['field_affected_organization_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_affected_organization_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_affected_organization_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Affected Organizations */
  $handler->display->display_options['fields']['field_affected_organizations']['id'] = 'field_affected_organizations';
  $handler->display->display_options['fields']['field_affected_organizations']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_affected_organizations']['field'] = 'field_affected_organizations';
  $handler->display->display_options['fields']['field_affected_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_affected_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_affected_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Type of affectee */
  $handler->display->display_options['fields']['field_type_of_affectee']['id'] = 'field_type_of_affectee';
  $handler->display->display_options['fields']['field_type_of_affectee']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_type_of_affectee']['field'] = 'field_type_of_affectee';
  $handler->display->display_options['fields']['field_type_of_affectee']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_type_of_affectee']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_type_of_affectee']['bypass_access'] = 0;
  /* Field: Indexed Node: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_bundles']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bundles']['bypass_access'] = 0;
  /* Field: Impacts: Impacts (indexed) */
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['id'] = 'field_acc_impacts_field_acc_impact_type';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['field'] = 'field_acc_impacts_field_acc_impact_type';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['label'] = 'Impacts';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_type']['bypass_access'] = 0;
  /* Field: Impacts: Value (indexed) */
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['id'] = 'field_acc_impacts_field_acc_impact_value';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['field'] = 'field_acc_impacts_field_acc_impact_value';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['label'] = 'Impact Value';
  $handler->display->display_options['fields']['field_acc_impacts_field_acc_impact_value']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['path'] = 'node/%/access/incidents/xls';
  $handler->display->display_options['displays'] = array(
    'table' => 'table',
    'default' => 0,
    'master' => 0,
    'map' => 0,
    'graphs' => 0,
  );

  /* Display: Map Data */
  $handler = $view->new_display('openlayers', 'Map Data', 'map_data');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'field_locations_field_geofield_lat',
    'other_lon' => 'field_locations_field_geofield_lon',
    'wkt' => 'title',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
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
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Locations » Geofield: Latitude (indexed) */
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['id'] = 'field_locations_field_geofield_lat';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['field'] = 'field_locations_field_geofield_lat';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['precision'] = '0';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['separator'] = '';
  $handler->display->display_options['fields']['field_locations_field_geofield_lat']['link_to_entity'] = 0;
  /* Field: Locations » Geofield: Longitude (indexed) */
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['id'] = 'field_locations_field_geofield_lon';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['field'] = 'field_locations_field_geofield_lon';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['precision'] = '0';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['separator'] = '';
  $handler->display->display_options['fields']['field_locations_field_geofield_lon']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Access Incidents';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
    229782242 => 0,
    147444660 => 0,
  );
  /* Filter criterion: Locations » Geofield: Latitude (indexed) */
  $handler->display->display_options['filters']['field_locations_field_geofield_lat']['id'] = 'field_locations_field_geofield_lat';
  $handler->display->display_options['filters']['field_locations_field_geofield_lat']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['field_locations_field_geofield_lat']['field'] = 'field_locations_field_geofield_lat';
  $handler->display->display_options['filters']['field_locations_field_geofield_lat']['operator'] = 'not empty';
  /* Filter criterion: Locations » Geofield: Longitude (indexed) */
  $handler->display->display_options['filters']['field_locations_field_geofield_lon']['id'] = 'field_locations_field_geofield_lon';
  $handler->display->display_options['filters']['field_locations_field_geofield_lon']['table'] = 'search_api_index_acc_search';
  $handler->display->display_options['filters']['field_locations_field_geofield_lon']['field'] = 'field_locations_field_geofield_lon';
  $handler->display->display_options['filters']['field_locations_field_geofield_lon']['operator'] = 'not empty';

  /* Display: Map */
  $handler = $view->new_display('page', 'Map', 'map');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'acc_incidents';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/access/incidents/map';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Graphs */
  $handler = $view->new_display('page', 'Graphs', 'graphs');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'node/%/access/incidents/graphs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Graphs';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['acc_incidents'] = array(
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
    t('Search Access Incidents'),
    t('Date'),
    t('Admin Level 1'),
    t('Admin Level 2'),
    t('Type'),
    t('View'),
    t('<a href="[url]">view</a>'),
    t('Table'),
    t('Location'),
    t('XLS'),
    t('Access Constraint'),
    t('Incident Type'),
    t('Locations'),
    t('Responsible Organization Type'),
    t('Responsible actor'),
    t('Affected Organization Type'),
    t('Affected Organizations'),
    t('Type of affectee'),
    t('Clusters/Sectors'),
    t('Impacts'),
    t('Impact Value'),
    t('Description'),
    t('Map Data'),
    t('Latitude (indexed)'),
    t('.'),
    t('Longitude (indexed)'),
    t('Map'),
    t('Graphs'),
  );
  $export['acc_incidents'] = $view;

  return $export;
}
