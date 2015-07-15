<?php
/**
 * @file
 * hr_events.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hr_events_taxonomy_default_vocabularies() {
  return array(
    'hr_event_category' => array(
      'name' => 'Event Category',
      'machine_name' => 'hr_event_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
