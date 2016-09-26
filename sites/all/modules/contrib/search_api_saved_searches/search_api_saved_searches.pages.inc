<?php

/**
 * @file
 * User UI functions and form callbacks for saved searches.
 */

/**
 * Page callback for listing all saved searches of a user.
 *
 * @param $account
 *   The user of which to list saved searches.
 */
function search_api_saved_searches_user_listing($account) {
  $base_path = 'search-api/saved-search/';
  $header = array(
    t('Name'),
    t('Created'),
    t('Last executed'),
    t('Interval'),
    t('Operations'),
  );
  $searches = search_api_saved_search_load_multiple(FALSE, array('uid' => $account->uid));
  $rows = array();
  foreach ($searches as $search) {
    $settings = $search->settings();
    if (empty($search->options['page'])) {
      $name = check_plain($search->name);
    }
    else {
      $name = $search->l($search->name);
    }
    $created = format_date($search->created, 'short');
    $last_execute = t('@time ago', array('@time' => format_interval(REQUEST_TIME - $search->last_execute)));

    // Get the translated label for the interval.
    $available_intervals = $settings->getTranslatedOption('interval_options');
    if (isset($available_intervals[$search->notify_interval])) {
      $interval = $available_intervals[$search->notify_interval];
    }
    elseif ($search->notify_interval < 0) {
      $interval = t('Never');
    }
    else {
      $interval = format_interval($search->notify_interval, 1);
    }

    $enable_options['attributes']['class'][] = 'saved-search-enable';
    $edit_options['attributes']['class'][] = 'saved-search-edit';
    $delete_options['attributes']['class'][] = 'saved-search-delete';

    if ($search->enabled) {
      $enable_action = '/disable';
      $enable_label = t('disable');
    }
    else {
      $enable_action = '/enable';
      $enable_label = t('enable');
      $enable_options['query']['token'] = drupal_get_token($search->id);
    }

    $path = $base_path . $search->id;
    $enable_link = l($enable_label, $path . $enable_action, $enable_options);
    $edit_link = l(t('edit'), $path . '/edit', $edit_options);
    $delete_link = l(t('delete'), $path . '/delete', $delete_options);
    $rows[] = array(
      $name,
      $created,
      $last_execute,
      $interval,
      $enable_link . ' | ' . $edit_link . ' | ' . $delete_link,
    );
  }

  $render = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No searches were saved yet.'),
    '#sticky' => TRUE,
  );
  return $render;
}

/**
 * Page callback for manually creating a new saved search.
 *
 * @param SearchApiSavedSearchesSettings $settings
 *   (optional) The settings to use. If not present, either the only available
 *   settings will be used, or a form for selecting one will be displayed.
 */
function search_api_saved_searches_create_manual(SearchApiSavedSearchesSettings $settings = NULL) {
  if (!isset($settings)) {
    foreach (search_api_saved_searches_settings_load_multiple(FALSE, array('enabled' => TRUE)) as $settings) {
      if (!empty($settings->options['manual']['allow'])) {
        $available_settings[$settings->delta] = $settings;
      }
    }
    if (empty($available_settings)) {
      return t('There are no searches for which saved searches can be created manually.');
    }
    if (count($available_settings) == 1) {
      $settings = reset($available_settings);
    }
    else {
      $render = array();
      $render['question']['#markup'] = t('For which search do you want to create a saved search?');
      $render['list']['#theme'] = 'list';
      $render['list']['#items'] = array();
      $base = 'search-api/saved-searches/add/';
      foreach ($available_settings as $id => $settings) {
        $name = $settings->index()->name;
        if (!empty($settings->options['manual']['page']['path'])) {
          $item = menu_get_item($settings->options['manual']['page']['path']);
          if (!empty($item['title'])) {
            $name = $item['title'];
          }
        }
        $render['list']['#items'][]['#markup'] = l($name, $base . $id);
      }
      return $render;
    }
  }

  return drupal_get_form('search_api_saved_searches_save_form', $settings);
}

/**
 * Page callback that activates a saved search.
 *
 * This is mostly necessary for anonymous users, but also when a user enters a
 * different mail address than the one he registered with.
 *
 * @param SearchApiSavedSearch $search
 *   The search to activate.
 * @param string $key
 *   The secret access key for this search, used to authenticate the user.
 */
function search_api_saved_searches_activate_page(SearchApiSavedSearch $search, $key) {
  $ret = array(
    'message' => array(
      '#markup' => '',
    ),
    'link' => array(
      '#markup' => '<p>' . $search->l(t('View this saved search')) . '</p>',
    ),
  );
  if ($search->enabled) {
    $msg = t('This saved search has already been activated.');
  }
  else {
    $search->enabled = TRUE;
    $success = $search->save();
    if (!$success) {
      drupal_set_message(t('An error occurred while trying to activate the search. Please contact the site administrator.'), 'error');
      return $ret;
    }
    $msg = t('Your saved search was successfully activated.');
  }
  if ($search->notify_interval >= 0) {
    $msg .= ' ' . t('You will receive e-mail notifications for new results in the future.');
  }
  $ret['message']['#markup'] = '<p>' . $msg . '</p>';
  return $ret;
}

/**
 * Form builder for editing a saved search.
 *
 * @param SearchApiSavedSearch $search
 *   The search to edit.
 *
 * @see search_api_saved_searches_search_edit_form_submit()
 * @ingroup forms
 */
function search_api_saved_searches_search_edit_form(array $form, array &$form_state, SearchApiSavedSearch $search) {
  $form_state['search'] = $search;
  $settings = $search->settings();

  if ($search->uid) {
    $form_state['destination']['path'] = 'user/' . $search->uid . '/saved-searches';
  }
  elseif (!empty($search->options['page'])) {
    $form_state['destination'] = array($search->options['page']['path'], $search->options['page']);
  }

  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Disable to stop receiving notifications from this saved search.'),
    '#default_value' => $search->enabled,
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('The name that will be displayed for this saved search.'),
    '#maxlength' => 50,
    '#required' => TRUE,
    '#default_value' => $search->name,
  );
  if ($settings->options['user_select_interval'] && count($settings->options['interval_options']) > 1) {
    $form['notify_interval'] = array(
      '#type' => 'select',
      '#title' => t('Notification interval'),
      '#options' => $settings->getTranslatedOption('interval_options'),
      '#required' => TRUE,
      '#default_value' => $search->notify_interval,
    );
  }
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );
  if (!empty($form_state['destination'])) {
    $form['actions']['cancel'] = array(
      '#type' => 'link',
      '#title' => t('Cancel'),
      '#href' => $form_state['destination']['path'],
      '#options' => $form_state['destination'],
    );
  }

  return $form;
}

/**
 * Submission handler for search_api_saved_searches_search_edit_form().
 *
 * @see search_api_saved_searches_search_edit_form()
 */
function search_api_saved_searches_search_edit_form_submit(array $form, array &$form_state) {
  $values = $form_state['values'];
  $search = $form_state['search'];
  $search->name = $values['name'];
  $search->enabled = $values['enabled'];
  if (isset($values['notify_interval'])) {
    $search->notify_interval = $values['notify_interval'];
  }
  if ($search->save()) {
    drupal_set_message(t('Successfully saved your changes.'));
    if (!empty($form_state['destination'])) {
      $form_state['redirect'] = $form_state['destination'];
    }
  }
  else {
    drupal_set_message(t('An error occurred while trying to save the changes.'), 'error');
  }
}

/**
 * Page callback: Enables a saved search.
 *
 * @param SearchApiSavedSearch $search
 *   The search to enable.
 */
function search_api_saved_searches_search_enable(SearchApiSavedSearch $search = NULL) {
  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], $search->id)) {
    return MENU_ACCESS_DENIED;
  }

  $search->enabled = TRUE;
  if ($search->save()) {
    drupal_set_message(t('The saved search was successfully enabled.'));
  }
  else {
    drupal_set_message(t('The saved search could not be enabled.'), 'error');
  }

  drupal_goto(_search_api_saved_searches_admin_redirect_url($search));
  return NULL;
}

/**
 * Page callback: Constructs a form for disabling a saved search.
 *
 * @param SearchApiSavedSearch $search
 *   The search to disable.
 *
 * @see search_api_saved_searches_search_disable_form_submit()
 *
 * @ingroup forms
 */
function search_api_saved_searches_search_disable_form(array $form, array &$form_state, SearchApiSavedSearch $search) {
  $form_state['search'] = $search;
  $url = _search_api_saved_searches_admin_redirect_url($search);
  return confirm_form($form, t('Do you really want to disable this saved search?'), $url, t('You will not receive any updates for this saved search until it is re-enabled.'));
}

/**
 * Form submission handler for search_api_saved_searches_search_disable_form().
 */
function search_api_saved_searches_search_disable_form_submit(array $form, array &$form_state) {
  $search = $form_state['search'];
  $search->enabled = FALSE;
  $search->save();
  drupal_set_message(t('The saved search was successfully disabled.'));
  $form_state['redirect'] = _search_api_saved_searches_admin_redirect_url($search);
}

/**
 * Form builder for confirming the deletion of a saved search.
 *
 * @param SearchApiSavedSearch $search
 *   The search to delete.
 *
 * @see search_api_saved_searches_search_delete_form_submit()
 * @ingroup forms
 */
function search_api_saved_searches_search_delete_form(array $form, array &$form_state, SearchApiSavedSearch $search) {
  $form_state['search'] = $search;
  $url = _search_api_saved_searches_admin_redirect_url($search);
  return confirm_form($form, t('Do you really want to delete this saved search?'), $url);
}

/**
 * Submission handler for search_api_saved_searches_search_delete_form().
 *
 * @see search_api_saved_searches_search_delete_form()
 */
function search_api_saved_searches_search_delete_form_submit(array $form, array &$form_state) {
  $search = $form_state['search'];
  $search->delete();
  drupal_set_message(t('The saved search was successfully deleted.'));
  $form_state['redirect'] = _search_api_saved_searches_admin_redirect_url($search);
}

/**
 * Returns the correct redirect URL after changing a saved search.
 *
 * This will be the user's "Saved searches" overview tab, if it is accessible;
 * otherwise, if the search has a page associated with it, that page; and if
 * none of the two are the case, the front page.
 *
 * @param SearchApiSavedSearch $search
 *   The saved search that was edited, deleted or otherwise changed.
 *
 * @return string
 *   The URL to redirect to.
 */
function _search_api_saved_searches_admin_redirect_url(SearchApiSavedSearch $search) {
  if ($search->uid && search_api_saved_search_edit_access(user_load($search->uid))) {
    return 'user/' . $search->uid . '/saved-searches';
  }
  elseif (!empty($search->options['page'])) {
    return $search->options['page'];
  }
  return '<front>';
}
