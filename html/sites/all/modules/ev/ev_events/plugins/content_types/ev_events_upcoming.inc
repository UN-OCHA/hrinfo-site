<?php

/**
 * @file
 * Upcoming events plugin.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Upcoming events'),
  'description' => t('Display upcoming events from Humanitarian Events.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'ev_events_upcoming_edit_form',
  'render callback' => 'ev_events_upcoming_render',
  'all contexts' => TRUE,
  'defaults' => array(
    'country' => '',
    'cluster' => '',
  ),
);

/**
 * Edit form callback for the content type.
 */
function ev_events_upcoming_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['country'] = array(
    '#type' => 'select',
    '#options' => ev_events_fetch_countries(),
    '#title' => 'Country',
    '#description' => t('Choose the country you want to get content for.'),
    '#default_value' => $conf['country'],
  );

  $form['cluster'] = array(
    '#type' => 'select',
    '#options' => ev_events_fetch_clusters(),
    '#title' => 'Cluster',
    '#empty_option' => '- Select a cluster -',
    '#description' => t('Choose the cluster you want to get content for.'),
    '#default_value' => $conf['cluster'],
  );

  return $form;
}

/**
 * Edit form submit handler.
 */
function ev_events_upcoming_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 */
function ev_events_upcoming_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Upcoming events');
  $output = t('No events to display');

  $now = new DateTime();
  $now->add(new DateInterval('P1D'));
  $path = current_path() . '/humanitarian-events';

  $api_base_url = variable_get('ev_events_api_url', 'https://events.staging.humanitarianresponse.info');

  $api_url = $api_base_url . '/api/v0/fetch-events';
  $params = array(
    'loc' => $conf['country'],
    'clu' => $conf['cluster'],
    'start' => $now->format('Y-m-d'),
  );

  $url = $api_url . '?' . drupal_http_build_query($params);
  $request = drupal_http_request($url);
  if (isset($request->data)) {
    $events = drupal_json_decode($request->data);
    $events = ev_events_order_by_date($events);

    // Since recurring events can have a date in the past, remove them.
    foreach ($events as $key => $event) {
      if ($event['start'] < $now->format('Y-m-d')) {
        unset($events[$key]);
      }
    }

    // Limit to 5 events.
    array_splice($events, 5);

    $items = array();
    foreach ($events as $event) {
      $items[] = array(
        'data' => ev_events_upcoming_render_event($event),
        'class' => array('ev-event'),
      );
    }

    $output = theme('item_list', array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array('class' => 'ev-upcoming-events'),
    ));
  }

  $read_more = '<div class="more-link read-more">';
  $read_more .= l(t('View more'), $path);
  $read_more .= '</div>';

  $block->content = $read_more . $output;

  return $block;
}

/**
 * Render one event.
 */
function ev_events_upcoming_render_event($event) {
  $timezone = drupal_get_user_timezone();

  $output = '';
  $date_start = new DateTime($event['start']);
  $date_end = new DateTime($event['end']);
  $all_day = $event['allDay'];

  $date_start_date = $date_start->format('d F Y');
  $date_end_date = $date_end->format('d F Y');

  $multiday = FALSE;
  if ($date_start_date != $date_end_date) {
    $multiday = TRUE;
  }

  if ($all_day) {
    if ($multiday) {
      $date = $date_start->format('d F Y') . ' - ' . $date_end->format('d F Y') . ' (' . t('All day') . ')';
    }
    else {
      $date = $date_start->format('d F Y') . ' (' . t('All day') . ')';
    }
  }
  else {
    if ($multiday) {
      $date = $date_start->format('d F Y H:i') . ' - ' . $date_end->format('d F Y H:i');
    }
    else {
      $date = $date_start->format('d F Y H:i') . ' - ' . $date_end->format('H:i');
    }
  }

  $output .= '<span class="ev-event-title">' . l($event['title'], $event['url'], array(
    'attributes' => array(
      'target' => '_blank',
    )
)) . '</span><br>';
  $output .= '<span class="ev-event-date">' . $date . '</span> ';

  return $output;
}
