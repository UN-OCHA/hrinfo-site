<?php
/**
 * @file
 * hr_infographics.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_infographics_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_infographic';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'node:hr_infographic:default:default';
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
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '68d4afa7-0cb9-4616-952e-8c1d58b6d2ff';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_infographic:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-88ee6379-8f3e-47e0-a402-bb29694876a9';
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
  $pane->uuid = '88ee6379-8f3e-47e0-a402-bb29694876a9';
  $display->content['new-88ee6379-8f3e-47e0-a402-bb29694876a9'] = $pane;
  $display->panels['contentmain'][0] = 'new-88ee6379-8f3e-47e0-a402-bb29694876a9';
  $pane = new stdClass();
  $pane->pid = 'new-a8930dee-b6ec-4d50-a0a6-38f0ba862a13';
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
  $pane->uuid = 'a8930dee-b6ec-4d50-a0a6-38f0ba862a13';
  $display->content['new-a8930dee-b6ec-4d50-a0a6-38f0ba862a13'] = $pane;
  $display->panels['contentmain'][1] = 'new-a8930dee-b6ec-4d50-a0a6-38f0ba862a13';
  $pane = new stdClass();
  $pane->pid = 'new-c7346f0f-c921-4dd1-858b-189fa86fe8cf';
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
  $pane->uuid = 'c7346f0f-c921-4dd1-858b-189fa86fe8cf';
  $display->content['new-c7346f0f-c921-4dd1-858b-189fa86fe8cf'] = $pane;
  $display->panels['contentmain'][2] = 'new-c7346f0f-c921-4dd1-858b-189fa86fe8cf';
  $pane = new stdClass();
  $pane->pid = 'new-edb11c6d-f3ff-4ebe-85a9-bc6b75f1fd4f';
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
  $pane->uuid = 'edb11c6d-f3ff-4ebe-85a9-bc6b75f1fd4f';
  $display->content['new-edb11c6d-f3ff-4ebe-85a9-bc6b75f1fd4f'] = $pane;
  $display->panels['contentmain'][3] = 'new-edb11c6d-f3ff-4ebe-85a9-bc6b75f1fd4f';
  $pane = new stdClass();
  $pane->pid = 'new-cc62b688-7b0a-4cb7-b9f0-673edf08e990';
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
  $pane->uuid = 'cc62b688-7b0a-4cb7-b9f0-673edf08e990';
  $display->content['new-cc62b688-7b0a-4cb7-b9f0-673edf08e990'] = $pane;
  $display->panels['contentmain'][4] = 'new-cc62b688-7b0a-4cb7-b9f0-673edf08e990';
  $pane = new stdClass();
  $pane->pid = 'new-8f908f20-0293-4e02-aa2d-c233ea22ab82';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_data_sources';
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
  $pane->uuid = '8f908f20-0293-4e02-aa2d-c233ea22ab82';
  $display->content['new-8f908f20-0293-4e02-aa2d-c233ea22ab82'] = $pane;
  $display->panels['contentmain'][5] = 'new-8f908f20-0293-4e02-aa2d-c233ea22ab82';
  $pane = new stdClass();
  $pane->pid = 'new-34067174-4f68-4da5-b6ab-620b0318fe6d';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'link_default',
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
  $pane->uuid = '34067174-4f68-4da5-b6ab-620b0318fe6d';
  $display->content['new-34067174-4f68-4da5-b6ab-620b0318fe6d'] = $pane;
  $display->panels['contentmain'][6] = 'new-34067174-4f68-4da5-b6ab-620b0318fe6d';
  $pane = new stdClass();
  $pane->pid = 'new-5a47c1a9-7199-4891-b139-56f4b8177c1f';
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
  $pane->uuid = '5a47c1a9-7199-4891-b139-56f4b8177c1f';
  $display->content['new-5a47c1a9-7199-4891-b139-56f4b8177c1f'] = $pane;
  $display->panels['sidebar'][0] = 'new-5a47c1a9-7199-4891-b139-56f4b8177c1f';
  $pane = new stdClass();
  $pane->pid = 'new-0fcd3266-45a5-467e-883a-6ab09958de84';
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
  $pane->uuid = '0fcd3266-45a5-467e-883a-6ab09958de84';
  $display->content['new-0fcd3266-45a5-467e-883a-6ab09958de84'] = $pane;
  $display->panels['sidebar'][1] = 'new-0fcd3266-45a5-467e-883a-6ab09958de84';
  $pane = new stdClass();
  $pane->pid = 'new-3365845b-b5c8-42a7-b068-eec4be167383';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_sectors';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3365845b-b5c8-42a7-b068-eec4be167383';
  $display->content['new-3365845b-b5c8-42a7-b068-eec4be167383'] = $pane;
  $display->panels['sidebar'][2] = 'new-3365845b-b5c8-42a7-b068-eec4be167383';
  $pane = new stdClass();
  $pane->pid = 'new-ff85dd49-6859-4753-955c-5a4dbf5fee14';
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
  $pane->uuid = 'ff85dd49-6859-4753-955c-5a4dbf5fee14';
  $display->content['new-ff85dd49-6859-4753-955c-5a4dbf5fee14'] = $pane;
  $display->panels['sidebar'][3] = 'new-ff85dd49-6859-4753-955c-5a4dbf5fee14';
  $pane = new stdClass();
  $pane->pid = 'new-283d5472-d1e7-4148-a6c2-cf5cf4455216';
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
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_repeat_rule' => 'show',
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
  $pane->uuid = '283d5472-d1e7-4148-a6c2-cf5cf4455216';
  $display->content['new-283d5472-d1e7-4148-a6c2-cf5cf4455216'] = $pane;
  $display->panels['sidebar'][4] = 'new-283d5472-d1e7-4148-a6c2-cf5cf4455216';
  $pane = new stdClass();
  $pane->pid = 'new-afb5e1e4-87cd-4030-939a-69f3bbefd3bc';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_infographic_type';
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
  $pane->uuid = 'afb5e1e4-87cd-4030-939a-69f3bbefd3bc';
  $display->content['new-afb5e1e4-87cd-4030-939a-69f3bbefd3bc'] = $pane;
  $display->panels['sidebar'][5] = 'new-afb5e1e4-87cd-4030-939a-69f3bbefd3bc';
  $pane = new stdClass();
  $pane->pid = 'new-bf281996-18b9-4140-8da9-166b013b6aff';
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
  $pane->uuid = 'bf281996-18b9-4140-8da9-166b013b6aff';
  $display->content['new-bf281996-18b9-4140-8da9-166b013b6aff'] = $pane;
  $display->panels['sidebar'][6] = 'new-bf281996-18b9-4140-8da9-166b013b6aff';
  $pane = new stdClass();
  $pane->pid = 'new-e7787ab9-d452-461e-9bf3-d5520cb6ffe8';
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
  $pane->uuid = 'e7787ab9-d452-461e-9bf3-d5520cb6ffe8';
  $display->content['new-e7787ab9-d452-461e-9bf3-d5520cb6ffe8'] = $pane;
  $display->panels['sidebar'][7] = 'new-e7787ab9-d452-461e-9bf3-d5520cb6ffe8';
  $pane = new stdClass();
  $pane->pid = 'new-f6776cb7-bc3f-46fa-8b09-1bd361c364f1';
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
  $pane->uuid = 'f6776cb7-bc3f-46fa-8b09-1bd361c364f1';
  $display->content['new-f6776cb7-bc3f-46fa-8b09-1bd361c364f1'] = $pane;
  $display->panels['sidebar'][8] = 'new-f6776cb7-bc3f-46fa-8b09-1bd361c364f1';
  $pane = new stdClass();
  $pane->pid = 'new-ff07b1f1-3d78-4e5b-a839-834b58abe87f';
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
  $pane->uuid = 'ff07b1f1-3d78-4e5b-a839-834b58abe87f';
  $display->content['new-ff07b1f1-3d78-4e5b-a839-834b58abe87f'] = $pane;
  $display->panels['sidebar'][9] = 'new-ff07b1f1-3d78-4e5b-a839-834b58abe87f';
  $pane = new stdClass();
  $pane->pid = 'new-a58bec3d-c7bb-4ee2-b11f-f59a1ae2d26e';
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
  $pane->uuid = 'a58bec3d-c7bb-4ee2-b11f-f59a1ae2d26e';
  $display->content['new-a58bec3d-c7bb-4ee2-b11f-f59a1ae2d26e'] = $pane;
  $display->panels['sidebar'][10] = 'new-a58bec3d-c7bb-4ee2-b11f-f59a1ae2d26e';
  $pane = new stdClass();
  $pane->pid = 'new-4409f83f-ec67-4d0c-9f36-6c04ed569eab';
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
  $pane->uuid = '4409f83f-ec67-4d0c-9f36-6c04ed569eab';
  $display->content['new-4409f83f-ec67-4d0c-9f36-6c04ed569eab'] = $pane;
  $display->panels['sidebar'][11] = 'new-4409f83f-ec67-4d0c-9f36-6c04ed569eab';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-5a47c1a9-7199-4891-b139-56f4b8177c1f';
  $panelizer->display = $display;
  $export['node:hr_infographic:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_infographic';
  $panelizer->access = array();
  $panelizer->view_mode = 'search_result';
  $panelizer->name = 'node:hr_infographic:default:search_result';
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
  $display->uuid = '6b4fcae5-9918-44f9-b6df-392df1fb1243';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_infographic:default:search_result';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9ff01383-1ddc-4045-a3da-b48800a6a6ff';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organizations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9ff01383-1ddc-4045-a3da-b48800a6a6ff';
  $display->content['new-9ff01383-1ddc-4045-a3da-b48800a6a6ff'] = $pane;
  $display->panels['contentmain'][0] = 'new-9ff01383-1ddc-4045-a3da-b48800a6a6ff';
  $pane = new stdClass();
  $pane->pid = 'new-05c8d42f-f81b-432b-abdf-bac6bb42a528';
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
      'show_repeat_rule' => 'show',
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
  $pane->uuid = '05c8d42f-f81b-432b-abdf-bac6bb42a528';
  $display->content['new-05c8d42f-f81b-432b-abdf-bac6bb42a528'] = $pane;
  $display->panels['contentmain'][1] = 'new-05c8d42f-f81b-432b-abdf-bac6bb42a528';
  $pane = new stdClass();
  $pane->pid = 'new-a9e5335d-0d6e-4429-98f4-fb55d117e5bd';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_infographic_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
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
  $pane->uuid = 'a9e5335d-0d6e-4429-98f4-fb55d117e5bd';
  $display->content['new-a9e5335d-0d6e-4429-98f4-fb55d117e5bd'] = $pane;
  $display->panels['contentmain'][2] = 'new-a9e5335d-0d6e-4429-98f4-fb55d117e5bd';
  $pane = new stdClass();
  $pane->pid = 'new-765656b6-f6c9-452b-bad4-9684e1cb7627';
  $pane->panel = 'footer';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:hr_core_read_more_button';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '765656b6-f6c9-452b-bad4-9684e1cb7627';
  $display->content['new-765656b6-f6c9-452b-bad4-9684e1cb7627'] = $pane;
  $display->panels['footer'][0] = 'new-765656b6-f6c9-452b-bad4-9684e1cb7627';
  $pane = new stdClass();
  $pane->pid = 'new-21d7bedf-69b7-45b1-9d08-25ea23d9971a';
  $pane->panel = 'footer';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:hr_core_share_button';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '21d7bedf-69b7-45b1-9d08-25ea23d9971a';
  $display->content['new-21d7bedf-69b7-45b1-9d08-25ea23d9971a'] = $pane;
  $display->panels['footer'][1] = 'new-21d7bedf-69b7-45b1-9d08-25ea23d9971a';
  $pane = new stdClass();
  $pane->pid = 'new-6ffd0fa3-0179-4eb0-9e3d-dc9c9ea0752d';
  $pane->panel = 'footer';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:hr_core_files_download_button';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6ffd0fa3-0179-4eb0-9e3d-dc9c9ea0752d';
  $display->content['new-6ffd0fa3-0179-4eb0-9e3d-dc9c9ea0752d'] = $pane;
  $display->panels['footer'][2] = 'new-6ffd0fa3-0179-4eb0-9e3d-dc9c9ea0752d';
  $pane = new stdClass();
  $pane->pid = 'new-c091d3e6-8db9-4d02-a179-8be3f1d0d338';
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
  $pane->uuid = 'c091d3e6-8db9-4d02-a179-8be3f1d0d338';
  $display->content['new-c091d3e6-8db9-4d02-a179-8be3f1d0d338'] = $pane;
  $display->panels['sidebar'][0] = 'new-c091d3e6-8db9-4d02-a179-8be3f1d0d338';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_infographic:default:search_result'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_infographic';
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->name = 'node:hr_infographic:default:teaser';
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
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '76d05376-3c49-4411-b665-ac4e9279cfa7';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_infographic:default:teaser';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4621a4fd-eefb-4530-9655-0d43a517d0c7';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'hr_infographics_panes-thumbnail';
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
  $pane->uuid = '4621a4fd-eefb-4530-9655-0d43a517d0c7';
  $display->content['new-4621a4fd-eefb-4530-9655-0d43a517d0c7'] = $pane;
  $display->panels['contentmain'][0] = 'new-4621a4fd-eefb-4530-9655-0d43a517d0c7';
  $pane = new stdClass();
  $pane->pid = 'new-c1ad3fcb-9446-4980-ba65-b028af7af09e';
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
  $pane->uuid = 'c1ad3fcb-9446-4980-ba65-b028af7af09e';
  $display->content['new-c1ad3fcb-9446-4980-ba65-b028af7af09e'] = $pane;
  $display->panels['contentmain'][1] = 'new-c1ad3fcb-9446-4980-ba65-b028af7af09e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_infographic:default:teaser'] = $panelizer;

  return $export;
}
