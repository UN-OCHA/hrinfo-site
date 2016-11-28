<?php
/**
 * @file
 * hr_documents.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_documents_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_document_types';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Document types';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'hr_document_type' => 'hr_document_type',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['hr_document_types'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Entity Reference'),
  );
  $export['hr_document_types'] = $view;

  $view = new view();
  $view->name = 'hr_documents';
  $view->description = '';
  $view->tag = 'Documents';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Documents';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
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
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Document type */
  $handler->display->display_options['fields']['field_document_type']['id'] = 'field_document_type';
  $handler->display->display_options['fields']['field_document_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_document_type']['field'] = 'field_document_type';
  $handler->display->display_options['fields']['field_document_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_document_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_document_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Managed by */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Original Publication Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Node: File(s) */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['label'] = 'Files';
  $handler->display->display_options['fields']['field_files_collection']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['display'] = 'view';
  $handler->display->display_options['fields']['field_files_collection']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_files_collection']['bypass_access'] = 0;
  /* Contextual filter: Indexed Node: Groups audience */
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
    'hr_document' => 'hr_document',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Documents';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'master');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/documents';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/documents/list';
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
    'title_field' => 'title_field',
    'field_document_type' => 'field_document_type',
    'field_organizations' => 'field_organizations',
    'field_publication_date' => 'field_publication_date',
    'field_files_collection' => 'field_files_collection',
  );
  $handler->display->display_options['style_options']['default'] = 'field_publication_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_document_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organizations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_files_collection' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/documents/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'csv');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Document type */
  $handler->display->display_options['fields']['field_document_type']['id'] = 'field_document_type';
  $handler->display->display_options['fields']['field_document_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_document_type']['field'] = 'field_document_type';
  $handler->display->display_options['fields']['field_document_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_document_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_document_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Managed by */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Original Publication Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Node: File(s) */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['label'] = 'Files';
  $handler->display->display_options['fields']['field_files_collection']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_files_collection']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_files_collection']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['display'] = 'view';
  $handler->display->display_options['fields']['field_files_collection']['view_mode'] = 'token';
  $handler->display->display_options['fields']['field_files_collection']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'node/%/documents/csv';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'list' => 0,
    'table' => 0,
  );

  /* Display: Global master */
  $handler = $view->new_display('page', 'Global master', 'global_master');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'documents';

  /* Display: Global list */
  $handler = $view->new_display('page', 'Global list', 'global_list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'documents/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Global table */
  $handler = $view->new_display('page', 'Global table', 'global_table');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_document_type' => 'field_document_type',
    'field_organizations' => 'field_organizations',
    'field_publication_date' => 'field_publication_date',
    'field_files_collection' => 'field_files_collection',
  );
  $handler->display->display_options['style_options']['default'] = 'field_publication_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_document_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organizations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_files_collection' => array(
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
  $handler->display->display_options['path'] = 'documents/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Global feed */
  $handler = $view->new_display('feed', 'Global feed', 'global_feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title_field';
  $handler->display->display_options['row_options']['link_field'] = 'url';
  $handler->display->display_options['row_options']['description_field'] = 'body_summary';
  $handler->display->display_options['row_options']['creator_field'] = 'author';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Original Publication Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
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
  /* Field: Indexed Node: The main body text » Summary */
  $handler->display->display_options['fields']['body_summary']['id'] = 'body_summary';
  $handler->display->display_options['fields']['body_summary']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body_summary']['field'] = 'body_summary';
  $handler->display->display_options['fields']['body_summary']['label'] = '';
  $handler->display->display_options['fields']['body_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_summary']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'documents/feed';
  $handler->display->display_options['displays'] = array(
    'global_master' => 'global_master',
    'default' => 0,
    'master' => 0,
    'list' => 0,
    'table' => 0,
    'global_list' => 0,
    'global_table' => 0,
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title_field';
  $handler->display->display_options['row_options']['link_field'] = 'url';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['creator_field'] = 'author';
  $handler->display->display_options['row_options']['date_field'] = 'field_publication_date';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Original Publication Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
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
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Groups audience */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  $handler->display->display_options['path'] = 'node/%/documents/feed';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'default' => 0,
    'list' => 0,
    'table' => 0,
    'global_master' => 0,
    'global_list' => 0,
    'global_table' => 0,
  );
  $translatables['hr_documents'] = array(
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
    t('Document type'),
    t('Managed by'),
    t('Original Publication Date'),
    t('Files'),
    t('All'),
    t('Search Documents'),
    t('List'),
    t('Table'),
    t('CSV'),
    t('Global master'),
    t('Global list'),
    t('Global table'),
    t('Global feed'),
    t('.'),
    t(','),
    t('Feed'),
    t('The main body text'),
  );
  $export['hr_documents'] = $view;

  $view = new view();
  $view->name = 'hr_documents_panes';
  $view->description = '';
  $view->tag = 'Documents';
  $view->base_table = 'node';
  $view->human_name = 'Documents Panes';
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
  /* Sort criterion: Content: Original Publication Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_publication_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_date_value']['expose']['label'] = 'Publication Date (field_publication_date)';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
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

  /* Display: List */
  $handler = $view->new_display('panel_pane', 'List', 'list');
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
    'hr_document' => 'hr_document',
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
  /* Filter criterion: Content: Coordination hubs (field_coordination_hubs) */
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['id'] = 'field_coordination_hubs_target_id';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['table'] = 'field_data_field_coordination_hubs';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['field'] = 'field_coordination_hubs_target_id';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['expose']['operator_id'] = 'field_coordination_hubs_target_id_op';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['expose']['label'] = 'Coordination hubs';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['expose']['operator'] = 'field_coordination_hubs_target_id_op';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['expose']['identifier'] = 'field_coordination_hubs_target_id';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );
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
  /* Filter criterion: Content: Document type (field_document_type) (reference filter) */
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['id'] = 'field_document_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['field'] = 'field_document_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['expose']['operator_id'] = 'field_document_type_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['expose']['label'] = 'Document type';
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['expose']['operator'] = 'field_document_type_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['expose']['identifier'] = 'field_document_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    188284353 => 0,
    235660466 => 0,
    229782242 => 0,
    147444660 => 0,
  );
  $handler->display->display_options['filters']['field_document_type_target_id_entityreference_filter']['reference_display'] = 'hr_document_types:entityreference_1';
  $handler->display->display_options['pane_title'] = 'Dynamic';
  $handler->display->display_options['pane_category']['name'] = 'Documents';
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

  /* Display: Thumbnail */
  $handler = $view->new_display('panel_pane', 'Thumbnail', 'thumbnail');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: File(s) (field_files_collection) */
  $handler->display->display_options['relationships']['field_files_collection_value']['id'] = 'field_files_collection_value';
  $handler->display->display_options['relationships']['field_files_collection_value']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['relationships']['field_files_collection_value']['field'] = 'field_files_collection_value';
  $handler->display->display_options['relationships']['field_files_collection_value']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: File */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'field_data_field_file';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['relationship'] = 'field_files_collection_value';
  $handler->display->display_options['fields']['field_file']['label'] = '';
  $handler->display->display_options['fields']['field_file']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_file']['alter']['path'] = 'node/!1';
  $handler->display->display_options['fields']['field_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_file']['settings'] = array(
    'file_view_mode' => 'preview',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'og_group_ref',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'og_group_ref' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Space(s) */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([og_group_ref])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Documents from context */
  $handler = $view->new_display('panel_pane', 'Documents from context', 'documents_from_context');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Documents';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'search';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Original Publication Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['arguments']['og_group_ref_target_id']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['validate']['fail'] = 'ignore';
  /* Contextual filter: Content: Clusters/Sectors (field_bundles) */
  $handler->display->display_options['arguments']['field_bundles_target_id']['id'] = 'field_bundles_target_id';
  $handler->display->display_options['arguments']['field_bundles_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['field_bundles_target_id']['field'] = 'field_bundles_target_id';
  $handler->display->display_options['arguments']['field_bundles_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_bundles_target_id']['default_argument_type'] = 'node';
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
    'hr_document' => 'hr_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['pane_title'] = 'Documents from context';
  $handler->display->display_options['pane_category']['name'] = 'Documents';
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
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Group',
    ),
    'field_bundles_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Clusters/Sectors (field_bundles)',
    ),
  );

  /* Display: Meeting Minutes from context */
  $handler = $view->new_display('panel_pane', 'Meeting Minutes from context', 'mm_from_context');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Meeting Minutes';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'search';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Original Publication Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'hr_document' => 'hr_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Document type (field_document_type) */
  $handler->display->display_options['filters']['field_document_type_target_id']['id'] = 'field_document_type_target_id';
  $handler->display->display_options['filters']['field_document_type_target_id']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['filters']['field_document_type_target_id']['field'] = 'field_document_type_target_id';
  $handler->display->display_options['filters']['field_document_type_target_id']['value']['value'] = '73';
  $handler->display->display_options['filters']['field_document_type_target_id']['shs_enabled'] = 0;
  $handler->display->display_options['pane_title'] = 'Meeting Minutes from context';
  $handler->display->display_options['pane_category']['name'] = 'Documents';
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
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Group',
    ),
    'field_bundles_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Clusters/Sectors (field_bundles)',
    ),
  );
  $translatables['hr_documents_panes'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Publication Date (field_publication_date)'),
    t('Post date'),
    t('All'),
    t('List'),
    t('Space'),
    t('Please select a space OR a cluster, but NOT BOTH. Selecting both a space and a cluster will not work.'),
    t('Clusters/Sectors'),
    t('Coordination hubs'),
    t('Disasters'),
    t('Locations'),
    t('Themes'),
    t('Document type'),
    t('Dynamic'),
    t('Documents'),
    t('Thumbnail'),
    t('field collection item from field_files_collection'),
    t('View panes'),
    t('Entity Reference'),
    t('[title] ([og_group_ref])'),
    t('Documents from context'),
    t('Latest Documents'),
    t('Meeting Minutes from context'),
    t('Latest Meeting Minutes'),
  );
  $export['hr_documents_panes'] = $view;

  return $export;
}
