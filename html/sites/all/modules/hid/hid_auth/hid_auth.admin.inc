<?php

function hid_auth_configpage($form, &$form_state) {
  $form['hid_auth_login_enabled'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Enable Drupal login page'),
    '#default_value'  => variable_get('hid_auth_login_enabled', FALSE),
    '#description'    => t('The user login page (/user/login) is disabled automatically by this module. Checking this option will allow users to login to Drupal directly.'),
  );

  return system_settings_form($form);
}