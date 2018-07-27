<?php
/**
 * @file
 * hr_notifications.features.inc
 */

/**
 * Implements hook_views_api().
 */
function hr_notifications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function hr_notifications_flag_default_flags() {
  $flags = array();
  // Exported flag: "Reliefweb".
  $flags['hr_reliefweb'] = array(
    'entity_type' => 'node',
    'title' => 'Reliefweb',
    'global' => 1,
    'types' => array(
      0 => 'hr_document',
      1 => 'hr_infographic',
    ),
    'flag_short' => 'Exclude from Reliefweb',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Excluded from Reliefweb',
    'link_type' => 'toggle',
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
    'show_on_form' => 1,
    'access_author' => 'own',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'hr_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
