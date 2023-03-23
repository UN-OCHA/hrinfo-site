<?php

/**
 * @file
 * Contains the container form callbacks.
 *
 * @author Jim Berry ("solotandem", http://drupal.org/user/240748)
 */

/**
 * Form constructor for the container form.
 *
 * @see google_tag_container_form_validate()
 * @see google_tag_container_form_submit()
 *
 * @ingroup forms
 */
function google_tag_container_form(&$form, &$form_state) {
  module_load_include('inc', 'google_tag', 'includes/variable');

  // Gather data.
  // @todo Set this on validation errors.
  $default_tab = !empty($form_state['default_tab']) ? $form_state['default_tab'] : '';

  // Build form elements.
  $description = t('On this and the following tabs, specify the conditions on which the GTM JavaScript snippet will either be inserted on or omitted from the page response, thereby enabling or disabling tracking and other analytics. All conditions must be satisfied for the snippet to be inserted. The snippet will be omitted if any condition is not met.');
  $text = t('The settings affecting the snippet contents for this container.');
  $suffix = '<div id="edit-default--description" class="description">' . $text . '</div>';

  $groups = array(
    'general' => array('title' => t('General'), 'collapse' => FALSE),
    'advanced' => array('title' => t('Advanced')),
  );

  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => $default_tab ? $default_tab : 'edit-general',
    '#attributes' => array('class' => array('google-tag')),
    '#prefix' => '<strong>' . t('Container settings') . '</strong>',
    '#suffix' => $suffix,
  );
  foreach ($groups as $group => $items) {
    $form['settings'][$group] = google_tag_fieldset($group, $items, $form_state['item']);
  }

  $groups = google_tag_condition_filter();

  $text = t('The snippet insertion conditions for this container.');
  $suffix = '<div id="edit-default--description" class="description">' . $text . '</div>';

  $form['conditions'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => $default_tab ? $default_tab : 'edit-path',
    '#attributes' => array('class' => array('google-tag')),
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'google_tag') . '/css/google_tag.admin.css'),
      'js' => array(drupal_get_path('module', 'google_tag') . '/js/google_tag.admin.js'),
    ),
    '#prefix' => '<strong>' . t('Insertion conditions') . '</strong>',
    '#suffix' => $suffix,
  );
  foreach ($groups as $group => $items) {
    $form['conditions'][$group] = google_tag_fieldset($group, $items, $form_state['item']);
  }
  $form['#after_build'] = array('google_tag_container_form_after_build');
}

/**
 * Fieldset builder for the module settings form.
 */
function google_tag_fieldset($group, array $items, $container) {
  // Gather data.
  $function = "_google_tag_variable_info_$group";
  $variables = $function(array());
  $items += array('description' => '', 'collapse' => TRUE);
  // @todo Does google_tag_condition_filter() obviate this gate check?
  if (empty($variables)) {
    // This handles optional conditions like domain, language, and realm.
    return array();
  }

  // Build form elements.
  $fieldset = array(
    '#type' => 'fieldset',
    '#title' => $items['title'],
    '#description' => $items['description'],
    '#collapsible' => $items['collapse'],
    '#collapsed' => $items['collapse'],
    '#tree' => FALSE,
  );
  $fieldset += google_tag_form_elements($variables, $container);

  return $fieldset;
}

/**
 * Returns form elements from variable definitions.
 *
 * @param array $variables
 *   Associative array of variable definitions.
 * @param object $container
 *   The container configuration object.
 *
 * @return array
 *   Associative array of form elements.
 */
function google_tag_form_elements(array $variables, $container) {
  static $keys = array(
    'type' => '#type',
    'title' => '#title',
    'description' => '#description',
    'options' => '#options',
    'default' => '#default_value',
  );
  $elements = array();
  foreach ($variables as $name => $variable) {
    $element = array();
    foreach ($keys as $key => $property) {
      if (isset($variable[$key])) {
        $element[$property] = $variable[$key];
      }
    }
    $element['#type'] = google_tag_form_element_type($element['#type']);
    $element['#default_value'] = isset($container->$name) ? $container->$name : $element['#default_value'];
    $element += isset($variable['element']) ? $variable['element'] : array();
    $elements[$name] = $element;
  }

  return $elements;
}

/**
 * Converts variable type to form element type.
 *
 * @param string $type
 *   Variable type.
 *
 * @return string
 *   Form element type.
 */
function google_tag_form_element_type($type) {
  static $keys = array(
    'string' => 'textfield',
    'select' => 'radios',
    'text' => 'textarea',
    'options' => 'checkboxes',
    'boolean' => 'checkbox',
    'weight' => 'weight',
  );
  return isset($keys[$type]) ? $keys[$type] : 'textfield';
}

/**
 * Element after build callback for google_tag_container_form().
 */
function google_tag_container_form_after_build($element, &$form_state) {
  $element['#submit'][] = 'google_tag_container_form_submit';
  $element['#validate'][] = 'google_tag_container_form_validate';
  return $element;
}

/**
 * Form validation handler for google_tag_container_form().
 */
function google_tag_container_form_validate($form, &$form_state) {
  $values = &$form_state['values'];

  // Trim the text values.
  $values['container_id'] = trim($values['container_id']);
  $values['environment_id'] = trim($values['environment_id']);
  $values['data_layer'] = trim($values['data_layer']);
  google_tag_text_clean($values['path_list']);
  google_tag_text_clean($values['status_list']);
  google_tag_text_clean($values['whitelist_classes']);
  google_tag_text_clean($values['blacklist_classes']);

  // Replace all types of dashes (n-dash, m-dash, minus) with a normal dash.
  $values['container_id'] = str_replace(array('–', '—', '−'), '-', $values['container_id']);
  $values['environment_id'] = str_replace(array('–', '—', '−'), '-', $values['environment_id']);

  foreach (array('role', 'domain', 'language', 'realm') as $type) {
    $key = "{$type}_list";
    if (isset($values[$key])) {
      $values[$key] = array_filter($values[$key]);
    }
  }

  if (!preg_match('/^GTM-\w{4,}$/', $values['container_id'])) {
    // @todo Is there a more specific regular expression that applies?
    // @todo Is there a way to "test the connection" to determine a valid ID for
    // a container? It may be valid but not the correct one for the website.
    form_set_error('container_id', t('A valid container ID is case sensitive and formatted like GTM-xxxxxx.'));
  }
  if ($values['include_environment'] && !preg_match('/^env-\d{1,}$/', $values['environment_id'])) {
    form_set_error('environment_id', t('A valid environment ID is case sensitive and formatted like env-x.'));
  }
  if ($message = _google_tag_data_layer_verify($values['data_layer'])) {
    form_set_error('data_layer', $message);
  }
  if ($values['include_classes']) {
    if (empty($values['whitelist_classes']) && empty($values['blacklist_classes'])) {
      form_set_error('include_classes', t('Enter listed classes in at least one field, or uncheck the box.'));
      form_set_error('whitelist_classes', '');
      form_set_error('blacklist_classes', '');
    }
  }
}

/**
 * Form submission handler for google_tag_container_form().
 *
 * @todo This handler is called from ctools_export_ui::edit_form_submit() which
 * precedes ::edit_save_form() where the config table is written to. Change this
 * to call the code in here from the latter?
 */
function google_tag_container_form_submit($form, &$form_state) {
  // @todo Filter values to those representing the configuration entity.
  $values = &$form_state['values'];
  $values['name'] = $values['data']['name'];
  $container = new GTMContainer($values);

  // Set global to avoid message display to non-admin users on cache flush.
  global $_google_tag_display_message;
  $_google_tag_display_message = TRUE;
  $manager = \GTMContainerManager::getInstance();
  $manager->createAssets($container);
}

/**
 * Cleans a string representing a list of items.
 *
 * @param string $text
 *   The string to clean.
 * @param string $format
 *   The final format of $text, either 'string' or 'array'.
 */
function google_tag_text_clean(&$text, $format = 'string') {
  $text = explode("\n", $text);
  $text = array_map('trim', $text);
  $text = array_filter($text, 'trim');
  if ($format == 'string') {
    $text = implode("\n", $text);
  }
}

/**
 * Verifies presence of dataLayer module and compares name of data layer.
 *
 * @return bool|null
 *   Whether data layer name is incompatible with dataLayer module, if present.
 */
function _google_tag_data_layer_verify($value) {
  if (module_exists('datalayer') && $value != 'dataLayer') {
    // @todo Setting form error does not allow user to save a different name,
    // i.e. to do what message text says.
    return t('The 1.1 release of the dataLayer module does not support a data layer name other than "dataLayer." If you need a different layer name, then either disable the dataLayer module or alter the JavaScript added to the page response.');
  }
}
