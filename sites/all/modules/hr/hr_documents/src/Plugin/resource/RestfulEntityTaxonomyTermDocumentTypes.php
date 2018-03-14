<?php

namespace Drupal\hr_infographics\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
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
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_infographic_type"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */

class RestfulEntityTaxonomyTermInfographicTypes extends ResourceEntity implements ResourceInterface {

}