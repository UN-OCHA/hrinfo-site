<?php

namespace Drupal\hr_assessments\Plugin\resource;
use Drupal\hr_core\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonoyTermPopulationTypes
 * @package Drupal\hr_assessments\Plugin\resource
 *
 * @Resource(
 *   name = "population_types:1.0",
 *   resource = "population_types",
 *   label = "Population Types",
 *   description = "Population Types taxonomy used for assessments",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_population_type"
 *     },
 *     "range" = 100
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityTaxonomyTermPopulationTypes extends ResourceCustom implements ResourceInterface {

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_core\Plugin\resource\DataProviderOptimized';
  }

}
