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
   * {@inheritdoc}
   */
  public function discover($path = NULL) {
    return array();
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
      $report = clone $object['report'];
      unset($object['report']);
    }

    $questionnaire = null;
    if (isset($object['questionnaire'])) {
      $questionnaire = clone $object['questionnaire'];
      unset($object['questionnaire']);
    }

    $adata = null;
    if (isset($object['data'])) {
      $adata = clone $object['data'];
      unset($object['data']);
    }

    /* @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    $this->setPropertyValues($wrapper, $object, TRUE);

    if ($report) {
      $ereport = entity_create('field_collection_item', array('bundles' => 'field_asst_report'));
      $ereport->setHostEntity('node', $entity);
      $wreport = entity_metadata_wrapper('field_collection_item', $ereport);
      $this->setPropertyValues($wreport, $report, TRUE);
    }

    if ($questionnaire) {
      $equestionnaire = entity_create('field_collection_item', array('bundles' => 'field_asst_questionnaire'));
      $equestionnaire->setHostEntity('node', $entity);
      $wquestionnaire = entity_metadata_wrapper('field_collection_item', $equestionnaire);
      $this->setPropertyValues($wquestionnaire, $questionnaire, TRUE);
    }

    if ($adata) {
      $edata = entity_create('field_collection_item', array('bundles' => 'field_asst_data'));
      $edata->setHostEntity('node', $entity);
      $wdata = entity_metadata_wrapper('field_collection_item', $edata);
      $this->setPropertyValues($wdata, $adata, TRUE);
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

    $this->setPropertyValues($wrapper, $object, $replace);

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

}
