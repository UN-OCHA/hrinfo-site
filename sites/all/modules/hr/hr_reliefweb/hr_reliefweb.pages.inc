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

  // Fetch arguments.
  $args = arg();
  // First 3 are base url of the page.
  $page_url = implode('/', array_slice($args, 0, 3));

  // Remove first 3: node - nid - reliefweb.
  $args = array_slice($args, 3);

  // Create optional filters.
  $filters = array();
  $active_filters = array();

  if (!empty($args)) {
    for ($i = 0; $i < count($args); $i += 2) {
      $active_filters['/' . $args[$i] . '/' . $args[$i + 1]] = array(
        'name' => $args[$i],
        'value' => $args[$i + 1],
        'path' => '/' . $args[$i] . '/' . $args[$i + 1],
      );

      $filters[] = array(
        'field' => $args[$i],
        'value' => $args[$i + 1],
        'operator' => 'OR',
      );
    }
  }

  $limit = 10;

  // Do a count only query.
  $data = hr_reliefweb_fetch_documents($country_codes, 0, 0, $filters);

  // Fetch current page and do a real query.
  $current_page = pager_default_initialize($data['total'], $limit);
  $data = hr_reliefweb_fetch_documents($country_codes, $limit, $current_page * $limit, $filters);

  $headers = array(
    t('Type'),
    t('Title'),
    t('Date'),
    t('Sources'),
    t('Location'),
    t('Download'),
  );

  $rows = array();
  foreach ($data['data'] as $key => $value) {
    $downloads = array();
    if (isset($value['files'])) {
      foreach ($value['files'] as $file) {
        if (isset($file['preview']) && !empty($file['preview'])) {
          $downloads[] = '<a target="reliefweb" title="' . $file['description'] .'" href = ' . $file['url'] . '>' . theme('image', array('path' => $file['preview'])) . '</a>';
        }
        else {
          $downloads[] = '<a target="reliefweb" title="' . $file['description'] .'" href = ' . $file['url'] . '>' . t('Download !file', array('!file' => $file['filename'])) . '</a>';
        }
      }
    }
    $rows[] = array(
      isset($value['format']) ? $value['format'] : '',
      '<a target="reliefweb" href = ' . $value['url'] . '> '. $value['title'] . '</a>',
      isset($value['date_changed']) ? format_date(strtotime($value['date_changed']), 'search_api_facetapi_DAY') : '',
      isset($value['sources']) ? implode(', ', $value['sources']) : '',
      isset($value['countries']) ? implode(', ', $value['countries']) : '',
      !empty($downloads) ? implode(' ', $downloads) : '',
    );
  }

  $remove_facets = array();
  if (!empty($active_filters)) {
    $links = array();
    foreach ($active_filters as $active_filter) {
      $links[] = array(
        'title' => hr_reliefweb_get_filters($active_filter['name']) . ': ' . $active_filter['value'],
        'href' => str_replace($active_filter['path'], '', drupal_get_path_alias()),
      );
    }
    $remove_facets = array(
      '#theme' => 'links',
      '#links' => $links,
      '#heading' => 'Remove active filter',
    );
  }

  $facets = array();
  $facets_weight = 0;
  foreach ($data['facets'] as $name => $facet) {
    $links = array();
    if (isset($facet['data']) && count($facet['data']) > 1) {
      foreach ($facet['data'] as $term) {
        $filter_path = '/' . $name . '/' . $term['value'];
        if (!array_key_exists($filter_path, $active_filters)) {
          $links[] = array(
            'title' => $term['value'] . ' (' . $term['count'] . ')',
            'href' => drupal_get_path_alias() . $filter_path,
          );
        }
      }
      if (count($links) > 1) {
        $facets[] = array(
          '#theme' => 'links',
          '#links' => $links,
          '#prefix' => '<div class="reliefweb--facet"><details><summary>' . t('Filter by !name', array('!name' => hr_reliefweb_get_filters($name))) . '</summary>',
          '#suffix' => '</details></div>',
        );
      }
    }
  }

  // Set active menu item.
  menu_set_active_item('node/' . $node->nid . '/reliefweb');

  // Return page array.
  return array(
    'hr_reliefweb_overview' => array(
      '#theme' => 'hr_reliefweb_overview',

      '#contents' => array(
        '#markup' => t('Reliefweb document overview ...'),
        '#prefix' => '<div id="my_page_data">',
        '#suffix' => '</div>',
      ),

      '#summary' => array(
        '#type' => 'container',
        'total' => array(
          '#type' => 'markup',
          '#markup' => format_plural($data['total'], 'One record found', '@count records found'),
        ),
      ),

      '#clearall' => array(
        '#type' => 'container',
        'total' => array(
          '#type' => 'markup',
          '#markup' => l('Remove all filters', $page_url),
        ),
      ),

      '#removefacets' => array(
        '#type' => 'container',
        $remove_facets,
      ),

      '#facets' => array(
        '#type' => 'container',
        $facets,
      ),
      '#data' => array(
        '#theme' => 'table',
        '#header' => $headers,
        '#rows' => $rows,
        '#sticky' => FALSE,
        '#empty' => t('No documents found.'),
      ),

      '#pager' => array(
        '#theme' => 'pager',
      ),
    ),
    '#attached' => array (
      'css' => array (
        array (
          'type' => 'file',
          'data' => drupal_get_path('module', 'hr_reliefweb') . '/css/hr_reliefweb_overview.css',
        ),
      ),
      'js' => array (
        array (
          'type' => 'file',
          'data' => drupal_get_path('module', 'hr_reliefweb') . '/js/hr_reliefweb_overview.js',
        ),
      ),
    ),
  );
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
