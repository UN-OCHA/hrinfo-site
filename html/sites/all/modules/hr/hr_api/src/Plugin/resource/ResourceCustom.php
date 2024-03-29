<?php

namespace Drupal\hr_api\Plugin\resource;

use Drupal\restful\Http\HttpHeader;
use Drupal\restful\Plugin\resource\ResourceEntity;

/**
 * Class definition.
 */
abstract class ResourceCustom extends ResourceEntity {

  /**
   * Adds the Allowed-Origin headers.
   *
   * @param string $path
   *   The requested path.
   */
  protected function preflight($path) {
    parent::preflight($path);
    $header_bag = restful()
      ->getResponse()
      ->getHeaders();
    $header_bag->add(HttpHeader::create('Access-Control-Allow-Headers', "Content-Type, Authorization"));

  }

  /**
   * {@inheritdoc}
   */
  public function remove($path) {
    // @todo Compare this with 1.x logic.
    $this->getDataProvider()->remove($path);
    $output = array();
    return $output;
  }

}
