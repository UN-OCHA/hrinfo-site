<?php

/**
 * @file Menu callbacks for the hdx datasets module.
 */


/**
 * Callback that renders the HDX datasets.
 */
function hdx_datasets_list_callback($node) {
  // Make sure that the og single menu is not displayed.
  context_set('context', 'hr_space_menu', FALSE);

  $templates = array(
    'hdx_datasets_list_view',
  );
  foreach ($templates as $template) {
    hdx_datasets_load_template($template, $template);
  }

  $operation = $node->type == 'hr_bundle' ? $op = node_load(_hr_bundles_get_operation($node->nid)) : $node;
  $operation_wrapper = entity_metadata_wrapper('node', $operation);

  $country_codes = array();
  // Get the country code directly from the operation.
  if ($country_code = hdx_datasets_get_country_from_operation(
    $operation_wrapper
  )
  ) {
    $country_codes[] = $country_code;
  }

  // Otherwise, it could be a region spread in multiple countries.
  if (empty($country_codes)) {
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'hr_operation')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition(
        'field_operation_region',
        'target_id',
        $operation_wrapper->getIdentifier()
      )
      ->execute();
    if (!empty($results['node'])) {
      $regions = node_load_multiple(array_keys($results['node']));
      foreach ($regions as $region) {
        $region_wrapper = entity_metadata_wrapper('node', $region);
        $country_codes[] = hdx_datasets_get_country_from_operation(
          $region_wrapper
        );
      }
    }
  }

  // Expose the settings in the js files.
  $settings = array();
  if (!empty($country_codes)) {
    $settings['country_codes'] = $country_codes;
    $dates = date_month_names_abbr();
    $settings['month'] = array_map('strtoupper', $dates);
  }

  return array(
    '#theme' => 'hdx_datasets_list',
    '#attached' => array(
      'js' => array(
        '//cdnjs.cloudflare.com/ajax/libs/underscore.js/1.8.2/underscore-min.js' => array('type' => 'external'),
        '//cdnjs.cloudflare.com/ajax/libs/backbone.js/1.1.2/backbone-min.js' => array('type' => 'external'),
        drupal_get_path('module', 'hdx_datasets') . '/js/hdx_datasets.js',
        array(
          'data' => array('hdx_datasets' => $settings),
          'type' => 'setting'
        ),
      )
    ),
  );
}

/**
 * Helper function to get the iso2 code from an operation.
 */
function hdx_datasets_get_country_from_operation($wrapper) {
  if (isset($wrapper->field_country) && isset($wrapper->field_country->field_pcode)) {
    $iso2 = $wrapper->field_country->field_pcode->value();
    $country_codes = hdx_datasets_get_country_codes();
    return drupal_strtolower($country_codes[$iso2]);
  }

  return '';
}
