<?php
/**
 * @file
 * HybridAuth Pinterest specific settings.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'configuration_form_callback' => 'hybridauth_provider_pinterest_configuration_form_callback',
  'configuration_callback' => 'hybridauth_provider_pinterest_configuration_callback',
);

/**
 * Callback for provider's configuration form.
 *
 * @param  array $form
 *   Form data.
 * @param  string $provider_id
 *   Provider name.
 */
function hybridauth_provider_pinterest_configuration_form_callback(&$form, $provider_id) {
  $apps_uri = 'https://developers.pinterest.com/apps/';
  $scope_uri = 'https://developers.pinterest.com/docs/api/overview/';

  $form['vtabs']['application']['#description'] = t('Enter the application ID and secret key as required. You can get these by creating a new application at !apps_uri',
    array(
      '!apps_uri' => l($apps_uri, $apps_uri, array(
        'attributes' => array(
          'target' => '_blank',
        )
      ))
    )
  );
  $form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_id']['#title'] = t('App ID');
  $form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_secret']['#title'] = t('App secret');
  $form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_secret']['#description'] = t('Application secret key');
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_key']);

  $form['vtabs']['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
  );
  $form['vtabs']['advanced']['#description'] = t('Use these scopes to authenticate your users. Most endpoints need authentication from both you and your user, while others only need your authentication.  These endpoints let you look up any public item that you know the identifier for.');
  $form['vtabs']['advanced']['hybridauth_provider_' . $provider_id . '_scope'] = array(
    '#type' => 'checkboxes',
    '#title' => l('Permission scopes', $scope_uri, array(
      'attributes' => array(
        'target' => '_blank',
      )
    )),
    '#default_value' => variable_get('hybridauth_provider_' . $provider_id . '_scope', hybridauth_provider_pinterest_scope_default()),
    '#options' => array(
      'read_public' => '<strong>read_public</strong> -- ' . t('Use GET method on a user’s Pins, boards and likes.'),
      'write_public' => '<strong>write_public</strong> -- ' . t('Use PATCH, POST and DELETE methods on a user’s Pins and boards.'),
      'read_relationships' => '<strong>read_relationships</strong> -- ' . t('Use GET method on a user’s follows and followers (on boards, users and interests).'),
      'write_relationships' => '<strong>write_relationships</strong> -- ' . t('Use PATCH, POST and DELETE methods on a user’s follows and followers (on boards, users and interests).'),
    ),
  );
}

/**
 * Set default permission scopes.
 *
 * @param  array $config
 *   Configuration data.
 * @param  string $provider_id
 *   Provider name.
 */
function hybridauth_provider_pinterest_configuration_callback(&$config, $provider_id) {
  if (empty($config['scope'])) {
    $config['scope'] = hybridauth_provider_pinterest_scope_default();
  }
}

/**
 * Return default permission scopes.
 *
 * @return array
 *   Permission scopes.
 */
function hybridauth_provider_pinterest_scope_default() {
  return array(
    'read_public',
    'write_public',
    'read_relationships',
    'write_relationships',
  );
}
