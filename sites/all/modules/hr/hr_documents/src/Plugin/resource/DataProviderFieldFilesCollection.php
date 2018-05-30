<?php

/**
 * @file
 * Contains \Drupal\hr_documents\Plugin\resource\DataProviderFieldFilesCollection.
 */

namespace Drupal\hr_documents\Plugin\resource;

use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;
use Drupal\restful\Http\RequestInterface;

class DataProviderFieldFilesCollection  extends DataProviderEntity implements DataProviderInterface {

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

    if (isset($object['host_entity'])) {
      $host_entity = entity_load_single('node', $object['host_entity']);
      $entity->setHostEntity('node', $host_entity);
      unset($object['host_entity']);
    }

    /* @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    $this->setPropertyValues($wrapper, $object, TRUE);

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
