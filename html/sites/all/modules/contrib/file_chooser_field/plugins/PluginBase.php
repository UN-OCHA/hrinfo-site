<?php

/**
 * @file
 * File Chooser Field Plugins class
 */

/**
 * File Chooser Field plugin abstract class.
 * Extend this class to integrate a new file upload plugin.
 */
abstract class FileChooserFieldPlugin {

  /**
   * Button label.
   *
   * @return string
   */
  abstract public function label();

  /**
   * Button CSS class name.
   *
   * @return string.
   */
  abstract public function cssClass();

  /**
   * Set button attributes such as data-[array-key]="[array-value]".
   *
   * @return array
   */
  abstract public function attributes($info);

  /**
   * Load all required assets, such as Javascript or CSS.
   * Use drupal_add_js() or drupal_add_css().
   */
  abstract public function assets();

  /**
   * Configuration form.
   * Drupal form API elements.
   *
   * @return array.
   */
  abstract public function configForm(&$form_state);

  /**
   * Form validation handler.
   */
  public function validateForm($form, &$form_state) {
    // Drupal Form API validation.
  }

  /**
   * Form submit handler.
   */
  abstract public function submitForm($form, &$form_state);

  /**
   * Download remote file to Drupal.
   *
   * @return public://[remote-file-name]
   * @see file_chooser_field_save_upload().
   */
  abstract public function download($destination, $url);

  /**
   * Redirect callback.
   * Some APIs require redirect URLs. This method handles that.
   * See Plugin configuration page for the URL.
   *
   * @return string. Contents of the callback page.
   */
  public function redirectCallback() {
    // This is where you would put all required code for the response.
  }

  /**
   * Set plugin status.
   */
  public function setStatus($value) {
    $this->setSetting('status', $value);
  }

  /**
   * Get plugin status.
   */
  public function getStatus() {
    return $this->getSetting('status');
  }

  /**
   * Save settings.
   */
  protected function setSetting($key, $value) {
    $settings = (object) variable_get('file_chooser_field_plugin_settings', array());
    $className = get_class($this);
    $settings->{$className}->$key = $value;
    variable_set('file_chooser_field_plugin_settings', $settings);
    return $this;
  }

  /**
   * Save settings.
   */
  protected function getSetting($key, $default = '') {
    $settings = (object) variable_get('file_chooser_field_plugin_settings', array());
    $className = get_class($this);
    if (!empty($settings->{$className}->$key)) {
      return $settings->{$className}->$key;
    }
    else {
      return $default;
    }
  }

}
