<?php
/**
 * @file
 * hr_tools.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_tools_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_toolbox_panes';
  $view->description = '';
  $view->tag = 'tools';
  $view->base_table = 'node';
  $view->human_name = 'Toolbox Panes';
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
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_toolbox_item_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_toolbox_item_type']['id'] = 'field_toolbox_item_type';
  $handler->display->display_options['fields']['field_toolbox_item_type']['table'] = 'field_data_field_toolbox_item_type';
  $handler->display->display_options['fields']['field_toolbox_item_type']['field'] = 'field_toolbox_item_type';
  $handler->display->display_options['fields']['field_toolbox_item_type']['label'] = '';
  $handler->display->display_options['fields']['field_toolbox_item_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_toolbox_item_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Files */
  $handler->display->display_options['fields']['field_files']['id'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['table'] = 'field_data_field_files';
  $handler->display->display_options['fields']['field_files']['field'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_files']['delta_offset'] = '0';
  /* Field: Content: Links */
  $handler->display->display_options['fields']['field_links']['id'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['table'] = 'field_data_field_links';
  $handler->display->display_options['fields']['field_links']['field'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Categories (field_toolbox_categories) */
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['id'] = 'field_toolbox_categories_target_id';
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['table'] = 'field_data_field_toolbox_categories';
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['field'] = 'field_toolbox_categories_target_id';
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_toolbox_categories_target_id']['summary_options']['items_per_page'] = '25';
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
    'hr_toolbox_item' => 'hr_toolbox_item',
  );

  /* Display: Toolbox items */
  $handler = $view->new_display('panel_pane', 'Toolbox items', 'items');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_toolbox_item_type']['id'] = 'field_toolbox_item_type';
  $handler->display->display_options['fields']['field_toolbox_item_type']['table'] = 'field_data_field_toolbox_item_type';
  $handler->display->display_options['fields']['field_toolbox_item_type']['field'] = 'field_toolbox_item_type';
  $handler->display->display_options['fields']['field_toolbox_item_type']['label'] = '';
  $handler->display->display_options['fields']['field_toolbox_item_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_toolbox_item_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Icon */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Files */
  $handler->display->display_options['fields']['field_files']['id'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['table'] = 'field_data_field_files';
  $handler->display->display_options['fields']['field_files']['field'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['label'] = '';
  $handler->display->display_options['fields']['field_files']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files']['settings'] = array(
    'text' => '[file:name]',
  );
  $handler->display->display_options['fields']['field_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files']['multi_type'] = 'ul';
  /* Field: Content: Links */
  $handler->display->display_options['fields']['field_links']['id'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['table'] = 'field_data_field_links';
  $handler->display->display_options['fields']['field_links']['field'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['label'] = '';
  $handler->display->display_options['fields']['field_links']['element_label_type'] = 'h3';
  $handler->display->display_options['fields']['field_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_links']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_links']['multi_type'] = 'ul';
  $handler->display->display_options['pane_category']['name'] = 'Toolbox';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_toolbox_categories_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Categories (field_toolbox_categories)',
    ),
  );
  $translatables['hr_toolbox_panes'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Files'),
    t('Links'),
    t('All'),
    t('Toolbox items'),
    t('Toolbox'),
  );
  $export['hr_toolbox_panes'] = $view;

  return $export;
}
