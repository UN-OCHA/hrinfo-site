<?php

/**
 * @file
 * Administration functions for the snap module.
 */

/**
 * Admin settings form callback.
 */
function ocha_snap_settings() {

  $form['ocha_snap_tokens'] = array(
    '#type'   => 'item',
    '#title'  => t('Tokens'),
    '#markup' => t('You can use the token <em>[pagination]</em> in both the header and footer. It will be replaced with a translated version of the text <em>Page current of total</em> with the appropriate numbers inserted.'),
  );

  $form['ocha_snap_header'] = array(
    '#type'          => 'textarea',
    '#title'         => t('PDF Header'),
    '#description'   => t('HTML content to use as the generated PDF header. You can <em>not</em> use remote references for images or stylesheets. Any javascript is ignored.'),
    '#default_value' => variable_get('ocha_snap_header', ''),
  );

  $form['ocha_snap_footer'] = array(
    '#type'          => 'textarea',
    '#title'         => t('PDF Footer'),
    '#description'   => t('HTML content to use as the generated PDF footer. You can <em>not</em> use remote references for images or stylesheets. Any javascript is ignored.'),
    '#default_value' => variable_get('ocha_snap_footer', ''),
  );

  $form['ocha_snap_css'] = array(
    '#type'          => 'textarea',
    '#title'         => t('PDF CSS'),
    '#description'   => t('Any custom CSS rules you need injected into the page before the PDF is generated.'),
    '#default_value' => variable_get('ocha_snap_css', ''),
  );

  $form['ocha_snap_debug'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Debug'),
    '#description'   => t('Collect and log debug information in the Snap Service backend.'),
    '#default_value' => variable_get('ocha_snap_debug', 0),
  );

  return system_settings_form($form);
}
