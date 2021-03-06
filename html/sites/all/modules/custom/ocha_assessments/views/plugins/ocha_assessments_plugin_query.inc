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
   * Only for hr_bundle and hr_operation.
   */
  public function execute(&$view) {
    $node = menu_get_object();
    if (empty($node)) {
      return;
    }
    $filters = '';
    switch ($node->type) {
      case 'hr_bundle':
        $filters .= 'f[0]=local_group_id:' . $node->nid;
        break;

      case 'hr_operation':
        $filters .= 'f[0]=operation_id:' . $node->nid;
        break;
    }

    $limit = variable_get('ocha_assessments_panel_display_limit', 5);
    $base_url = ocha_assessments_base_url();
    $src = $base_url . '/rest/list-data?sort=-field_date';
    if (!empty($filters)) {
      $src .= '&' . $filters;
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
          $row->title = l($item['title'], $base_url . '/assessment/' . $item['uuid'], $options);
          $view->result[] = $row;
        }
      }
    }
  }

}
