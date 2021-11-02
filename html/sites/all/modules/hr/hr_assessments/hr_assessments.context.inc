<?php

/**
 * @file
 * hr_assessments.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_assessments_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_assessments_global';
  $context->description = '';
  $context->tag = 'Assessments';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_assessments:global_master' => 'hr_assessments:global_master',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        '9a75ed90e2d48b07ad8545d51a9af9d5' => array(
          'delta' => '9a75ed90e2d48b07ad8545d51a9af9d5',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'delta' => 'hr_current_search',
          'module' => 'current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-3quDa8MFI2Sa9usljzl0qr3fbusfVG93' => array(
          'delta' => '3quDa8MFI2Sa9usljzl0qr3fbusfVG93',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'system-main-menu' => array(
          'delta' => 'main-menu',
          'module' => 'system',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'outside_space' => 'outside_space',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assessments');
  $export['hr_assessments_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_assessments_global_table';
  $context->description = '';
  $context->tag = 'Assessments';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_assessments:global_table' => 'hr_assessments:global_table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        '88e7fc1471098ac2a8ab3ab9920623e2' => array(
          'delta' => '88e7fc1471098ac2a8ab3ab9920623e2',
          'module' => 'views',
          'region' => 'header_search',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'delta' => 'hr_current_search',
          'module' => 'current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-3quDa8MFI2Sa9usljzl0qr3fbusfVG93' => array(
          'delta' => '3quDa8MFI2Sa9usljzl0qr3fbusfVG93',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'system-main-menu' => array(
          'delta' => 'main-menu',
          'module' => 'system',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'outside_space' => 'outside_space',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assessments');
  $export['hr_assessments_global_table'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_assessments_space';
  $context->description = '';
  $context->tag = 'Assessments';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_assessments:master' => 'hr_assessments:master',
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
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'views--exp-hr_assessments-master' => array(
          'delta' => '-exp-hr_assessments-master',
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
  t('Assessments');
  $export['hr_assessments_space'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_assessments_space_map';
  $context->description = '';
  $context->tag = 'Assessments';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_assessments:map' => 'hr_assessments:map',
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
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'views--exp-hr_assessments-map' => array(
          'delta' => '-exp-hr_assessments-map',
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
  t('Assessments');
  $export['hr_assessments_space_map'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_assessments_space_table';
  $context->description = '';
  $context->tag = 'Assessments';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_assessments:table' => 'hr_assessments:table',
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
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'module' => 'facetapi',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'views--exp-hr_assessments-table' => array(
          'delta' => '-exp-hr_assessments-table',
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
  t('Assessments');
  $export['hr_assessments_space_table'] = $context;

  return $export;
}
