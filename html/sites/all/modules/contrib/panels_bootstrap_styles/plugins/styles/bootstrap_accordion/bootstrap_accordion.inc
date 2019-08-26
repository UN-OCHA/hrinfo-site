<?php

/**
 * @file
 * Definition of the 'bootstrap_tabs' panels style plugin.
 */

$plugin = array(
  'title' => t('Bootstrap Styles: Accordion'),
  'description' => t('The title of every pane in this region will become an accordion panel.'),
  'render region' => 'bootstrap_panels_styles_bootstrap_accordion_render_region',
  'weight' => -50,
);

/**
 * Render callback.
 */
function theme_bootstrap_panels_styles_bootstrap_accordion_render_region(&$variables) {
  $output = theme('panels_bootstrap_accordion', $variables);
  return $output;
}
