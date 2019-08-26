<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermIndicatorTypes.
 */

/**
 * Class definition.
 */
class RestfulEntityTaxonomyTermIndicatorTypes extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
    );

    return $public_fields;
  }

}
