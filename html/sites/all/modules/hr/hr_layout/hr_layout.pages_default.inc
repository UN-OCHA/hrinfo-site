<?php

/**
 * @file
 * hr_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hr_layout_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_clusters';
  $page->task = 'page';
  $page->admin_title = 'Clusters';
  $page->admin_description = '';
  $page->path = 'clusters';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'main-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'Clusters',
    'type' => 'normal',
    'weight' => '4',
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clusters_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_clusters';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Landing page',
  );
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_clusters_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'clusters text',
    'body' => '<p>When emergencies occur coordination is necessary. Good coordination means less gaps and overlaps in the assistance delivered by humanitarian organizations.</p>

<p>The foundations of the current international humanitarian coordination system were set by General Assembly resolution 46/182 in December 1991. Almost 15 years later, in 2005, a major reform of humanitarian coordination, known as the Humanitarian Reform Agenda, introduced a number of new elements to enhance predictability, accountability and partnership. The Cluster Approach was one of these new elements.</p>

<p>Clusters are groups of humanitarian organizations, both UN and non-UN, in each of the main sectors of humanitarian action, e.g. water, health and logistics. They are designated by the Inter-Agency Standing Committee (IASC) and have clear responsibilities for coordination.</p>

<p class="text-center"><a class="btn btn-primary" href="/clusters/space">Read all the information about clusters</a></p>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2532dff5-41bf-471e-a491-cee72a7612f5';
  $display->content['new-2532dff5-41bf-471e-a491-cee72a7612f5'] = $pane;
  $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane = new stdClass();
  $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/clusters.png" class="img-responsive" alt="Cluster Approach" />',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->content['new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e'] = $pane;
  $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_clusters'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_coordination';
  $page->task = 'page';
  $page->admin_title = 'Coordination';
  $page->admin_description = '';
  $page->path = 'coordination';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'main-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'Coordination',
    'type' => 'normal',
    'weight' => '3',
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hr_coordination_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_coordination';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Landing page',
  );
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'column1' => NULL,
      'column2' => NULL,
      'default' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_hr_coordination_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Coordination text',
    'body' => '<p>Humanitarian coordination involves bringing together humanitarian actors to ensure a coherent and principled response to emergencies. The aim is to assist people when they most need relief or protection.</p>

<p>Humanitarian coordination seeks to improve the effectiveness of humanitarian response by ensuring greater predictability, accountability and partnership. Coordination involves assessing situations and needs; agreeing common priorities; developing common strategies to address issues such as negotiating access, mobilizing funding and other resources; clarifying consistent public messaging; and monitoring progress.</p>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2532dff5-41bf-471e-a491-cee72a7612f5';
  $display->content['new-2532dff5-41bf-471e-a491-cee72a7612f5'] = $pane;
  $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane = new stdClass();
  $pane->pid = 'new-029e719e-a02b-4a49-a595-69273bc5306d';
  $pane->panel = 'column1';
  $pane->type = 'views_panes';
  $pane->subtype = 'hr_spaces-panel_pane_2';
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
  $pane->uuid = '029e719e-a02b-4a49-a595-69273bc5306d';
  $display->content['new-029e719e-a02b-4a49-a595-69273bc5306d'] = $pane;
  $display->panels['column1'][1] = 'new-029e719e-a02b-4a49-a595-69273bc5306d';
  $pane = new stdClass();
  $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/coordination.jpg" class="img-responsive" alt="Coordination" />',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
    'title' => '',
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
  $pane->uuid = '4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->content['new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e'] = $pane;
  $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_coordination'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'main-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'Home',
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
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Landing page',
  );
  $display = new panels_display();
  $display->layout = 'radix_mccoppin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'contentmain' => array(
      'style' => 'default',
    ),
    'style_settings' => array(
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
      'contentmain' => NULL,
      'default' => NULL,
      'footer' => NULL,
      'half' => NULL,
      'header' => NULL,
      'quarter1' => NULL,
      'quarter2' => NULL,
      'secondarycolumn1' => NULL,
      'secondarycolumn2' => NULL,
      'secondarycolumn3' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array(
    'method' => 'hr_content',
    'settings' => array(
      'content_type' => 'hr_operation',
      'granularity' => array(
        'args' => 'args',
        'user_role' => 'user_role',
      ),
      'granularity_role_selection' => 'all',
      'granularity_roles_as_anon' => array(),
      'granularity_url' => 'base_url_system',
      'lifetime' => 922,
    ),
  );
  $display->title = 'Home';
  $display->uuid = 'b4f0cdd8-1e4b-4d49-b201-90e3bbd936dc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1b2873ca-a822-4a62-99fb-1fbe5ff6383f';
  $pane->panel = 'column1';
  $pane->type = 'block';
  $pane->subtype = 'hr_operations-operations_dropdown';
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
  $pane->uuid = '1b2873ca-a822-4a62-99fb-1fbe5ff6383f';
  $display->content['new-1b2873ca-a822-4a62-99fb-1fbe5ff6383f'] = $pane;
  $display->panels['column1'][0] = 'new-1b2873ca-a822-4a62-99fb-1fbe5ff6383f';
  $pane = new stdClass();
  $pane->pid = 'new-10e08847-b4f7-4575-9870-c63cfc926a04';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<iframe width="100%" height="200" src="https://www.youtube.com/embed/OAzNjYtabuM?rel=0&amp;controls=0&amp;showinfo=0" frameborder="0" allow="fullscreen"></iframe>',
    'format' => 'hr_wysiwyg',
    'substitute' => TRUE,
    'title' => 'What is HumanitarianResponse.info?',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'granularity' => 'none',
      'lifetime' => '604800',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '10e08847-b4f7-4575-9870-c63cfc926a04';
  $display->content['new-10e08847-b4f7-4575-9870-c63cfc926a04'] = $pane;
  $display->panels['column1'][1] = 'new-10e08847-b4f7-4575-9870-c63cfc926a04';
  $pane = new stdClass();
  $pane->pid = 'new-1c175875-c02e-4268-8e75-6082e1a438e5';
  $pane->panel = 'column2';
  $pane->type = 'block';
  $pane->subtype = 'hr_layout-hr_layout_key_documents';
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
  $pane->uuid = '1c175875-c02e-4268-8e75-6082e1a438e5';
  $display->content['new-1c175875-c02e-4268-8e75-6082e1a438e5'] = $pane;
  $display->panels['column2'][0] = 'new-1c175875-c02e-4268-8e75-6082e1a438e5';
  $pane = new stdClass();
  $pane->pid = 'new-78cb0576-14ee-40ca-886f-91a3ba356067';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<p><strong>Purpose:</strong> to support efficient, effective, and coordinated humanitarian response through the sharing of operational information.</p>

<p><strong>Goal: </strong>to be the place where the disaster response community can share, find, and collaborate on information to inform strategic decisions.</p>

<p><strong>Target audience:</strong> persons deployed to respond to complex emergencies and disasters.</p>
',
    'format' => 'hr_wysiwyg',
    'substitute' => TRUE,
    'title' => 'The Role of HumanitarianResponse.info',
    'title_heading' => 'h2',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'granularity' => 'none',
      'lifetime' => '604800',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '78cb0576-14ee-40ca-886f-91a3ba356067';
  $display->content['new-78cb0576-14ee-40ca-886f-91a3ba356067'] = $pane;
  $display->panels['column2'][1] = 'new-78cb0576-14ee-40ca-886f-91a3ba356067';
  $pane = new stdClass();
  $pane->pid = 'new-63730577-59cd-461b-812d-2c90c4ecdffe';
  $pane->panel = 'column3';
  $pane->type = 'block';
  $pane->subtype = 'hr_layout-hr_layout_hum_system';
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
  $pane->uuid = '63730577-59cd-461b-812d-2c90c4ecdffe';
  $display->content['new-63730577-59cd-461b-812d-2c90c4ecdffe'] = $pane;
  $display->panels['column3'][0] = 'new-63730577-59cd-461b-812d-2c90c4ecdffe';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_programme_cycle';
  $page->task = 'page';
  $page->admin_title = 'Programme Cycle';
  $page->admin_description = '';
  $page->path = 'programme-cycle';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'main-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'Programme Cycle',
    'type' => 'normal',
    'weight' => '6',
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hr_programme_cycle_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_programme_cycle';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Landing page',
  );
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'column1' => NULL,
      'column2' => NULL,
      'default' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_hr_programme_cycle_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Programme Cycle text',
    'body' => '<p>Welcome to the Humanitarian Programme Cycle space on HumanitarianResponse.info</p><p>The Humanitarian Programme Cycle (HPC) is the way in which humanitarian actors work together to help people affected by disasters and conflict. In these pages, you will find guidance, practical tools and templates as well as background information on the various elements which together make up the programme cycle.</p>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2532dff5-41bf-471e-a491-cee72a7612f5';
  $display->content['new-2532dff5-41bf-471e-a491-cee72a7612f5'] = $pane;
  $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane = new stdClass();
  $pane->pid = 'new-aae1a8c7-93d3-4578-8cc4-52f705db0898';
  $pane->panel = 'column1';
  $pane->type = 'views_panes';
  $pane->subtype = 'hr_spaces-panel_pane_1';
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
  $pane->uuid = 'aae1a8c7-93d3-4578-8cc4-52f705db0898';
  $display->content['new-aae1a8c7-93d3-4578-8cc4-52f705db0898'] = $pane;
  $display->panels['column1'][1] = 'new-aae1a8c7-93d3-4578-8cc4-52f705db0898';
  $pane = new stdClass();
  $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/programme-cycle.png" class="img-responsive" alt="Programme Cycle" />',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
    'title' => '',
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
  $pane->uuid = '4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->content['new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e'] = $pane;
  $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_programme_cycle'] = $page;

  return $pages;

}
