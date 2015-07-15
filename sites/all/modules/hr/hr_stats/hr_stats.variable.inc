<?php

/**
 * @file
 * Definition of variables for Variable API module.
 */

/**
 * Implements hook_variable_info().
 */
function hr_stats_variable_info($options) {
  $variables['hr_stats_piwik_segment'] = array(
    'type' => 'select',
    'title' => t('Piwik segment', array(), $options),
    'default' => '',
    'description' => t('The Piwik segment.'),
    'options callback' => 'hr_stats_get_piwik_segments',
  );

  return $variables;
}

