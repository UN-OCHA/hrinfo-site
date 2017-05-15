<?php

/**
 * @file Menu callbacks for the Humanitarian Events.
 */

/**
 * Callback that renders the calendar.
 */
function ev_events_calendar($node) {
  // Make sure that the og single menu is not displayed.
  context_set('context', 'hr_space_menu', FALSE);

  // Check if it's a cluster.
  $is_cluster = $node->type == 'hr_bundle';

  $operation = $is_cluster ? $op = node_load(_hr_bundles_get_operation($node->nid)) : $node;
  $operation_wrapper = entity_metadata_wrapper('node', $operation);

  $country_codes = array();
  // Get the country code directly from the operation.
  if ($country_code = hr_reliefweb_get_country_from_operation($operation_wrapper)) {
    $country_codes[] = $country_code;
  }

  // Otherwise, it could be a region spread in multiple countries.
  if (empty($country_codes)) {
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'hr_operation')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition(
        'field_operation_region',
        'target_id',
        $operation_wrapper->getIdentifier()
      )
      ->execute();
    if (!empty($results['node'])) {
      $regions = node_load_multiple(array_keys($results['node']));
      foreach ($regions as $region) {
        $region_wrapper = entity_metadata_wrapper('node', $region);
        $country_codes[] = hr_reliefweb_get_country_from_operation($region_wrapper);
      }
    }
  }

  // Set active menu item, it will override current_path.
  menu_set_active_item('node/' . $node->nid . '/humanitarian-events');

  $api_base_url = variable_get('ev_events_api_url', 'https://events.staging.humanitarianresponse.info');
  $settings = array(
    'base_url' => $api_base_url,
    'header' => array(
      'left' => 'prev,next today',
      'center' => 'title',
      'right' => 'month,agendaWeek,agendaDay,listYear,upcoming,past',
    ),
    'editable' => FALSE,
    'eventLimit' => TRUE,
    'firstDay' => 1,
    'weekends' => TRUE,
    'timeFormat' => 'H:mm',
    'timezone' => drupal_get_user_timezone(),
    'views' => array(
      'month' => array(
        'buttonText' => 'Month',
      ),
      'agendaWeek' => array(
        'buttonText' => 'Week',
      ),
      'agendaDay' => array(
        'buttonText' => 'Day',
      ),
      'listYear' => array(
        'buttonText' => 'Year',
      ),
      'upcoming' => array(
        'buttonText' => 'Upcoming',
      ),
      'past' => array(
        'buttonText' => 'Past Events',
      ),
    ),
    'events' => array(
      'url' => $api_base_url . '/api/v0/fetch-events',
      'type' => 'GET',
      'data' => array(
        'hub' => '',
        'clu' => '',
        'cat' => '',
        'loc' => '',
      )
    ),
  );

  if (isset($node->field_country['und'][0]['target_id'])) {
    $term = taxonomy_term_load($node->field_country['und'][0]['target_id']);
    $settings['events']['data']['vloc'] = $term->name;
  }

  drupal_add_library('chosen', 'drupal.chosen');
  drupal_add_js(drupal_get_path('module', 'ev_events') . '/js/ev_events_calendar.js');

  return theme('fullcalendar_calendar', array(
    'calendar_id' => 'fullcalendar',
    'calendar_settings' => $settings,
  ));
}
