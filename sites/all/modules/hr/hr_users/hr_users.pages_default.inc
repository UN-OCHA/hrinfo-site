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
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'My Check-ins',
    'name' => 'user-menu',
    'weight' => '0',
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
  $handler->name = 'page_hr_user_check_ins_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_user_check_ins';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '83f22f06-0840-485a-be75-cc9bf6bef892';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-470fc1ad-ac6f-4965-bb03-7a7586cf9e3c';
    $pane->panel = 'contentmain';
    $pane->type = 'hid_profiles_checkins';
    $pane->subtype = 'hid_profiles_checkins';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'gid' => '',
      'hno' => '',
      'srp' => '',
      'monr' => '',
      'opr' => '',
      'orp' => '',
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
    $pane->uuid = '470fc1ad-ac6f-4965-bb03-7a7586cf9e3c';
    $display->content['new-470fc1ad-ac6f-4965-bb03-7a7586cf9e3c'] = $pane;
    $display->panels['contentmain'][0] = 'new-470fc1ad-ac6f-4965-bb03-7a7586cf9e3c';
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
    $display->panels['contentmain'][1] = 'new-6a11c7c6-b8d4-4f6d-9ace-a107c2d436f7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_user_check_ins'] = $page;

  return $pages;

}
