<?php
/**
 * @file
 * acc_incidents.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function acc_incidents_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:map' => 'acc_incidents:map',
        'acc_incidents:master' => 'acc_incidents:master',
        'acc_incidents:table' => 'acc_incidents:table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-acc_current_search' => array(
          'module' => 'current_search',
          'delta' => 'acc_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-Tjs9NXxZSebDxkhlJjgXCd3olaAJkXWl' => array(
          'module' => 'facetapi',
          'delta' => 'Tjs9NXxZSebDxkhlJjgXCd3olaAJkXWl',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-FeT1cPJ9qLvCLY6svdGdSIiJWrS0KmeG' => array(
          'module' => 'facetapi',
          'delta' => 'FeT1cPJ9qLvCLY6svdGdSIiJWrS0KmeG',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF' => array(
          'module' => 'facetapi',
          'delta' => 'dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-c5d9XPw6uuFO30vJLSOv1r0IoBnprcaQ' => array(
          'module' => 'facetapi',
          'delta' => 'c5d9XPw6uuFO30vJLSOv1r0IoBnprcaQ',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-1ndZWpcD0rZWcvNy1gs5v0yk6Oocw8e6' => array(
          'module' => 'facetapi',
          'delta' => '1ndZWpcD0rZWcvNy1gs5v0yk6Oocw8e6',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-qR5mxuLQ4hVzdb2YOeX9Ydm5nAoKj141' => array(
          'module' => 'facetapi',
          'delta' => 'qR5mxuLQ4hVzdb2YOeX9Ydm5nAoKj141',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4' => array(
          'module' => 'facetapi',
          'delta' => 'bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents_graphs';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:graphs' => 'acc_incidents:graphs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-acc_incident_graphs-block_2' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_2',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-acc_incident_graphs-block_1' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_1',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_incident_graphs-block_3' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_3',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-acc_incident_graphs-block_4' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_4',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_incident_graphs-block_5' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_5',
          'region' => 'content',
          'weight' => '6',
        ),
        'views-d9cede631cd7c771b18188cc5ee4a307' => array(
          'module' => 'views',
          'delta' => 'd9cede631cd7c771b18188cc5ee4a307',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-698c8d70463be9d041890d880332ecb4' => array(
          'module' => 'views',
          'delta' => '698c8d70463be9d041890d880332ecb4',
          'region' => 'content',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_graphs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents_map';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:map' => 'acc_incidents:map',
        'acc_incidents:master' => 'acc_incidents:master',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-acc_incidents-map' => array(
          'module' => 'views',
          'delta' => '-exp-acc_incidents-map',
          'region' => 'branding',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_map'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents_table';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:table' => 'acc_incidents:table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-acc_incidents-table' => array(
          'module' => 'views',
          'delta' => '-exp-acc_incidents-table',
          'region' => 'branding',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_table'] = $context;

  return $export;
}
