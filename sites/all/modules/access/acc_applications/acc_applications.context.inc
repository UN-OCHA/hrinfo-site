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
          'module' => 'current_search',
          'delta' => 'acc_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-k1w80uxhO0sJgmNdTGkH5jcGYEVwD3v5' => array(
          'module' => 'facetapi',
          'delta' => 'k1w80uxhO0sJgmNdTGkH5jcGYEVwD3v5',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF' => array(
          'module' => 'facetapi',
          'delta' => 'dvs9HFNbA1yPbX2yB3O11ao3SK0kcNeF',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-2WTmHsFNAT5B1ZIvq8tz11Sg2g1FtVKX' => array(
          'module' => 'facetapi',
          'delta' => '2WTmHsFNAT5B1ZIvq8tz11Sg2g1FtVKX',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-IaWlGZVrJA7FTh0NHWbaDeE3QFwVwDdn' => array(
          'module' => 'facetapi',
          'delta' => 'IaWlGZVrJA7FTh0NHWbaDeE3QFwVwDdn',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-wuoP0THqqIxGaGGByNMa0TCwII79H2I2' => array(
          'module' => 'facetapi',
          'delta' => 'wuoP0THqqIxGaGGByNMa0TCwII79H2I2',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-zmFonWzXqzcyjtjn60qwNsVwHDZGdOFV' => array(
          'module' => 'facetapi',
          'delta' => 'zmFonWzXqzcyjtjn60qwNsVwHDZGdOFV',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-Bahacx6hlInI8WhUvXeBkqBCHzmk85Xe' => array(
          'module' => 'facetapi',
          'delta' => 'Bahacx6hlInI8WhUvXeBkqBCHzmk85Xe',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-0es5BMRhMD82UpEURBfd773FnVW0pHAh' => array(
          'module' => 'facetapi',
          'delta' => '0es5BMRhMD82UpEURBfd773FnVW0pHAh',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-KWo4OvAq8XxeS14QtHgf0eft21sybkZ5' => array(
          'module' => 'facetapi',
          'delta' => 'KWo4OvAq8XxeS14QtHgf0eft21sybkZ5',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-X1BhKtR0CLOkmx0fS6CfqQdQP8d0CVhn' => array(
          'module' => 'facetapi',
          'delta' => 'X1BhKtR0CLOkmx0fS6CfqQdQP8d0CVhn',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4' => array(
          'module' => 'facetapi',
          'delta' => 'bXKrYplwVKVrTXrTgRKEoABcPBPjdJM4',
          'region' => 'sidebar_first',
          'weight' => '1',
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
        'views-acc_application_repots-block_7' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_7',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_application_repots-block_8' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_8',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-acc_application_repots-block_10' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_10',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-acc_application_repots-block_11' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_11',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-acc_application_repots-block_12' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_12',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_application_repots-block_13' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_13',
          'region' => 'content',
          'weight' => '5',
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
          'module' => 'views',
          'delta' => '-exp-acc_applications-map',
          'region' => 'branding',
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
          'module' => 'views',
          'delta' => 'acc_application_repots-block',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_application_repots-block_1' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_1',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-acc_application_repots-block_2' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_2',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-acc_application_repots-block_3' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_3',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-acc_application_repots-block_4' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_4',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_application_repots-block_5' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_5',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-acc_application_repots-block_6' => array(
          'module' => 'views',
          'delta' => 'acc_application_repots-block_6',
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
          'module' => 'views',
          'delta' => '-exp-acc_applications-table',
          'region' => 'branding',
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
