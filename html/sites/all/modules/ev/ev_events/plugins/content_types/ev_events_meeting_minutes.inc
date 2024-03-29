<?php

/**
 * @file
 * Meeting minutes plugin.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Meeting minutes'),
  'description' => t('Display meeting minutes from Humanitarian Events.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'ev_events_meeting_minutes_edit_form',
  'render callback' => 'ev_events_meeting_minutes_render',
  'all contexts' => TRUE,
  'defaults' => array(
    'country' => '',
    'cluster' => '',
  ),
);

/**
 * Edit form callback for the content type.
 */
function ev_events_meeting_minutes_edit_form($form, &$form_state) {
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
function ev_events_meeting_minutes_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 */
function ev_events_meeting_minutes_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Upcoming events');
  $output = t('No events to display');

  $start = new DateTime();
  $start->sub(new DateInterval('P3M'));
  $end = new DateTime();
  $path = current_path() . '/humanitarian-events';

  $api_base_url = variable_get('ev_events_api_url', 'https://events.staging.humanitarianresponse.info');

  $api_url = $api_base_url . '/api/v0/fetch-events';
  $params = array(
    'doct' => variable_get('ev_events_doc_type_meeting_minutes', 2),
    'loc' => $conf['country'],
    'clu' => $conf['cluster'],
    'start' => $start->format('Y-m-d'),
    'end' => $end->format('Y-m-d'),
  );

  $url = $api_url . '?' . drupal_http_build_query($params);
  $request = drupal_http_request($url);
  if (isset($request->data)) {
    $events = drupal_json_decode($request->data);
    $events = array_reverse(ev_events_order_by_date($events));

    $items = array();
    foreach ($events as $event) {
      $items[] = array(
        'data' => ev_events_meeting_minutes_render_event($event),
        'class' => array('ev-meeting-minutes'),
      );
    }

    $output = theme('item_list', array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array('class' => 'ev-meeting-minutes'),
    ));
  }

  $read_more = '<div class="more-link read-more">';
  $read_more .= l(t('View more'), $path, array('query' => array('view' => 'past')));
  $read_more .= '</div>';

  $block->content = $read_more . $output;

  return $block;
}

/**
 * Render one event.
 */
function ev_events_meeting_minutes_render_event($event) {
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

  $date = $date_start->format('d F Y');

  // Add files.
  $docs = array();
  foreach ($event['files'] as $file) {
    if ($file['type'] == variable_get('ev_events_doc_type_meeting_minutes', 2)) {
      $docs[] = l($file['type_human'] . ' from ' . $event['title'], $event['url'], array(
        'attributes' => array(
          'target' => '_blank',
        ),
      )) . '<br />' . $date;
    }
  }

  if (count($docs) > 0) {
    $output .= '<span class="ev-event-meeting-minutes">';
    $output .= implode(', ', $docs);
    $output .= '</span> ';
  }

  return $output;
}

/**
 * Function to return ReliefWeb Api paths.
 */
function ev_events_meeting_minutes_api_path() {
  $source_url = 'http://api.reliefweb.int/v1';
  $api_endpoints = array();
  $request = drupal_http_request($source_url);
  if (isset($request->data)) {
    $data = drupal_json_decode($request->data);
    $api = $data['data'];
    foreach ($api as $value) {
      foreach ($value as $subvalue) {
        $api_endpoints[$value['href']] = $value['title'];
      }
    }
    return $api_endpoints;
  }
  else {
    drupal_set_message("Could not return ReliefWeb API Paths. Please consult the site administrator");
  }
}

/**
 * Function to return content given an api path.
 */
function ev_events_meeting_minutes_content($path) {
  $request = drupal_http_request($path);
  if (isset($request->data)) {
    $response = drupal_json_decode($request->data);
    $data = $response['data'];
    $data_array = array();
    foreach ($data as $value) {
      $url = $value['fields']['url'];
      $title = $value['fields']['title'] ?? $value['fields']['name'];
      $data_array[$title] = array(
        'title' => $title,
        'url' => $url,
        'closing_date' => $value['fields']['date']['closing'] ?? NULL,
        'source' => $value['fields']['source'][0]['name'] ?? '',
      );
    }
    return $data_array;
  }
  else {
    drupal_set_message('Could not fetch content for the given API path, please consult your site administrator');
  }
}
