<?php

/**
 * @file
 * Current Search plugin to provide Reset filters link.
 */

class FacetapiBonusCurrentSearchResetFiltersLink extends CurrentSearchItemText {
  /**
   * Implements CurrentSearchItem::execute().
   */
  public function execute(FacetapiAdapter $adapter) {
    $data = array('facetapi_adapter' => $adapter);

    // Determines plurality of string.
    if ($this->settings['plural']) {
      $condition = '[' . $this->settings['plural_condition'] . ']';
      $count = (int) token_replace($condition, $data);
      $raw_text = ($count != 1) ? $this->settings['text_plural'] : $this->settings['text'];
    }
    else {
      $raw_text = $this->settings['text'];
    }

    // Translates text, returns themed output.
    $translated_text = $this->translate('text', $raw_text);

    // Makes sure facet builds are initialized.
    $adapter->processFacets();

    // Get the right URL processor.
    $processor = $adapter->getUrlProcessor();

    // Build the query parameters.
    $query = $processor->normalizeParams($processor->fetchParams());

    // If no facets were selected stop here.
    $items = $adapter->getAllActiveItems();
    if (empty($items) && empty(array_filter($query))) {
      return;
    }

    // Remove the current facet key.
    unset($query[$processor->getFilterKey()]);

    // Get the path from either a basePath or the first search item if the
    // current URL processor doesn't provide a basePath.
    $path = method_exists($processor, 'getBasePath') ? $processor->getBasePath() : $this->getFacetPath(reset($items), $adapter);
    if ($this->settings['reset_type']) {
      $path = $processor->getBasePath();
      $reset_query_params = explode(',', $this->settings['reset_query_params']);
      foreach ($reset_query_params as $reset_query_param) {
        if (isset($query[trim($reset_query_param)])) {
          unset($query[trim($reset_query_param)]);
        }
      }
    }

    $variables = array(
      'text' => l(token_replace($translated_text, $data), $path, array('query' => $query, 'html' => TRUE)),
      'wrapper' => $this->settings['wrapper'],
      'element' => $this->settings['element'],
      'css' => $this->settings['css'],
      'class' => current_search_get_classes($this->settings['classes'], $data),
      'options' => array('html' => TRUE),
    );
    return array('#markup' => theme('current_search_text', $variables));
  }

  /**
   * Adds settings
   * @param $form
   * @param $form_state
   */
  public function settingsForm(&$form, &$form_state) {
    $form['reset_type'] = array(
      '#type' => 'checkbox',
      '#title' => t('Complete reset'),
      '#description' => t('This option will cause all querystring ($_GET) variables to be reset.  While heavy-handed, this is sometimes useful if you also want exposed filters on a view to be reset.'),
      '#default_value' => $this->settings['reset_type'],
    );

    $form['reset_query_params'] = array(
      '#type' => 'textfield',
      '#title' => t('Reset query parameters'),
      '#description' => t('Comma separated list of query parameters to reset.'),
      '#default_value' => $this->settings['reset_query_params'],
    );

    parent::settingsForm($form, $form_state);
  }

  /**
   * Implements CurrentSearchItem::getDefaultSettings().
   */
  public function getDefaultSettings() {
    $defaults = array(
      'reset_type' => 0,
    );
    return $defaults + parent::getDefaultSettings();
  }
}
