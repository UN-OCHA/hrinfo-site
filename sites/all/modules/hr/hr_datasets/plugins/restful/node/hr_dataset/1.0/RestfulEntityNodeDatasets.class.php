<?php

/**
 * @file
 * Contains \RestfulEntityNodeDatasets.
 */

class RestfulEntityNodeDatasets extends \RestfulEntityBaseNode {

  /**
   * Overrides RestfulEntityBaseNode::addExtraInfoToQuery()
   * 
   * Adds proper query tags
   */
  protected function addExtraInfoToQuery($query) {
    parent::addExtraInfoToQuery($query);
    $filters = $this->parseRequestForListFilter();
    if (!empty($filters)) {
      foreach ($query->tags as $i => $tag) {
        if ($tag == 'node_access') {
          unset($query->tags[$i]);
        }
      }
      $query->addTag('entity_field_access');
    }
  }

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['categories'] = array(
      'property' => 'field_dataset_categories',
      'sub_property' => 'name',
    );

    $public_fields['summary'] = array(
      'property' => 'field_ds_summary',
      'sub_property' => 'value',
    );

    $public_fields['data_sources'] = array(
      'property' => 'field_ds_datasources',
      'sub_property' => 'value',
    );

    $public_fields['data_guardian'] = array(
      'property' => 'field_email',
    );

    $public_fields['terms_of_use'] = array(
      'property' => 'field_terms_of_use',
      'sub_property' => 'value',
    );

    $public_fields['abstract'] = array(
      'property' => 'field_ds_abstract',
      'sub_property' => 'value',
    );

    $public_fields['types'] = array(
      'property' => 'field_dataset_types',
      'sub_property' => 'name',
    );

    $public_fields['date'] = array(
      'property' => 'field_ds_date',
      'process_callbacks' => array(array($this, 'getDatasetDate')),
    );

    $public_fields['recent_changes'] = array(
      'property' => 'field_ds_recent_changes',
      'sub_property' => 'value',
    );

    $public_fields['languages'] = array(
      'property' => 'field_languages',
      'sub_property' => 'value',
    );

    $public_fields['instructions'] = array(
      'property' => 'field_ds_instructions',
      'sub_property' => 'value',
    );

    $public_fields['locations'] = array(
      'property' => 'field_locations',
      'resource' => array(
        'hr_location' => 'locations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['files'] = array(
      'property' => 'field_ds_files',
      'process_callbacks' => array(array($this, 'getFiles')),
    );

    $public_fields['operation'] = array(
      'property' => 'og_group_ref',
      'resource' => array(
        'hr_operation' => 'operations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
    );

    $public_fields['url'] = array(
      'property' => 'url',
    );

    return $public_fields;
  }

  protected function getEntity($wrapper) {
    foreach ($wrapper as &$item) {
      $array_item = (array)$item;
      $properties = array_keys($array_item);
      foreach ($properties as $property) {
        if (!in_array($property, array('id', 'label', 'self'))) {
          unset($array_item[$property]);
        }
      }
      $item = (object)$array_item;
    }
    return $wrapper;
  }

  protected function getFiles($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new stdClass();
        $tmp->fid = $value['fid'];
        $tmp->filename = $value['filename'];
        $tmp->filesize = $value['filesize'];
        $tmp->url = file_create_url($value['uri']);
        $return[] = $tmp;
      }
    }
    return $return;
  }

  protected function getDatasetDate($value) {
    return strftime('%Y-%m-%d', $value);
  }

}
