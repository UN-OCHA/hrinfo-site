<?php

/**
 * @file
 * Provides token integration for the phone module.
 *
 * Implementation shamelessly based on code from the name module.
 * http://drupal.org/project/name
 */

/**
 * Implements hook_token_info().
 */
function phone_token_info($type = 'all') {
  $types = array(
    'phone' => array(
      'name' => t('Phone field values'),
      'description' => t('Phone field in the default format.'),
      'needs-data' => 'phone',
    ),
  );

  $tokens = array();
  $tokens['component-countrycode'] = array(
    'name' => t('Component: Country code'),
    'description' => t('The two digit ISO country code for this number.'),
  );
  $tokens['component-callingcode'] = array(
    'name' => t('Component: Calling code'),
    'description' => t('The international calling code for this number.'),
  );
  $tokens['component-countryname'] = array(
    'name' => t('Component: Country name'),
    'description' => t('The name of the country for this number.'),
  );
  $tokens['component-extension'] = array(
    'name' => t('Component: Extension'),
    'description' => t('The extension for this number.'),
  );
  $tokens['component-number'] = array(
    'name' => t('Component: Number'),
    'description' => t('The un-altered number as entered.'),
  );
  $tokens['component-numbertypelabel'] = array(
    'name' => t('Component: Number type Label'),
    'description' => t('The number type of this number.'),
  );
  $tokens['component-numbertype'] = array(
    'name' => t('Component: Number type'),
    'description' => t('The number type id of the number type for this number.'),
  );

  // Create some formatted tokens that include useful options.
  // We don't make one for the tel: link, as this can be done
  // quite easily with the existing tokens using the rfc3966 formatter.
  $formatters = phone_field_formatter_info();
  foreach ($formatters as $name => $info) {
    $name = str_replace('_', '-', $name);
    $tokens['formatter-' . $name] = array(
      'name' => t('Formatted name: %formatter', array('%formatter' => $info['label'])),
      'description' => $info['description'],
    );
    $tokens['formatter-no-ext-' . $name] = array(
      'name' => t('Formatted name (without extension): %formatter', array('%formatter' => $info['label'])),
      'description' => $info['description'],
    );
    $tokens['formatter-alpha-' . $name] = array(
      'name' => t('Formatted name (keep alpha components): %formatter', array('%formatter' => $info['label'])),
      'description' => $info['description'],
    );
    $tokens['formatter-alpha-no-ext-' . $name] = array(
      'name' => t('Formatted name (keep alpha components, without extension): %formatter', array('%formatter' => $info['label'])),
      'description' => $info['description'],
    );
  }

  $token_info = array(
    'types' => $types,
    'tokens' => array(
      'phone' => $tokens,
    ),
  );

  foreach (phone_token_types_chained(NULL, TRUE) as $token_type => $tokens) {
    $token_info['tokens'][$token_type] = $tokens;
  }

  return $token_info;
}

/**
 * Implements hook_tokens().
 */
function phone_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $sanitize = !empty($options['sanitize']);
  $replacements = array();

  // This handles the field tokens.
  if (isset($data[$type]) && phone_token_types_chained($type)) {
    foreach ($tokens as $name => $original) {
      if (strpos($name, 'phone-') === 0) {
        /*
         * We handle a number of different combinations here.
         * token
         * token:[delta|all]
         * token:formatter-FORMAT_NAME
         * token:[delta|all]:formatter-FORMAT_NAME
         * token:component-TYPE
         * token:[delta|all]:component-TYPE
         */
        $parts = explode(':', $name);
        $field_name = array_shift($parts);
        $field_name = str_replace('-', '_', substr($field_name, 6));

        // Ensure that this is actually a real field token before replacing.
        if ($field = field_info_field($field_name)) {
          $items = field_get_items($type, $data[$type], $field_name);
          if (empty($items)) {
            $replacements[$original] = '';
            continue;
          }

          // Find the delta value.
          $delta = NULL;
          $next = array_shift($parts);
          if (isset($next)) {
            if (is_numeric($next) && ((string) intval($next)) === (string) $next) {
              $delta = $next;
            }
            elseif ($next == 'all') {
              $delta = 'all';
            }
            else {
              // Return the value to the array for the next step.
              $delta = 0;
              array_unshift($parts, $next);
            }
          }
          else {
            $delta = 0;
          }

          if ($delta != 'all' && !isset($items[$delta])) {
            $replacements[$original] = '';
            continue;
          }

          // Find the token action and format / component.
          $action = NULL;
          $action_key = NULL;
          $no_extension = FALSE;
          $alpha = FALSE;
          if ($next = array_shift($parts)) {
            if (strpos($next, 'formatter-alpha-no-ext-') === 0) {
              $action = 'formatter';
              $action_key = substr($next, 24);
              $no_extension = TRUE;
              $alpha = TRUE;
            }
            if (strpos($next, 'formatter-alpha-') === 0) {
              $action = 'formatter';
              $action_key = substr($next, 16);
              $alpha = TRUE;
            }
            if (strpos($next, 'formatter-no-ext-') === 0) {
              $action = 'formatter';
              $action_key = substr($next, 17);
              $no_extension = TRUE;
            }
            elseif (strpos($next, 'formatter-') === 0) {
              $action = 'formatter';
              $action_key = substr($next, 10);
            }
            elseif (strpos($next, 'component-') === 0) {
              $action = 'component';
              $action_key = substr($next, 10);
            }
          }
          else {
            $action_key = 'phone_international';
            $action = 'formatter';
          }

          $formatted = array();
          if ($action == 'formatter') {
            if ($delta != 'all') {
              $items = array($items[$delta]);
            }

            foreach ($items as $item) {
              // Load libphonenumber.
              phone_libphonenumber();
              $number = $item['number'];
              $countrycode = $item['countrycode'];
              $extension = $no_extension ? '' : $item['extension'];
              $format = str_replace('-', '_', $action_key);

              $formatted[] = phone_libphonenumber_format($number, $countrycode, $extension, $format, $alpha);
            }
          }
          else {
            if ($delta != 'all') {
              $items = array($items[$delta]);
            }
            foreach ($items as $item) {
              switch ($action_key) {
                case 'countryname':
                case 'callingcode':
                  if (isset($item['countrycode'])) {
                    $formatted[] = phone_countries($item['countrycode'], ($action_key == 'countryname' ? 'country' : 'calling_code'));
                  }
                  break;

                case 'numbertypelabel':
                  if (isset($item['numbertype'])) {
                    $entity_info = entity_get_info($type);
                    $key = $entity_info['bundle keys']['bundle'];
                    $instance = field_info_instance($type, $field['field_name'], $data[$type]->$key);
                    $allowed_values = phone_numbertype_allowed_values($field, $instance);
                    if (isset($allowed_values[$item['numbertype']])) {
                      $formatted[] = $allowed_values[$item['numbertype']];
                    }
                  }
                  break;

                default:
                  if (isset($item[$action_key])) {
                    $formatted[] = $item[$action_key];
                  }
                  break;
              }
            }

          }
          $formatted = implode(', ', array_filter($formatted));
          $replacements[$original] = $sanitize ? check_plain($formatted) : $formatted;
        }
      }
    }
  }

  return $replacements;
}

/**
 * Defines a list of token types that can be chained with the phone field.
 *
 * @param mixed $type
 *   The type of token that we are working with. When NULL, works on
 *   all of them. Defaults to NULL.
 * @param bool $reset
 *   When TRUE, resets any cached data. Defaults to FALSE.
 *
 * @return array
 *   If an entity (token) type is given, returns the chained sub-list.
 */
function phone_token_types_chained($type = NULL, $reset = FALSE) {
  static $types = NULL;

  if (!isset($types) || $reset) {
    // Note that this hook contains translated strings, so each language is
    // cached separately.
    $langcode = $GLOBALS['language']->language;
    if (!$reset && $cache = cache_get("phone_token_types_chained:$langcode", 'cache')) {
      $types = $cache->data;
    }
    else {
      $types = array();
      foreach (field_info_fields() as $field_name => $info) {
        if ($info['type'] == 'phone') {
          foreach ($info['bundles'] as $entity_type => $bundles) {
            $labels = array();
            foreach ($bundles as $bundle) {
              $instance = field_info_instance($entity_type, $field_name, $bundle);
              $labels[$instance['label']] = $instance['label'];
            }
            $label = array_shift($labels);
            $clean = str_replace('_', '-', $field_name);
            if (empty($labels)) {
              $description = t('Phone field in the default format. To specify a delta value, use "@token:0". Append the other chained options after the delta value like this, "@token:0:component-number". Replace the delta value with all to obtain all items in the field like this "@token:all".',
                array('@token' => $clean));
            }
            else {
              $description = t('Phone field in the default format. Also known as %labels', array('%labels' => implode(', ', $labels)));
            }

            // Make sure we get the correct token type.
            $entity_info = entity_get_info($entity_type);
            $token_type = isset($entity_info['token type']) ? $entity_info['token type'] : $entity_type;
            $types[$token_type]['phone-' . $clean] = array(
              'name' => check_plain($label),
              'description' => $description,
              'type' => 'phone',
            );
          }
        }
      }
      cache_set("phone_token_types_chained:$langcode", $types);
    }
  }

  if (isset($type)) {
    return isset($types[$type]) ? $types[$type] : NULL;
  }

  return $types;
}
