<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Rss Feeds'),
  'description' => t('Display RSS Feeds in Humanitarianresponse'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_rss_feeds_edit_form',
  'render callback' => 'hr_layout_rss_feeds_render',
  'all contexts' => TRUE,
  'defaults' => array(
    'feed_url' => '',
    'no_of_items' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */

function hr_layout_rss_feeds_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $options = range(1, 50);

  $form['feed_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Feed URL',
    '#description' => t('Enter the Feed URL for which you want to display content'),
    '#default_value' => $conf['feed_url'],
  );
  $form['no_of_items'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => $options,
    '#title' => 'Number of items to display',
    '#description' => t('Select the number of feed items you would like to display'),
    '#default_value' => $conf['no_of_items'],
  );

  return $form;
}

/**
 * Edit form submit handler.
 */

function hr_layout_rss_feeds_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */

function hr_layout_rss_feeds_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $block->title = 'RSS Feeds';
  $feed_url = $conf['feed_url'];
  $no_of_items = $conf['no_of_items'];
  $feeds = hr_layout_rss_feeds_load($feed_url);
  $content = '';
  if(isset($no_of_items)){
    $items_to_display = array_slice($feeds, 0, intval($no_of_items + 1), true);
    $content .= '<ul>';
    foreach ($items_to_display as $key => $value) {
      $content .= '<li><a href = ' .$value. '> ' .$key. '</a></li>';
    }
    $content .= '</ul>';
  }
  $block->content = $content;
  return $block;
}

/**
*  This function returns an array containing the feed titles and urls.
*  @return array().
*/
function hr_layout_rss_feeds_load($url){
  if(module_exists('feeds')){
    feeds_include_simplepie();

    $feed = new SimplePie();
    $feed->set_feed_url($url);
    $feed->set_cache_location(cacheDirectory());
    $feed->set_cache_duration(24*60*60);
    $feed->init();
    $feed->handle_content_type();
    $feeds = array();
    foreach ($feed->get_items() as $item) {
      $title = $item->get_title();
      $link = $item->get_link();
      $feeds[$title] = $link;
    }

    return $feeds;
  }
  else{
    drupal_set_message("could not load the Feeds module, please consult the site administrator");
  }
}

/**
 * Returns cache directory. Creates it if it doesn't exist.
 */

function cacheDirectory() {
  $directory = 'public://simplepie';
  file_prepare_directory($dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
  return $directory;
}