<?php

namespace Drupal\hr_disasters\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeDisasters.
 *
 * @package Drupal\hr_disasters\Plugin\resource
 *
 * @Resource(
 *   name = "disasters:1.0",
 *   resource = "disasters",
 *   label = "Disasters",
 *   description = "Disasters pulled from reliefweb.int",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_disaster"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulEntityNodeDisasters extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides ResourceEntity::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['@id'] = array(
      'callback' => array($this, 'getDisasterUrl'),
    );

    $public_fields['glide'] = array(
      'property' => 'field_glide_number',
    );

    $public_fields['primary_type'] = array(
      'property' => 'field_glide_type',
      'process_callbacks' => array(array($this, 'getPrimaryType')),
    );

    $public_fields['status'] = array(
      'property' => 'field_disaster_status',
    );

    $public_fields['reliefweb_id'] = array(
      'property' => 'field_reliefweb_id',
    );

    $public_fields['body-html'] = array(
      'property' => 'body',
      'sub_property' => 'value',
    );

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'process_callbacks' => array(array($this, 'getBodyRaw')),
    );

    $public_fields['operation'] = array(
      'property' => 'og_group_ref',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'operations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
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
   * Get the primary type.
   */
  public function getPrimaryType($value) {
    $term = taxonomy_term_load($value);
    return $term->name;
  }

  /**
   * Get raw body.
   */
  public function getBodyRaw($value) {
    return strip_tags($value);
  }

  /**
   * Get a disaster URL.
   */
  public function getDisasterUrl(DataInterpreterInterface $di) {
    $wrapper = $di->getWrapper();
    $rid = $wrapper->field_reliefweb_id->value();
    if (!$rid) {
      return $this->versionedUrl($wrapper->getIdentifier());
    }
    else {
      return 'http://api.reliefweb.int/v1/disasters/' . $rid;
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderOptimized';
  }

}
