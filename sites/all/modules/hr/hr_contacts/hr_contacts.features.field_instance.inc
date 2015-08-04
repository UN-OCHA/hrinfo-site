<?php
/**
 * @file
 * hr_contacts.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hr_contacts_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'fieldable_panels_pane-hr_contacts-field_contacts'
  $field_instances['fieldable_panels_pane-hr_contacts-field_contacts'] = array(
    'bundle' => 'hr_contacts',
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'teaser',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
      'link' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'teaser',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_contacts',
    'label' => 'Contacts',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => 1,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'fieldable_panels_pane-hr_contacts-title_field'
  $field_instances['fieldable_panels_pane-hr_contacts-title_field'] = array(
    'bundle' => 'hr_contacts',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A field replacing fieldable panel pane title.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'link' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => FALSE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -10,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_bundles'
  $field_instances['node-hr_contact-field_bundles'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bundles',
    'label' => 'Clusters/Sectors',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'options_select',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'og_context' => 0,
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_coordination_hubs'
  $field_instances['node-hr_contact-field_coordination_hubs'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 15,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_coordination_hubs',
    'label' => 'Coordination hubs',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_disasters'
  $field_instances['node-hr_contact-field_disasters'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 16,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_disasters',
    'label' => 'Emergencies',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_email'
  $field_instances['node-hr_contact-field_email'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_email',
    'label' => 'Main Email',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_emails'
  $field_instances['node-hr_contact-field_emails'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_emails',
    'label' => 'Other emails',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_first_name'
  $field_instances['node-hr_contact-field_first_name'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_first_name',
    'label' => 'First name',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_functional_roles'
  $field_instances['node-hr_contact-field_functional_roles'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 22,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_functional_roles',
    'label' => 'Functional Roles',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_job_title_other'
  $field_instances['node-hr_contact-field_job_title_other'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter your Job Title here',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_job_title_other',
    'label' => 'Job Title',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_last_name'
  $field_instances['node-hr_contact-field_last_name'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_last_name',
    'label' => 'Last name',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_location'
  $field_instances['node-hr_contact-field_location'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Your physical location',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 13,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
          'use_chosen' => 'always',
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_locations'
  $field_instances['node-hr_contact-field_locations'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The locations you cover',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_locations',
    'label' => 'Locations',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
          'use_chosen' => 'always',
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_opt_out'
  $field_instances['node-hr_contact-field_opt_out'] = array(
    'bundle' => 'hr_contact',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_opt_out',
    'label' => 'Exclude name and details from the Humanitarian Contact List',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_organizations'
  $field_instances['node-hr_contact-field_organizations'] = array(
    'bundle' => 'hr_contact',
    'default_value' => array(),
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 9,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organizations',
    'label' => 'Organization',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_organizations_other'
  $field_instances['node-hr_contact-field_organizations_other'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you selected "Other" in the above field, please enter your organization name here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organizations_other',
    'label' => 'Organization name',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_phones'
  $field_instances['node-hr_contact-field_phones'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'phone',
        'settings' => array(
          'allow_alpha' => FALSE,
          'as_tel_link' => FALSE,
          'components' => array(
            'extension' => 'extension',
            'numbertype' => 'numbertype',
          ),
          'country_name_position' => 'after',
          'extension_prefix' => ' ext. ',
          'full_hcard' => FALSE,
          'numbertype_position' => 'before',
          'raw' => FALSE,
        ),
        'type' => 'phone_international',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'phone',
        'settings' => array(
          'allow_alpha' => FALSE,
          'as_tel_link' => FALSE,
          'components' => array(
            'extension' => 'extension',
            'numbertype' => 'numbertype',
          ),
          'country_name_position' => 'after',
          'extension_prefix' => ' ext. ',
          'full_hcard' => FALSE,
          'numbertype_position' => 'before',
          'raw' => FALSE,
        ),
        'type' => 'phone_international',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'phone',
        'settings' => array(
          'allow_alpha' => FALSE,
          'as_tel_link' => FALSE,
          'components' => array(
            'extension' => 'extension',
            'numbertype' => 'numbertype',
          ),
          'country_name_position' => 'after',
          'extension_prefix' => ' ext. ',
          'full_hcard' => FALSE,
          'numbertype_position' => 'before',
          'raw' => FALSE,
        ),
        'type' => 'phone_international',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_phones',
    'label' => 'Phones',
    'required' => 0,
    'settings' => array(
      'country_options' => array(
        'all_country_codes' => 1,
        'country_codes' => array(
          'country_selection' => array(
            '00' => 0,
            '01' => 0,
            '02' => 0,
            '03' => 0,
            '04' => 0,
            '05' => 0,
            '06' => 0,
            '07' => 0,
            '08' => 0,
            'AC' => 0,
            'AD' => 0,
            'AE' => 0,
            'AF' => 'AF',
            'AG' => 0,
            'AI' => 0,
            'AL' => 0,
            'AM' => 0,
            'AO' => 0,
            'AR' => 0,
            'AS' => 0,
            'AT' => 0,
            'AU' => 0,
            'AW' => 0,
            'AX' => 0,
            'AZ' => 0,
            'BA' => 0,
            'BB' => 0,
            'BD' => 0,
            'BE' => 0,
            'BF' => 0,
            'BG' => 0,
            'BH' => 0,
            'BI' => 0,
            'BJ' => 0,
            'BL' => 0,
            'BM' => 0,
            'BN' => 0,
            'BO' => 0,
            'BQ' => 0,
            'BR' => 0,
            'BS' => 0,
            'BT' => 0,
            'BW' => 0,
            'BY' => 0,
            'BZ' => 0,
            'CA' => 0,
            'CC' => 0,
            'CD' => 0,
            'CF' => 0,
            'CG' => 0,
            'CH' => 0,
            'CI' => 0,
            'CK' => 0,
            'CL' => 0,
            'CM' => 0,
            'CN' => 0,
            'CO' => 0,
            'CR' => 0,
            'CU' => 0,
            'CV' => 0,
            'CW' => 0,
            'CX' => 0,
            'CY' => 0,
            'CZ' => 0,
            'DE' => 0,
            'DJ' => 0,
            'DK' => 0,
            'DM' => 0,
            'DO' => 0,
            'DZ' => 0,
            'EC' => 0,
            'EE' => 0,
            'EG' => 0,
            'EH' => 0,
            'ER' => 0,
            'ES' => 0,
            'ET' => 0,
            'FI' => 0,
            'FJ' => 0,
            'FK' => 0,
            'FM' => 0,
            'FO' => 0,
            'FR' => 0,
            'GA' => 0,
            'GB' => 0,
            'GD' => 0,
            'GE' => 0,
            'GF' => 0,
            'GG' => 0,
            'GH' => 0,
            'GI' => 0,
            'GL' => 0,
            'GM' => 0,
            'GN' => 0,
            'GP' => 0,
            'GQ' => 0,
            'GR' => 0,
            'GT' => 0,
            'GU' => 0,
            'GW' => 0,
            'GY' => 0,
            'HK' => 0,
            'HN' => 0,
            'HR' => 0,
            'HT' => 0,
            'HU' => 0,
            'ID' => 0,
            'IE' => 0,
            'IL' => 0,
            'IM' => 0,
            'IN' => 0,
            'IO' => 0,
            'IQ' => 0,
            'IR' => 0,
            'IS' => 0,
            'IT' => 0,
            'JE' => 0,
            'JM' => 0,
            'JO' => 0,
            'JP' => 0,
            'KE' => 0,
            'KG' => 0,
            'KH' => 0,
            'KI' => 0,
            'KM' => 0,
            'KN' => 0,
            'KP' => 0,
            'KR' => 0,
            'KW' => 0,
            'KY' => 0,
            'KZ' => 0,
            'LA' => 0,
            'LB' => 0,
            'LC' => 0,
            'LI' => 0,
            'LK' => 0,
            'LR' => 0,
            'LS' => 0,
            'LT' => 0,
            'LU' => 0,
            'LV' => 0,
            'LY' => 0,
            'MA' => 0,
            'MC' => 0,
            'MD' => 0,
            'ME' => 0,
            'MF' => 0,
            'MG' => 0,
            'MH' => 0,
            'MK' => 0,
            'ML' => 0,
            'MM' => 0,
            'MN' => 0,
            'MO' => 0,
            'MP' => 0,
            'MQ' => 0,
            'MR' => 0,
            'MS' => 0,
            'MT' => 0,
            'MU' => 0,
            'MV' => 0,
            'MW' => 0,
            'MX' => 0,
            'MY' => 0,
            'MZ' => 0,
            'NA' => 0,
            'NC' => 0,
            'NE' => 0,
            'NF' => 0,
            'NG' => 0,
            'NI' => 0,
            'NL' => 0,
            'NO' => 0,
            'NP' => 0,
            'NR' => 0,
            'NU' => 0,
            'NZ' => 0,
            'OM' => 0,
            'PA' => 0,
            'PE' => 0,
            'PF' => 0,
            'PG' => 0,
            'PH' => 0,
            'PK' => 0,
            'PL' => 0,
            'PM' => 0,
            'PR' => 0,
            'PS' => 0,
            'PT' => 0,
            'PW' => 0,
            'PY' => 0,
            'QA' => 0,
            'RE' => 0,
            'RO' => 0,
            'RS' => 0,
            'RU' => 0,
            'RW' => 0,
            'SA' => 0,
            'SB' => 0,
            'SC' => 0,
            'SD' => 0,
            'SE' => 0,
            'SG' => 0,
            'SH' => 0,
            'SI' => 0,
            'SJ' => 0,
            'SK' => 0,
            'SL' => 0,
            'SM' => 0,
            'SN' => 0,
            'SO' => 0,
            'SR' => 0,
            'SS' => 0,
            'ST' => 0,
            'SV' => 0,
            'SX' => 0,
            'SY' => 0,
            'SZ' => 0,
            'TC' => 0,
            'TD' => 0,
            'TG' => 0,
            'TH' => 0,
            'TJ' => 0,
            'TK' => 0,
            'TL' => 0,
            'TM' => 0,
            'TN' => 0,
            'TO' => 0,
            'TR' => 0,
            'TT' => 0,
            'TV' => 0,
            'TW' => 0,
            'TZ' => 0,
            'UA' => 0,
            'UG' => 0,
            'US' => 0,
            'UY' => 0,
            'UZ' => 0,
            'VA' => 0,
            'VC' => 0,
            'VE' => 0,
            'VG' => 0,
            'VI' => 0,
            'VN' => 0,
            'VU' => 0,
            'WF' => 0,
            'WS' => 0,
            'YE' => 0,
            'YT' => 0,
            'ZA' => 0,
            'ZM' => 0,
            'ZW' => 0,
          ),
          'hide_single_cc' => 0,
        ),
        'default_country' => 'AF',
        'enable_country' => 1,
        'enable_default_country' => 1,
      ),
      'enable_extension' => 1,
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'phone',
      'settings' => array(
        'country_code_position' => 'before',
        'extension_size' => 7,
        'label_position' => 'none',
        'number_size' => 30,
        'numbertype_allowed_values_position' => 'before',
        'use_tel_input' => 1,
      ),
      'type' => 'phone',
      'weight' => 13,
    ),
  );
  // Exported field_instance: 'node-hr_contact-field_skype_id'
  $field_instances['node-hr_contact-field_skype_id'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'hr_users',
        'settings' => array(),
        'type' => 'hr_users_skype',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_skype_id',
    'label' => 'Skype ID',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 16,
    ),
  );
  // Exported field_instance: 'node-hr_contact-field_social_media'
  $field_instances['node-hr_contact-field_social_media'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'link_icons',
        'settings' => array(),
        'type' => 'link_icons',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_social_media',
    'label' => 'Social media',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-hr_contact-field_themes'
  $field_instances['node-hr_contact-field_themes'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 18,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_themes',
    'label' => 'Themes',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-hr_contact-og_group_ref'
  $field_instances['node-hr_contact-og_group_ref'] = array(
    'bundle' => 'hr_contact',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(),
        'type' => 'og_list_default',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Space(s)',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'form_error',
          'providers' => array(
            'url' => 1,
          ),
          'skip_perm' => 'administer modules',
          'status' => 1,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_list_default',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_list_default',
      ),
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 22,
    ),
  );

  // Exported field_instance:
  // 'og_membership-hr_responder-field_contact_information'
  $field_instances['og_membership-hr_responder-field_contact_information'] = array(
    'bundle' => 'hr_responder',
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'og_membership',
    'field_name' => 'field_contact_information',
    'label' => 'Contact information',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => FALSE,
          'delete_references' => 1,
          'label_plural' => 'nodes',
          'label_singular' => 'node',
          'match_operator' => 'CONTAINS',
          'override_labels' => 0,
        ),
      ),
      'type' => 'inline_entity_form_single',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-hr_functional_role-name_field'
  $field_instances['taxonomy_term-hr_functional_role-name_field'] = array(
    'bundle' => 'hr_functional_role',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Exported field_instance: 'user-user-field_responder_in'
  $field_instances['user-user-field_responder_in'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(),
        'type' => 'og_list_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(),
        'type' => 'og_list_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_responder_in',
    'label' => 'Responder in',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A field replacing fieldable panel pane title.');
  t('Clusters/Sectors');
  t('Contact information');
  t('Contacts');
  t('Coordination hubs');
  t('Emergencies');
  t('Enter your Job Title here');
  t('Exclude name and details from the Humanitarian Contact List');
  t('First name');
  t('Functional Roles');
  t('If you selected "Other" in the above field, please enter your organization name here.');
  t('Job Title');
  t('Last name');
  t('Location');
  t('Locations');
  t('Main Email');
  t('Name');
  t('Organization');
  t('Organization name');
  t('Other emails');
  t('Phones');
  t('Responder in');
  t('Social media');
  t('Space(s)');
  t('The locations you cover');
  t('Themes');
  t('Title');
  t('Your physical location');

  return $field_instances;
}
