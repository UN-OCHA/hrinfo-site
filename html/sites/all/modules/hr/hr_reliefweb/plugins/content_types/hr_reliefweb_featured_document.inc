<?php

/**
 * @file
 * Featured document plugin.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Featured document'),
  'description' => t('Chose which document you want to display as featured.'),
  'category' => t('Documents'),
  'edit form' => 'hr_reliefweb_featured_document_edit_form',
  'render callback' => 'hr_reliefweb_featured_document_render',
  'defaults' => array(
    'doc_id' => '',
    'doc_title' => '',
  ),
);

/**
 * Edit form callback for the content type.
 */
function hr_reliefweb_featured_document_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['doc_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Document title'),
    '#autocomplete_path' => 'reliefweb/autocomplete',
    '#default_value' => $conf['doc_title'],
    '#maxlength' => 512,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hr_reliefweb_featured_document_edit_form_submit($form, &$form_state) {
  if (preg_match("/\s\((\d+)\)$/", $form_state['values']['doc_title'], $matches)) {
    $form_state['conf']['doc_title'] = $form_state['values']['doc_title'];
    $form_state['conf']['doc_id'] = $matches[1];
  }

  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @See ctools_plugin_examples for more advanced info.
 */
function hr_reliefweb_featured_document_render($subtype, $conf, $panel_args, $context = NULL) {
  // Initial content is blank.
  $block = new stdClass();
  $block->title = 'Featured reliefweb documents';
  $block->content = '';

  // Override title.
  if ($conf['override_title']) {
    $block->title = $conf['override_title_text'];
  }

  $filters[] = array(
    'field' => 'id',
    'value' => $conf['doc_id'],
    'operator' => 'AND',
  );

  $data = hr_reliefweb_fetch_documents('', 1, 0, $filters);
  if (!empty($data['data'])) {
    foreach ($data['data'] as $key => $value) {
      $downloads = array();
      if (isset($value['files'])) {
        // Only show first file.
        $file = reset($value['files']);
        if (isset($file['preview']) && !empty($file['preview'])) {
          $downloads[] = '<a target="reliefweb" title="' . $file['description'] . '" href = ' . $file['url'] . '>' . theme('image', array('path' => $file['preview'])) . '</a>';
        }
        else {
          $downloads[] = '<a target="reliefweb" title="' . $file['description'] . '" href = ' . $file['url'] . '>' . t('Download !file', array('!file' => $file['filename'])) . '</a>';
        }
      }
      $rows[] = array(
        array(
          'data' => !empty($downloads) ? implode(' ', $downloads) : '',
          'class' => 'reliefweb--doc-type--download',
        ),
        array(
          'data' => '<a target="reliefweb" href = ' . $value['url'] . '> ' . $value['title'] . '</a>',
          'class' => 'reliefweb--doc-type--title',
        ),
      );
    }
    $block->content = theme('table', array('rows' => $rows));
  }

  return $block;
}
