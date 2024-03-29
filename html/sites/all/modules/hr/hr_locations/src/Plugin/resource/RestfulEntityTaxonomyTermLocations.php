<?php

namespace Drupal\hr_locations\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterEMW;
use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonomyTermLocations.
 *
 * @package Drupal\hr_locations\Plugin\resource
 *
 * @Resource(
 *   name = "locations:1.0",
 *   resource = "locations",
 *   label = "Locations",
 *   description = "Humanitarianresponse locations",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_location"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulEntityTaxonomyTermLocations extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['pcode'] = array(
      'property' => 'field_pcode',
    );

    $public_fields['iso3'] = array(
      'property' => 'field_iso3',
    );

    $public_fields['parents'] = array(
      'callback' => array($this, 'getParents'),
    );

    $public_fields['admin_level'] = array(
      'property' => 'field_loc_admin_level',
    );

    $public_fields['geolocation'] = array(
      'callback' => array($this, 'getGeolocation'),
    );

    $public_fields['parent'] = array(
      'property' => 'parent',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'locations',
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
   * Get parents.
   */
  public function getParents(DataInterpreterInterface $di) {
    global $user;
    $wrapper = $di->getWrapper();
    $labels = array();
    foreach ($wrapper->parents_all->getIterator() as $delta => $term_wrapper) {
      $tdi = new DataInterpreterEMW($user, $term_wrapper);
      $labels[] = $this->getEntitySelf($tdi);
    }
    return $labels;
  }

  /**
   * Get geolocation.
   */
  public function getGeolocation(DataInterpreterInterface $di) {
    $wrapper = $di->getWrapper();
    $geofield = $wrapper->field_geofield->value();
    return array('lat' => $geofield['lat'], 'lon' => $geofield['lon']);
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderTermWithParent';
  }

}
