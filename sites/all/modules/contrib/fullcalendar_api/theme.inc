<?php
/**
 * Theme implementations and template preprocess functions for 
 * FullCalendar API module.
 */

/**
 * Theme function for fullcalendar_calendar.
 *
 * @params
 *   events array of event objects
 *   date_field string field name of valid date field
 *   calendar_id string the CSS id of the calendar DOM object
 *   calendar_settings array of settings to override FullCalendar.js defaults
 */
function theme_fullcalendar_calendar($vars) {
  $calendar_id = $vars['calendar_id'];
  $user_settings = $vars['calendar_settings'];

  // Default settings.
  $settings = array(  
    'header' => array(
      'left' => 'month,agendaWeek',
      'right' => 'prev title next',
    ),
    'defaultDate' => date('Y-m-d'),
    'businessHours' => TRUE,
    'editable' => TRUE,
    'events' => array(),
  );

  // Override defaults with user submitted data.
  $settings = array_replace_recursive($settings, $user_settings);

  // Add FullCalendar scripts.
  fullcalendar_api_load_calendar($calendar_id, $settings);

  return array(
    '#markup' => '<div id="' . check_plain($calendar_id) . '"></div>',
  );
}


/**
 * Theme function for fullcalendar_calendar_entity.
 * Renders an array of entities with date fields as calendar items.
 *
 * @params
 *   entities array of event objects
 *   date_field string field name of valid date field
 *   calendar_id string the CSS id of the calendar DOM object
 *   calendar_settings array of settings to override FullCalendar.js defaults
 */
function theme_fullcalendar_calendar_entity($vars) {
  $entities = $vars['entities'];
  $date_field_map = $vars['date_field_map'];
  $calendar_id = $vars['calendar_id'];
  $settings = $vars['calendar_settings'];

  if (!array($date_field_map)) {
    throw new Exception(t('Invalid parameter: Date field must be an array.'));
  }

  foreach ($date_field_map as $date_field) {
    // Check if field is valid date type.
    $date_field_info = field_info_field($date_field);
    if (
      !$date_field_info ||
      !in_array($date_field_info['type'], array('date', 'datetime', 'datestamp', 'ep_datetime'))
    ) {
      throw new Exception(t('Field name %field_name is not a valid date field.', array('%field_name' => $date_field)));
    }
  }

  // Get entity_type -> bundle mappings so we can have mixed entity types 
  // in our calendar events.
  $entity_info = entity_get_info();
  $entity_bundle_types = array();
  foreach ($entity_info as $entity_type => $data) {
    foreach (array_keys($data['bundles']) as $bundle) {
      $entity_bundle_types[$bundle] = $entity_type;
    }
  }

  foreach ($entities as $entity) {
    // If "bundle" is not defined, use "type".
    if (!isset($entity->bundle)) {
      $entity->bundle = $entity->type;
    }
    $entity_type = $entity_bundle_types[$entity->bundle];
    $date_field = $date_field_map[$entity->bundle];

    $start = NULL;
    $end = NULL;
    // If the date type is not "datestamp" (timestamp), pass the string to 
    // DateTime constructor. It will automatically detect the date format and 
    // give us a timestamp.
    $date_field_value = $entity->{$date_field}[LANGUAGE_NONE][0];
    $date_type = $date_field_value['date_type'];
    switch ($date_type) {
      case 'date':
      case 'datetime':
      case 'ep_datetime':
        // @todo timezone?
        $dateTime = new DateTime($date_field_value['value']);
        $start = $dateTime->getTimestamp();
        // if end date
        if (!empty($date_field_value['value2'])) {
          // @todo timezone?
          $endDateTime = new DateTime($date_field_value['value2']);
          $end = $endDateTime->getTimestamp();
        }
        break;
      case 'datestamp':
        // Date value is already a timestamp.
        $start = $date_field_value['value'];
        // if end date
        if (!empty($date_field_value['value2'])) {
          $end = $date_field_value['value2'];
        }
        break;
    }

    list($entity_id,,) = entity_extract_ids($entity_type, $entity);

    $entity_array = array(
      'id' => $entity_id,
      'entityType' => $entity_type,
      'bundle' => $entity->bundle,
      'title' => $entity->title,
      'dateField' => $date_field,
      'start' => date('c', $start),
      'className' => array(
        'event-' . $entity_type . '-' . $entity->type,
      ),
    );
    if (!empty($end)) {
      $entity_array['end'] = date('c', $end);
    }

    $settings['events'][] = $entity_array;
  }
  // At this point validation is complete. 
  // Pass the settings data to the theme_fullcalendar_calendar function.

  return theme('fullcalendar_calendar', array(
    'calendar_id' => $calendar_id,
    'calendar_settings' => $settings,
  ));
}
