<?php

/**
 * @file
 * acc_applications.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function acc_applications_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_applications';
  $context->description = '';
  $context->tag = 'Access Applications';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_applications:map' => 'acc_applications:map',
        'acc_applications:master' => 'acc_applications:master',
        'acc_applications:table' => 'acc_applications:table',
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
        'facetapi-0es5BMRhMD82UpEURBfd773FnVW0pHAh' => array(
          'delta' => '0es5BMRhMD82UpEURBfd773FnVW0pHAh',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-2WTmHsFNAT5B1ZIvq8tz11Sg2g1FtVKX' => array(
          'delta' => '2WTmHsFNAT5B1ZIvq8tz11Sg2g1FtVKX',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-Bahacx6hlInI8WhUvXeBkqBCHzmk85Xe' => array(
          'delta' => 'Bahacx6hlInI8WhUvXeBkqBCHzmk85Xe',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-IaWlGZVrJA7FTh0NHWbaDeE3QFwVwDdn' => array(
          'delta' => 'IaWlGZVrJA7FTh0NHWbaDeE3QFwVwDdn',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-KWo4OvAq8XxeS14QtHgf0eft21sybkZ5' => array(
          'delta' => 'KWo4OvAq8XxeS14QtHgf0eft21sybkZ5',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-X1BhKtR0CLOkmx0fS6CfqQdQP8d0CVhn' => array(
          'delta' => 'X1BhKtR0CLOkmx0fS6CfqQdQP8d0CVhn',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4' => array(
          'delta' => 'bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF' => array(
          'delta' => 'dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-k1w80uxhO0sJgmNdTGkH5jcGYEVwD3v5' => array(
          'delta' => 'k1w80uxhO0sJgmNdTGkH5jcGYEVwD3v5',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-wuoP0THqqIxGaGGByNMa0TCwII79H2I2' => array(
          'delta' => 'wuoP0THqqIxGaGGByNMa0TCwII79H2I2',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-zmFonWzXqzcyjtjn60qwNsVwHDZGdOFV' => array(
          'delta' => 'zmFonWzXqzcyjtjn60qwNsVwHDZGdOFV',
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
  t('Access Applications');
  $export['acc_applications'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_applications_imp_reports';
  $context->description = '';
  $context->tag = 'Access Applications';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_applications:imp_reports' => 'acc_applications:imp_reports',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-acc_application_repots-block_10' => array(
          'delta' => 'acc_application_repots-block_10',
          'module' => 'views',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-acc_application_repots-block_11' => array(
          'delta' => 'acc_application_repots-block_11',
          'module' => 'views',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-acc_application_repots-block_12' => array(
          'delta' => 'acc_application_repots-block_12',
          'module' => 'views',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_application_repots-block_13' => array(
          'delta' => 'acc_application_repots-block_13',
          'module' => 'views',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-acc_application_repots-block_7' => array(
          'delta' => 'acc_application_repots-block_7',
          'module' => 'views',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_application_repots-block_8' => array(
          'delta' => 'acc_application_repots-block_8',
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
  t('Access Applications');
  $export['acc_applications_imp_reports'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_applications_map';
  $context->description = '';
  $context->tag = 'Access Applications';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_applications:map' => 'acc_applications:map',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-acc_applications-map' => array(
          'delta' => '-exp-acc_applications-map',
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
  t('Access Applications');
  $export['acc_applications_map'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_applications_reports';
  $context->description = '';
  $context->tag = 'Access Applications';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_applications:res_reports' => 'acc_applications:res_reports',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-acc_application_repots-block' => array(
          'delta' => 'acc_application_repots-block',
          'module' => 'views',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_application_repots-block_1' => array(
          'delta' => 'acc_application_repots-block_1',
          'module' => 'views',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-acc_application_repots-block_2' => array(
          'delta' => 'acc_application_repots-block_2',
          'module' => 'views',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-acc_application_repots-block_3' => array(
          'delta' => 'acc_application_repots-block_3',
          'module' => 'views',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-acc_application_repots-block_4' => array(
          'delta' => 'acc_application_repots-block_4',
          'module' => 'views',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_application_repots-block_5' => array(
          'delta' => 'acc_application_repots-block_5',
          'module' => 'views',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-acc_application_repots-block_6' => array(
          'delta' => 'acc_application_repots-block_6',
          'module' => 'views',
          'region' => 'content',
          'weight' => '6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Applications');
  $export['acc_applications_reports'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_applications_table';
  $context->description = '';
  $context->tag = 'Access Applications';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_applications:master' => 'acc_applications:master',
        'acc_applications:table' => 'acc_applications:table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-acc_applications-table' => array(
          'delta' => '-exp-acc_applications-table',
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
  t('Access Applications');
  $export['acc_applications_table'] = $context;

  return $export;
}
