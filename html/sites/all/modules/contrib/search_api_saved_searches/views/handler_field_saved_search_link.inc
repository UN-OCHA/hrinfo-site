<?php

/**
 * @file
 * Contains the SearchApiSavedSearchesViewsHandlerFieldName class.
 */

/**
 * Views field handler for displaying a saved search's name, optionally linked to the search page.
 */
class SearchApiSavedSearchesViewsHandlerFieldLink extends views_handler_field {

  public function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '');

    return $options;
  }

  public function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Link label'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);

    // The path is set by render() so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  public function render($values) {
    $search = !empty($values->id) ? search_api_saved_search_load($values->id) : NULL;
    if (search_api_saved_search_edit_access(NULL, $search)) {
      $url = $url = 'search-api/saved-search/' . $search->id;
      switch ($this->real_field) {
        case 'edit_link':
          $default_label = t('edit');
          $url .= '/edit';
          break;
        case 'delete_link':
          $default_label = t('delete');
          $url .= '/delete';
          break;

        default:
          return;
      }
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $url;

      return $this->options['text'] ? $this->options['text'] : $default_label;
    }
  }

}
