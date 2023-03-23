<?php

/**
 * @file
 * Callbacks for FullCalendar API Examples feeds.
 */

/**
 * Ajax deliver callback for /fullcalendar/json-data.
 */
function full_calendar_api_example_data_provider() {
  $events = array(
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
    ),
  );
  echo drupal_json_encode($events);
  drupal_exit();
}
