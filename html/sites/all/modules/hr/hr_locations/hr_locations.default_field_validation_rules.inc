<?php
/**
 * @file
 * hr_locations.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function hr_locations_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Locations PCode Unique';
  $rule->name = 'hr_locations_pcode_unique';
  $rule->field_name = 'field_pcode';
  $rule->col = 'value';
  $rule->entity_type = 'taxonomy_term';
  $rule->bundle = 'hr_location';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'The PCode must be unique';
  $export['hr_locations_pcode_unique'] = $rule;

  return $export;
}
