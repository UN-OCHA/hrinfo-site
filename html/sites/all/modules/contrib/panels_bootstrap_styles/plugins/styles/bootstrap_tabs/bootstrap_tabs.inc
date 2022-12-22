<?php

/**
 * @file
 * Definition of the 'bootstrap_tabs' panels style plugin.
 */

$plugin = array(
  'title' => t('Bootstrap Styles: Tabs'),
  'description' => t('The title of every pane in this region will become a horizontal tab.'),
  'render region' => 'bootstrap_panels_styles_bootstrap_tabs_render_region',
  'settings form' => 'bootstrap_panels_styles_bootstrap_tabs_settings_form',
  'weight' => -50,
);

/**
 * Render callback.
 */
function theme_bootstrap_panels_styles_bootstrap_tabs_render_region(&$variables) {
  // Remove pane titles using CSS.
  drupal_add_css(drupal_get_path('module', 'panels_bootstrap_styles') . '/plugins/styles/bootstrap_tabs/bootstrap-tabs.css', 'file');
  $output = theme('panels_bootstrap_tabs', $variables);
  return $output;
}

/**
 * Settings form.
 */
function bootstrap_panels_styles_bootstrap_tabs_settings_form($style_settings) {
  $form['help_text'] = array(
    '#markup' => t('<strong>IMPORTANT:</strong> The title of each pane will be used as the tab title.
        Ensure that you give every pane a title, otherwise you will see a message reminding you to do so.'),
  );

  $form['tab_type'] = array(
    '#title' => t('Tab type'),
    '#type' => 'select',
    '#options' => array(
      'nav-tabs' => t('Nav tabs'),
      'nav-pills' => t('Nav pills'),
    ),
    '#default_value' => (isset($style_settings['tab_type'])) ? $style_settings['tab_type'] : 'nav-tabs',
  );

  $form['tab_display'] = array(
    '#title' => t('Tab display'),
    '#type' => 'select',
    '#options' => array(
      'default' => t('Default'),
      'nav-stacked' => t('Stacked'),
      'nav-justified' => t('Justified'),
    ),
    '#default_value' => (isset($style_settings['tab_display'])) ? $style_settings['tab_display'] : 'default',
  );

  return $form;
}
