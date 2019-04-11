<?php

/**
 * @file
 * Contains \Drupal\hr_assessments\Plugin\resource\DataProviderAssessments.
 */

namespace Drupal\hr_assessments\Plugin\resource;

use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;
use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Exception\ForbiddenException;

class DataProviderAssessments  extends DataProviderEntity implements DataProviderInterface {
  /**
   * Overrides DataProviderEntity::getQueryForList().
   *
   * Expose only published nodes.
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();
    if ($this->entityType === 'node') {
      $query->propertyCondition('status', NODE_PUBLISHED);
    }
    return $query;
  }

  /**
   * Overrides DataProviderEntity::getQueryCount().
   *
   * Only count published nodes.
   */
  public function getQueryCount() {
    $query = parent::getQueryCount();
    if ($this->entityType === 'node') {
      $query->propertyCondition('status', NODE_PUBLISHED);
    }
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function discover($path = NULL) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function entityPreSave(\EntityDrupalWrapper $wrapper) {
    if ($this->entityType === 'node') {
      $node = $wrapper->value();
      if (!empty($node->nid)) {
        // Node is already saved.
        return;
      }
      node_object_prepare($node);
      $node->uid = $this->getAccount()->uid;
      $node->path['pathauto'] = TRUE;
    }
  }

  protected function setFieldCollectionValues($wrapper, $values) {
    if ($values['accessibility']) {
      $wrapper->field_asst_accessibility->set($values['accessibility']);
    }
    if ($values['file']) {
      $wrapper->field_asst_file->set(array('fid' => $values['file'], 'display' => 1));
    }
    if ($values['url']) {
      $wrapper->field_asst_url->set($values['url']);
    }
    if ($values['instructions']) {
      $wrapper->field_asst_instructions->set($values['instructions']);
    }
    $wrapper->save();
  }

  /**
   * {@inheritdoc}
   */
  public function create($object) {
    $this->validateBody($object);
    $entity_info = $this->getEntityInfo();
    $bundle_key = $entity_info['entity keys']['bundle'];
    // TODO: figure out how to derive the bundle when posting to a resource with
    // multiple bundles.
    $bundle = reset($this->bundles);
    $values = $bundle_key ? array($bundle_key => $bundle) : array();

    $entity = entity_create($this->entityType, $values);

    if ($this->checkEntityAccess('create', $this->entityType, $entity) === FALSE) {
      // User does not have access to create entity.
      throw new ForbiddenException('You do not have access to create a new resource.');
    }

    $report = null;
    if (isset($object['report'])) {
      $report = $object['report'];
      unset($object['report']);
    }

    $questionnaire = null;
    if (isset($object['questionnaire'])) {
      $questionnaire = $object['questionnaire'];
      unset($object['questionnaire']);
    }

    $adata = null;
    if (isset($object['data'])) {
      $adata = $object['data'];
      unset($object['data']);
    }

    /* @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    $this->setPropertyValues($wrapper, $object, TRUE);

    if ($report) {
      $ereport = entity_create('field_collection_item', array('field_name' => 'field_asst_report'));
      $ereport->setHostEntity('node', $entity);
      $wreport = entity_metadata_wrapper('field_collection_item', $ereport);
      $this->setFieldCollectionValues($wreport, $report);
    }

    if ($questionnaire) {
      $equestionnaire = entity_create('field_collection_item', array('field_name' => 'field_asst_questionnaire'));
      $equestionnaire->setHostEntity('node', $entity);
      $wquestionnaire = entity_metadata_wrapper('field_collection_item', $equestionnaire);
      $this->setFieldCollectionValues($wquestionnaire, $questionnaire);
    }

    if ($adata) {
      $edata = entity_create('field_collection_item', array('field_name' => 'field_asst_data'));
      $edata->setHostEntity('node', $entity);
      $wdata = entity_metadata_wrapper('field_collection_item', $edata);
      $this->setFieldCollectionValues($wdata, $adata);
    }

    // The access calls use the request method. Fake the view to be a GET.
    $old_request = $this->getRequest();
    $this->getRequest()->setMethod(RequestInterface::METHOD_GET);
    $output = array($this->view($wrapper->getIdentifier()));
    // Put the original request back to a POST.
    $this->request = $old_request;

    return $output;
  }

  /**
   * {@inheritdoc}
   */
  public function update($identifier, $object, $replace = FALSE) {
    $this->validateBody($object);
    $entity_id = $this->getEntityIdByFieldId($identifier);
    $this->isValidEntity('update', $entity_id);

    if (isset($object['host_entity'])) {
      unset($object['host_entity']);
    }

    /* @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity_id);

    $report = null;
    if (isset($object['report'])) {
      $report = $object['report'];
      unset($object['report']);
    }

    $questionnaire = null;
    if (isset($object['questionnaire'])) {
      $questionnaire = $object['questionnaire'];
      unset($object['questionnaire']);
    }

    $adata = null;
    if (isset($object['data'])) {
      $adata = $object['data'];
      unset($object['data']);
    }

    $this->setPropertyValues($wrapper, $object, $replace);

    if ($report) {
      $raw_report = $wrapper->field_asst_report->value();
      $wreport = entity_metadata_wrapper('field_collection_item', $raw_report);
      $this->setFieldCollectionValues($wreport, $report);
    }

    if ($questionnaire) {
      $raw_questionnaire = $wrapper->field_asst_questionnaire->value();
      $wquestionnaire = entity_metadata_wrapper('field_collection_item', $raw_questionnaire);
      $this->setFieldCollectionValues($wquestionnaire, $questionnaire);
    }

    if ($adata) {
      $raw_data = $wrapper->field_asst_data->value();
      $wdata = entity_metadata_wrapper('field_collection_item', $raw_data);
      $this->setFieldCollectionValues($wdata, $adata);
    }

    // Set the HTTP headers.
    $this->setHttpHeader('Status', 201);

    if (!empty($wrapper->url) && $url = $wrapper->url->value()) {
      $this->setHttpHeader('Location', $url);
    }

    // The access calls use the request method. Fake the view to be a GET.
    $old_request = $this->getRequest();
    $this->getRequest()->setMethod(RequestInterface::METHOD_GET);
    $output = array($this->view($identifier));
    // Put the original request back to a PUT/PATCH.
    $this->request = $old_request;

    return $output;
  }

  /**
   * Validates an entity's fields before they are saved.
   *
   * @param \EntityDrupalWrapper $wrapper
   *   A metadata wrapper for the entity.
   *
   * @throws \Drupal\restful\Exception\RestfulException
   */
  protected function validateFields($wrapper) {
    try {
      $entity = $wrapper->value();
      if (isset($entity->og_group_ref) && user_access('administer group')) {
        foreach($entity->og_group_ref[LANGUAGE_NONE] as &$item) {
          $item['field_mode'] = 'admin';
        }
      }
      field_attach_validate($wrapper->type(), $entity);
    }
    catch (\FieldValidationException $e) {
      throw new UnprocessableEntityException($e->getMessage());
    }
  }

}
