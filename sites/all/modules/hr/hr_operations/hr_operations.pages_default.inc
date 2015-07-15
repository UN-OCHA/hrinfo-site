<?php
/**
 * @file
 * hr_operations.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hr_operations_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_operations';
  $page->task = 'page';
  $page->admin_title = 'Operations';
  $page->admin_description = '';
  $page->path = 'operations';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Operations',
    'name' => 'main-menu',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hr_operations_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_operations';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
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
  $display->title = '';
  $display->uuid = 'cb51fde1-8469-4d99-9470-0cfe51a2e382';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b068c086-ea38-43cd-bdad-b4bb3d809c16';
    $pane->panel = 'contentmain';
    $pane->type = 'block';
    $pane->subtype = 'hr_operations-operations_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'b068c086-ea38-43cd-bdad-b4bb3d809c16';
    $display->content['new-b068c086-ea38-43cd-bdad-b4bb3d809c16'] = $pane;
    $display->panels['contentmain'][0] = 'new-b068c086-ea38-43cd-bdad-b4bb3d809c16';
    $pane = new stdClass();
    $pane->pid = 'new-45c370e9-66aa-49df-8656-dcad7b670d30';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_operations-text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '45c370e9-66aa-49df-8656-dcad7b670d30';
    $display->content['new-45c370e9-66aa-49df-8656-dcad7b670d30'] = $pane;
    $display->panels['contentmain'][1] = 'new-45c370e9-66aa-49df-8656-dcad7b670d30';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_operations'] = $page;

  return $pages;

}
