<?php

/**
 * @file
 * hr_users module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_users_drush_command() {
  $items = array();

  $items['hr-users-og-remove'] = array(
    'description' => "Remove group members that do not have roles",
    'arguments' => array(
    ),
    'options' => array(
    ),
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Loads all users and removes them from their group if they are only a member.
 */
function drush_hr_users_og_remove() {
  $result = db_select('users', 'u')
    ->fields('u')
    ->execute();
  while ($record = $result->fetchAssoc()) {
    $user = user_load($record['uid']);
    $groups = og_get_groups_by_user($user);
    if (!empty($groups) && !empty($groups['node'])) {
      foreach ($groups['node'] as $gid) {
        try {
          $roles = og_get_user_roles('node', $gid, $user->uid);
          if (count($roles) == 1) {
            og_ungroup('node', $gid, 'user', $user->uid);
          }
        }
        catch ($e) {
          
        }
      }
    }
  }
}
