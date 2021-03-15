<?php

/**
 * @file
 * Views query plugin for Assessment Registry.
 */

/**
 * Views query plugin for Assessment Registry.
 */
class ocha_assessments_plugin_query extends views_plugin_query {

  /**
   * Override query.
   */
  function query($get_count = FALSE) {
  }

  /**
   * Get results.
   *
   * Only for hr_bundle and hr_operation - by country.
   * When changing to get the data from AR, only one operation using the
   * Assessments block was not country-based. There's no match to spaces on AR.
   */
  function execute(&$view) {
    $node = menu_get_object();
    if (empty($node)) {
      return;
    }
    $filters = '';
    switch ($node->type) {
      case 'hr_bundle':
        $filters .= 'f[0]=clusters_sectors:' . $node->nid;
        break;

      case 'hr_operation':
        if (!empty($node->field_country[LANGUAGE_NONE])) {
          $filters .= 'f[0]=locations:' . $node->field_country[LANGUAGE_NONE][0]['target_id'];
        }
        else {
          return;
        }
        break;
    }

    $limit = variable_get('ocha_assessments_panel_display_limit', 5);
    $base_url = ocha_assessments_base_url();
    $src = $base_url . '/rest/assessments?items_per_page=' . $limit;
    if (!empty($filters)) {
      $src .= '&' . $filters;
    }

    $request = drupal_http_request($src);
    if (isset($request->data)) {
      $response = drupal_json_decode($request->data);
      if (!empty($response['search_results'])) {
        $options = array('external' => TRUE);
        foreach ($response['search_results'] as $item) {
          $row = new stdClass();
          $row->title = l($item['title'], $base_url . '/node/' . $item['nid'], $options);
          $view->result[] = $row;
        }
      }
    }
  }

}
