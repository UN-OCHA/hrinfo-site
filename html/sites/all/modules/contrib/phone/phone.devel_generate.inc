<?php
/**
 * @file
 * Provides devel generate integration.
 */

/**
 * Implements hook_devel_generate().
 */
function phone_devel_generate($object, $field, $instance, $bundle) {
  if (field_behaviors_widget('multiple values', $instance) == FIELD_BEHAVIOR_CUSTOM) {
    return devel_generate_multiple('_phone_devel_generate', $object, $field, $instance, $bundle);
  }
  else {
    return _phone_devel_generate($object, $field, $instance, $bundle);
  }
}

/**
 * Devel generate callback for phone field types.
 */
function _phone_devel_generate($object, $field, $instance, $bundle) {
  // Phone numbers are hard to randomly make up, so here is a list
  // of phone numbers for the acquia sales teams for us to randomise.
  $numbers = array(
    0 => array('countrycode' => 'US', 'number' => '855 430 7700'),
    1 => array('countrycode' => 'US', 'number' => '781 238 8600'),
    2 => array('countrycode' => 'AU', 'number' => '02 8815 8185'),
    3 => array('countrycode' => 'BH', 'number' => '3644 2719'),
    4 => array('countrycode' => 'DE', 'number' => '0221 370 502'),
    5 => array('countrycode' => 'NL', 'number' => '020 890 3987'),
    6 => array('countrycode' => 'ES', 'number' => '911 829 743'),
    7 => array('countrycode' => 'GB', 'number' => '01865 520 010'),
  );

  $known_countries = array(
    'US' => array(0, 1),
    'AU' => array(2),
    'BH' => array(3),
    'DE' => array(4),
    'NL' => array(5),
    'ES' => array(6),
    'GB' => array(7),
  );

  $settings = $instance['settings'];
  $extension = '';
  if ($settings['enable_extension']) {
    // 50/50 that we actually add an extension.
    if (rand() & 1) {
      $extension = rand(0, pow(10, $field['settings']['extension_size']) - 1);
    }
  }

  $numbertype = '';
  if ($field['settings']['enable_numbertype']) {
    $allowed_values = phone_numbertype_allowed_values($field, $instance);
    $numbertype = array_rand($allowed_values);
  }

  if (!$settings['country_options']['all_country_codes']) {
    $allowed = array_filter($settings['country_options']['country_codes']['country_selection']);
    $choices = array_intersect_key($known_countries, $allowed);
    if (empty($choices)) {
      // Can't work with these options.
      return FALSE;
    }
    $final = array();
    foreach ($choices as $items) {
      foreach ($items as $item) {
        $final[] = $numbers[$item];
      }
    }
    $numbers = $final;
  }

  $item = array_rand($numbers);
  return $numbers[$item] + array('extension' => $extension, 'numbertype' => $numbertype);
}
