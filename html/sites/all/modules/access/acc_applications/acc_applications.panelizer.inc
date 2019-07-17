<?php
/**
 * @file
 * acc_applications.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function acc_applications_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:acc_application:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'acc_application';
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
  $display->uuid = '31b23107-47fc-4ee3-81c3-5c8e4bdd4b73';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6306802a-9cee-4cb4-b848-9e5d80a0cb60';
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
    $pane->uuid = '6306802a-9cee-4cb4-b848-9e5d80a0cb60';
    $display->content['new-6306802a-9cee-4cb4-b848-9e5d80a0cb60'] = $pane;
    $display->panels['contentmain'][0] = 'new-6306802a-9cee-4cb4-b848-9e5d80a0cb60';
    $pane = new stdClass();
    $pane->pid = 'new-a646bd05-006d-4574-841a-8bcabd186ab1';
    $pane->panel = 'contentmain';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
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
    $pane->uuid = 'a646bd05-006d-4574-841a-8bcabd186ab1';
    $display->content['new-a646bd05-006d-4574-841a-8bcabd186ab1'] = $pane;
    $display->panels['contentmain'][1] = 'new-a646bd05-006d-4574-841a-8bcabd186ab1';
    $pane = new stdClass();
    $pane->pid = 'new-252b713a-c5b4-44d4-b260-697d586d3bdb';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_impacts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => 'Edit',
        'delete' => 'Delete',
        'add' => 'Add',
        'description' => 1,
        'view_mode' => 'full',
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
    $pane->uuid = '252b713a-c5b4-44d4-b260-697d586d3bdb';
    $display->content['new-252b713a-c5b4-44d4-b260-697d586d3bdb'] = $pane;
    $display->panels['contentmain'][2] = 'new-252b713a-c5b4-44d4-b260-697d586d3bdb';
    $pane = new stdClass();
    $pane->pid = 'new-1c8358bc-3d73-459a-ba6c-f9afffad3639';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_attach_file';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'file_default',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1c8358bc-3d73-459a-ba6c-f9afffad3639';
    $display->content['new-1c8358bc-3d73-459a-ba6c-f9afffad3639'] = $pane;
    $display->panels['contentmain'][3] = 'new-1c8358bc-3d73-459a-ba6c-f9afffad3639';
    $pane = new stdClass();
    $pane->pid = 'new-3513a308-fe0c-40c2-97a3-3e5a2fdfc1eb';
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
    $pane->uuid = '3513a308-fe0c-40c2-97a3-3e5a2fdfc1eb';
    $display->content['new-3513a308-fe0c-40c2-97a3-3e5a2fdfc1eb'] = $pane;
    $display->panels['sidebar'][0] = 'new-3513a308-fe0c-40c2-97a3-3e5a2fdfc1eb';
    $pane = new stdClass();
    $pane->pid = 'new-d9be8d7f-3754-468f-9ee4-0fb05b341fd2';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_application_types';
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
    $pane->uuid = 'd9be8d7f-3754-468f-9ee4-0fb05b341fd2';
    $display->content['new-d9be8d7f-3754-468f-9ee4-0fb05b341fd2'] = $pane;
    $display->panels['sidebar'][1] = 'new-d9be8d7f-3754-468f-9ee4-0fb05b341fd2';
    $pane = new stdClass();
    $pane->pid = 'new-946fee6b-e790-4fa2-8839-38574d75c013';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'long',
        'fromto' => 'both',
        'multiple_from' => '',
        'multiple_number' => '',
        'multiple_to' => '',
        'show_repeat_rule' => 'show',
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
    $pane->uuid = '946fee6b-e790-4fa2-8839-38574d75c013';
    $display->content['new-946fee6b-e790-4fa2-8839-38574d75c013'] = $pane;
    $display->panels['sidebar'][2] = 'new-946fee6b-e790-4fa2-8839-38574d75c013';
    $pane = new stdClass();
    $pane->pid = 'new-81695e3d-deb4-40f8-bcd8-18e7faff639c';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_submitted_by_org_type';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '81695e3d-deb4-40f8-bcd8-18e7faff639c';
    $display->content['new-81695e3d-deb4-40f8-bcd8-18e7faff639c'] = $pane;
    $display->panels['sidebar'][3] = 'new-81695e3d-deb4-40f8-bcd8-18e7faff639c';
    $pane = new stdClass();
    $pane->pid = 'new-f1881554-e191-4aed-aaa3-5ba8cc184d70';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_nationality';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f1881554-e191-4aed-aaa3-5ba8cc184d70';
    $display->content['new-f1881554-e191-4aed-aaa3-5ba8cc184d70'] = $pane;
    $display->panels['sidebar'][4] = 'new-f1881554-e191-4aed-aaa3-5ba8cc184d70';
    $pane = new stdClass();
    $pane->pid = 'new-111d872c-4f38-4edf-aaa6-8eb5cf300dc0';
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
      'override_title' => 1,
      'override_title_text' => 'Geographical Location (Origin)',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '111d872c-4f38-4edf-aaa6-8eb5cf300dc0';
    $display->content['new-111d872c-4f38-4edf-aaa6-8eb5cf300dc0'] = $pane;
    $display->panels['sidebar'][5] = 'new-111d872c-4f38-4edf-aaa6-8eb5cf300dc0';
    $pane = new stdClass();
    $pane->pid = 'new-485e9927-c777-4f9b-83a9-14dca3700a65';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_geo_location_dest';
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
    $pane->uuid = '485e9927-c777-4f9b-83a9-14dca3700a65';
    $display->content['new-485e9927-c777-4f9b-83a9-14dca3700a65'] = $pane;
    $display->panels['sidebar'][6] = 'new-485e9927-c777-4f9b-83a9-14dca3700a65';
    $pane = new stdClass();
    $pane->pid = 'new-5c4924db-3c9e-4afa-8ab7-6a6240c4a202';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_submitted_to';
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
    $pane->uuid = '5c4924db-3c9e-4afa-8ab7-6a6240c4a202';
    $display->content['new-5c4924db-3c9e-4afa-8ab7-6a6240c4a202'] = $pane;
    $display->panels['sidebar'][7] = 'new-5c4924db-3c9e-4afa-8ab7-6a6240c4a202';
    $pane = new stdClass();
    $pane->pid = 'new-d27f2cf6-da55-47cf-b96e-f5c57ba7c444';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_submission_status';
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
    $pane->uuid = 'd27f2cf6-da55-47cf-b96e-f5c57ba7c444';
    $display->content['new-d27f2cf6-da55-47cf-b96e-f5c57ba7c444'] = $pane;
    $display->panels['sidebar'][8] = 'new-d27f2cf6-da55-47cf-b96e-f5c57ba7c444';
    $pane = new stdClass();
    $pane->pid = 'new-74762c9b-f857-42dc-90b2-abb68ade5ff5';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_if_denied_by_whom_';
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
    $pane->uuid = '74762c9b-f857-42dc-90b2-abb68ade5ff5';
    $display->content['new-74762c9b-f857-42dc-90b2-abb68ade5ff5'] = $pane;
    $display->panels['sidebar'][9] = 'new-74762c9b-f857-42dc-90b2-abb68ade5ff5';
    $pane = new stdClass();
    $pane->pid = 'new-05be79ea-dcdb-4c12-a19a-f61739824fc6';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_how_many_days';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'decimal_separator' => '.',
        'prefix_suffix' => TRUE,
        'scale' => 0,
        'thousand_separator' => ' ',
      ),
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
    $pane->uuid = '05be79ea-dcdb-4c12-a19a-f61739824fc6';
    $display->content['new-05be79ea-dcdb-4c12-a19a-f61739824fc6'] = $pane;
    $display->panels['sidebar'][10] = 'new-05be79ea-dcdb-4c12-a19a-f61739824fc6';
    $pane = new stdClass();
    $pane->pid = 'new-81748cfc-59e9-4239-9203-2a07a8e08589';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_sector';
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
    $pane->uuid = '81748cfc-59e9-4239-9203-2a07a8e08589';
    $display->content['new-81748cfc-59e9-4239-9203-2a07a8e08589'] = $pane;
    $display->panels['sidebar'][11] = 'new-81748cfc-59e9-4239-9203-2a07a8e08589';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-3513a308-fe0c-40c2-97a3-3e5a2fdfc1eb';
  $panelizer->display = $display;
  $export['node:acc_application:default:default'] = $panelizer;

  return $export;
}
