<?php
/**
 * @file
 * Implements Feeds support for Phone fields.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets()
 */
function phone_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'phone') {
      $targets[$name] = array(
        'name' => t('@name: Number (single field)', array('@name' => $instance['label'])),
        'callback' => 'phone_feeds_set_target',
        'description' => t('The @label field of the entity.  Use if the entire number (country code, number, and extension) are provided in a single field.', array('@label' => $instance['label'])),
      );
      if (array_key_exists('countrycode', $info['columns'])) {
        $targets[$name . ':countrycode'] = array(
          'name' => t('@name: Country Code', array('@name' => $instance['label'])),
          'callback' => 'phone_feeds_set_target',
          'description' => t('The country code for a @label field of the entity, providing the two-letter code of the phone number\'s country.', array('@label' => $instance['label'])),
          'real_target' => $name,
        );
      }
      if (array_key_exists('number', $info['columns'])) {
        $targets[$name . ':number'] = array(
          'name' => t('@name: Number', array('@name' => $instance['label'])),
          'callback' => 'phone_feeds_set_target',
          'description' => t('The national number for a @label field of the entity, without any country information or extension.', array('@label' => $instance['label'])),
          'real_target' => $name,
        );
      }
      if (array_key_exists('numbertype', $info['columns'])) {
        $targets[$name . ':numbertype'] = array(
          'name' => t('@name: Number type', array('@name' => $instance['label'])),
          'callback' => 'phone_feeds_set_target',
          'description' => t('The number type for a @label field of the entity, providing the hcard telephone type.', array('@label' => $instance['label'])),
          'real_target' => $name,
        );
      }
      if (array_key_exists('extension', $info['columns'])) {
        $targets[$name . ':extension'] = array(
          'name' => t('@name: Extension', array('@name' => $instance['label'])),
          'callback' => 'phone_feeds_set_target',
          'description' => t('The extension for a @label field of the entity.', array('@label' => $instance['label'])),
          'real_target' => $name,
        );
      }
    }
  }
}

/**
 * Callback for mapping. Here is where the actual mapping happens.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 */
function phone_feeds_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = array($value);
  }

  // Iterate over all values.
  list($field_name, $column) = explode(':', $target);
  if (strpos($target, ':')===FALSE) {
    $field_name = $target;
    $column = NULL;
  }
  else {
    list($field_name, $column) = explode(':', $target);
  }
  $info = field_info_field($field_name);

  $field = isset($entity->$field_name) ? $entity->$field_name : array();
  $delta = 0;

  foreach ($value as $v) {
    if (is_object($v) && ($v instanceof FeedsElement)) {
      $v = $v->getValue();
    }

    if (is_scalar($v)) {
      if (!isset($column)) {
      // Convert whole number into components.
        $item = _phone_migrate_phone_number($v);
        foreach ($item as $column => $sub_value) {
          $field[LANGUAGE_NONE][$delta][$column] = $sub_value;
        }
      }
      else {
        if ($column == 'countrycode') {
	  // Note: allowing non-allowed countries through here, to avoid
	  // data loss.  Any attempt to edit the field will force user
	  // to change the data
	  // @todo: is this what should be done for feeds?  Should there
	  // be a setting allowing user to determine whether to apply
	  // strict standards?
	  $v = strtoupper($v);
          $country_info = phone_countries($v);
          if (empty($country_info)) {
            $v = NULL;
	  }
        }
        elseif ($column == 'number' || $column == 'extension') {
          // Strip all non-numbers from number/extension.
	  // @todo: Does this need to be changed to allow vanity numbers?
          $v = preg_replace('/[^\d]/', '', $v);
        }
	elseif ($column == 'numbertype') {
	  // @todo: needs to check that numbertype is an hcard type,
	  // convert to match the case being used in module, and
	  // combine multiple values using appropriate separator
	}

        $field[LANGUAGE_NONE][$delta][$column] = $v;
      }
    }

    $delta++;
    if ($info['cardinality'] != FIELD_CARDINALITY_UNLIMITED && $delta >= $info['cardinality']) {
      break;
    }

  }

  $entity->$field_name = $field;
}
