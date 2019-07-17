<?php

/**
 * @file
 * Hooks provided by the Facet API Translation module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Defines which settings contain translatable user generated strings.
 *
 * @return array
 *   An associative array containing the module, plugin ID, and element key in
 *   the settings form that contain translatable user generated strings.
 */
function hook_facetapi_i18n_translatable_settings() {
  return array(
    // The name of the module.
    'current_search' => array(
      // The name of the plugin.
      'text' => array(
        // The name of the element containing the setting.
        'text',
      ),
      'active' => array(
        'pattern',
      ),
      'group' => array(
        'field_pattern',
      ),
    ),
  );
}

/**
 * @} End of "addtogroup hooks".
 */
