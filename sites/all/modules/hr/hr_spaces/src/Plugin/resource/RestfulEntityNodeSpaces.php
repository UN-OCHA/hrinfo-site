<?php

namespace Drupal\hr_spaces\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeSpaces
 * @package Drupal\hr_spaces\Plugin\resource
 *
 * @Resource(
 *   name = "spaces:1.0",
 *   resource = "spaces",
 *   label = "Spaces",
 *   description = "Export the global spaces",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_space"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityNodeSpaces extends ResourceEntity implements ResourceInterface {

  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['email'] = array(
      'property' => 'field_email',
    );

    $public_fields['category'] = array(
      'property' => 'field_space_category',
      'sub_property' => 'name',
    );

    $public_fields['organizations'] = array(
      'property' => 'field_organizations',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'organizations',
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

    $public_fields['url'] = array(
      'property' => 'url',
    );

    return $public_fields;
  }

}
