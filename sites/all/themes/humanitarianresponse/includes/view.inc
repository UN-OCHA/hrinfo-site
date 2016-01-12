<?php
/**
 * @file
 * Theme and preprocess functions for views
 */

/**
 * Implements template_preprocess().
 */
function humanitarianresponse_preprocess_views_view(&$variables) {
  $variables['feed_icons'] = drupal_get_feeds();
}

function humanitarianresponse_feed_icon($variables) {
  $text = t('Subscribe to !feed-title', array('!feed-title' => $variables['title']));
  return l('<i class="fa fa-rss-square fa-lg"></i>', $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-icon'), 'title' => $text)));
}

function humanitarianresponse_views_data_export_feed_icon($variables) {
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
function humanitarianresponse_views_pdf_icon($vars) {
  $title = $vars['title'];
  $path = $vars['path'];
  $options = $vars['options'];
  return '<li>'.l('PDF', $path, $options).'</li>';
}

/**
 * Theme function for ical icon
 */
function humanitarianresponse_date_ical_icon($variables) {
  if (empty($variables['tooltip'])) {
    $variables['tooltip'] = t('Add this event to my calendar');
  }
  return '<li>'.l('ICAL', $variables['url']).'</li>';
}

/**
 * Returns the facet path for a specific field and value
 */
function _humanitarianresponse_views_get_facet_path($real_field, $value) {
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

function _humanitarianresponse_views_more_path($type, $display, $view) {
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
        $segment = _humanitarianresponse_views_get_facet_path($view['view']->filter[$key]->real_field, $val[0]);
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
function humanitarianresponse_views_more__hr_documents_panes__list($view) {
  return _humanitarianresponse_views_more_path('documents', 'list', $view);
}

function humanitarianresponse_views_more__hr_infographics_panes__list($view) {
  return _humanitarianresponse_views_more_path('infographics', 'list', $view);
}

function humanitarianresponse_views_more__hr_news_panes__list($view) {
  return _humanitarianresponse_views_more_path('blog', 'list', $view);
}

function humanitarianresponse_views_more__hr_events_panes__upcoming($view) {
  return _humanitarianresponse_views_more_path('events', 'upcoming', $view);
}

function humanitarianresponse_views_more__hr_assessments_panes__list($view) {
  return _humanitarianresponse_views_more_path('assessments', 'list', $view);
}

/**
 * Preprocess function for Date pager template.
 * Override the pager for the printable calendar. See http://atrium.humanitarianresponse.info/humanitarian_response/node/4466
 */
function humanitarianresponse_preprocess_date_views_pager(&$vars) {
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
}

