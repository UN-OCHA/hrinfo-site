<?php
/**
 * @file
 * hr_bundles.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_bundles_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_bundle:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_bundle';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_sutro';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '89066893-9058-4625-9428-b569701a0246';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6877c6ce-c2f1-4982-bc24-066fb66750f1';
    $pane->panel = 'column1';
    $pane->type = 'hr_documents_key_documents';
    $pane->subtype = 'hr_documents_key_documents';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'documents' => FALSE,
      'override_title' => 1,
      'override_title_text' => 'Key Documents',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6877c6ce-c2f1-4982-bc24-066fb66750f1';
    $display->content['new-6877c6ce-c2f1-4982-bc24-066fb66750f1'] = $pane;
    $display->panels['column1'][0] = 'new-6877c6ce-c2f1-4982-bc24-066fb66750f1';
    $pane = new stdClass();
    $pane->pid = 'new-95e3e805-0870-4575-b617-cec3ea15411d';
    $pane->panel = 'column1';
    $pane->type = 'hr_infographics_key_infographics';
    $pane->subtype = 'hr_infographics_key_infographics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'infographics' => array(
        0 => FALSE,
      ),
      'override_title' => 1,
      'override_title_text' => 'Key Infographics',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '95e3e805-0870-4575-b617-cec3ea15411d';
    $display->content['new-95e3e805-0870-4575-b617-cec3ea15411d'] = $pane;
    $display->panels['column1'][1] = 'new-95e3e805-0870-4575-b617-cec3ea15411d';
    $pane = new stdClass();
    $pane->pid = 'new-78681d00-c9d4-4bc8-8693-9c6dbd083be4';
    $pane->panel = 'column1';
    $pane->type = 'hr_contacts_key_contacts';
    $pane->subtype = 'hr_contacts_key_contacts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'contacts' => array(
        0 => FALSE,
      ),
      'override_title' => 1,
      'override_title_text' => 'Key Contacts',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '78681d00-c9d4-4bc8-8693-9c6dbd083be4';
    $display->content['new-78681d00-c9d4-4bc8-8693-9c6dbd083be4'] = $pane;
    $display->panels['column1'][2] = 'new-78681d00-c9d4-4bc8-8693-9c6dbd083be4';
    $pane = new stdClass();
    $pane->pid = 'new-b6ec1f94-7313-4b3a-ba67-c5b2145a3674';
    $pane->panel = 'column1';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_assessments_panes-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 0,
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'context' => array(
        1 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b6ec1f94-7313-4b3a-ba67-c5b2145a3674';
    $display->content['new-b6ec1f94-7313-4b3a-ba67-c5b2145a3674'] = $pane;
    $display->panels['column1'][3] = 'new-b6ec1f94-7313-4b3a-ba67-c5b2145a3674';
    $pane = new stdClass();
    $pane->pid = 'new-72991a33-ae33-4088-adbf-5f8b348b0e45';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_documents_panes-documents_from_context';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 0,
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'context' => array(
        0 => 'panelizer',
        1 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '72991a33-ae33-4088-adbf-5f8b348b0e45';
    $display->content['new-72991a33-ae33-4088-adbf-5f8b348b0e45'] = $pane;
    $display->panels['column2'][0] = 'new-72991a33-ae33-4088-adbf-5f8b348b0e45';
    $pane = new stdClass();
    $pane->pid = 'new-7d442ae2-11a0-415a-be90-ac1008931aa3';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_infographics_panes-infographics_from_context';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 0,
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'context' => array(
        0 => 'empty',
        1 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7d442ae2-11a0-415a-be90-ac1008931aa3';
    $display->content['new-7d442ae2-11a0-415a-be90-ac1008931aa3'] = $pane;
    $display->panels['column2'][1] = 'new-7d442ae2-11a0-415a-be90-ac1008931aa3';
    $pane = new stdClass();
    $pane->pid = 'new-5f5e936f-9127-45c0-a69a-169ac7e209d6';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_events_panes-upcoming_from_context';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 0,
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'fields_override' => array(
        'title' => 1,
        'field_event_date' => 1,
      ),
      'context' => array(
        0 => 'empty',
        1 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5f5e936f-9127-45c0-a69a-169ac7e209d6';
    $display->content['new-5f5e936f-9127-45c0-a69a-169ac7e209d6'] = $pane;
    $display->panels['column2'][2] = 'new-5f5e936f-9127-45c0-a69a-169ac7e209d6';
    $pane = new stdClass();
    $pane->pid = 'new-04905869-f9c4-4dde-b96a-a417791d0a25';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_documents_panes-mm_from_context';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 0,
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'context' => array(
        0 => 'panelizer',
        1 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'hr_highlighted',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '04905869-f9c4-4dde-b96a-a417791d0a25';
    $display->content['new-04905869-f9c4-4dde-b96a-a417791d0a25'] = $pane;
    $display->panels['column2'][3] = 'new-04905869-f9c4-4dde-b96a-a417791d0a25';
    $pane = new stdClass();
    $pane->pid = 'new-eef056d1-27fc-4637-b3e6-d94dfd3c0fa8';
    $pane->panel = 'header';
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
    $pane->uuid = 'eef056d1-27fc-4637-b3e6-d94dfd3c0fa8';
    $display->content['new-eef056d1-27fc-4637-b3e6-d94dfd3c0fa8'] = $pane;
    $display->panels['header'][0] = 'new-eef056d1-27fc-4637-b3e6-d94dfd3c0fa8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_bundle:default:default'] = $panelizer;

  return $export;
}
