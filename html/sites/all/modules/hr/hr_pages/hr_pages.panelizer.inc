<?php

/**
 * @file
 * hr_pages.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_pages_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'node:hr_page:default:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'bottom' => NULL,
      'contentmain' => NULL,
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '132e0da5-7125-4267-bbc1-cbd03dc2dc9f';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_page:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fafa16ac-3821-4ba4-9700-d192d96d453f';
  $pane->panel = 'contentmain';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fafa16ac-3821-4ba4-9700-d192d96d453f';
  $display->content['new-fafa16ac-3821-4ba4-9700-d192d96d453f'] = $pane;
  $display->panels['contentmain'][0] = 'new-fafa16ac-3821-4ba4-9700-d192d96d453f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_page:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'search_result';
  $panelizer->name = 'node:hr_page:default:search_result';
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
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'contentmain' => NULL,
      'default' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '465baefa-21f1-4a73-8d5d-213c806a2d36';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:hr_page:default:search_result';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-43d5fb33-5dce-479a-8343-93fa58b1cfd8';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'panelizer',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_summary_or_trimmed',
    'formatter_settings' => array(
      'trim_length' => '600',
    ),
    'label' => 'hidden',
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
  $pane->uuid = '43d5fb33-5dce-479a-8343-93fa58b1cfd8';
  $display->content['new-43d5fb33-5dce-479a-8343-93fa58b1cfd8'] = $pane;
  $display->panels['contentmain'][0] = 'new-43d5fb33-5dce-479a-8343-93fa58b1cfd8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_page:default:search_result'] = $panelizer;

  return $export;
}
