<?php

/**
 * @file
 * Theme functions for SearchAPI Sorts Widget.
 */

/**
 * Theme a list of sort options.
 *
 * @param array $variables
 *   An associative array containing:
 *   - items: The sort options
 *   - options: Various options to pass
 */
function theme_search_api_sorts_widget_form(array $variables) {
  $items = $variables['items'];
  $options = $variables['options'];

  if ($items) {
    $form = drupal_get_form('search_api_sorts_widget_form', $items, $options);
    return drupal_render($form);
  }
  else {
    return '';
  }
}
