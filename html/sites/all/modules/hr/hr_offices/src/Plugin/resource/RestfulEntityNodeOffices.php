<?php

namespace Drupal\hr_offices\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeOffices.
 *
 * @package Drupal\hr_offices\Plugin\resource
 *
 * @Resource(
 *   name = "offices:1.0",
 *   resource = "offices",
 *   label = "Offices",
 *   description = "Coordination hubs",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_office"
 *     },
 *     "range" = 100,
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulEntityNodeOffices extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    // @todo consider removing this.
    $public_fields['location'] = array(
      'property' => 'field_location',
      'resource' => array(
        'name' => 'locations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['address'] = array(
      'property' => 'field_address',
    );

    $public_fields['phones'] = array(
      'property' => 'field_phones',
    );

    $public_fields['email'] = array(
      'property' => 'field_email',
    );

    $public_fields['coordination_hub'] = array(
      'property' => 'field_is_coordination_hub',
    );

    // @todo consider removing this.
    $public_fields['organizations'] = array(
      'property' => 'field_organizations',
      'resource' => array(
        'name' => 'organizations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['operation'] = array(
      'property' => 'og_group_ref',
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

    $public_fields['published'] = array(
      'property' => 'status',
    );

    $public_fields['language'] = array(
      'property' => 'language',
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
