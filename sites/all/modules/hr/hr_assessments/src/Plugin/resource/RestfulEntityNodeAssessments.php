<?php

namespace Drupal\hr_assessments\Plugin\resource;
use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeAssessments
 * @package Drupal\hr_assessments\Plugin\resource
 *
 * @Resource(
 *   name = "assessments:1.0",
 *   resource = "assessments",
 *   label = "Assessments",
 *   description = "Humanitarianresponse assessments",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_assessment"
 *     },
 *     "range" = 100,
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityNodeAssessments extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

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

    $public_fields['participating_organizations'] = array(
      'property' => 'field_organizations2',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'organizations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['locations'] = array(
      'property' => 'field_locations',
      'class' => '\Drupal\hr_api\Plugin\resource\fields\ResourceFieldEntityMinimal',
      'resource' => array(
        'name' => 'locations',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['other_location'] = array(
      'property' => 'field_asst_other_location',
    );

    $public_fields['subject'] = array(
      'property' => 'field_asst_subject',
    );

    $public_fields['methodology'] = array(
      'property' => 'field_asst_methodology',
    );

    $public_fields['key_findings'] = array(
      'property' => 'field_asst_key_findings',
    );

    $public_fields['unit_measurement'] = array(
      'property' => 'field_asst_unit',
    );

    $public_fields['collection_method'] = array(
      'property' => 'field_asst_collection_method',
    );

    $public_fields['sample_size'] = array(
      'property' => 'field_asst_sample_size',
    );

    $public_fields['geographic_level'] = array(
      'property' => 'field_level_of_representation',
    );

    $public_fields['population_types'] = array(
      'property' => 'field_population_types',
      'resource' => array(
        'name' => 'population_types',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['date'] = array(
      'property' => 'field_asst_date',
      'process_callbacks' => array(array($this, 'formatDate')),
    );

    $public_fields['frequency'] = array(
      'property' => 'field_asst_freq',
    );

    $public_fields['status'] = array(
      'property' => 'field_asst_status',
    );

    $public_fields['report'] = array(
      'property' => 'field_asst_report',
      'process_callbacks' => array(array($this, 'formatFieldCollection')),
    );

    $public_fields['questionnaire'] = array(
      'property' => 'field_asst_questionnaire',
      'process_callbacks' => array(array($this, 'formatFieldCollection')),
    );

    $public_fields['data'] = array(
      'property' => 'field_asst_data',
      'process_callbacks' => array(array($this, 'formatFieldCollection')),
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
      'sub_property' => 'uid',
      'process_callbacks' => array(array($this, 'getUser'))
    );

    return $public_fields;
  }

  public function getUser($value) {
    $valueOut = new \stdClass();
    $valueOut->uid = $value->uid;
    $valueOut->hid = _hid_profiles_get_hid_by_uid($value->uid);
    $valueOut->label = $value->realname;
    return $valueOut;
  }

  public function formatDate($value) {
    if (isset($value['value'])) {
      $value['from'] = $value['value'];
      unset($value['value']);
    }
    if (isset($value['value2'])) {
      $value['to'] = $value['value2'];
      unset($value['value2']);
    }
    if (isset($value['timezone_db'])) {
      $value['timezone'] = $value['timezone_db'];
      unset($value['timezone_db']);
    }
    if (isset($value['date_type'])) {
      unset($value['date_type']);
    }
    return $value;
  }

  public function getDisasters($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new \stdClass();
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

  public function formatFieldCollection($value) {
    $tmp = new \stdClass();
    if (!empty($value->field_asst_accessibility)) {
      $tmp->accessibility = $value->field_asst_accessibility[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($value->field_asst_file)) {
      $tmp->file = new \stdClass();
      $field_file = $value->field_asst_file[LANGUAGE_NONE][0];
      $tmp->file->fid = $field_file['fid'];
      $tmp->file->filename = $field_file['filename'];
      $tmp->file->filesize = $field_file['filesize'];
      $tmp->file->url = file_create_url($field_file['uri']);
    }
    if (!empty($value->field_asst_instructions)) {
      $tmp->instructions = $value->field_asst_instructions[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($value->field_asst_url)) {
      $tmp->url = $value->field_asst_url[LANGUAGE_NONE][0]['url'];
    }
    return $tmp;
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderOptimized';
  }

}
