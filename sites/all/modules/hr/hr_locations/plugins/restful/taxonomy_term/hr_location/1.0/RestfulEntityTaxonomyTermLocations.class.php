<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermLocations.
 */

class RestfulEntityTaxonomyTermLocations extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides RestfulEntityBaseNode::addExtraInfoToQuery()
   * 
   * Adds proper query tags
   */
  protected function addExtraInfoToQuery($query) {
    parent::addExtraInfoToQuery($query);
    $filters = $this->parseRequestForListFilter();
    if (!empty($filters)) {
      $addTag = FALSE;
      foreach ($filters as $filter) {
        if ($filter['public_field'] == 'parent') {
          $addTag = TRUE;
        }
      }
      if ($addTag == TRUE) {
        $query->addTag('hr_locations_filter_parent');
      }
    }
  }

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['pcode'] = array(
      'property' => 'field_pcode',
    );

    $public_fields['iso3'] = array(
      'property' => 'field_iso3',
    );

    $public_fields['parents'] = array(
      'callback' => array($this, 'getParents'),
    );

    $public_fields['admin_level'] = array(
      'property' => 'field_loc_admin_level',
    );

    $public_fields['geolocation'] = array(
      'callback' => array($this, 'getGeolocation'),
    );

    $public_fields['parent'] = array(
      'property' => 'parent',
      'resource' => array(
        'hr_location' => 'locations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    return $public_fields;
  }

  protected function getEntity($wrapper) {
    $single = FALSE;
    foreach ($wrapper as $id => &$item) {
      if (is_string($item) || $single == TRUE) {
        if ($single == FALSE) {
          $single = TRUE;
        }
        if (!in_array($id, array('id', 'label', 'self'))) {
          unset($wrapper[$id]);
        }
      }
      else {
        $array_item = (array)$item;
        $properties = array_keys($array_item);
        foreach ($properties as $property) {
          if (!in_array($property, array('id', 'label', 'self'))) {
            unset($array_item[$property]);
          }
        }
        $item = (object)$array_item;
      }
    }
    return $wrapper;
  }

  protected function getParents($wrapper) {
    $labels = array();
    foreach ($wrapper->parents_all->getIterator() as $delta => $term_wrapper) {
      $labels[] = $this->getEntitySelf($term_wrapper);
    }
    return $labels;
  }

  protected function getAdminLevel($wrapper) {
    $count = 0;
    foreach ($wrapper->parents_all->getIterator() as $delta => $term_wrapper) {
      $count++;
    }
    return $count - 1;
  }

  protected function getGeolocation($wrapper) {
    $geofield = $wrapper->field_geofield->value();
    return array('lat' => $geofield['lat'], 'lon' => $geofield['lon']);
  }
}
