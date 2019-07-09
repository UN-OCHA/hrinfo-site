<?php

/**
 * @file
 * hr_jobbies.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_jobbies_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hr_job_title_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_hr_job_title_pattern'] = $strongarm;

  return $export;
}
