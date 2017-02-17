<?php

/**
 * @file Menu callbacks for the reliefweb.
 */

/**
 * Callback that renders the document list.
 */
function hr_reliefweb_document_list($node) {
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
  if ($country_code = hr_reliefweb_get_country_from_operation($operation_wrapper)) {
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
        $country_codes[] = hr_reliefweb_get_country_from_operation($region_wrapper);
      }
    }
  }

  $result = hr_reliefweb_fetch_documents($country_codes, 10);

  $headers = array(
    t('Type'),
    t('Title'),
    t('Date'),
    t('Sources'),
    t('Location'),
    t('Download'),
  );

  $rows = array();
  foreach ($result as $key => $value) {
    $downloads = array();
    if (isset($value['files'])) {
      foreach ($value['files'] as $file) {
        if (isset($file['preview'])) {
          $downloads[] = '<a target="reliefweb" href = ' . $file['url'] . '>' . theme('image', array('path' => $file['preview'])) . '</a>';
        }
        else {
          $downloads[] = '<a target="reliefweb" href = ' . $file['url'] . '>' . t('Download') . '</a>';
        }
      }
    }
    $rows[] = array(
      isset($value['format']) ? $value['format'] : '',
      '<a target="reliefweb" href = ' . $value['url'] . '> '. $value['title'] . '</a>',
      isset($value['date_changed']) ? format_date(strtotime($value['date_changed']), 'search_api_facetapi_DAY') : '',
      isset($value['sources']) ? implode(', ', $value['sources']) : '',
      isset($value['countries']) ? implode(', ', $value['countries']) : '',
      !empty($downloads) ? implode(', ', $downloads) : '',
    );
  }

  return theme('table', array(
    'header' => $headers,
    'rows' => $rows,
    'sticky' => TRUE,
    'empty' => t('No open vacancies currently available.'),
  ));

}

/**
 * Helper function to get the iso2 code from an operation.
 */
function hr_reliefweb_get_country_from_operation($wrapper) {
  if (isset($wrapper->field_country) && isset($wrapper->field_country->field_pcode)) {
    $iso2 = $wrapper->field_country->field_pcode->value();
    $country_codes = hdx_datasets_get_country_codes();
    return drupal_strtolower($country_codes[$iso2]);
  }

  return '';
}
