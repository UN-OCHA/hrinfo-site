<?php

namespace Drupal\hr_api\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Http\HttpHeader;

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

}
