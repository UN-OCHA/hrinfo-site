<?php
/**
 * @file
 * Enable tmgmt_field to translate field collections
 */

/**
 * Implements hook_tmgmt_source_translation_structure().
 *
 * This hook is implemented on behalf of the field_collection module.
 */
function field_collection_tmgmt_source_translation_structure($entity_type, $entity, $field, $instance, $langcode, $items) {
  $fields = array();
  $fields['#label'] = check_plain($instance['label']);
  $sub_fields = field_info_instances('field_collection_item', $field['field_name']);

  foreach ($items as $delta => $item) {
    $field_collection_instance = field_collection_item_load($item['value']);

    if (count($items) > 1) {
      $fields[$delta]['#label'] = t('Delta #@delta', array('@delta' => $delta));
    }

    foreach ($sub_fields as $sub_field_name => $sub_field_instance) {
      $sub_field = field_info_field($sub_field_name);
      $sub_field_items = field_get_items('field_collection_item', $field_collection_instance, $sub_field_name, $langcode);

      if ($items) {
        $sub_field_data = module_invoke(
          $sub_field['module'],
          'tmgmt_source_translation_structure',
          'field_collection_item',
          $field_collection_instance,
          $sub_field,
          $sub_field_instance,
          $langcode,
          $sub_field_items
        );

        if ($sub_field_data) {
          $fields[$delta][$sub_field_name] = $sub_field_data;
        }
      }
    }
  }

  return $fields;
}

/**
 * Implements hook_tmgmt_field_type_populate_entity().
 *
 * This hook is implemented on behalf of the field_collection module.
 */
function field_collection_field_type_tmgmt_populate_entity($entity_type, $entity, $field, $instance, $langcode, $data, $use_translatable = TRUE) {

  if (!isset($data[$field['field_name']])) {
    return;
  }

  $field_name = $field['field_name'];
  $field_items = field_get_items($entity_type, $entity, $field_name);

  foreach (element_children($data[$field_name]) as $delta) {
    $field_item = isset($field_items[$delta]) ? $field_items[$delta] : NULL;
    /*
     * Do not use $langcode to access data of a field collection,
     * because field collection always has LANGUAGE_NONE
     */
    $entity->{$field_name}[LANGUAGE_NONE][$delta]['entity'] = field_collection_field_get_entity($field_item, $field_name);
    tmgmt_field_populate_entity(
      'field_collection_item',
      $entity->{$field_name}[LANGUAGE_NONE][$delta]['entity'],
      $langcode,
      $data[$field_name][$delta],
      $use_translatable
    );
  }
}
