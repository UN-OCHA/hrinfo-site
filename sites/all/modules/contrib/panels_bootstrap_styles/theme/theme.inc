<?php

/**
 * Implements hook_preprocess_panels_pane_bootstrap().
 */
function template_preprocess_panels_bootstrap_pane(&$vars, $hook) {
  $content = $vars['content'];
  $style = $vars['style'];
  $substyle = $style['substyle'];

  panels_bootstrap_styles_preprocess_contextual_links($vars, $content);

  $vars['pane_prefix'] = !empty($content->pane_prefix) ? $content->pane_prefix : '';
  $vars['pane_suffix'] = !empty($content->pane_suffix) ? $content->pane_suffix : '';

  $vars['id'] = '';

  // Basic classes.
  $vars['classes_array'] = array_merge(array('panel-bootstrap-pane'), $vars['style_settings']['wrapper_classes']);

  // Add some usable classes based on type/subtype
  ctools_include('cleanstring');
  $type_class = $content->type ? 'pane-' . ctools_cleanstring($content->type, array('lower case' => TRUE)) : '';
  $subtype_class = $content->subtype ? 'pane-' . ctools_cleanstring($content->subtype, array('lower case' => TRUE)) : '';

  // Sometimes type and subtype are the same. Avoid redundant classes.
  $vars['classes_array'][] = $type_class;
  if ($type_class != $subtype_class) {
    $vars['classes_array'][] = $subtype_class;
  }

  // Add id and custom class if sent in.
  if (!empty($content->content)) {
    if (!empty($content->css_id)) {
      $vars['id'] = $content->css_id;
    }
    if (!empty($content->css_class)) {
      $vars['classes_array'][] = $content->css_class;
    }
  }

  /* Wrapper */
  $vars['wrapper_element'] = $vars['style_settings']['wrapper_element'];

  /* Header */
  $vars['header_element'] = $vars['style_settings']['header_element'];
  $vars['header_attributes_array']['class'][] = $vars['style_settings']['header_class'];

  /* Title */
  $vars['title'] = !empty($content->title) ? $content->title : '';
  $vars['title_element'] = $vars['style_settings']['title_element'];
  $vars['title_attributes_array']['class'][] = $vars['style_settings']['title_class'];

  /* Content */
  $vars['content'] = !empty($content->content) ? $content->content : '';
  $vars['content_element'] = $vars['style_settings']['content_element'];
  $vars['content_attributes_array']['class'] = $vars['style_settings']['content_class'];

  /* Footer */
  $vars['footer'] = !empty($content->footer) ? $content->footer : '';
  $vars['footer_element'] = $vars['style_settings']['footer_element'];
  $vars['footer_attributes_array']['class'][] = $vars['style_settings']['footer_class'];

  /* Links */
  $vars['links'] = !empty($content->links) ? theme('links', array('links' => $content->links)) : '';
  $vars['links_element'] = $vars['style_settings']['links_element'];

  $vars['feeds'] = !empty($content->feeds) ? implode(' ', $content->feeds) : '';

  $vars['more'] = '';
  if (!empty($content->more)) {
    if (empty($content->more['title'])) {
      $content->more['title'] = t('more');
    }
    $vars['more'] = l($content->more['title'], $content->more['href'], $content->more);
  }

  $vars['collapsible'] = !empty($vars['#collapsible']);
  $vars['collapsed'] = !empty($vars['#collapsed']);

  // For Collapsing to work we need an id and a title to be set.
  if ($vars['collapsible']) {
    $id_index = &drupal_static(__FUNCTION__, 0);
    if (empty($vars['id'])) {
      ++$id_index;
      $vars['id'] = 'pane-' . (string) $id_index;
    }
    if (empty($vars['title'])) {
      // TODO Come up with a better solution.
      $vars['title'] = '<span class="center-block">&nbsp;&nbsp;&nbsp;</span>';
    }
  }

  // Set up some placeholders for constructing template file names.
  $delimiter = '__';
  $substyle_suggestion = $hook . $delimiter . $substyle['name'];
  // Add template file suggestion for content type and sub-type.
  $vars['theme_hook_suggestions'][] = $substyle_suggestion;
  $vars['theme_hook_suggestions'][] = $substyle_suggestion . $delimiter .  $content->type;
  $vars['theme_hook_suggestions'][] = $substyle_suggestion . $delimiter . strtr($content->type, '-', '_') . $delimiter . strtr($content->subtype, '-', '_');

}


/**
 * Implements hook_process_panels_bootstrap_pane().
 */
function template_process_panels_bootstrap_pane(&$variables, $hook) {
  // Flatten out classes.
  $variables['classes'] = implode(' ', $variables['classes_array']);

  if (!empty($variables['classes'])) {
    $variables['wrapper_attributes_array']['class'] = $variables['classes'];
  }
  if (!empty($vars['id'])) {
    $variables['wrapper_attributes_array']['id'] = $variables['id'];
  }

  // Flatten out the various attributes, because this function can be called
  // very often, and often with empty attributes, optimize performance by only
  // calling drupal_attributes() if necessary.
  $variables['wrapper_attributes'] = $variables['wrapper_attributes_array'] ? drupal_attributes($variables['wrapper_attributes_array']) : '';
  $variables['header_attributes'] = $variables['header_attributes_array'] ? drupal_attributes($variables['header_attributes_array']) : '';
  $variables['title_attributes'] = $variables['title_attributes_array'] ? drupal_attributes($variables['title_attributes_array']) : '';
  $variables['content_attributes'] = $variables['content_attributes_array'] ? drupal_attributes($variables['content_attributes_array']) : '';
  $variables['footer_attributes'] = $variables['footer_attributes_array'] ? drupal_attributes($variables['footer_attributes_array']) : '';
}

/**
 * Implements hook_preprocess_panels_pane_bootstrap().
 */
function template_preprocess_panels_bootstrap_region(&$vars, $hook) {
  $panes = $vars['panes'];
  $style = $vars['style'];
  $substyle = $style['substyle'];

  $vars['id'] = '';

  // Basic classes.
  $vars['classes_array'] = array_merge(array('panel-bootstrap-pane'), $vars['style_settings']['wrapper_classes']);

  /* Wrapper */
  $vars['wrapper_element'] = $vars['style_settings']['wrapper_element'];

  /* Header */
  $vars['header_element'] = $vars['style_settings']['header_element'];
  $vars['header_attributes_array']['class'][] = $vars['style_settings']['header_class'];

  /* Title */
  $vars['title'] = !empty($vars['style_settings']['region_title']) ? $vars['style_settings']['region_title'] : '';
  $vars['title_element'] = $vars['style_settings']['title_element'];
  $vars['title_attributes_array']['class'][] = $vars['style_settings']['title_class'];

  /* Content */
  $vars['content_element'] = $vars['style_settings']['content_element'];
  $vars['content_attributes_array']['class'] = $vars['style_settings']['content_class'];

  $vars['collapsible'] = !empty($vars['#collapsible']);
  $vars['collapsed'] = !empty($vars['#collapsed']);

  // For Collapsing to work we need an id and a title to be set.
  if ($vars['collapsible']) {
    $id_index = &drupal_static(__FUNCTION__, 0);
    if (empty($vars['id'])) {
      ++$id_index;
      $vars['id'] = 'pane-' . (string) $id_index;
    }
    if (empty($vars['title'])) {
      // TODO Come up with a better solution.
      $vars['title'] = '<span class="center-block">&nbsp;&nbsp;&nbsp;</span>';
    }
  }

  // Set up some placeholders for constructing template file names.
  $delimiter = '__';
  $substyle_suggestion = $hook . $delimiter . $substyle['name'];
  // Add template file suggestion for content type and sub-type.
  $vars['theme_hook_suggestions'][] = $substyle_suggestion;

}


/**
 * Implements hook_process_panels_bootstrap_pane().
 */
function template_process_panels_bootstrap_region(&$variables, $hook) {
  // Flatten out classes.
  $variables['classes'] = implode(' ', $variables['classes_array']);

  if (!empty($variables['classes'])) {
    $variables['wrapper_attributes_array']['class'] = $variables['classes'];
  }
  if (!empty($vars['id'])) {
    $variables['wrapper_attributes_array']['id'] = $variables['id'];
  }

  // Flatten out the various attributes, because this function can be called
  // very often, and often with empty attributes, optimize performance by only
  // calling drupal_attributes() if necessary.
  $variables['wrapper_attributes'] = $variables['wrapper_attributes_array'] ? drupal_attributes($variables['wrapper_attributes_array']) : '';
  $variables['header_attributes'] = $variables['header_attributes_array'] ? drupal_attributes($variables['header_attributes_array']) : '';
  $variables['title_attributes'] = $variables['title_attributes_array'] ? drupal_attributes($variables['title_attributes_array']) : '';
  $variables['content_attributes'] = $variables['content_attributes_array'] ? drupal_attributes($variables['content_attributes_array']) : '';
}

/**
 * Prepares the contextual links for the pane.
 * @param $vars
 * @param $content
 */
function panels_bootstrap_styles_preprocess_contextual_links(&$vars, $content) {
  $vars['contextual_links'] = array();
  $vars['admin_links'] = '';
  if (module_exists('contextual') && user_access('access contextual links')) {
    $links = array();
    // These are specified by the content.
    if (!empty($content->admin_links)) {
      $links += $content->admin_links;
    }

    // Take any that may have been in the render array we were given and
    // move them up so they appear outside the pane properly.
    if (is_array($content->content) && isset($content->content['#contextual_links'])) {
      $element = array(
        '#type' => 'contextual_links',
        '#contextual_links' => $content->content['#contextual_links'],
      );
      unset($content->content['#contextual_links']);

      // Add content to $element array.
      if (is_array($content->content)) {
        $element['#element'] = $content->content;
      }

      $element = contextual_pre_render_links($element);
      $links += $element['#links'];
    }

    if ($links) {
      $build = array(
        '#prefix' => '<div class="contextual-links-wrapper">',
        '#suffix' => '</div>',
        '#theme' => 'links__contextual',
        '#links' => $links,
        '#attributes' => array('class' => array('contextual-links')),
        '#attached' => array(
          'library' => array(array('contextual', 'contextual-links')),
        ),
      );
      $vars['classes_array'][] = 'contextual-links-region';
      $vars['admin_links'] = drupal_render($build);
    }
  }
}
