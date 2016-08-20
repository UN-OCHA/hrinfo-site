<?php

/**
 * @file
 * Admin UI functions and form callbacks for saved searches.
 */

/**
 * Form builder for editing the saved search settings for an index.
 *
 * @param SearchApiIndex $index
 *   The index for which to edit settings.
 *
 * @see search_api_saved_searches_index_edit_validate()
 * @see search_api_saved_searches_index_edit_submit()
 * @ingroup forms
 */
function search_api_saved_searches_index_edit(array $form, array &$form_state, SearchApiIndex $index) {
  if (!$index->enabled) {
    $form = array(
      'note' => array(
        '#markup' => t('Saved searches cannot be enabled for a disabled search index. Enable the index first.'),
      ),
    );
    return $form;
  }
  $settings = search_api_saved_searches_settings_load_multiple(FALSE, array('index_id' => $index->machine_name));
  if (!$settings) {
    $delta = $index->machine_name;
    if (strlen($delta) > 32) {
      $delta = substr($delta, 0, 32);
    }
    $base = $delta;
    for ($i = 1; search_api_saved_searches_settings_load($delta); ++$i) {
      $suffix = '_' . $i;
      $delta = substr($base, 0, 32 - strlen($suffix)) . $suffix;
    }
    $settings = entity_create('search_api_saved_searches_settings', array(
      'delta' => $delta,
      'index_id' => $index->machine_name,
      'enabled' => FALSE,
      'options' => array(),
    ));
  }
  else {
    $settings = reset($settings);
  }

  // Set default options.
  $settings->options += array(
    'date_field' => NULL,
    'description' => '',
    'default_true' => TRUE,
    'ids_list' => array(),
    'registered_choose_mail' => FALSE,
    'choose_name' => FALSE,
    'registered_user_delete_key' => FALSE,
    'show_empty_list' => FALSE,
    'user_select_interval' => TRUE,
    'interval_options' => array(
      60 * 60 * 24     => t('Daily'),
      60 * 60 * 24 * 7 => t('Weekly'),
    ),
    'set_interval' => 60 * 60 * 24,
    'mail' => array(),
    'manual' => array(),
  );
  $settings->options['mail'] += array(
    'activate' => array(),
    'notify' => array(),
  );
  $settings->options['mail']['activate'] += array(
    'send' => TRUE,
    'title' => t('Activate your saved search at [site:name]'),
    'body' => t("A saved search on [site:name] with this e-mail address was created.
To activate this saved search, click the following link:

[search-api-saved-search:activate-url]

If you didn't create this saved search, just ignore this mail and it will be deleted.

--  [site:name] team"),
  );
  $settings->options['mail']['notify'] += array(
    'title' => t('New results for your saved search at [site:name]'),
    'body' => t('[user:name],

There are new results for your saved search on [site:name]:

[search-api-saved-searches:results]

You can configure your saved searches at the following address:
[user:search-api-saved-searches-url]

--  [site:name] team'),
    'results' => t('New results for search "!name_token"', array('!name_token' => '[search-api-saved-search:name]')) .
        ":\n[search-api-saved-search:items]\n[search-api-saved-search:results-capped]",
    'result' => '[search-api-saved-search-result:label] ([search-api-saved-search-result:url])',
    'max_results' => 0,
    'results_capped' => "…\n" . t('View all results') . ': [search-api-saved-search:view-url]',
  );
  $settings->options['manual'] += array(
    'allow' => FALSE,
    'fulltext' => FALSE,
    'fields' => array(),
    'page' => array(),
  );
  $settings->options['manual']['page'] += array(
    'path' => '',
    'fulltext' => '',
    'direct_filter_params' => FALSE,
  );

  $form_state['settings'] = $settings;
  $options = $settings->options;

  $form['#tree'] = TRUE;
  $form['#attached']['css'][] = drupal_get_path('module', 'search_api') . '/search_api.admin.css';
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#description' => t('Enable saved searches for this index.'),
    '#default_value' => $settings->enabled,
  );
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#states' => array(
      'invisible' => array(
        ':input[name="enabled"]' => array('checked' =>FALSE),
      ),
    ),
  );

  $form['options']['misc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Miscellaneous'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings->enabled,
  );
  $fields = array();
  foreach ($index->getFields() as $key => $field) {
    if ($field['type'] == 'date') {
      $fields[$key] = t('Determine by @name', array('@name' => $field['name']));
    }
  }
  if ($fields) {
    $fields = array(NULL => t('Determine by result ID')) + $fields;
    $form['options']['misc']['date_field'] = array(
      '#type' => 'select',
      '#title' => t('Method for determining new results'),
      '#description' => t('The method by which to decide which results are new. "Determine by result ID" will internally save the IDs of all results that were previously found by the user and only report results not already reported. (This might use a lot of memory for large result sets.) The other options check whether the date in the selected field is later than the date of last notification.'),
      '#options' => $fields,
      '#default_value' => $options['date_field'],
      '#parents' => array('options', 'date_field'),
    );
  }
  else {
    $form['options'] = array(
      '#type' => 'value',
      '#value' => NULL,
    );
  }
  $form['options']['misc']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Enter a text that will be displayed to users when creating a saved search.'),
    '#default_value' => $settings->options['description'],
    '#parents' => array('options', 'description'),
  );
  $search_ids = variable_get('search_api_saved_searches_search_ids', array());
  if (empty($search_ids[$index->machine_name]) || count($search_ids[$index->machine_name]) <= 1) {
    $form['options']['default_true'] = array(
      '#type' => 'value',
      '#value' => $options['default_true'],
    );
    $form['options']['ids_list'] = array(
      '#type' => 'value',
      '#value' => $options['ids_list'],
    );
  }
  else {
    $form['options']['misc']['default_true'] = array(
      '#type' => 'select',
      '#title' => t('Display for searches'),
      '#options' => array(
        TRUE => t('For all except the selected'),
        FALSE => t('Only for the selected'),
      ),
      '#default_value' => $options['default_true'],
      '#parents' => array('options', 'default_true'),
    );
    $form['options']['misc']['ids_list'] = array(
      '#type' => 'select',
      '#title' => t('Search IDs'),
      '#options' => $search_ids[$index->machine_name],
      '#size' => min(4, count($search_ids[$index->machine_name])),
      '#multiple' => TRUE,
      '#default_value' => $options['ids_list'],
      '#parents' => array('options', 'ids_list'),
    );
  }
  $form['options']['misc']['registered_choose_mail'] = array(
    '#type' => 'checkbox',
    '#title' => t('Let logged-in users also enter a different mail address'),
    '#default_value' => $options['registered_choose_mail'],
    '#parents' => array('options', 'registered_choose_mail'),
  );
  $form['options']['misc']['choose_name'] = array(
    '#type' => 'checkbox',
    '#title' => t('Customizable search name'),
    '#description' => t("Let users modify the saved search's name even when not manually creating it."),
    '#default_value' => $options['choose_name'],
    '#parents' => array('options', 'choose_name'),
  );
  $form['options']['misc']['registered_user_delete_key'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a delete link for registered users'),
    '#description' => t('If enabled, registered users will also get the option to delete their searches via a special link, without logging in.'),
    '#default_value' => $options['registered_user_delete_key'],
    '#parents' => array('options', 'registered_user_delete_key'),
  );
  $form['options']['misc']['show_empty_list'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show empty list of saved searches'),
    '#description' => t('If enabled, the "Saved searches" tab for registered users will even be available when no saved searches were created by them yet.'),
    '#default_value' => $options['show_empty_list'],
    '#parents' => array('options', 'show_empty_list'),
  );

  // @todo Access options? Maximum number of saved searches per user, maximum
  //   number of results to create saved search, minimum number of filters?

  $form['options']['interval'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notification interval'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings->enabled,
  );
  $form['options']['interval']['user_select_interval'] = array(
    '#type' => 'checkbox',
    '#title' => t('Let users select the interval'),
    '#default_value' => $options['user_select_interval'],
    '#parents' => array('options', 'user_select_interval'),
  );
  $interval_options = array();
  foreach ($options['interval_options'] as $k => $v) {
    $interval_options[] = "$k | $v";
  }
  $interval_options = implode("\n", $interval_options);
  $form['options']['interval']['interval_options'] = array(
    '#type' => 'textarea',
    '#title' => t('Interval options'),
    '#description' => t('The possible intervals the user can choose from. Enter one value per line, in the format seconds|label. Use a negative value for disabling notifications.'),
    '#default_value' => $interval_options,
    '#parents' => array('options', 'interval_options'),
    '#states' => array(
      'visible' => array(
        ':input[name="options[user_select_interval]"]' => array('checked' => TRUE),
      ),
    ),
  );
  $interval_options = array(
    60 * 60 * 24     => t('Daily'),
    60 * 60 * 24 * 7 => t('Weekly'),
    0 => t('Custom'),
  );
  $form['options']['interval']['set_interval'] = array(
    '#type' => 'select',
    '#title' => t('Fixed notification interval'),
    '#options' => $interval_options,
    '#default_value' => isset($interval_options[$options['set_interval']]) ? $options['set_interval'] : 0,
    '#parents' => array('options', 'set_interval'),
    '#states' => array(
      'visible' => array(
        ':input[name="options[user_select_interval]"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['options']['interval']['set_interval_custom'] = array(
    '#type' => 'textfield',
    '#description' => t('Enter the custom notification interval, in seconds. Use a negative value to disable notifications.'),
    '#default_value' => $options['set_interval'],
    '#parents' => array('options', 'set_interval_custom'),
    '#states' => array(
      'visible' => array(
        ':input[name="options[user_select_interval]"]' => array('checked' => FALSE),
        ':input[name="options[set_interval]"]' => array('value' => 0),
      ),
    ),
  );

  $form['options']['mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('E-mails'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings->enabled,
  );
  $form['options']['mail']['activate_send'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use activation mail for anonymous users'),
    '#description' => t("Will need saved searches created by anonymous users, or by normal users with an e-mail address that isn't their own, to be activated by clicking a link in an e-mail."),
    '#default_value' => $options['mail']['activate']['send'],
    '#parents' => array('options', 'mail', 'activate', 'send'),
  );

  $form['options']['mail']['activate'] = array(
    '#type' => 'fieldset',
    '#title' => t('Activation mail'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings->enabled,
  );
  $form['options']['mail']['activate']['#states']['visible'][':input[name="options[mail][activate][send]"]']['checked'] = TRUE;
  $form['options']['mail']['activate']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t("Enter the mail's subject.") . ' ' . t('Available variables are: @vars.',
        array('@vars' => '[site:name], [user:name], [user:mail], [search-api-saved-search:activate-url], ' .
            '[search-api-saved-search:view-url]')),
    '#default_value' => $options['mail']['activate']['title'],
    '#required' => TRUE,
  );
  $form['options']['mail']['activate']['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t("Enter the mail's body.") . ' ' . t('Available variables are: @vars.',
        array('@vars' => '[site:name], [site:url], [user:name], [user:mail], [site:url-brief], ' .
            '[search-api-saved-searches:results], [user:search-api-saved-searches-url]')) . ' ' .
        t('The replacement for @var can be configured below.', array('@var' => '[search-api-saved-searches:results]')) . '<br />' .
        t('Please note: For anonymous users, the [user:*] variables will be empty.'),
    '#default_value' => $options['mail']['activate']['body'],
    '#rows' => 12,
    '#required' => TRUE,
  );

  $form['options']['mail']['notify'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notification mails'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings->enabled,
  );
  $form['options']['mail']['notify']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t("Enter the mail's subject.") . ' ' . t('Available variables are: @vars.',
        array('@vars' => '[site:name], [user:name], [user:mail], [search-api-saved-search:name], [search-api-saved-search:created]')) . '<br />' .
        t('The search-specific variables are taken from the first saved search of the mail. (Alerts from multiple searches are sent at the same time.)'),
    '#default_value' => $options['mail']['notify']['title'],
    '#required' => TRUE,
  );
  $form['options']['mail']['notify']['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t("Enter the mail's body.") . ' ' . t('Available variables are: @vars.',
        array('@vars' => '[site:name], [site:url], [user:name], [user:mail], [site:url-brief], ' .
            '[search-api-saved-searches:results], [user:search-api-saved-searches-url], ' .
            '[search-api-saved-search:name], [search-api-saved-search:created], ' .
            '[search-api-saved-search:results-capped], [search-api-saved-search:view-url], ' .
            '[search-api-saved-search:edit-url], [search-api-saved-search:delete-url]')) . ' ' .
        t('The replacement for @var can be configured below.', array('@var' => '[search-api-saved-searches:results]')) . '<br />' .
        t('The search-specific variables are taken from the first saved search of the mail. (Alerts from multiple searches are sent at the same time.)') . '<br />' .
        t('Please note: For anonymous users, the [user:*] variables will be empty.'),
    '#default_value' => $options['mail']['notify']['body'],
    '#rows' => 12,
    '#required' => TRUE,
  );
  $form['options']['mail']['notify']['results'] = array(
    '#type' => 'textarea',
    '#title' => t('Results replacement'),
    '#description' => t('Enter the text that will replace the [search-api-saved-searches:results] variable above. If there are new results for several saved searches of a single user, this text will be inserted multiple times.') . ' ' .
        t('Available variables are: @vars.',
        array('@vars' => '[site:url], [search-api-saved-search:name], [search-api-saved-search:created], ' .
            '[search-api-saved-search:items], [search-api-saved-search:results-capped], [search-api-saved-search:view-url], ' .
            '[search-api-saved-search:edit-url], [search-api-saved-search:delete-url]')) . ' ' .
        t('The replacement for @var can be configured below.', array('@var' => '[search-api-saved-search:items]')),
    '#default_value' => $options['mail']['notify']['results'],
    '#rows' => 5,
    '#required' => TRUE,
  );
  $form['options']['mail']['notify']['result'] = array(
    '#type' => 'textarea',
    '#title' => t('Result item replacement'),
    '#description' => t('Enter the text that will replace the [search-api-saved-search:items] variable above. This text will be inserted on a new line once for every new result.') . ' ' .
        t('Available variables are: @vars.',
        array('@vars' => '[site:url], [search-api-saved-search-result:label], [search-api-saved-search-result:url], ' .
            '[search-api-saved-search:view-url], [search-api-saved-search:edit-url], [search-api-saved-search:delete-url]')),
    '#default_value' => $options['mail']['notify']['result'],
    '#rows' => 2,
    '#required' => TRUE,
  );
  $tokens = token_info();
  $type = $index->item_type;
  if (isset($tokens['types'][$type])) {
    $form['options']['mail']['notify']['result']['#description'] .= ' ' . t('You can also use the @varstyle variables.',
      array('@varstyle' => "[$type:*]"));
  }
  $form['options']['mail']['notify']['max_results'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of results'),
    '#description' => t('Maximum number of results per search that will be included in the mail. Specify an integer greater than 0 to limit the results.'),
    '#default_value' => $options['mail']['notify']['max_results'],
    '#element_validate' => array('element_validate_integer'),
  );
  $form['options']['mail']['notify']['results_capped'] = array(
    '#type' => 'textarea',
    '#title' => t('Show text if not all results are displayed'),
    '#description' => t('Enter the text that will replace the [search-api-saved-search:results-capped] variable above. This text will only be inserted for searches in which the number of new results exceeds the set maximum.') . ' ' .
        t('Available variables are: @vars.',
        array('@vars' => '[site:url], [search-api-saved-search:name], [search-api-saved-search:created], ' .
            '[search-api-saved-search:items], [search-api-saved-search:view-url], ' .
            '[search-api-saved-search:edit-url], [search-api-saved-search:delete-url]')),
    '#default_value' => $options['mail']['notify']['results_capped'],
    '#rows' => 4,
    '#states' => array(
      'invisible' => array(
        ':input[name="options[mail][notify][max_results]"]' => array('value' => 0),
      ),
    ),
  );

  $form['options']['manual'] = array(
    '#type' => 'fieldset',
    '#title' => t('Manual saved search creation'),
    '#description' => t('This provides a form to users where they can create a saved search manually, without first executing a search.'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings->enabled,
  );
  $form['options']['manual']['allow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow manual creation of saved searches'),
    '#default_value' => $options['manual']['allow'],
  );
  $form['options']['manual']['fulltext'] = array(
    '#type' => 'checkbox',
    '#title' => t('Provide textfield for fulltext keywords'),
    '#default_value' => $options['manual']['fulltext'],
  );
  if (!empty($index->options['fields'])) {
    $fields = array();
    foreach ($index->getFields() as $field => $info) {
      $fields[$field] = $info['name'];
    }
  }
  if (!empty($fields)) {
    $form['options']['manual']['fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Fields for which to provide filter options'),
      '#options' => $fields,
      '#attributes' => array(
        'class' => array('search-api-checkboxes-list'),
      ),
      '#default_value' => drupal_map_assoc($options['manual']['fields']),
    );
  }
  $form['options']['manual']['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search page'),
    '#description' => t('Specify the page where search results can be viewed.'),
    '#collapsible' => TRUE,
  );
  $form['options']['manual']['page']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Base path'),
    '#description' => t('Base path for a search without any of the restrictions that can be applied. ' .
        'If this is not specified, no link to a search page will be provided to users for manually created searches.'),
    '#default_value' => $options['manual']['page']['path'],
  );
  $form['options']['manual']['page']['fulltext'] = array(
    '#type' => 'textfield',
    '#title' => t('Fulltext URL parameter'),
    '#description' => t('Query parameter used for passing the fulltext keywords in the URL. ' .
        'If left empty, the fulltext keywords (if present at all) will be appended to the path, instead of being passed as a parameter.'),
    '#default_value' => $options['manual']['page']['fulltext'],
  );
  $form['options']['manual']['page']['direct_filter_params'] = array(
    '#type' => 'select',
    '#title' => t('Method for passing filter values in the URL'),
    '#options' => array(
      FALSE => t('In filter[*], as used by facets'),
      TRUE => t('As direct URL parameters'),
    ),
    '#default_value' => $options['manual']['page']['direct_filter_params'],
  );
  foreach (array('fulltext', 'fields', 'page') as $v) {
    $form['options']['manual'][$v]['#states']['visible'][':input[name="options[manual][allow]"]']['checked'] = TRUE;
  }
  foreach (array('fulltext', 'direct_filter_params') as $v) {
    $form['options']['manual']['page'][$v]['#states']['visible'][':input[name="options[manual][page][path]"]']['empty'] = FALSE;
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  return $form;
}

/**
 * Form validation handler for search_api_saved_searches_index_edit().
 *
 * @see search_api_saved_searches_index_edit()
 * @see search_api_saved_searches_index_edit_submit()
 */
function search_api_saved_searches_index_edit_validate(array $form, array &$form_state) {
  $values = &$form_state['values'];
  $interval_options = $values['options']['interval_options'];
  $values['options']['interval_options'] = array();
  foreach (explode("\n", $interval_options) as $line) {
    $parts = explode('|', $line, 2);
    if (count($parts) == 1) {
      $k = $v = trim($line);
    }
    else {
      list($k, $v) = array_map('trim', $parts);
    }
    $values['options']['interval_options'][$k] = $v;
  }
  if ($values['options']['user_select_interval']) {
    foreach ($values['options']['interval_options'] as $k => $v) {
      if (!preg_match('/^-?\d+$/', $k)) {
        form_error($form['options']['interval_options'], t('"@input" is not a valid integer. Only integers can be used as intervals.', array('@input' => $k)));
      }
    }
  }
  elseif ($values['options']['set_interval'] == 0) {
    $v = $values['options']['set_interval_custom'];
    if (!preg_match('/^-?\d+$/', $v)) {
      form_error($form['options']['set_interval_custom'], t('"@input" is not a valid integer. Only integers can be used as intervals.', array('@input' => $v)));
    }
  }
}

/**
 * Form submission handler for search_api_saved_searches_index_edit().
 *
 * @see search_api_saved_searches_index_edit()
 * @see search_api_saved_searches_index_edit_vaidate()
 */
function search_api_saved_searches_index_edit_submit(array $form, array &$form_state) {
  $values = $form_state['values'];
  $settings = $form_state['settings'];

  $options = $values['options'];
  if ($options['set_interval'] == 0) {
    $options['set_interval'] = $options['set_interval_custom'];
  }
  unset($options['set_interval_custom']);
  $options['manual']['fields'] = array_keys(array_filter($options['manual']['fields']));

  $settings->enabled = $values['enabled'];
  $settings->options = $options;

  $ret = $settings->save();
  if ($ret === FALSE) {
    drupal_set_message('An error occurred while trying to save the settings. Check the logs for details.', 'error');
    $form_state['rebuild'] = TRUE;
  }
  else {
    drupal_set_message('The settings were successfully saved.');
  }
}
