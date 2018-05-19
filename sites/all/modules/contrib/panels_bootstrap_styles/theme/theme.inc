<?php

/**
 * @file
 * Theme processings for panel panes and regions.
 */

/**
 * Implements hook_preprocess_panels_pane_bootstrap().
 */
function template_preprocess_panels_bootstrap_pane(&$variables, $hook) {
  $content = $variables['content'];
  $style = $variables['style'];
  $substyle = $style['substyle'];

  panels_bootstrap_styles_preprocess_contextual_links($variables, $content);

  $variables['pane_prefix'] = !empty($content->pane_prefix) ? $content->pane_prefix : '';
  $variables['pane_suffix'] = !empty($content->pane_suffix) ? $content->pane_suffix : '';

  $variables['id'] = '';

  // Basic classes.
  $variables['classes_array'] = array_merge(array('panel-bootstrap-pane'), $variables['style_settings']['wrapper_classes']);

  // Add some usable classes based on type/subtype.
  ctools_include('cleanstring');
  $type_class = $content->type ? 'pane-' . ctools_cleanstring($content->type, array('lower case' => TRUE)) : '';
  $subtype_class = $content->subtype ? 'pane-' . ctools_cleanstring($content->subtype, array('lower case' => TRUE)) : '';

  // Sometimes type and subtype are the same. Avoid redundant classes.
  $variables['classes_array'][] = $type_class;
  if ($type_class != $subtype_class) {
    $variables['classes_array'][] = $subtype_class;
  }

  // Add id and custom class if sent in.
  if (!empty($content->content)) {
    if (!empty($content->css_id)) {
      $variables['id'] = $content->css_id;
    }
    if (!empty($content->css_class)) {
      $variables['classes_array'][] = $content->css_class;
    }
  }

  /* Wrapper */
  $variables['wrapper_element'] = $variables['style_settings']['wrapper_element'];

  /* Header */
  $variables['header_element'] = $variables['style_settings']['header_element'];
  $variables['header_attributes_array']['class'][] = $variables['style_settings']['header_class'];

  /* Title */
  $variables['title'] = !empty($content->title) ? $content->title : '';
  $variables['title_element'] = $variables['style_settings']['title_element'];
  $variables['title_attributes_array']['class'][] = $variables['style_settings']['title_class'];

  /* Content */
  $variables['content'] = !empty($content->content) ? $content->content : '';
  $variables['content_element'] = $variables['style_settings']['content_element'];
  $variables['content_attributes_array']['class'] = $variables['style_settings']['content_class'];

  /* Footer */
  $variables['footer'] = !empty($content->footer) ? $content->footer : '';
  $variables['footer_element'] = $variables['style_settings']['footer_element'];
  $variables['footer_attributes_array']['class'][] = $variables['style_settings']['footer_class'];

  /* Links */
  $variables['links'] = !empty($content->links) ? theme('links', array('links' => $content->links)) : '';
  $variables['links_element'] = $variables['style_settings']['links_element'];

  $variables['feeds'] = !empty($content->feeds) ? implode(' ', $content->feeds) : '';

  $variables['more'] = '';
  if (!empty($content->more)) {
    if (empty($content->more['title'])) {
      $content->more['title'] = t('more');
    }
    $variables['more'] = l($content->more['title'], $content->more['href'], $content->more);
  }

  $variables['collapsible'] = !empty($variables['#collapsible']);
  $variables['collapsed'] = !empty($variables['#collapsed']);

  // For Collapsing to work we need an id and a title to be set.
  if ($variables['collapsible']) {
    $id_index = &drupal_static(__FUNCTION__, 0);
    if (empty($variables['id'])) {
      ++$id_index;
      $variables['id'] = 'pane-' . (string) $id_index;
    }
    if (empty($variables['title'])) {
      // TODO Come up with a better solution.
      $variables['title'] = '<span class="center-block">&nbsp;&nbsp;&nbsp;</span>';
    }
  }

  // Set up some placeholders for constructing template file names.
  $delimiter = '__';
  $substyle_suggestion = $hook . $delimiter . $substyle['name'];
  // Add template file suggestion for content type and sub-type.
  $variables['theme_hook_suggestions'][] = $substyle_suggestion;
  $variables['theme_hook_suggestions'][] = $substyle_suggestion . $delimiter . $content->type;
  $variables['theme_hook_suggestions'][] = $substyle_suggestion . $delimiter . strtr($content->type, '-', '_') . $delimiter . strtr($content->subtype, '-', '_');
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
  if (!empty($variables['id'])) {
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

  $pane_title = &drupal_static('pane_' . $variables['pane']->pid . '_title');
  $pane_title = $variables['title'];
}

/**
 * Implements hook_preprocess_panels_pane_bootstrap().
 */
function template_preprocess_panels_bootstrap_region(&$variables, $hook) {
  $panes = $variables['panes'];
  $style = $variables['style'];
  $substyle = $style['substyle'];

  $variables['id'] = '';

  // Basic classes.
  $variables['classes_array'] = array_merge(array('panel-bootstrap-pane'), $variables['style_settings']['wrapper_classes']);

  /* Wrapper */
  $variables['wrapper_element'] = $variables['style_settings']['wrapper_element'];

  /* Header */
  $variables['header_element'] = $variables['style_settings']['header_element'];
  $variables['header_attributes_array']['class'][] = $variables['style_settings']['header_class'];

  /* Title */
  $variables['title'] = !empty($variables['style_settings']['region_title']) ? $variables['style_settings']['region_title'] : '';
  $variables['title_element'] = $variables['style_settings']['title_element'];
  $variables['title_attributes_array']['class'][] = $variables['style_settings']['title_class'];

  /* Content */
  $variables['content_element'] = $variables['style_settings']['content_element'];
  $variables['content_attributes_array']['class'] = $variables['style_settings']['content_class'];

  $variables['collapsible'] = !empty($variables['#collapsible']);
  $variables['collapsed'] = !empty($variables['#collapsed']);

  // For Collapsing to work we need an id and a title to be set.
  if ($variables['collapsible']) {
    $id_index = &drupal_static(__FUNCTION__, 0);
    if (empty($variables['id'])) {
      ++$id_index;
      $variables['id'] = 'pane-' . (string) $id_index;
    }
    if (empty($variables['title'])) {
      // TODO Come up with a better solution.
      $variables['title'] = '<span class="center-block">&nbsp;&nbsp;&nbsp;</span>';
    }
  }

  // Set up some placeholders for constructing template file names.
  $delimiter = '__';
  $substyle_suggestion = $hook . $delimiter . $substyle['name'];
  // Add template file suggestion for content type and sub-type.
  $variables['theme_hook_suggestions'][] = $substyle_suggestion;
  $variables['theme_hook_suggestions'][] = $substyle_suggestion . $delimiter . $variables['region_id'];
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
  if (!empty($variables['id'])) {
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
 * Implements hook_preprocess_panels_pane_bootstrap().
 */
function template_preprocess_panels_bootstrap_tabs(&$variables, $hook) {
  $panes = $variables['panes'];
  $settings = $variables['settings'];
  $tab_titles = array();
  $tab_panes = array();
  $variables['tab_classes_array'] = array();
  $variables['nav_wrapper_classes_array'] = array();
  $variables['tab_content_wrapper_classes_array'] = array();

  // Generate tab titles.
  $i = 0;
  foreach ($panes as $pane_id => $pane) {
    if ($i == 0) {
      $output = '<li class="active">';
      $i++;
    }
    else {
      $output = '<li>';
      $i++;
    }
    $pane_title = &drupal_static('pane_' . $pane_id . '_title');
    if (empty($pane_title)) {
      $pane_title = 'This pane needs a title.';
    }
    $output .= '<a href="#pane-' . $pane_id . '" data-toggle="tab">' . $pane_title . '</a>';

    $output .= '</li>';
    $tab_titles[] = $output;
  }
  // Generate tab content.
  $i = 0;
  foreach ($panes as $pane_id => $pane) {
    $content_classes = array('tab-pane');
    // Add active class.
    if ($i == 0) {
      $content_classes[] = 'active';
      $i++;
    }
    $output = '<div id="pane-' . $pane_id . '" class="' . implode(' ', $content_classes) . '">' . $pane . '</div>';
    $tab_panes[] = $output;
  }
  // Add tab classes.
  $variables['tab_classes_array'][] = 'nav';
  $variables['tab_classes_array'][] = !empty($settings['tab_type']) ? $settings['tab_type'] : 'nav-tabs';
  if (!empty($settings['tab_display']) && $settings['tab_display'] != 'default') {
    $variables['tab_classes_array'][] = $settings['tab_display'];
  }
  $variables['tab_classes'] = implode(' ', $variables['tab_classes_array']);
  // Add nav wrapper classes.
  $variables['nav_wrapper_classes_array'][] = 'nav-wrapper';
  $variables['nav_wrapper_classes'] = implode(' ', $variables['nav_wrapper_classes_array']);
  // Add tab content wrapper classes.
  $variables['tab_content_wrapper_classes_array'][] = 'tab-content-wrapper';
  $variables['tab_content_wrapper_classes'] = implode(' ', $variables['tab_content_wrapper_classes_array']);

  $variables['tab_titles'] = $tab_titles;
  $variables['tab_panes'] = $tab_panes;
}

/**
 * Prepares the contextual links for the pane.
 *
 * @param array $variables
 *   Provided variables by reference.
 * @param object $content
 *   Content from template_preprocess_panels_bootstrap_pane.
 */
function panels_bootstrap_styles_preprocess_contextual_links(&$variables, $content) {
  $variables['contextual_links'] = array();
  $variables['admin_links'] = '';
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
      $variables['classes_array'][] = 'contextual-links-region';
      $variables['admin_links'] = drupal_render($build);
    }
  }
}
