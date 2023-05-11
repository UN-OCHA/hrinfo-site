<?php

/**
 * Defines the module settings entity.
 */
class GTMSettings {

  /**
   * Singleton instance of this class.
   *
   * @var GTMSettings
   */
  private static $instance;

  /**
   * Constructs a module settings object.
   */
  public function __construct() {
    // On load the values include ctools items: table, type, export_type.
    // $values = (array) ctools_export_crud_load('gtag_config', 'google_tag.settings');
    $values = (array) gtag_export_crud_load('gtag_config', 'google_tag.settings');
    foreach ($values as $key => $value) {
      $this->$key = $value;
    }
  }

  /**
   * Returns singleton instance of this class.
   *
   * @return GTMSettings
   *   The instance.
   */
  public static function getInstance() {
    if (!self::$instance) {
      self::$instance = new GTMSettings();
    }
    return self::$instance;
  }

  /**
   * Returns a property.
   *
   * @param string $property
   *   The property name.
   *
   * @return string
   *   The property.
   */
  public function get($property) {
    return isset($this->$property) ? $this->$property : NULL;
  }

  /**
   * Saves settings to database.
   *
   * @return bool
   *   Whether the save was successful.
   */
  public function save() {
    // On load the properties include ctools items: table, type, export_type.
    $export_type = isset($this->export_type) ? $this->export_type : NULL;
    $data = (array) $this;
    unset($data['table'], $data['type'], $data['export_type']);

    $settings['name'] = 'google_tag.settings';
    $settings['data'] = $data;
    $settings['type'] = 'Normal';
    $settings['export_type'] = $export_type;
    $settings = (object) $settings;
    $result = ctools_export_crud_save('gtag_config', $settings);
    return $result;
  }

}
