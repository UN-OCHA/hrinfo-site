<?php
/**
 * @file
 * JavaScript callback handler module.
 */

/**
 * Form callback for the js configuration form.
 */
function js_configure_form($form, &$form_state) {
  $htaccess = '# Rewrite JavaScript callback URLs of the form js.php?q=x.' . PHP_EOL;
  $htaccess .= 'RewriteCond %{REQUEST_URI} ^' . str_replace("/", "\/", base_path()) . '([a-z]{2}\/)?js\/.*' . PHP_EOL;
  $htaccess .= 'RewriteRule ^(.*)$ js.php?q=$1 [L,QSA]' . PHP_EOL;
  $htaccess .= 'RewriteCond %{QUERY_STRING} (^|&)q=((\/)?[a-z]{2})?(\/)?js\/.*' . PHP_EOL;
  $htaccess .= 'RewriteRule .* js.php [L]';

  $form['js_server_software'] = array(
    '#type'          => 'select',
    '#options'       => array('apache' => 'Apache', 'other' => t('Other')),
    '#title'         => t('Server software'),
    '#description'   => t('The server software for the http server, used to detect if the requirements for the module are met. Set this to other if running on anything other than Apache.'),
    '#default_value' => variable_get('js_server_software', 'apache'),
  );

  $form['htaccess'] = array(
    '#type'        => 'textarea',
    '#title'       => t('Add the following lines in front of the existing RewriteRules in your .htaccess.'),
    '#value'       => $htaccess,
  );

  return system_settings_form($form);
}
