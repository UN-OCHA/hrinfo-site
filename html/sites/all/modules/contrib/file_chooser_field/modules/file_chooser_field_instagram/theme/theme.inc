<?php

/**
 * @file
 * Theme preprocess functions for the File Chooser Field Instagram module.
 */

/**
 * Preprocess function for the file-chooser-field-instagram-photos.tpl.php.
 */
function file_chooser_field_instagram_preprocess_photos(&$vars) {
  module_load_include('inc', 'file_chooser_field_instagram');

  // Instgram access token.
  $access_token = isset($_GET['access_token']) ? filter_xss($_GET['access_token']) : FALSE;

  $vars['attributes_array'] = array();
  $vars['title_attributes_array'] = array();
  $vars['content_attributes_array'] = array();
  $vars['classes_array'] = array('');

  // Module path.
  $vars['module_path'] = base_path() . drupal_get_path('module', 'file_chooser_field_instagram');

  // Instagram photos.
  $vars['photos'] = file_chooser_field_instagram_user_photos($access_token);

  // Currenly logged in user profile.
  $profile = file_chooser_field_instagram_user_profile($access_token);
  $vars['profile'] = $profile;
  $vars['counts'] = array(
    'media' => format_plural((int) $profile['counts']['media'], '1 post', '@count posts'),
    'followed_by' => format_plural((int) $profile['counts']['followed_by'], '1 follower', '@count followers'),
    'follows' => format_plural((int) $profile['counts']['follows'], '1 following', '@count following'),
  );

  // Random number to prevent css/JS caching.
  $vars['rand'] = rand(1, 234854);

  // Strings.
  $vars['title'] = t('Instagram Photo Picker');
  $vars['insert_label'] = t('Choose');
  $vars['cancel_label'] = t('Cancel');
}
