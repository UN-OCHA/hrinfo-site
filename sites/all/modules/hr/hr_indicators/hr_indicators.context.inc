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
        'views--exp-hr_indicators-table' => array(
          'module' => 'views',
          'delta' => '-exp-hr_indicators-table',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-V14egKF141IaMDUK4g0ON2bAIbD6pAjQ' => array(
          'module' => 'facetapi',
          'delta' => 'V14egKF141IaMDUK4g0ON2bAIbD6pAjQ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-y9mSyuIVQ73femuK1MdF1RhmRBG5xKkl' => array(
          'module' => 'facetapi',
          'delta' => 'y9mSyuIVQ73femuK1MdF1RhmRBG5xKkl',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-f4c113LvlBk1vEX2ZVgm2yIp1AhJsctR' => array(
          'module' => 'facetapi',
          'delta' => 'f4c113LvlBk1vEX2ZVgm2yIp1AhJsctR',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-u1Qk386Hm2lt1tjgYiA6LLBeJgHjuvX8' => array(
          'module' => 'facetapi',
          'delta' => 'u1Qk386Hm2lt1tjgYiA6LLBeJgHjuvX8',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-bHwNwkwj2M84tVpx1LhffUfGnLOMFTpe' => array(
          'module' => 'facetapi',
          'delta' => 'bHwNwkwj2M84tVpx1LhffUfGnLOMFTpe',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-PtnzOYGAQ4r54BwtIYyy1V9aQHo49u6D' => array(
          'module' => 'facetapi',
          'delta' => 'PtnzOYGAQ4r54BwtIYyy1V9aQHo49u6D',
          'region' => 'sidebar_first',
          'weight' => '-3',
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
