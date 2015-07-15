<?php
/**
 * @file
 * hr_users.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_users_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'user:user:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'user';
  $panelizer->panelizer_key = 'user';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array(
    1 => array(
      'identifier' => 'Profile2 from user',
      'keyword' => 'profile2',
      'name' => 'profile2',
      'type' => 'main',
      'context' => 'panelizer',
      'id' => 1,
    ),
  );
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_bartlett_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'contentheader' => NULL,
      'contentcolumn1' => NULL,
      'contentcolumn2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%user:name';
  $display->uuid = '3885f405-1a6b-4b93-b63c-46536abf2bd8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-21bfd4b2-e8b8-4ed0-86ef-11192594db4c';
    $pane->panel = 'contentcolumn1';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '21bfd4b2-e8b8-4ed0-86ef-11192594db4c';
    $display->content['new-21bfd4b2-e8b8-4ed0-86ef-11192594db4c'] = $pane;
    $display->panels['contentcolumn1'][0] = 'new-21bfd4b2-e8b8-4ed0-86ef-11192594db4c';
    $pane = new stdClass();
    $pane->pid = 'new-bba0afc8-0e39-4f7a-b141-1c825d4ef38f';
    $pane->panel = 'contentheader';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
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
    $pane->uuid = 'bba0afc8-0e39-4f7a-b141-1c825d4ef38f';
    $display->content['new-bba0afc8-0e39-4f7a-b141-1c825d4ef38f'] = $pane;
    $display->panels['contentheader'][0] = 'new-bba0afc8-0e39-4f7a-b141-1c825d4ef38f';
    $pane = new stdClass();
    $pane->pid = 'new-c0082414-7c29-40ee-8b0e-acfac304c6e7';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_organizations';
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
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
    $pane->uuid = 'c0082414-7c29-40ee-8b0e-acfac304c6e7';
    $display->content['new-c0082414-7c29-40ee-8b0e-acfac304c6e7'] = $pane;
    $display->panels['sidebar'][1] = 'new-c0082414-7c29-40ee-8b0e-acfac304c6e7';
    $pane = new stdClass();
    $pane->pid = 'new-9b3f9df5-064b-4020-b5a0-ab7476de1fa0';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_job_title_other';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
    $pane->uuid = '9b3f9df5-064b-4020-b5a0-ab7476de1fa0';
    $display->content['new-9b3f9df5-064b-4020-b5a0-ab7476de1fa0'] = $pane;
    $display->panels['sidebar'][2] = 'new-9b3f9df5-064b-4020-b5a0-ab7476de1fa0';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['user:user:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'user:user:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'user';
  $panelizer->panelizer_key = 'user';
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
      'middle' => NULL,
      'contentmain' => NULL,
    ),
    'middle' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '02f76176-982f-4716-9f14-e5a3b0e42b7a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4e17e53c-fbd1-45c1-9d3f-95a74b2cd940';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'user:profile_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
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
    $pane->uuid = '4e17e53c-fbd1-45c1-9d3f-95a74b2cd940';
    $display->content['new-4e17e53c-fbd1-45c1-9d3f-95a74b2cd940'] = $pane;
    $display->panels['contentmain'][0] = 'new-4e17e53c-fbd1-45c1-9d3f-95a74b2cd940';
    $pane = new stdClass();
    $pane->pid = 'new-ffd304a9-44b2-46ba-a64c-1ceba46e14fb';
    $pane->panel = 'contentmain';
    $pane->type = 'token';
    $pane->subtype = 'user:mail';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
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
    $pane->uuid = 'ffd304a9-44b2-46ba-a64c-1ceba46e14fb';
    $display->content['new-ffd304a9-44b2-46ba-a64c-1ceba46e14fb'] = $pane;
    $display->panels['contentmain'][1] = 'new-ffd304a9-44b2-46ba-a64c-1ceba46e14fb';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['user:user:default:teaser'] = $panelizer;

  return $export;
}
