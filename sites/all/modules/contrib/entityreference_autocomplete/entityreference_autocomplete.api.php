<?php

/**
 * @file
 * API documentation for Entity Reference Autocomplete
 */

/**
 * Allows modules to alter the ajax results returned by entityreference fields.
 *
 * Use this hook to alter the data returned to users in entityreference fields,
 * for example to add some nice markup to the data, or prevent some results from
 * being returned at all.
 *
 * @param array $matches
 *   An associative array with the results to return in an entityreference field.
 * @param array $context
 *   An associative with metadata about every result contained in $matches. Each
 *   index in the array maps to an index in the $matches variables, and contains
 *   the following data:
 *    'entity'        =>      The full entity object, as loaded via EFQ,
 *    'entity_id'     =>      The ID of the entity referenced,
 *    'entity_type'   =>      The type of the entity referenced,
 *    'entity_bundle' =>      The bundle that the entity referenced belogns to,
 *    'rendered_html' =>      The html returned in the ajax selection window,
 *
 * @see entityreference_autocomplete_autocomplete_callback()
 */
function hook_entityreference_autocomplete_matches_alter(&$matches, $context) {
  foreach ($context as $match_key => $data) {
    // Look for an offensive entity label.
    if (strstr($data['rendered_html'], 'Offensive Label')) {
      // Disable this match. Don't want offensive titles in the kids section ;D.
      unset($matches[$match_key]);
    }

    // ...

    // Change colour of old entities.
    if ($data['entity_id'] < 500) {
      // Alter the html to render.
      $new_html = '<div class="clearfix" style="height:25px;background:#BBBBBB;">';
      $new_html .= $matches[$match_key];
      $new_html .= '</div>';

      // Replace the original html with the new one.
      $matches[$match_key] = $new_html;
    }
  }
}
