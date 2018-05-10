<?php

/**
 * @file
 * Contains \Drupal\hr_locations\Plugin\resource\DataProviderLocations.
 */

namespace Drupal\hr_locations\Plugin\resource;

use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;
use Drupal\restful\Http\RequestInterface;

class DataProviderLocations  extends DataProviderEntity implements DataProviderInterface {

  /**
   * {@inheritdoc}
   */
  public function discover($path = NULL) {
    return array();
  }

  /**
   * Adds query tags and metadata to the EntityFieldQuery.
   *
   * @param \EntityFieldQuery $query
   *   The query to enhance.
   */
  protected function addExtraInfoToQuery($query) {
    parent::addExtraInfoToQuery($query);
    $filters = $this->parseRequestForListFilter();
    if (!empty($filters)) {
      $addTag = FALSE;
      foreach ($filters as $filter) {
        if ($filter['public_field'] == 'parent') {
          $addTag = TRUE;
        }
      }
      if ($addTag == TRUE) {
        $query->addTag('hr_core_filter_parent');
      }
    }
  }

}
