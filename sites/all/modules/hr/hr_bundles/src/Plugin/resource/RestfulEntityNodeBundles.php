<?php

namespace Drupal\hr_bundles\Plugin\resource;
use Drupal\hr_core\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeBundles
 * @package Drupal\hr_bundles\Plugin\resource
 *
 * @Resource(
 *   name = "bundles:1.0",
 *   resource = "bundles",
 *   label = "Clusters/Sectors",
 *   description = "Export the clusters/sectors",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_bundle"
 *     },
 *     "range" = 100,
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityNodeBundles extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['email'] = array(
      'property' => 'field_email',
    );

    $public_fields['type'] = array(
      'property' => 'field_bundle_type',
    );


    $public_fields['global_cluster'] = array(
      'property' => 'field_sector',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'global_clusters',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['lead_agencies'] = array(
      'property' => 'field_organizations',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'organizations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['partners'] = array(
      'property' => 'field_partners',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'organizations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['activation_document'] = array(
      'property' => 'field_activation_document',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'documents',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
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
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'operations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['created'] = array(
      'property' => 'created',
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
    );

    return $public_fields;
  }

  public function getClusterCoordinators($wrapper) {
    $return  = array();
    if (!empty($wrapper)) {
      foreach ($wrapper as $item) {
        $tmp = new \stdClass();
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

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_core\Plugin\resource\DataProviderOptimized';
  }

}
