<?php

/**
 * @file
 * Contains \RestfulEntityNodeInfographics.
 */

class RestfulEntityNodeInfographics extends \RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['infographic_type'] = array(
      'property' => 'field_infographic_type',
      'resource' => array(
        'hr_infographic_type' => 'infographic_types',
      ),
    );

    $public_fields['body-html'] = array(
      'property' => 'body',
      'sub_property' => 'value',
    );

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'process_callbacks' => array(array($this, 'getBodyRaw')),
    );

    $public_fields['files'] = array(
      'property' => 'field_files_collection',
      'process_callbacks' => array(array($this, 'getFiles')),
    );

    $public_fields['data_sources'] = array(
      'property' => 'field_data_sources',
      'process_callbacks' => array(array($this, 'getDataSources')),
    );

    $public_fields['global_clusters'] = array(
      'property' => 'field_sectors',
      'resource' => array(
        'hr_sector' => 'global_clusters',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['bundles'] = array(
      'property' => 'field_bundles',
      'resource' => array(
        'hr_bundle' => 'bundles',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['organizations'] = array(
      'property' => 'field_organizations',
      'resource' => array(
        'hr_organization' => 'organizations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['locations'] = array(
      'property' => 'field_locations',
      'resource' => array(
        'hr_location' => 'locations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['offices'] = array(
      'property' => 'field_coordination_hubs',
      'resource' => array(
        'hr_office' => 'offices',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['publication_date'] = array(
      'property' => 'field_publication_date',
      'process_callbacks' => array(array($this, 'formatTimestamp')),
    );

    $public_fields['themes'] = array(
      'property' => 'field_themes',
      'resource' => array(
        'hr_theme' => 'themes',
      ),
    );

    $public_fields['disasters'] = array(
      'property' => 'field_disasters',
      'process_callbacks' => array(array($this, 'getDisasters')),
    );

    $public_fields['operation'] = array(
      'property' => 'og_group_ref',
      'resource' => array(
        'hr_operation' => 'operations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['space'] = array(
      'property' => 'og_group_ref',
      'resource' => array(
        'hr_space' => 'spaces',
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

  protected function formatTimestamp($value) {
    return strftime('%F', $value);
  }

  protected function getDisasters($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new stdClass();
        $tmp->glide = $value->field_glide_number[LANGUAGE_NONE][0]['value'];
        $tmp->label = $value->title;
        if (!empty($value->field_reliefweb_id)) {
          $tmp->self = 'http://api.reliefweb.int/v1/disasters/'.$value->field_reliefweb_id[LANGUAGE_NONE][0]['value'];
        }
        $return[] = $tmp;
      }
    }
    return $return;
  }

  protected function getBodyRaw($value) {
    return strip_tags($value);
  }

  protected function getFiles($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new stdClass();
        $tmp->file = new stdClass();
        $field_file = $value->field_file[LANGUAGE_NONE][0];
        $tmp->file->fid = $field_file['fid'];
        $tmp->file->filename = $field_file['filename'];
        $tmp->file->filesize = $field_file['filesize'];
        $tmp->file->url = file_create_url($field_file['uri']);
        if (!empty($value->field_language)) {
          $tmp->language = $value->field_language[LANGUAGE_NONE][0]['value'];
        }
        $return[] = $tmp;
      }
    }
    return $return;
  }

  protected function getDataSources($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new stdClass();
        $tmp->url = $value['url'];
        $tmp->title = $value['title'];
        $return[] = $tmp;
      }
    }
    return $return;
  }

}
