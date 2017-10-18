<?php


/**
 * @file
 * HR Core selection handler without access check.
 */

class RefHRCoreSelectionHandler extends EntityReference_SelectionHandler_Generic {

  /**
   * Overrides OgSelectionHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new RefHRCoreSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * Overrides EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    $target_type = $this->field['settings']['target_type'];
    return entity_label($target_type, $entity);
  }

}
