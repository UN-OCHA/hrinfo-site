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

  $changed = 0;
  $tried = 0;
  $orphans = [];
  while ($record = $result->fetchAssoc()) {
    $term = taxonomy_term_load($record['tid']);
    $parents = taxonomy_get_parents_all($term->tid);
    if (count($parents) == 0) {
      drush_print("Parents count of zero for location with tid: " . $term->tid);
      $orphans[] = $term->tid;
    }
    if ($term->field_loc_admin_level[LANGUAGE_NONE][0]['value'] != count($parents) - 1) {
      $term->field_loc_admin_level[LANGUAGE_NONE] = array(array('value' => count($parents) - 1));
      taxonomy_term_save($term);
      $changed++;
    }
    unset($term);
    $tried++;
    // Progress indicator.
    if ($tried % 500 == 0) {
      drush_print("Updated $changed admin_levels in $tried terms.");
    }
  }
  if (!empty($orphans)) {
    drush_print("Finished. There were " . count($orphans) . "terms with no parents: " . serialize($orphans));
  }
  else {
    drush_print("Finished. There were no terms with no parents.");
  }
}
