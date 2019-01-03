<?php
/**
 * @file
 * Theme and preprocess functions for views
 */

/**
 * Implements template_preprocess().
 */
function ocha_basic_preprocess_views_view(&$variables) {
  $variables['feed_icons'] = drupal_get_feeds();
}

function ocha_basic_feed_icon($variables) {
  $text = t('Subscribe to !feed-title', array('!feed-title' => $variables['title']));
  return l('<i class="fa fa-rss-square fa-lg"></i>', $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-icon'), 'title' => $text)));
}

function ocha_basic_views_data_export_feed_icon($variables) {
  extract($variables, EXTR_SKIP);
  $url_options = array('html' => TRUE);
  if ($query) {
    $url_options['query'] = $query;
  }
  $image = theme('image', array('path' => $image_path, 'alt' => $text, 'title' => $text));
  return '<li>'.l($text, $url, $url_options).'</li>';
}

/**
 * Theme function for the PDF icon of appended PDFs.
 */
function ocha_basic_views_pdf_icon($vars) {
  $title = $vars['title'];
  $path = $vars['path'];
  $options = $vars['options'];
  return '<li>'.l('PDF', $path, $options).'</li>';
}

/**
 * Theme function for ical icon
 */
function ocha_basic_date_ical_icon($variables) {
  if (empty($variables['tooltip'])) {
    $variables['tooltip'] = t('Add this event to my calendar');
  }
  return '<li>'.l('ICAL', $variables['url']).'</li>';
}

/**
 * Returns the facet path for a specific field and value
 */
function _ocha_basic_views_get_facet_path($real_field, $value) {
  $adapter = facetapi_adapter_load('search_api@default_node_index');
  $field_name = str_replace('_target_id', '', $real_field);
  $args = array();
  $args['adapter'] = $adapter;
  if ($args['facet'] = facetapi_facet_load($field_name, 'search_api@default_node_index')) {
    $segment = array();
    $segment['value'] = $value;
    $facet_settings = $adapter->getFacetSettingsGlobal($args['facet']);
    $segment['alias'] = $facet_settings->settings['pretty_paths_alias'];
    $args['segment'] = &$segment;
    facetapi_pretty_paths_coder_callback('encodePathSegment', $args);
    if (!empty($args['segment']['value'])) {
      return $args['segment']['alias'].'/'.$args['segment']['value'];
    }
  }

  return FALSE;
}

function _ocha_basic_views_more_path($type, $display, $view) {
  $path = $type;
  $filter_keys = array_keys($view['view']->display[$display]->display_options['filters']);
  foreach ($filter_keys as $key) {
    $val = $view['view']->filter[$key]->{'value'};
    if (!empty($val) && isset($val[0])) {
      if ($key == 'og_group_ref_target_id' || $key == 'field_bundles_target_id_entityreference_filter') {
        $path = 'node/'.$val[0].'/'.$type;
        if ($type == 'events') {
          $path .= '/list';
        }
      }
      elseif ($key != 'type' && $key != 'status' && $key != 'date_filter') {
        $segment = _ocha_basic_views_get_facet_path($view['view']->filter[$key]->real_field, $val[0]);
        if (!empty($segment)) {
          $path .= '/'.$segment;
        }
      }
    }
  }
  return '<div class="more-link">'.l(t('view more'), $path).'</div>';
}

/**
 * More links
 */
function ocha_basic_views_more__hr_documents_panes__list($view) {
  return _ocha_basic_views_more_path('documents', 'list', $view);
}

function ocha_basic_views_more__hr_infographics_panes__list($view) {
  return _ocha_basic_views_more_path('infographics', 'list', $view);
}

function ocha_basic_views_more__hr_news_panes__list($view) {
  return _ocha_basic_views_more_path('blog', 'list', $view);
}

function ocha_basic_views_more__hr_events_panes__upcoming($view) {
  return _ocha_basic_views_more_path('events', 'upcoming', $view);
}

function ocha_basic_views_more__hr_assessments_panes__list($view) {
  return _ocha_basic_views_more_path('assessments', 'list', $view);
}

/**
 * Preprocess function for Date pager template.
 * Override the pager for the printable calendar. See http://atrium.ocha_basic.info/humanitarian_response/node/4466
 */
function ocha_basic_preprocess_date_views_pager(&$vars) {
  global $language;
  $view = $vars['plugin']->view;
  if ($view->name == 'hr_events_calendar') {
    if ($view->current_display == 'print_week') {
      $date_info = $view->date_info;
      $format = 'F d, Y';
      if ($language->language != 'en') {
        $format = 'd F Y';
      }
      $title = t('@mindate to @maxdate', array('@mindate' => date_format_date($date_info->min_date, 'custom', $format), '@maxdate' => date_format_date($date_info->max_date, 'custom', $format)));
      $vars['nav_title'] = $title;
      $vars['prev_url'] = '';
      $vars['next_url'] = '';
    }
    elseif ($view->current_display == 'print_day') {
      $date_info = $view->date_info;
      $format = 'l d / F Y';
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $vars['nav_title'] = $title;
      $vars['prev_url'] = '';
      $vars['next_url'] = '';
    }
  }

  // Render pagers controls as buttons.
  $vars['prev_options']['attributes']['class'][] = 'btn';
  $vars['prev_options']['attributes']['class'][] = 'btn-default';
  $vars['next_options']['attributes']['class'][] = 'btn';
  $vars['next_options']['attributes']['class'][] = 'btn-default';
}

/**
 * Implements template_preprocess_views_view_table().
 */
function ocha_basic_preprocess_views_view_table(&$variables) {
  // Add Bootstrap table classes.
  $variables['classes_array'] = array_merge($variables['classes_array'], array(
    'table',
    'table-striped',
    'table-bordered',
  ));
}

/**
 * Implements theme_views_mini_pager().
 */
function ocha_basic_views_mini_pager($vars) {
  global $pager_page_array, $pager_total;

  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];

  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  if ($pager_total[$element] > 1) {

    $li_previous = theme('pager_previous', array(
      'text' => (isset($tags[1]) ? $tags[1] : t('‹‹')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters,
    ));
    if (empty($li_previous)) {
      $li_previous = "&nbsp;";
    }

    $li_next = theme('pager_next', array(
      'text' => (isset($tags[3]) ? $tags[3] : t('››')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters,
    ));

    if (empty($li_next)) {
      $li_next = "&nbsp;";
    }

    $items[] = array(
      'class' => array('pager-previous'),
      'data' => $li_previous,
    );

    $items[] = array(
      'class' => array('pager-current'),
      'data' => '<span>' . t('@current of @max', array('@current' => $pager_current, '@max' => $pager_max)) . '</span>',
    );

    $items[] = array(
      'class' => array('pager-next'),
      'data' => $li_next,
    );
    return theme('item_list', array(
      'items' => $items,
      'title' => NULL,
      'type' => 'ul',
      'attributes' => array('class' => array('pagination')),
    ));
  }
}
