<?php
/**
 * @file
 * Pages file for hr_stats module.
 */

/**
 * Return the $form that handles piwik reports.
 */
function hr_stats_reports($form, &$form_state, $entity_type, $entity_id, $report) {
  $form = array();
  $piwik_url = variable_get('piwik_url_https', '');
  if (!isset($piwik_url)) {
    drupal_set_message(t('Please check your piwik http URL in the configuration settings'), 'warning', FALSE);
    return array();
  }
  $piwik_site_id = variable_get('piwik_site_id', '');
  if (!isset($piwik_site_id)) {
    drupal_set_message(t('Please check your piwik site Id in the configuration settings'), 'warning', FALSE);
    return array();
  }
  if (!is_numeric($entity_id)) {
    return array();
  }

  $wrapper = entity_metadata_wrapper($entity_type, $entity_id);

  $range = isset($_SESSION['hr_stats_reports_range']) ? $_SESSION['hr_stats_reports_range'] : date('Y-m-d');
  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select time period'),
    '#attributes' => array(
      'class' => array(
        'container-inline',
      ),
    ),
  );
  $form['basic']['range'] = array(
    '#type' => 'daterangepicker',
    '#required' => TRUE,
    '#default_value' => $range,
  );
  $form['basic']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
    '#weight' => 15,
  );

  $token_auth = variable_get('hr_stats_piwik_token_auth', '');

  // We need to identify if we're in a section or a cluster to establish the
  // right segment.
  $segment_vars = array(
    'hr_operation' => array(
      'name' => 'customVariablePageName1',
      'value' => 'customVariablePageValue1',
      'context' => 'spaces',
      'widget' => 'getSpaceSummary',
      'key' => 'space',
    ),
    'hr_bundle' => array(
      'name' => 'customVariablePageName2',
      'value' => 'customVariablePageValue2',
      'context' => 'bundles',
      'widget' => 'getClusterSummary',
      'key' => 'cluster',
    ),
  );
  // Default to operation in case of unexpected node types.
  $segment_var = isset($segment_vars[$entity_type]) ? $segment_vars[$entity_type] : $segment_vars['hr_operation'];

  $period = 'day';
  $date_range = $range;
  if (is_array($range)) {
    $date_range = $range['start'];
    if (!empty($range['end']) && ($range['end'] <> $range['start'])) {
      $date_range .= ',' . $range['end'];
      $period = 'range';
    }
  }

  // Default height for the iframe.
  $iframe_height = 500;
  // Array of URL parameters.
  $data_params = array();
  $data_params[0]['idSite'] = $piwik_site_id;
  $data_params[0]['date'] = $date_range;
  $data_params[0]['period'] = $period;
  $data_params[0]['segment'] = $segment_var['name'] . '==' . $segment_var['context'] . ';' . $segment_var['value'] . '=@' . $wrapper->getIdentifier();
  $data_params[0]['disableLink'] = 1;
  $data_params[0]['module'] = 'Widgetize';
  $data_params[0]['action'] = 'iframe';
  $data_params[0]['disableLink'] = 1;
  $data_params[0]['widget'] = 1;
  if (!empty($token_auth)) {
    $data_params[0]['token_auth'] = $token_auth;
  }
  switch ($report) {
    case 'visitors_overview':
      $title[0] = t('Visits trend');
      $data_params[0]['columns[]'] = 'nb_visits';
      $data_params[0]['moduleToWidgetize'] = 'VisitsSummary';
      $data_params[0]['actionToWidgetize'] = 'getSparklines';
      break;
    case 'visitors_overview_content':
      $title[0] = t('Pages visited');
      $data_params[0]['moduleToWidgetize'] = 'Actions';
      $data_params[0]['actionToWidgetize'] = 'menuGetPageUrls';
      $data_params[0]['iframe_height'] = 750;
      break;
    case 'visitors_overview_downloads':
      $title[0] = t('Total downloads');
      $data_params[0]['moduleToWidgetize'] = 'HumanitarianResponse';
      $data_params[0]['actionToWidgetize'] = $segment_var['widget'];
      $data_params[0][$segment_var['key'] . '_id'] = $wrapper->getIdentifier();
      $data_params[0][$segment_var['key'] . '_type'] = $data_params[1][$segment_var['key']];
      $data_params[0]['iframe_height'] = 250;
      $data_params[1] = $data_params[0];
      $title[1] = t('Files downloaded');
      $data_params[1]['moduleToWidgetize'] = 'Actions';
      $data_params[1]['actionToWidgetize'] = 'menuGetDownloads';
      $data_params[1]['iframe_height'] = 750;
      break;
    case 'visitors_settings':
      $data_params[0]['filter_limit'] = 6;
      $title[0] = t('Browser families');
      $data_params[0]['moduleToWidgetize'] = 'DevicesDetection';
      $data_params[0]['actionToWidgetize'] = 'getBrowsers';
      break;
    case 'visitors_overview_map':
      $title[0] = t('Visitor Map');
      $data_params[0]['moduleToWidgetize'] = 'UserCountryMap';
      $data_params[0]['actionToWidgetize'] = 'visitorMap';
      $data_params[0]['iframe_height'] = 850;
      break;
  }


  // Build the data URL with all params and urlencode it.
  $theme_args = array();
  foreach ($data_params as $key => $data) {
    $theme_args['data_url'][] = array(
      'url' => $piwik_url . 'index.php?' . drupal_http_build_query($data),
      'title' => $title[$key],
      'iframe_height' => !empty($data['iframe_height']) ? $data['iframe_height'] : $iframe_height,
      'empty_text' => (isset($empty_text) ? $empty_text : NULL),
    );
  }

  $form['content'] = array(
    '#type' => 'item',
    '#markup' => theme('piwik_reports', $theme_args),
  );
  return $form;
}

/**
 * Reports form submit handler.
 */
function hr_stats_reports_submit($form, &$form_state) {
  $_SESSION['hr_stats_reports_range'] = drupal_json_decode($form_state['values']['range']);
}

function hr_stats_admin_reports_form($form, &$form_state) {
  $form['period'] = array(
    '#type' => 'select',
    '#title' => t('Period'),
    '#options' => array(
      'day' => t('Day'),
      'week' => t('Week'),
      'month' => t('Month'),
      'year' => t('Year'),
    ),
  );

  $form['date'] = array(
    '#type' => 'date',
    '#title' => t('Date'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function hr_stats_admin_reports_form_submit($form, &$form_state) {
  drupal_set_time_limit(0);
  $filename = 'hr_stats.csv';
  $date = $form_state['values']['date'];
  drupal_add_http_header('Content-Type', 'text/csv;charset=utf-8');
  drupal_add_http_header(
    'Content-Disposition',
    'attachment;filename="' . $filename . '"'
  );
  hr_stats_get_full_stats(
    $form_state['values']['period'],
    $date['year'] . '-' . sprintf("%02d", $date['month']) . '-' . sprintf(
      "%02d",
      $date['day']
    )
  );
  drupal_exit();
}

