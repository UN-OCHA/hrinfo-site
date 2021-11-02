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
          'delta' => 'acc_current_search',
          'module' => 'current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-1ndZWpcD0rZWcvNy1gs5v0yk6Oocw8e6' => array(
          'delta' => '1ndZWpcD0rZWcvNy1gs5v0yk6Oocw8e6',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-FeT1cPJ9qLvCLY6svdGdSIiJWrS0KmeG' => array(
          'delta' => 'FeT1cPJ9qLvCLY6svdGdSIiJWrS0KmeG',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-Tjs9NXxZSebDxkhlJjgXCd3olaAJkXWl' => array(
          'delta' => 'Tjs9NXxZSebDxkhlJjgXCd3olaAJkXWl',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4' => array(
          'delta' => 'bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-c5d9XPw6uuFO30vJLSOv1r0IoBnprcaQ' => array(
          'delta' => 'c5d9XPw6uuFO30vJLSOv1r0IoBnprcaQ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF' => array(
          'delta' => 'dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-qR5mxuLQ4hVzdb2YOeX9Ydm5nAoKj141' => array(
          'delta' => 'qR5mxuLQ4hVzdb2YOeX9Ydm5nAoKj141',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
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
        'views-698c8d70463be9d041890d880332ecb4' => array(
          'delta' => '698c8d70463be9d041890d880332ecb4',
          'module' => 'views',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-acc_incident_graphs-block_1' => array(
          'delta' => 'acc_incident_graphs-block_1',
          'module' => 'views',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_incident_graphs-block_2' => array(
          'delta' => 'acc_incident_graphs-block_2',
          'module' => 'views',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-acc_incident_graphs-block_3' => array(
          'delta' => 'acc_incident_graphs-block_3',
          'module' => 'views',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-acc_incident_graphs-block_4' => array(
          'delta' => 'acc_incident_graphs-block_4',
          'module' => 'views',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_incident_graphs-block_5' => array(
          'delta' => 'acc_incident_graphs-block_5',
          'module' => 'views',
          'region' => 'content',
          'weight' => '6',
        ),
        'views-d9cede631cd7c771b18188cc5ee4a307' => array(
          'delta' => 'd9cede631cd7c771b18188cc5ee4a307',
          'module' => 'views',
          'region' => 'content',
          'weight' => '1',
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
          'delta' => '-exp-acc_incidents-map',
          'module' => 'views',
          'region' => 'header_search',
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
          'delta' => '-exp-acc_incidents-table',
          'module' => 'views',
          'region' => 'header_search',
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
