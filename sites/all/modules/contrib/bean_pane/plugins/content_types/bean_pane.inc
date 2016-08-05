<?php

/**
 * @file
 * Plugin to handle the 'bean' content type which allows individual bean
 * to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title'             => t('Bean Pane'),
  'description'       => t('Add a bean from your site as content.'),
  'content types'     => 'ctools_bean_content_type_content_types',
  'single'            => FALSE,
  'no title override' => TRUE,
  'defaults'          => array(
    'view_mode'  => 'full',
    'bean_delta' => '',
  ),
  'category'          => t('Bean Pane'),
  'edit form'         => 'ctools_bean_pane_content_type_edit_form',
  'render callback'   => 'ctools_bean_pane_content_type_render',
  'admin title'       => 'ctools_bean_pane_content_type_admin_title',
);

/**
 * Return an info array for a specific custom content type.
 */
function _ctools_bean_content_type_content_type($bean_type) {
  $bean_type_name = $bean_type->type;
  $info           = array(
    'name'         => $bean_type_name,
    'title'        => t('Add New: @type', array('@type' => strtoupper($bean_type_name))),
    'description'  => t('Add new bean: @type', array('@type' => strtoupper($bean_type_name))),
    'category'     => t('Bean Pane'),
    'all contexts' => TRUE,
    // 'icon' => 'icon_block_custom.png',.
    'add form'     => array(
      'ctools_bean_pane_content_type_form' => t('Add new @type', array('@type' => $bean_type_name)),
    ),
    'edit form'    => array(
      'ctools_bean_pane_content_type_form' => t('Edit content'),
    ),
  );

  return $info;
}

/**
 * Selection form for existing bean.
 */
function ctools_bean_content_type_selection_form($form, &$form_state) {
  $conf         = $form_state['conf'];
  $beans        = bean_get_all_beans();
  $bean_options = array();
  foreach ($beans as $bean) {
    $bean_options[$bean->delta] = $bean->label;
  }
  // Order by label.
  if (!empty($bean_options) && is_array($bean_options)) {
    natsort($bean_options);
  }

  $form['bean_delta'] = array(
    '#type'          => 'select',
    '#options'       => $bean_options,
    '#title'         => t('Bean'),
    '#description'   => t('Select the bean you want to display.'),
    '#default_value' => $conf['bean_delta'],
  );
  $form['#submit'][]  = 'ctools_bean_pane_content_type_selection_form_return_submit';

  return $form;
}

/**
 * Save selected view mode.
 */
function ctools_bean_pane_content_type_selection_form_return_submit($form, &$form_state) {
  if (isset($form_state['values']['bean_delta'])) {
    $form_state['conf']['bean_delta'] = $form_state['values']['bean_delta'];
  }
}

/**
 * Return all bean types.
 */
function ctools_bean_content_type_content_types() {
  $ctools_content_types = &drupal_static(__FUNCTION__, array());
  if (!empty($ctools_content_types)) {
    return $ctools_content_types;
  }

  foreach (bean_get_types() as $name => $bean_type) {
    $ctools_content_types[$name] = _ctools_bean_content_type_content_type($bean_type);
  }
  // Add an existing node.
  $ctools_content_types['existing_bean'] = array(
    'title'       => t('Choose an existing bean'),
    'description' => t('Add a bean from your site as content.'),
    'add form'    => array(
      'ctools_bean_content_type_selection_form' => t('Choose an existing bean'),
      'ctools_bean_pane_content_type_form'      => t('Config bean'),
    ),
    'edit form'   => array(
      'ctools_bean_pane_content_type_form' => t('Edit content'),
    ),
    'category'    => t('Bean Pane'),
  );
  return $ctools_content_types;
}

/**
 * Submit handler for the add form.
 */
function ctools_bean_pane_content_type_form_return_submit(&$form, &$form_state) {
  module_load_include('inc', 'bean', 'includes/bean.pages');
  bean_form_submit($form, $form_state);
  $form_state['conf']['bean_delta'] = $form_state['bean']->delta;
  $form_state['conf']['view_mode']  = $form_state['bean']->view_mode;
}

/**
 * Output function for the 'node' content type.
 *
 * Outputs a node based on the module and delta supplied in the configuration.
 */
function ctools_bean_pane_content_type_render($subtype, $conf, $panel_args) {
  $block         = new stdClass();
  $block->module = 'bean_pane';
  $delta         = $conf['bean_delta'];
  $view_mode     = $conf['view_mode'];
  $block->delta  = 'bean_pane' . '-' . str_replace('-', '_', $view_mode) . '-' . str_replace('-', '_', $delta);
  // Default to empty.
  $block->content = FALSE;
  if (($bean = bean_load_delta($delta))) {
    // Bean delta exists.
    if (bean_access('view', $bean)) {
      if (!empty($bean->title)) {
        $block->title = check_plain($bean->title);
      }
      $block->content = $bean->view($view_mode);
      $block->content['#contextual_links']['bean'] = array('block', array($delta));
    }
  }

  return $block;
}

/**
 * Title display for bean pane.
 */
function ctools_bean_pane_content_type_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Bean Pane');
  if (!empty($conf['override_title']) && !empty($conf['override_title_text'])) {
    $output = $output . ": " . filter_xss_admin($conf['override_title_text']);
  }
  else {
    if (!empty($conf['bean_delta']) && $bean = bean_delta_load($conf['bean_delta'])) {
      $bean_title = empty($bean->title) ? $bean->label : $bean->title;
      $output     = $output . ": " . filter_xss_admin($bean_title);
    }
    else {
      $output = '<i style="color:red">' . t('This block content is removed, please remove it.') . '</i>';
    }
  }

  return $output;
}
