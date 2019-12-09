<?php

/**
 * @file
 * Rules integration.
 */

/**
 * {@inheritdoc}
 */
function tmgmt_ui_rules_action_info() {
  $info['tmgmt_ui_rules_source_add_item_to_cart'] = array(
    'label' => t('Add to cart'),
    'group' => t('Translation Management'),
    'parameter' => array(
      'plugin' => array(
        'type' => 'token',
        'label' => t('Source plugin'),
        'description' => t('The source plugin of this item'),
      ),
      'item_type' => array(
        'type' => 'token',
        'label' => t('Item type'),
        'description' => t('The item type'),
      ),
      'item_id' => array(
        'type' => 'text',
        'label' => t('Item ID'),
        'description' => t('ID of the referenced item'),
      ),
    ),
  );

  return $info;
}

/**
 * Rules callback to add a job item into the cart.
 */
function tmgmt_ui_rules_source_add_item_to_cart($plugin, $item_type, $item_id) {
  tmgmt_ui_cart_get()->addJobItem($plugin, $item_type, $item_id);
}
