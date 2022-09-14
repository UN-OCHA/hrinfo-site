<?php

/**
 * @file
 * Provides microdata integration for the phone module.
 */

/**
 * Implements hook_microdata_suggestions().
 */
function phone_microdata_suggestions() {
  $suggestions = array(
    'fields' => array(
      'phone' => array(
        'schema.org' => array(
          '#itemprop' => array('telephone'),
        ),
      ),
    ),
  );

  return $suggestions;
}
