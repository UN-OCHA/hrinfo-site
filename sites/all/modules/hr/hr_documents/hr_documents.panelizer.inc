<?php
/**
 * @file
 * hr_documents.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_documents_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_document';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'node:hr_document:default:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_bryant_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '6a4de020-4f65-496e-af53-3ddfef226a2f';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_document:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-85d3fca5-4012-4849-8b87-0dec0997d31b';
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
  $pane->uuid = '85d3fca5-4012-4849-8b87-0dec0997d31b';
  $display->content['new-85d3fca5-4012-4849-8b87-0dec0997d31b'] = $pane;
  $display->panels['contentmain'][0] = 'new-85d3fca5-4012-4849-8b87-0dec0997d31b';
  $pane = new stdClass();
  $pane->pid = 'new-89b1915e-c00c-4547-a9f6-01a57140b2b9';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_files_collection';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'field_collection_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 0,
      'view_mode' => 'search_result',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '89b1915e-c00c-4547-a9f6-01a57140b2b9';
  $display->content['new-89b1915e-c00c-4547-a9f6-01a57140b2b9'] = $pane;
  $display->panels['contentmain'][1] = 'new-89b1915e-c00c-4547-a9f6-01a57140b2b9';
  $pane = new stdClass();
  $pane->pid = 'new-1af0a221-17ac-4055-8646-8570f233d1f0';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1af0a221-17ac-4055-8646-8570f233d1f0';
  $display->content['new-1af0a221-17ac-4055-8646-8570f233d1f0'] = $pane;
  $display->panels['contentmain'][2] = 'new-1af0a221-17ac-4055-8646-8570f233d1f0';
  $pane = new stdClass();
  $pane->pid = 'new-faadae31-e597-4bc2-ac01-522d42a309a9';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:hr_core_files_download_button';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'faadae31-e597-4bc2-ac01-522d42a309a9';
  $display->content['new-faadae31-e597-4bc2-ac01-522d42a309a9'] = $pane;
  $display->panels['contentmain'][3] = 'new-faadae31-e597-4bc2-ac01-522d42a309a9';
  $pane = new stdClass();
  $pane->pid = 'new-d70ed78b-5d77-4d45-8dc1-5a49de613ce1';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'd70ed78b-5d77-4d45-8dc1-5a49de613ce1';
  $display->content['new-d70ed78b-5d77-4d45-8dc1-5a49de613ce1'] = $pane;
  $display->panels['contentmain'][4] = 'new-d70ed78b-5d77-4d45-8dc1-5a49de613ce1';
  $pane = new stdClass();
  $pane->pid = 'new-4ab4b07f-e6c9-48ac-8d02-d76e7ae37d1c';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'link_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
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
  $pane->uuid = '4ab4b07f-e6c9-48ac-8d02-d76e7ae37d1c';
  $display->content['new-4ab4b07f-e6c9-48ac-8d02-d76e7ae37d1c'] = $pane;
  $display->panels['contentmain'][5] = 'new-4ab4b07f-e6c9-48ac-8d02-d76e7ae37d1c';
  $pane = new stdClass();
  $pane->pid = 'new-ce771c23-c72b-4aba-8d2a-4e9958fb0e03';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:og_group_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'og_list_default',
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
  $pane->uuid = 'ce771c23-c72b-4aba-8d2a-4e9958fb0e03';
  $display->content['new-ce771c23-c72b-4aba-8d2a-4e9958fb0e03'] = $pane;
  $display->panels['sidebar'][0] = 'new-ce771c23-c72b-4aba-8d2a-4e9958fb0e03';
  $pane = new stdClass();
  $pane->pid = 'new-b39f9735-02e9-4341-9fc7-af3e14f50623';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organizations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = 'b39f9735-02e9-4341-9fc7-af3e14f50623';
  $display->content['new-b39f9735-02e9-4341-9fc7-af3e14f50623'] = $pane;
  $display->panels['sidebar'][1] = 'new-b39f9735-02e9-4341-9fc7-af3e14f50623';
  $pane = new stdClass();
  $pane->pid = 'new-7c51214c-7e7b-4008-b753-1e6b663fd49a';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7c51214c-7e7b-4008-b753-1e6b663fd49a';
  $display->content['new-7c51214c-7e7b-4008-b753-1e6b663fd49a'] = $pane;
  $display->panels['sidebar'][2] = 'new-7c51214c-7e7b-4008-b753-1e6b663fd49a';
  $pane = new stdClass();
  $pane->pid = 'new-015939cc-09d1-4599-b59b-a3e633184827';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bundles';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
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
  $pane->uuid = '015939cc-09d1-4599-b59b-a3e633184827';
  $display->content['new-015939cc-09d1-4599-b59b-a3e633184827'] = $pane;
  $display->panels['sidebar'][3] = 'new-015939cc-09d1-4599-b59b-a3e633184827';
  $pane = new stdClass();
  $pane->pid = 'new-a31c102d-0188-4ac5-a9da-eb0f29cf65d8';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'hr_1',
      'fromto' => 'both',
      'multiple_from' => '',
      'multiple_number' => '',
      'multiple_to' => '',
    ),
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
  $pane->uuid = 'a31c102d-0188-4ac5-a9da-eb0f29cf65d8';
  $display->content['new-a31c102d-0188-4ac5-a9da-eb0f29cf65d8'] = $pane;
  $display->panels['sidebar'][4] = 'new-a31c102d-0188-4ac5-a9da-eb0f29cf65d8';
  $pane = new stdClass();
  $pane->pid = 'new-30e70384-f967-4691-897a-178eda9dbd02';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_document_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = '30e70384-f967-4691-897a-178eda9dbd02';
  $display->content['new-30e70384-f967-4691-897a-178eda9dbd02'] = $pane;
  $display->panels['sidebar'][5] = 'new-30e70384-f967-4691-897a-178eda9dbd02';
  $pane = new stdClass();
  $pane->pid = 'new-43d3ff65-792d-43b2-97fa-a4ac235fe40a';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = '43d3ff65-792d-43b2-97fa-a4ac235fe40a';
  $display->content['new-43d3ff65-792d-43b2-97fa-a4ac235fe40a'] = $pane;
  $display->panels['sidebar'][6] = 'new-43d3ff65-792d-43b2-97fa-a4ac235fe40a';
  $pane = new stdClass();
  $pane->pid = 'new-0ac28c56-0f31-4a25-9bc9-d0c52c25528e';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_themes';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = '0ac28c56-0f31-4a25-9bc9-d0c52c25528e';
  $display->content['new-0ac28c56-0f31-4a25-9bc9-d0c52c25528e'] = $pane;
  $display->panels['sidebar'][7] = 'new-0ac28c56-0f31-4a25-9bc9-d0c52c25528e';
  $pane = new stdClass();
  $pane->pid = 'new-ee72d629-e314-4eed-abc1-630ca0b5e474';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_coordination_hubs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = 'ee72d629-e314-4eed-abc1-630ca0b5e474';
  $display->content['new-ee72d629-e314-4eed-abc1-630ca0b5e474'] = $pane;
  $display->panels['sidebar'][8] = 'new-ee72d629-e314-4eed-abc1-630ca0b5e474';
  $pane = new stdClass();
  $pane->pid = 'new-ef0ff3ea-1b0f-47f3-b6d0-0f709b11c66d';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_disasters';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = 'ef0ff3ea-1b0f-47f3-b6d0-0f709b11c66d';
  $display->content['new-ef0ff3ea-1b0f-47f3-b6d0-0f709b11c66d'] = $pane;
  $display->panels['sidebar'][9] = 'new-ef0ff3ea-1b0f-47f3-b6d0-0f709b11c66d';
  $pane = new stdClass();
  $pane->pid = 'new-a155f7a3-81fc-4322-8231-acadd22863b0';
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
  $pane->uuid = 'a155f7a3-81fc-4322-8231-acadd22863b0';
  $display->content['new-a155f7a3-81fc-4322-8231-acadd22863b0'] = $pane;
  $display->panels['sidebar'][10] = 'new-a155f7a3-81fc-4322-8231-acadd22863b0';
  $pane = new stdClass();
  $pane->pid = 'new-481ea9a0-a172-4510-856e-5ef45a9e0992';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_funding_methods';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
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
  $pane->uuid = '481ea9a0-a172-4510-856e-5ef45a9e0992';
  $display->content['new-481ea9a0-a172-4510-856e-5ef45a9e0992'] = $pane;
  $display->panels['sidebar'][11] = 'new-481ea9a0-a172-4510-856e-5ef45a9e0992';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_document:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_document';
  $panelizer->access = array();
  $panelizer->view_mode = 'search_result';
  $panelizer->name = 'node:hr_document:default:search_result';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
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
  $display->uuid = 'f489438d-fe9c-404a-9533-b18df9cba25a';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_document:default:search_result';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-34a09403-e834-46d6-99bc-64a1c989dec0';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organizations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = '34a09403-e834-46d6-99bc-64a1c989dec0';
  $display->content['new-34a09403-e834-46d6-99bc-64a1c989dec0'] = $pane;
  $display->panels['contentmain'][0] = 'new-34a09403-e834-46d6-99bc-64a1c989dec0';
  $pane = new stdClass();
  $pane->pid = 'new-f0c63796-e209-43e3-9208-9ee02a102866';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'hr_1',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f0c63796-e209-43e3-9208-9ee02a102866';
  $display->content['new-f0c63796-e209-43e3-9208-9ee02a102866'] = $pane;
  $display->panels['contentmain'][1] = 'new-f0c63796-e209-43e3-9208-9ee02a102866';
  $pane = new stdClass();
  $pane->pid = 'new-106c9a69-3fd4-46ae-8416-68ad95c2a463';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_document_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
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
  $pane->uuid = '106c9a69-3fd4-46ae-8416-68ad95c2a463';
  $display->content['new-106c9a69-3fd4-46ae-8416-68ad95c2a463'] = $pane;
  $display->panels['contentmain'][2] = 'new-106c9a69-3fd4-46ae-8416-68ad95c2a463';
  $pane = new stdClass();
  $pane->pid = 'new-df5e9686-509c-4ace-b0c5-67fadd9b15a3';
  $pane->panel = 'footer';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:hr_core_read_more_button';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'search_result',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'df5e9686-509c-4ace-b0c5-67fadd9b15a3';
  $display->content['new-df5e9686-509c-4ace-b0c5-67fadd9b15a3'] = $pane;
  $display->panels['footer'][0] = 'new-df5e9686-509c-4ace-b0c5-67fadd9b15a3';
  $pane = new stdClass();
  $pane->pid = 'new-49fb4dde-9131-43cc-a524-329aca18b3da';
  $pane->panel = 'footer';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:hr_core_share_button';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '49fb4dde-9131-43cc-a524-329aca18b3da';
  $display->content['new-49fb4dde-9131-43cc-a524-329aca18b3da'] = $pane;
  $display->panels['footer'][1] = 'new-49fb4dde-9131-43cc-a524-329aca18b3da';
  $pane = new stdClass();
  $pane->pid = 'new-03fcdbde-c0df-4c5e-a0b1-0a1282eec897';
  $pane->panel = 'footer';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:hr_core_files_download_button';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '03fcdbde-c0df-4c5e-a0b1-0a1282eec897';
  $display->content['new-03fcdbde-c0df-4c5e-a0b1-0a1282eec897'] = $pane;
  $display->panels['footer'][2] = 'new-03fcdbde-c0df-4c5e-a0b1-0a1282eec897';
  $pane = new stdClass();
  $pane->pid = 'new-022e020f-d5e1-4305-aacb-6f9053c08535';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_files_collection';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'field_collection_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 0,
      'view_mode' => 'search_result',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'hr_highlighted',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '022e020f-d5e1-4305-aacb-6f9053c08535';
  $display->content['new-022e020f-d5e1-4305-aacb-6f9053c08535'] = $pane;
  $display->panels['sidebar'][0] = 'new-022e020f-d5e1-4305-aacb-6f9053c08535';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-34a09403-e834-46d6-99bc-64a1c989dec0';
  $panelizer->display = $display;
  $export['node:hr_document:default:search_result'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_document';
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->name = 'node:hr_document:default:teaser';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H4';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '62b777f8-e25b-4077-b09c-a0ef2e31b103';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_document:default:teaser';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a6d6044f-229c-494e-b8f6-e892449ba0e2';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'hr_documents_panes-thumbnail';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'panelizer',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a6d6044f-229c-494e-b8f6-e892449ba0e2';
  $display->content['new-a6d6044f-229c-494e-b8f6-e892449ba0e2'] = $pane;
  $display->panels['contentmain'][0] = 'new-a6d6044f-229c-494e-b8f6-e892449ba0e2';
  $pane = new stdClass();
  $pane->pid = 'new-5b640a71-32c8-41f8-9780-4778d2e7d437';
  $pane->panel = 'contentmain';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 1,
    'markup' => 'none',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5b640a71-32c8-41f8-9780-4778d2e7d437';
  $display->content['new-5b640a71-32c8-41f8-9780-4778d2e7d437'] = $pane;
  $display->panels['contentmain'][1] = 'new-5b640a71-32c8-41f8-9780-4778d2e7d437';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_document:default:teaser'] = $panelizer;

  return $export;
}
