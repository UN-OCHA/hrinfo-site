<?php

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
  ),
);

/**
 * 'Edit form' callback for the content type.
 */

function ev_events_upcoming_edit_form($form, &$form_state){
  $countries_list = country_get_list();
  $countries = array();
  foreach ($countries_list as $key => $value) {
    $countries[$value] = $value;
  }
  $conf = $form_state['conf'];

  $form['country'] = array(
    '#type' => 'select',
    '#options' => $countries,
    '#title' => 'Country',
    '#description' => t('Choose the country you want to get content for.'),
    '#default_value' => $conf['country'],
  );

  return $form;
}

/**
 * Edit form submit handler.
 */

function ev_events_upcoming_edit_form_submit($form, &$form_state) {
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

function ev_events_upcoming_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = t('Upcoming events');

  $api_base_url = variable_get('ev_events_api_url', 'https://events.staging.humanitarianresponse.info');
  $country = $conf['country'];

  $api_base_url = variable_get('ev_events_api_url', 'https://events.staging.humanitarianresponse.info');
  $settings = array(
    'base_url' => $api_base_url,
    'header' => array(
      'left' => '',
      'center' => 'title',
      'right' => '',
    ),
    'editable' => FALSE,
    'eventLimit' => TRUE,
    'firstDay' => 1,
    'weekends' => TRUE,
    'timeFormat' => 'H:mm',
    'timezone' => drupal_get_user_timezone(),
    'defaultView' => 'upcoming',
    'views' => array(
      'upcoming' => array(),
    ),
    'events' => array(
      'url' => $api_base_url . '/api/v0/fetch-events',
      'type' => 'GET',
      'data' => array(
        'vloc' => $country,
      )
    ),
  );

  drupal_add_library('chosen', 'drupal.chosen');
  drupal_add_js(drupal_get_path('module', 'ev_events') . '/js/ev_events_calendar.js');

  $block->content = theme('fullcalendar_calendar', array(
    'calendar_id' => 'fullcalendar',
    'calendar_settings' => $settings,
  ));

  return $block;
}

/**
*  Function to return ReliefWeb Api paths.
*/

function ev_events_upcoming_api_path() {
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
  else{
    drupal_set_message("Could not return ReliefWeb API Paths. Please consult the site administrator");
  }
}

/**
*  Function to return content given an api path.
*/

function ev_events_upcoming_content($path) {
  $request = drupal_http_request($path);
  if (isset($request->data)) {
    $response = drupal_json_decode($request->data);
    $data = $response['data'];
    $data_array = array();
    foreach ($data as $value) {
      $url = $value['fields']['url'];
      $title = isset($value['fields']['title']) ? $value['fields']['title'] : $value['fields']['name'];
      $data_array[$title] = array(
        'title' => $title,
        'url' => $url,
        'closing_date' => isset($value['fields']['date']['closing']) ? $value['fields']['date']['closing'] : NULL,
        'source' => isset($value['fields']['source'][0]['name']) ? $value['fields']['source'][0]['name'] : '',
      );
    }
    return $data_array;
  }
  else{
    drupal_set_message('Could not fetch content for the given API path, please consult your site administrator');
  }
}
