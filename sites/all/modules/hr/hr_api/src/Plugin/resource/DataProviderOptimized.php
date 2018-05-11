<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\DataProviderOptimized.
 */

namespace Drupal\hr_api\Plugin\resource;

use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;
use Drupal\restful\Http\RequestInterface;

class DataProviderOptimized  extends DataProviderEntity implements DataProviderInterface {
  /**
   * {@inheritdoc}
   */
  public function discover($path = NULL) {
    return array();
  }
}
