<?php

/**
 * @file
 * Holds methods directly related to the Views module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_pivot_views_plugins() {
  return array(
    'module' => 'views_pivot',
    'style' => array(
      'views_pivot' => array(
        'title' => t('Pivot'),
        'help' => t('Displays rows as a pivot table.'),
        'handler' => 'views_plugin_style_pivot',
        'path' => drupal_get_path('module', 'views_pivot'),
        'theme' => 'views_view_pivot_table',
        'theme file' => 'views_pivot.theme.inc',
        'theme path' => drupal_get_path('module', 'views_pivot'),
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'type' => 'normal',
      ),
    )
  );
}
