<?php

/**
 * @file
 * Contains the SearchApiSavedSearchesViewsHandlerFieldInterval class.
 */

/**
 * Views field handler for displaying a saved search's notification interval.
 */
class SearchApiSavedSearchesViewsHandlerFieldInterval extends views_handler_field_time_interval {

  /**
   * Overrides views_handler_field_time_interval::option_definition().
   *
   * Adds the custom_labels option.
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['custom_labels'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Overrides views_handler_field_time_interval::options_form().
   *
   * Adds the custom_labels option.
   */
  public function options_form(&$form, &$form_state) {
    $form['custom_labels'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use custom labels defined in the saved search settings'),
      '#default_value' => $this->options['custom_labels'],
    );
    parent::options_form($form, $form_state);
    $form['granularity']['#dependency'] = array(
      'edit-options-custom-labels' => array(0),
    );
  }

  /**
   * Overrides views_handler_field::query().
   *
   * Adds the settings_id field if custom labels should be used.
   */
  public function query() {
    parent::query();

    if ($this->options['custom_labels']) {
      $this->add_additional_fields(array('settings_id'));
    }
  }

  /**
   * Overrides views_handler_field_time_interval::render().
   *
   * Takes custom labels from the associated settings, if the corresponding
   * handler option is enabled.
   */
  public function render($values) {
    if ($this->options['custom_labels']) {
      $field = $this->aliases['settings_id'];
      if ($values->$field && ($settings = search_api_saved_searches_settings_load($values->$field))) {
        $intervals = $settings->getTranslatedOption('interval_options');
        if (isset($intervals[$values->{$this->field_alias}])) {
          return $intervals[$values->{$this->field_alias}];
        }
      }
    }
    if ($values->{$this->field_alias} < 0) {
      return t('Never');
    }
    return parent::render($values);
  }

}
