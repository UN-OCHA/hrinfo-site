<?php
/**
 * @file
 * hr_core.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function hr_core_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'hr_node_links';
  $mini->category = '';
  $mini->admin_title = 'Node links';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '87e7df65-5d1d-422b-b62d-1ef782415427';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b4fe4137-69b8-4f1e-aad6-a54ee3e456ac';
    $pane->panel = 'middle';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:hr_core_read_more_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = 'b4fe4137-69b8-4f1e-aad6-a54ee3e456ac';
    $display->content['new-b4fe4137-69b8-4f1e-aad6-a54ee3e456ac'] = $pane;
    $display->panels['middle'][0] = 'new-b4fe4137-69b8-4f1e-aad6-a54ee3e456ac';
    $pane = new stdClass();
    $pane->pid = 'new-93452cd9-2c94-4d17-80cc-b96c741c7d12';
    $pane->panel = 'middle';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:hr_core_share_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '93452cd9-2c94-4d17-80cc-b96c741c7d12';
    $display->content['new-93452cd9-2c94-4d17-80cc-b96c741c7d12'] = $pane;
    $display->panels['middle'][1] = 'new-93452cd9-2c94-4d17-80cc-b96c741c7d12';
    $pane = new stdClass();
    $pane->pid = 'new-a2140a2d-8922-4054-ba9e-ad7522568c43';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_files_collection';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'field_collection_fields',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = 'a2140a2d-8922-4054-ba9e-ad7522568c43';
    $display->content['new-a2140a2d-8922-4054-ba9e-ad7522568c43'] = $pane;
    $display->panels['middle'][2] = 'new-a2140a2d-8922-4054-ba9e-ad7522568c43';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-b4fe4137-69b8-4f1e-aad6-a54ee3e456ac';
  $mini->display = $display;
  $export['hr_node_links'] = $mini;

  return $export;
}
