<?php

/**
 * @file
 * Contains \Drupal\restful\Plugin\resource\fields\ResourceFieldEntityOperation.
 */

namespace Drupal\hr_disasters\Plugin\resource\fields;

use Drupal\restful\Plugin\resource\Field\ResourceFieldEntity;
use Drupal\restful\Plugin\resource\Field\ResourceFieldEntityInterface;

class ResourceFieldEntityOperation extends ResourceFieldEntity implements ResourceFieldEntityInterface {

  /**
   * {@inheritdoc}
   */
  public function preprocess($value) {
    // dpm($value, 'preprocess $value');

    print_r($value);
    return $value;
  }

}
