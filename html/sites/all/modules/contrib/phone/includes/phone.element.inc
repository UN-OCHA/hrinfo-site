<?php

/**
 * @file
 * Provides FAPI implementation for a phone element.
 */

/**
 * Implements hook_element_info().
 */
function _phone_element_info() {
  $path = drupal_get_path('module', 'phone');

  $types['phone'] = array(
    '#input' => TRUE,
    '#process' => array('ajax_process_form', 'phone_element_process'),
    '#element_validate' => array('phone_element_validate'),
    '#theme_wrappers' => array('phone'),
    '#attached' => array(
      'css' => array($path . '/theme/phone.css'),
    ),
    '#phone_settings' => array(
      'label_position' => 'none',
      'use_tel_input' => TRUE,
      'number_size' => 30,
      'numbertype_allowed_values' => array(
        'home' => t('Home'),
        'work' => t('Work'),
        'mobile' => t('Mobile'),
        'fax' => t('Fax'),
      ),
      'bubble_errors' => FALSE,
      'enable_numbertype' => TRUE,
      'numbertype_allowed_values_position' => 'before',
      'enable_extension' => FALSE,
      'extension_size' => 7,
      'country_options' => array(
        'enable_default_country' => TRUE,
        'default_country' => NULL,
        'all_country_codes' => TRUE,
        'country_codes' => array(
          'hide_single_cc' => FALSE,
          'country_selection' => array(),
        ),
        'country_code_position' => 'after',
      ),
    ),
  );

  $types['phone_tel'] = array(
    '#input' => TRUE,
    '#size' => 30,
    '#maxlength' => 128,
    '#autocomplete_path' => FALSE,
    '#process' => array('ajax_process_form'),
    '#theme' => 'phone_tel',
    '#theme_wrappers' => array('form_element'),
  );

  return $types;
}

/**
 * Process an individual phone element.
 */
function phone_element_process($element, &$form_state, $form) {
  $item = $element['#value'];

  $settings = $element['#phone_settings'];

  $labels = array(
    'type' => theme('phone_part_label_type', array('element' => $element)),
    'number' => theme('phone_part_label_number', array('element' => $element)),
    'extension' => theme('phone_part_label_extension', array('element' => $element)),
    'country' => theme('phone_part_label_country', array('element' => $element)),
  );

  if ($settings['label_position'] == 'before') {
    if (!isset($element['#attributes']['class'])) {
      $element['#attributes']['class'] = array();
    }
    $element['#attributes']['class'][] = 'phone-label-before';
  }

  if ($settings['enable_numbertype'] && !empty($settings['numbertype_allowed_values'])) {
    $element['numbertype'] = array(
      '#type' => 'select',
      '#title' => $labels['type'],
      '#title_display' => $settings['label_position'] == 'none' ? 'invisible' : 'before',
      '#options' => $settings['numbertype_allowed_values'],
      '#weight' => $settings['numbertype_allowed_values_position'] == 'after' ? 5 : -5,
      '#empty_option' => t('- Select -'),
      '#default_value' => isset($item['numbertype']) ? $item['numbertype'] : NULL,
    );
  }
  else {
    $element['numbertype'] = array(
      '#type' => 'hidden',
      '#value' => isset($item['numbertype']) ? $item['numbertype'] : NULL,
    );
  }

  $element['number'] = array(
    '#type' => !empty($settings['use_tel_input']) ? 'phone_tel' : 'textfield',
    '#title' => $labels['number'],
    '#title_display' => $settings['label_position'] == 'none' ? 'invisible' : 'before',
    '#maxlength' => $settings['number_size'],
    '#size' => $settings['number_size'],
    '#required' => ($element['#delta'] == 0 && $element['#required']) ? $element['#required'] : FALSE,
    '#default_value' => isset($item['number']) ? $item['number'] : NULL,
    '#weight' => 0,
  );

  // If only one country code, make it as a hidden form item.
  $country_options = $settings['country_options'];
  $country_selection = array_filter($country_options['country_codes']['country_selection']);
  if ((!$country_options['all_country_codes'] && count($country_selection) == 1) || empty($country_options['enable_country'])) {
    $countrycode = '';
    if (!empty($country_options['enable_country'])) {
      $countrycode = reset($country_selection);
    }
    elseif (!empty($country_options['enable_default_country'])) {
      $countrycode = $country_options['default_country'];
    }
    $country = phone_countries($countrycode);
    $element['countrycode'] = array(
      '#type' => 'hidden',
      '#value' => $countrycode,
    );
    if (!$country_options['country_codes']['hide_single_cc'] && !empty($country_options['enable_country'])) {
      $element['country_code_markup'] = array(
        '#type' => 'item',
        '#title' => $labels['country'],
        '#title_display' => $settings['label_position'] == 'none' ? 'invisible' : 'before',
        '#markup' => $country,
        '#weight' => ($settings['country_code_position'] == 'after' ? 1 : -1),
      );
    }
  }
  else {
    $element['countrycode'] = array(
      '#type' => 'select',
      '#title' => $labels['country'],
      '#title_display' => $settings['label_position'] == 'none' ? 'invisible' : 'before',
      '#options' => phone_countries($country_options['all_country_codes'] ? NULL : $country_selection),
      '#weight' => ($settings['country_code_position'] == 'after' ? 1 : -1),
      '#empty_option' => t('- Guess from number -'),
    );
    if (isset($item['countrycode'])) {
      $element['countrycode']['#default_value'] = $item['countrycode'];
    }
    elseif ($country_options['enable_default_country']) {
      $element['countrycode']['#default_value'] = $country_options['default_country'];
    }
  }

  if ($settings['enable_extension']) {
    $element['extension'] = array(
      '#type' => 'textfield',
      '#title' => $labels['extension'],
      '#title_display' => $settings['label_position'] == 'none' ? 'invisible' : 'before',
      '#maxlength' => $settings['extension_size'],
      '#size' => $settings['extension_size'],
      '#title' => t('ext'),
      '#required' => FALSE,
      '#default_value' => isset($item['extension']) ? $item['extension'] : NULL,
      '#weight' => 2,
    );
  }
  else {
    $element['extension'] = array(
      '#type' => 'hidden',
      '#value' => isset($item['extension']) ? $item['extension'] : NULL,
    );
  }

  return $element;
}

/**
 * An #element_validate callback for the phone element.
 */
function phone_element_validate(&$element, &$form_state) {
  // Load up libphonenumber.
  phone_libphonenumber();

  $item = $element['#value'];
  if (isset($item['number'])) {
    $phone_input = trim($item['number']);
  }
  if (isset($item['countrycode'])) {
    $countrycode = trim($item['countrycode']);
  }
  $ext_input = '';
  $settings = $element['#phone_settings'];

  if ($settings['enable_extension'] && isset($item['extension'])) {
    $ext_input = trim($item['extension']);
  }

  $error = FALSE;
  if (isset($phone_input) && !empty($phone_input)) {
    $all_countries = $settings['country_options']['all_country_codes'];
    $selection = array_filter($settings['country_options']['country_codes']['country_selection']);
    $valid = phone_libphonenumber_valid($phone_input, $countrycode, $ext_input, $all_countries, $selection);
    if (TRUE !== $valid) {
      $error = $valid;
    }
  }
  elseif ($element['#required']) {
    $error = t('Number is required.');
  }

  // If this is used in a field widget, bubble the errors to be handled
  // by hook_field_validate(). We can set a more useful message there
  // as we'll have full access to the field information, and won't have
  // to write complex code here to handle the case when this is used
  // as it's own FAPI element outside of the field system.
  if (!empty($error)) {
    if (isset($settings['bubble_errors']) && $settings['bubble_errors'] === TRUE) {
      $dummy_element = array(
        '#parents' => array_merge($element['#parents'], array('error')),
      );
      form_set_value($dummy_element, $error, $form_state);
    }
    else {
      form_error($element, t('%name: !error', array('%name' => $element['#title'], '!error' => $error)));
    }
  }
}

/**
 * Returns HTML for a phone element.
 */
function theme_phone($variables) {
  $element = $variables['element'];
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : array('class' => array());
  $wrapper_attributes = array('class' => array('clearfix'));
  // Add an wrapper to mimic the way a single value field works, for ease in
  // using #states.
  if (isset($element['#children'])) {
    $element['#children'] = '<div id="' . $element['#id'] . '" ' . drupal_attributes($wrapper_attributes) . '>' . $element['#children'] . '</div>';
  }
  return '<div ' . drupal_attributes($attributes) . '>' . theme('form_element', $element) . '</div>';
}

/**
 * Returns HTML for a tel form element.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #value, #description, #size, #maxlength,
 *     #placeholder, #required, #attributes, #autocomplete_path.
 *
 * @ingroup themeable
 */
function theme_phone_tel($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'tel';
  element_set_attributes($element, array(
    'id', 'name', 'value', 'size',
    'maxlength', 'placeholder',
  ));
  _form_set_class($element, array('form-phone-tel'));
  _form_set_class($element, array('form-text'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

/**
 * Returns HTML for a phone 'number' label.
 */
function theme_phone_part_label_number($variables) {
  return t('Number', array(), array('context' => 'phone'));
}

/**
 * Returns HTML for a phone 'country' label.
 */
function theme_phone_part_label_country($variables) {
  return t('Country', array(), array('context' => 'phone'));
}

/**
 * Returns HTML for a phone 'extension' label.
 */
function theme_phone_part_label_extension($variables) {
  return t('Extension', array(), array('context' => 'phone'));
}

/**
 * Returns HTML for a phone 'type' label.
 */
function theme_phone_part_label_type($variables) {
  return t('Type', array(), array('context' => 'phone'));
}
