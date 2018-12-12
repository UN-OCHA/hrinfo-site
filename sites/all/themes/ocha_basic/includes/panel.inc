<?php
/**
 * @file
 * Theme and preprocess functions for panels and panes.
 */

function ocha_basic_field__field_documents($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  if ($variables['element']['#view_mode'] == 'link') {
    $output .= '<ul class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
      $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<li class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
    }
    $output .= '</ul>';
  }
  else {
    $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
      $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
    }
    $output .= '</div>';
  }

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Change labels of panel panes in add content modal form
 * See http://atrium.humanitarianresponse.info/humanitarian_response/node/4506
 */
function ocha_basic_preprocess_panels_add_content_modal(&$vars) {
  // Remove redundant array.
  unset($vars['categories_array']);
  
  // Remove adding assesment.
  unset($vars['root_content_array']);

  // Process the list of categories.
  foreach ($vars['categories'] as $key => $category_info) {
    // 'root' category is actually displayed under the categories, so
    // skip it.
    if ($key == 'root') {
      continue;
    }

    $class = 'panels-modal-add-category btn btn-default';
    if ($key == $vars['category']) {
      $class .= ' active';
    }

    $url = $vars['renderer']->get_url('select-content', $vars['region'], $key);
    $vars['categories_array'][] = ctools_ajax_text_button($category_info['title'], $url, '', $class);
  }

  // Now render the top level buttons (aka the root category) if any.
  $vars['root_content'] = '';
  if (!empty($vars['categories']['root'])) {
    foreach ($vars['categories']['root']['content'] as $content_type) {
      $vars['root_content'] .= theme('panels_add_content_link', array('renderer' => $vars['renderer'], 'region' => $vars['region'], 'content_type' => $content_type));
    }
  }
}
