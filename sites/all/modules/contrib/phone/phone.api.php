<?php

/**
 * @file
 * Hooks provided by phone.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alter available number type options per site/field/instance.
 *
 * @param array $values
 *   An array of number type options used by phone in key => label format.
 * @param array $context
 *   An array containing:
 *   - field:    The field which is being operated on.
 *   - instance: The instance (if available) which is being operated on.
 */
function hook_phone_numbertype_values_alter(array &$values, array $context) {
  // Remove the Personal Comm. services option.
  unset($values['pcs']);

  // Update the label for the work type.
  $values['work'] = t('Office');

  // Add in some options of our own.
  $values['switch'] = t('Main switch');
  $values['direct'] = t('Direct line');
}
