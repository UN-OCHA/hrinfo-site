<?php

/**
 * @file
 * Contains \RestfulEntityNodeDisasters.
 */

class RestfulEntityNodeDisasters extends \RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['@id'] = array(
      'callback' => array($this, 'getDisasterUrl'),
    );

    $public_fields['glide'] = array(
      'property' => 'field_glide_number',
    );

    $public_fields['primary_type'] = array(
      'property' => 'field_glide_type',
      'sub_property' => 'name',
    );

    $public_fields['status'] = array(
      'property' => 'field_disaster_status',
    );

    $public_fields['reliefweb_id'] = array(
      'property' => 'field_reliefweb_id',
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

  protected function getBodyRaw($value) {
    return strip_tags($value);
  }

  protected function getDisasterUrl($wrapper) {
    $rid = $wrapper->field_reliefweb_id->value();
    if (!$rid) {
      return $this->versionedUrl($wrapper->getIdentifier());
    }
    else {
      return 'http://api.reliefweb.int/v1/disasters/'.$rid;
    }
  }

}
