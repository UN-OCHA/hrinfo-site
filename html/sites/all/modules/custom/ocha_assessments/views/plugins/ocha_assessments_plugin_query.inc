<?php

/**
 * @file
 * Views query plugin for Assessment Registry.
 */

/**
 * Views query plugin for Assessment Registry.
 */
class OchaAssessmentsPluginQuery extends views_plugin_query {

  /**
   * Override query.
   */
  public function query($get_count = FALSE) {
  }

  /**
   * Get results.
   *
   * Only for hr_bundle and hr_operation - by country.
   * When changing to get the data from AR, only one operation using the
   * Assessments block was not country-based. There's no match to spaces on AR.
   */
  public function execute(&$view) {
    $node = menu_get_object();
    if (empty($node)) {
      return;
    }
    $filters = '';
    switch ($node->type) {
      case 'hr_bundle':
        // @todo This isn't working. Need to add local_groups to AR.
        // @codingStandardsIgnoreLine
        //$filters .= 'f[0]=clusters_sectors:' . $node->nid;
        break;

      case 'hr_operation':
        $filters .= 'f[0]=operation_id:' . $node->nid;
        break;
    }

    $limit = variable_get('ocha_assessments_panel_display_limit', 5);
    $base_url = ocha_assessments_base_url();
    $src = $base_url . '/rest/list-data';
    if (!empty($filters)) {
      $src .= '?' . $filters;
    }

    $request = drupal_http_request($src);
    if (isset($request->data)) {
      $response = drupal_json_decode($request->data);
      if (!empty($response['search_results'])) {
        $options = array('external' => TRUE);
        // @todo Add limit to api query when we can.
        $results = array_slice($response['search_results'], 0, $limit);
        foreach ($results as $item) {
          $row = new stdClass();
          $row->title = l(reset($item['title']), $base_url . '/assessment/' . reset($item['uuid']), $options);
          $view->result[] = $row;
        }
      }
    }
  }

}
