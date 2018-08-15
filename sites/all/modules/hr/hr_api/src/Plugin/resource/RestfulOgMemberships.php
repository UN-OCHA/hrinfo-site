<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\RestfulOgMemberships.
 */

namespace Drupal\hr_api\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulOgMemberships
 * @package Drupal\hr_api\Plugin\resource
 *
 * @Resource(
 *   name = "og_membership:1.0",
 *   resource = "og_membership",
 *   label = "OG Membership",
 *   description = "Export the OG Memberships.",
 *   authenticationOptional = TRUE,
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   dataProvider = {
 *     "entityType": "og_membership",
 *     "bundles": {
 *       "og_membership_type_default"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulOgMemberships extends ResourceCustom implements ResourceInterface {

  /**                                             
   * Overrides \RestfulEntityBase::publicFields().
   */                                       
  public function publicFields() {                              
    $public_fields = parent::publicFields();

    $public_fields['entity_type'] = array(
      'property' => 'entity_type'
    );

    $public_fields['entity'] = array(
      'property' => 'entity',
      'process_callbacks' => array(array($this, 'getUser')),
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldOgMembershipGroup'
    );

    $public_fields['group_type'] = array(
      'property' => 'group_type'
    );

    $public_fields['group'] = array(
      'property' => 'group',
      'sub_property' => 'nid',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldOgMembershipGroup'
    );

    $public_fields['roles'] = array(
      'callback' => array($this, 'getRoles')
    );

    $public_fields['created'] = array(
      'property' => 'created'
    );

    $public_fields['state'] = array(
      'property' => 'state'
    );

    return $public_fields;
  }

  public function getRoles($di) {
    $wrapper = $di->getWrapper();
    $uid = $wrapper->entity->getIdentifier();
    $nid = $wrapper->group->getIdentifier();
    return array_values(og_get_user_roles('node', $nid, $uid));
  }

 public function getUser($value) {
   $valueOut = new \stdClass();
   $valueOut->uid = $value->uid;
   $valueOut->label = $value->realname;
   return $valueOut;
 }

}
