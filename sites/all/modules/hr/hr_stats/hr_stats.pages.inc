<?php

/**
 * Return the form where to select the report period.
 */

function hr_stats_dateselect_form() {

  $period = array(
    0 => t('Today'),
    1 => t('Yesterday'),
    2 => t('Last week'),
    3 => t('Last month'),
    4 => t('Last year'),
  );

  $form['#attributes'] = array('class' => array('search-form'));
  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select time period'),
  );
  $form['basic']['inline'] = array(
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );
  $form['basic']['inline']['period'] = array(
    '#type' => 'select',
    '#title' => '',
    '#default_value' => isset($_SESSION['hr_stats_reports_period']) ? $_SESSION['hr_stats_reports_period'] : 0,
    '#options' => $period,
  );
  $form['basic']['inline']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
    '#weight' => 15,
  );
  return $form;
}

/**
 * Reports form submit function
 */
 
function hr_stats_reports_submit($form, &$form_state) {
  $_SESSION['hr_stats_reports_period'] = $form_state['values']['period'];
}

/**
 * Return the $form that handles piwik reports
 *
 * @param $form
 * @param $form_state
 *   see form api.
 * @param $report
 *   The report name.
 *
 * @return
 */

function hr_stats_reports($form, &$form_state, $report){
	
  $piwik_url = variable_get('piwik_url_https', '');
  if(!isset($piwik_url)){
    drupal_set_message('Please check your piwik http URL in the configuration settings', 'warning', false);

    return;
  }
  $form = hr_stats_dateselect_form();
  $piwik_site_id = variable_get('piwik_site_id', '');
  if(!isset($piwik_site_id)){
    drupal_set_message('Please check your piwik site Id in the configuration settings', 'warning', false);

    return;
  }
  $period = isset($_SESSION['hr_stats_reports_period']) ? $_SESSION['hr_stats_reports_period'] : 0;
  if($period == 1){
    // Special handling for "yesterday" = 1.
    // The yesterday date value is required.
    $date = _hr_stats_select_period($period);
  }
  else {
    // Otherwise it returns the today date value.
    $date = _hr_stats_select_period(0);
  }
  $period_name = _hr_stats_get_period_name($period);
	$token_auth = variable_get('hr_stats_piwik_token_auth', '');
	$segment = variable_get('hr_stats_piwik_segment');
  if(!isset($segment)){
    drupal_set_message('You have to specify the segment(In this case the operation) to fetch piwik reports for. This can be done in the group admin page', 'warning', false);

    return;
  }
	
  //array of URL parameters
  $data_params = array();
  $data_params[0]['idSite'] = $piwik_site_id;
  $data_params[0]['date'] = $date;
  $data_params[0]['period'] = $period_name;
  $data_params[0]['segment'] = $segment;
  $data_params[0]['disableLink'] = 1;
  $data_params[0]['module'] = 'Widgetize';
  $data_params[0]['action'] = 'iframe';
  $data_params[0]['disableLink'] = 1;
  $data_params[0]['widget'] = 1;
  if (!empty($token_auth)) {
    $data_params[0]['token_auth'] = $token_auth;
  }
  switch($report){
    case 'visitors_overview':
      $title[0] = t('Visits trend');
      $data_params[0]['columns[]'] = 'nb_visits';
      $data_params[0]['moduleToWidgetize'] = 'VisitsSummary';
      $data_params[0]['actionToWidgetize'] = 'getSparklines';
    break;
    case 'visitors_settings':
      $data_params[0]['filter_limit'] = 6;
      // Browser families
      $title[0] = t('Browser families');
      $data_params[0]['moduleToWidgetize'] = 'UserSettings';
      $data_params[0]['actionToWidgetize'] = 'getBrowserType';
    break;
		case 'visitors_overview_map':
			$title[0] = t('Browser Map');
			$data_params[0]['moduleToWidgetize'] = 'UserCountryMap';
			$data_params[0]['actionToWidgetize'] = 'visitorMap';
		break;
		}
    // Build the data URL with all params and urlencode it.
		$theme_args = array();
    foreach ($data_params as $key => $data) {
      $theme_args['data_url'][] = array('url' => $piwik_url . 'index.php?' . drupal_http_build_query($data), 
      'title' => $title[$key], 
      'iframe_height' => ( isset($iframe_height[$key]) && $iframe_height[$key] > 0 ? $iframe_height[$key] : 350),
      'empty_text' => ( isset($empty_text) ? $empty_text : NULL),
      );
    }
    // Render HTML code.
    $output = theme('piwik_reports', $theme_args);
    $form['content'] = array(
      '#type' => 'item',
      '#markup' => $output,
    );
    return $form;
}

/**
 * Helper function that return the starting and ending dates according to the
 * selected period.
 *
 * @param $period
 *    selected period
 * @return
 *    array with starting and ending date
 */
function _hr_stats_select_period($period) {
  switch ($period) {
    case 0:
      $date = date("Y-m-d");
      break;

    case 1:
      $d = mktime(0, 0, 0, date("m"), date("d") - 1, date("Y"));
      $date = date("Y-m-d", $d);
      break;

    case 2:
      $d = mktime(0, 0, 0, date("m"), date("d") - 7, date("Y"));
      $date = date("Y-m-d", $d);
      break;

    case 3:
      $d = mktime(0, 0, 0, date("m") - 1, date("d"), date("Y"));
      $date = date("Y-m-d", $d);
      break;

    case 4:
      $d = mktime(0, 0, 0, date("m"), date("d"), date("Y") - 1);
      $date = date("Y-m-d", $d);
      break;
  }
  return $date;
}

/**
 * Helper function that return the name of the selected period.
 *
 * @param $period
 *    selected period
 * @return
 *    name
 */
function _hr_stats_get_period_name($period) {
  // Possible periods are day, week, month, year.
  switch ($period) {
    case 0:
      $p = "day";
      break;

    case 1:
      $p = "day";
      break;

    case 2:
      $p = "week";
      break;

    case 3:
      $p = "month";
      break;

    case 4:
      $p = "year";
      break;
  }
  return $p;
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
  drupal_add_http_header('Content-Disposition', 'attachment;filename="'.$filename.'"');
  hr_stats_get_full_stats($form_state['values']['period'], $date['year'].'-'.sprintf("%02d",$date['month']).'-'.sprintf("%02d", $date['day']));
  drupal_exit();
}

