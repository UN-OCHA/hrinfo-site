<?php

/**
 * @file
 * File Chooser Field page callbacks.
 */

/**
 * Redirect URL callback.
 */
function file_chooser_field_redirect_callback($phpClassName) {
  module_load_include('inc', 'file_chooser_field');

  if (!empty($phpClassName)) {
    $redirectCallback = file_chooser_field_plugin_method($phpClassName, 'redirectCallback');
    if ($redirectCallback) {
      return $redirectCallback;
    }
  }

  return ' ';

}

/**
 * File Chooser Field settings form.
 */
function file_chooser_field_admin_settings($form, &$form_state) {
  module_load_include('inc', 'file_chooser_field');

  $enabled_plugins = array();

  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'file_chooser_field') . '/js/file_chooser_field.form.js'
      ),
    ),
  );

  $plugins = file_chooser_field_load_plugins();
  foreach ($plugins as $name => $plugin) {

    // List of enabled plugins. This goes to Drupal.settings.
    $enabled_plugins[] = $name;

    $form['settings'][$name] = array(
      '#type' => 'fieldset',
      '#title' => $plugin['name'],
    );

    $status = file_chooser_field_plugin_method($plugin['phpClassName'], 'getStatus');
    $form['settings'][$name][$name . '_status'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable plugin'),
      '#default_value' => $status,
      '#description' => t("Disabled plugins are not visible in <em>File</em> and <em>Image</em> fields."),
    );

    $configForm = file_chooser_field_plugin_method($plugin['phpClassName'], 'configForm', array(&$form_state));
    if (is_array($configForm)) {
      $form['settings'][$name] += $configForm;
    }

    $redirectCallback = file_chooser_field_plugin_method($plugin['phpClassName'], 'redirectCallback');
    if ($redirectCallback) {
      $form['settings'][$name][$name . '_redirect_url'] = array(
        '#markup' => '<em>' . url('redirectCallback/' . $plugin['phpClassName'], array('absolute' => TRUE)) . '</em>',
        '#prefix' => '<div><strong>' . t('Redirect URL') . '</strong></div>',
        '#suffix' => '<div class="description">' . t('This is the URL you will need for the redirect URL/OAuth authentication') . '</div>',
      );
    }

  }

  if (!empty($enabled_plugins)) {
    drupal_add_js(
      array(
        'file_chooser_field' => array(
          'enabled_plugins' => $enabled_plugins,
        )
      ),
      'setting'
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;

}

/**
 * Form validate handler.
 */
function file_chooser_field_admin_settings_validate($form, &$form_state) {
  module_load_include('inc', 'file_chooser_field');
  $plugins = file_chooser_field_load_plugins();
  foreach ($plugins as $name => $plugin) {
    // Validate form submit.
    file_chooser_field_plugin_method($plugin['phpClassName'], 'validateForm', array($form, &$form_state));
  }
}

/**
 * Form submit handler.
 */
function file_chooser_field_admin_settings_submit($form, &$form_state) {
  module_load_include('inc', 'file_chooser_field');
  $plugins = file_chooser_field_load_plugins();
  foreach ($plugins as $name => $plugin) {
    // Save plugin settings.
    file_chooser_field_plugin_method($plugin['phpClassName'], 'setStatus', array($form_state['values'][$name . '_status']));
    file_chooser_field_plugin_method($plugin['phpClassName'], 'submitForm', array($form, &$form_state));
  }
  drupal_set_message(t('The configuration options have been saved.'));
}
