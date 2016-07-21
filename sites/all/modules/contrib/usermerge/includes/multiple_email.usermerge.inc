<?php
/**
 * @file
 * Adds support for Multiple E-mail.
 * Supplemental include loaded via usermerge_load_includes().
 */

/**
 * Implements hook_usermerge_actions_supported() on behalf of multiple_email.
 */
function multiple_email_usermerge_actions_supported() {
  return array(
    'multiple_email' => t('Choosing to keep or merge e-mail addresses managed by Multiple E-mail.')
  );
}

/**
 * Implements hook_form_FORM_ID_alter() on behalf of multiple_email.
 */
function multiple_email_form_usermerge_merge_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['general']['usermerge_user_delete_action'])) {
    $form['general']['usermerge_user_delete_action']['#default_value'] = 'delete';
    $form['general']['usermerge_user_delete_action']['#disabled'] = TRUE;
    $form['general']['usermerge_user_delete_action']['#description'] = t('Integration with Multiple E-mail requires the account to be deleted.');
  }
}

/**
 * Implements hook_form_FORM_ID_alter() on behalf of multiple_email.
 */
function multiple_email_form_usermerge_data_review_form_alter(&$form, $user_to_delete, $user_to_keep) {
  // Removes the default value for mail in the core review form
  $form['review']['core']['mail']['options']['#default_value'] = NULL;
}

/**
 * Implements hook_usermerge_account_properties() on behalf of multiple_email.
 */
function multiple_email_usermerge_account_properties($user_to_delete, $user_to_keep, $action) {
  $account_properties['multiple_email'] = array(
    'title' => t('Multiple E-mail'),
    'items' => array(
      'multiple_email' => array(
        'name' => 'multiple_email',
        'criterion' => 'merge'
      )
    )
  );

  return $account_properties;
}

/**
 * Implements hook_usermerge_build_review_form_elements() on behalf of multiple_email.
 */
function multiple_email_usermerge_build_review_form_elements($review, $account_properties, $user_to_delete, $user_to_keep) {
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
 * Implements hook_usermerge_merge_accounts() on behalf of multiple_email.
 */
function multiple_email_usermerge_merge_accounts($user_to_delete, $user_to_keep, $review) {
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
 * Returns a keyed array of email addresses to be displayed in the review form.
 */
function _multiple_email_usermerge_load_addresses($uid) {
  $addresses = multiple_email_load_addresses($uid);
  unset($addresses[0]);

  $address_list = array();
  foreach ($addresses as $eid => $properties) {
    $address_list[$eid] = $properties->email;

    if ($properties->primary_address == TRUE) {
      $address_list[$eid] .= ' ' . t('(main)');
    }
  }

  return $address_list;
}
