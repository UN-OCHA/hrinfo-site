<?php

namespace Drupal\hr_offices\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeOffices
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
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityNodeOffices extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

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

    return $public_fields;
  }

}
