<?php

/*
 * @file
 * API documentation for this module.
 */

/**
 * Alter source field data before being saved in a translation job.
 *
 * @param array $data
 *    Source field data.
 * @param string $entity_type
 *   The entity type.
 * @param object $entity
 *   An entity object.
 * @param string $langcode
 *   The language of retrieved field values.
 */
function hook_tmgmt_field_source_data_alter(&$data, $entity_type, $entity, $langcode) {

}

/**
 * Extract translatable text elements from a field.
 *
 * @param $entity_type
 *   The type of $entity.
 * @param $entity
 *   The entity being extracted.
 * @param $field
 *   The field structure.
 * @param $instance
 *   The field instance.
 * @param $langcode
 *   The language associated with $items.
 * @param $items
 *   Array of values for this field.
 *
 * @return
 *   An array of translatable text elements, keyed by the schema name of the
 *   field.
 *
 * @see text_tmgmt_source_translation_structure()
 *
 * @ingroup tmgmt_source
 */
function hook_tmgmt_source_translation_structure($entity_type, $entity, $field, $instance, $langcode, $items) {

}

/**
 * Puts data on the entity of the field type owned by the module.
 *
 * @param $entity_type
 *   The type of $entity.
 * @param $entity
 *   The entity being extracted.
 * @param $field
 *   The field structure.
 * @param $instance
 *   The field instance.
 * @param $langcode
 *   The language associated with $items.
 * @param $data
 *   Translated data array.
 * @param $use_field_translation
 *   TRUE if field translation is being used.
 *
 * @see tmgmt_field_populate_entity()
 */
function hook_tmgmt_field_type_populate_entity($entity_type, $entity, $field, $instance, $langcode, $data, $use_field_translation) {

}

/**
 * Alter an entity object before populating its field with translations.
 *
 * @param array $data
 *    Source field data.
 * @param object $entity
 *   An entity object.
 * @param string $entity_type
 *   The entity type.
 * @param string $langcode
 *   The language of retrieved field values.
 */
function hook_tmgmt_field_pre_populate_entity_alter(&$data, $entity, $entity_type, $langcode) {

}

/**
 * Alter an entity object after populating its field with translations.
 *
 * @param object $entity
 *   An entity object.
 * @param string $entity_type
 *   The entity type.
 * @param array $data
 *    Source field data.
 * @param string $langcode
 *   The language of retrieved field values.
 */
function hook_tmgmt_field_post_populate_entity_alter(&$entity, $entity_type, $data, $langcode) {

}
