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
    }
  }
}
