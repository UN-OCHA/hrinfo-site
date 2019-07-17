<?php

/**
 * @file
 * Contains the SearchApiSavedSearchesViewsHandlerFieldName class.
 */

/**
 * Views field handler for displaying a saved search's name, optionally linked to the search page.
 */
class SearchApiSavedSearchesViewsHandlerFieldName extends views_handler_field {

  /**
   * The ID of the currently rendered search.
   *
   * @var int|null
   */
  protected $currentSearchId;

  public function option_definition() {
    $options = parent::option_definition();

    $options['link_to_page'] = array('default' => TRUE);

    return $options;
  }

  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_to_page'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link to search page'),
      '#default_value' => $this->options['link_to_page'],
    );
  }

  public function render($values) {
    $this->currentSearchId = isset($values->id) ? $values->id : NULL;
    return parent::render($values);
  }

  public function render_text($alter) {
    if ($this->options['link_to_page'] && $this->currentSearchId) {
      $search = search_api_saved_search_load($this->currentSearchId);
      if ($search && search_api_saved_search_edit_access(NULL, $search) && !empty($search->options['page'])) {
        $alter['make_link'] = TRUE;
        $page = $search->options['page'] + array(
          'path' => NULL,
          'query' => array(),
        );
        $alter['path'] = $page['path'];
        if ($page['query']) {
          $query = urldecode(drupal_http_build_query($page['query']));
          $alter['path'] .= '?' . $query;
        }
      }
    }
    return parent::render_text($alter);
  }

}
