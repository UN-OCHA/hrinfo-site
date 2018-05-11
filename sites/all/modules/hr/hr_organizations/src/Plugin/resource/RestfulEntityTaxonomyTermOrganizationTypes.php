<?php

namespace Drupal\hr_organizations\Plugin\resource;
use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonoyTermOrganizationTypes
 * @package Drupal\hr_organizations\Plugin\resource
 *
 * @Resource(
 *   name = "organization_types:1.0",
 *   resource = "organization_types",
 *   label = "Organization Types",
 *   description = "Organization Types used for Humanitarianresponse organizations",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_organization_type"
 *     },
 *     "range" = 100,
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityTaxonomyTermOrganizationTypes extends ResourceCustom implements ResourceInterface {
  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderOptimized';
  }
}
