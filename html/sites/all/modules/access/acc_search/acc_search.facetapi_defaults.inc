<?php

/**
 * @file
 * acc_search.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function acc_search_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search::field_acc_date:value';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = '';
  $facet->facet = 'field_acc_date:value';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'date_granularity' => 'DAY',
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => 0,
    'hard_limit' => '50',
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'field_acc_date:value',
    'query_type' => 'date',
  );
  $export['search_api@acc_search::field_acc_date:value'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search::field_acc_type';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = '';
  $facet->facet = 'field_acc_type';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'exclude' => 0,
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => '0',
    'hard_limit' => '50',
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'field_acc_type',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'acc_application_submission_status',
    'query_type' => 'term',
  );
  $export['search_api@acc_search::field_acc_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:created';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'created';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:created'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_application_types';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_application_types';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_application_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_date:value';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_date:value';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'hr_wysiwyg',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_date:value'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_geo_location_dest';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_geo_location_dest';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_geo_location_dest'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_impacts:field_acc_impact_type';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_impacts:field_acc_impact_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_impacts:field_acc_impact_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_impacts:field_acc_impact_value';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_impacts:field_acc_impact_value';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_impacts:field_acc_impact_value'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_submission_status';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_submission_status';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_submission_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_submitted_by';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_submitted_by';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_submitted_by'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_submitted_by_org_type';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_submitted_by_org_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_submitted_by_org_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_acc_type';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_acc_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'hr_wysiwyg',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 1,
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_acc_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_affected_organization_type';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_affected_organization_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_affected_organization_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_affected_organizations';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_affected_organizations';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_affected_organizations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_bundles';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_bundles';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_bundles'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_date_app:value';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_date_app:value';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_date_app:value'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_if_denied_by_whom_';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_if_denied_by_whom_';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_if_denied_by_whom_'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_locations';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_locations';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_locations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_nationality';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_nationality';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_nationality'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_responsible_actors';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_responsible_actors';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_responsible_actors'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_responsible_organization_t';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_responsible_organization_t';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_responsible_organization_t'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_submitted_to';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_submitted_to';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_submitted_to'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@acc_search:block:field_type_of_affectee';
  $facet->searcher = 'search_api@acc_search';
  $facet->realm = 'block';
  $facet->facet = 'field_type_of_affectee';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'empty_behavior' => 'none',
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => 20,
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'weight' => 0,
    'widget' => 'facetapi_links',
  );
  $export['search_api@acc_search:block:field_type_of_affectee'] = $facet;

  return $export;
}
