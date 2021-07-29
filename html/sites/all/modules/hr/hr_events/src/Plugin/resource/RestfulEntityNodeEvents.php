<?php

namespace Drupal\hr_events\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeEvents.
 *
 * @package Drupal\hr_events\Plugin\resource
 *
 * @Resource(
 *   name = "events:1.0",
 *   resource = "events",
 *   label = "Events",
 *   description = "Humanitarianresponse events",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_event"
 *     },
 *     "range" = 100,
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulEntityNodeEvents extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

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

    $public_fields['meeting_minutes'] = array(
      'property' => 'field_event_meeting_minutes',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'documents',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['agenda'] = array(
      'property' => 'field_event_agenda',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'documents',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['body-html'] = array(
      'property' => 'body',
      'sub_property' => 'value',
    );

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'class' => '\Drupal\hr_api\Plugin\resource\Field\ResourceFieldEntityTextCustom',
      'process_callbacks' => array(array($this, 'getBodyRaw')),
    );

    $public_fields['global_clusters'] = array(
      'property' => 'field_sectors',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'global_clusters',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['bundles'] = array(
      'property' => 'field_bundles',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'bundles',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['organizations'] = array(
      'property' => 'field_organizations',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'organizations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['location'] = array(
      'property' => 'field_location',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'locations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['offices'] = array(
      'property' => 'field_coordination_hubs',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'offices',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['themes'] = array(
      'property' => 'field_themes',
      'resource' => array(
        'name' => 'themes',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['disasters'] = array(
      'property' => 'field_disasters',
      'process_callbacks' => array(array($this, 'getDisasters')),
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

    $public_fields['space'] = array(
      'property' => 'og_group_ref',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'spaces',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['language'] = array(
      'property' => 'language',
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

    $public_fields['published'] = array(
      'property' => 'status',
    );

    $public_fields['author'] = array(
      'property' => 'author',
      'process_callbacks' => array(array($this, 'getUser')),
    );

    return $public_fields;
  }

  /**
   * Get user.
   */
  public function getUser($value) {
    $valueOut = new \stdClass();
    $valueOut->uid = $value->uid;
    $identity = reset(_hybridauth_identity_load_by_uid($value->uid));
    if ($identity['provider_identifier']) {
      $valueOut->hid = $identity['provider_identifier'];
    }
    $valueOut->label = $value->realname;
    return $valueOut;
  }

  /**
   * Get disasters.
   */
  public function getDisasters($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $node = node_load($value);
        $tmp = new \stdClass();
        $tmp->id = $node->nid;
        $tmp->glide = $node->field_glide_number[LANGUAGE_NONE][0]['value'];
        $tmp->label = $node->title;
        if (!empty($node->field_reliefweb_id)) {
          $tmp->self = 'http://api.reliefweb.int/v1/disasters/' . $value->field_reliefweb_id[LANGUAGE_NONE][0]['value'];
        }
        $return[] = $tmp;
      }
    }
    return $return;
  }

  /**
   * Get raw body.
   */
  public function getBodyRaw($value) {
    return strip_tags($value);
  }

  /**
   * Format a date.
   */
  public function formatDate($values) {
    foreach ($values as &$value) {
      if (isset($value['date_type'])) {
        unset($value['date_type']);
      }
    }
    return $values;
  }

  /**
   * Format an address.
   */
  public function formatAddress($value) {
    unset($value['organisation_name']);
    unset($value['name_line']);
    unset($value['first_name']);
    unset($value['last_name']);
    unset($value['data']);
    return $value;
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderOptimized';
  }

}
