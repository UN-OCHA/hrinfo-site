<?php

namespace Drupal\hr_documents\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonoyTermDocumentTypes
 * @package Drupal\hr_documents\Plugin\resource
 *
 * @Resource(
 *   name = "document_types:1.0",
 *   resource = "document_types",
 *   label = "Document Types",
 *   description = "Document Types used for Humanitarianresponse documents",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_document_type"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */

class RestfulEntityTaxonomyTermDocumentTypes extends ResourceEntity implements ResourceInterface {

}
