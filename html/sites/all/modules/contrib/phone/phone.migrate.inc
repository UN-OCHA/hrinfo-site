<?php

/**
 * @file
 * Support for migrate module.
 *
 * With Migrate 2.4 or later, you can use the subfield syntax to set the title
 * and attributes:
 *
 * @code
 * $this->addFieldMapping('field_my_phone', 'source_number');
 * $this->addFieldMapping('field_my_phone:countrycode', 'source_countrycode');
 * $this->addFieldMapping('field_my_phone:numbertype', 'source_numbertype');
 * $this->addFieldMapping('field_my_phone:extension', 'source_extension');
 * @endcode
 *
 * With earlier versions of Migrate, you must pass an arguments array:
 *
 * @code
 * $phone_args = array(
 *   'countrycode' => array('source_field' => 'source_countrycode'),
 *   'numbertype' => array('source_field' => 'source_numbertype'),
 *   'extension' => array('source_field' => 'source_extension'),
 * );
 * $this->addFieldMapping('field_my_phone', 'source_number')
 *      ->arguments($phone_args);
 * @endcode
 */

/**
 * Implements hook_migrate_api().
 */
function phone_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array('MigratePhoneFieldHandler'),
  );
}

/**
 * Migration class for phone fields.
 */
class MigratePhoneFieldHandler extends MigrateFieldHandler {
  /**
   * Declares the types of fields used.
   */
  public function __construct() {
    $this->registerTypes(array('phone'));
  }

  /**
   * Arguments for a phone field migration.
   *
   * @param string $countrycode
   *   The countrycode for a number.
   * @param string $numbertype
   *   The number type for a number.
   * @param string $extension
   *   The extension for a number.
   * @param string $language
   *   Language of the text (defaults to destination language).
   *
   * @return array
   *   An array of all the arguments.
   */
  static function arguments($countrycode = NULL, $numbertype = NULL, $extension = NULL, $language = NULL) {
    $arguments = array();
    foreach (array('countrycode', 'numbertype', 'extension', 'language') as $field) {
      if (isset($$field)) {
        $arguments[$field] = $$field;
      }
    }

    return $arguments;
  }

  /**
   * Implementation of MigrateFieldHandler::fields().
   *
   * @param string $type
   *   The field type.
   * @param string $parent_field
   *   Name of the parent field.
   * @param Migration $migration
   *   The migration context for the parent field. We can look at the mappings
   *   and determine which subfields are relevant.
   *
   * @return array
   *   The array of subfields we support.
   */
  public function fields($type, $parent_field, $migration = NULL) {
    $fields = array(
      'countrycode' => t('Subfield: The phone countrycode attribute'),
      'numbertype' => t('Subfield: The phone number type'),
      'extension' => t('Subfield: The phone extension'),
      'language' => t('Subfield: Language for the field'),
    );

    return $fields;
  }

  /**
   * Converts incoming data into the proper field arrays for Phone fields.
   *
   * @param object $entity
   *   The destination entity which will hold the field arrays.
   * @param array $field_info
   *   Metadata for the date field being populated.
   * @param array $instance
   *   Metadata for this instance of the date field being populated.
   * @param array $values
   *   Array of date values to be fielded.
   *
   * @return array|null
   *   An array of date fields.
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    if (isset($values['arguments'])) {
      $arguments = $values['arguments'];
      unset($values['arguments']);
    }
    else {
      $arguments = array();
    }

    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    // Setup the standard Field API array for saving.
    $delta = 0;
    foreach ($values as $number) {
      $item = array();
      if (isset($arguments['countrycode'])) {
        if (is_array($arguments['countrycode'])) {
          $item['countrycode'] = $arguments['countrycode'][$delta];
        }
        else {
          $item['countrycode'] = $arguments['countrycode'];
        }
      }
      if (isset($arguments['numbertype'])) {
        if (is_array($arguments['numbertype'])) {
          $item['numbertype'] = $arguments['numbertype'][$delta];
        }
        else {
          $item['numbertype'] = $arguments['numbertype'];
        }
      }
      if (isset($arguments['extension'])) {
        if (is_array($arguments['extension'])) {
          $item['extension'] = $arguments['extension'][$delta];
        }
        else {
          $item['extension'] = $arguments['extension'];
        }
      }

      $item['number'] = $number;

      if (is_array($language)) {
        $current_language = $language[$delta];
      }
      else {
        $current_language = $language;
      }
      $return[$current_language][] = $item;
      $delta++;
    }

    return isset($return) ? $return : NULL;
  }
}
