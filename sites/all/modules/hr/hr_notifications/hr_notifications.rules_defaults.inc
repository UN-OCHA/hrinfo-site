<?php
/**
 * @file
 * hr_notifications.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function hr_notifications_default_rules_configuration() {
  $items = array();
  $items['rules_administrator_member'] = entity_import('rules_config', '{ "rules_administrator_member" : {
      "LABEL" : "administrator member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "USES VARIABLES" : {
        "account_type" : { "label" : "account", "type" : "user" },
        "group" : { "label" : "group", "type" : "og_membership" },
        "node" : { "label" : "node", "type" : "node" },
        "entity_type" : { "label" : "entity", "type" : "entity" }
      },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "group:group" ], "type" : "node" } },
        { "og_user_has_role" : {
            "account" : [ "account-type" ],
            "group" : [ "group:group" ],
            "roles" : { "value" : { "administrator member" : "administrator member" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "site:og-context--node" ] },
            "PROVIDE" : { "variable_added" : { "group_name" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account-type:mail" ],
            "subject" : "Your  membership request was approved for \\u0027[group-name:title]\\u0027",
            "message" : "Dear [account-type:name],\\r\\n\\r\\nWelcome to HumanitarianResponse.info platform [group-name:title]. \\r\\n\\r\\nWe wanted to let you know that you are now an administrative member of the page [group-name:title] located at [group-name:url].\\r\\n\\r\\nAs a manager you have entire control of your pages: You can design your pages as you wish, add documents, create new pages, etc. You can also add others as managers or editors. To give you some guidance on how to work with the platform, please check out https:\\/\\/www.humanitarianresponse.info\\/help . If you run into trouble, please contact the OCHA Information Management Officer in country or write to us at help@humanitarianresponse.info .\\r\\n\\r\\nWe hope you will enjoy the HR.info services!\\r\\n\\r\\nYour HR.info team Site: www.humanitarianresponse.info Animation: https:\\/\\/youtu.be\\/OAzNjYtabuM Twitter: https:\\/\\/twitter.com\\/humresponse",
            "language" : [ "account-type:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_bundle_member'] = entity_import('rules_config', '{ "rules_bundle_member" : {
      "LABEL" : "bundle member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "USES VARIABLES" : {
        "account_type" : { "label" : "account", "type" : "user" },
        "group" : { "label" : "group", "type" : "og_membership" },
        "node" : { "label" : "node", "type" : "node" },
        "entity_type" : { "label" : "entity", "type" : "entity" }
      },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "group:group" ], "type" : "node" } },
        { "og_user_has_role" : {
            "account" : [ "account-type" ],
            "group" : [ "group:group" ],
            "roles" : { "value" : { "bundle member" : "bundle member" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "site:og-context--node" ] },
            "PROVIDE" : { "variable_added" : { "group_name" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account-type:mail" ],
            "subject" : "Your  membership request was approved for \\u0027[group-name:title]\\u0027",
            "message" : "[account-type:name],\\r\\n\\r\\nYou are now a member in the group \\u0027[group_name:title]\\u0027 located at [group-name:url]",
            "language" : [ "account-type:language" ]
          }
        },
        { "mail" : {
            "to" : [ "group-name:author:mail" ],
            "subject" : "[account-type:name] joined [group-name:title]",
            "message" : "[group-name:author:name],\\r\\n\\r\\n[account-type:name] joined [group-name:title] in [group-name:url]",
            "language" : [ "account-type:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_contributor'] = entity_import('rules_config', '{ "rules_contributor" : {
      "LABEL" : "contributor",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "USES VARIABLES" : {
        "account_type" : { "label" : "account", "type" : "user" },
        "group" : { "label" : "group", "type" : "og_membership" },
        "node" : { "label" : "node", "type" : "node" },
        "entity_type" : { "label" : "entity", "type" : "entity" }
      },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "group:group" ], "type" : "node" } },
        { "og_user_has_role" : {
            "account" : [ "account-type" ],
            "group" : [ "group:group" ],
            "roles" : { "value" : { "contributor" : "contributor" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "site:og-context--node" ] },
            "PROVIDE" : { "variable_added" : { "group_name" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account-type:mail" ],
            "subject" : "Your  membership request was approved for \\u0027[group-name:title]\\u0027",
            "message" : "Dear [account-type:name],\\r\\n\\r\\nWelcome to HumanitarianResponse.info platform [group-name:title]. \\r\\n\\r\\nWe wanted to let you know that you are now a contributor of the page [group-name:title] located at [group-name:url].\\r\\n\\r\\nAs a contributor you have entire control of your pages: You have the capability to add new content to the site but those content are not published to the site right away.To give you some guidance on how to work with the platform, please check out https:\\/\\/www.humanitarianresponse.info\\/help . If you run into trouble, please contact the OCHA Information Management Officer in country or write to us at help@humanitarianresponse.info .\\r\\n\\r\\nWe hope you will enjoy the HR.info services!\\r\\n\\r\\nYour HR.info team\\r\\nSite: www.humanitarianresponse.info\\r\\nAnimation: https:\\/\\/youtu.be\\/OAzNjYtabuM\\r\\nTwitter: https:\\/\\/twitter.com\\/humresponse",
            "language" : [ "account-type:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_editor_'] = entity_import('rules_config', '{ "rules_editor_" : {
      "LABEL" : "editor ",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "USES VARIABLES" : {
        "account_type" : { "label" : "account", "type" : "user" },
        "group" : { "label" : "group", "type" : "og_membership" },
        "node" : { "label" : "node", "type" : "node" },
        "entity_type" : { "label" : "entity", "type" : "entity" }
      },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "group:group" ], "type" : "node" } },
        { "og_user_has_role" : {
            "account" : [ "account-type" ],
            "group" : [ "group:group" ],
            "roles" : { "value" : { "editor" : "editor" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "site:og-context--node" ] },
            "PROVIDE" : { "variable_added" : { "group_name" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account-type:mail" ],
            "subject" : "Your  membership request was approved for \\u0027[group-name:title]\\u0027",
            "message" : "Dear [account-type:name],\\r\\n\\r\\nWelcome to HumanitarianResponse.info platform [group-name:title]. \\r\\n\\r\\nWe wanted to let you know that you are now an editor of the page [group-name:title] located at [group-name:url].\\r\\n\\r\\nAs an editor you have enough permission to manage the site content by adding, editing or removing the existing content to keep the overall website up-to-date. To give you some guidance on how to work with the platform, please check out https:\\/\\/www.humanitarianresponse.info\\/help . If you run into trouble, please contact the OCHA Information Management Officer in country or write to us at help@humanitarianresponse.info .\\r\\n\\r\\nWe hope you will enjoy the HR.info services!\\r\\n\\r\\nYour HR.info team\\r\\nSite: www.humanitarianresponse.info\\r\\nAnimation: https:\\/\\/youtu.be\\/OAzNjYtabuM\\r\\nTwitter: https:\\/\\/twitter.com\\/humresponse\\r\\n\\r\\n\\r\\n\\r\\n\\r\\n",
            "language" : [ "account-type:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_hr_submit_to_reliefweb'] = entity_import('rules_config', '{ "rules_hr_submit_to_reliefweb" : {
      "LABEL" : "Submit to Reliefweb",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_hr_reliefweb" : [] },
      "DO" : [
        { "mail" : {
            "to" : "submit@reliefweb.int",
            "subject" : "[HumanitarianResponse] New content submitted : [flagged-node:title]",
            "message" : "A new [flagged-node:content-type] ([flagged-node:title]) was submitted on Humanitarianresponse.\r\n\r\nSpace(s): [flagged-node:og_group_ref]\r\nOrganization: [flagged-node:field-organizations]\r\nPublication Date: [flagged-node:field-publication-date]\r\nDocument type: [flagged-node:field-document-type]\r\n\r\nYou can see it here: [flagged-node:url].",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_manager'] = entity_import('rules_config', '{ "rules_manager" : {
      "LABEL" : "manager",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "USES VARIABLES" : {
        "account_type" : { "label" : "account", "type" : "user" },
        "group" : { "label" : "group", "type" : "og_membership" },
        "node" : { "label" : "node", "type" : "node" },
        "entity_type" : { "label" : "entity", "type" : "entity" }
      },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "group:group" ], "type" : "node" } },
        { "og_user_has_role" : {
            "account" : [ "account-type" ],
            "group" : [ "group:group" ],
            "roles" : { "value" : { "manager" : "manager" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "site:og-context--node" ] },
            "PROVIDE" : { "variable_added" : { "group_name" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account-type:mail" ],
            "subject" : "Your  membership request was approved for \\u0027[group-name:title]\\u0027",
            "message" : "Dear [account-type:name],\\r\\n\\r\\nWelcome to HumanitarianResponse.info platform [group-name:title]. \\r\\n\\r\\nWe wanted to let you know that you are now a manager of the page [group-name:title] located at [group-name:url].\\r\\n\\r\\nAs a manager you have entire control of your pages: You can design your pages as you wish, add documents, create new pages, etc. You can also add others as managers or editors. To give you some guidance on how to work with the platform, please check out https:\\/\\/www.humanitarianresponse.info\\/help . If you run into trouble, please contact the OCHA Information Management Officer in country or write to us at help@humanitarianresponse.info .\\r\\n\\r\\nWe hope you will enjoy the HR.info services!\\r\\n\\r\\nYour HR.info team\\r\\nSite: www.humanitarianresponse.info\\r\\nAnimation: https:\\/\\/youtu.be\\/OAzNjYtabuM\\r\\nTwitter: https:\\/\\/twitter.com\\/humresponse",
            "language" : [ "account-type:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_notify_editor'] = entity_import('rules_config', '{ "rules_notify_editor" : {
      "LABEL" : "Cluster and Operations User Notifications",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_role_grant" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "OR" : [
            { "node_is_of_type" : {
                "node" : [ "og-membership:group" ],
                "type" : { "value" : { "hr_operation" : "hr_operation" } }
              }
            },
            { "node_is_of_type" : {
                "node" : [ "site:og-context--node" ],
                "type" : { "value" : { "hr_bundle" : "hr_bundle" } }
              }
            }
          ]
        },
        { "og_entity_in_group" : { "entity" : [ "account" ], "group" : [ "site:og-context--node" ] } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "site:og-context--node" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "component_rules_editor_" : {
            "account_type" : [ "account" ],
            "group" : [ "og-membership" ],
            "node" : [ "site:og-context--node" ],
            "entity_type" : [ "group" ]
          }
        },
        { "component_rules_manager" : {
            "account_type" : [ "account" ],
            "group" : [ "og-membership" ],
            "node" : [ "site:og-context--node" ],
            "entity_type" : [ "group" ]
          }
        },
        { "component_rules_contributor" : {
            "account_type" : [ "account" ],
            "group" : [ "og-membership" ],
            "node" : [ "site:og-context--node" ],
            "entity_type" : [ "group" ]
          }
        }
      ]
    }
  }');
  return $items;
}
