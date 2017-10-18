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

    if (extension_loaded('newrelic')) { // Ensure PHP agent is available
      newrelic_record_custom_event('og_ref' , array(
        'class' => 'RefHRCoreSelectionHandler',
        'label' => entity_label($target_type, $entity),
      ));
    }

    return entity_label($target_type, $entity);
  }

}
