<?php
/**
 * @file
 * hr_datasets.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hr_datasets_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-hr_dataset-field_dataset_categories'
  $field_instances['node-hr_dataset-field_dataset_categories'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '<p>Choose from COD or FOD and then click the “Add another item button”. You can apply more than one category to this record. For example you could include Admin Level 1,2 and 3 Boundaries in the same file.</p>',
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
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dataset_categories',
    'label' => 'Dataset Categories',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_dataset_types'
  $field_instances['node-hr_dataset-field_dataset_types'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'This is a <strong>multiselect</strong> field.  Choose the one or more types of data included in the dataset.  ',
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
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dataset_types',
    'label' => 'Dataset Types',
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
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_ds_abstract'
  $field_instances['node-hr_dataset-field_ds_abstract'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<strong>DO</strong> INCLUDE HERE: Include as much information as you can about the dataset. descriptions of field names, methodology used to develop the dataset, update frequency, projection, scale, limitations of the dataset (e.g. incomplete, known errors) advantages to the dataset (e.g. very accurate for a particular reason), URL for the data source.<br>
<strong>DO NOT</strong> INCLUDE HERE: information about the data types, languages, sources, and dates.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_ds_datasources'
  $field_instances['node-hr_dataset-field_ds_datasources'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'List the sources of data here. Spell out all acronyms (e.g. Central Statistics Agency (CSA)) Website of data source can be included here or in the abstract).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_datasources',
    'label' => 'Data Source(s)',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_ds_date'
  $field_instances['node-hr_dataset-field_ds_date'] = array(
    'bundle' => 'hr_dataset',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 8,
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
    'field_name' => 'field_ds_date',
    'label' => 'Dataset Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'apply_chosen' => 1,
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'none',
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-10:+0',
      ),
      'type' => 'date_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_ds_files'
  $field_instances['node-hr_dataset-field_ds_files'] = array(
    'bundle' => 'hr_dataset',
    'deleted' => 0,
    'description' => 'If you upload a file here, a link to it will be available to users.  See the <a href="https://sites.google.com/site/ochaimwiki/file-and-dataset-naming-manual/file-naming-convention">OCHA IM Wiki article on the file naming convention</a> for information about file naming for datasets. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 10,
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_files',
    'label' => 'Dataset Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'datasets',
      'file_extensions' => 'txt zip rar xls xlsx csv dbf ods gml',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_ds_instructions'
  $field_instances['node-hr_dataset-field_ds_instructions'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<strong>DO</strong> INCLUDE HERE: Information about how to access/request the dataset. (e.g. Contact information to request a dataset (<a href="https://www.humanitarianresponse.info/operations/nepal/dataset/nepal-contour-lines">example</a>) or the URL to access the dataset (<a href="https://www.humanitarianresponse.info/operations/syria/dataset/syrian-arab-republic-admin-level-1-boundaries-admin-level-2-boundaries-populated-places">example</a>).)<br>
<strong>DO NOT</strong> INLCLUDE HERE: any other information about the dataset. All other information should be in the Abstract section.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
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
    'field_name' => 'field_ds_instructions',
    'label' => 'Instructions',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_ds_recent_changes'
  $field_instances['node-hr_dataset-field_ds_recent_changes'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Describe changes to the dataset so clients know if they should download the new version or not and the impact it will have on their systems. Include the date of the changes. DO NOT provide a link to datasets from here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_recent_changes',
    'label' => 'Most Recent Changes',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_ds_summary'
  $field_instances['node-hr_dataset-field_ds_summary'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a couple words to describe the dataset more specifically than the Dataset Category.This must be completed details if it is a <strong>FOD</strong>. (examples: Storm Surg Reading, Regional Health boundaries, Obstacles, Main Roads, Trails etc).',
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
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_summary',
    'label' => 'Summary',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_email'
  $field_instances['node-hr_dataset-field_email'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => array(
      0 => array(
        'email' => 'data@humanitarianresponse.info',
      ),
    ),
    'deleted' => 0,
    'description' => '<strong>Add</strong> a generic email address for your office so questions about this dataset or the metadata can be sent to the appropriate data guardian. A default email address is provided.<br>
<strong>Add</strong> a generic email address for your office so questions about this dataset or the metadata can be sent to the appropriate data guardian. If you do not have a generic email address use <a href="data@humanitarianresponse.info">data@humanitarianresponse.info</a><br>
Suggested text: <strong>OCHA</strong> is the data guardian; send question or comments about the dataset to email.',
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
    'field_name' => 'field_email',
    'label' => 'Data Guardian',
    'required' => 1,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_languages'
  $field_instances['node-hr_dataset-field_languages'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is a <strong>multiselect</strong> field.  Choose one or more languages that are used in the dataset.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'languagefield',
        'settings' => array(
          'format' => array(
            'name' => 'name',
          ),
        ),
        'type' => 'language_default',
        'weight' => 13,
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_languages',
    'label' => 'Dataset Language(s)',
    'required' => 1,
    'settings' => array(
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_locations'
  $field_instances['node-hr_dataset-field_locations'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Select which country or region to which the dataset applies.  If you don\'t see what you are looking for here, get in touch with <a href="mailto:data@humanitarianresponse.info">data@humanitarianresponse.info</a>.',
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
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_locations',
    'label' => 'Country/Region',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-field_terms_of_use'
  $field_instances['node-hr_dataset-field_terms_of_use'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => array(
      0 => array(
        'value' => '<p>See the site&#39;s <a href="/applications/data/page/terms-use">Terms of Use</a>. &nbsp;This does not replace any terms of use information provided with the dataset.</p>
',
        'format' => 'panopoly_wysiwyg_text',
      ),
    ),
    'deleted' => 0,
    'description' => 'Indicate any information you have about limitations on the use of this data.  OCHA should generally push for datasets to be released as "public domain" to enable their use by partners such as OpenStreetMap.  For new records, this field defaults to <em>See the site\'s <a href="/applications/data/page/terms-use">Terms of Use</a>.  This does not replace any terms of use information provided with the dataset.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
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
    'field_name' => 'field_terms_of_use',
    'label' => 'Terms of Use',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-og_group_ref'
  $field_instances['node-hr_dataset-og_group_ref'] = array(
    'bundle' => 'hr_dataset',
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
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
          'fallback' => 'none',
          'og_context' => 0,
          'skip_perm' => 0,
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
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-hr_dataset-title_field'
  $field_instances['node-hr_dataset-title_field'] = array(
    'bundle' => 'hr_dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'taxonomy_term-hr_dataset_category-name_field'
  $field_instances['taxonomy_term-hr_dataset_category-name_field'] = array(
    'bundle' => 'hr_dataset_category',
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

  // Exported field_instance: 'taxonomy_term-hr_dataset_type-name_field'
  $field_instances['taxonomy_term-hr_dataset_type-name_field'] = array(
    'bundle' => 'hr_dataset_type',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Choose from COD or FOD and then click the “Add another item button”. You can apply more than one category to this record. For example you could include Admin Level 1,2 and 3 Boundaries in the same file.</p>');
  t('<strong>Add</strong> a generic email address for your office so questions about this dataset or the metadata can be sent to the appropriate data guardian. A default email address is provided.<br>
<strong>Add</strong> a generic email address for your office so questions about this dataset or the metadata can be sent to the appropriate data guardian. If you do not have a generic email address use <a href="data@humanitarianresponse.info">data@humanitarianresponse.info</a><br>
Suggested text: <strong>OCHA</strong> is the data guardian; send question or comments about the dataset to email.');
  t('<strong>DO</strong> INCLUDE HERE: Include as much information as you can about the dataset. descriptions of field names, methodology used to develop the dataset, update frequency, projection, scale, limitations of the dataset (e.g. incomplete, known errors) advantages to the dataset (e.g. very accurate for a particular reason), URL for the data source.<br>
<strong>DO NOT</strong> INCLUDE HERE: information about the data types, languages, sources, and dates.');
  t('<strong>DO</strong> INCLUDE HERE: Information about how to access/request the dataset. (e.g. Contact information to request a dataset (<a href="https://www.humanitarianresponse.info/operations/nepal/dataset/nepal-contour-lines">example</a>) or the URL to access the dataset (<a href="https://www.humanitarianresponse.info/operations/syria/dataset/syrian-arab-republic-admin-level-1-boundaries-admin-level-2-boundaries-populated-places">example</a>).)<br>
<strong>DO NOT</strong> INLCLUDE HERE: any other information about the dataset. All other information should be in the Abstract section.');
  t('Abstract');
  t('Add a couple words to describe the dataset more specifically than the Dataset Category.This must be completed details if it is a <strong>FOD</strong>. (examples: Storm Surg Reading, Regional Health boundaries, Obstacles, Main Roads, Trails etc).');
  t('Country/Region');
  t('Data Guardian');
  t('Data Source(s)');
  t('Dataset Categories');
  t('Dataset Date');
  t('Dataset Files');
  t('Dataset Language(s)');
  t('Dataset Types');
  t('Describe changes to the dataset so clients know if they should download the new version or not and the impact it will have on their systems. Include the date of the changes. DO NOT provide a link to datasets from here.');
  t('If you upload a file here, a link to it will be available to users.  See the <a href="https://sites.google.com/site/ochaimwiki/file-and-dataset-naming-manual/file-naming-convention">OCHA IM Wiki article on the file naming convention</a> for information about file naming for datasets. ');
  t('Indicate any information you have about limitations on the use of this data.  OCHA should generally push for datasets to be released as "public domain" to enable their use by partners such as OpenStreetMap.  For new records, this field defaults to <em>See the site\'s <a href="/applications/data/page/terms-use">Terms of Use</a>.  This does not replace any terms of use information provided with the dataset.</em>');
  t('Instructions');
  t('List the sources of data here. Spell out all acronyms (e.g. Central Statistics Agency (CSA)) Website of data source can be included here or in the abstract).');
  t('Most Recent Changes');
  t('Name');
  t('Select which country or region to which the dataset applies.  If you don\'t see what you are looking for here, get in touch with <a href="mailto:data@humanitarianresponse.info">data@humanitarianresponse.info</a>.');
  t('Space(s)');
  t('Summary');
  t('Terms of Use');
  t('This is a <strong>multiselect</strong> field.  Choose one or more languages that are used in the dataset.');
  t('This is a <strong>multiselect</strong> field.  Choose the one or more types of data included in the dataset.  ');
  t('Title');

  return $field_instances;
}
