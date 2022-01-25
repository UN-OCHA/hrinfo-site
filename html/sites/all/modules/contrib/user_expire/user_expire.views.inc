<?php
/**
 * @file
 * Views integration for the User Expire module.
 */

/**
 * Implements hook_views_data().
 */
function user_expire_views_data() {
  $data['user_expire']['table']['group'] = t('User');

  $data['user_expire']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['user_expire']['expiration'] = array(
    'title' => t('Expiration date'),
    'help' => t('The date on which this account will be disabled.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}
