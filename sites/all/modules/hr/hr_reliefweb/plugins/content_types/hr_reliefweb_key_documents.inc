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
    'limit' => 5,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_reliefweb_key_documents_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $dropdowns = hr_reliefweb_get_list_of_filters();
  $form['filters'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );
  foreach ($dropdowns as $name => $dropdown) {
    $form['filters'][$name] = array(
      '#title' => hr_reliefweb_get_dropdowns($name),
      '#type' => 'select',
      '#options' => $dropdown,
      '#required' => FALSE,
      '#empty_value' => '',
      '#default_value' => $conf['filters'][$name],
    );
  }

  $form['limit'] = array(
    '#title' => t('Number of documents to display'),
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
function hr_reliefweb_key_documents_edit_form_submit($form, &$form_state) {
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
function hr_reliefweb_key_documents_render($subtype, $conf, $panel_args, $context = NULL) {
  // initial content is blank
  $block = new stdClass();
  $block->title = 'Reliefweb documents';
  $block->content = '';

  // Override title.
  if ($conf['override_title']) {
    $block->title = $conf['override_title_text'];
  }

  $limit = $conf['limit'];

  // Build parameters and path.
  $filters = array();
  $path = current_path();
  $dropdowns = hr_reliefweb_get_dropdowns();
  foreach ($conf['filters'] as $filter => $value) {
    if ($value && isset($dropdowns[$filter])) {
      $filters[] = array(
        'field' => $dropdowns[$filter]['filter'],
        'value' => $value,
        'operator' => 'AND',
      );

      $path .= '/' . $dropdowns[$filter]['filter'] . '/' . $value;
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

    $read_more = '<div class="read-more">';
    $read_more .= '<a href="' . $path . '">' . t('Read more') . '</a>';
    $read_more .= '</div>';

    $block->content = $read_more . theme('links', array('links' => $links));
  }

  return $block;
}
