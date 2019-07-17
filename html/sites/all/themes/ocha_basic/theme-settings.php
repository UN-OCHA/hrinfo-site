<?php
/**
 * @file
 * Theme setting callbacks for the ocha_basic theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function ocha_basic_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['ocha_basic_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable theme debugging'),
    '#default_value' => theme_get_setting('ocha_basic_debug'),
    '#description' => t('To help with theme development, you can enable or disable theme debugging.'),
    '#weight' => -2,
  );
}
