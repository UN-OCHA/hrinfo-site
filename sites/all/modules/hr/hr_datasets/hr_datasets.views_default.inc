<?php
/**
 * @file
 * hr_datasets.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_datasets_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_datasets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  /* Field: Indexed Node: Dataset Categories */
  $handler->display->display_options['fields']['field_dataset_categories']['id'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_dataset_categories']['field'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_dataset_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Summary */
  $handler->display->display_options['fields']['field_ds_summary']['id'] = 'field_ds_summary';
  $handler->display->display_options['fields']['field_ds_summary']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_summary']['field'] = 'field_ds_summary';
  /* Field: Indexed Node: Dataset Date */
  $handler->display->display_options['fields']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['settings'] = array(
    'format_type' => 'hr_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Abstract */
  $handler->display->display_options['fields']['field_ds_abstract']['id'] = 'field_ds_abstract';
  $handler->display->display_options['fields']['field_ds_abstract']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_abstract']['field'] = 'field_ds_abstract';
  /* Field: Indexed Node: Dataset Files */
  $handler->display->display_options['fields']['field_ds_files']['id'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_files']['field'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ds_files']['delta_offset'] = '0';
  /* Field: Indexed Node: Instructions */
  $handler->display->display_options['fields']['field_ds_instructions']['id'] = 'field_ds_instructions';
  $handler->display->display_options['fields']['field_ds_instructions']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_instructions']['field'] = 'field_ds_instructions';
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Sort criterion: Indexed Node: Dataset Date */
  $handler->display->display_options['sorts']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['sorts']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['sorts']['field_ds_date']['order'] = 'DESC';
  /* Contextual filter: Indexed Node: Space(s) */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_group_ref']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['og_group_ref']['validate_options']['types'] = array(
    'hr_operation' => 'hr_operation',
  );
  $handler->display->display_options['arguments']['og_group_ref']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_dataset' => 'hr_dataset',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Datasets';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'master');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/datasets';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/datasets/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
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
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Dataset Categories */
  $handler->display->display_options['fields']['field_dataset_categories']['id'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_dataset_categories']['field'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dataset_categories']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_dataset_categories']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_dataset_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Summary */
  $handler->display->display_options['fields']['field_ds_summary']['id'] = 'field_ds_summary';
  $handler->display->display_options['fields']['field_ds_summary']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_summary']['field'] = 'field_ds_summary';
  /* Field: Indexed Node: Dataset Date */
  $handler->display->display_options['fields']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['settings'] = array(
    'format_type' => 'hr_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated Date';
  $handler->display->display_options['fields']['changed']['date_format'] = 'hr_1';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'hr_1';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  /* Field: Indexed Node: Abstract */
  $handler->display->display_options['fields']['field_ds_abstract']['id'] = 'field_ds_abstract';
  $handler->display->display_options['fields']['field_ds_abstract']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_abstract']['field'] = 'field_ds_abstract';
  $handler->display->display_options['path'] = 'node/%/datasets/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Locations */
  $handler = $view->new_display('search_api_views_facets_block', 'Locations', 'dataset_locations');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_dataset' => 'hr_dataset',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Dataset Locations';
  $handler->display->display_options['linked_path'] = 'applications/data/datasets';
  $handler->display->display_options['facet_field'] = 'field_locations';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'csv');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'datasets.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Published';
  $handler->display->display_options['fields']['status']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['status']['format_name'] = 1;
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Dataset Categories */
  $handler->display->display_options['fields']['field_dataset_categories']['id'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_dataset_categories']['field'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_dataset_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Summary */
  $handler->display->display_options['fields']['field_ds_summary']['id'] = 'field_ds_summary';
  $handler->display->display_options['fields']['field_ds_summary']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_summary']['field'] = 'field_ds_summary';
  /* Field: Indexed Node: Data Source(s) */
  $handler->display->display_options['fields']['field_ds_datasources']['id'] = 'field_ds_datasources';
  $handler->display->display_options['fields']['field_ds_datasources']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_datasources']['field'] = 'field_ds_datasources';
  /* Field: Indexed Node: Data Guardian */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Indexed Node: Abstract */
  $handler->display->display_options['fields']['field_ds_abstract']['id'] = 'field_ds_abstract';
  $handler->display->display_options['fields']['field_ds_abstract']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_abstract']['field'] = 'field_ds_abstract';
  /* Field: Indexed Node: Dataset Types */
  $handler->display->display_options['fields']['field_dataset_types']['id'] = 'field_dataset_types';
  $handler->display->display_options['fields']['field_dataset_types']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_dataset_types']['field'] = 'field_dataset_types';
  $handler->display->display_options['fields']['field_dataset_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_dataset_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Terms of Use */
  $handler->display->display_options['fields']['field_terms_of_use']['id'] = 'field_terms_of_use';
  $handler->display->display_options['fields']['field_terms_of_use']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_terms_of_use']['field'] = 'field_terms_of_use';
  $handler->display->display_options['fields']['field_terms_of_use']['type'] = 'text_plain';
  /* Field: Indexed Node: Dataset Language(s) */
  $handler->display->display_options['fields']['field_languages']['id'] = 'field_languages';
  $handler->display->display_options['fields']['field_languages']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_languages']['field'] = 'field_languages';
  $handler->display->display_options['fields']['field_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_languages']['delta_offset'] = '0';
  /* Field: Indexed Node: Dataset Date */
  $handler->display->display_options['fields']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['settings'] = array(
    'format_type' => 'hr_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Most Recent Changes */
  $handler->display->display_options['fields']['field_ds_recent_changes']['id'] = 'field_ds_recent_changes';
  $handler->display->display_options['fields']['field_ds_recent_changes']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_recent_changes']['field'] = 'field_ds_recent_changes';
  /* Field: Indexed Node: Dataset Files */
  $handler->display->display_options['fields']['field_ds_files']['id'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_files']['field'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ds_files']['delta_offset'] = '0';
  /* Field: Indexed Node: Instructions */
  $handler->display->display_options['fields']['field_ds_instructions']['id'] = 'field_ds_instructions';
  $handler->display->display_options['fields']['field_ds_instructions']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_instructions']['field'] = 'field_ds_instructions';
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Post date';
  $handler->display->display_options['fields']['created']['date_format'] = 'hr_1';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Node: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated date';
  $handler->display->display_options['fields']['changed']['date_format'] = 'hr_1';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Path';
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'node/%/datasets/csv';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'list' => 'list',
    'table' => 'table',
    'default' => 0,
    'dataset_locations' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: CSV ADMIN */
  $handler = $view->new_display('views_data_export', 'CSV ADMIN', 'csv_admin');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'view any unpublished hr_dataset content';
  $handler->display->display_options['access']['group_id_arg'] = '1';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'CSV ADMIN';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'datasets.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Published';
  $handler->display->display_options['fields']['status']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['status']['format_name'] = 1;
  /* Field: Indexed Node: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_locations']['bypass_access'] = 0;
  /* Field: Indexed Node: Dataset Categories */
  $handler->display->display_options['fields']['field_dataset_categories']['id'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_dataset_categories']['field'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_dataset_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Summary */
  $handler->display->display_options['fields']['field_ds_summary']['id'] = 'field_ds_summary';
  $handler->display->display_options['fields']['field_ds_summary']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_summary']['field'] = 'field_ds_summary';
  /* Field: Indexed Node: Data Source(s) */
  $handler->display->display_options['fields']['field_ds_datasources']['id'] = 'field_ds_datasources';
  $handler->display->display_options['fields']['field_ds_datasources']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_datasources']['field'] = 'field_ds_datasources';
  /* Field: Indexed Node: Data Guardian */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Indexed Node: Abstract */
  $handler->display->display_options['fields']['field_ds_abstract']['id'] = 'field_ds_abstract';
  $handler->display->display_options['fields']['field_ds_abstract']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_abstract']['field'] = 'field_ds_abstract';
  /* Field: Indexed Node: Dataset Types */
  $handler->display->display_options['fields']['field_dataset_types']['id'] = 'field_dataset_types';
  $handler->display->display_options['fields']['field_dataset_types']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_dataset_types']['field'] = 'field_dataset_types';
  $handler->display->display_options['fields']['field_dataset_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_dataset_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Terms of Use */
  $handler->display->display_options['fields']['field_terms_of_use']['id'] = 'field_terms_of_use';
  $handler->display->display_options['fields']['field_terms_of_use']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_terms_of_use']['field'] = 'field_terms_of_use';
  $handler->display->display_options['fields']['field_terms_of_use']['type'] = 'text_plain';
  /* Field: Indexed Node: Dataset Language(s) */
  $handler->display->display_options['fields']['field_languages']['id'] = 'field_languages';
  $handler->display->display_options['fields']['field_languages']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_languages']['field'] = 'field_languages';
  $handler->display->display_options['fields']['field_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_languages']['delta_offset'] = '0';
  /* Field: Indexed Node: Dataset Date */
  $handler->display->display_options['fields']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['settings'] = array(
    'format_type' => 'hr_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Most Recent Changes */
  $handler->display->display_options['fields']['field_ds_recent_changes']['id'] = 'field_ds_recent_changes';
  $handler->display->display_options['fields']['field_ds_recent_changes']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_recent_changes']['field'] = 'field_ds_recent_changes';
  /* Field: Indexed Node: Dataset Files */
  $handler->display->display_options['fields']['field_ds_files']['id'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_files']['field'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ds_files']['delta_offset'] = '0';
  /* Field: Indexed Node: Instructions */
  $handler->display->display_options['fields']['field_ds_instructions']['id'] = 'field_ds_instructions';
  $handler->display->display_options['fields']['field_ds_instructions']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_instructions']['field'] = 'field_ds_instructions';
  /* Field: Indexed Node: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Post date';
  $handler->display->display_options['fields']['created']['date_format'] = 'hr_1';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Node: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated date';
  $handler->display->display_options['fields']['changed']['date_format'] = 'hr_1';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Path';
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'node/%/datasets/csv-admin';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'list' => 'list',
    'table' => 'table',
    'default' => 0,
    'dataset_locations' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title_field';
  $handler->display->display_options['row_options']['link_field'] = 'url';
  $handler->display->display_options['row_options']['description_field'] = 'field_ds_summary';
  $handler->display->display_options['row_options']['creator_field'] = 'author';
  $handler->display->display_options['row_options']['date_field'] = 'field_ds_date';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Summary */
  $handler->display->display_options['fields']['field_ds_summary']['id'] = 'field_ds_summary';
  $handler->display->display_options['fields']['field_ds_summary']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_summary']['field'] = 'field_ds_summary';
  /* Field: Indexed Node: Dataset Date */
  $handler->display->display_options['fields']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['settings'] = array(
    'format_type' => 'hr_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'node/%/datasets/feed';
  $handler->display->display_options['displays'] = array(
    'list' => 'list',
    'default' => 0,
    'master' => 0,
    'table' => 0,
    'dataset_locations' => 0,
  );
  $translatables['hr_datasets'] = array(
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
    t('Dataset Categories'),
    t('Summary'),
    t('Dataset Date'),
    t('Abstract'),
    t('Dataset Files'),
    t('Instructions'),
    t('URL'),
    t('All'),
    t('Search Datasets'),
    t('List'),
    t('Table'),
    t('Last Updated Date'),
    t('Locations'),
    t('Dataset Locations'),
    t('CSV'),
    t('Node ID'),
    t('.'),
    t('Published'),
    t('Data Source(s)'),
    t('Data Guardian'),
    t('Dataset Types'),
    t('Terms of Use'),
    t('Dataset Language(s)'),
    t('Most Recent Changes'),
    t('Post date'),
    t('Updated date'),
    t('Path'),
    t('CSV ADMIN'),
    t('Author'),
    t('Feed'),
  );
  $export['hr_datasets'] = $view;

  return $export;
}
