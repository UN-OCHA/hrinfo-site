<?php

/**
 * @file
 * Administrative callbacks for the JS module.
 */

/**
 * Form callback for the JS configuration form.
 */
function js_configure_form($form, &$form_state) {
  $default_value = '';

  $form['rewrite'] = array(
    '#type' => 'fieldset',
    '#title' => t('Server rewrite rules'),
    '#description' => t('Provides a template for common HTTP server rewrite rules. If the type of server this site is using is not listed here, you will need to ensure that any request starting with <code>/@endpoint</code> is forwarded to <code>js.php</code>', array(
      '@endpoint' => variable_get('js_endpoint', 'js'),
    )),
  );

  $options = array();
  $servers = js_server_info();
  foreach ($servers as $name => $info) {
    $options[$name] = $info['label'];

    // Detect the default value from the server.
    if (!$default_value && preg_match($info['regexp'], $_SERVER['SERVER_SOFTWARE'])) {
      $default_value = $name;
    }

    $form['rewrite'][$name] = array(
      '#type' => 'textarea',
      '#title' => $info['label'],
      '#description' => $info['description'],
      '#value' => $info['rewrite'],
      '#rows' => count(explode(PHP_EOL, $info['rewrite'])),
      '#resizable' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name=server]' => array('value' => $name),
        ),
      ),
    );
  }

  $form['rewrite']['server'] = array(
    '#type' => 'select',
    '#title' => t('Choose server:'),
    '#empty_option' => t('Unknown'),
    '#options' => $options,
    '#default_value' => $default_value,
    '#weight' => -1,
  );

  return $form;
}
