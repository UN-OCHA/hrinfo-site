<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\DataProvider\DataProviderEntity.
 */

namespace Drupal\hr_api\Plugin\resource\DataProvider;

use Drupal\restful\Exception\ForbiddenException;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Http\RequestInterface;

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

    $og_membership = og_membership_create('node', $object['group'], 'user', hid_profiles_get_uid_by_hid($object['entity']), 'og_user_node');

    if ($this->checkEntityAccess('create', $this->entityType, $og_membership) === FALSE) {
      // User does not have access to create entity.
      throw new ForbiddenException('You do not have access to create a new resource.');
    }

    $og_membership->save();

    // The access calls use the request method. Fake the view to be a GET.
    $old_request = $this->getRequest();
    $this->getRequest()->setMethod(RequestInterface::METHOD_GET);
    $output = array($this->view($og_membership->identifier()));
    // Put the original request back to a POST.
    $this->request = $old_request;

    return $output;
  }
}
