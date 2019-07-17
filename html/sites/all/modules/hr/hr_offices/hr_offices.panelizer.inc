<?php
/**
 * @file
 * hr_offices.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_offices_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_office:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_office';
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
  $display->uuid = 'ab11184b-6cb4-4818-b53c-34ac3fd465ba';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f548e4c8-bee1-4566-a0ab-44a949cb8326';
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
    $pane->uuid = 'f548e4c8-bee1-4566-a0ab-44a949cb8326';
    $display->content['new-f548e4c8-bee1-4566-a0ab-44a949cb8326'] = $pane;
    $display->panels['contentmain'][0] = 'new-f548e4c8-bee1-4566-a0ab-44a949cb8326';
    $pane = new stdClass();
    $pane->pid = 'new-47c110cc-83f5-449c-8d84-34aba5b64055';
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
    $pane->uuid = '47c110cc-83f5-449c-8d84-34aba5b64055';
    $display->content['new-47c110cc-83f5-449c-8d84-34aba5b64055'] = $pane;
    $display->panels['contentmain'][1] = 'new-47c110cc-83f5-449c-8d84-34aba5b64055';
    $pane = new stdClass();
    $pane->pid = 'new-71b7da01-f766-4854-a8a9-6f5924258649';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_address';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'addressfield_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_handlers' => array(
          'address' => 'address',
        ),
        'use_widget_handlers' => 1,
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
    $pane->uuid = '71b7da01-f766-4854-a8a9-6f5924258649';
    $display->content['new-71b7da01-f766-4854-a8a9-6f5924258649'] = $pane;
    $display->panels['contentmain'][2] = 'new-71b7da01-f766-4854-a8a9-6f5924258649';
    $pane = new stdClass();
    $pane->pid = 'new-5b5e030f-ad1e-4b9f-82a7-4d0e8107e517';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_phones';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'phone_international',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'allow_alpha' => 0,
        'as_tel_link' => 0,
        'components' => array(
          'numbertype' => 'numbertype',
          'country' => 0,
        ),
        'country_name_position' => 'after',
        'extension_prefix' => ' ext. ',
        'full_hcard' => 0,
        'numbertype_position' => 'before',
        'raw' => 0,
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
    $pane->uuid = '5b5e030f-ad1e-4b9f-82a7-4d0e8107e517';
    $display->content['new-5b5e030f-ad1e-4b9f-82a7-4d0e8107e517'] = $pane;
    $display->panels['contentmain'][3] = 'new-5b5e030f-ad1e-4b9f-82a7-4d0e8107e517';
    $pane = new stdClass();
    $pane->pid = 'new-a64ece39-2254-4f54-811c-2f4abcdf4d3e';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_email';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'email_default',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'a64ece39-2254-4f54-811c-2f4abcdf4d3e';
    $display->content['new-a64ece39-2254-4f54-811c-2f4abcdf4d3e'] = $pane;
    $display->panels['contentmain'][4] = 'new-a64ece39-2254-4f54-811c-2f4abcdf4d3e';
    $pane = new stdClass();
    $pane->pid = 'new-59fdb501-5d44-4453-ae91-2f095e4917e7';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:og_group_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'og_list_default',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '59fdb501-5d44-4453-ae91-2f095e4917e7';
    $display->content['new-59fdb501-5d44-4453-ae91-2f095e4917e7'] = $pane;
    $display->panels['sidebar'][0] = 'new-59fdb501-5d44-4453-ae91-2f095e4917e7';
    $pane = new stdClass();
    $pane->pid = 'new-0b017680-6db5-4ec2-941a-ba093bf1c518';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0b017680-6db5-4ec2-941a-ba093bf1c518';
    $display->content['new-0b017680-6db5-4ec2-941a-ba093bf1c518'] = $pane;
    $display->panels['sidebar'][1] = 'new-0b017680-6db5-4ec2-941a-ba093bf1c518';
    $pane = new stdClass();
    $pane->pid = 'new-50f09c0d-c418-46f8-ab15-9d410848fa42';
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
    $pane->uuid = '50f09c0d-c418-46f8-ab15-9d410848fa42';
    $display->content['new-50f09c0d-c418-46f8-ab15-9d410848fa42'] = $pane;
    $display->panels['sidebar'][2] = 'new-50f09c0d-c418-46f8-ab15-9d410848fa42';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-59fdb501-5d44-4453-ae91-2f095e4917e7';
  $panelizer->display = $display;
  $export['node:hr_office:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_office:default:search_result';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_office';
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
  $display->uuid = 'fb12a7ba-dc40-46dd-bfb7-e6cf37474352';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-93902138-dda8-422a-9a17-66ae1ca1a305';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '93902138-dda8-422a-9a17-66ae1ca1a305';
    $display->content['new-93902138-dda8-422a-9a17-66ae1ca1a305'] = $pane;
    $display->panels['contentmain'][0] = 'new-93902138-dda8-422a-9a17-66ae1ca1a305';
    $pane = new stdClass();
    $pane->pid = 'new-e39e89f6-8e35-409e-8897-ac4263fb4f5d';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_location';
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
    $pane->uuid = 'e39e89f6-8e35-409e-8897-ac4263fb4f5d';
    $display->content['new-e39e89f6-8e35-409e-8897-ac4263fb4f5d'] = $pane;
    $display->panels['contentmain'][1] = 'new-e39e89f6-8e35-409e-8897-ac4263fb4f5d';
    $pane = new stdClass();
    $pane->pid = 'new-1d12e74b-f207-4792-97ec-f93a8dad1e1b';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_phones';
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
    $pane->uuid = '1d12e74b-f207-4792-97ec-f93a8dad1e1b';
    $display->content['new-1d12e74b-f207-4792-97ec-f93a8dad1e1b'] = $pane;
    $display->panels['contentmain'][2] = 'new-1d12e74b-f207-4792-97ec-f93a8dad1e1b';
    $pane = new stdClass();
    $pane->pid = 'new-1df0bec3-3953-457e-9a28-53c16f22c928';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_email';
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
    $pane->uuid = '1df0bec3-3953-457e-9a28-53c16f22c928';
    $display->content['new-1df0bec3-3953-457e-9a28-53c16f22c928'] = $pane;
    $display->panels['contentmain'][3] = 'new-1df0bec3-3953-457e-9a28-53c16f22c928';
    $pane = new stdClass();
    $pane->pid = 'new-bf39e004-87af-410a-90b3-0cffbc9c9ca0';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'bf39e004-87af-410a-90b3-0cffbc9c9ca0';
    $display->content['new-bf39e004-87af-410a-90b3-0cffbc9c9ca0'] = $pane;
    $display->panels['contentmain'][4] = 'new-bf39e004-87af-410a-90b3-0cffbc9c9ca0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1d12e74b-f207-4792-97ec-f93a8dad1e1b';
  $panelizer->display = $display;
  $export['node:hr_office:default:search_result'] = $panelizer;

  return $export;
}
