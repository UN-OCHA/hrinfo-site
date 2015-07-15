<?php

/**
 * @file
 * hr_migrate module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function hr_migrate_drush_command() {
  $items = array();

  $items['hr-migrate-job-titles'] = array(
    'description' => "Migrate the job titles to a text field",
    'options' => array(
    ),
    'drupal dependencies' => array('hr_users'),
    'aliases' => array(),
  );

  $items['hr-migrate-redirects'] = array(
    'description' => "Import the redirects into multisite_redirect",
    'arguments' => array(
      'site' => 'Site URL',
      'path' => 'Path to the CSV file containing the redirects',
    ),
    'options' => array(
    ),
    'drupal dependencies' => array(),
  );

  return $items;
}

function drush_hr_migrate_job_titles() {
  // Load all profiles
  $query = new EntityFieldQuery();
  $profiles = $query->entityCondition('entity_type', 'profile2')
    ->execute();
  if (isset($profiles['profile2'])) {
    $pids = array_keys($profiles['profile2']);
    foreach ($pids as $pid) {
      $profile = profile2_load($pid);
      if (!isset($profile->field_job_title_other[LANGUAGE_NONE][0]['value'])) {
        $tid = $profile->field_job_title[LANGUAGE_NONE][0]['target_id'];
        $term = taxonomy_term_load($tid);
        $profile->field_job_title_other[LANGUAGE_NONE][0]['value'] = $term->name;
        profile2_save($profile);
      }
    }
  }

  // Load all contacts
  $query = new EntityFieldQuery();
  $contacts = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hr_contact')
    ->execute();
  if (isset($contacts['node'])) {
    $nids = array_keys($contacts['node']);
    foreach ($nids as $nid) {
      $contact = node_load($nid);
      if (!isset($contact->field_job_title_other[LANGUAGE_NONE][0]['value'])) {
        $tid = $contact->field_job_title[LANGUAGE_NONE][0]['target_id'];
        $term = taxonomy_term_load($tid);
        $contact->field_job_title_other[LANGUAGE_NONE][0]['value'] = $term->name;
        node_save($contact);
      }
    }
  }

}

function _hr_migrate_csv_to_array($filename='', $delimiter=',') {
    $header = NULL;
    $data = array();
    if (($handle = fopen($filename, 'r')) !== FALSE)
    {
        while (($row = fgetcsv($handle, 1000, $delimiter)) !== FALSE)
        {
            if(!$header)
                $header = $row;
            else
                $data[] = array_combine($header, $row);
        }
        fclose($handle);
    }
    return $data;
}

function drush_hr_migrate_redirects($site, $path) {
  // Load the CSV file
  $redirects = _hr_migrate_csv_to_array($path);
  foreach ($redirects as $redirect) {
    $mredirect = new stdClass();
    multisite_redirect_object_prepare($mredirect, array(
      'source_site' => $site,
      'source_path' => $redirect['Source URL'],
      'redirect' => str_replace('https://www.humanitarianresponse.info/', '', $redirect['Redirect URL']),
      'status_code' => '301',
    ));
    if (strlen($mredirect->source_path) <= 255 && strlen($mredirect->redirect) <= 255) {
      multisite_redirect_save($mredirect);
    }
    else {
      print "Could not add redirect: ".$mredirect->source_path;
    }
  }
}
