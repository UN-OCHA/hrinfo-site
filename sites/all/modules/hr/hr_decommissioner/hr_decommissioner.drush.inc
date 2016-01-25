<?php

/**
 * @file
 * hr_decommissioner module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *  An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_decommissioner_drush_command() {
  $items = array();

  $items['hr-decommissioner-export-additional-contacts'] = array(
    'description' => "Export additional contacts in hrinfo",
    'drupal dependencies' => array(),
    'aliases' => array(),
  );

  return $items;
}

/**
 * Callback to get the contacts that aren't in HID.
 */
function drush_hr_decommissioner_export_additional_contacts() {

  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_users_ref')
    ->execute();
  if (empty($results['field_collection_item'])) {
    return;
  }
  $contacts = array_keys($results['field_collection_item']);

  $batch = array(
    'operations' => array(
      array(
        'drush_hr_decommissioner_get_contacts',
        array(
          $contacts,
        ),
      ),
    ),
    'finished' => 'drush_hr_decommissioner_finished',
    'title' => t('Calculating'),
    'init_message' => t('Preparing contacts calculation...'),
    'progress_message' => t('Calculating contacts...'),
    'error_message' => t('Contacts process resulted in an error.'),
  );

  batch_set($batch);
  drush_backend_batch_process();
}

function drush_hr_decommissioner_finished($success, $results, $operations) {
  drush_log('Process finished');
}

/**
 * Generates a listing of additional contacts.
 */
function drush_hr_decommissioner_get_contacts($contacts, &$context) {
  $limit = 500;
  $context['finished'] = 0;

  if (!isset($context['sandbox']['file'])) {
    $headers = array(
      'Name',
      'Email',
      'Phones',
    );
    // Create the file and print the labels in the header row.
    $file_path = file_directory_temp() . '/additional-contacts-report.csv';
    $handle = fopen($file_path, 'w');
    fputcsv($handle, $headers);
    fclose($handle);
    $context['sandbox']['contacts'] = $contacts;
    $context['sandbox']['total_contacts'] = count($contacts);
    $context['sandbox']['file'] = $file_path;
    $context['results']['count'] = 0;
  }

  $handle = fopen($context['sandbox']['file'], 'a');

  if ($contacts_pending = count($context['sandbox']['contacts'])) {
    drush_log('Pending: ' . $contacts_pending);
    $actual_limit = min($contacts_pending, $limit);
    $contact_info = array_slice(
      $context['sandbox']['contacts'],
      $context['results']['count'],
      $actual_limit,
      TRUE
    );

    // Load all the contacts for the iteration.
    $contact_items = field_collection_item_load_multiple($contact_info);

    foreach ($contact_items as $contact_item) {
      $wrapper = entity_metadata_wrapper('field_collection_item', $contact_item);
      $additional_user = $wrapper->field_users_ref_checkbox->value();

      if (!empty($additional_user)) {
        // Otherwise, add it to the csv.
        $row = array();
        $row[] = $wrapper->field_users_ref_name->value();
        $row[] = $wrapper->field_email->value();
        $phone_values = $wrapper->field_phones->value();
        $phones = array();
        foreach ($phone_values as $value) {
          $phones[] = $value['number'];
        }
        $row[] = implode(',', $phones);
        fputcsv($handle, $row);
      }
    }

    $context['results']['count'] += $actual_limit;
    $context['finished'] = $context['results']['count'] / $context['sandbox']['total_contacts'];
  }
  else {
    $context['finished'] = 1;
  }

  fclose($handle);

  $context['message'] = t(
    'Processed @count of @total contacts.',
    array(
      '@count' => $context['results']['count'],
      '@total' => $context['sandbox']['total_contacts'],
    )
  );
}

/**
 * Checks the email in the profiles.
 */
function drush_hr_contacts_email_is_in_profile($email, $profiles) {
  foreach ($profiles as $profile) {
    if (strstr($profile->cid, $email) !== FALSE) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Reads the file and looks for the email.
 */
function drush_hr_contacts_email_is_in_file($email, $handle) {
  while ($row = fgetcsv($handle)) {
    if (in_array($email, $row)) {
//      $meta_data = stream_get_meta_data($handle);
//      $filename = $meta_data['uri'];
//      drush_log("Found $email in $filename");
      return TRUE;
    }
  }

  return FALSE;
}
