<?php

$expire_time = REQUEST_TIME - 60 * 60 * 24 * 180;
$sql = "select distinct u.uid, name from {users} u inner join {og_users_roles} o on u.uid = o.uid where access < :expire_time limit 10;";
$query = db_query($sql, array(
  ':expire_time' => $expire_time,
));
$data = $query->fetchAllAssoc('uid');

$mids = array();
foreach ($data as $row) {
  $uid = $row->uid;
  $name = $row->name;
  drush_log('Removing all memberships of ' . $name . ' (' . $uid . ')');
  $account = user_load($uid);

  $groups = og_get_groups_by_user($account);
  if ($groups) {
    foreach ($groups as $group_type => $gids) {
      foreach ($gids as $gid) {
        // Load membership.
        $membership = og_get_membership($group_type, $gid, 'user', $uid);
        if ($membership) {
          $mids[$membership->id] = $membership->id;
        }
      }
    }
  }

  // Remove stale records in the {og_users_roles} table.
  db_delete('og_users_roles')
    ->condition('uid', $uid)
    ->execute();

  // Remove all roles from user.
  user_save($account, array('roles' => array(
    '2' => 'authenticated user',
  )));
}

og_membership_delete_multiple($mids);
