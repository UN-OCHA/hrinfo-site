<?php

namespace Drupal\hr_themes\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonoyTermThemes
 * @package Drupal\hr_themes\Plugin\resource
 *
 * @Resource(
 *   name = "themes:1.0",
 *   resource = "themes",
 *   label = "Themes",
 *   description = "Themes used in Humanitarianresponse",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_theme"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityTaxonomyTermThemes extends ResourceEntity implements ResourceInterface {

}
