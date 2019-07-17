<?php

/**
 * @file
 * Contains the entity class for stored "Saved searches" settings of search
 * indexes.
 */

/**
 * Class representing "Saved searches" settings.
 */
class SearchApiSavedSearchesSettings extends Entity {

  /**
   * The search index these settings are for.
   *
   * @var SearchApiIndex
   */
  protected $index;

  // Database values that will be set when object is loaded

  /**
   * @var integer
   */
  public $id;

  /**
   * @var string
   */
  public $delta;

  /**
   * @var string
   */
  public $index_id;

  /**
   * @var boolean
   */
  public $enabled;

  /**
   * @var array
   */
  public $options;

  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'search_api_saved_searches_settings');
  }

  /**
   * @return SearchApiIndex
   *   The index these saved search settings are for.
   *
   * @throws SearchApiException
   *   If the index doesn't exist.
   */
  public function index() {
    if (!isset($this->index)) {
      $this->index = search_api_index_load($this->index_id);
    }
    if (!$this->index) {
      throw new SearchApiException(t("The index with the ID %id doesn't exist, but has saved search settings attached.", array('%id' => $this->index_id)));
    }
    return $this->index;
  }

  /**
   * Gets the translated value of an option via i18n string translations.
   *
   * @param $property
   *   The name of the property stored in the options, as declared for i18n;
   *   e.g. "mail.notify.title".
   * @param $langcode
   *   (optional) The language code of the language to which the value should
   *   be translated. If set to NULL, the default display language is being
   *   used.
   *
   * @return
   *   The raw, translated property value; or the raw, un-translated value if no
   *   translation is available.
   *
   * @see SearchApiSavedSearchesSettingsI18nController
   */
  public function getTranslatedOption($property, $langcode = NULL) {
    $value = drupal_array_get_nested_value($this->options, explode('.', $property));
    if (isset($value) && module_exists('search_api_saved_searches_i18n') && function_exists('i18n_string')) {
      $name = 'search_api_saved_searches:search_api_saved_searches_settings:' . $this->identifier() . ':' . $property;
      if (is_array($value)) {
        // Handle arrays of values, i.e. interval_options.
        foreach ($value as $key => $data) {
          $value[$key] = i18n_string($name . ".$key", $data, array('langcode' => $langcode, 'sanitize' => FALSE));
        }
        return $value;
      }
      else {
        return i18n_string($name, $value, array('langcode' => $langcode, 'sanitize' => FALSE));
      }
    }
    return $value;
  }
}
