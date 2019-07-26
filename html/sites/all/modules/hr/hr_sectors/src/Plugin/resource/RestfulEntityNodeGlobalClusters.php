<?php

namespace Drupal\hr_sectors\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeGlobalClusters.
 *
 * @package Drupal\hr_sectors\Plugin\resource
 *
 * @Resource(
 *   name = "global_clusters:1.0",
 *   resource = "global_clusters",
 *   label = "Global clusters",
 *   description = "Global clusters",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_sector"
 *     },
 *     "range" = 100,
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulEntityNodeGlobalClusters extends ResourceCustom implements ResourceInterface {

  /**
   * Get public fields.
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['acronym'] = array(
      'property' => 'field_acronym',
    );

    $public_fields['type'] = array(
      'property' => 'field_sector_type',
    );

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderOptimized';
  }

}
