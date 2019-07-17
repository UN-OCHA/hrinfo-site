<?php
/**
 * @file
 * hr_indicators.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function hr_indicators_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Unique Indicators code';
  $rule->name = 'hr_indicators_code_unique';
  $rule->field_name = 'field_ind_code';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'hr_indicator';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      30037204 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'The indicator code must be unique';
  $export['hr_indicators_code_unique'] = $rule;

  return $export;
}
