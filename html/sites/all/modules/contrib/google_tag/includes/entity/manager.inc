<?php

/**
 * Defines the Google tag container manager.
 */
class GTMContainerManager implements ContainerManagerInterface {

  /**
   * Singleton instance of this class.
   *
   * @var GTMContainerManager
   */
  private static $instance;

  /**
   * Returns singleton instance of this class.
   *
   * @return GTMContainerManager
   *   The instance.
   */
  public static function getInstance() {
    if (!self::$instance) {
      self::$instance = new GTMContainerManager();
    }
    return self::$instance;
  }

  /**
   * {@inheritdoc}
   */
  public function createAssets($container) {
    $result = TRUE;
    $directory = $container->snippetDirectory();
    if (!is_dir($directory) || !_google_tag_is_writable($directory) || !_google_tag_is_executable($directory)) {
      $result = _file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    }
    if ($result) {
      $result = $this->saveSnippets($container);
    }
    else {
      $args = array('%directory' => $directory);
      $message = 'The directory %directory could not be prepared for use, possibly due to file system permissions. The directory either does not exist, or is not writable or searchable.';
      $this->displayMessage($message, $args, 'error');
      watchdog('google_tag', $message, $args, WATCHDOG_ERROR);
    }
    return $result;
  }

  /**
   * {@inheritdoc}
   */
  public function saveSnippets($container) {
    // Save the altered snippets after hook_google_tag_snippets_alter().
    $result = TRUE;
    $snippets = $container->snippets();
    foreach ($snippets as $type => $snippet) {
      $uri = $container->snippetURI($type);
      $path = file_unmanaged_save_data($snippet, $uri, FILE_EXISTS_REPLACE);
      $result = !$path ? FALSE : $result;
    }
    $args = array('@count' => count($snippets), '%container' => $container->get('label'));
    if (!$result) {
      $message = 'An error occurred saving @count snippet files for %container container. Contact the site administrator if this persists.';
      $this->displayMessage($message, $args, MessengerInterface::TYPE_ERROR);
      watchdog('google_tag', $message, $args, WATCHDOG_ERROR);
    }
    else {
      $message = 'Created @count snippet files for %container container based on configuration.';
      $this->displayMessage($message, $args);
      // Reset the URL query argument so browsers reload snippet files.
      _drupal_flush_css_js();
    }
    return $result;
  }

  /**
   * Displays a message to admin users.
   *
   * @param string $message
   *   The message to display.
   * @param array $args
   *   (optional) An associative array of replacements.
   * @param string $type
   *   (optional) The message type. Defaults to 'status'.
   */
  public function displayMessage($message, array $args = array(), $type = 'status') {
    global $_google_tag_display_message;
    if ($_google_tag_display_message) {
      drupal_set_message(t($message, $args), $type);
    }
  }

  /**
   * Returns the container entities sorted by weight.
   *
   * @return array
   *   The array of container entity objects.
   *
   * @todo Implement status property and filter on it.
   */
  public function loadContainers() {
    static $containers;
    if (!isset($containers)) {
      ctools_include('export');
      $keys = array_flip(array('settings'));
      $objects = ctools_export_load_object('gtag_config', 'all');
      $objects = array_diff_key($objects, $keys);
      $containers = array();
      foreach ($objects as $object) {
        $containers[] = new GTMContainer((array) $object);
      }
      usort($containers, function ($a, $b) {
        return (int) $b->weight < (int) $a->weight;
      });
    }
    return $containers;
  }

  /**
   * {@inheritdoc}
   */
  public function getScriptAttachments(array &$page) {
    $containers = $this->loadContainers();
    foreach ($containers as $container) {
      if (!$container->insertSnippet()) {
        continue;
      }

      static $weight = 9;
      $include_script_as_file = \GTMSettings::getInstance()->get('include_file');
      $include_classes = $container->get('include_classes');
      // @todo Only want one data_layer snippet even with multiple containers.
      // If user sorts containers such that the first does not define the data
      // layer, then validate this or adjust for it here.
      // Sort the items being added and put the data_layer at top?
      $types = $include_classes ? array('data_layer', 'script') : array('script');

      $data_layer = $container->get('data_layer');
      if ($include_classes && module_exists('datalayer') && $data_layer == 'dataLayer') {
        $container->dataLayerSnippet($classes);
        if ($classes) {
          // Add data_layer using dataLayer module.
          datalayer_add($classes);
        }
        $types = array('script');
      }

      // Add data_layer and script snippets to head (no longer by default).
      if ($include_script_as_file) {
        foreach ($types as $type) {
          // @todo Will it matter if file is empty?
          // @todo Check config for the whitelist and blacklist classes before adding.
          $container->fileTag($type, $weight++);
        }
      }
      else {
        foreach ($types as $type) {
          // @see drupal_get_js() in 7.x core.
          // For inline JavaScript to validate as XHTML, all JavaScript containing
          // XHTML needs to be wrapped in CDATA.
          $container->inlineTag($type, $weight++);
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getNoScriptAttachments(array &$page) {
    $containers = $this->loadContainers();
    foreach ($containers as $container) {
      if (!$container->insertSnippet()) {
        continue;
      }

      $page += array('page_top' => array());
      $page['page_top'] += $container->noscriptTag();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function createAllAssets() {
    $containers = $this->loadContainers();
    if (!$containers) {
      return;
    }
    if (\GTMSettings::getInstance()->get('flush_snippets')) {
      $directory = \GTMSettings::getInstance()->get('uri');
      if (!empty($directory)) {
        // Remove any stale files (e.g. module update or machine name change).
        file_unmanaged_delete_recursive($directory . '/google_tag');
      }
    }
    // Create snippet files for enabled containers.
    // $containers = $this->loadContainers();
    $result = TRUE;
    foreach ($containers as $container) {
      $result = !$this->createAssets($container) ? FALSE : $result;
    }
    return $result;
  }

}
