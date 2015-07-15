<?php

/**
 * @file
 * hr_bundles module drush integration.
 *
 * Drush command used when bundles will be activated as full spaces
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_bundles_drush_command() {
  $items = array();

  $items['hr-bundles-as-spaces'] = array(
    'description' => "Activate bundles as spaces",
    'options' => array(
    ),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

function drush_hr_bundles_as_spaces() {
  ini_set('memory_limit', '2G');
  // Load all bundles
  $query = new EntityFieldQuery();
  $bundles = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hr_bundle')
    ->execute();
  if (isset($bundles['node'])) {
    $nids = array_keys($bundles['node']);
    foreach ($nids as $nid) {
      $bundle = node_load($nid);

      // Enable OG menu and save bundle
      if (!isset($bundle->og_menu)) {
        $bundle->og_menu = TRUE;
      }
      node_save($bundle);

      // Set variables based on the operation
      $op_gid = $bundle->{OG_AUDIENCE_FIELD}[LANGUAGE_NONE][0]['target_id'];
      // Get enabled variables
      $controller = variable_realm_controller('og');
      $enabled_variables = $controller->getEnabledVariables();
      foreach ($enabled_variables as $name) {
        $value = variable_realm_get('og', 'node_'.$op_gid, $name);
        if ($value != NULL) {
          variable_realm_set('og', 'node_'.$bundle->nid, $name, $value);
        }
      }

      // Activate default features
      $features = array(
        'hr_assessments' => 1,
        'hr_contacts' => 1,
        'hr_documents' => 1,
        'hr_events' => 1,
        'hr_infographics' => 1,
        'hr_news' => 1,
      );
      // Save the new settings
      og_features_save_feature_settings($bundle->nid, 'node', $features);
      // Alert other modules about the change
      $group = entity_load_single('node', $bundle->nid);
      module_invoke_all('og_features_toggle', $group, $bundle->nid, 'node', $features);

      // Set label of default menu link
      // Get initial menu link
      $mlid = og_menu_single_get_link_mlid('node', $bundle->nid);
      $link = menu_link_load($mlid);
      if ($link['link_title'] == 'Latest') {
        $link['link_title'] = entity_label('node', $group);
        menu_link_save($link);
      }
    }
  }
}
