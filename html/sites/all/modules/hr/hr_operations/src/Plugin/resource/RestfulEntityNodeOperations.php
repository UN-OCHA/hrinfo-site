<?php

namespace Drupal\hr_operations\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;

/**
 * Class RestfulEntityNodeOperations.
 *
 * @package Drupal\hr_operations\Plugin\resource
 *
 * @Resource(
 *   name = "operations:1.0",
 *   resource = "operations",
 *   label = "Operations",
 *   description = "Humanitarianresponse operations",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_operation"
 *     },
 *     "range" = 100,
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulEntityNodeOperations extends ResourceCustom implements ResourceInterface {

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

    $public_fields['country'] = array(
      'property' => 'field_country',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'locations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['region'] = array(
      'property' => 'field_operation_region',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'operations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['cluster_configuration'] = array(
      'property' => 'field_cluster_configuration',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'documents',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['managed_by'] = array(
      'property' => 'field_organizations',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'organizations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['timezone'] = array(
      'callback' => array($this, 'getTimezone')
    );

    $public_fields['focal_points'] = array(
      'callback' => array($this, 'getContacts')
    );

    $public_fields['social_media'] = array(
      'property' => 'field_social_media'
    );

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

    $public_fields['published'] = array(
      'property' => 'status',
    );

    $public_fields['language'] = array(
      'property' => 'language'
    );

    return $public_fields;
  }

  /**
   * Get contacts.
   */
  public function getContacts(DataInterpreterInterface $di) {
    $cids = array();
    $wrapper = $di->getWrapper();
    $nid = $wrapper->getIdentifier();
    $node = node_load($nid);
    if (!empty($node->field_hid_contact_ref)) {
      foreach ($node->field_hid_contact_ref[LANGUAGE_NONE] as $cid) {
        $cids[] = $cid['cid'];
      }
    }
    return $cids;
  }

  /**
   * Get timezone.
   */
  public function getTimezone(DataInterpreterInterface $di) {
    $wrapper = $di->getWrapper();
    $nid = $wrapper->getIdentifier();
    $store = variable_store('og', 'node_' . $nid);
    return $store['date_default_timezone'] ? $store['date_default_timezone'] : variable_get('date_default_timezone');
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderOptimized';
  }

}
