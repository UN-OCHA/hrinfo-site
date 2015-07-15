<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Static'),
  'description' => t('Chose which infographics you want to display.'),
  'category' => t('Infographics'),
  'edit form' => 'hr_infographics_key_infographics_edit_form',
  'render callback' => 'hr_infographics_key_infographics_render',
  'defaults' => array(
    'infographics' => '',
    'view_mode' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_infographics_key_infographics_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  if (isset($form_state['infographics_count'])) {
    $infographics_count = $form_state['infographics_count'];
  }
  else {
      $infographics_count = count($conf['infographics']);
  }

  // Add a wrapper for the infographics and more button.
  $form['infographics_wrapper'] = array(
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix" id="hr-infographics-key-wrapper">',
    '#suffix' => '</div>',
  );

  // Container for just the infographics.
  $form['infographics_wrapper']['infographics'] = array(
    '#prefix' => '<div id="hr-infographics-key-infographics">',
    '#suffix' => '</div>',
  );

  for ($delta = 0; $delta < $infographics_count; $delta++) {
    $form['infographics_wrapper']['infographics'][$delta] = array(
      '#type' => 'entityreference',
      '#title' => t('Infographic'),
      '#era_entity_type' => 'node',
      '#era_bundles' => array('hr_infographic'),
      '#era_cardinality' => 1,
      '#default_value' => isset($conf['infographics'][$delta]) ? $conf['infographics'][$delta] : '',
      '#parents' => array('infographics', $delta),
    );
  }

  // We name our button 'hr_infographics_key_list_more' to avoid conflicts with other modules using
  // Ajax-enabled buttons with the id 'more'.
  $form['infographics_wrapper']['hr_infographics_key_list_more'] = array(
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
function hr_infographics_key_infographics_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  if ($form_state['values']['hr_infographics_key_list_more']) {
    $form_state['infographics_count'] = count($form_state['values']['infographics']) + 1;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_infographics_key_infographics_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $infographics = $conf['infographics'];

  // initial content is blank
  $block->title = '';
  $block->content = '';
  if (!empty($infographics)) {

    foreach ($infographics as $infographic) {
      if (isset($infographic['entity_id'])) {
        $nid = $infographic['entity_id'];
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

