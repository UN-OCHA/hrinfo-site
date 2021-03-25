<?php

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_field_views_data_alter().
 */
function title_field_views_data_alter(&$result, $field, $module) {
  // Replace field default handler (views_handler_field_field).
  foreach (entity_get_info() as $entity_type => $entity_info) {
    $entity_info += array(
      'field replacement' => array(),
    );

    foreach ($entity_info['field replacement'] as $replacement) {
      if (isset($replacement['field']['field_name'])) {
        $field = field_info_field($replacement['field']['field_name']);
        if (!empty($field)) {
          $table = _field_sql_storage_tablename($field);
          if (isset($result[$table][$field['field_name']])) {
            $result[$table][$field['field_name']]['field']['handler'] = 'views_handler_title_field';
          }
        }
      }
    }
  }
}
