<?php
/**
 * @file
 * hr_organizations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_organizations_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_organizations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Organizations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Field: Field: Acronym */
  $handler->display->display_options['fields']['field_acronym']['id'] = 'field_acronym';
  $handler->display->display_options['fields']['field_acronym']['table'] = 'field_data_field_acronym';
  $handler->display->display_options['fields']['field_acronym']['field'] = 'field_acronym';
  $handler->display->display_options['fields']['field_acronym']['label'] = '';
  $handler->display->display_options['fields']['field_acronym']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_acronym']['alter']['text'] = '[[field_acronym]]';
  $handler->display->display_options['fields']['field_acronym']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_acronym']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_acronym']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_acronym']['type'] = 'text_plain';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'hr_organization' => 'hr_organization',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_acronym' => 'field_acronym',
    'name_field' => 'name_field',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name_field' => 'name_field',
    'field_acronym' => 'field_acronym',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_acronym' => array(
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'You can\'t find your organization in HumanitarianResposne.info ? Fill in <a href="/help/add-new-organization">this form</a> and we will get back to you!';
  $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'ID';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Acronym */
  $handler->display->display_options['fields']['field_acronym']['id'] = 'field_acronym';
  $handler->display->display_options['fields']['field_acronym']['table'] = 'field_data_field_acronym';
  $handler->display->display_options['fields']['field_acronym']['field'] = 'field_acronym';
  $handler->display->display_options['fields']['field_acronym']['alter']['text'] = '[[field_acronym]]';
  $handler->display->display_options['fields']['field_acronym']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_acronym']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_acronym']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_acronym']['type'] = 'text_plain';
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_url';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'hr_organization' => 'hr_organization',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );
  /* Filter criterion: Taxonomy term: Type (field_organization_type) (reference filter) */
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['id'] = 'field_organization_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['field'] = 'field_organization_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['operator_id'] = 'field_organization_type_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['operator'] = 'field_organization_type_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['identifier'] = 'field_organization_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['reference_display'] = 'hr_organizations:org_types';
  /* Filter criterion: Field: Acronym (field_acronym) */
  $handler->display->display_options['filters']['field_acronym_value']['id'] = 'field_acronym_value';
  $handler->display->display_options['filters']['field_acronym_value']['table'] = 'field_data_field_acronym';
  $handler->display->display_options['filters']['field_acronym_value']['field'] = 'field_acronym_value';
  $handler->display->display_options['filters']['field_acronym_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_acronym_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_acronym_value']['expose']['operator_id'] = 'field_acronym_value_op';
  $handler->display->display_options['filters']['field_acronym_value']['expose']['label'] = 'Acronym';
  $handler->display->display_options['filters']['field_acronym_value']['expose']['operator'] = 'field_acronym_value_op';
  $handler->display->display_options['filters']['field_acronym_value']['expose']['identifier'] = 'field_acronym_value';
  $handler->display->display_options['filters']['field_acronym_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );
  $handler->display->display_options['path'] = 'organizations';

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'csv');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'ID';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Acronym */
  $handler->display->display_options['fields']['field_acronym']['id'] = 'field_acronym';
  $handler->display->display_options['fields']['field_acronym']['table'] = 'field_data_field_acronym';
  $handler->display->display_options['fields']['field_acronym']['field'] = 'field_acronym';
  $handler->display->display_options['fields']['field_acronym']['alter']['text'] = '[[field_acronym]]';
  $handler->display->display_options['fields']['field_acronym']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_acronym']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_acronym']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_acronym']['type'] = 'text_plain';
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'hr_organization' => 'hr_organization',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );
  /* Filter criterion: Taxonomy term: Type (field_organization_type) (reference filter) */
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['id'] = 'field_organization_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['field'] = 'field_organization_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['operator_id'] = 'field_organization_type_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['operator'] = 'field_organization_type_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['identifier'] = 'field_organization_type_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    218860149 => 0,
    188284353 => 0,
    235660466 => 0,
  );
  $handler->display->display_options['filters']['field_organization_type_target_id_entityreference_filter']['reference_display'] = 'hr_organizations:org_types';
  $handler->display->display_options['path'] = 'organizations/csv';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Org types */
  $handler = $view->new_display('entityreference', 'Org types', 'org_types');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name_field' => 'name_field',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'hr_organization_type' => 'hr_organization_type',
  );
  $translatables['hr_organizations'] = array(
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
    t('[[field_acronym]]'),
    t('Entity Reference'),
    t('Page'),
    t('You can\'t find your organization in HumanitarianResposne.info ? Fill in <a href="/help/add-new-organization">this form</a> and we will get back to you!'),
    t('ID'),
    t('.'),
    t('Name'),
    t('Type'),
    t('Acronym'),
    t('Website'),
    t('CSV'),
    t('Org types'),
  );
  $export['hr_organizations'] = $view;

  return $export;
}
