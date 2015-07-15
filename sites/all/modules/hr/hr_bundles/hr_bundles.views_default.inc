<?php
/**
 * @file
 * hr_bundles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_bundles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_bundles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bundles';
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
      'field' => 'field_sector',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['empty'] = '[path]';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_absolute';
  /* Field: Content: Space(s) */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['og_group_ref']['alter']['path'] = '[field_website]';
  $handler->display->display_options['fields']['og_group_ref']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Content: Global Cluster */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['label'] = '';
  $handler->display->display_options['fields']['field_sector']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sector']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Global Cluster (field_sector) */
  $handler->display->display_options['sorts']['field_sector_target_id']['id'] = 'field_sector_target_id';
  $handler->display->display_options['sorts']['field_sector_target_id']['table'] = 'field_data_field_sector';
  $handler->display->display_options['sorts']['field_sector_target_id']['field'] = 'field_sector_target_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'og_membership_related_node_group';
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
    'hr_bundle' => 'hr_bundle',
  );
  /* Filter criterion: Content: Type (field_bundle_type) */
  $handler->display->display_options['filters']['field_bundle_type_value']['id'] = 'field_bundle_type_value';
  $handler->display->display_options['filters']['field_bundle_type_value']['table'] = 'field_data_field_bundle_type';
  $handler->display->display_options['filters']['field_bundle_type_value']['field'] = 'field_bundle_type_value';
  $handler->display->display_options['filters']['field_bundle_type_value']['value'] = array(
    'cluster' => 'cluster',
  );

  /* Display: GeoJSON */
  $handler = $view->new_display('page', 'GeoJSON', 'geojson');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'wkt';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_geofield';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_geofield';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title_field';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'nothing';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_country_target_id']['id'] = 'field_country_target_id';
  $handler->display->display_options['relationships']['field_country_target_id']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_target_id']['field'] = 'field_country_target_id';
  $handler->display->display_options['relationships']['field_country_target_id']['relationship'] = 'og_membership_related_node_group';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_sector_target_id']['id'] = 'field_sector_target_id';
  $handler->display->display_options['relationships']['field_sector_target_id']['table'] = 'field_data_field_sector';
  $handler->display->display_options['relationships']['field_sector_target_id']['field'] = 'field_sector_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['empty'] = '[path]';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_website]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[title_field] ([title])';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Geofield */
  $handler->display->display_options['fields']['field_geofield']['id'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['relationship'] = 'field_country_target_id';
  $handler->display->display_options['fields']['field_geofield']['label'] = '';
  $handler->display->display_options['fields']['field_geofield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Field: Organization */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'field_data_field_organizations';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = 'Lead Agencies';
  $handler->display->display_options['fields']['field_organizations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organizations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organizations']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_organizations']['delta_offset'] = '0';
  /* Field: Content: Partners */
  $handler->display->display_options['fields']['field_partners']['id'] = 'field_partners';
  $handler->display->display_options['fields']['field_partners']['table'] = 'field_data_field_partners';
  $handler->display->display_options['fields']['field_partners']['field'] = 'field_partners';
  $handler->display->display_options['fields']['field_partners']['alter']['text'] = 'Lead Agencies: [field_organizations]<br />
Co-leads: [field_partners]';
  $handler->display->display_options['fields']['field_partners']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_partners']['delta_offset'] = '0';
  /* Field: Content: Activation Document */
  $handler->display->display_options['fields']['field_activation_document']['id'] = 'field_activation_document';
  $handler->display->display_options['fields']['field_activation_document']['table'] = 'field_data_field_activation_document';
  $handler->display->display_options['fields']['field_activation_document']['field'] = 'field_activation_document';
  $handler->display->display_options['fields']['field_activation_document']['label'] = '';
  $handler->display->display_options['fields']['field_activation_document']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_activation_document']['alter']['path'] = 'node/[field_activation_document-target_id]';
  $handler->display->display_options['fields']['field_activation_document']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_activation_document']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activation_document']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_activation_document']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Cluster coordinators */
  $handler->display->display_options['fields']['field_cluster_coordinators']['id'] = 'field_cluster_coordinators';
  $handler->display->display_options['fields']['field_cluster_coordinators']['table'] = 'field_data_field_cluster_coordinators';
  $handler->display->display_options['fields']['field_cluster_coordinators']['field'] = 'field_cluster_coordinators';
  $handler->display->display_options['fields']['field_cluster_coordinators']['label'] = '';
  $handler->display->display_options['fields']['field_cluster_coordinators']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cluster_coordinators']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_cluster_coordinators']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_cluster_coordinators']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cluster_coordinators']['multi_type'] = 'ul';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Lead Agencies</strong>: [field_organizations]<br />
<strong>Co-leads</strong>: [field_partners]<br />
<strong>Activation document</strong>: [field_activation_document]<br />
<strong>Cluster coordinators</strong>: [field_cluster_coordinators]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Acronym (field_acronym) */
  $handler->display->display_options['arguments']['field_acronym_value']['id'] = 'field_acronym_value';
  $handler->display->display_options['arguments']['field_acronym_value']['table'] = 'field_data_field_acronym';
  $handler->display->display_options['arguments']['field_acronym_value']['field'] = 'field_acronym_value';
  $handler->display->display_options['arguments']['field_acronym_value']['relationship'] = 'field_sector_target_id';
  $handler->display->display_options['arguments']['field_acronym_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_acronym_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_acronym_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_acronym_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_acronym_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_acronym_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_acronym_value']['case'] = 'upper';
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
    'hr_bundle' => 'hr_bundle',
  );
  /* Filter criterion: Content: Type (field_bundle_type) */
  $handler->display->display_options['filters']['field_bundle_type_value']['id'] = 'field_bundle_type_value';
  $handler->display->display_options['filters']['field_bundle_type_value']['table'] = 'field_data_field_bundle_type';
  $handler->display->display_options['filters']['field_bundle_type_value']['field'] = 'field_bundle_type_value';
  $handler->display->display_options['filters']['field_bundle_type_value']['value'] = array(
    'aor' => 'aor',
    'cluster' => 'cluster',
  );
  /* Filter criterion: Content: Country (field_country) */
  $handler->display->display_options['filters']['field_country_target_id']['id'] = 'field_country_target_id';
  $handler->display->display_options['filters']['field_country_target_id']['table'] = 'field_data_field_country';
  $handler->display->display_options['filters']['field_country_target_id']['field'] = 'field_country_target_id';
  $handler->display->display_options['filters']['field_country_target_id']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['field_country_target_id']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'clusters/countries/geojson/%';

  /* Display: GeoJSON Sectors */
  $handler = $view->new_display('page', 'GeoJSON Sectors', 'page_1');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'wkt';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_geofield';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_geofield';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title_field';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'nothing';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_country_target_id']['id'] = 'field_country_target_id';
  $handler->display->display_options['relationships']['field_country_target_id']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_target_id']['field'] = 'field_country_target_id';
  $handler->display->display_options['relationships']['field_country_target_id']['relationship'] = 'og_membership_related_node_group';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_sector_target_id']['id'] = 'field_sector_target_id';
  $handler->display->display_options['relationships']['field_sector_target_id']['table'] = 'field_data_field_sector';
  $handler->display->display_options['relationships']['field_sector_target_id']['field'] = 'field_sector_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['empty'] = '[path]';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_website]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[title_field] ([title])';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Geofield */
  $handler->display->display_options['fields']['field_geofield']['id'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield']['relationship'] = 'field_country_target_id';
  $handler->display->display_options['fields']['field_geofield']['label'] = '';
  $handler->display->display_options['fields']['field_geofield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Field: Organization */
  $handler->display->display_options['fields']['field_organizations']['id'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['table'] = 'field_data_field_organizations';
  $handler->display->display_options['fields']['field_organizations']['field'] = 'field_organizations';
  $handler->display->display_options['fields']['field_organizations']['label'] = 'Lead Agencies';
  $handler->display->display_options['fields']['field_organizations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organizations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organizations']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_organizations']['delta_offset'] = '0';
  /* Field: Content: Partners */
  $handler->display->display_options['fields']['field_partners']['id'] = 'field_partners';
  $handler->display->display_options['fields']['field_partners']['table'] = 'field_data_field_partners';
  $handler->display->display_options['fields']['field_partners']['field'] = 'field_partners';
  $handler->display->display_options['fields']['field_partners']['alter']['text'] = 'Lead Agencies: [field_organizations]<br />
Co-leads: [field_partners]';
  $handler->display->display_options['fields']['field_partners']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_partners']['delta_offset'] = '0';
  /* Field: Content: Activation Document */
  $handler->display->display_options['fields']['field_activation_document']['id'] = 'field_activation_document';
  $handler->display->display_options['fields']['field_activation_document']['table'] = 'field_data_field_activation_document';
  $handler->display->display_options['fields']['field_activation_document']['field'] = 'field_activation_document';
  $handler->display->display_options['fields']['field_activation_document']['label'] = '';
  $handler->display->display_options['fields']['field_activation_document']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_activation_document']['alter']['path'] = 'node/[field_activation_document-target_id]';
  $handler->display->display_options['fields']['field_activation_document']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_activation_document']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activation_document']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_activation_document']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Cluster coordinators */
  $handler->display->display_options['fields']['field_cluster_coordinators']['id'] = 'field_cluster_coordinators';
  $handler->display->display_options['fields']['field_cluster_coordinators']['table'] = 'field_data_field_cluster_coordinators';
  $handler->display->display_options['fields']['field_cluster_coordinators']['field'] = 'field_cluster_coordinators';
  $handler->display->display_options['fields']['field_cluster_coordinators']['label'] = '';
  $handler->display->display_options['fields']['field_cluster_coordinators']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cluster_coordinators']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_cluster_coordinators']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_cluster_coordinators']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cluster_coordinators']['multi_type'] = 'ul';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Lead Agencies</strong>: [field_organizations]<br />
<strong>Co-leads</strong>: [field_partners]<br />
<strong>Activation document</strong>: [field_activation_document]<br />
<strong>Cluster coordinators</strong>: [field_cluster_coordinators]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Acronym (field_acronym) */
  $handler->display->display_options['arguments']['field_acronym_value']['id'] = 'field_acronym_value';
  $handler->display->display_options['arguments']['field_acronym_value']['table'] = 'field_data_field_acronym';
  $handler->display->display_options['arguments']['field_acronym_value']['field'] = 'field_acronym_value';
  $handler->display->display_options['arguments']['field_acronym_value']['relationship'] = 'field_sector_target_id';
  $handler->display->display_options['arguments']['field_acronym_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_acronym_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_acronym_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_acronym_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_acronym_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_acronym_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_acronym_value']['case'] = 'upper';
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
    'hr_bundle' => 'hr_bundle',
  );
  /* Filter criterion: Content: Type (field_bundle_type) */
  $handler->display->display_options['filters']['field_bundle_type_value']['id'] = 'field_bundle_type_value';
  $handler->display->display_options['filters']['field_bundle_type_value']['table'] = 'field_data_field_bundle_type';
  $handler->display->display_options['filters']['field_bundle_type_value']['field'] = 'field_bundle_type_value';
  $handler->display->display_options['filters']['field_bundle_type_value']['value'] = array(
    'sector' => 'sector',
  );
  /* Filter criterion: Content: Country (field_country) */
  $handler->display->display_options['filters']['field_country_target_id']['id'] = 'field_country_target_id';
  $handler->display->display_options['filters']['field_country_target_id']['table'] = 'field_data_field_country';
  $handler->display->display_options['filters']['field_country_target_id']['field'] = 'field_country_target_id';
  $handler->display->display_options['filters']['field_country_target_id']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['field_country_target_id']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'sectors/countries/geojson/%';

  /* Display: Text */
  $handler = $view->new_display('panel_pane', 'Text', 'text');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-catgroup';

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
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([og_group_ref])';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Space(s) (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'fixed';
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
    'hr_bundle' => 'hr_bundle',
  );
  $translatables['hr_bundles'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Group node from OG membership'),
    t('[path]'),
    t('GeoJSON'),
    t('Taxonomy term entity referenced from field_country'),
    t('Content entity referenced from field_sector'),
    t('[title_field] ([title])'),
    t('Lead Agencies'),
    t('Partners'),
    t('Lead Agencies: [field_organizations]<br />
Co-leads: [field_partners]'),
    t('<strong>Lead Agencies</strong>: [field_organizations]<br />
<strong>Co-leads</strong>: [field_partners]<br />
<strong>Activation document</strong>: [field_activation_document]<br />
<strong>Cluster coordinators</strong>: [field_cluster_coordinators]'),
    t('All'),
    t('GeoJSON Sectors'),
    t('Text'),
    t('View panes'),
    t('Entity Reference'),
    t('[title] ([og_group_ref])'),
  );
  $export['hr_bundles'] = $view;

  return $export;
}
