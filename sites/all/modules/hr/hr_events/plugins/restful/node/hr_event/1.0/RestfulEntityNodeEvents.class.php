<?php

/**
 * @file
 * Contains \RestfulEntityNodeEvents.
 */

class RestfulEntityNodeEvents extends \RestfulEntityBaseNode {

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

    $public_fields['category'] = array(
      'property' => 'field_event_category',
      'sub_property' => 'name',
    );

    $public_fields['date'] = array(
      'property' => 'field_event_date',
      'process_callbacks' => array(array($this, 'formatDate')),
    );

    $public_fields['address'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(array($this, 'formatAddress')),
    );

    $public_fields['contacts'] = array(
      'property' => 'field_users_ref',
      'process_callbacks' => array(array($this, 'getContacts')),
    );

    $public_fields['meeting_minutes'] = array(
      'property' => 'field_event_meeting_minutes',
      'resource' => array(
        'hr_document' => 'documents',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    $public_fields['agenda'] = array(
      'property' => 'field_event_agenda',
      'resource' => array(
        'hr_document' => 'documents',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
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

    $public_fields['location'] = array(
      'property' => 'field_location',
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

    $public_fields['fundings'] = array(
      'property' => 'field_fundings',
      'process_callbacks' => array(array($this, 'getFundings')),
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

  protected function getFundings($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new stdClass();
        $tmp->label = $value->title;
        if (!empty($value->field_appeal_id)) {
          $tmp->self = 'http://fts.unocha.org/api/v1/Appeal/id/'.$value->field_appeal_id[LANGUAGE_NONE][0]['value'].'.json';
        }
        $return[] = $tmp;
      }
    }
    return $return;
  }

  protected function getBodyRaw($value) {
    return strip_tags($value);
  }

  protected function formatDate($values) {
    foreach ($values as &$value) {
      if (isset($value['date_type'])) {
        unset($value['date_type']);
      }
    }
    return $values;
  }

  protected function formatAddress($value) {
    unset($value['organisation_name']);
    unset($value['name_line']);
    unset($value['first_name']);
    unset($value['last_name']);
    unset($value['data']);
    return $value;
  }

  protected function getContacts($wrapper) {
    $return  = array();
    if (!empty($wrapper)) {
      foreach ($wrapper as $item) {
        $tmp = new stdClass();
        if (!empty($item->field_user)) {
          $account = user_load($item->field_user[LANGUAGE_NONE][0]['target_id']);
          $tmp->name = $account->realname;
          $tmp->email = $account->mail;
        }
        else {
          if (!empty($item->field_users_ref_name)) {
            $tmp->name = $item->field_users_ref_name[LANGUAGE_NONE][0]['value'];
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
