<?php

/**
 * @file
 * Contains \RestfulEntityNodeBundles.
 */

class RestfulEntityNodeBundles extends \RestfulEntityBaseNode {

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

    $public_fields['email'] = array(
      'property' => 'field_email',
    );

    $public_fields['type'] = array(
      'property' => 'field_bundle_type',
    );


    $public_fields['global_cluster'] = array(
      'property' => 'field_sector',
      'resource' => array(
        'hr_sector' => 'global_clusters',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['lead_agencies'] = array(
      'property' => 'field_organizations',
      'resource' => array(
        'hr_organization' => 'organizations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['partners'] = array(
      'property' => 'field_partners',
      'resource' => array(
        'hr_organization' => 'organizations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['activation_document'] = array(
      'property' => 'field_activation_document',
      'resource' => array(
        'hr_document' => 'documents',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['cluster_coordinators'] = array(
      'property' => 'field_cluster_coordinators',
      'process_callbacks' => array(array($this, 'getClusterCoordinators')),
    );

    $public_fields['hid_access'] = array(
      'property' => 'field_bundle_hid_access',
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

  protected function getClusterCoordinators($wrapper) {
    $return  = array();
    if (!empty($wrapper)) {
      foreach ($wrapper as $item) {
        $tmp = new stdClass();
        if (!empty($item->field_cluster_coordinator)) {
          $account = user_load($item->field_cluster_coordinator[LANGUAGE_NONE][0]['target_id']);
          $tmp->name = $account->realname;
          $tmp->email = $account->mail;
        }
        else {
          if (!empty($item->field_cluster_coordinator_name)) {
            $tmp->name = $item->field_cluster_coordinator_name[LANGUAGE_NONE][0]['value'];
          }
          if (!empty($item->field_email)) {
            $tmp->email = $item->field_email[LANGUAGE_NONE][0]['email'];
          }
        }
        $return[] = $tmp;
      }
    }
    return $return;
  }

}
