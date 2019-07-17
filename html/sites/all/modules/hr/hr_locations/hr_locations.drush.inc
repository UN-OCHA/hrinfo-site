<?php

/**
 * @file
 * hr_locations module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_locations_drush_command() {
  $items = array();

  $items['hr-locations-admin-levels'] = array(
    'description' => "Update location admin levels based on their number of parent terms",
    'arguments' => array(
    ),
    'options' => array(
    ),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}


function drush_hr_locations_admin_levels() {
  //ini_set('memory_limit', '2G');

  $voc = taxonomy_vocabulary_machine_name_load('hr_location');

  $result = db_select('taxonomy_term_data', 't')
      ->fields('t')
      ->condition('vid', $voc->vid, '=')
      ->execute();

  while ($record = $result->fetchAssoc()) {
    $term = taxonomy_term_load($record['tid']);
    $parents = taxonomy_get_parents_all($term->tid);
    $term->field_loc_admin_level[LANGUAGE_NONE] = array(array('value' => count($parents)-1));
    taxonomy_term_save($term);
    unset($term);
  }
}
