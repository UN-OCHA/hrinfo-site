<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Static'),
  'description' => t('Chose the documents you want to display.'),
  'category' => t('Documents'),
  'edit form' => 'hr_documents_key_documents_edit_form',
  'render callback' => 'hr_documents_key_documents_render',
  'defaults' => array(
    'documents' => '',
    'view_mode' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_documents_key_documents_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  if (isset($form_state['documents_count'])) {
    $documents_count = $form_state['documents_count'];
  }
  else {
    $documents_count = count($conf['documents']);
  }

  // Add a wrapper for the documents and more button.
  $form['documents_wrapper'] = array(
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix" id="hr-documents-key-wrapper">',
    '#suffix' => '</div>',
  );

  // Container for just the documents.
  $form['documents_wrapper']['documents'] = array(
    '#prefix' => '<div id="hr-documents-key-documents">',
    '#suffix' => '</div>',
  );

  for ($delta = 0; $delta < $documents_count; $delta++) {
    $form['documents_wrapper']['documents'][$delta] = array(
      '#type' => 'entityreference',
      '#title' => t('Document'),
      '#era_entity_type' => 'node',
      '#era_bundles' => array('hr_document'),
      '#era_cardinality' => 1,
      '#default_value' => isset($conf['documents'][$delta]) ? $conf['documents'][$delta] : '',
      '#parents' => array('documents', $delta),
    );
  }

  // We name our button 'hr_documents_key_list_more' to avoid conflicts with other modules using
  // Ajax-enabled buttons with the id 'more'.
  $form['documents_wrapper']['hr_documents_key_list_more'] = array(
    '#type' => 'submit',
    '#value' => t('Add another item'),
  );

  $form['view_mode'] = array(
    '#type' => 'select',
    '#title' => t('View mode'),
    '#options' => array(
      'teaser' => t('Teaser'),
      'default' => t('Full'),
      'link' => t('Links'),
    ),
    '#default_value' => isset($conf['view_more']) ? $conf['view_more'] : '',
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hr_documents_key_documents_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  if ($form_state['values']['hr_documents_key_list_more']) {
    $form_state['documents_count'] = count($form_state['values']['documents']) + 1;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_documents_key_documents_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $documents = $conf['documents'];
  $conf['view_mode'] = !empty($conf['view_mode']) ? $conf['view_mode'] : 'teaser';

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
            $block->content .= drupal_render(node_view($node, $conf['view_mode']));
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

