<?php
/**
 * @file
 * Adds support for User Points.
 * Supplemental include loaded via usermerge_load_includes().
 */

/**
 * Implements hook_usermerge_actions_supported() on behalf of userpoints.
 */
function userpoints_usermerge_actions_supported() {
  return array(
    'userpoints' => t('Choosing to keep or merge points assigned by the User Points module.')
  );
}

/**
 * Implements hook_usermerge_account_properties() on behalf of userpoints.
 */
function userpoints_usermerge_account_properties($user_to_delete, $user_to_keep, $action) {
  $account_properties['userpoints'] = array(
    'title' => t('Userpoints'),
    'items' => array(
      'userpoints' => array(
        'name' => 'userpoints',
        'criterion' => 'merge'
      )
    )
  );

  return $account_properties;
}

/**
 * Implements hook_usermerge_build_review_form_elements() on behalf of userpoints.
 */
function userpoints_usermerge_build_review_form_elements($review, $account_properties, $user_to_delete, $user_to_keep) {
  $points_user_to_delete = userpoints_get_current_points($user_to_delete->uid,'all');
  $points_user_to_keep = userpoints_get_current_points($user_to_keep->uid,'all');

  $properties = $account_properties['userpoints'];

  $review['userpoints'] = array(
    '#tree' => TRUE,
    '#theme' => 'usermerge_data_review_form_table',
    '#title' => $properties['title'],
    'userpoints' => array(
      'property_name' => array(
        '#type' => 'markup',
        '#markup' => t('User Points'),
      ),
      'options' => array(
        '#type' => 'radios',
        '#options' => array(
          'user_to_delete' => $points_user_to_delete,
          'user_to_keep' => $points_user_to_keep,
          'merge' => 'merge'
        ),
        '#default_value' => 'merge'
      )
    ),
  );

  if (isset($properties['description'])) {
    $review['userpoints']['#description'] = $properties['description'];
  }

  return $review;
}

/**
 * Implements hook_usermerge_merge_accounts() on behalf of userpoints.
 */
function userpoints_usermerge_merge_accounts($user_to_delete, $user_to_keep, $review) {
  $points_to_keep = $review['userpoints']['userpoints']['options'];

  if ($points_to_keep == 'merge') {
    $query = db_update('userpoints_txn')
      ->fields(array(
        'uid' => $user_to_keep->uid
      ))
      ->condition('uid', $user_to_delete->uid)
      ->execute();
    // Force userpoints module to update it's totals now that the transaction table
    // has changed.
    _userpoints_regenerate_counts_uid($user_to_keep->uid);
    _userpoints_regenerate_counts_uid($user_to_delete->uid);
  }
  else {
    $points_to_delete = $points_to_keep == 'user_to_keep' ? 'user_to_delete' : 'user_to_keep';
    $query_delete = db_delete('userpoints_txn')
      ->condition('uid', $$points_to_delete->uid)
      ->execute();
    // Force userpoints module to update it's totals now that the transaction table
    // has changed.
    _userpoints_regenerate_counts_uid($$points_to_delete->uid);
  }
}

/**
 * Regenerates the points tables based off of the userpoints_txn table,
 * and the $uid argument, so it doesn't do the whole table as
 * userpoints_regenerate_counts() does.
 */
function _userpoints_regenerate_counts_uid($uid) {
  $userpoints_total_query = "SELECT uid, MAX(changed) AS last_updated,
    SUM(points) AS points, SUM(points) AS max_points
      FROM {userpoints_txn}
      WHERE uid = :uid
      GROUP BY uid";

  $results = db_query($userpoints_total_query, array(':uid' => $uid))->fetchAll();

  // Handle case where the user no longer has any transactions.
  if (0 == count($results)) {
    db_delete('userpoints_total')
      ->condition('uid',$uid)
      ->execute();
  }

  $userpoints_total_replace_query = "REPLACE INTO {userpoints_total} (uid, points, max_points, last_update)
    VALUES (:uid, :points, :max_points, :last_update)";

  foreach ($results as $row) {
    $res = db_query($userpoints_total_replace_query, array(
      ':uid'         => $row->uid,
      ':points'      => $row->points,
      ':max_points'  => $row->max_points,
      ':last_update' => $row->last_updated,
    ));
  }

  $userpoints_query = "SELECT uid, MAX(changed) AS last_updated,
    SUM(points) AS points, SUM(points) AS max_points, tid
      FROM userpoints_txn
      WHERE uid = :uid
      GROUP BY uid, tid";

  $results = db_query($userpoints_query, array(':uid' => $uid))->fetchAll();

  // Handle case where the user no longer has any transactions.
  if (0 == count($results)) {
    db_delete('userpoints')
      ->condition('uid',$uid)
      ->execute();
  }

  $userpoints_replace_query = "REPLACE INTO {userpoints} (uid, points, max_points, last_update, tid)
    VALUES (:uid, :points, :max_points, :last_update, :tid)";

  foreach ($results as $row) {
    $res = db_query($userpoints_replace_query, array(
      ':uid'         => $row->uid,
      ':points'      => $row->points,
      ':max_points'  => $row->max_points,
      ':last_update' => $row->last_updated,
      ':tid'         => $row->tid,
    ));
  }
}
