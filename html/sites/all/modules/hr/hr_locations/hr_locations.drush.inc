<?php

/**
 * @file
 * Hr_locations module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @see drush_parse_command()
 */
function hr_locations_drush_command() {
  $items = array();

  $items['hr-locations-admin-levels'] = array(
    'description' => "Update location admin levels based on their number of parent terms",
    'arguments' => array(),
    'options' => array(),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Function callback.
 */
function drush_hr_locations_admin_levels() {
  // @codingStandardsIgnoreLine
  // ini_set('memory_limit', '2G');.

  $voc = taxonomy_vocabulary_machine_name_load('hr_location');

  $result = db_select('taxonomy_term_data', 't')
    ->fields('t')
    ->condition('vid', $voc->vid, '=')
    ->execute();

  while ($record = $result->fetchAssoc()) {
    $term = taxonomy_term_load($record['tid']);
    $parents = taxonomy_get_parents_all($term->tid);
    if (count($parents) == 0) {
      print "\n Parents count of zero for location with tid: " . $term->tid . "\n";
    }
    if ($term->field_loc_admin_level[LANGUAGE_NONE][0]['value'] != count($parents) - 1) {
      $term->field_loc_admin_level[LANGUAGE_NONE] = array(array('value' => count($parents) - 1));
      taxonomy_term_save($term);
    }
    unset($term);
  }
}
