<?php
/**
 * @file
 * hr_news.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_news_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_news:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_news';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_bryant_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '707fb154-7b94-4a2b-bd01-86c565f71064';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3a6e0690-0615-45ee-a20a-19dd1c5ada3c';
    $pane->panel = 'contentmain';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3a6e0690-0615-45ee-a20a-19dd1c5ada3c';
    $display->content['new-3a6e0690-0615-45ee-a20a-19dd1c5ada3c'] = $pane;
    $display->panels['contentmain'][0] = 'new-3a6e0690-0615-45ee-a20a-19dd1c5ada3c';
    $pane = new stdClass();
    $pane->pid = 'new-86659990-3303-44cc-8516-b81b502f33c0';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:hr_core_share_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '86659990-3303-44cc-8516-b81b502f33c0';
    $display->content['new-86659990-3303-44cc-8516-b81b502f33c0'] = $pane;
    $display->panels['contentmain'][1] = 'new-86659990-3303-44cc-8516-b81b502f33c0';
    $pane = new stdClass();
    $pane->pid = 'new-a1c17d5f-7d03-415c-8cb3-27fc5ed16fd0';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a1c17d5f-7d03-415c-8cb3-27fc5ed16fd0';
    $display->content['new-a1c17d5f-7d03-415c-8cb3-27fc5ed16fd0'] = $pane;
    $display->panels['contentmain'][2] = 'new-a1c17d5f-7d03-415c-8cb3-27fc5ed16fd0';
    $pane = new stdClass();
    $pane->pid = 'new-e1b34355-54b1-44b1-8eb8-df9986e5ab7d';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:og_group_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e1b34355-54b1-44b1-8eb8-df9986e5ab7d';
    $display->content['new-e1b34355-54b1-44b1-8eb8-df9986e5ab7d'] = $pane;
    $display->panels['sidebar'][0] = 'new-e1b34355-54b1-44b1-8eb8-df9986e5ab7d';
    $pane = new stdClass();
    $pane->pid = 'new-ddfc388d-c162-4bb0-ab61-4a718a8a648f';
    $pane->panel = 'sidebar';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ddfc388d-c162-4bb0-ab61-4a718a8a648f';
    $display->content['new-ddfc388d-c162-4bb0-ab61-4a718a8a648f'] = $pane;
    $display->panels['sidebar'][1] = 'new-ddfc388d-c162-4bb0-ab61-4a718a8a648f';
    $pane = new stdClass();
    $pane->pid = 'new-3c2b415a-2eeb-433a-a091-25b3c2566652';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_organizations';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3c2b415a-2eeb-433a-a091-25b3c2566652';
    $display->content['new-3c2b415a-2eeb-433a-a091-25b3c2566652'] = $pane;
    $display->panels['sidebar'][2] = 'new-3c2b415a-2eeb-433a-a091-25b3c2566652';
    $pane = new stdClass();
    $pane->pid = 'new-d556d7ad-551a-423c-a9ec-6f1c6a2d3e0b';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_sectors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd556d7ad-551a-423c-a9ec-6f1c6a2d3e0b';
    $display->content['new-d556d7ad-551a-423c-a9ec-6f1c6a2d3e0b'] = $pane;
    $display->panels['sidebar'][3] = 'new-d556d7ad-551a-423c-a9ec-6f1c6a2d3e0b';
    $pane = new stdClass();
    $pane->pid = 'new-75cc2542-9538-4f5c-8f59-0a52aaa429b8';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_bundles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '75cc2542-9538-4f5c-8f59-0a52aaa429b8';
    $display->content['new-75cc2542-9538-4f5c-8f59-0a52aaa429b8'] = $pane;
    $display->panels['sidebar'][4] = 'new-75cc2542-9538-4f5c-8f59-0a52aaa429b8';
    $pane = new stdClass();
    $pane->pid = 'new-f326b1d6-f207-402d-b037-9b6ed81bc022';
    $pane->panel = 'sidebar';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'hr_1',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'f326b1d6-f207-402d-b037-9b6ed81bc022';
    $display->content['new-f326b1d6-f207-402d-b037-9b6ed81bc022'] = $pane;
    $display->panels['sidebar'][5] = 'new-f326b1d6-f207-402d-b037-9b6ed81bc022';
    $pane = new stdClass();
    $pane->pid = 'new-61dff246-cb8c-4e21-a9cc-d7cd91940e98';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_locations';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '61dff246-cb8c-4e21-a9cc-d7cd91940e98';
    $display->content['new-61dff246-cb8c-4e21-a9cc-d7cd91940e98'] = $pane;
    $display->panels['sidebar'][6] = 'new-61dff246-cb8c-4e21-a9cc-d7cd91940e98';
    $pane = new stdClass();
    $pane->pid = 'new-d87de19e-dd69-4a39-9c26-e3e67f133357';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_themes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'd87de19e-dd69-4a39-9c26-e3e67f133357';
    $display->content['new-d87de19e-dd69-4a39-9c26-e3e67f133357'] = $pane;
    $display->panels['sidebar'][7] = 'new-d87de19e-dd69-4a39-9c26-e3e67f133357';
    $pane = new stdClass();
    $pane->pid = 'new-c9ae9de6-83e0-4678-a990-27519ac29c4c';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_coordination_hubs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'c9ae9de6-83e0-4678-a990-27519ac29c4c';
    $display->content['new-c9ae9de6-83e0-4678-a990-27519ac29c4c'] = $pane;
    $display->panels['sidebar'][8] = 'new-c9ae9de6-83e0-4678-a990-27519ac29c4c';
    $pane = new stdClass();
    $pane->pid = 'new-cd8259eb-457d-4579-8884-4f4605dc3397';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_disasters';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'cd8259eb-457d-4579-8884-4f4605dc3397';
    $display->content['new-cd8259eb-457d-4579-8884-4f4605dc3397'] = $pane;
    $display->panels['sidebar'][9] = 'new-cd8259eb-457d-4579-8884-4f4605dc3397';
    $pane = new stdClass();
    $pane->pid = 'new-66ee2d3c-9a26-4559-b8e0-2cfd9c0c51d3';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fundings';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '66ee2d3c-9a26-4559-b8e0-2cfd9c0c51d3';
    $display->content['new-66ee2d3c-9a26-4559-b8e0-2cfd9c0c51d3'] = $pane;
    $display->panels['sidebar'][10] = 'new-66ee2d3c-9a26-4559-b8e0-2cfd9c0c51d3';
    $pane = new stdClass();
    $pane->pid = 'new-8448c14d-4f8d-437b-acf7-c154034dc9f6';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_funding_methods';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = '8448c14d-4f8d-437b-acf7-c154034dc9f6';
    $display->content['new-8448c14d-4f8d-437b-acf7-c154034dc9f6'] = $pane;
    $display->panels['sidebar'][11] = 'new-8448c14d-4f8d-437b-acf7-c154034dc9f6';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_news:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_news:default:search_result';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_news';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'search_result';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_moscone';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f76092d4-765f-4753-82a8-73a5dad47fc8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fd9a10db-6c46-4586-b4c5-5dc726fa610d';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_summary_or_trimmed',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '600',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fd9a10db-6c46-4586-b4c5-5dc726fa610d';
    $display->content['new-fd9a10db-6c46-4586-b4c5-5dc726fa610d'] = $pane;
    $display->panels['contentmain'][0] = 'new-fd9a10db-6c46-4586-b4c5-5dc726fa610d';
    $pane = new stdClass();
    $pane->pid = 'new-f115094b-9ba9-4fc0-ae81-51948172934b';
    $pane->panel = 'contentmain';
    $pane->type = 'panels_mini';
    $pane->subtype = 'hr_node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f115094b-9ba9-4fc0-ae81-51948172934b';
    $display->content['new-f115094b-9ba9-4fc0-ae81-51948172934b'] = $pane;
    $display->panels['contentmain'][1] = 'new-f115094b-9ba9-4fc0-ae81-51948172934b';
    $pane = new stdClass();
    $pane->pid = 'new-fce53ffb-f26f-4238-adfa-083f04c5e549';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>by <strong><a href="%node:author:url">%node:author</a></strong> on %node:created:hr_1</p>
',
      'format' => 'panopoly_wysiwyg_text',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fce53ffb-f26f-4238-adfa-083f04c5e549';
    $display->content['new-fce53ffb-f26f-4238-adfa-083f04c5e549'] = $pane;
    $display->panels['header'][0] = 'new-fce53ffb-f26f-4238-adfa-083f04c5e549';
    $pane = new stdClass();
    $pane->pid = 'new-4e3e3662-8577-4d6c-b1c4-a1f22193f0b6';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'thumbnail',
        'image_link' => 'content',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4e3e3662-8577-4d6c-b1c4-a1f22193f0b6';
    $display->content['new-4e3e3662-8577-4d6c-b1c4-a1f22193f0b6'] = $pane;
    $display->panels['sidebar'][0] = 'new-4e3e3662-8577-4d6c-b1c4-a1f22193f0b6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_news:default:search_result'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_news:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_news';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '95136f5a-f7ce-4017-816b-b7e39655295c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-743c06dd-3cbf-45a2-bffc-42e09799ff5f';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_disasters';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '743c06dd-3cbf-45a2-bffc-42e09799ff5f';
    $display->content['new-743c06dd-3cbf-45a2-bffc-42e09799ff5f'] = $pane;
    $display->panels['contentmain'][0] = 'new-743c06dd-3cbf-45a2-bffc-42e09799ff5f';
    $pane = new stdClass();
    $pane->pid = 'new-ba23b2bc-35f9-4306-86f7-63367b6010ee';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_organizations';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ba23b2bc-35f9-4306-86f7-63367b6010ee';
    $display->content['new-ba23b2bc-35f9-4306-86f7-63367b6010ee'] = $pane;
    $display->panels['contentmain'][1] = 'new-ba23b2bc-35f9-4306-86f7-63367b6010ee';
    $pane = new stdClass();
    $pane->pid = 'new-6c4f8b6b-3ec1-4a4f-a1cd-a10226b6b022';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6c4f8b6b-3ec1-4a4f-a1cd-a10226b6b022';
    $display->content['new-6c4f8b6b-3ec1-4a4f-a1cd-a10226b6b022'] = $pane;
    $display->panels['contentmain'][2] = 'new-6c4f8b6b-3ec1-4a4f-a1cd-a10226b6b022';
    $pane = new stdClass();
    $pane->pid = 'new-337ae815-7c18-4cf8-a91a-f3f4c72dea35';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_themes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '337ae815-7c18-4cf8-a91a-f3f4c72dea35';
    $display->content['new-337ae815-7c18-4cf8-a91a-f3f4c72dea35'] = $pane;
    $display->panels['contentmain'][3] = 'new-337ae815-7c18-4cf8-a91a-f3f4c72dea35';
    $pane = new stdClass();
    $pane->pid = 'new-9bea595d-c02c-4d54-b156-8c8e36c3b1b2';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:og_group_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9bea595d-c02c-4d54-b156-8c8e36c3b1b2';
    $display->content['new-9bea595d-c02c-4d54-b156-8c8e36c3b1b2'] = $pane;
    $display->panels['contentmain'][4] = 'new-9bea595d-c02c-4d54-b156-8c8e36c3b1b2';
    $pane = new stdClass();
    $pane->pid = 'new-0208f9f3-371c-433c-9ffd-678af73c3f47';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:title_field';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '0208f9f3-371c-433c-9ffd-678af73c3f47';
    $display->content['new-0208f9f3-371c-433c-9ffd-678af73c3f47'] = $pane;
    $display->panels['contentmain'][5] = 'new-0208f9f3-371c-433c-9ffd-678af73c3f47';
    $pane = new stdClass();
    $pane->pid = 'new-20176958-9fa5-4418-9b5d-5a829e6c4fff';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_funding_methods';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '20176958-9fa5-4418-9b5d-5a829e6c4fff';
    $display->content['new-20176958-9fa5-4418-9b5d-5a829e6c4fff'] = $pane;
    $display->panels['contentmain'][6] = 'new-20176958-9fa5-4418-9b5d-5a829e6c4fff';
    $pane = new stdClass();
    $pane->pid = 'new-d4abaf4f-9d6b-400c-82e1-18eb1eb09361';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_bundles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'd4abaf4f-9d6b-400c-82e1-18eb1eb09361';
    $display->content['new-d4abaf4f-9d6b-400c-82e1-18eb1eb09361'] = $pane;
    $display->panels['contentmain'][7] = 'new-d4abaf4f-9d6b-400c-82e1-18eb1eb09361';
    $pane = new stdClass();
    $pane->pid = 'new-9eb29641-54bb-4906-a0b9-d13a37b363ce';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_coordination_hubs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '9eb29641-54bb-4906-a0b9-d13a37b363ce';
    $display->content['new-9eb29641-54bb-4906-a0b9-d13a37b363ce'] = $pane;
    $display->panels['contentmain'][8] = 'new-9eb29641-54bb-4906-a0b9-d13a37b363ce';
    $pane = new stdClass();
    $pane->pid = 'new-c3af856a-bcc8-4cd0-a153-7d8506a05840';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_locations';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'c3af856a-bcc8-4cd0-a153-7d8506a05840';
    $display->content['new-c3af856a-bcc8-4cd0-a153-7d8506a05840'] = $pane;
    $display->panels['contentmain'][9] = 'new-c3af856a-bcc8-4cd0-a153-7d8506a05840';
    $pane = new stdClass();
    $pane->pid = 'new-295703bc-a8cf-4453-bdd8-54796a5b5db9';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_sectors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '295703bc-a8cf-4453-bdd8-54796a5b5db9';
    $display->content['new-295703bc-a8cf-4453-bdd8-54796a5b5db9'] = $pane;
    $display->panels['contentmain'][10] = 'new-295703bc-a8cf-4453-bdd8-54796a5b5db9';
    $pane = new stdClass();
    $pane->pid = 'new-0c5dc91f-37c7-4775-950e-9b0181a79a0e';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_summary_or_trimmed',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => 600,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = '0c5dc91f-37c7-4775-950e-9b0181a79a0e';
    $display->content['new-0c5dc91f-37c7-4775-950e-9b0181a79a0e'] = $pane;
    $display->panels['contentmain'][11] = 'new-0c5dc91f-37c7-4775-950e-9b0181a79a0e';
    $pane = new stdClass();
    $pane->pid = 'new-18b6570a-8209-4dec-9add-1532f100db43';
    $pane->panel = 'contentmain';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'teaser',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $pane->uuid = '18b6570a-8209-4dec-9add-1532f100db43';
    $display->content['new-18b6570a-8209-4dec-9add-1532f100db43'] = $pane;
    $display->panels['contentmain'][12] = 'new-18b6570a-8209-4dec-9add-1532f100db43';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-18b6570a-8209-4dec-9add-1532f100db43';
  $panelizer->display = $display;
  $export['node:hr_news:default:teaser'] = $panelizer;

  return $export;
}
