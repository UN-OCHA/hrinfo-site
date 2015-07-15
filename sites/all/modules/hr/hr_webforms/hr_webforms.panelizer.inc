<?php
/**
 * @file
 * hr_webforms.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_webforms_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:webform:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'webform';
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
  $display->uuid = '2e1a0fa3-5e9f-4f3a-805a-fb38649c2e01';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e502f2d7-2f3f-4857-b978-4e390f366f91';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e502f2d7-2f3f-4857-b978-4e390f366f91';
    $display->content['new-e502f2d7-2f3f-4857-b978-4e390f366f91'] = $pane;
    $display->panels['contentmain'][0] = 'new-e502f2d7-2f3f-4857-b978-4e390f366f91';
    $pane = new stdClass();
    $pane->pid = 'new-baa31916-fbe6-40ab-8e75-a1fe9b0564d5';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:webform';
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
    $pane->uuid = 'baa31916-fbe6-40ab-8e75-a1fe9b0564d5';
    $display->content['new-baa31916-fbe6-40ab-8e75-a1fe9b0564d5'] = $pane;
    $display->panels['contentmain'][1] = 'new-baa31916-fbe6-40ab-8e75-a1fe9b0564d5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-e502f2d7-2f3f-4857-b978-4e390f366f91';
  $panelizer->display = $display;
  $export['node:webform:default:default'] = $panelizer;

  return $export;
}
