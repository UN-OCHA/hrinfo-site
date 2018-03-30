<?php

namespace Drupal\hr_documents\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityFieldFilesCollection
 * @package Drupal\hr_documents\Plugin\resource
 *
 * @Resource(
 *   name = "files_collection:1.0",
 *   resource = "files_collection",
 *   label = "File Collections",
 *   description = "File Collections",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "field_collection_item",
 *     "bundles": {
 *       "field_files_collection"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */

class RestfulEntityFieldFilesCollection extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['file'] = array(
      'property' => 'field_file',
    );

    $public_fields['language'] = array(
      'property' => 'field_language',
    );

    $public_fields['host_entity'] = array(
      'property' => 'host_entity',
      'process_callbacks' => array(array($this, 'getHostEntity'))
    )

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_documents\Plugin\resource\DataProviderFieldFilesCollection';
  }

  public function getHostEntity($value) {
    $tmp = new \stdClass();
    $tmp->id = $value->nid;
    $tmp->label = $value->title;
    return $tmp;
  }

}
