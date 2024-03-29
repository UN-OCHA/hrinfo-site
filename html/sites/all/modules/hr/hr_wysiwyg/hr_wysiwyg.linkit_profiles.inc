<?php

/**
 * @file
 * hr_wysiwyg.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function hr_wysiwyg_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'content_editors';
  $linkit_profile->admin_title = 'Content Editors';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'remoteTimeout' => '10000',
      'wait' => '350',
    ),
    'button_text' => 'Search',
    'entity:bean' => array(
      'result_description' => '',
    ),
    'entity:fieldable_panels_pane' => array(
      'bundles' => array(
        'fieldable_panels_pane' => 0,
        'hr_assessments' => 0,
        'hr_contacts' => 0,
        'hr_documents' => 0,
        'hr_infographics' => 0,
      ),
      'group_by_bundle' => 0,
      'result_description' => '',
    ),
    'entity:file' => array(
      'bundles' => array(
        'audio' => 0,
        'document' => 0,
        'image' => 0,
        'video' => 0,
      ),
      'group_by_bundle' => 0,
      'group_by_scheme' => 0,
      'image_extra_info' => array(
        'dimensions' => 'dimensions',
        'thumbnail' => 'thumbnail',
      ),
      'result_description' => '',
      'show_scheme' => 0,
      'url_type' => 'entity',
    ),
    'entity:node' => array(
      'bundles' => array(
        'acc_application' => 0,
        'acc_incident' => 0,
        'hr_assessment' => 0,
        'hr_bundle' => 0,
        'hr_disaster' => 0,
        'hr_document' => 0,
        'hr_event' => 0,
        'hr_indicator' => 0,
        'hr_infographic' => 0,
        'hr_news' => 0,
        'hr_office' => 0,
        'hr_operation' => 0,
        'hr_page' => 0,
        'hr_sector' => 0,
        'hr_space' => 0,
        'hr_toolbox_category' => 0,
        'hr_toolbox_item' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
      'result_description' => '[node:title]',
    ),
    'entity:profile2' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:taxonomy_term' => array(
      'bundles' => array(
        'acc_application_submission_status' => 0,
        'acc_application_types' => 0,
        'acc_impact_types' => 0,
        'acc_incident_types' => 0,
        'acc_responsible_actors' => 0,
        'acc_type_of_aid_workers' => 0,
        'hr_dataset_category' => 0,
        'hr_dataset_type' => 0,
        'hr_document_type' => 0,
        'hr_event_category' => 0,
        'hr_functional_role' => 0,
        'hr_glide_type' => 0,
        'hr_indicator_domain' => 0,
        'hr_indicator_standard' => 0,
        'hr_indicator_type' => 0,
        'hr_indicator_unit' => 0,
        'hr_infographic_type' => 0,
        'hr_job_title' => 0,
        'hr_location' => 0,
        'hr_organization' => 0,
        'hr_organization_type' => 0,
        'hr_population_type' => 0,
        'hr_space_category' => 0,
        'hr_theme' => 0,
      ),
      'group_by_bundle' => 0,
      'result_description' => '',
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'url_method' => '2',
    ),
    'search_plugins' => array(
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:fieldable_panels_pane' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:profile2' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'text_formats' => array(
      'filtered_html' => 0,
      'full_html' => 0,
      'hr_wysiwyg' => 'hr_wysiwyg',
      'hr_wysiwyg_trusted' => 0,
      'panopoly_html_text' => 'panopoly_html_text',
      'panopoly_wysiwyg_text' => 'panopoly_wysiwyg_text',
      'php_code' => 0,
      'plain_text' => 0,
    ),
  );
  $linkit_profile->weight = 0;
  $export['content_editors'] = $linkit_profile;

  return $export;
}
