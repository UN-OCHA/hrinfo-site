<?php
/**
 * @file
 * hr_disasters.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_disasters_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_disaster:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_disaster';
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
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '86c74894-d4d3-40d9-a26e-7216275e1030';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-edaec7ef-c512-4a94-a577-781fcbc11829';
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
    $pane->uuid = 'edaec7ef-c512-4a94-a577-781fcbc11829';
    $display->content['new-edaec7ef-c512-4a94-a577-781fcbc11829'] = $pane;
    $display->panels['contentmain'][0] = 'new-edaec7ef-c512-4a94-a577-781fcbc11829';
    $pane = new stdClass();
    $pane->pid = 'new-5710cbc4-3eed-4c56-a0ad-8778e3a2af45';
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
    $pane->uuid = '5710cbc4-3eed-4c56-a0ad-8778e3a2af45';
    $display->content['new-5710cbc4-3eed-4c56-a0ad-8778e3a2af45'] = $pane;
    $display->panels['contentmain'][1] = 'new-5710cbc4-3eed-4c56-a0ad-8778e3a2af45';
    $pane = new stdClass();
    $pane->pid = 'new-006605dd-b29e-4263-a1bc-0128fdd98310';
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
    $pane->uuid = '006605dd-b29e-4263-a1bc-0128fdd98310';
    $display->content['new-006605dd-b29e-4263-a1bc-0128fdd98310'] = $pane;
    $display->panels['contentmain'][2] = 'new-006605dd-b29e-4263-a1bc-0128fdd98310';
    $pane = new stdClass();
    $pane->pid = 'new-3dadae13-d9fb-4f79-9764-a7f2f1b062f9';
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
    $pane->uuid = '3dadae13-d9fb-4f79-9764-a7f2f1b062f9';
    $display->content['new-3dadae13-d9fb-4f79-9764-a7f2f1b062f9'] = $pane;
    $display->panels['sidebar'][0] = 'new-3dadae13-d9fb-4f79-9764-a7f2f1b062f9';
    $pane = new stdClass();
    $pane->pid = 'new-935bcd7c-7f40-4e73-a0f8-ffe3c019deac';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_glide_number';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '935bcd7c-7f40-4e73-a0f8-ffe3c019deac';
    $display->content['new-935bcd7c-7f40-4e73-a0f8-ffe3c019deac'] = $pane;
    $display->panels['sidebar'][1] = 'new-935bcd7c-7f40-4e73-a0f8-ffe3c019deac';
    $pane = new stdClass();
    $pane->pid = 'new-cd5633c9-bcde-44a4-b05d-cac6daf876ee';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_glide_type';
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
    $pane->uuid = 'cd5633c9-bcde-44a4-b05d-cac6daf876ee';
    $display->content['new-cd5633c9-bcde-44a4-b05d-cac6daf876ee'] = $pane;
    $display->panels['sidebar'][2] = 'new-cd5633c9-bcde-44a4-b05d-cac6daf876ee';
    $pane = new stdClass();
    $pane->pid = 'new-cc0b8478-d140-42c3-a1ec-56848cd84202';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_disaster_status';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'list_default',
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
    $pane->uuid = 'cc0b8478-d140-42c3-a1ec-56848cd84202';
    $display->content['new-cc0b8478-d140-42c3-a1ec-56848cd84202'] = $pane;
    $display->panels['sidebar'][3] = 'new-cc0b8478-d140-42c3-a1ec-56848cd84202';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-3dadae13-d9fb-4f79-9764-a7f2f1b062f9';
  $panelizer->display = $display;
  $export['node:hr_disaster:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_disaster:default:search_result';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_disaster';
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
  $display->uuid = 'cfa14df4-903b-4260-af79-54ed583acfcf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d9cc044f-0a6b-4cb2-9353-3da25e27bc04';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_glide_number';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd9cc044f-0a6b-4cb2-9353-3da25e27bc04';
    $display->content['new-d9cc044f-0a6b-4cb2-9353-3da25e27bc04'] = $pane;
    $display->panels['contentmain'][0] = 'new-d9cc044f-0a6b-4cb2-9353-3da25e27bc04';
    $pane = new stdClass();
    $pane->pid = 'new-f7249aaf-a8ec-43f6-a79c-fc7e43445649';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_disaster_status';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f7249aaf-a8ec-43f6-a79c-fc7e43445649';
    $display->content['new-f7249aaf-a8ec-43f6-a79c-fc7e43445649'] = $pane;
    $display->panels['contentmain'][1] = 'new-f7249aaf-a8ec-43f6-a79c-fc7e43445649';
    $pane = new stdClass();
    $pane->pid = 'new-e4fd7784-3646-40f9-9d0f-1b8bd6e24f35';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e4fd7784-3646-40f9-9d0f-1b8bd6e24f35';
    $display->content['new-e4fd7784-3646-40f9-9d0f-1b8bd6e24f35'] = $pane;
    $display->panels['contentmain'][2] = 'new-e4fd7784-3646-40f9-9d0f-1b8bd6e24f35';
    $pane = new stdClass();
    $pane->pid = 'new-6cd9ed47-5cff-4e7f-94f2-7ac10b883c63';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6cd9ed47-5cff-4e7f-94f2-7ac10b883c63';
    $display->content['new-6cd9ed47-5cff-4e7f-94f2-7ac10b883c63'] = $pane;
    $display->panels['contentmain'][3] = 'new-6cd9ed47-5cff-4e7f-94f2-7ac10b883c63';
    $pane = new stdClass();
    $pane->pid = 'new-63c8a7d3-b0b5-48a5-9c10-19c2f87f8b6e';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_glide_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '63c8a7d3-b0b5-48a5-9c10-19c2f87f8b6e';
    $display->content['new-63c8a7d3-b0b5-48a5-9c10-19c2f87f8b6e'] = $pane;
    $display->panels['sidebar'][0] = 'new-63c8a7d3-b0b5-48a5-9c10-19c2f87f8b6e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-63c8a7d3-b0b5-48a5-9c10-19c2f87f8b6e';
  $panelizer->display = $display;
  $export['node:hr_disaster:default:search_result'] = $panelizer;

  return $export;
}
