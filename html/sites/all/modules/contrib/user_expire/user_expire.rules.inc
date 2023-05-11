<?php
/**
 * @file
 * Provides Rules integration for the User Expire module.
 */

/**
 * Implements hook_rules_action_info().
 */
function user_expire_rules_action_info() {
  $defaults = array(
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
        'save' => TRUE,
      ),
      'expiration' => array(
        'type' => 'date',
        'label' => t('Expiration date'),
        'save' => TRUE,
      ),
    ),
    'group' => t('User'),
  );
  $actions['user_expire'] = $defaults + array(
    'label' => t('Set a user expiration date'),
    'base' => 'user_expire_set_expiration',
  );
  return $actions;
}
