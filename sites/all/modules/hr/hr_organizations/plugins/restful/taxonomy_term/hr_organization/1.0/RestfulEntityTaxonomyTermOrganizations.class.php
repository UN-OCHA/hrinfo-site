<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermOrganizations.
 */

class RestfulEntityTaxonomyTermOrganizations extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['acronym'] = array(
      'property' => 'field_acronym',
    );

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['fts_id'] = array(
      'property' => 'field_organization_fts',
    );

    $public_fields['type'] = array(
      'property' => 'field_organization_type',
      'resource' => array(
        'hr_organization_type' => 'organization_types',
      ),
    );

    return $public_fields;
  }

}
