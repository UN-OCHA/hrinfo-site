<?php
/**
 * @file
 * Administrative pages for User expire module.
 */

/**
 * View a list of all users with an expiration date.
 */
function user_expire_report() {
  $header = array(
    'username' => array(
      'data' => t('Username'),
      'field' => 'u.name',
    ),
    'access' => array(
      'data' => t('Last access'),
      'field' => 'u.access',
    ),
    'expiration' => array(
      'data' => t('Expiration'),
      'field' => 'expiration',
      'sort' => 'asc',
    ),
  );
  $rows = array();

  $query = db_select('user_expire', 'ue');
  $query->join('users', 'u', 'ue.uid = u.uid');

  $query = $query->extend('PagerDefault')->extend('TableSort');
  $query
    ->fields('u', array('uid', 'name', 'access'))
    ->fields('ue', array('expiration'))
    ->limit(50)
    ->orderByHeader($header);

  $accounts = $query->execute();

  foreach ($accounts as $account) {
    $rows[$account->uid] = array(
      'username' => theme('username', array('account' => $account)),
      'access' => $account->access ? t('@time ago', array('@time' => format_interval(REQUEST_TIME - $account->access))) : t('never'),
      'expiration' => t('@time from now', array('@time' => format_interval($account->expiration - REQUEST_TIME))),
    );
  }

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
}

/**
 * Page callback for the admin form.
 *
 * @return array|mixed
 *   A form to be rendered.
 */
function user_expire_settings_page() {
  return drupal_get_form('user_expire_settings');
}

/**
 * User expire admin settings form.
 */
function user_expire_settings($form, &$form_state) {
  // Get the rules and the roles.
  $rules = user_expire_get_role_rules();
  $roles = user_roles(TRUE);

  // Save the current roles for use in submit handler.
  $form['current_roles'] = array(
    '#type' => 'value',
    '#value' => $roles,
  );

  // Now show boxes for each role.
  $form['user_expire_roles'] = array(
    '#type' => 'fieldset',
    '#title' => t('User inactivity expire by role settings'),
    '#description' => t('Configure expiration of users by roles. Enter 0 to disable for the role. Enter 7776000 for 90 days.'),
  );

  foreach ($roles as $rid => $role) {
    $form['user_expire_roles']['user_expire_' . $rid] = array(
      '#type' => 'textfield',
      '#title' => t('Seconds of inactivity before expiring %role users', array('%role' => $role)),
      '#default_value' => isset($rules[$rid]->inactivity_period) ? $rules[$rid]->inactivity_period : 0,
    );
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Validates user expire settings.
 */
function user_expire_settings_validate($form, &$form_state) {
  foreach ($form_state['values']['current_roles'] as $rid => $role) {
    if (!ctype_digit($form_state['values']['user_expire_' . $rid])) {
      form_set_error($rid, t('Inactivity period must be an integer.'));
    }
  }
}

/**
 * Submit handler for user expire settings.
 */
function user_expire_settings_submit($form, &$form_state) {
  // Start with a beginner's mind.
  db_truncate(('user_expire_roles'))->execute();

  // Insert the rows that were inserted.
  foreach ($form_state['values']['current_roles'] as $rid => $role) {
    // Only save non-zero values.
    if (!empty($form_state['values']['user_expire_' . $rid])) {
      db_insert('user_expire_roles')
        ->fields(array('rid', 'inactivity_period'))
        ->values(array(
          'rid' => $rid,
          'inactivity_period' => (int) $form_state['values']['user_expire_' . $rid],
        ))
        ->execute();
    }
  }
}
