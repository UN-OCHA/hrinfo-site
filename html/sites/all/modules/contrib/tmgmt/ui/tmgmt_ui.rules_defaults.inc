<?php

/*
 * @file
 * Contains default rules.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function tmgmt_ui_default_rules_configuration() {
  $data = '{ "rules_tmgmt_job_accept_translation" : {
      "LABEL" : "Accept Translation",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "tmgmt" ],
      "USES VARIABLES" : { "job" : { "label" : "Job", "type" : "tmgmt_job" } },
      "DO" : [ { "tmgmt_rules_job_accept_translation" : { "job" : [ "job" ] } } ]
    }
  }';
  $rule = rules_import($data);
  $configs[$rule->name] = $rule;
  $data = '{ "rules_tmgmt_job_abort_translation" : {
      "LABEL" : "Abort Translation",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "tmgmt" ],
      "USES VARIABLES" : { "job" : { "label" : "Job", "type" : "tmgmt_job" } },
      "DO" : [ { "tmgmt_rules_job_abort_translation" : { "job" : [ "job" ] } } ]
    }
  }';
  $rule = rules_import($data);
  $configs[$rule->name] = $rule;
  $data = '{ "rules_tmgmt_job_delete" : {
      "LABEL" : "Delete Job",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "tmgmt" ],
      "USES VARIABLES" : { "job" : { "label" : "Job", "type" : "tmgmt_job" } },
      "DO" : [ { "tmgmt_rules_job_delete" : { "job" : [ "job" ] } } ]
    }
  }';
  $rule = rules_import($data);
  $configs[$rule->name] = $rule;
  $data = '{ "tmgmt_node_ui_tmgmt_nodes_add_items_to_cart" : {
      "LABEL" : "Add to cart",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "tmgmt", "rules", "tmgmt_ui" ],
      "USES VARIABLES" : { "nodes" : { "label" : "Nodes", "type" : "list\u003Cnode\u003E" } },
      "DO" : [
        { "tmgmt_get_first_from_node_list" : {
            "USING" : { "list" : [ "nodes" ] },
            "PROVIDE" : { "first_node" : { "first_node" : "Node" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "nodes" ] },
            "ITEM" : { "node" : "Node" },
            "DO" : [
              { "tmgmt_ui_rules_source_add_item_to_cart" : { "plugin" : "node", "item_type" : "node", "item_id" : "[node:nid]" } }
            ]
          }
        }
      ]
    }
  }';
  $rule = rules_import($data);
  $configs[$rule->name] = $rule;
  return $configs;
}
