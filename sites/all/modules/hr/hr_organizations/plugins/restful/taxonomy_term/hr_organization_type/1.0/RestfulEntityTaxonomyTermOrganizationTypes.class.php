<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermOrganizationTypes.
 */

class RestfulEntityTaxonomyTermOrganizationTypes extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['humanitarian_access'] = array(
      'property' => 'field_org_type_access',
    );

    return $public_fields;
  }


}
