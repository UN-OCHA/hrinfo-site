<?php

/**
 * @file
 * hr_indicators.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_indicators_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_indicators';
  $context->description = 'Indicators list';
  $context->tag = 'Indicators';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/indicators' => 'node/*/indicators',
        'node/*/indicators/*' => 'node/*/indicators/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-hr_current_search' => array(
          'delta' => 'hr_current_search',
          'module' => 'current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-PtnzOYGAQ4r54BwtIYyy1V9aQHo49u6D' => array(
          'delta' => 'PtnzOYGAQ4r54BwtIYyy1V9aQHo49u6D',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-V14egKF141IaMDUK4g0ON2bAIbD6pAjQ' => array(
          'delta' => 'V14egKF141IaMDUK4g0ON2bAIbD6pAjQ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-bHwNwkwj2M84tVpx1LhffUfGnLOMFTpe' => array(
          'delta' => 'bHwNwkwj2M84tVpx1LhffUfGnLOMFTpe',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-f4c113LvlBk1vEX2ZVgm2yIp1AhJsctR' => array(
          'delta' => 'f4c113LvlBk1vEX2ZVgm2yIp1AhJsctR',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-u1Qk386Hm2lt1tjgYiA6LLBeJgHjuvX8' => array(
          'delta' => 'u1Qk386Hm2lt1tjgYiA6LLBeJgHjuvX8',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-y9mSyuIVQ73femuK1MdF1RhmRBG5xKkl' => array(
          'delta' => 'y9mSyuIVQ73femuK1MdF1RhmRBG5xKkl',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views--exp-hr_indicators-table' => array(
          'delta' => '-exp-hr_indicators-table',
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
  t('Indicators');
  t('Indicators list');
  $export['hr_indicators'] = $context;

  return $export;
}
