<?php

/**
 * @file
 * Contains the SearchApiSavedSearchesViewsHandlerFieldName class.
 */

/**
 * Views field handler for displaying a saved search's name, optionally linked to the search page.
 */
class SearchApiSavedSearchesViewsHandlerFieldName extends views_handler_field {

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
    $value = parent::render($values);
    if ($value && $this->options['link_to_page']) {
      $this->render_link($values);
    }
    return $value;
  }

  public function render_link($values) {
    $search = !empty($values->id) ? search_api_saved_search_load($values->id) : NULL;
    if (search_api_saved_search_edit_access(NULL, $search) && !empty($search->options['page'])) {
      $this->options['alter']['make_link'] = TRUE;
      $page = $search->options['page'] + array(
        'path' => NULL,
        'query' => array(),
        'absolute' => TRUE,
      );
      $this->options['alter']['path'] = url($page['path'], $page);
    }
  }

}
