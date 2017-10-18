<?php


/**
 * @file
 * OG HR Core selection handler without access check.
 */

class OgHRCoreSelectionHandler extends OgSelectionHandler {

  /**
   * Overrides OgSelectionHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new OgHRCoreSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * Overrides EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    $target_type = $this->field['settings']['target_type'];
    return entity_label($target_type, $entity);
  }

}
