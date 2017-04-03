<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('OCHA products'),
  'description' => t('OCHA products block.'),
  'category' => t('Documents'),
  'edit form' => 'hr_reliefweb_ocha_products_edit_form',
  'render callback' => 'hr_reliefweb_ocha_products_render',
  'defaults' => array(
    'hno_id' => '',
    'srp_id' => '',
    'monr_id' => '',
    'opr_id' => '',
    'orp_id' => '',
    'hno_title' => '',
    'srp_title' => '',
    'monr_title' => '',
    'opr_title' => '',
    'orp_title' => '',
    'show_sitrep' => TRUE,
    'show_humbul' => TRUE,
    'show_humsnap' => TRUE,
    'show_humdash' => TRUE,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_reliefweb_ocha_products_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['response_planning'] = array(
    '#type' => 'fieldset',
    '#title' => t('Response planning'),
  );

  $form['response_planning']['hno_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Humanitarian Needs Overview'),
    '#default_value' => $conf['hno_title'],
    '#autocomplete_path' => 'reliefweb/hno/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['srp_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Strategic Response Plan'),
    '#default_value' => $conf['srp_title'],
    '#autocomplete_path' => 'reliefweb/srp/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['monr_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Periodic Monitoring Report'),
    '#default_value' => $conf['monr_title'],
    '#autocomplete_path' => 'reliefweb/monr/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['opr_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Operational Peer Review Summary'),
    '#default_value' => $conf['opr_title'],
    '#autocomplete_path' => 'reliefweb/opr/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['orp_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Response plan'),
    '#default_value' => $conf['orp_title'],
    '#autocomplete_path' => 'reliefweb/orp/autocomplete',
    '#maxlength' => 512,
  );

  $form['ocha_products'] = array(
    '#type' => 'fieldset',
    '#title' => t('OCHA Products'),
  );

  $form['ocha_products']['show_sitrep'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest sitrep'),
    '#default_value' => $conf['show_sitrep'],
  );

  $form['ocha_products']['show_humbul'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest humanitarian bulletin'),
    '#default_value' => $conf['show_humbul'],
  );

  $form['ocha_products']['show_humsnap'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest humanitarian snapshot'),
    '#default_value' => $conf['show_humsnap'],
  );

  $form['ocha_products']['show_humdash'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest humanitarian dashboard'),
    '#default_value' => $conf['show_humdash'],
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hr_reliefweb_ocha_products_edit_form_submit($form, &$form_state) {
  foreach (array('hno', 'srp', 'monr', 'opr', 'orp') as $base) {
    if (preg_match("/\s\((\d+)\)$/", $form_state['values'][$base . '_title'], $matches)) {
      $form_state['conf'][$base . '_title'] = $form_state['values'][$base . '_title'];
      $form_state['conf'][$base . '_id'] = $matches[1];
    }
  }

  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_reliefweb_ocha_products_render($subtype, $conf, $panel_args, $context = NULL) {
  // initial content is blank
  $block = new stdClass();
  $block->title = 'OCHA products';
  $block->content = '';

  // Override title.
  if ($conf['override_title']) {
    $block->title = $conf['override_title_text'];
  }

  $block->content = 'No output yet';
  return $block;
}
