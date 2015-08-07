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
  $items['rules_hr_submit_to_reliefweb'] = entity_import('rules_config', '{ "rules_hr_submit_to_reliefweb" : {
      "LABEL" : "Submit to Reliefweb",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_hr_reliefweb" : [] },
      "DO" : [
        { "mail" : {
            "to" : "submit@reliefweb.int",
            "subject" : "[HumanitarianResponse] New content submitted",
            "message" : "A new content was submitted on Humanitarianresponse. You can see it here: [flagged-node:url].",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
