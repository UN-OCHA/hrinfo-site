<?php

/**
 * @file
 * Hooks provided by this module.
 *
 * @author Jim Berry ("solotandem", http://drupal.org/user/240748)
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alter the state of snippet insertion on the current page response.
 *
 * This hook allows other modules to alter the state of snippet insertion based
 * on custom conditions that cannot be defined by the status, path, and role
 * conditions provided by this module.
 *
 * @param bool $satisfied
 *   The snippet insertion state.
 * @param GTMContainer $container
 *   The associated container object.
 */
function hook_google_tag_insert_alter(&$satisfied, $container) {
  // Do something to the state.
  $state = !$state;
}

/**
 * Alter the realm values for the current page response.
 *
 * This hook allows other modules to alter the realm values that affect the
 * snippets to be inserted.
 *
 * @param array $realm
 *   Associative array of realm values keyed by name and key.
 */
function hook_google_tag_realm_alter(array &$realm) {
  // Do something to the realm values.
  $realm['name'] = 'my_realm';
  $realm['key'] = 'my_key';
}

/**
 * Alter the snippets to be inserted on a page response.
 *
 * This hook allows other modules to alter the snippets to be inserted based on
 * custom settings not defined by this module.
 *
 * @param array $snippets
 *   Associative array of snippets keyed by type: script, noscript and
 *   data_layer.
 * @param GTMContainer $container
 *   The associated container object.
 */
function hook_google_tag_snippets_alter(array &$snippets, $container) {
  // Do something to the script snippet.
  $snippets['script'] = str_replace('insertBefore', 'insertAfter', $snippets['script']);
}

/**
 * Alter the insertion condition types.
 *
 * This hook allows other modules to alter the insertion condition types. The
 * types affect the condition fieldsets displayed on the container form as well
 * as the the condition checks made before the snippets are inserted on a page
 * response.
 *
 * If a module adds a type not defined by this module, then it is responsible to
 * implement the condition type or ensure the module dependency is met.
 *
 * To implement a condition type requires two functions:
 * - _google_tag_variable_info_[type]
 * - _google_tag_condition_evaluate_[type]
 * For examples, see:
 * - includes/variable.inc file
 * - includes/entity/container.inc (the genericCheck routine)
 *
 * @param array $types
 *   Associative array of condition item arrays keyed by type.
 *   Each condition item array has the following keys:
 *   'file': relative path to file with implementing routines
 *   'title': fieldset title
 *   (optional) 'description': 'fieldset description'
 */
function hook_google_tag_conditions_alter(array &$types) {
  // Add custom condition.
  $types['my_type'] = array(
    'file' => drupal_get_path('module', 'my_module') . '/includes/gtag.inc',
    'title' => t('fieldset title'),
    'description' => t('fieldset description'),
  );
}
