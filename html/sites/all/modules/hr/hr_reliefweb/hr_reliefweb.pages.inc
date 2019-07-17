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

  // Check if it's a cluster.
  $is_cluster = $node->type == 'hr_bundle';

  $operation = $is_cluster ? $op = node_load(_hr_bundles_get_operation($node->nid)) : $node;
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
      // Date is a special case.
      if (strpos($args[$i], 'date') !== FALSE) {
        $from_to = explode(':', $args[$i + 1]);
        $active_filters['/' . $args[$i] . '/' . $args[$i + 1]] = array(
          'name' => $args[$i],
          'value' => format_date(strtotime($from_to[0]), 'custom', 'F Y'),
          'path' => '/' . $args[$i] . '/' . $args[$i + 1],
        );

        $filters[] = array(
          'field' => $args[$i],
          'value' => array(
            'from' => $from_to[0]. 'T00:00:00+00:00',
            'to' => $from_to[1] . 'T23:59:59+00:00',
          ),
          'operator' => 'AND',
        );
      }
      else {
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
  }

  // Always filter clusters.
  if ($is_cluster) {
    $filters = array_merge($filters, _hr_reliefweb_map_cluster_to_rw_filters($node));
  }

  // Handle search parameter.
  $query = NULL;
  if (isset($_GET['s']) && $_GET['s']) {
    // Be safe.
    $query = check_plain($_GET['s']);
    // Remove &quot;.
    $query = str_replace('&quot;', '', $query);
    // Search exact.
    $query = '"' . $query . '"';
  }

  $limit = 10;

  // Do a count only query.
  $data = hr_reliefweb_fetch_documents($country_codes, 0, 0, $filters, $query);

  // Fetch current page and do a real query.
  $current_page = pager_default_initialize($data['total'], $limit);
  $data = hr_reliefweb_fetch_documents($country_codes, $limit, $current_page * $limit, $filters, $query);

  $headers = array(
    t('Format'),
    t('Title'),
    t('Date'),
    t('Sources'),
    t('Download'),
  );

  $rows = array();
  foreach ($data['data'] as $key => $value) {
    $downloads = array();
    if (isset($value['files'])) {
      foreach ($value['files'] as $file) {
        if (isset($file['preview']) && !empty($file['preview'])) {
          $downloads[] = '<a target="reliefweb" class="reliefweb-tb-link" style="background-image: url(' . $file['preview'] . ')" title="' . $file['description'] .'" href = ' . $file['url'] . '><span class="sr-only">' . t('Download !file', array('!file' => $file['filename'])) . '</span></a>';
        }
        else {
          $downloads[] = '<a target="reliefweb" title="' . $file['description'] .'" href = ' . $file['url'] . '>' . t('Download !file', array('!file' => $file['filename'])) . '</a>';
        }
      }
    }

    $type_path = current_path() . "/format.name/" . $value['format'];
    $type_text = (isset($value['format']) ? $value['format'] : '');

    $rows[] = array(
      array(
        'data' => l($type_text, $type_path, array('attributes' => array('class' => 'reliefweb--doc-type-link'))),
        'class' => isset($value['format']) ? drupal_html_class('reliefweb--doc-type--' . $value['format']) : '',
      ),
      array(
        'data' => '<a target="reliefweb" href = ' . $value['url'] . '> '. $value['title'] . '</a>',
        'class' => 'reliefweb--doc-type--title',
      ),
      array(
        'data' => isset($value['date_changed']) ? format_date(strtotime($value['date_changed']), 'custom', 'd F Y') : '',
        'class' => 'reliefweb--doc-type--date',
      ),
      array(
        'data' => isset($value['sources']) ? implode(', ', $value['sources']) : '',
        'class' => 'reliefweb--doc-type--source',
      ),
      array(
        'data' => !empty($downloads) ? implode(' ', $downloads) : '',
        'class' => 'reliefweb--doc-type--download',
      ),
    );
  }

  $remove_facets = array();
  if (!empty($active_filters)) {
    $links = array();
    foreach ($active_filters as $active_filter) {
      if (hr_reliefweb_get_filters($active_filter['name'])) {
        $links[] = array(
          'title' => hr_reliefweb_get_filters($active_filter['name']) . ': ' . $active_filter['value'],
          'href' => str_replace($active_filter['path'], '', drupal_get_path_alias()),
        );
      }
    }
    $remove_facets = array(
      '#theme' => 'links',
      '#links' => $links,
      '#heading' => 'Remove active filter',
    );
  }

  $facets = array();
  $facets_weight = 0;
  $country_disasters = hr_reliefweb_fetch_disasters($country_codes);
  foreach ($data['facets'] as $name => $facet) {
    $links = array();
    if (isset($facet['data']) && count($facet['data']) > 1) {
      foreach ($facet['data'] as $term) {
        // Date is a special case.
        if (strpos($name, 'date') !== FALSE) {
          $filter_path = '/' . $name . '/' . format_date(strtotime($term['value']), 'custom', 'Y-m-d') . ':' . format_date(strtotime($term['value']), 'custom', 'Y-m-t');
        }
        else {
          $filter_path = '/' . $name . '/' . $term['value'];
        }

        // Special case filters.
        if ($name == 'disaster.name') {
          if (!in_array($term['value'], $country_disasters)) {
            continue;
          }
        }

        if (!array_key_exists($filter_path, $active_filters)) {
          // Date is a special case.
          if (strpos($name, 'date') !== FALSE) {
            if ($term['count'] > 0) {
              $links[] = array(
                'title' => format_date(strtotime($term['value']), 'custom', 'F Y') . ' (' . $term['count'] . ')',
                'href' => drupal_get_path_alias() . $filter_path,
              );
            }
          }
          else {
            $links[] = array(
              'title' => $term['value'] . ' (' . $term['count'] . ')',
              'href' => drupal_get_path_alias() . $filter_path,
            );
          }
        }
      }

      // Reverse order for date filter.
      if (strpos($name, 'date') !== FALSE) {
        $links = array_reverse($links);
      }

      if (count($links) > 1) {
        $facets[] = array(
          '#theme' => 'links',
          '#links' => $links,
          '#prefix' => '<div class="reliefweb--facet block"><details><summary>' . t('Filter by !name', array('!name' => hr_reliefweb_get_filters($name))) . '</summary>',
          '#suffix' => '</details></div>',
        );
      }
    }
  }

  // Render pager upfront, it needs the full current_path.
  $pager_html = theme('pager');

  // Set active menu item, it will override current_path.
  menu_set_active_item('node/' . $node->nid . '/reliefweb');

  // Return page array.
  return array(
    'hr_reliefweb_overview' => array(
      '#theme' => 'hr_reliefweb_overview',

      '#contents' => array(
        '#markup' => t('No intro needed ...'),
        '#access' => FALSE,
      ),

      '#summary' => array(
        '#type' => 'container',
        'total' => array(
          '#type' => 'markup',
          '#markup' => format_plural($data['total'], 'Filter: <strong>1</strong> item displayed', 'Filter: <strong>@count</strong> items displayed'),
        ),
      ),

      '#clearall' => array(
        '#type' => 'container',
        'total' => array(
          '#type' => 'markup',
          '#markup' => l('Reset all filters', $page_url),
        ),
        '#access' => count($active_filters) > 0 || !empty($query),
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
        '#markup' => $pager_html,
      ),
    ),
    '#attached' => array (
      'library' => array(
        array('chosen', 'drupal.chosen'),
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
