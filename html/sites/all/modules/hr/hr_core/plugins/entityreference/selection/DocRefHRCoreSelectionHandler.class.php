<?php


/**
 * HR Core selection handler for document types.
 */
class DocRefHRCoreSelectionHandler extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new DocRefHRCoreSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * Overrides EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    $target_type = $this->field['settings']['target_type'];

    // Some date fields have 'und', some the language of the entity.
    if (!empty($entity->field_publication_date[$entity->language])) {
      $datefield = $entity->field_publication_date[$entity->language][0];
    }
    elseif (!empty($entity->field_publication_date[LANGUAGE_NONE])) {
      $datefield = $entity->field_publication_date[LANGUAGE_NONE][0];
    }
    else {
      return entity_label($target_type, $entity);
    }
    $date = format_date(strtotime($datefield['value']), 'short', '', $datefield['timezone']);

    return entity_label($target_type, $entity) . ' (' . $date . ')';
  }

  /**
   * Override EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);

    $form['target_bundles']['#access'] = FALSE;
    $form['target_bundles']['#value'] = array(
      'hr_document' => 'hr_document',
    );
    $form['timespan'] = array(
      '#type' => 'textfield',
      '#title' => t('Timespan'),
      '#default_value' => '100',
      '#description' => t('Maximum age since the referenced document was created, or edited, in days.'),
      '#required' => TRUE,
    );
    // Options keyed by taxonomy tid.
    $form['document_type'] = array(
      '#type' => 'select',
      '#title' => t('Document type'),
      '#options' => array(
        74 => 'Agenda',
        73 => 'Meeting minutes',
      ),
      '#default_value' => 'Agenda',
      '#description' => t('The type of the documents that can be referenced.'),
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * Build an EntityFieldQuery to get referencable entities.
   */
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    global $user;

    $handler = EntityReference_SelectionHandler_Generic::getInstance($this->field, $this->instance, $this->entity_type, $this->entity);
    $query = $handler->buildEntityFieldQuery($match, $match_operator);

    // Only get recent documents.
    $timespan = 100;
    if (!empty($this->field['settings']['handler_settings']['timespan'])) {
      $timespan = $this->field['settings']['handler_settings']['timespan'];
    }
    $query->propertyCondition('changed', strtotime('-' . $timespan . ' days'), '>');

    // Add a document type condition.
    if (!empty($this->field['settings']['handler_settings']['document_type'])) {
      $document_type = $this->field['settings']['handler_settings']['document_type'];
      $query->fieldCondition('field_document_type', 'target_id', $document_type);
    }

    return $query;
  }

}
