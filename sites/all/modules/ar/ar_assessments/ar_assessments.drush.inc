<?php

/**
 * @file
 * ar_assessments module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function ar_assessments_drush_command() {
  $items = array();

  $items['ar-assessments-redirects'] = array(
    'description' => "Creates the CSV file for redirects",
    'arguments' => array(
    ),
    'options' => array(
    ),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Creates a CSV file with URL redirects.
 */
function drush_ar_assessments_redirects() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'hr_assessment', '=');
  $result = $query->execute();
  $csv = array();

  foreach ($result['node'] as $node) {
    $nid = $node->nid;
    $url = 'https://assessments.hpc.tools/api/v1.1/assessments?fields=url&filter[hrinfo_id]=' . $nid;
    $assessments = array();
    $request = drupal_http_request($url);
    if (isset($request->data)) {
      $assessments = drupal_json_decode($request->data);
      if (!empty($assessments['data'])) {
        $asst = reset($assessments['data']);
        echo 'node/' . $nid . ':' . $asst['url'];
        $csv[] = array('node/' . $nid, $asst['url']);
      }
    }
  }

  $fp = fopen('redirects.csv', 'w');
  foreach ($csv as $line) {
    fputcsv($fp, $line);
  }
  fclose($fp);
}
