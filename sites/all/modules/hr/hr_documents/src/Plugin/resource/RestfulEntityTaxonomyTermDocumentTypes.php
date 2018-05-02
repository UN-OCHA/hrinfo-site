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
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_document_type"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*",
 * )
 */

class RestfulEntityTaxonomyTermDocumentTypes extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['parent'] = array(
      'property' => 'parent',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'document_types',
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
    return '\Drupal\hr_documents\Plugin\resource\DataProviderDocumentTypes';
  }

}
