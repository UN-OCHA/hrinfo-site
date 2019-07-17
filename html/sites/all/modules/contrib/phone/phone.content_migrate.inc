<?php
/**
 * @file
 * Functions specifically to support the content_migrate package used within
 * CCK to do Drupal6 to Drupal7 migration of fields.
 *
 * This includes support for migrating both phone-6.x and cck_phone-6.x fields.
 *
 * Note that the migrate module is supported by a separate file,
 * phone.migrate.inc.
 */

/**
 * Implements hook_content_migrate_field_alter().
 *
 * Alter the field definition of D6 fields.
 */
function phone_content_migrate_field_alter(&$field_value, $instance_value) {
  // content_migrate takes care of creating new tables with current schema
  if ($instance_value['widget']['module']=='phone') {
    // No changes to field-level settings necessary for D6-phone migration.
  }
  elseif ($instance_value['widget']['module']=='cck_phone') {
    // Update name of module for D6-cck_phone migration.
    $field_value['messages'][] = t("Changed field type: The '@field' field type will be changed from '@type' to 'phone'.", array('@type' => $field_value['type'], '@field' => $field_value['field_name']));
    $field_value['module'] = 'phone';
    $field_value['type'] = 'phone';
  }
}

/**
 * Implements hook_content_migrate_instance_alter().
 *
 * Alter the instance definition of D6 fields.
 */
function phone_content_migrate_instance_alter(&$instance_value, $field_value) {
  if ($instance_value['widget']['module']=='phone') {
    $orig_country = $field_value['settings']['country'];
    $country = _phone_update_phone_country($orig_country);

    _phone_update_phone_instance_settings($instance_value, array('orig' => $orig_country, 'new' => $country));
  }
  elseif ($instance_value['widget']['module']=='cck_phone') {
    _phone_update_cck_phone_instance_settings($instance_value);
  }
}

/**
 * Implements hook_content_migrate_field_alter().
 *
 * Alter the data records of D6 fields.
 */
function phone_content_migrate_data_record_alter(&$record, $field, $instance) {
  // The processing here for cck_phone fields is actually overkill.
  // Really all that needs to be done is update the country code,
  // however opting to put phone and cck_phone through the same
  // type of processing.
  if ($field['type']=='phone' || $field['type']=='cck_phone') {
    $field_name = $field['field_name'];
    if (!empty($record[$field_name . '_value'])) {
      // phone-6.x
      $number = $record[$field_name . '_value'];
      unset($record[$field_name . '_value']);
    }
    else {
      // cck_phone-6.x
      $number = $record[$field_name . '_number'];
    }
    if (!empty($record[$field_name . '_country_codes'])) {
      // country_codes only exists if this is a cck_phone-6.x field
      $countrycode = _phone_update_cck_phone_country($record[$field_name . '_country_codes']);
      // Change from 'country_codes' to 'countrycode'
      unset($record[$field_name . '_country_codes']);
      $record[$field_name . '_countrycode'] = $country_code;
    }
    else {
      $countrycode = $instance['settings']['default_country'];
    }
    $newvals = _phone_migrate_phone_number($number, $countrycode);
    // Note that for cck_phone-6.x fields with an extension, the existing
    // value is left unchanged (extension only exists in $newvals if the
    // number entry contained an extension).
    foreach ($newvals as $valname => $value) {
      $record[$field_name . '_' . $valname] = $value;
    }
    // Don't migrate empty records
    if (empty($record[$field_name . '_number'])) {
      $record = NULL;
    }
  }
}

