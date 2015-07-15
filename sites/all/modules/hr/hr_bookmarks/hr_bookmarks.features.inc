<?php
/**
 * @file
 * hr_bookmarks.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function hr_bookmarks_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorite Space".
  $flags['hr_favorite_space'] = array(
    'entity_type' => 'node',
    'title' => 'Pinned Space',
    'global' => 0,
    'types' => array(
      0 => 'hr_operation',
      1 => 'hr_sector',
      2 => 'hr_space',
    ),
    'flag_short' => 'Pin this space',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove this space',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'ical' => 0,
      'diff_standard' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'hr_bookmarks',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
