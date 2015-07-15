<?php
/**
 * @file
 * hr_assessments.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function hr_assessments_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_data',
    'dependent' => 'field_asst_file',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Restricted Distribution',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_data',
    'dependent' => 'field_asst_file_rest',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Publicly Available',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_data',
    'dependent' => 'field_asst_instructions',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Not Available',
        1 => 'Not Applicable',
        2 => 'Publicly Available',
        3 => 'Restricted Distribution',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_data',
    'dependent' => 'field_asst_url',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Restricted Distribution',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_data',
    'dependent' => 'field_asst_url_rest',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Publicly Available',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_questionnaire',
    'dependent' => 'field_asst_file',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Restricted Distribution',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_questionnaire',
    'dependent' => 'field_asst_file_rest',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Publicly Available',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_questionnaire',
    'dependent' => 'field_asst_instructions',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Not Available',
        1 => 'Not Applicable',
        2 => 'Publicly Available',
        3 => 'Restricted Distribution',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_questionnaire',
    'dependent' => 'field_asst_url',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Restricted Distribution',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_questionnaire',
    'dependent' => 'field_asst_url_rest',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Publicly Available',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_report',
    'dependent' => 'field_asst_file',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Restricted Distribution',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_report',
    'dependent' => 'field_asst_file_rest',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Publicly Available',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_report',
    'dependent' => 'field_asst_instructions',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Not Available',
        1 => 'Not Applicable',
        2 => 'Publicly Available',
        3 => 'Restricted Distribution',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_report',
    'dependent' => 'field_asst_url',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Restricted Distribution',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_asst_report',
    'dependent' => 'field_asst_url_rest',
    'dependee' => 'field_asst_accessibility',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        235660466 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        200153887 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30037204 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        235660466 => array(
          1 => 1,
          3 => 0,
        ),
        200153887 => array(
          1 => 1,
          3 => 0,
        ),
        30037204 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 5,
      'value_form' => '_none',
      'values' => array(
        0 => 'Publicly Available',
        1 => 'Available on Request',
        2 => 'Not Available',
        3 => 'Not Applicable',
      ),
      'value' => array(),
    ),
  );

  return $items;
}
