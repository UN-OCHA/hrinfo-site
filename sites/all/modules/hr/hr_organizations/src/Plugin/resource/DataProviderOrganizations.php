<?php

/**
 * @file
 * Contains \Drupal\hr_organizations\Plugin\resource\DataProviderOrganizations.
 */

namespace Drupal\hr_organizations\Plugin\resource;

use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;
use Drupal\restful\Http\RequestInterface;

class DataProviderOrganizations  extends DataProviderEntity implements DataProviderInterface {

  /**
   * Adds query tags and metadata to the EntityFieldQuery.
   *
   * @param \EntityFieldQuery $query
   *   The query to enhance.
   */
  protected function addExtraInfoToQuery($query) {
    parent::addExtraInfoToQuery($query);
    $query->addTag('hr_organizations_acronym');
  }

}
