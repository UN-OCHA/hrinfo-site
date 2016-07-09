<?php

/**
 * @file
 * Contains the entity class for saved searches.
 */

/**
 * Class representing "Saved searches" settings.
 */
class SearchApiSavedSearch extends Entity {

  /**
   * The user that owns this saved search.
   *
   * @var stdClass
   */
  protected $user;

  /**
   * The settings this saved search uses.
   *
   * @var SearchApiSavedSearchesSettings
   */
  protected $settings;

  /**
   * The search index this saved search uses.
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
   * @var integer
   */
  public $uid;

  /**
   * @var string
   */
  public $settings_id;

  /**
   * @var boolean
   */
  public $enabled;

  /**
   * @var string
   */
  public $name;

  /**
   * @var string
   */
  public $mail;

  /**
   * @var integer
   */
  public $created;

  /**
   * @var integer
   */
  public $last_queued;

  /**
   * @var integer
   */
  public $last_execute;

  /**
   * @var integer
   */
  public $notify_interval;

  /**
   * Array representing the search query to execute, containing:
   *   keys: The parsed fulltext keys.
   *   fields: The fields that will be fulltext-searched.
   *   filters: An array of filters, as used in SearchApiQueryFilterInterface.
   *   options: The query options.
   *
   * @var array
   */
  public $query;

  /**
   * @var array
   */
  public $options;

  /**
   * @var string
   */
  public $results;

  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'search_api_saved_search');
  }

  /**
   * Permanently saves the entity.
   *
   * @see entity_save()
   */
  public function save() {
    $settings = $this->settings();
    if ((!$this->enabled && empty($this->options['key'])) || !empty($settings->options['registered_user_delete_key'])) {
      $this->options['key'] = drupal_hash_base64(drupal_random_bytes(12));
    }
    $date_field = isset($settings->options['date_field']) ? $settings->options['date_field'] : NULL;
    if ($this->enabled && !isset($this->results) && !$date_field) {
      $results = array();
      $response = $this->query()->execute();
      $this->results = implode(',', array_keys($response['results']));
    }
    $ret = parent::save();
    if ($ret == SAVED_NEW && !$this->enabled) {
      $params = array(
        'user' => user_load($this->uid),
        'search' => $this,
      );
      drupal_mail('search_api_saved_searches', 'activate', $this->mail, user_preferred_language($params['user']), $params);
    }
    return $ret;
  }

  /**
   * @return
   *   The user that owns this saved search.
   */
  public function user() {
    if (!isset($this->user)) {
      $this->user = user_load($this->uid);
    }
    return $this->user;
  }

  /**
   * @return SearchApiSavedSearchesSettings
   *   The settings this saved search uses.
   *
   * @throws SearchApiException
   *   If the settings don't exist.
   */
  public function settings() {
    if (!isset($this->settings)) {
      $this->settings = search_api_saved_searches_settings_load($this->settings_id);
    }
    if (!$this->settings) {
      throw new SearchApiException(t("The saved search settings with the ID %id don't exist, but are used by an existing saved search.", array('%id' => $this->settings_id)));
    }
    return $this->settings;
  }

  /**
   * @return SearchApiIndex
   *   The index this saved search uses.
   *
   * @throws SearchApiException
   *   If the index doesn't exist.
   */
  public function index() {
    if (!isset($this->index)) {
      $this->index = search_api_index_load($this->settings()->index_id);
    }
    if (!$this->index) {
      throw new SearchApiException(t("The index with the ID %id doesn't exist, but has saved search settings attached.", array('%id' => $this->settings()->index_id)));
    }
    return $this->index;
  }

  /**
   * @return SearchApiQueryInterface
   *   A query for getting all new results for this saved search.
   *
   * @throws SearchApiException
   *   If the saved search's index is disabled.
   */
  public function query() {
    $query = $this->index()->query($this->query['options']);
    if ($this->query['keys']){
      $query->keys($this->query['keys']);
    }
    if ($this->query['fields']){
      $query->fields($this->query['fields']);
    }
    if ($this->query['filters']){
      $filters = &$query->getFilter()->getFilters();
      $filters = $this->query['filters'];
    }
    return $query;
  }

  /**
   * Return the URL where this search can be viewed, if any.
   */
  public function url() {
    if (isset($this->options['page']['path'])) {
      return url($this->options['page']['path'], $this->options['page']);
    }
  }

  /**
   * Return a link to the URL where this search can be viewed, if any.
   */
  public function l($text) {
    if (isset($this->options['page']['path'])) {
      return l($text, $this->options['page']['path'], $this->options['page']);
    }
  }

}
