<?php

/**
 * @file
 * Contains \RestfulEntityNodeGlobalClusters.
 */

class RestfulEntityNodeGlobalClusters extends \RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['acronym'] = array(
      'property' => 'field_acronym',
    );

    $public_fields['type'] = array(
      'property' => 'field_sector_type',
    );

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
    );

    return $public_fields;
  }

}
