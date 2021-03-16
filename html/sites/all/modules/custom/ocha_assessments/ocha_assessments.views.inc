<?php

/**
 * @file
 * Views plugin for Assessment Registry.
 */

/**
 * Implements hook_views_plugins().
 */
function ocha_assessments_views_plugins() {
  $plugin = array();
  $plugin['query']['ocha_assessments_plugin_query'] = array(
    'title' => t('Assessment Registry Query'),
    'handler' => 'OchaAssessmentsPluginQuery',
  );

  return $plugin;
}

/**
 * Implements hook_views_data().
 */
function ocha_assessments_views_data() {
  $data = array();

  $data['ocha_assessments']['table']['group'] = t('OCHA Assessments');
  $data['ocha_assessments']['table']['base'] = array(
    'title' => t('OCHA Assessments'),
    'help' => t('Data from Assessment Registry'),
    'query class' => 'ocha_assessments_plugin_query',
  );

  // Fields.
  $data['ocha_assessments']['title'] = array(
    'title' => t('Title'),
    'field' => array(
      'handler' => 'OchaAssessmentsHandlerField',
    ),
  );

  return $data;
}
