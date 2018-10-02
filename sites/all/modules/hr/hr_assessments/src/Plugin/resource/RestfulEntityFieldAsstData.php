<?php

namespace Drupal\hr_assessments\Plugin\resource;
use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityFieldAsstData
 * @package Drupal\hr_assessments\Plugin\resource
 *
 * @Resource(
 *   name = "asst_data:1.0",
 *   resource = "asst_data",
 *   label = "Assessment data",
 *   description = "Assessment data",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "field_collection_item",
 *     "bundles": {
 *       "field_asst_data"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*",
 * )
 */

class RestfulEntityFieldAsstData extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['accessibility'] = array(
      'property' => 'field_asst_accessibility',
    );

    $public_fields['file'] = array(
      'property' => 'field_asst_file',
    );

    $public_fields['url'] = array(
      'property' => 'field_asst_url',
    );

    $public_fields['instructions'] = array(
      'property' => 'field_asst_instructions'
    );

    $public_fields['host_entity'] = array(
      'property' => 'host_entity',
      'process_callbacks' => array(array($this, 'getHostEntity')),
    );

    return $public_fields;
  }

  public function getHostEntity($value) {
    $tmp = new \stdClass();
    $tmp->id = $value->nid;
    $tmp->label = $value->title;
    return $tmp;
  }

}
