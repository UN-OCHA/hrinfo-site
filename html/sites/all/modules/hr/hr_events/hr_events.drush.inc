<?php

/**
 * @file
 * Drush functions.
 */

/**
 * Implements hook_drush_command().
 */
function hr_events_drush_command() {
  $items = array();

  $items['hr-events-hid-contacts'] = array(
    'description' => 'Import contact details from HID',
    'callback' => 'drush_hr_events_hid_contacts',
    'options' => array(
      'limit' => array(
        'description' => 'The amount of contacts to import. Defaults to 1.',
        'example-value' => '30',
      ),
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Access rebuild callback.
 */
function drush_hr_events_hid_contacts() {
  if (!drush_bootstrap_to_phase(DRUSH_BOOTSTRAP_DRUPAL_DATABASE)) {
    return drush_set_error('DRUPAL_SITE_NOT_FOUND', dt('You need to specify an alias or run this command within a drupal site.'));
  }

  $limit = drush_get_option('limit', 1);

  $batch = array(
    'title' => t('Importing contact details from HID'),
    'operations' => array(
      array('drush_hr_events_hid_contacts_batch_operation', array($limit)),
    ),
    'finished' => 'drush_hr_events_hid_contacts_batch_finished',
  );
  batch_set($batch);
  $batch =& batch_get();
  drush_backend_batch_process();
}

/**
 * Batch handler.
 */
// @codingStandardsIgnoreLine
function drush_hr_events_hid_contacts_batch_operation($limit = 1, &$context) {
  static $processed = array();

  if (empty($context['sandbox'])) {
    // Initiate multistep processing.
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_entity_id'] = 0;
    $context['sandbox']['max'] = $limit;
    $context['message'] = 'Starting import of HID contact details.';
  }

  // Process the next 50 nodes.
  $batch_limit = $limit > 50 ? 50 : $limit;
  $results = db_query_range("SELECT entity_id, field_hid_contact_ref_cid FROM {field_data_field_hid_contact_ref} WHERE entity_id > :entity_id AND bundle = :bundle ORDER BY entity_id ASC", 0, $batch_limit, array(':entity_id' => $context['sandbox']['current_entity_id'], ':bundle' => 'hr_event'))->fetchAll();
  dd($results, 'results');
  foreach ($results as $result) {
    $text = '';
    $wrapper = entity_metadata_wrapper('node', $result->entity_id);

    if (in_array($result->entity_id, $processed) && !empty($wrapper->field_contacts_text->value()['value'])) {
      dd($wrapper->field_contacts_text->value()['value'], '$wrapper->field_contacts_text->value() value');
      $text .= $wrapper->field_contacts_text->value()['value'] . "<br><br>";
    }

    $contact = hid_profiles_get_contact($result->field_hid_contact_ref_cid);
    if (!empty($contact->name)) {
      $text .= $contact->name;
    }
    if (!empty($contact->job_title)) {
      $text .= "<br>" . $contact->job_title;
    }
    if (!empty($contact->organizations[0]->name)) {
      $text .= "<br>" . $contact->organizations[0]->name;
    }
    if (!empty($contact->emails[0]->email)) {
      $text .= "<br>" . $contact->emails[0]->email;
    }
    if ($contact->phonesVisibility === 'anyone' && !empty($contact->phone_numbers[0]->number)) {
      $text .= "<br>" . $contact->phone_numbers[0]->number;
    }

    if (!empty($text)) {
      dd($text, 'text');
      $wrapper->field_contacts_text->set(array(
        'value' => $text,
        'format' => 'hr_wysiwyg',
      ));
      $wrapper->save();
    }

    $processed[] = $result->entity_id;

    $context['sandbox']['progress']++;
    $context['sandbox']['current_entity_id'] = $result->entity_id;
  }

  // Multistep processing : report progress.
  if ($context['sandbox']['progress'] <= $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    $context['message'] = 'Progress ' . $context['sandbox']['progress'] . '/' . $context['sandbox']['max'];
  }
}

/**
 * Finished callback.
 */
function drush_hr_events_hid_contacts_batch_finished($success, $results, $operations) {
  if ($success) {
    drush_log(t('The contact details have been imported from HID.'));
  }
  else {
    drush_log(t('There was an error importing contacts from HID.'), 'error');
  }
  cache_clear_all();
}
