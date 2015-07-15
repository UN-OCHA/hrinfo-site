<?php

/**
 * @file
 * Admin page callbacks for the XHProf module.
 */

/**
 * Administrative settings form for XHProf module.
 */
function xhprof_admin_settings() {
  $description = extension_loaded('xhprof') ? t('Profile requests with the xhprof php extension.') : '<span class="warning">' . t('You must enable the <a href="!url">xhprof php extension</a> to use this feature.', array('!url' => url('http://techportal.ibuildings.com/2009/12/01/profiling-with-xhprof/'))) . '</span>';
  $form['xhprof_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable profiling of page views and <a href="!drush">drush</a> requests.', array('!drush' => url('http://drush.ws'))),
    '#default_value' => variable_get('xhprof_enabled', FALSE),
    '#description' => $description,
    '#disabled' => !extension_loaded('xhprof'),
  );
  $form['settings'] = array(
    '#title' => t('Profiling settings'),
    '#type' => 'fieldset',
    '#states' => array(
      'invisible' => array(
        'input[name="xhprof_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['settings']['xhprof_flags_cpu'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include CPU time in profiling output.'),
    '#description' => t('Tracking CPU time adds some overhead. You may consider disabling this when debugging an issue that is not I/O related.'),
    '#default_value' => variable_get('xhprof_flags_cpu', TRUE),
  );
  $form['settings']['xhprof_flags_memory'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include memory usage in profiling output.'),
    '#description' => t('Tracking memory adds some overhead, but not as much as CPU.'),
    '#default_value' => variable_get('xhprof_flags_memory', TRUE),
  );
  $form['settings']['xhprof_disable_admin_paths'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable profiling of admin pages'),
    '#default_value' => variable_get('xhprof_disable_admin_paths', TRUE),
  );

  $form['settings']['xhprof_interval'] = array(
    '#type' => 'textfield',
    '#title' => 'Profiling interval',
    '#default_value' => variable_get('xhprof_interval', ''),
    '#description' => t('The approximate number of requests between XHProf samples. Leave empty to profile all requests'),
  );

  $options = drupal_map_assoc(xhprof_get_classes());
  $form['settings']['xhprof_default_class'] = array(
    '#type' => 'radios',
    '#title' => t('XHProf storage'),
    '#default_value' => variable_get('xhprof_default_class', 'XHProfRunsFile'),
    '#options' => $options,
    '#description' => t('Choose an XHProf runs class.'),
  );

  return system_settings_form($form);
}

function xhprof_admin_settings_validate($form, &$form_state) {
  // TODO: Simplify this.
  if (isset($form_state['values']['xhprof_interval']) && $form_state['values']['xhprof_interval'] != '' && (!is_numeric($form_state['values']['xhprof_interval']) || $form_state['values']['xhprof_interval'] <= 0 || $form_state['values']['xhprof_interval'] > mt_getrandmax())) {
    form_set_error('xhprof_interval', 'The profiling interval must be set to a positive integer.');
  }
}
