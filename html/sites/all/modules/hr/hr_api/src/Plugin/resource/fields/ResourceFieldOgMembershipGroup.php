<?php

/**
 * @file
 * Contains \Drupal\restful\Plugin\resource\fields\ResourceFieldOgMembershipGroup.
 */

namespace Drupal\hr_api\Plugin\resource\fields;

use Drupal\restful\Plugin\resource\Field\ResourceFieldEntity;
use Drupal\restful\Plugin\resource\Field\ResourceFieldEntityAlterableInterface;

class ResourceFieldOgMembershipGroup extends ResourceFieldEntity implements ResourceFieldEntityAlterableInterface {

  public function alterFilterEntityFieldQuery(array $filter, \EntityFieldQuery $query) {
    if ($filter['public_field'] == 'group') {
      $query->propertyCondition('gid', $filter['value'][0], $filter['operator'][0]);
      $filter['processed'] = TRUE;
    }
    if ($filter['public_field'] == 'entity') {
      $query->propertyCondition('etid', $filter['value'][0], $filter['operator'][0]);
      $filter['processed'] = TRUE;
    }
    return $filter;
  }

  public function alterSortEntityFieldQuery(array $filter, \EntityFieldQuery $query) {
    return $filter;
  }

}
