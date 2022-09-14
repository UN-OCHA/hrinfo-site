<?php

/**
 * Defines the container configuration entity.
 */
class GTMContainer {

  /**
   * The machine name for the configuration entity.
   *
   * To work with ctools, use public $name. In 8x this is protected $id.
   *
   * @var string
   */
  public $name;

  /**
   * The human-readable name of the configuration entity.
   *
   * @var string
   */
  public $label;

  /**
   * The enabled-disabled status of the configuration entity.
   *
   * @var bool
   */
  public $status = TRUE;

  /**
   * The weight of the configuration entity.
   *
   * @var int
   */
  public $weight = 0;

  /**
   * The Google Tag Manager container id.
   *
   * @var string
   */
  public $container_id;

  /**
   * The name of the data layer.
   *
   * @var string
   */
  public $data_layer;

  /**
   * Whether to add the listed classes to the data layer.
   *
   * @var bool
   */
  public $include_classes;

  /**
   * The white-listed classes.
   *
   * @var string
   */
  public $whitelist_classes;

  /**
   * The black-listed classes.
   *
   * @var string
   */
  public $blacklist_classes;

  /**
   * Whether to include the environment items in the applicable snippets.
   *
   * @var bool
   */
  public $include_environment;

  /**
   * The environment ID.
   *
   * @var string
   */
  public $environment_id;

  /**
   * The environment token.
   *
   * @var string
   */
  public $environment_token;

  /**
   * Whether to include or exclude the listed paths.
   *
   * @var string
   */
  public $path_toggle;

  /**
   * The listed paths.
   *
   * @var string
   */
  public $path_list;

  /**
   * Whether to include or exclude the listed roles.
   *
   * @var string
   */
  public $role_toggle;

  /**
   * The listed roles.
   *
   * @var array
   */
  public $role_list;

  /**
   * Whether to include or exclude the listed statuses.
   *
   * @var string
   */
  public $status_toggle;

  /**
   * The listed statuses.
   *
   * @var string
   */
  public $status_list;

  /**
   * Whether to include or exclude the listed realms. (optional)
   *
   * @var string
   */
  public $realm_toggle;

  /**
   * The listed realms. (optional)
   *
   * @var string
   */
  public $realm_list;

  /**
   * Constructs a container configuration object.
   *
   * @param array $values
   *   Associative array of container properties keyed by property name.
   * @param string $name
   *   (optional) Machine name of container to load.
   */
  public function __construct(array $values, $name = NULL) {
    if (empty($values) && $name) {
      // $values = (array) ctools_export_crud_load('gtag_config', "google_tag.container.$name");
      $values = (array) gtag_export_crud_load('gtag_config', "google_tag.container.$name");
    }
    // @todo Always append default container values to mimic variable_get()?
    foreach ($values as $key => $value) {
      $this->$key = $value;
    }

/*
    $values = array_diff_key($values, array_flip(['uuid', 'langcode']));
    if (empty($values)) {
      // Initialize entity properties from default container settings.
      $config = \GTMSettings::getInstance();
      foreach ($config->get('_default_container') as $key => $value) {
        $this->$key = $value;
      }
    }
*/
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
    $property = $property == 'id' ? 'name' : $property;
    return isset($this->$property) ? $this->$property : '';
  }

  /**
   * Returns the ID property.
   *
   * @return string
   *   The property.
   */
  public function id() {
    return $this->get('name');
  }

  /**
   * Returns array of JavaScript snippets.
   *
   * @return array
   *   Associative array of snippets keyed by type: script, noscript and
   *   data_layer.
   */
  public function snippets() {
    $snippets = array(
      'script' => $this->scriptSnippet(),
      'noscript' => $this->noscriptSnippet(),
      'data_layer' => $this->dataLayerSnippet(),
    );
    // Allow other modules to alter the snippets.
    drupal_alter('google_tag_snippets', $snippets, $this);
    return $snippets;
  }

  /**
   * Returns JavaScript script snippet.
   *
   * @return array
   *   The script snippet.
   */
  protected function scriptSnippet() {
    // Gather data.
    $compact = \GTMSettings::getInstance()->get('compact_snippet');
    $container_id = $this->variableClean('container_id');
    $data_layer = $this->variableClean('data_layer');
    $query = $this->environmentQuery();

    // Build script snippet.
    $script = <<<EOS
(function(w,d,s,l,i){

  w[l]=w[l]||[];
  w[l].push({'gtm.start':new Date().getTime(),event:'gtm.js'});
  var f=d.getElementsByTagName(s)[0];
  var j=d.createElement(s);
  var dl=l!='dataLayer'?'&l='+l:'';
  j.src='https://www.googletagmanager.com/gtm.js?id='+i+dl+'$query';
  j.async=true;
  f.parentNode.insertBefore(j,f);

})(window,document,'script','$data_layer','$container_id');
EOS;
    if ($compact) {
      $script = str_replace(array("\n", '  '), '', $script);
    }
    return $script;
  }

  /**
   * Returns JavaScript noscript snippet.
   *
   * @return array
   *   The noscript snippet.
   */
  protected function noscriptSnippet() {
    // Gather data.
    $compact = \GTMSettings::getInstance()->get('compact_snippet');
    $container_id = $this->variableClean('container_id');
    $query = $this->environmentQuery();

    // Build noscript snippet.
    $noscript = <<<EOS
<noscript aria-hidden="true"><iframe src="https://www.googletagmanager.com/ns.html?id=$container_id$query"
 height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
EOS;
    $noscript = <<<EOS
<iframe src="https://www.googletagmanager.com/ns.html?id=$container_id$query"
 height="0" width="0" style="display:none;visibility:hidden"></iframe>
EOS;
    if ($compact) {
      $noscript = str_replace("\n", '', $noscript);
    }
    return $noscript;
  }

  /**
   * Returns JavaScript data layer snippet or adds items to data layer.
   *
   * @return string|null
   *   The data layer snippet or NULL.
   */
  public function dataLayerSnippet(array &$classes = array()) {
    // Gather data.
    $data_layer = $this->variableClean('data_layer');
    $whitelist = $this->get('whitelist_classes');
    $blacklist = $this->get('blacklist_classes');

    $classes = array();
    $names = array('whitelist', 'blacklist');
    foreach ($names as $name) {
      // Inline code from google_tag_text_clean($$name, 'array');
      $$name = explode("\n", $$name);
      $$name = array_map('trim', $$name);
      $$name = array_filter($$name, 'trim');
      if (empty($$name)) {
        continue;
      }
      $classes["gtm.$name"] = $$name;
    }

    if ($classes) {
      // Build data layer snippet.
      $script = "var $data_layer = [" . drupal_json_encode($classes) . '];';
      return $script;
    }
  }

  /**
   * Returns a query string with the environment parameters.
   *
   * @return string
   *   The query string.
   */
  protected function environmentQuery() {
    if (!$this->get('include_environment')) {
      return '';
    }

    // Gather data.
    $environment_id = $this->variableClean('environment_id');
    $environment_token = $this->variableClean('environment_token');

    // Build query string.
    return "&gtm_auth=$environment_token&gtm_preview=$environment_id";
  }

  /**
   * Returns a cleansed variable.
   *
   * @param string $variable
   *   The variable name.
   *
   * @return string
   *   The cleansed variable.
   */
  public function variableClean($variable) {
    return trim(json_encode($this->get($variable)), '"');
  }

  /**
   * Determines whether to insert the snippet on the response.
   *
   * @return bool
   *   TRUE if the conditions are met; FALSE otherwise.
   */
  public function insertSnippet() {
    static $satisfied = array();

    if (!isset($satisfied[$this->name])) {
      $id = $this->get('container_id');

      if (empty($id)) {
        // No container ID.
        return $satisfied[$this->name] = FALSE;
      }

      $this->displayMessage('google_tag container ' . $this->name);
      $satisfied[$this->name] = TRUE;
      $types = google_tag_condition_filter();
      foreach ($types as $type => $value) {
        if (is_array($value) && isset($value['file'])) {
          $result = TRUE;
          $function = "_google_tag_condition_evaluate_$type";
          if (function_exists($function)) {
            $result = $function($this);
          }
        }
        else {
          $result = $this->genericCheck($type);
        }
        if (!$result) {
          // Omit snippet if any condition is not met.
          $satisfied[$this->name] = FALSE;
          break;
        }
      }

      // Allow other modules to alter the insertion criteria.
      drupal_alter('google_tag_insert', $satisfied[$this->name], $this);
      $this->displayMessage('after alter @satisfied', array('@satisfied' => $satisfied[$this->name]));
    }
    return $satisfied[$this->name];
  }

  /**
   * Determines whether to insert the snippet based on settings.
   *
   * @param string $type
   *   The condition type.
   *
   * @return bool
   *   TRUE if the conditions are met; FALSE otherwise.
   */
  public function genericCheck($type) {
    $this->toggle = "{$type}_toggle";
    $this->list = "{$type}_list";
    $this->context = "{$type}Context";
    $this->singular = $type;

    $toggle = $this->get($this->toggle);
    if (empty($toggle)) {
      // Condition is not configured.
      return TRUE;
    }
    $values = $this->get($this->list);
    $values = $values && is_array($values) ? array_filter($values) : $values;

    if (empty($values)) {
      $satisfied = ($toggle == GOOGLE_TAG_EXCLUDE_LISTED);
    }
    else {
      $value = $this->{$this->context}($values);
      if (is_string($values)) {
        // Examples: status and path.
        $satisfied = $value;
      }
      elseif (is_array($value)) {
        $satisfied = (bool) array_intersect($value, $values);
      }
      else {
        $satisfied = in_array($value, $values);
      }
      $satisfied = ($toggle == GOOGLE_TAG_EXCLUDE_LISTED) ? !$satisfied : $satisfied;
    }
    $this->displayMessage('@singular check @satisfied', array('@singular' => $this->singular, '@satisfied' => $satisfied));
    return $satisfied;
  }

  protected function statusContext($statuses) {
    // Get the HTTP response status.
    $status = drupal_get_http_header('status');
    return $status && strpos($statuses, (string) $status) !== FALSE;
  }

  protected function pathContext($paths) {
    // Compare the lowercase path alias (if any) and internal path.
    $paths = drupal_strtolower($paths);
    $path = drupal_strtolower(drupal_get_path_alias($_GET['q']));
    $satisfied = drupal_match_path($path, $paths);
    // @todo Lowercase $_GET['q'] before comparison? What is purpose of this check?
    if ($path != $_GET['q']) {
      $satisfied = $satisfied || drupal_match_path($_GET['q'], $paths);
    }
    return $satisfied;
  }

  protected function roleContext() {
    return $GLOBALS['user']->roles;
  }

  protected function domainContext() {
    // @todo Array dereference requires PHP 5.4+.
    return domain_get_domain()['machine_name'];
  }

  protected function languageContext() {
    return $GLOBALS['language']->language;
  }

  protected function realmContext() {
    return $this->realmKey();
  }

  /**
   * Returns applicable realm name and key for the request.
   *
   * @return string
   *   The realm name and key.
   */
  protected function realmKey() {
    static $value;
    if (!isset($value)) {
      list($realm_name, $realm_key) = google_tag_realm_values();
      $value = "$realm_name:$realm_key";
    }
    return $value;
  }

  /**
   * Displays a message.
   *
   * @param string $message
   *   The message to display.
   * @param array $args
   *   (optional) An associative array of replacements.
   */
  protected function displayMessage($message, array $args = array()) {
    if (\GTMSettings::getInstance()->get('debug_output')) {
      drupal_set_message(t($message, $args));
    }
  }

  /**
   * Returns the snippet directory path.
   *
   * @return string
   *   The snippet directory path.
   */
  public function snippetDirectory() {
    return \GTMSettings::getInstance()->get('uri') . "/google_tag/{$this->id()}";
  }

  /**
   * Returns the snippet URI for a snippet type.
   *
   * @param string $type
   *   The snippet type.
   *
   * @return string
   *   The snippet URI.
   */
  public function snippetURI($type) {
    return $this->snippetDirectory() . "/google_tag.$type.js";
  }

  /**
   * Returns tag array for the snippet type.
   *
   * @param string $type
   *   The snippet type.
   * @param int $weight
   *   The weight of the item.
   *
   * @return array
   *   The tag array. [not used]
   */
  public function fileTag($type, $weight) {
    $uri = $this->snippetURI($type);
    // file_create_url() is invoked in the JS render workflow.
    $url = file_create_url($uri);
    $query_string = variable_get('css_js_query_string', '');

    // This omits the query string, but drupal adds it.
    // This outputs defer="defer"; see drupal_get_js()
    drupal_add_js($url, array('group' => JS_LIBRARY * 2, 'requires_jquery' => FALSE, 'defer' => TRUE));

    // This approach uses weight only but does not group the script tags so
    // difficult to put this at or near top of them.
    // This approach does not allow 'requires_jquery' to be set.
    // Needs the '#value' key to get a closing tag with theme_html_tag().
    // This outputs defer="1"
    // drupal_add_html_head($attachment[0], $attachment[1]);
    $attachment = array(
      array(
        '#type' => 'html_tag',
        '#tag' => 'script',
        '#attributes' => array('type' => 'text/javascript', 'src' => $url . '?' . $query_string, 'defer' => TRUE),
        '#weight' => $weight,
        '#value' => '',
      ),
      "google_tag_{$type}_tag__{$this->id()}",
    );
    return $attachment;
  }

  /**
   * Returns tag array for the snippet type.
   *
   * @param string $type
   *   The snippet type.
   * @param int $weight
   *   The weight of the item.
   *
   * @return array
   *   The tag array. [not used]
   */
  public function inlineTag($type, $weight) {
    $uri = $this->snippetURI($type);
    $url = drupal_realpath($uri);
    $contents = @file_get_contents($url);
    drupal_add_js($contents, array('type' => 'inline', 'group' => JS_LIBRARY * 2, 'requires_jquery' => FALSE));

    // This approach uses weight only but does not group the script tags so
    // difficult to put this at or near top of them.
    // drupal_add_html_head($attachment[0], $attachment[1]);
    $attachment = array(
      $contents ? array(
        '#type' => 'html_tag',
        '#tag' => 'script',
        '#value' => $contents,
        '#weight' => $weight,
      )
      : array('#type' => 'ignore_tag'),
      "google_tag_{$type}_tag__{$this->id()}",
    );
    return $attachment;
  }

  /**
   * Returns tag array for the snippet type.
   *
   * @param string $type
   *   (optional) The snippet type.
   * @param int $weight
   *   (optional) The weight of the item.
   *
   * @return array
   *   The tag array.
   */
  public function noscriptTag($type = 'noscript', $weight = -10) {
    // Note: depending on the theme, this may not place the snippet immediately
    // after the body tag but should be close and it can be altered.

    // https://developer.mozilla.org/en-US/docs/Web/Accessibility/ARIA/ARIA_Techniques/Using_the_aria-hidden_attribute
    // Do not add aria-hidden if element or ancestor is hidden with
    // display:none or visibility:hidden. Both are on the iframe tag inside the
    // noscript tag.

    // TRUE outputs as aria-hidden="1"
    $uri = $this->snippetURI($type);
    $url = drupal_realpath($uri);
    $contents = @file_get_contents($url);
    $attachment = $contents ? array(
      "google_tag_{$type}_tag__{$this->id()}" => array(
        '#type' => 'html_tag',
        '#tag' => 'noscript',
        '#value' => $contents,
        '#attributes' => array('aria-hidden' => 'true'),
      ),
    ) : array();
    return $attachment;
  }

  /**
   * Saves configuration to database.
   *
   * @param int $export_type
   *   (optional) The indicator of a new or existing configuration item.
   *
   * @return bool
   *   Whether the save was successful.
   */
  public function save($export_type = EXPORT_IN_DATABASE) {
    // $export_type = isset($this->export_type) ? $this->export_type : NULL;
    $export_type = isset($this->export_type) ? $this->export_type : $export_type;
    $data = (array) $this;

    $config['name'] = "google_tag.container.{$this->name}";
    $config['data'] = $data;
    $config['type'] = 'Normal';
    $config['export_type'] = $export_type;
    $config = (object) $config;
    $result = ctools_export_crud_save('gtag_config', $config);
    return $result;
  }

  /**
   * Deletes configuration from database.
   */
  public function delete() {
    $data = (array) $this;

    $config['name'] = "google_tag.container.{$this->name}";
    $config['data'] = $data;
    $config = (object) $config;
    ctools_export_crud_delete('gtag_config', $config);
  }

}
