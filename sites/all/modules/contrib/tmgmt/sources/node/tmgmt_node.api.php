<?php

/**
 * @file
 * Hooks provided by the node source plugin for TMGMT.
 */

/**
 * Alter the created node translation.
 *
 * @param object
 *   $tnode translated node
 * @param object
 *   $node source node
 * @param TMGMTJobItem
 *   $job_item
 */
function hook_tmgmt_before_update_node_translation_alter($tnode, $node, $job_item) {
  // Always store new translations as a new revision.
  $tnode->revision = 1;
}
