<?php

/**
 * @file
 * hr_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hr_users_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_user_check_ins';
  $page->task = 'page';
  $page->admin_title = 'User check-ins';
  $page->admin_description = '';
  $page->path = 'check-ins';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'user-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'My Spaces',
    'type' => 'normal',
    'weight' => '0',
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hr_user_check_ins_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_user_check_ins';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(
      0 => array(
        'id' => 1,
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
      ),
    ),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
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
  $display->title = '';
  $display->uuid = '83f22f06-0840-485a-be75-cc9bf6bef892';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_hr_user_check_ins_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6a11c7c6-b8d4-4f6d-9ace-a107c2d436f7';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'hr_user_memberships-checkins';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'context_user_1',
    ),
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
  $pane->uuid = '6a11c7c6-b8d4-4f6d-9ace-a107c2d436f7';
  $display->content['new-6a11c7c6-b8d4-4f6d-9ace-a107c2d436f7'] = $pane;
  $display->panels['contentmain'][0] = 'new-6a11c7c6-b8d4-4f6d-9ace-a107c2d436f7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_user_check_ins'] = $page;

  return $pages;

}
