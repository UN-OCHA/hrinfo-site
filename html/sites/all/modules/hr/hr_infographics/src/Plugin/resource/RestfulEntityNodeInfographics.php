<?php

namespace Drupal\hr_infographics\Plugin\resource;
use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityNodeInfographics
 * @package Drupal\hr_infographics\Plugin\resource
 *
 * @Resource(
 *   name = "infographics:1.0",
 *   resource = "infographics",
 *   label = "Infographics",
 *   description = "Infographics used for Humanitarianresponse",
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "hr_infographic"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */

class RestfulEntityNodeInfographics extends ResourceCustom implements ResourceInterface {

  /**
   * Overrides \RestfulEntityBase::publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['infographic_type'] = array(
      'property' => 'field_infographic_type',
      'resource' => array(
        'name' => 'infographic_types',
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

    $public_fields['files'] = array(
      'property' => 'field_files_collection',
      'process_callbacks' => array(array($this, 'getFiles')),
    );

    $public_fields['data_sources'] = array(
      'property' => 'field_data_sources',
      'process_callbacks' => array(array($this, 'getDataSources')),
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

    $public_fields['locations'] = array(
      'property' => 'field_locations',
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

    $public_fields['publication_date'] = array(
      'property' => 'field_publication_date',
      'process_callbacks' => array(array($this, 'formatTimestamp')),
    );

    $public_fields['themes'] = array(
      'property' => 'field_themes',
      'resource' => array(
        'name' => 'themes',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    $public_fields['related_content'] = array(
      'property' => 'field_related_content'
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
      'property' => 'language'
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

    $public_fields['exclude_from_reliefweb'] = array(
      'property' => 'field_exclude_reliefweb'
    );

    $public_fields['published'] = array(
      'property' => 'status',
    );

    $public_fields['author'] = array(
      'property' => 'author',
      'process_callbacks' => array(array($this, 'getUser'))
    );

    return $public_fields;
  }

  public function getUser($value) {
    $valueOut = new \stdClass();
    $valueOut->uid = $value->uid;
    $identities = _hybridauth_identity_load_by_uid($value->uid);
    $identity = reset($identities);
    if ($identity['provider_identifier']) {
      $valueOut->hid = $identity['provider_identifier'];
    }
    $valueOut->label = $value->realname;
    return $valueOut;
  }

  public function formatTimestamp($value) {
    return strftime('%F', $value);
  }

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
          $tmp->self = 'http://api.reliefweb.int/v1/disasters/'.$value->field_reliefweb_id[LANGUAGE_NONE][0]['value'];
        }
        $return[] = $tmp;
      }
    }
    return $return;
  }

  public function getBodyRaw($value) {
    return strip_tags($value);
  }

  public function getFiles($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new \stdClass();
        $tmp->file = new \stdClass();
        $field_file = $value->field_file[LANGUAGE_NONE][0];
        $tmp->file->fid = $field_file['fid'];
        $tmp->file->filename = $field_file['filename'];
        $tmp->file->filesize = $field_file['filesize'];
        $tmp->file->url = file_create_url($field_file['uri']);
        $tmp->file->preview = file_create_url(_pdfpreview_create_preview($tmp->file));
        if (!empty($value->field_language)) {
          $tmp->language = $value->field_language[LANGUAGE_NONE][0]['value'];
        }
        $return[] = $tmp;
      }
    }
    return $return;
  }

  public function getDataSources($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new \stdClass();
        $tmp->url = $value['url'];
        $tmp->title = $value['title'];
        $return[] = $tmp;
      }
    }
    return $return;
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\hr_api\Plugin\resource\DataProviderOptimized';
  }

}
