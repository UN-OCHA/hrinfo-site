<?php

/**
 * @file
 * Contains the SearchApiSavedSearchesSettingsI18nStringObjectWrapper class.
 */

/**
 * Custom i18n object wrapper.
 */
class SearchApiSavedSearchesSettingsI18nStringObjectWrapper extends i18n_string_object_wrapper {

  /**
   * Overrides i18n_string_object_wrapper::get_field() to read properties from the options array.
   */
  public function get_field($field, $default = NULL) {
    if (strpos($field, '.') !== FALSE) {
      $value = drupal_array_get_nested_value($this->object->options, explode('.', $field));
      if (isset($value)) {
        return $value;
      }
    }

    if (isset($this->object->options[$field])) {
      return $this->object->options[$field];
    }

    // Fallback to the usual behaviour.
    return parent::get_field($field, $default);
  }

  /**
   * Get translatable properties
   */
  protected function build_properties() {
    $strings = parent::build_properties();
    $properties = array();

    // Dynamically add interval options.
    foreach ($this->object->options['interval_options'] as $key => $value) {
      $properties['interval_options.' . $key] = array(
          'title' => t('Interval option, @key', array('@key' => $key)),
          'string' => $value,
      );
    }
    $strings[$this->get_textgroup()]['search_api_saved_searches_settings'][$this->object->delta] += $properties;
    return $strings;
  }

}