<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Assessments (remote)'),
  'description' => t('Choose the Assessments you want to display.'),
  'category' => t('Assessments'),
  'edit form' => 'ar_assessments_key_assessments_edit_form',
  'render callback' => 'ar_assessments_key_assessments_render',
  'defaults' => array(
    'filters' => array(
      'operation' => '',
      'source' => '',
    ),
    'limit' => 5,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function ar_assessments_key_assessments_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $dropdowns = ar_assessments_get_list_of_filters();
  $form['filters'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );
  foreach ($dropdowns as $name => $dropdown) {
    $form['filters'][$name] = array(
      '#title' => $name,
      '#type' => 'select',
      '#options' => $dropdown,
      '#required' => FALSE,
      '#empty_value' => '',
      '#default_value' => $conf['filters'][$name],
    );
  }

  $form['limit'] = array(
    '#title' => t('Number of assessments to display'),
    '#type' => 'select',
    '#options' => array_combine(range(1, 10), range(1, 10)),
    '#required' => TRUE,
    '#default_value' => $conf['limit'],
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function ar_assessments_key_assessments_edit_form_submit($form, &$form_state) {
  $form_state['conf']['limit'] = $form_state['values']['limit'];
  foreach ($form_state['values']['filters'] as $key => $value) {
    $form_state['conf']['filters'][$key] = $value;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function ar_assessments_key_assessments_render($subtype, $conf, $panel_args, $context = NULL) {
  // initial content is blank
  $block = new stdClass();
  $block->title = 'Reliefweb documents';
  $block->content = '';

  // Override title.
  if ($conf['override_title']) {
    $block->title = $conf['override_title_text'];
  }

  $limit = $conf['limit'];

  // Build parameters.
  $filters = array();
  $dropdowns = hr_reliefweb_get_dropdowns();
  foreach ($conf['filters'] as $filter => $value) {
    if ($value && isset($dropdowns[$filter])) {
      $filters[] = array(
        'field' => $dropdowns[$filter]['filter'],
        'value' => $value,
        'operator' => 'AND',
      );
    }
  }

  $data = hr_reliefweb_fetch_documents('', $limit, 0, $filters);
  if (!empty($data['data'])) {
    $links = array();
    foreach ($data['data'] as $key => $value) {
      $links[] = array(
        'title' => $value['title'],
        'href' => $value['url'],
      );
    }
    $block->content = theme('links', array('links' => $links));
  }

  return $block;
}
