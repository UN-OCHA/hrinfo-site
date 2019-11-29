<?php

/**
 * @file
 * Contains the test source plugin with html.
 */

class TMGMTTestHTMLSourcePluginController extends TMGMTTestSourcePluginController {

  /**
   * {@inheritdoc}
   */
  public function getData(TMGMTJobItem $job_item) {
    return array(
      'dummy' => array(
        'deep_nesting' => array(
          '#text' => file_get_contents(drupal_get_path('module', 'tmgmt') . '/tests/testing_html/sample.html'),
          '#label' => 'Label for job item with type ' . $job_item->item_type . ' and id ' . $job_item->item_id . '.',
        ),
      ),
    );
  }
}
