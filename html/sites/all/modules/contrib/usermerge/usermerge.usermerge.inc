<?php
/**
 * @file
 * Implements User merge hooks for core-related user properties.
 *
 */
/**
 * Implement hook_usermerge_actions_supported().
 */
function usermerge_usermerge_actions_supported() {
  return array(
    'a-core' => t('Choosing which user information (default properties and custom fields, if available) should be kept, discarded, or merged (this choice is not available for all properties).'),
    'a-entities' => t('Assigning to the new user any entities (such as nodes and comments) previously associated with the old user.')
  );
}
/**
 * Implement hook_usermerge_account_properties().
 */
function usermerge_usermerge_account_properties($user_to_delete, $user_to_keep, $action) {
  $user_entity_properties['core'] = usermerge_get_user_core_properties();

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
      // Exclude properties that shouldn't be merged, like password
      // These could be defined via settings page
      if (!in_array($property_name, array('pass'))) {
        $account_properties[$type]['items'][$property_name] = array(
          'name' => $property_name,
          'criterion' => 'merge'
        );
      }
    }
  }

  // Set default choices for core properties
  // This could be defined via settings page
  $usermerge_settings = variable_get('usermerge_settings', usermerge_settings_default());

  foreach ($usermerge_settings['core'] as $property_name => $setting_value) {
    if (empty($setting_value)) {
      // If the property is not checked in settings, set a default
      $account_properties['core']['items'][$property_name]['default'] = $user_to_keep->{$property_name};
    }
  }

  // Always show uid, mail, and name, regarless of whether they can be editted.
  foreach (array('uid', 'mail', 'name') as $property_name) {
    if (isset($account_properties['core']['items'][$property_name]['default']) || $action != 'delete') {
      $account_properties['core']['items'][$property_name]['disabled'] = TRUE;
    }
    unset($account_properties['core']['items'][$property_name]['default']);
  }

  // Automatically handle properties that can't be exposed via settings:

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

  // Choose newer login date
  if ($user_to_delete->login > $user_to_keep->login) {
    $account_properties['core']['items']['login']['default'] = $user_to_delete->login;
  }
  else {
    $account_properties['core']['items']['login']['default'] = $user_to_keep->login;
  }

  $account_properties['core']['items']['init']['default'] = $user_to_keep->init;
  $account_properties['core']['items']['data']['default'] = $user_to_keep->data;

  foreach ($account_properties['core']['items'] as $property_name => $settings) {
    if ($property_name == 'roles') {
      // Keep the ability to choose between roles of the two users, but set the default option to merge
      $account_properties['core']['items'][$property_name]['default_option'] = 'merge';
    }
    else {
      // All other properties should not have a "both" option
      $account_properties['core']['items'][$property_name]['criterion'] = 'no_merge';
    }
  }

  // Special settings for fields
  if (!empty($account_properties['fields']['items'])) {
    foreach ($account_properties['fields']['items'] as $field_name => $properties) {
      $field_settings = field_info_field($field_name);
      // If the field's cardinality is not 1, do not allow merging
      // This could pose problems for fields whose cardinality is greater than one, but not unlimited
      if ($field_settings['cardinality'] <> FIELD_CARDINALITY_UNLIMITED) {
        $account_properties['fields']['items'][$field_name]['criterion'] = 'force_select';
      }
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
 * Implement hook_usermerge_build_review_form_elements().
 */
function usermerge_usermerge_build_review_form_elements($review, $account_properties, $user_to_delete, $user_to_keep) {
  // Build form elements
  // Set very low weight to keep properties controlled by this file at the top of the table
  $i = -10000;
  foreach ($account_properties as $property_type => $properties) {
    // User properties
    if (in_array($property_type, array('core', 'fields', 'other'))) {
      $review[$property_type] = array(
        '#tree' => TRUE,
        '#theme' => 'usermerge_data_review_form_table',
        '#title' => $properties['title'],
        '#weight' => $i
      );

      if (isset($properties['description'])) {
        $review[$property_type]['#description'] = $properties['description'];
      }

      if ($property_type == 'fields') {
        $review[$property_type]['#attributes']['property_label'] = t('Field');
      }

      foreach ($properties['items'] as $property) {
        $property_name = $property['name'];

        // Properties with default behaviors will not be displayed
        if (!array_key_exists('default', $property)) {
          $review[$property_type][$property_name]['property_name'] = array(
            '#type' => 'markup',
            '#markup' => $property_name
          );

          // Display property values
          $field_user_to_delete = $user_to_delete->{$property_name};
          $field_user_to_keep = $user_to_keep->{$property_name};

          switch ($property_name) {
            // Roles must be dealt with separately
            case 'roles' :
              $field_user_to_delete = implode(', ', $user_to_delete->{$property_name});
              $field_user_to_keep = implode(', ', $user_to_keep->{$property_name});
            break;

            case 'picture' :
              if ($user_to_delete->{$property_name}) {
                $filepath_user_to_delete = image_style_url('thumbnail', $user_to_delete->{$property_name}->uri);
                $field_user_to_delete = theme('image', array('path' => $filepath_user_to_delete));
              }

              if ($user_to_keep->{$property_name}) {
                $filepath_user_to_keep = image_style_url('thumbnail', $user_to_keep->{$property_name}->uri);
                $field_user_to_keep = theme('image', array('path' => $filepath_user_to_keep));
              }
            break;
          }

          // Process custom fields for display
          if ($property_type == 'fields') {
            if (is_array($field_user_to_delete)) {
              $field_user_to_delete = field_view_field('user', $user_to_delete, $property_name, array('label' => 'hidden', 'settings' => array()));
              $field_user_to_delete = strip_tags(drupal_render($field_user_to_delete), '<em> <strong> <ul> <li>');
            }

            if (is_array($field_user_to_keep)) {
              $field_user_to_keep = field_view_field('user', $user_to_keep, $property_name, array('label' => 'hidden', 'settings' => array()));
              $field_user_to_keep = strip_tags(drupal_render($field_user_to_keep), '<em> <strong> <ul> <li>');
            }
          }

          $review[$property_type][$property_name]['options'] = array(
            '#type' => 'radios',
            '#options' => array(
              'user_to_delete' => is_string($field_user_to_delete) ? $field_user_to_delete : '',
              'user_to_keep' => is_string($field_user_to_keep) ? $field_user_to_keep : '',
            ),
          );

          if (isset($property['default_option'])) {
            $review[$property_type][$property_name]['options']['#default_value'] = $property['default_option'];
          }
          else {
            $review[$property_type][$property_name]['options']['#default_value'] = 'user_to_keep';
          }

          switch ($property['criterion']) {
            case 'merge' :
              $review[$property_type][$property_name]['options']['#options']['merge'] = 'merge';
              break;

            case 'force_select' :
              // Nothing happens here
              $review[$property_type][$property_name]['options']['#options']['merge'] = 'force_select';
              break;
            case 'no_merge' :
              $review[$property_type][$property_name]['options']['#options']['merge'] = 'no_merge';
              // uid and (if not editable, mail and name) should be visible but disabled.
              if (!empty($property['disabled'])) {
                $review[$property_type][$property_name]['options']['#disabled'] = TRUE;
              }
            break;
          }

          if (isset($property['default_option'])) {
            $review[$property_type][$property_name]['options']['#default_value'] = $property['default_option'];
          }
        }
        else {
          $account[$property_name] = $property['default'];
        }
      }
    }
    // Entities
    elseif ($property_type == 'entities') {
      $content_user_to_delete = usermerge_query_authored_entities($properties['items'], $user_to_delete->uid);
      $content_user_to_keep = usermerge_query_authored_entities($properties['items'], $user_to_keep->uid);

      if (count($content_user_to_delete) || count($content_user_to_keep)) {
        $review[$property_type] = array(
          '#tree' => TRUE,
          '#theme' => 'usermerge_data_review_form_table',
          '#title' => $properties['title'],
          '#attributes' => array('no_merge', 'property_label' => t('Entity')),
          '#weight' => $i
        );

        foreach ($content_user_to_delete as $entity_type => $entities) {
          $review[$property_type][$entity_type]['property_name'] = array(
              '#type' => 'markup',
              '#markup' => $entity_type
            );

          $review[$property_type][$entity_type]['options']['user_to_delete'] = array(
            '#type' => 'markup',
            '#markup' => format_plural(count($entities), '1 %entity entity to be reassigned', '@count %entity entities to be reassigned', array('%entity' => $entity_type))
          );
        }

        foreach ($content_user_to_keep as $entity_type => $entities) {
          $review[$property_type][$entity_type]['property_name'] = array(
              '#type' => 'markup',
              '#markup' => $entity_type
            );

          $review[$property_type][$entity_type]['options']['user_to_keep'] = array(
            '#type' => 'markup',
            '#markup' => format_plural(count($entities), '1 %entity entity to be maintained', '@count %entity entities to be maintained', array('%entity' => $entity_type))
          );
        }
        ksort($review[$property_type]);
      }
    }

    // Increments weight
    $i++;
  }

  if (isset($account)) {
    $review['account'] = array(
      '#type' => 'hidden',
      '#value' => serialize($account)
    );
  }

  return $review;
}

/**
 * Selects entities with a uid column.
 */
function usermerge_get_authorable_entities() {
  $entities = entity_get_info();

  foreach ($entities as $entity_type => $entity) {
    if (!in_array('uid', $entity['schema_fields_sql']['base table'])) {
      unset($entities[$entity_type]);
    }
  }

  // Exclude user entity
  unset($entities['user']);

  return $entities;
}

/**
 * Selects entities whose uid matches the selected user.
 */
function usermerge_query_authored_entities($entities, $user_id) {
  $found_entities = array();

  foreach ($entities as $entity_type => $entity) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $entity_type)
      ->propertyCondition('uid', $user_id);
    $result = $query->execute();

    if (count($result)) {
      $found_entities[$entity_type] = $result[$entity_type];
    }
  }
  drupal_alter('usermerge_query_authored_entities', $found_entities, $entities, $user_id);
  return $found_entities;
}

/**
 * Implements hook_usermerge_merge_accounts().
 */
function usermerge_usermerge_merge_accounts($user_to_delete, $user_to_keep, $review) {
  $merged_account = unserialize($review['account']);
  unset($review['account']);

  // Process core, fields, other properties
  foreach ($review as $property_type => $properties) {
    if (in_array($property_type, array('core', 'fields', 'other'))) {
      foreach ($properties as $property_name => $options) {
        if ($options['options'] != NULL) {
          if ($options['options'] != 'merge') {
            $chosen_account = $options['options'];
            $merged_account[$property_name] = $$chosen_account->{$property_name};
          }
          else {
            switch ($property_type) {
              case 'core' :
                // Other modules can enforce merging of properties this module won't merge, so we won't object to that here
                // This module deals natively only with roles
                if ($property_name == 'roles') {
                  $merged_account[$property_name] = $user_to_delete->{$property_name} + $user_to_keep->{$property_name};
                  ksort($merged_account[$property_name]);
                }
              break;

              case 'fields' :
                // $user_to_delete has data in the field
                if (count($user_to_delete->{$property_name})) {
                  foreach ($user_to_delete->{$property_name} as $language => $items) {
                    // $user_to_keep has data in the field
                    if (isset($user_to_keep->{$property_name}[$language])) {
                      $merged_account[$property_name][$language] = array_merge($user_to_delete->{$property_name}[$language], $user_to_keep->{$property_name}[$language]);
                    }
                    else {
                      $merged_account[$property_name][$language] = $user_to_delete->{$property_name}[$language];
                    }
                  }
                }
                // $user_to_delete does not have data in the field, but $user_to_keep does
                // No need to iterate
                elseif (count($user_to_keep->{$property_name})) {
                  $merged_account[$property_name] = $user_to_keep->{$property_name};
                }
              break;
            }
          }
        }
      }
    }
  }

  // Operate on entities
  // Rebuild the list of entities here instead of passing as form values
  $authorable_entities = usermerge_get_authorable_entities();

  $entities_user_to_delete = usermerge_query_authored_entities($authorable_entities, $user_to_delete->uid);
  // No need to find entities for $user_to_keep

  foreach ($entities_user_to_delete as $entity_type => $entities) {
    // We take for granted that the base table has a uid column, because of usermerge_get_authorable_entities()
    // We also don't need to select specific entities, because we're replacing all the entities belonging to $user_to_delete
    db_update($authorable_entities[$entity_type]['base table'])
      ->fields(array(
              'uid' => $user_to_keep->uid,
              ))
      ->condition('uid', $user_to_delete->uid)
      ->execute();

    // Check if the entity has a revision table
    if (isset($authorable_entities[$entity_type]['revision table'])) {
      // Find the correct column name
      // Not all revision tables have the uid stored in uid (like node_revision)
      // Some store it in revision_uid
      // Could be taking a chance here
      $uid_column = reset(preg_grep("/uid/", $authorable_entities[$entity_type]['schema_fields_sql']['revision table']));
      db_update($authorable_entities[$entity_type]['revision table'])
        ->fields(array(
                $uid_column => $user_to_keep->uid,
                ))
        ->condition($uid_column, $user_to_delete->uid)
        ->execute();
    }
  }

  return $merged_account;
}
