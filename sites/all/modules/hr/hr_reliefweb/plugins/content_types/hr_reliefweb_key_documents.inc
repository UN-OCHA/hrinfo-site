<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Reliefweb documents'),
  'description' => t('Choose the Reliefweb documents you want to display.'),
  'category' => t('Documents'),
  'edit form' => 'hr_reliefweb_key_documents_edit_form',
  'render callback' => 'hr_reliefweb_key_documents_render',
  'defaults' => array(
    'filters' => array(
      'country' => '',
      'theme' => '',
      'source' => '',
      'format' => '',
      'disaster_type' => '',
      'language' => '',
    ),
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_reliefweb_key_documents_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $dropdowns = hr_reliefweb_get_list_of_filters();
  foreach ($dropdowns as $name => $dropdown) {
    $form[$name] = array(
      '#title' => hr_reliefweb_get_dropdowns($name),
      '#type' => 'select',
      '#options' => $dropdown,
      '#required' => FALSE,
      '#empty_value' => '',
      '#default_value' => $conf['filters'][$name],
    );
  }

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hr_reliefweb_key_documents_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_reliefweb_key_documents_render($subtype, $conf, $panel_args, $context = NULL) {
  $limit = 5;
  $block = new stdClass();
  dpm($conf['filters']);

  // Build parameters.
  $filters = array();
  $dropdowns = hr_reliefweb_get_dropdowns();
  foreach ($conf['filters'] as $filter => $value) {
    if ($value && isset($dropdowns[$filter])) {
      $filters[] = array(
        'field' => $dropdowns[$filter]['field'],
        'value' => $value,
        'operator' => 'AND',
      );
    }
  }

  $data = hr_reliefweb_fetch_documents('', $limit, 0, $filters);
  dpm($data);
  // initial content is blank
  $block->title = '';
  $block->content = '';
  if (!empty($documents)) {
    if ($conf['view_mode'] == 'link') {
      $block->content = '<ul>'.$block->content.'</ul>';
    }

    if (!empty($block->content)) {
      $block->content = '<div class="fieldable-panels-pane">'.$block->content.'</div>';
    }
  }

  return $block;
}
