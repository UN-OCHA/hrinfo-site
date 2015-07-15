<?php
/**
 * @file
 * Theme and preprocess functions for users.
 */

function humanitarianresponse_preprocess_user_picture(&$variables) {
  template_preprocess_user_picture($variables);
  if (empty($variables['user_picture'])) {
    $account = $variables['account'];
    if (!empty($account->uid) && user_access('access user profiles')) {
      $attributes = array(
        'attributes' => array('title' => t('View user profile.')),
        'html' => TRUE,
      );
      $variables['user_picture'] = l('<i class="fa fa-user fa-5x"></i>', 'user/'.$account->uid, $attributes);
    }
    else {
      $variables['user_picture'] = '<i class="fa fa-user fa-5x"></i>';
    }
  }
}
