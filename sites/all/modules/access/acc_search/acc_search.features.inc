<?php
/**
 * @file
 * acc_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function acc_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function acc_search_default_search_api_index() {
  $items = array();
  $items['acc_search'] = entity_import('search_api_index', '{
    "name" : "Access",
    "machine_name" : "acc_search",
    "description" : null,
    "server" : "hr_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_acc_application_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_acc_date:value" : { "type" : "date" },
        "field_acc_geo_location_dest" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_acc_geo_location_dest:field_geofield:geom" : { "type" : "list\\u003Cstring\\u003E" },
        "field_acc_geo_location_dest:field_geofield:lat" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_acc_geo_location_dest:field_geofield:lon" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_acc_impacts:field_acc_impact_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_acc_impacts:field_acc_impact_value" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_acc_submission_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_acc_submitted_by" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_acc_submitted_by_org_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_acc_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_affected_organization_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_affected_organizations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_bundles" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_how_many_days" : { "type" : "integer" },
        "field_if_denied_by_whom_" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_locations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_locations:field_geofield:geom" : { "type" : "list\\u003Cstring\\u003E" },
        "field_locations:field_geofield:lat" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:field_geofield:lon" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_nationality" : { "type" : "list\\u003Cstring\\u003E" },
        "field_responsible_actors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_responsible_organization_t" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_sector" : { "type" : "integer", "entity_type" : "node" },
        "field_submitted_to" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_type_of_affectee" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "language" : { "type" : "string" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "acc_application" : "acc_application", "acc_incident" : "acc_incident" }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_acc_application_types:parents_all" : "field_acc_application_types:parents_all",
              "field_acc_type:parents_all" : "field_acc_type:parents_all"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "title_field" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "title_field" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "title_field" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "title_field" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "sorts_widget" : {
        "enabled" : false,
        "title" : "",
        "autosubmit" : false,
        "autosubmit_hide" : false
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
