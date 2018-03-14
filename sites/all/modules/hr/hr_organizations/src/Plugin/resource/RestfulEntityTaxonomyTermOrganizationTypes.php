<?php

namespace Drupal\hr_organizations\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
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
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_organization_type"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */

class RestfulEntityTaxonomyTermOrganizationTypes extends ResourceEntity implements ResourceInterface {

}
