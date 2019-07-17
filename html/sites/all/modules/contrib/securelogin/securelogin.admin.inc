<?php

/**
 * @file
 * Admin page callbacks for Secure Login module.
 */

/**
 * Admin settings form.
 */
function securelogin_admin() {
  global $base_secure_url;
  if (variable_get('https', FALSE)) {
    drupal_set_message(t("Secure Login module expects the Drupal <code>\$conf['https']</code> setting to be at its default value: <code>FALSE</code>. Because it is currently enabled, secure logins cannot be fully implemented because Drupal sets insecure session cookies during login to the secure site."), 'warning');
  }
  $form['securelogin_base_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Secure base URL'),
    '#default_value' => variable_get('securelogin_base_url', NULL),
    '#description'   => t('The base URL for secure pages. Leave blank to allow Drupal to determine it automatically. It is not allowed to have a trailing slash; Drupal will add it for you. For example: %base_secure_url%. Note that in order for cookies to work, the hostnames in the secure base URL and the insecure base URL must be in the same domain as per the appropriate setting in <code>settings.php</code>, which you may need to modify.', array('%base_secure_url%' => $base_secure_url)),
  );
  $form['securelogin_secure_forms'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Redirect form pages to secure URL'),
    '#default_value' => variable_get('securelogin_secure_forms', TRUE),
    '#description'   => t('If enabled, any pages containing the forms enabled below will be redirected to the secure URL. Users can be assured that they are entering their private data on a secure URL, the contents of which have not been tampered with.'),
  );
  $form['securelogin_all_forms'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Submit all forms to secure URL'),
    '#default_value' => variable_get('securelogin_all_forms', FALSE),
    '#description'   => t('If enabled, all forms will be submitted to the secure URL.'),
  );
  $form['required'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Required forms'),
    '#description'   => t('If enabled, the following forms will be submitted to the secure URL. These forms must be secured in order to implement basic secure login functionality.'),
  );
  $form['optional'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Optional forms'),
    '#description'   => t('Other forms accessible to anonymous users may optionally be secured. If enabled, the following forms will be submitted to the secure URL.'),
  );
  $forms['user_login'] = array('group' => 'required', 'title' => t('User login form'));
  $forms['user_login_block'] = array('group' => 'required', 'title' => t('User login block form'));
  $forms['user_pass_reset'] = array('group' => 'required', 'title' => t('User password reset form'));
  $forms['user_profile_form'] = array('group' => 'required', 'title' => t('User edit form'));
  // Registration form is also a login form if e-mail verification is disabled.
  $register = variable_get('user_email_verification', TRUE) ? 'optional' : 'required';
  $forms['user_register_form'] = array('group' => $register, 'title' => t('User registration form'));
  $forms['user_pass'] = array('group' => 'optional', 'title' => t('User password request form'));
  $forms['node_form'] = array('group' => 'optional', 'title' => t('Node form'));
  drupal_alter('securelogin', $forms);
  foreach ($forms as $id => $item) {
    $form[$item['group']]['securelogin_form_' . $id] = array(
      '#type'          => 'checkbox',
      '#title'         => $item['title'],
      '#default_value' => variable_get('securelogin_form_' . $id, TRUE),
    );
  }
  $form['securelogin_other_forms'] = array(
    '#type' => 'textfield',
    '#title' => t('Other forms to secure'),
    '#default_value' => variable_get('securelogin_other_forms', ''),
    '#description' => t('List the form IDs of any other forms that you want secured, separated by a space. If the form has a base form ID, you must list the base form ID rather than the form ID.'),
  );
  $form['#submit'][] = 'securelogin_admin_submit';
  return system_settings_form($form);
}

/**
 * Admin settings form submit handler.
 */
function securelogin_admin_submit($form, &$form_state) {
  // Any cached pages containing forms should be regenerated.
  drupal_register_shutdown_function('cache_clear_all');
}

/**
 * Admin settings form validation handler.
 */
function securelogin_admin_validate($form, &$form_state) {
  if (empty($form_state['values']['securelogin_base_url'])) {
    $form_state['values']['securelogin_base_url'] = NULL;
  }
  elseif (!valid_url($form_state['values']['securelogin_base_url'], TRUE)) {
    form_set_error('securelogin_base_url', t('The secure base URL must be a valid URL.'));
  }
  elseif (strtolower(parse_url($form_state['values']['securelogin_base_url'], PHP_URL_SCHEME)) !== 'https') {
    form_set_error('securelogin_base_url', t('The secure base URL must start with <em>https://</em>.'));
  }
}

/**
 * Implements hook_securelogin_alter() for comment module.
 */
function comment_securelogin_alter(&$forms) {
  $forms['comment_form'] = array('group' => 'optional', 'title' => t('Comment form'));
}

/**
 * Implements hook_securelogin_alter() for contact module.
 */
function contact_securelogin_alter(&$forms) {
  $forms['contact_personal_form'] = array('group' => 'optional', 'title' => t('Personal contact form'));
  $forms['contact_site_form'] = array('group' => 'optional', 'title' => t('Site contact form'));
}

/**
 * Implements hook_securelogin_alter() for webform module.
 */
function webform_securelogin_alter(&$forms) {
  $forms['webform_client_form'] = array('group' => 'optional', 'title' => t('Webform'));
}
