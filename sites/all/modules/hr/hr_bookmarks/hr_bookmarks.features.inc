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
  // Exported flag: "Pinned Space".
  $flags['hr_favorite_space'] = array(
    'entity_type' => 'node',
    'title' => 'Pinned Space',
    'global' => 0,
    'types' => array(
      0 => 'hr_operation',
      1 => 'hr_sector',
      2 => 'hr_space',
    ),
    'flag_short' => '',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => FALSE,
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
