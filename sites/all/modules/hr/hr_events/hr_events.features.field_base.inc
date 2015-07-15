<?php
/**
 * @file
 * hr_events.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hr_events_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_event_agenda'
  $field_bases['field_event_agenda'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_agenda',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'hr_document' => 'hr_document',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_event_category'
  $field_bases['field_event_category'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_category',
    'foreign keys' => array(
      'taxonomy_term_data' => array(
        'columns' => array(
          'target_id' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 1,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'hr_event_category' => 'hr_event_category',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_event_date'
  $field_bases['field_event_date'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'entity_translation_sync' => FALSE,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'profile2_private' => FALSE,
      'repeat' => 1,
      'timezone_db' => array(
        '#after_build' => array(	
          0 => 'conditional_fields_element_after_build',	
        ),	
        '#after_build_done' => TRUE,	
        '#array_parents' => array(	
          0 => 'field',	
          1 => 'settings',	
          2 => 'timezone_db',
        ),	
        '#defaults_loaded' => TRUE,	
        '#id' => 'edit-field-settings-timezone-db',
        '#input' => TRUE,	
        '#name' => 'field[settings][timezone_db]',
        '#parents' => array(	
          0 => 'field',	
          1 => 'settings',	
          2 => 'timezone_db',	
        ),	
        '#process' => array(	
          0 => 'ajax_process_form',	
        ),	
        '#processed' => TRUE,
        '#sorted' => TRUE,	
        '#theme' => 'hidden',	
        '#title_display' => 'before',	
        '#tree' => TRUE,	
        '#type' => 'hidden',	
        '#validated' => TRUE,	
        '#value' => 'UTC',	
        '#weight' => 0.004,	
      ),
      'todate' => 'optional',
      'tz_handling' => 'date',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_event_meeting_minutes'
  $field_bases['field_event_meeting_minutes'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_meeting_minutes',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'hr_document' => 'hr_document',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
