<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('ReliefWeb API'),
  'description' => t('Display content from ReliefWeb APIs.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_reliefweb_edit_form',
  'render callback' => 'hr_layout_reliefweb_render',
  'all contexts' => TRUE,
  'defaults' => array(
    'country' => '',
    'api_path' => '',
    'api_path_advanced' => '',
    'no_of_items' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */

function hr_layout_reliefweb_edit_form($form, &$form_state){
  $options = range(1, 50);
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
  $form['api_path'] = array(
    '#type' => 'select',
    '#options' => hr_layout_reliefweb_api_path(),
    '#title' => 'Title to ReliefWeb API path',
    '#description' => t('Choose what you want to display, for instance Job to get a listing of jobs from the ReliefWeb API.'),
    '#default_value' => $conf['api_path'],
  );
  $form['api_path_advanced'] = array(
    '#type' => 'textfield',
    '#title' => 'ReliefWeb API path(Advanced Users)',
    '#description' => t('Enter the full ReliefWeb API path. Please note that this is for advanced users for cases where they might want to explore more options not provided by the settings above. For more advanced usage of the ReliefWeb API, kindly see ' .l('ReliefWeb API', 'http://reliefweb.int/help/api/advanced', array('external' => TRUE))) .'. Kindly also ensure that you DO NOT include the "limit" and "offset" parameters. For more help on this, please contact ' .l('help@humanitarianresponse.info', 'mailto:help@humanitarianresponse.info', array('absolute' => TRUE)) .'.',
    '#default_value' => $conf['api_path_advanced'],
  );
  $form['no_of_items'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#required' => TRUE,
    '#title' => 'Number of items to display',
    '#description' => t('Select the number of items you would like to display'),
    '#default_value' => $conf['no_of_items'],
  );
  return $form;
}

/**
 * Edit form submit handler.
 */

function hr_layout_reliefweb_edit_form_submit($form, &$form_state) {
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

function hr_layout_reliefweb_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = t('ReliefWeb');
  $country = $conf['country'];
  $api_path = $conf['api_path'];
  $api_path_advanced = $conf['api_path_advanced'];
  $no_of_items  = $conf['no_of_items'];

  $path = '';
  if(!empty($api_path_advanced)){
    $string = '?';
    if(strpos($api_path_advanced, $string) !== false){
      $api_path_advanced .= '&fields[include][]=url';
      $path = $api_path_advanced;
    }
    else {
      $api_path_advanced .= '?fields[include][]=url';
      $path = $api_path_advanced;
    }
  }
  else{
    //$api_path .= '?offset=0&limit=50&preset=minimal&fields[include][]=url&query[value]='.$country.'&query[fields][]=country';
    $params = array(
      'offset' => 0,
      'limit' => isset($no_of_items) ? ($no_of_items + 1) : 50,
      'preset' => 'minimal',
      'fields[include][]' => 'url',
      'query[value]' => $country,
      'query[fields][]' => 'country',
    );

    $path = $api_path . '?' . drupal_http_build_query($params);
  }

  $api_data = hr_layout_reliefweb_content($path);
  $content = '';
  if (isset($no_of_items)) {
    $result = array_slice($api_data, 0, $no_of_items + 1, true);
    $content .= '<ul>';
    foreach ($result as $key => $value) {
      $content .= '<li><a href = '.$value.'> '.$key . '</a></li>';
    }
    $content .= '</ul>';
  }
  $block->content = $content;
  return $block;
}

/**
*  Function to return ReliefWeb Api paths.
*/

function hr_layout_reliefweb_api_path() {
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

function hr_layout_reliefweb_content($path) {
  $request = drupal_http_request($path);
  if (isset($request->data)) {
    $response = drupal_json_decode($request->data);
    $data = $response['data'];
    $data_array = array();
    foreach ($data as $value) {
      $url = $value['fields']['url'];
      $title = isset($value['fields']['title']) ? $value['fields']['title'] : $value['fields']['name'];
      $data_array[$title] = $url;
    }
    return $data_array;
  }
  else{
    drupal_set_message('Could not fetch content for the given API path, please consult your site administrator');
  }
}
