<?php
/**
 * @file
 * hr_indicators.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_indicators_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_indicators';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Indicators';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_sectors' => 'field_sectors',
    'field_ind_code' => 'field_ind_code',
    'field_ind_domain' => 'field_ind_domain',
    'title' => 'title',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_sectors' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ind_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ind_domain' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Indexed Node: Global Clusters */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sectors']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_sectors']['bypass_access'] = 0;
  /* Field: Indexed Node: Code */
  $handler->display->display_options['fields']['field_ind_code']['id'] = 'field_ind_code';
  $handler->display->display_options['fields']['field_ind_code']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_code']['field'] = 'field_ind_code';
  /* Field: Indexed Node: Sub-domain */
  $handler->display->display_options['fields']['field_ind_domain']['id'] = 'field_ind_domain';
  $handler->display->display_options['fields']['field_ind_domain']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_domain']['field'] = 'field_ind_domain';
  $handler->display->display_options['fields']['field_ind_domain']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_domain']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_domain']['bypass_access'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Indexed Node: Code */
  $handler->display->display_options['sorts']['field_ind_code']['id'] = 'field_ind_code';
  $handler->display->display_options['sorts']['field_ind_code']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_ind_code']['field'] = 'field_ind_code';
  /* Contextual filter: Indexed Node: Space(s) */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_indicator' => 'hr_indicator',
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
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Indicators';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/indicators';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: XLS */
  $handler = $view->new_display('views_data_export', 'XLS', 'xls');
  $handler->display->display_options['link_url'] = 'test/indicators';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Global Clusters */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_sectors']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sectors']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_sectors']['bypass_access'] = 0;
  /* Field: Indexed Node: Code */
  $handler->display->display_options['fields']['field_ind_code']['id'] = 'field_ind_code';
  $handler->display->display_options['fields']['field_ind_code']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_code']['field'] = 'field_ind_code';
  /* Field: Indexed Node: Sub-domain */
  $handler->display->display_options['fields']['field_ind_domain']['id'] = 'field_ind_domain';
  $handler->display->display_options['fields']['field_ind_domain']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_domain']['field'] = 'field_ind_domain';
  $handler->display->display_options['fields']['field_ind_domain']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_domain']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_domain']['bypass_access'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Indexed Node: Unit of Measurement */
  $handler->display->display_options['fields']['field_ind_unit']['id'] = 'field_ind_unit';
  $handler->display->display_options['fields']['field_ind_unit']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_unit']['field'] = 'field_ind_unit';
  $handler->display->display_options['fields']['field_ind_unit']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_unit']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_unit']['bypass_access'] = 0;
  /* Field: Indexed Node: Unit Description */
  $handler->display->display_options['fields']['field_ind_unit_desc']['id'] = 'field_ind_unit_desc';
  $handler->display->display_options['fields']['field_ind_unit_desc']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_unit_desc']['field'] = 'field_ind_unit_desc';
  /* Field: Indexed Node: Denominator */
  $handler->display->display_options['fields']['field_ind_denominator']['id'] = 'field_ind_denominator';
  $handler->display->display_options['fields']['field_ind_denominator']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_denominator']['field'] = 'field_ind_denominator';
  /* Field: Indexed Node: Numerator */
  $handler->display->display_options['fields']['field_ind_numerator']['id'] = 'field_ind_numerator';
  $handler->display->display_options['fields']['field_ind_numerator']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_numerator']['field'] = 'field_ind_numerator';
  /* Field: Indexed Node: Disaggregation */
  $handler->display->display_options['fields']['field_ind_disaggregation']['id'] = 'field_ind_disaggregation';
  $handler->display->display_options['fields']['field_ind_disaggregation']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_disaggregation']['field'] = 'field_ind_disaggregation';
  /* Field: Indexed Node: Key indicator */
  $handler->display->display_options['fields']['field_ind_key']['id'] = 'field_ind_key';
  $handler->display->display_options['fields']['field_ind_key']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_key']['field'] = 'field_ind_key';
  /* Field: Indexed Node: Types */
  $handler->display->display_options['fields']['field_ind_types']['id'] = 'field_ind_types';
  $handler->display->display_options['fields']['field_ind_types']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_types']['field'] = 'field_ind_types';
  $handler->display->display_options['fields']['field_ind_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Indicator used for response monitoring ? */
  $handler->display->display_options['fields']['field_ind_response']['id'] = 'field_ind_response';
  $handler->display->display_options['fields']['field_ind_response']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_response']['field'] = 'field_ind_response';
  $handler->display->display_options['fields']['field_ind_response']['label'] = 'Response Monitoring';
  /* Field: Indexed Node: Standards */
  $handler->display->display_options['fields']['field_ind_standards']['id'] = 'field_ind_standards';
  $handler->display->display_options['fields']['field_ind_standards']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_standards']['field'] = 'field_ind_standards';
  $handler->display->display_options['fields']['field_ind_standards']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_standards']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_standards']['bypass_access'] = 0;
  /* Field: Indexed Node: Threshold / Standard */
  $handler->display->display_options['fields']['field_ind_threshold']['id'] = 'field_ind_threshold';
  $handler->display->display_options['fields']['field_ind_threshold']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_threshold']['field'] = 'field_ind_threshold';
  $handler->display->display_options['fields']['field_ind_threshold']['label'] = 'Threshold';
  /* Field: Indexed Node: Guidance on phases */
  $handler->display->display_options['fields']['field_ind_guidance_phases']['id'] = 'field_ind_guidance_phases';
  $handler->display->display_options['fields']['field_ind_guidance_phases']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_guidance_phases']['field'] = 'field_ind_guidance_phases';
  /* Field: Indexed Node: Phase applicability */
  $handler->display->display_options['fields']['field_ind_phase_applicability']['id'] = 'field_ind_phase_applicability';
  $handler->display->display_options['fields']['field_ind_phase_applicability']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_phase_applicability']['field'] = 'field_ind_phase_applicability';
  $handler->display->display_options['fields']['field_ind_phase_applicability']['delta_offset'] = '0';
  /* Field: Indexed Node: General guidance */
  $handler->display->display_options['fields']['field_ind_general_guidance']['id'] = 'field_ind_general_guidance';
  $handler->display->display_options['fields']['field_ind_general_guidance']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_general_guidance']['field'] = 'field_ind_general_guidance';
  /* Field: Indexed Node: Guidance for pre-crisis/baseline */
  $handler->display->display_options['fields']['field_ind_guidance_baseline']['id'] = 'field_ind_guidance_baseline';
  $handler->display->display_options['fields']['field_ind_guidance_baseline']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_guidance_baseline']['field'] = 'field_ind_guidance_baseline';
  /* Field: Indexed Node: Comments */
  $handler->display->display_options['fields']['field_ind_comments']['id'] = 'field_ind_comments';
  $handler->display->display_options['fields']['field_ind_comments']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_comments']['field'] = 'field_ind_comments';
  /* Field: Indexed Node: Data Sources */
  $handler->display->display_options['fields']['field_ind_data_sources']['id'] = 'field_ind_data_sources';
  $handler->display->display_options['fields']['field_ind_data_sources']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_data_sources']['field'] = 'field_ind_data_sources';
  /* Field: Indexed Node: Sector cross-tagging */
  $handler->display->display_options['fields']['field_ind_cross_tagging']['id'] = 'field_ind_cross_tagging';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['field'] = 'field_ind_cross_tagging';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_cross_tagging']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['bypass_access'] = 0;
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
  $handler->display->display_options['path'] = 'node/%/indicators/xls';
  $handler->display->display_options['displays'] = array(
    'table' => 'table',
    'default' => 0,
  );
  $handler->display->display_options['segment_size'] = '100';

  /* Display: XML */
  $handler = $view->new_display('views_data_export', 'XML', 'xml');
  $handler->display->display_options['link_url'] = 'test/indicators';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'pascal';
  $handler->display->display_options['style_options']['root_node'] = 'indicators';
  $handler->display->display_options['style_options']['item_node'] = 'indicator';
  $handler->display->display_options['style_options']['cdata_wrapper'] = array(
    'body' => 'body',
    'field_ind_unit_desc' => 'field_ind_unit_desc',
    'field_ind_guidance_phases' => 'field_ind_guidance_phases',
    'field_ind_general_guidance' => 'field_ind_general_guidance',
    'field_ind_guidance_baseline' => 'field_ind_guidance_baseline',
    'field_ind_comments' => 'field_ind_comments',
    'field_ind_data_sources' => 'field_ind_data_sources',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Global Clusters */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['label'] = 'Clusters';
  $handler->display->display_options['fields']['field_sectors']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sectors']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_sectors']['bypass_access'] = 0;
  /* Field: Indexed Node: Code */
  $handler->display->display_options['fields']['field_ind_code']['id'] = 'field_ind_code';
  $handler->display->display_options['fields']['field_ind_code']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_code']['field'] = 'field_ind_code';
  /* Field: Indexed Node: Sub-domain */
  $handler->display->display_options['fields']['field_ind_domain']['id'] = 'field_ind_domain';
  $handler->display->display_options['fields']['field_ind_domain']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_domain']['field'] = 'field_ind_domain';
  $handler->display->display_options['fields']['field_ind_domain']['label'] = 'Sub Domain';
  $handler->display->display_options['fields']['field_ind_domain']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_domain']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_domain']['bypass_access'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Indexed Node: Unit of Measurement */
  $handler->display->display_options['fields']['field_ind_unit']['id'] = 'field_ind_unit';
  $handler->display->display_options['fields']['field_ind_unit']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_unit']['field'] = 'field_ind_unit';
  $handler->display->display_options['fields']['field_ind_unit']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_unit']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_unit']['bypass_access'] = 0;
  /* Field: Indexed Node: Unit Description */
  $handler->display->display_options['fields']['field_ind_unit_desc']['id'] = 'field_ind_unit_desc';
  $handler->display->display_options['fields']['field_ind_unit_desc']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_unit_desc']['field'] = 'field_ind_unit_desc';
  /* Field: Indexed Node: Denominator */
  $handler->display->display_options['fields']['field_ind_denominator']['id'] = 'field_ind_denominator';
  $handler->display->display_options['fields']['field_ind_denominator']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_denominator']['field'] = 'field_ind_denominator';
  /* Field: Indexed Node: Numerator */
  $handler->display->display_options['fields']['field_ind_numerator']['id'] = 'field_ind_numerator';
  $handler->display->display_options['fields']['field_ind_numerator']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_numerator']['field'] = 'field_ind_numerator';
  /* Field: Indexed Node: Disaggregation */
  $handler->display->display_options['fields']['field_ind_disaggregation']['id'] = 'field_ind_disaggregation';
  $handler->display->display_options['fields']['field_ind_disaggregation']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_disaggregation']['field'] = 'field_ind_disaggregation';
  /* Field: Indexed Node: Key indicator */
  $handler->display->display_options['fields']['field_ind_key']['id'] = 'field_ind_key';
  $handler->display->display_options['fields']['field_ind_key']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_key']['field'] = 'field_ind_key';
  /* Field: Indexed Node: Types */
  $handler->display->display_options['fields']['field_ind_types']['id'] = 'field_ind_types';
  $handler->display->display_options['fields']['field_ind_types']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_types']['field'] = 'field_ind_types';
  $handler->display->display_options['fields']['field_ind_types']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_types']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_types']['bypass_access'] = 0;
  /* Field: Indexed Node: Indicator used for response monitoring ? */
  $handler->display->display_options['fields']['field_ind_response']['id'] = 'field_ind_response';
  $handler->display->display_options['fields']['field_ind_response']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_response']['field'] = 'field_ind_response';
  $handler->display->display_options['fields']['field_ind_response']['label'] = 'Response Monitoring';
  /* Field: Indexed Node: Standards */
  $handler->display->display_options['fields']['field_ind_standards']['id'] = 'field_ind_standards';
  $handler->display->display_options['fields']['field_ind_standards']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_standards']['field'] = 'field_ind_standards';
  $handler->display->display_options['fields']['field_ind_standards']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_standards']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_standards']['bypass_access'] = 0;
  /* Field: Indexed Node: Threshold / Standard */
  $handler->display->display_options['fields']['field_ind_threshold']['id'] = 'field_ind_threshold';
  $handler->display->display_options['fields']['field_ind_threshold']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_threshold']['field'] = 'field_ind_threshold';
  $handler->display->display_options['fields']['field_ind_threshold']['label'] = 'Threshold';
  /* Field: Indexed Node: Guidance on phases */
  $handler->display->display_options['fields']['field_ind_guidance_phases']['id'] = 'field_ind_guidance_phases';
  $handler->display->display_options['fields']['field_ind_guidance_phases']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_guidance_phases']['field'] = 'field_ind_guidance_phases';
  /* Field: Indexed Node: Phase applicability */
  $handler->display->display_options['fields']['field_ind_phase_applicability']['id'] = 'field_ind_phase_applicability';
  $handler->display->display_options['fields']['field_ind_phase_applicability']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_phase_applicability']['field'] = 'field_ind_phase_applicability';
  $handler->display->display_options['fields']['field_ind_phase_applicability']['delta_offset'] = '0';
  /* Field: Indexed Node: General guidance */
  $handler->display->display_options['fields']['field_ind_general_guidance']['id'] = 'field_ind_general_guidance';
  $handler->display->display_options['fields']['field_ind_general_guidance']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_general_guidance']['field'] = 'field_ind_general_guidance';
  /* Field: Indexed Node: Guidance for pre-crisis/baseline */
  $handler->display->display_options['fields']['field_ind_guidance_baseline']['id'] = 'field_ind_guidance_baseline';
  $handler->display->display_options['fields']['field_ind_guidance_baseline']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_guidance_baseline']['field'] = 'field_ind_guidance_baseline';
  $handler->display->display_options['fields']['field_ind_guidance_baseline']['label'] = 'Guidance for pre crisis';
  /* Field: Indexed Node: Comments */
  $handler->display->display_options['fields']['field_ind_comments']['id'] = 'field_ind_comments';
  $handler->display->display_options['fields']['field_ind_comments']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_comments']['field'] = 'field_ind_comments';
  /* Field: Indexed Node: Data Sources */
  $handler->display->display_options['fields']['field_ind_data_sources']['id'] = 'field_ind_data_sources';
  $handler->display->display_options['fields']['field_ind_data_sources']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_data_sources']['field'] = 'field_ind_data_sources';
  /* Field: Indexed Node: Sector cross-tagging */
  $handler->display->display_options['fields']['field_ind_cross_tagging']['id'] = 'field_ind_cross_tagging';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['field'] = 'field_ind_cross_tagging';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['label'] = 'Sector cross tagging';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_ind_cross_tagging']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ind_cross_tagging']['bypass_access'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'GUID';
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
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
  $handler->display->display_options['path'] = 'node/%/indicators/xml';
  $handler->display->display_options['displays'] = array(
    'table' => 'table',
    'default' => 0,
  );
  $handler->display->display_options['segment_size'] = '100';
  $translatables['hr_indicators'] = array(
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
    t('Global Clusters'),
    t('Code'),
    t('Sub-domain'),
    t('Title'),
    t('Description'),
    t('All'),
    t('Search Indicators'),
    t('Table'),
    t('XLS'),
    t('Unit of Measurement'),
    t('Unit Description'),
    t('Denominator'),
    t('Numerator'),
    t('Disaggregation'),
    t('Key indicator'),
    t('Types'),
    t('Response Monitoring'),
    t('Standards'),
    t('Threshold'),
    t('Guidance on phases'),
    t('Phase applicability'),
    t('General guidance'),
    t('Guidance for pre-crisis/baseline'),
    t('Comments'),
    t('Data Sources'),
    t('Sector cross-tagging'),
    t('XML'),
    t('Clusters'),
    t('Sub Domain'),
    t('Guidance for pre crisis'),
    t('Sector cross tagging'),
    t('GUID'),
  );
  $export['hr_indicators'] = $view;

  return $export;
}
