<?php
/**
 * @file
 * hr_tools.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function hr_tools_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_toolbox_category:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_toolbox_category';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7b520a2e-247b-4cae-94fc-614c8a38742f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bccf9599-273d-444e-8975-f6735faf19c5';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_toolbox_panes-items';
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
    $pane->uuid = 'bccf9599-273d-444e-8975-f6735faf19c5';
    $display->content['new-bccf9599-273d-444e-8975-f6735faf19c5'] = $pane;
    $display->panels['middle'][0] = 'new-bccf9599-273d-444e-8975-f6735faf19c5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_toolbox_category:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_toolbox_category:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_toolbox_category';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'e037d441-8d37-4351-a05b-032bfc2c2dce';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-05948102-c4d1-49be-987f-7cf41ed90d84';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_toolbox_panes-items';
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
    $pane->uuid = '05948102-c4d1-49be-987f-7cf41ed90d84';
    $display->content['new-05948102-c4d1-49be-987f-7cf41ed90d84'] = $pane;
    $display->panels['middle'][0] = 'new-05948102-c4d1-49be-987f-7cf41ed90d84';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_toolbox_category:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_toolbox_item:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_toolbox_item';
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
  $display->uuid = '9ddcf5de-3f00-4549-a264-a30f5c4ac788';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8b5caba2-b2fc-4dc4-8968-b6324c6c0885';
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
    $pane->uuid = '8b5caba2-b2fc-4dc4-8968-b6324c6c0885';
    $display->content['new-8b5caba2-b2fc-4dc4-8968-b6324c6c0885'] = $pane;
    $display->panels['contentmain'][0] = 'new-8b5caba2-b2fc-4dc4-8968-b6324c6c0885';
    $pane = new stdClass();
    $pane->pid = 'new-889ec6dc-fdde-4dc3-a48e-cf3a7efa6528';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '889ec6dc-fdde-4dc3-a48e-cf3a7efa6528';
    $display->content['new-889ec6dc-fdde-4dc3-a48e-cf3a7efa6528'] = $pane;
    $display->panels['contentmain'][1] = 'new-889ec6dc-fdde-4dc3-a48e-cf3a7efa6528';
    $pane = new stdClass();
    $pane->pid = 'new-38c60b10-b7c3-4b5a-a82c-b5e323db83ef';
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
    $pane->uuid = '38c60b10-b7c3-4b5a-a82c-b5e323db83ef';
    $display->content['new-38c60b10-b7c3-4b5a-a82c-b5e323db83ef'] = $pane;
    $display->panels['contentmain'][2] = 'new-38c60b10-b7c3-4b5a-a82c-b5e323db83ef';
    $pane = new stdClass();
    $pane->pid = 'new-8e70cbe8-266d-4d3c-83ad-81db10a9cf2d';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_files';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'file_default',
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
    $pane->uuid = '8e70cbe8-266d-4d3c-83ad-81db10a9cf2d';
    $display->content['new-8e70cbe8-266d-4d3c-83ad-81db10a9cf2d'] = $pane;
    $display->panels['contentmain'][3] = 'new-8e70cbe8-266d-4d3c-83ad-81db10a9cf2d';
    $pane = new stdClass();
    $pane->pid = 'new-aeaf991e-0de0-417a-ba2b-105cad90f7ef';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_links';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'aeaf991e-0de0-417a-ba2b-105cad90f7ef';
    $display->content['new-aeaf991e-0de0-417a-ba2b-105cad90f7ef'] = $pane;
    $display->panels['contentmain'][4] = 'new-aeaf991e-0de0-417a-ba2b-105cad90f7ef';
    $pane = new stdClass();
    $pane->pid = 'new-4d12ae78-cdbf-48d4-adbc-46609706019f';
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
    $pane->uuid = '4d12ae78-cdbf-48d4-adbc-46609706019f';
    $display->content['new-4d12ae78-cdbf-48d4-adbc-46609706019f'] = $pane;
    $display->panels['sidebar'][0] = 'new-4d12ae78-cdbf-48d4-adbc-46609706019f';
    $pane = new stdClass();
    $pane->pid = 'new-bf8fb68d-3d30-458c-b251-f433b64d8817';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_toolbox_categories';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bf8fb68d-3d30-458c-b251-f433b64d8817';
    $display->content['new-bf8fb68d-3d30-458c-b251-f433b64d8817'] = $pane;
    $display->panels['sidebar'][1] = 'new-bf8fb68d-3d30-458c-b251-f433b64d8817';
    $pane = new stdClass();
    $pane->pid = 'new-238450f2-33a8-45c3-a656-744037171ab5';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_toolbox_item_type';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '238450f2-33a8-45c3-a656-744037171ab5';
    $display->content['new-238450f2-33a8-45c3-a656-744037171ab5'] = $pane;
    $display->panels['sidebar'][2] = 'new-238450f2-33a8-45c3-a656-744037171ab5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-4d12ae78-cdbf-48d4-adbc-46609706019f';
  $panelizer->display = $display;
  $export['node:hr_toolbox_item:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:hr_toolbox_item:default:search_result';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'hr_toolbox_item';
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
  $display->uuid = 'a0c9a3c0-bff6-4e94-bdef-d5684d328e81';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9af85668-75e6-4faa-ba7e-c6fbcc202854';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_toolbox_categories';
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
    $pane->uuid = '9af85668-75e6-4faa-ba7e-c6fbcc202854';
    $display->content['new-9af85668-75e6-4faa-ba7e-c6fbcc202854'] = $pane;
    $display->panels['contentmain'][0] = 'new-9af85668-75e6-4faa-ba7e-c6fbcc202854';
    $pane = new stdClass();
    $pane->pid = 'new-4faf0af5-7743-46cf-a86a-a332624301e9';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_toolbox_item_type';
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
    $pane->uuid = '4faf0af5-7743-46cf-a86a-a332624301e9';
    $display->content['new-4faf0af5-7743-46cf-a86a-a332624301e9'] = $pane;
    $display->panels['contentmain'][1] = 'new-4faf0af5-7743-46cf-a86a-a332624301e9';
    $pane = new stdClass();
    $pane->pid = 'new-48a6426f-faec-4666-9fb9-7c3705d59691';
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
    $pane->uuid = '48a6426f-faec-4666-9fb9-7c3705d59691';
    $display->content['new-48a6426f-faec-4666-9fb9-7c3705d59691'] = $pane;
    $display->panels['contentmain'][2] = 'new-48a6426f-faec-4666-9fb9-7c3705d59691';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:hr_toolbox_item:default:search_result'] = $panelizer;

  return $export;
}
