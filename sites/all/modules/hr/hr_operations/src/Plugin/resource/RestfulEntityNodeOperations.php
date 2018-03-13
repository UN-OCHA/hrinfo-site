<?php

namespace Drupal\hr_operations\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeOperations
 * @package Drupal\hr_operations\Plugin\resource
 *
 * @Resource(
 *   name = "operations:1.0",
 *   resource = "operations",
 *   label = "Operations",
 *   description = "Humanitarianresponse operations",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_operation"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */

class RestfulEntityNodeOperations extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides RestfulEntity::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['email'] = array(
      'property' => 'field_email',
    );

    $public_fields['type'] = array(
      'property' => 'field_operation_type',
    );

    $public_fields['status'] = array(
      'property' => 'field_operation_status',
    );

    $public_fields['hid_access'] = array(
      'property' => 'field_hid_access',
    );

    /*$public_fields['country'] = array(
      'property' => 'field_country',
      'resource' => array(
        'hr_location' => 'locations',
      ),
    );*/

    $public_fields['launch_date'] = array(
      'property' => 'field_launch_date',
    );

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
    );

    $public_fields['url'] = array(
      'property' => 'url',
    );

    return $public_fields;
  }

}
