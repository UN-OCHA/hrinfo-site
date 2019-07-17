<?php

/**
 * @file
 * Variable module integration.
 */

/**
 * Implements hook_variable_info().
 */
function securelogin_variable_info($options) {
  global $base_secure_url;

  $variable['securelogin_all_forms'] = array(
    'title' => t('Submit all forms to secure URL', array(), $options),
    'description' => t('If enabled, all forms will be submitted to the secure URL.', array(), $options),
    'default' => variable_get('securelogin_all_forms', FALSE),
  );

  $variable['securelogin_base_url'] = array(
    'title' => t('Secure base URL', array(), $options),
    'description' => t('The base URL for secure pages. Leave blank to allow Drupal to determine it automatically. It is not allowed to have a trailing slash; Drupal will add it for you. For example: %base_secure_url%. Note that in order for cookies to work, the hostnames in the secure base URL and the insecure base URL must be in the same domain as per the appropriate setting in <code>settings.php</code>, which you may need to modify.', array('%base_secure_url%' => $base_secure_url), $options),
    'default' => variable_get('securelogin_base_url', NULL),
  );

  // Build a list of forms that may be secured.
  $forms['user_login'] = array(
    'group' => 'required',
    'title' => t('User login form', array(), $options),
  );
  $forms['user_login_block'] = array(
    'group' => 'required',
    'title' => t('User login block form', array(), $options),
  );
  $forms['user_pass_reset'] = array(
    'group' => 'required',
    'title' => t('User password reset form', array(), $options),
  );
  $forms['user_profile_form'] = array(
    'group' => 'required',
    'title' => t('User edit form', array(), $options),
  );
  // Registration form is also a login form if e-mail verification is disabled.
  $register = variable_get('user_email_verification', TRUE) ? 'optional' : 'required';
  $forms['user_register_form'] = array(
    'group' => $register,
    'title' => t('User registration form', array(), $options),
  );
  $forms['user_pass'] = array(
    'group' => 'optional',
    'title' => t('User password request form', array(), $options),
  );
  $forms['node_form'] = array(
    'group' => 'optional',
    'title' => t('Node form', array(), $options),
  );
  module_load_include('inc', 'securelogin', 'securelogin.admin');
  drupal_alter('securelogin', $forms);
  foreach ($forms as $id => $item) {
    $variable['securelogin_form_' . $id] = array(
      'type' => 'boolean',
      'title' => $item['title'],
      'default' => variable_get('securelogin_form_' . $id, FALSE),
    );
  }

  $variable['securelogin_other_forms'] = array(
    'title' => t('Other forms to secure', array(), $options),
    'description' => t('List the form IDs of any other forms that you want secured, separated by a space. If the form has a base form ID, you must list the base form ID rather than the form ID.', array(), $options),
    'default' => variable_get('securelogin_other_forms', ''),
  );

  $variable['securelogin_secure_forms'] = array(
    'type' => 'boolean',
    'title' => t('Redirect form pages to secure URL', array(), $options),
    'description' => t('If enabled, any pages containing the forms enabled below will be redirected to the secure URL. Users can be assured that they are entering their private data on a secure URL, the contents of which have not been tampered with.', array(), $options),
    'default' => variable_get('securelogin_secure_forms', TRUE),
  );

  return $variable;
}
