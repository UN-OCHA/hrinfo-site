<?php
/**
 * @file
 * acc_incidents.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function acc_incidents_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:acc_incident:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'acc_incident';
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
  $display->uuid = '7908b3e3-8faf-46a9-8226-bb1627ecd7d4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-07acdea2-1eb3-4bb3-9656-140f22dfe1e2';
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
    $pane->uuid = '07acdea2-1eb3-4bb3-9656-140f22dfe1e2';
    $display->content['new-07acdea2-1eb3-4bb3-9656-140f22dfe1e2'] = $pane;
    $display->panels['contentmain'][0] = 'new-07acdea2-1eb3-4bb3-9656-140f22dfe1e2';
    $pane = new stdClass();
    $pane->pid = 'new-0d27fd0b-b429-43e6-9dc1-ca566ed7e3b4';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0d27fd0b-b429-43e6-9dc1-ca566ed7e3b4';
    $display->content['new-0d27fd0b-b429-43e6-9dc1-ca566ed7e3b4'] = $pane;
    $display->panels['contentmain'][1] = 'new-0d27fd0b-b429-43e6-9dc1-ca566ed7e3b4';
    $pane = new stdClass();
    $pane->pid = 'new-edf35888-56ec-494d-adce-ff2c506d1429';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_impacts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'field_collection_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'add' => 'Add',
        'delete' => 'Delete',
        'description' => TRUE,
        'edit' => 'Edit',
        'view_mode' => 'full',
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
    $pane->uuid = 'edf35888-56ec-494d-adce-ff2c506d1429';
    $display->content['new-edf35888-56ec-494d-adce-ff2c506d1429'] = $pane;
    $display->panels['contentmain'][2] = 'new-edf35888-56ec-494d-adce-ff2c506d1429';
    $pane = new stdClass();
    $pane->pid = 'new-e4d77aed-b410-41af-ba91-e599daf1f3f0';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_attach_file';
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
    $pane->uuid = 'e4d77aed-b410-41af-ba91-e599daf1f3f0';
    $display->content['new-e4d77aed-b410-41af-ba91-e599daf1f3f0'] = $pane;
    $display->panels['contentmain'][3] = 'new-e4d77aed-b410-41af-ba91-e599daf1f3f0';
    $pane = new stdClass();
    $pane->pid = 'new-25ecad9c-5855-434a-8534-17ea197a35d8';
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
    $pane->uuid = '25ecad9c-5855-434a-8534-17ea197a35d8';
    $display->content['new-25ecad9c-5855-434a-8534-17ea197a35d8'] = $pane;
    $display->panels['sidebar'][0] = 'new-25ecad9c-5855-434a-8534-17ea197a35d8';
    $pane = new stdClass();
    $pane->pid = 'new-ce8673af-6e64-4901-b3ad-fa37e472c0b9';
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
        'format_type' => 'hr_1',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ce8673af-6e64-4901-b3ad-fa37e472c0b9';
    $display->content['new-ce8673af-6e64-4901-b3ad-fa37e472c0b9'] = $pane;
    $display->panels['sidebar'][1] = 'new-ce8673af-6e64-4901-b3ad-fa37e472c0b9';
    $pane = new stdClass();
    $pane->pid = 'new-aebfffb4-680f-4b0b-894f-1a118e10c5f9';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acc_type';
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
    $pane->uuid = 'aebfffb4-680f-4b0b-894f-1a118e10c5f9';
    $display->content['new-aebfffb4-680f-4b0b-894f-1a118e10c5f9'] = $pane;
    $display->panels['sidebar'][2] = 'new-aebfffb4-680f-4b0b-894f-1a118e10c5f9';
    $pane = new stdClass();
    $pane->pid = 'new-5e71e8cc-c447-4393-a196-583c83fa7f85';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_type_of_affectee';
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
    $pane->uuid = '5e71e8cc-c447-4393-a196-583c83fa7f85';
    $display->content['new-5e71e8cc-c447-4393-a196-583c83fa7f85'] = $pane;
    $display->panels['sidebar'][3] = 'new-5e71e8cc-c447-4393-a196-583c83fa7f85';
    $pane = new stdClass();
    $pane->pid = 'new-612fcec0-15d7-4328-815a-a1e2424d4114';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '612fcec0-15d7-4328-815a-a1e2424d4114';
    $display->content['new-612fcec0-15d7-4328-815a-a1e2424d4114'] = $pane;
    $display->panels['sidebar'][4] = 'new-612fcec0-15d7-4328-815a-a1e2424d4114';
    $pane = new stdClass();
    $pane->pid = 'new-89941a42-05e8-4629-ac40-8604d9b59a2a';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_affected_organization_type';
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
    $pane->uuid = '89941a42-05e8-4629-ac40-8604d9b59a2a';
    $display->content['new-89941a42-05e8-4629-ac40-8604d9b59a2a'] = $pane;
    $display->panels['sidebar'][5] = 'new-89941a42-05e8-4629-ac40-8604d9b59a2a';
    $pane = new stdClass();
    $pane->pid = 'new-38d196a0-2914-4293-a837-c2bb471b68b9';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_affected_organizations';
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
    $pane->uuid = '38d196a0-2914-4293-a837-c2bb471b68b9';
    $display->content['new-38d196a0-2914-4293-a837-c2bb471b68b9'] = $pane;
    $display->panels['sidebar'][6] = 'new-38d196a0-2914-4293-a837-c2bb471b68b9';
    $pane = new stdClass();
    $pane->pid = 'new-8c40a63c-dee9-4879-974a-d3c99e39b83e';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_responsible_organization_t';
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
    $pane->uuid = '8c40a63c-dee9-4879-974a-d3c99e39b83e';
    $display->content['new-8c40a63c-dee9-4879-974a-d3c99e39b83e'] = $pane;
    $display->panels['sidebar'][7] = 'new-8c40a63c-dee9-4879-974a-d3c99e39b83e';
    $pane = new stdClass();
    $pane->pid = 'new-1cc2ee22-9ee2-4831-aaf9-87403d958f76';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_responsible_actors';
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
    $pane->uuid = '1cc2ee22-9ee2-4831-aaf9-87403d958f76';
    $display->content['new-1cc2ee22-9ee2-4831-aaf9-87403d958f76'] = $pane;
    $display->panels['sidebar'][8] = 'new-1cc2ee22-9ee2-4831-aaf9-87403d958f76';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-25ecad9c-5855-434a-8534-17ea197a35d8';
  $panelizer->display = $display;
  $export['node:acc_incident:default:default'] = $panelizer;

  return $export;
}
