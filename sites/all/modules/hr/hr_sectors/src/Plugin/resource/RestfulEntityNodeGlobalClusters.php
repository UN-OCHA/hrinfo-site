<?php

namespace Drupal\hr_sectors\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeGlobalClusters
 * @package Drupal\hr_sectors\Plugin\resource
 *
 * @Resource(
 *   name = "global_clusters:1.0",
 *   resource = "global_clusters",
 *   label = "Global clusters",
 *   description = "Global clusters",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_sector"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */

class RestfulEntityNodeGlobalClusters extends ResourceEntity implements ResourceInterface {

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

}
