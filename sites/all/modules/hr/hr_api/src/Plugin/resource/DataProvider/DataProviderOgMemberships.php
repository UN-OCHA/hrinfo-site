<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\DataProvider\DataProviderEntity.
 */

namespace Drupal\hr_api\Plugin\resource\DataProvider;

use Drupal\restful\Exception\ForbiddenException;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;

/**
 * Class DataProviderOgMemberships.
 *
 * @package Drupal\hr_api\Plugin\resource\DataProvider
 */
class DataProviderOgMemberships extends DataProviderEntity {

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
}
