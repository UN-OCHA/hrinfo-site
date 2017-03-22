<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Reliefweb documents'),
  'description' => t('Choose the Reliefweb documents you want to display.'),
  'category' => t('Documents'),
  'edit form' => 'hr_reliefweb_key_documents_edit_form',
  'render callback' => 'hr_reliefweb_key_documents_render',
  'defaults' => array(
    'country' => '',
    'theme' => '',
    'source' => '',
    'format' => '',
    'disaster_type' => '',
    'language' => '',
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
      '#title' => $name,
      '#type' => 'select',
      '#options' => $dropdown,
      '#required' => FALSE,
      '#empty_value' => '',
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
  $block = new stdClass();

  $documents = $conf['documents'];
  $view_mode = !empty($conf['view_mode']) ? $conf['view_mode'] : 'teaser';

  // initial content is blank
  $block->title = '';
  $block->content = '';
  if (!empty($documents)) {

    foreach ($documents as $document) {
      if (isset($document['entity_id'])) {
        $nid = $document['entity_id'];
        $node = node_load($nid);
        if ($node != FALSE) {
          if ($conf['view_mode'] == 'link') {
            $entity = entity_load_single('node', $nid);
            $block->content .= '<li>'.l(entity_label('node', $entity), 'node/'.$nid).'</li>';
          }
          else {
            $node_view = node_view($node, $view_mode);
            $block->content .= drupal_render($node_view);
          }
        }
      }
    }

    if ($conf['view_mode'] == 'link') {
      $block->content = '<ul>'.$block->content.'</ul>';
    }

    if (!empty($block->content)) {
      $block->content = '<div class="fieldable-panels-pane">'.$block->content.'</div>';
    }
  }

  return $block;
}
