<?php

/**
 * @file
 * Page callbacks for FullCalendar API Examples module.
 */

/**
 * Page callback for /fullcalendar/calendar.
 */
function fullcalendar_api_example_calendar_page() {

  // Array of FullCalendar settings.
  $settings = array(
      'header' => array(
        'left' => 'prev,next today',
        'center' => 'title',
        'right' => 'month,agendaWeek,agendaDay',
      ),
      'defaultDate' => '2015-02-12',
      'editable' => TRUE,
      'eventLimit' => TRUE, // allow "more" link when too many events
      'events' => array(
        array(
          'title' => 'All Day Event',
          'start' => '2015-02-01',
        ),
        array(
          'title' => 'Long Event',
          'start' => '2015-02-07',
          'end' => '2015-02-10',
        ),
        array(
          'id' => 999,
          'title' => 'Repeating Event',
          'start' => '2015-02-09T16:00:00',
        ),
        array(
          'id' => 999,
          'title' => 'Repeating Event',
          'start' => '2015-02-16T16:00:00',
        ),
        array(
          'title' => 'Conference',
          'start' => '2015-02-11',
          'end' => '2015-02-13',
        ),
        array(
          'title' => 'Meeting',
          'start' => '2015-02-12T10:30:00',
          'end' => '2015-02-12T12:30:00',
        ),
        array(
          'title' => 'Lunch',
          'start' => '2015-02-12T12:00:00',
        ),
        array(
          'title' => 'Meeting',
          'start' => '2015-02-12T14:30:00',
        ),
        array(
          'title' => 'Happy Hour',
          'start' => '2015-02-12T17:30:00',
        ),
        array(
          'title' => 'Dinner',
          'start' => '2015-02-12T20:00:00',
        ),
        array(
          'title' => 'Birthday Party',
          'start' => '2015-02-13T07:00:00',
        ),
        array(
          'title' => 'Click for Google',
          'url' => 'http://google.com/',
          'start' => '2015-02-28',
        )
      )
    );

  return theme('fullcalendar_calendar', array(
    'calendar_id' => 'fullcalendar',
    'calendar_settings' => $settings,
  ));
}

/**
 * Page callback for /fullcalendar/datasource.
 */
function fullcalendar_api_example_datasource_page() {
  // Array of FullCalendar settings.
  $settings = array(
    'header' => array(
      'left' => 'prev,next today',
      'center' => 'title',
      'right' => 'month,agendaWeek,agendaDay',
    ),
    'defaultDate' => '2015-02-12',
    'editable' => TRUE,
  );
  // @see fullcalendar_api_example.ajax.inc.
  $datasource_uri = 'fullcalendar/json-data';
  return theme('fullcalendar_calendar_datasource', array(
    'calendar_id' => 'fullcalendar',
    'calendar_settings' => $settings,
    'datasource_uri' => $datasource_uri,
  ));
}

/**
 * Page callback for /fullcalendar/entity.
 */
function fullcalendar_api_example_entity_page() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article');
  $result = $query->execute();
  if (isset($result['node'])) {
    $entity_ids = array_keys($result['node']);
    $entities = entity_load('node', $entity_ids);

    // Array of custom calendar settings. These override the defaults set 
    // in the theme function.
    $custom_settings = array(
      'header' => array(
        'left' => 'month,agendaWeek',
        'right' => 'prev title next',
      ),
      'weekends' => TRUE,
      'firstDay' => 1,
      'defaultDate' => date('Y-m-d'),
    );

    return theme('fullcalendar_calendar_entity', array(
      'entities' => $entities,
      'date_field_map' => array('article' => 'field_date'),
      'calendar_id' => 'fullcalendar-entity',
      'calendar_settings' => $custom_settings,
    ));
  }
  return array(
    '#markup' => '<p>Calendar not available.</p>' .
      '<ol><li>Add a required field called <em>field_date</em> to the Article content type.</li>' . 
      '<li>Add some content.</li>' .
      '<li>Visit this page again.</li>',
  );
}

/**
 * Page callback for /fullcalendar/callbacks.
 */
function fullcalendar_api_example_callbacks_page() {
  $build = array();

  // Array of FullCalendar settings.
  $settings = array(
    'header' => array(
      'left' => 'prev,next today',
      'center' => 'title',
      'right' => 'month,agendaWeek,agendaDay',
    ),
    'defaultDate' => '2015-02-12',
    'editable' => TRUE,
    'eventLimit' => TRUE, // allow "more" link when too many events
    'events' => array(
      array(
        'title' => 'All Day Event',
        'start' => '2015-02-01',
      ),
      array(
        'title' => 'Long Event',
        'start' => '2015-02-07',
        'end' => '2015-02-10',
      ),
      array(
        'title' => 'Conference',
        'start' => '2015-02-11',
        'end' => '2015-02-13',
      ),
    )
  );
  // Here we add our custom javascript file which will implement FullCalendar's callbacks.
  drupal_add_js(drupal_get_path('module', 'fullcalendar_api_example') . '/fullcalendar-example-custom-callbacks.js');
  $build['calendar'] = theme('fullcalendar_calendar', array(
    'calendar_id' => 'fullcalendar',
    'calendar_settings' => $settings,
  ));
  return $build;
}