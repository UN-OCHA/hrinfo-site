<?php
/**
 * @file
 * hr_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hr_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function hr_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "hr_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "published_safe" : 0,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
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
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "contact_real_name",
                "type" : "fulltext",
                "fields" : [ "field_last_name", "field_first_name" ],
                "description" : "A Fulltext aggregation of the following fields: Last name, First name."
              },
              "search_api_aggregation_2" : {
                "name" : "indicator_code_fulltext",
                "type" : "fulltext",
                "fields" : [ "field_ind_code" ],
                "description" : "A Fulltext aggregation of the following fields: Code."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_infographic_type:parents_all" : "field_infographic_type:parents_all",
              "field_document_type:parents_all" : "field_document_type:parents_all",
              "field_ind_cross_tagging:parents_all" : "field_ind_cross_tagging:parents_all",
              "field_ind_domain:parents_all" : "field_ind_domain:parents_all",
              "field_dataset_categories:parents_all" : "field_dataset_categories:parents_all"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_code" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "field_last_name" : true,
              "field_first_name" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_code" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "field_last_name" : true,
              "field_first_name" : true,
              "body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "body:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_code" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "field_last_name" : true,
              "field_first_name" : true,
              "body:value" : true
            },
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
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_asst_collection_method" : { "type" : "list\\u003Cstring\\u003E" },
        "field_asst_date:value" : { "type" : "date" },
        "field_asst_date:value2" : { "type" : "date" },
        "field_asst_freq" : { "type" : "string" },
        "field_asst_key_findings" : { "type" : "text" },
        "field_asst_methodology" : { "type" : "text" },
        "field_asst_other_location" : { "type" : "text", "boost" : "0.5" },
        "field_asst_status" : { "type" : "string" },
        "field_asst_subject" : { "type" : "text" },
        "field_asst_unit" : { "type" : "list\\u003Cstring\\u003E" },
        "field_bundles" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_bundles:field_sector" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_coordination_hubs" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_dataset_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dataset_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_disaster_status" : { "type" : "string" },
        "field_disasters" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_document_type:field_acronym" : { "type" : "list\\u003Ctext\\u003E" },
        "field_document_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_ds_abstract:value" : { "type" : "text" },
        "field_ds_datasources:value" : { "type" : "text" },
        "field_ds_date" : { "type" : "date" },
        "field_ds_instructions:value" : { "type" : "text" },
        "field_ds_recent_changes:value" : { "type" : "text" },
        "field_ds_summary:value" : { "type" : "text" },
        "field_event_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_date:value" : { "type" : "list\\u003Cdate\\u003E" },
        "field_event_date:value2" : { "type" : "list\\u003Cdate\\u003E" },
        "field_first_name" : { "type" : "string" },
        "field_funding_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_fundings" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_fundings:field_acronym" : { "type" : "list\\u003Ctext\\u003E" },
        "field_fundings:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_geographic_level" : { "type" : "integer", "entity_type" : "node" },
        "field_glide_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_ind_code" : { "type" : "string" },
        "field_ind_comments" : { "type" : "text", "boost" : "0.5" },
        "field_ind_cross_tagging" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_data_sources" : { "type" : "text", "boost" : "0.5" },
        "field_ind_denominator" : { "type" : "text", "boost" : "0.5" },
        "field_ind_disaggregation" : { "type" : "text", "boost" : "0.5" },
        "field_ind_domain" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_general_guidance" : { "type" : "text", "boost" : "0.5" },
        "field_ind_guidance_baseline" : { "type" : "text", "boost" : "0.5" },
        "field_ind_guidance_phases" : { "type" : "text", "boost" : "0.5" },
        "field_ind_key" : { "type" : "boolean" },
        "field_ind_numerator" : { "type" : "text", "boost" : "0.5" },
        "field_ind_response" : { "type" : "boolean" },
        "field_ind_standards" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_threshold" : { "type" : "text", "boost" : "0.5" },
        "field_ind_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_unit" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_ind_unit_desc" : { "type" : "text", "boost" : "0.5" },
        "field_infographic_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_infographic_type:field_acronym" : { "type" : "list\\u003Ctext\\u003E" },
        "field_infographic_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_languages:safe_value" : { "type" : "list\\u003Cstring\\u003E" },
        "field_last_name" : { "type" : "string" },
        "field_location" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_location:field_geofield:geom" : { "type" : "string" },
        "field_location:field_geofield:lat" : { "type" : "decimal" },
        "field_location:field_geofield:lon" : { "type" : "decimal" },
        "field_locations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_locations:field_geofield:geom" : { "type" : "list\\u003Cstring\\u003E" },
        "field_locations:field_geofield:lat" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:field_geofield:lon" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_organizations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_organizations2" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_organizations:field_acronym" : { "type" : "list\\u003Ctext\\u003E" },
        "field_organizations:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_population_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_publication_date" : { "type" : "date" },
        "field_sector" : { "type" : "integer", "entity_type" : "node" },
        "field_sectors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_terms_of_use:value" : { "type" : "text" },
        "field_themes" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_themes:field_acronym" : { "type" : "list\\u003Ctext\\u003E" },
        "field_themes:name" : { "type" : "list\\u003Ctext\\u003E" },
        "language" : { "type" : "string" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_aggregation_2" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "sorts_widget" : { "enabled" : 1, "autosubmit" : 1, "autosubmit_hide" : 1, "title" : "" }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function hr_search_default_search_api_server() {
  $items = array();
  $items['hr_solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "hr_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "dev.humanitarianresponse.info",
      "port" : "8080",
      "path" : "\\/solr\\/dev1",
      "http_user" : "root",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO",
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function hr_search_default_search_api_sort() {
  $items = array();
  $items['default_node_index__changed'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "changed",
    "name" : "Last updated",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__changed",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "settings" : {
      "default_true" : "0",
      "search_ids" : {
        "search_api_views:hr_datasets:list" : "search_api_views:hr_datasets:list",
        "search_api_views:hr_datasets:master" : "search_api_views:hr_datasets:master",
        "search_api_views:hr_datasets:table" : "search_api_views:hr_datasets:table"
      }
    },
    "options" : { "field_name" : "Date changed" }
  }');
  $items['default_node_index__created'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "created",
    "name" : "Date created",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__created",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "settings" : {
      "default_true" : "0",
      "search_ids" : {
        "search_api_views:hr_news:list" : "search_api_views:hr_news:list",
        "search_api_views:hr_news:page" : "search_api_views:hr_news:page",
        "search_api_views:hr_datasets:list" : "search_api_views:hr_datasets:list",
        "search_api_views:hr_datasets:master" : "search_api_views:hr_datasets:master",
        "search_api_views:hr_datasets:table" : "search_api_views:hr_datasets:table"
      }
    },
    "options" : { "field_name" : "Date created" }
  }');
  $items['default_node_index__field_asst_date:value'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_asst_date:value",
    "name" : "Assessment Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_asst_date:value",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "settings" : {
      "default_true" : "0",
      "search_ids" : {
        "search_api_views:hr_assessments:master" : "search_api_views:hr_assessments:master",
        "search_api_views:hr_assessments:table" : "search_api_views:hr_assessments:table"
      }
    },
    "options" : { "field_name" : "Date \\u00bb Start date" }
  }');
  $items['default_node_index__field_ds_date'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_ds_date",
    "name" : "Dataset Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_ds_date",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "settings" : {
      "default_true" : "0",
      "search_ids" : {
        "search_api_views:hr_datasets:list" : "search_api_views:hr_datasets:list",
        "search_api_views:hr_datasets:master" : "search_api_views:hr_datasets:master",
        "search_api_views:hr_datasets:table" : "search_api_views:hr_datasets:table"
      }
    },
    "options" : { "field_name" : "Dataset Date" }
  }');
  $items['default_node_index__field_first_name'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_first_name",
    "name" : "First name",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_first_name",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "settings" : {
      "default_true" : "0",
      "search_ids" : {
        "search_api_views:hr_contacts:table" : "search_api_views:hr_contacts:table",
        "search_api_views:hr_contacts:list" : "search_api_views:hr_contacts:list",
        "search_api_views:hr_contacts:master" : "search_api_views:hr_contacts:master"
      }
    },
    "options" : { "field_name" : "First name" }
  }');
  $items['default_node_index__field_last_name'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_last_name",
    "name" : "Last name",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_last_name",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "settings" : {
      "default_true" : "0",
      "search_ids" : {
        "search_api_views:hr_contacts:table" : "search_api_views:hr_contacts:table",
        "search_api_views:hr_contacts:list" : "search_api_views:hr_contacts:list",
        "search_api_views:hr_contacts:master" : "search_api_views:hr_contacts:master"
      }
    },
    "options" : { "field_name" : "Last name" }
  }');
  $items['default_node_index__field_publication_date'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_publication_date",
    "name" : "Publication Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_publication_date",
    "default_sort" : "0",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "settings" : {
      "default_true" : "0",
      "search_ids" : {
        "search_api_views:hr_documents:list" : "search_api_views:hr_documents:list",
        "search_api_views:hr_documents:table" : "search_api_views:hr_documents:table",
        "search_api_views:hr_documents:master" : "search_api_views:hr_documents:master",
        "search_api_views:hr_infographics:table" : "search_api_views:hr_infographics:table",
        "search_api_views:hr_infographics:master" : "search_api_views:hr_infographics:master"
      }
    },
    "options" : { "field_name" : "Publication Date" }
  }');
  return $items;
}
