<?php
/**
 * @file
 * hr_contacts.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_contacts_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_contacts';
  $view->description = '';
  $view->tag = 'Contacts';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Contacts';
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
  /* Field: Indexed Node: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['label'] = 'Clusters';
  $handler->display->display_options['fields']['field_bundles']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_bundles']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bundles']['bypass_access'] = 0;
  /* Field: Indexed Node: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'First name';
  $handler->display->display_options['fields']['field_first_name']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_first_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last name';
  $handler->display->display_options['fields']['field_last_name']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email';
  /* Field: Indexed Node: Job Title */
  $handler->display->display_options['fields']['field_job_title_other']['id'] = 'field_job_title_other';
  $handler->display->display_options['fields']['field_job_title_other']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_job_title_other']['field'] = 'field_job_title_other';
  /* Field: Indexed Node: Managed by */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = 'Organization';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = 'Location';
  $handler->display->display_options['fields']['field_location']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_location']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_location']['bypass_access'] = 0;
  /* Sort criterion: Indexed Node: Last name */
  $handler->display->display_options['sorts']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['sorts']['field_last_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_last_name']['field'] = 'field_last_name';
  /* Sort criterion: Indexed Node: First name */
  $handler->display->display_options['sorts']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['sorts']['field_first_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_first_name']['field'] = 'field_first_name';
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
    'hr_contact' => 'hr_contact',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Contacts';
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
  $handler->display->display_options['path'] = 'node/%/contacts';

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
  $handler->display->display_options['path'] = 'node/%/contacts/table';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/contacts/list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'csv');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'contacts.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['label'] = 'Clusters';
  $handler->display->display_options['fields']['field_bundles']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_bundles']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_bundles']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bundles']['bypass_access'] = 0;
  /* Field: Indexed Node: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'First name';
  $handler->display->display_options['fields']['field_first_name']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_first_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last name';
  $handler->display->display_options['fields']['field_last_name']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email';
  /* Field: Indexed Node: Phones */
  $handler->display->display_options['fields']['field_phones']['id'] = 'field_phones';
  $handler->display->display_options['fields']['field_phones']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_phones']['field'] = 'field_phones';
  $handler->display->display_options['fields']['field_phones']['label'] = 'Phones';
  $handler->display->display_options['fields']['field_phones']['click_sort_column'] = 'numbertype';
  $handler->display->display_options['fields']['field_phones']['settings'] = array(
    'components' => array(
      'country' => 0,
      'numbertype' => 0,
    ),
    'full_hcard' => 0,
    'as_tel_link' => 0,
    'raw' => 1,
    'allow_alpha' => 0,
    'country_name_position' => 'after',
    'numbertype_position' => 'before',
  );
  $handler->display->display_options['fields']['field_phones']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_phones']['separator'] = ';';
  /* Field: Indexed Node: Managed by */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = 'Organization';
  $handler->display->display_options['fields']['field_organizations']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Job Title */
  $handler->display->display_options['fields']['field_job_title_other']['id'] = 'field_job_title_other';
  $handler->display->display_options['fields']['field_job_title_other']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_job_title_other']['field'] = 'field_job_title_other';
  /* Field: Indexed Node: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = 'Location';
  $handler->display->display_options['fields']['field_location']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_location']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_location']['bypass_access'] = 0;
  /* Field: Indexed Node: Coordination hubs */
  $handler->display->display_options['fields']['field_coordination_hubs']['id'] = 'field_coordination_hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_coordination_hubs']['field'] = 'field_coordination_hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['label'] = 'Coordination hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_coordination_hubs']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_coordination_hubs']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_coordination_hubs']['bypass_access'] = 0;
  /* Field: Indexed Node: Themes */
  $handler->display->display_options['fields']['field_themes']['id'] = 'field_themes';
  $handler->display->display_options['fields']['field_themes']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_themes']['field'] = 'field_themes';
  $handler->display->display_options['fields']['field_themes']['label'] = 'Themes';
  $handler->display->display_options['fields']['field_themes']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_themes']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_themes']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_themes']['bypass_access'] = 0;
  /* Field: Indexed Node: Emergencies */
  $handler->display->display_options['fields']['field_disasters']['id'] = 'field_disasters';
  $handler->display->display_options['fields']['field_disasters']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_disasters']['field'] = 'field_disasters';
  $handler->display->display_options['fields']['field_disasters']['label'] = 'Disasters';
  $handler->display->display_options['fields']['field_disasters']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_disasters']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_disasters']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_disasters']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'node/%/contacts/csv';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'table' => 'table',
    'list' => 'list',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: XML */
  $handler = $view->new_display('views_data_export', 'XML', 'xml');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'camel';
  $handler->display->display_options['style_options']['root_node'] = 'contacts';
  $handler->display->display_options['style_options']['item_node'] = 'contact';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['label'] = 'Clusters';
  $handler->display->display_options['fields']['field_bundles']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_bundles']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_bundles']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bundles']['bypass_access'] = 0;
  /* Field: Indexed Node: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_first_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_plain';
  /* Field: Indexed Node: Phones */
  $handler->display->display_options['fields']['field_phones']['id'] = 'field_phones';
  $handler->display->display_options['fields']['field_phones']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_phones']['field'] = 'field_phones';
  $handler->display->display_options['fields']['field_phones']['click_sort_column'] = 'numbertype';
  $handler->display->display_options['fields']['field_phones']['settings'] = array(
    'components' => array(
      'country' => 0,
      'numbertype' => 0,
    ),
    'full_hcard' => 0,
    'as_tel_link' => 0,
    'raw' => 1,
    'allow_alpha' => 0,
    'country_name_position' => 'after',
    'numbertype_position' => 'before',
  );
  $handler->display->display_options['fields']['field_phones']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_phones']['separator'] = ';';
  /* Field: Indexed Node: Managed by */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = 'Organization';
  $handler->display->display_options['fields']['field_organizations']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: Job Title */
  $handler->display->display_options['fields']['field_job_title_other']['id'] = 'field_job_title_other';
  $handler->display->display_options['fields']['field_job_title_other']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_job_title_other']['field'] = 'field_job_title_other';
  /* Field: Indexed Node: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = 'Location';
  $handler->display->display_options['fields']['field_location']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_location']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_location']['bypass_access'] = 0;
  /* Field: Indexed Node: Coordination hubs */
  $handler->display->display_options['fields']['field_coordination_hubs']['id'] = 'field_coordination_hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_coordination_hubs']['field'] = 'field_coordination_hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_coordination_hubs']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_coordination_hubs']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_coordination_hubs']['bypass_access'] = 0;
  /* Field: Indexed Node: Themes */
  $handler->display->display_options['fields']['field_themes']['id'] = 'field_themes';
  $handler->display->display_options['fields']['field_themes']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_themes']['field'] = 'field_themes';
  $handler->display->display_options['fields']['field_themes']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_themes']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_themes']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_themes']['bypass_access'] = 0;
  /* Field: Indexed Node: Emergencies */
  $handler->display->display_options['fields']['field_disasters']['id'] = 'field_disasters';
  $handler->display->display_options['fields']['field_disasters']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_disasters']['field'] = 'field_disasters';
  $handler->display->display_options['fields']['field_disasters']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_disasters']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_disasters']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_disasters']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'node/%/contacts/xml';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'table' => 'table',
    'list' => 'list',
    'default' => 0,
  );
  $handler->display->display_options['segment_size'] = '100';

  /* Display: EMAILS */
  $handler = $view->new_display('views_data_export', 'EMAILS', 'emails');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'EMAILS';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'emails.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = '';
  $handler->display->display_options['style_options']['quote'] = 0;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 0;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['type'] = 'email_plain';
  $handler->display->display_options['path'] = 'node/%/contacts/emails';
  $handler->display->display_options['displays'] = array(
    'master' => 'master',
    'table' => 'table',
    'list' => 'list',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
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
    'other_lat' => 'field_location_field_geofield_lat',
    'other_lon' => 'field_location_field_geofield_lon',
    'wkt' => 'field_location_field_geofield_lon',
    'other_top' => 'field_location_field_geofield_lon',
    'other_right' => 'field_location_field_geofield_lon',
    'other_bottom' => 'field_location_field_geofield_lon',
    'other_left' => 'field_location_field_geofield_lon',
    'name_field' => 'nothing',
    'description_field' => 'field_organizations',
    'style_field' => '',
    'projection' => 'EPSG:4326',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Location » Geofield: Longitude (indexed) */
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['id'] = 'field_location_field_geofield_lon';
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['field'] = 'field_location_field_geofield_lon';
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['label'] = '';
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['precision'] = '0';
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['separator'] = '';
  $handler->display->display_options['fields']['field_location_field_geofield_lon']['link_to_entity'] = 0;
  /* Field: Location » Geofield: Latitude (indexed) */
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['id'] = 'field_location_field_geofield_lat';
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['field'] = 'field_location_field_geofield_lat';
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['label'] = '';
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['precision'] = '0';
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['separator'] = '';
  $handler->display->display_options['fields']['field_location_field_geofield_lat']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Managed by */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = '';
  $handler->display->display_options['fields']['field_organizations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organizations']['list']['mode'] = 'first';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
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
    'hr_contact' => 'hr_contact',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Contacts';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );
  /* Filter criterion: Location » Geofield: Latitude (indexed) */
  $handler->display->display_options['filters']['field_location_field_geofield_lat']['id'] = 'field_location_field_geofield_lat';
  $handler->display->display_options['filters']['field_location_field_geofield_lat']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_location_field_geofield_lat']['field'] = 'field_location_field_geofield_lat';
  $handler->display->display_options['filters']['field_location_field_geofield_lat']['operator'] = 'not empty';

  /* Display: Map */
  $handler = $view->new_display('page', 'Map', 'map');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'hr_contacts';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/contacts/map';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Graphs */
  $handler = $view->new_display('page', 'Graphs', 'graphs');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/contacts/graphs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Graphs';
  $handler->display->display_options['menu']['weight'] = '8';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Print */
  $handler = $view->new_display('page', 'Print', 'print');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['label'] = 'Clusters';
  $handler->display->display_options['fields']['field_bundles']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_bundles']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bundles']['bypass_access'] = 0;
  /* Field: Indexed Node: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_location']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_location']['bypass_access'] = 0;
  /* Field: Indexed Node: Managed by */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = 'Organization';
  $handler->display->display_options['fields']['field_organizations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_organizations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_organizations']['bypass_access'] = 0;
  /* Field: Indexed Node: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_first_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Job Title */
  $handler->display->display_options['fields']['field_job_title_other']['id'] = 'field_job_title_other';
  $handler->display->display_options['fields']['field_job_title_other']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_job_title_other']['field'] = 'field_job_title_other';
  /* Field: Indexed Node: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_plain';
  /* Field: Indexed Node: Phones */
  $handler->display->display_options['fields']['field_phones']['id'] = 'field_phones';
  $handler->display->display_options['fields']['field_phones']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_phones']['field'] = 'field_phones';
  $handler->display->display_options['fields']['field_phones']['click_sort_column'] = 'numbertype';
  $handler->display->display_options['fields']['field_phones']['settings'] = array(
    'components' => array(
      'numbertype' => 'numbertype',
      'country' => 0,
    ),
    'full_hcard' => 0,
    'as_tel_link' => 0,
    'raw' => 0,
    'allow_alpha' => 0,
    'country_name_position' => 'after',
    'numbertype_position' => 'before',
  );
  $handler->display->display_options['fields']['field_phones']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Space(s) */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  $handler->display->display_options['path'] = 'node/%/contacts/print';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['hr_contacts'] = array(
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
    t('Clusters'),
    t('First name'),
    t('Last name'),
    t('Email'),
    t('Job Title'),
    t('Organization'),
    t('Location'),
    t('All'),
    t('Search Contacts'),
    t('Table'),
    t('List'),
    t('CSV'),
    t('Phones'),
    t('Coordination hubs'),
    t('Themes'),
    t('Disasters'),
    t('XML'),
    t('Emergencies'),
    t('EMAILS'),
    t('Map data'),
    t('.'),
    t('Map'),
    t('Graphs'),
    t('Print'),
    t('Contacts'),
    t('Name'),
    t('[field_first_name] [field_last_name]'),
  );
  $export['hr_contacts'] = $view;

  $view = new view();
  $view->name = 'hr_contacts_graphs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contacts Graphs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_bundles' => array(
      'enabled' => 0,
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_bundles',
    'invert' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of contacts';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Clusters/Sectors */
  $handler->display->display_options['fields']['field_bundles']['id'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_bundles']['field'] = 'field_bundles';
  $handler->display->display_options['fields']['field_bundles']['label'] = '';
  $handler->display->display_options['fields']['field_bundles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bundles']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_bundles']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Space(s) (og_group_ref) */
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
    'hr_contact' => 'hr_contact',
  );

  /* Display: By Cluster */
  $handler = $view->new_display('block', 'By Cluster', 'by_cluster');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of contacts by cluster';
  $handler->display->display_options['block_description'] = 'Number of contacts by cluster';

  /* Display: By Organization */
  $handler = $view->new_display('block', 'By Organization', 'by_organization');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of contacts by organization';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_organizations' => array(
      'enabled' => 0,
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_organizations',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of contacts';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Field: Organization */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'field_data_field_organizations';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = '';
  $handler->display->display_options['fields']['field_organizations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organizations']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_organizations']['delta_offset'] = '0';
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
    'hr_contact' => 'hr_contact',
  );
  /* Filter criterion: Field: Organization (field_organizations) */
  $handler->display->display_options['filters']['field_organizations_target_id']['id'] = 'field_organizations_target_id';
  $handler->display->display_options['filters']['field_organizations_target_id']['table'] = 'field_data_field_organizations';
  $handler->display->display_options['filters']['field_organizations_target_id']['field'] = 'field_organizations_target_id';
  $handler->display->display_options['filters']['field_organizations_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_organizations_target_id']['shs_enabled'] = 0;
  $handler->display->display_options['block_description'] = 'Number of contacts by organization';

  /* Display: By Coordination Hub */
  $handler = $view->new_display('block', 'By Coordination Hub', 'by_coordination_hub');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of contacts by coordination hub';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_coordination_hubs' => array(
      'enabled' => 0,
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_coordination_hubs',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of contacts';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Coordination hubs */
  $handler->display->display_options['fields']['field_coordination_hubs']['id'] = 'field_coordination_hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['table'] = 'field_data_field_coordination_hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['field'] = 'field_coordination_hubs';
  $handler->display->display_options['fields']['field_coordination_hubs']['label'] = '';
  $handler->display->display_options['fields']['field_coordination_hubs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coordination_hubs']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_coordination_hubs']['delta_offset'] = '0';
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
    'hr_contact' => 'hr_contact',
  );
  /* Filter criterion: Content: Coordination hubs (field_coordination_hubs) */
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['id'] = 'field_coordination_hubs_target_id';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['table'] = 'field_data_field_coordination_hubs';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['field'] = 'field_coordination_hubs_target_id';
  $handler->display->display_options['filters']['field_coordination_hubs_target_id']['operator'] = 'not empty';
  $handler->display->display_options['block_description'] = 'Number of contacts by coordination hub';

  /* Display: By Location */
  $handler = $view->new_display('block', 'By Location', 'by_location');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of contacts by location';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_location' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_location',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Number of contacts';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['settings'] = array(
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
    'hr_contact' => 'hr_contact',
  );
  /* Filter criterion: Field: Location (field_location) */
  $handler->display->display_options['filters']['field_location_target_id']['id'] = 'field_location_target_id';
  $handler->display->display_options['filters']['field_location_target_id']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_target_id']['field'] = 'field_location_target_id';
  $handler->display->display_options['filters']['field_location_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_location_target_id']['shs_enabled'] = 0;
  $handler->display->display_options['block_description'] = 'Number of contacts by location';

  /* Display: Organizations by Type */
  $handler = $view->new_display('block', 'Organizations by Type', 'organizations_by_type');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of organizations by type';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_organizations' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_organization_type' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_organization_type',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_organizations_target_id']['id'] = 'field_organizations_target_id';
  $handler->display->display_options['relationships']['field_organizations_target_id']['table'] = 'field_data_field_organizations';
  $handler->display->display_options['relationships']['field_organizations_target_id']['field'] = 'field_organizations_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Field: Organization) */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'field_data_field_organizations';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_organizations']['label'] = '';
  $handler->display->display_options['fields']['field_organizations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organizations']['separator'] = ', ';
  /* Field: Taxonomy term: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_organizations_target_id';
  $handler->display->display_options['fields']['field_organization_type']['label'] = '';
  $handler->display->display_options['fields']['field_organization_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_type']['settings'] = array(
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
    'hr_contact' => 'hr_contact',
  );
  $handler->display->display_options['block_description'] = 'Number of organizations by type';
  $translatables['hr_contacts_graphs'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Number of contacts'),
    t('All'),
    t('By Cluster'),
    t('Number of contacts by cluster'),
    t('By Organization'),
    t('Number of contacts by organization'),
    t('By Coordination Hub'),
    t('Number of contacts by coordination hub'),
    t('By Location'),
    t('Number of contacts by location'),
    t('Organizations by Type'),
    t('Number of organizations by type'),
    t('Taxonomy term entity referenced from field_organizations'),
  );
  $export['hr_contacts_graphs'] = $view;

  $view = new view();
  $view->name = 'hr_contacts_panes';
  $view->description = '';
  $view->tag = 'Contacts';
  $view->base_table = 'node';
  $view->human_name = 'Contacts panes';
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
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
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
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Field: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_field_value']['expose']['label'] = 'Name';
  /* Contextual filter: Field: Space(s) (og_group_ref) */
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
    'hr_contact' => 'hr_contact',
  );

  /* Display: List */
  $handler = $view->new_display('panel_pane', 'List', 'list');
  $handler->display->display_options['pane_title'] = 'Dynamic';
  $handler->display->display_options['pane_category']['name'] = 'Contacts';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'og_group_ref_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Groups audience (og_group_ref)',
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Space(s) */
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
    'hr_contact' => 'hr_contact',
  );
  $translatables['hr_contacts_panes'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Post date'),
    t('Name'),
    t('All'),
    t('List'),
    t('Dynamic'),
    t('Contacts'),
    t('Entity Reference'),
    t('[title] ([og_group_ref])'),
  );
  $export['hr_contacts_panes'] = $view;

  return $export;
}
