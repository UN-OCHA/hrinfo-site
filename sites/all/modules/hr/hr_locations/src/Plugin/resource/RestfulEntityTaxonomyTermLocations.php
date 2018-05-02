<?php

namespace Drupal\hr_locations\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;
use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterEMW;

/**
 * Class RestfulEntityTaxonomyTermLocations
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
class RestfulEntityTaxonomyTermLocations extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides RestfulEntityBaseNode::addExtraInfoToQuery()
   *
   * Adds proper query tags
   */
  protected function addExtraInfoToQuery($query) {
    parent::addExtraInfoToQuery($query);
    $filters = $this->parseRequestForListFilter();
    if (!empty($filters)) {
      $addTag = FALSE;
      foreach ($filters as $filter) {
        if ($filter['public_field'] == 'parent') {
          $addTag = TRUE;
        }
      }
      if ($addTag == TRUE) {
        $query->addTag('hr_locations_filter_parent');
      }
    }
  }

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

    return $public_fields;
  }

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

  public function getGeolocation(DataInterpreterInterface $di) {
    $wrapper = $di->getWrapper();
    $geofield = $wrapper->field_geofield->value();
    return array('lat' => $geofield['lat'], 'lon' => $geofield['lon']);
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_locations\Plugin\resource\DataProviderLocations';
  }
}
