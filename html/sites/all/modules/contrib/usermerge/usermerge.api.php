<?php
/**
 * @file
 * Hooks provided by the User Merge module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Add elements to the list of supported actions.
 *
 * The returned array will be sorted by key, so the hook implementation can
 * adjust the order by returning appropriate key names.
 */
function hook_usermerge_actions_supported() {
  return array(
    'a-core' => t('Choosing which user information (default properties and custom fields, if available) should be kept, discarded, or merged (this choice is not available for all properties).'),
    'a-entities' => t('Assigning to the new user any entities (such as nodes and comments) previously associated with the old user.')
  );
}

/**
 * Define which properties of the user account will be merged.
 *
 * @param $user_to_delete
 *   The full object of the user to be deleted.
 * @param $user_to_keep
 *   The full object of the user to be kept.
 * @param $action
 *   'delete' or 'block'. Usually does not affect the properties.
 */
function hook_usermerge_account_properties($user_to_delete, $user_to_keep, $action) {
  // Example taken from usermerge_usermerge_account_properties()

  // Define list of fields and other user data
  // Using the columns in the user table, so non-field data added from other modules doesn't get mixed in
  $user_entity_info = entity_get_info('user');
  $user_entity_properties['core'] = $user_entity_info['schema_fields_sql']['base table'];
  // Adding roles
  $user_entity_properties['core'][] = 'roles';

  // Define an array of properties that can be used to display the data-review table(s)
  $account_properties = array(
    'core' => array(
      'title' => t('Core properties'),
      'items' => array()
    )
  );

  // Define list of all user properties (including fields)
  // Using $user_to_delete insures that all properties are accounted for
  $user_all_properties = array_keys((array) $user_to_delete);

  // Find custom fields
  $user_entity_properties['fields'] = preg_grep("/^field_/", $user_all_properties);

  if (count($user_entity_properties['fields'])) {
    $account_properties['fields'] = array(
      'title' => t('Fields'),
      'description' => t('Please note that single-value fields cannot be merged.'),
      'items' => array()
    );
  }

  // Find other user properties
  $user_noncore_properties = array_diff($user_all_properties, $user_entity_properties['core']);
  $user_entity_properties['other'] = array_diff($user_noncore_properties, $user_entity_properties['fields']);

  if (count($user_entity_properties['other'])) {
    $account_properties['other'] = array(
      'title' => t('Other properties'),
      'items' => array()
    );
  }

  foreach ($user_entity_properties as $type => $properties) {
    foreach (array_flip($properties) as $property_name => $delta) {
      $account_properties[$type]['items'][$property_name] = array(
        'name' => $property_name,
        'criterion' => 'merge'
      );
    }
  }

  // These could be defined via settings page
  // Remove unwanted items
  unset($user_entity_properties, $account_properties['core']['items']['pass']);

  // Set default choices for core properties
  // This could be defined via settings page
  $account_properties['core']['items']['theme']['default'] = $user_to_keep->theme;
  $account_properties['core']['items']['signature']['default'] = $user_to_keep->signature;
  $account_properties['core']['items']['signature_format']['default'] = $user_to_keep->signature_format;

  // Choose older created date
  if ($user_to_delete->created < $user_to_keep->created) {
    $account_properties['core']['items']['created']['default'] = $user_to_delete->created;
  }
  else {
    $account_properties['core']['items']['created']['default'] = $user_to_keep->created;
  }

  // Choose newer access date
  if ($user_to_delete->access > $user_to_keep->access) {
    $account_properties['core']['items']['access']['default'] = $user_to_delete->access;
  }
  else {
    $account_properties['core']['items']['access']['default'] = $user_to_keep->access;
  }

  $account_properties['core']['items']['login']['default'] = $user_to_keep->login;
  $account_properties['core']['items']['status']['default'] = $user_to_keep->status;
  $account_properties['core']['items']['timezone']['default'] = $user_to_keep->timezone;
  $account_properties['core']['items']['language']['default'] = $user_to_keep->language;
  $account_properties['core']['items']['picture']['default'] = $user_to_keep->picture;
  $account_properties['core']['items']['init']['default'] = $user_to_keep->init;
  $account_properties['core']['items']['data']['default'] = $user_to_keep->data;

  // Keep the ability to choose between roles of the two users, but set the default option to merge
  $account_properties['core']['items']['roles']['default_option'] = 'merge';

  // Properties that should not have a "both" option
  $account_properties['core']['items']['uid']['criterion'] = 'no_merge';
  $account_properties['core']['items']['name']['criterion'] = 'no_merge';
  $account_properties['core']['items']['mail']['criterion'] = 'no_merge';

  // Special settings for fields
  foreach ($account_properties['fields']['items'] as $field_name => $properties) {
    $field_settings = field_info_field($field_name);
    // If the field's cardinality is not 1, do not allow merging
    // This could pose problems for fields whose cardinality is greater than one, but not unlimited
    if ($field_settings['cardinality'] <> FIELD_CARDINALITY_UNLIMITED) {
      $account_properties['fields']['items'][$field_name]['criterion'] = 'force_select';
    }
  }

  // Authored entitites
  $account_properties['entities']['title'] = t('Authored entities');

  foreach (usermerge_get_authorable_entities() as $entity_name => $entity) {
    $account_properties['entities']['items'][$entity_name] = array(
      'name' => $entity_name,
      'criterion' => 'no_merge'
    );
  }

  return $account_properties;
}

/**
 * Perform alterations to the list of properties before it's displayed.
 *
 * @param $properties
 *   The full properties array.
 * @param $user_to_delete
 *   The full object of the user to be deleted.
 * @param $user_to_keep
 *   The full object of the user to be kept.
 * @param $action
 *   'delete' or 'block'. Usually does not affect the properties.
 *
 * @see hook_usermerge_account_properties()
 */
function hook_usermerge_account_properties_alter(&$properties, $user_to_delete, $user_to_keep, $action) {
  // Example taken from rdf_usermerge_account_properties_alter()

  // Sets the default to the value of $user_to_keep
  $properties['other']['items']['rdf_mapping']['default'] = $user_to_keep->rdf_mapping;
}

/**
 * Build elements of the review table.
 *
 * @param $review
 *   The array containing review data (as form elements).
 * @param $account_properties
 *   The array of account properties to be merged.
 * @param $user_to_delete
 *   The full object of the user to be deleted.
 * @param $user_to_keep
 *   The full object of the user to be kept.
 */
function hook_usermerge_build_review_form_elements($review, $account_properties, $user_to_delete, $user_to_keep) {
  // Example from multiple_email_usermerge_build_review_form_elements()
  $emails_user_to_delete = implode(', ', _multiple_email_usermerge_load_addresses($user_to_delete->uid));
  $emails_user_to_keep = implode(', ', _multiple_email_usermerge_load_addresses($user_to_keep->uid));

  $properties = $account_properties['multiple_email'];

  $review['multiple_email'] = array(
    '#tree' => TRUE,
    '#theme' => 'usermerge_data_review_form_table',
    '#title' => $properties['title'],
    'multiple_email' => array(
      'property_name' => array(
        '#type' => 'markup',
        '#markup' => t('E-mail addresses'),
      ),
      'options' => array(
        '#type' => 'radios',
        '#options' => array(
          'user_to_delete' => $emails_user_to_delete,
          'user_to_keep' => $emails_user_to_keep,
          'merge' => 'merge'
        ),
        '#default_value' => 'user_to_keep'
      )
    ),
  );

  if (isset($properties['description'])) {
    $review['multiple_email']['#description'] = $properties['description'];
  }

  return $review;
}

/**
 * Merge specific account properties.
 *
 * @param $user_to_delete
 *   The full object of the user to be deleted.
 * @param $user_to_keep
 *   The full object of the user to be kept.
 * @param $review
 *   The array containing review data (as form elements).
 */
function hook_usermerge_merge_accounts($user_to_delete, $user_to_keep, $review) {
  // Example from multiple_email_usermerge_merge_accounts()

  $emails_to_keep = $review['multiple_email']['multiple_email']['options'];

  if ($emails_to_keep == 'merge') {
    $query = db_update('multiple_email')
      ->fields(array(
        'uid' => $user_to_keep->uid
      ))
      ->condition('uid', $user_to_delete->uid)
      ->execute();

    // Make sure $user_to_keep's primary email remains primary
    // Necessary because support for regular mail property is disabled by this extension
    multiple_email_make_primary(multiple_email_find_address($user_to_keep->mail));
  }
  else {
    $emails_to_delete = $emails_to_keep == 'user_to_keep' ? 'user_to_delete' : 'user_to_keep';
    $query_delete = db_delete('multiple_email')
      ->condition('uid', $$emails_to_delete->uid)
      ->execute();

    // This fires only if the emails to keep are those of the account to delete
    // If not, this would be redundant
    if ($emails_to_keep == 'user_to_delete') {
      $query_update = db_update('multiple_email')
        ->fields(array(
          'uid' => $user_to_keep->uid
        ))
        ->condition('uid', $$emails_to_keep->uid)
        ->execute();
    }

    // Make sure $emails_to_keep's primary email remains primary
    multiple_email_make_primary(multiple_email_find_address($$emails_to_keep->mail));
  }
}

/**
 * Alter merged data before saving account.
 *
 * @param $merged_account
 *   The full object of the merged account.
 * @param $user_to_delete
 *   The full object of the user to be deleted.
 * @param $user_to_keep
 *   The full object of the user to be kept.
 *
 * @see hook_usermerge_merge_accounts()
 */
function hook_usermerge_merge_accounts_alter($merged_account, $user_to_delete, $user_to_keep) {
  // Example from realname_usermerge_merge_accounts_alter()

  // Removes the Real Name, which will be recreated automatically
  $merged_account['realname'] = NULL;

  return $merged_account;
}

/**
 * Alter authored entities which are automatically merged.
 *
 * @param array $entities
 *    An array of arrays of entities that will be automatically merged, indexed
 *    by entity type and then entity id.
 * @param array $entity_types
 *    An array of entity merge specifications, indexed by entity type, which
 *    are eligible to be merged.
 * @param integer $user_id
 *    The user id of the account to be deleted.
 */
function hook_usermerge_query_authored_entities_alter(&$entities, $entity_types, $user_id) {
  // Prevent profile2 entities from being automatically merged as authoried entities because
  // Profile2 supplies its own merging.
  unset($entities['profile2']);
}
/**
 *@} End of "addtogroup hooks".
 */
