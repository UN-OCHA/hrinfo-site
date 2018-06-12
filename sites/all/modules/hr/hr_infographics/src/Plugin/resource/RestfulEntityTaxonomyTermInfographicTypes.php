<?php

namespace Drupal\hr_infographics\Plugin\resource;
use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonoyTermInfographicTypes
 * @package Drupal\hr_infographics\Plugin\resource
 *
 * @Resource(
 *   name = "infographic_types:1.0",
 *   resource = "infographic_types",
 *   label = "Infographic Types",
 *   description = "Infographic Types used for Humanitarianresponse infographics",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_infographic_type"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityTaxonomyTermInfographicTypes extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['parent'] = array(
      'property' => 'parent',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'infographic_types',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderTermWithParent';
  }
}
