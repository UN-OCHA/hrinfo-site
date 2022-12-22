<?php

/**
 * @file
 * Helper functions.
 */

define('FCF_INSTAGRAM_API', 'https://api.instagram.com/v1');

/**
 * Get recursive photos.
 */
function file_chooser_field_instagram_user_photos_all($url, $limit) {
  $photos = &drupal_static(__FUNCTION__);
  $request = drupal_http_request($url);
  $media = drupal_json_decode($request->data);
  if (!empty($media['data'])) {
    foreach ($media['data'] as $item) {
      if (isset($item['images'])) {
        $photos[] = array(
          'id'                  => $item['id'],
          'thumbnail'           => $item['images']['thumbnail'],
          'standard_resolution' => $item['images']['standard_resolution'],
          'likes'               => $item['likes']['count'],
          'filter'              => $item['filter'],
          'created_time'        => $item['created_time'],
          'location'            => isset($item['location']['name']),
        );
      }
    }
  }
  if (count($photos) <= $limit && !empty($media['pagination']['next_url'])) {
    // Walk through all pages.
    return file_chooser_field_instagram_user_photos_all(
      $media['pagination']['next_url'], 
      $limit
    );
  }
  else {
    return $photos;
  }
}

/**
 * Get all user photos.
 */
function file_chooser_field_instagram_user_photos($access_token) {

  $limit = variable_get('file_chooser_field_instagram_photos_limit', 200);

  $photos = array();

  if ($access_token) {
    // Get the most recent media published by a user.
    $photos = file_chooser_field_instagram_user_photos_all(
      FCF_INSTAGRAM_API . '/users/self/media/recent/?access_token=' . $access_token
      . '&count=' . $limit,
      $limit
    );
  }

  return $photos;

}

/**
 * Profile information.
 */
function file_chooser_field_instagram_user_profile($access_token) {
  if ($access_token) {
    // Get the most recent media published by a user.
    $request = drupal_http_request(FCF_INSTAGRAM_API . '/users/self/?access_token=' . $access_token);
    $data = drupal_json_decode($request->data);
    if (!empty($data['data']['username'])) {
      return $data['data'];
    }
  }
  return FALSE;
}
