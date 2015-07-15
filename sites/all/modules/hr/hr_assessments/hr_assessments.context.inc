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
          'module' => 'views',
          'delta' => '9a75ed90e2d48b07ad8545d51a9af9d5',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'module' => 'facetapi',
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-3quDa8MFI2Sa9usljzl0qr3fbusfVG93' => array(
          'module' => 'facetapi',
          'delta' => '3quDa8MFI2Sa9usljzl0qr3fbusfVG93',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'module' => 'facetapi',
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'module' => 'facetapi',
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'module' => 'facetapi',
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'module' => 'facetapi',
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'module' => 'facetapi',
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'region' => 'sidebar_first',
          'weight' => '2',
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
          'module' => 'views',
          'delta' => '88e7fc1471098ac2a8ab3ab9920623e2',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-djs1o6VrivuNykMYeYyvXVKT480Y01tL' => array(
          'module' => 'facetapi',
          'delta' => 'djs1o6VrivuNykMYeYyvXVKT480Y01tL',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-3quDa8MFI2Sa9usljzl0qr3fbusfVG93' => array(
          'module' => 'facetapi',
          'delta' => '3quDa8MFI2Sa9usljzl0qr3fbusfVG93',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'module' => 'facetapi',
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'module' => 'facetapi',
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'module' => 'facetapi',
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'module' => 'facetapi',
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'module' => 'facetapi',
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'region' => 'sidebar_first',
          'weight' => '2',
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
        'views--exp-hr_assessments-master' => array(
          'module' => 'views',
          'delta' => '-exp-hr_assessments-master',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'module' => 'facetapi',
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'module' => 'facetapi',
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'module' => 'facetapi',
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'module' => 'facetapi',
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'module' => 'facetapi',
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'region' => 'sidebar_first',
          'weight' => '2',
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
        'views--exp-hr_assessments-map' => array(
          'module' => 'views',
          'delta' => '-exp-hr_assessments-map',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'module' => 'facetapi',
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'module' => 'facetapi',
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'module' => 'facetapi',
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'module' => 'facetapi',
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'module' => 'facetapi',
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'region' => 'sidebar_first',
          'weight' => '2',
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
        'views--exp-hr_assessments-table' => array(
          'module' => 'views',
          'delta' => '-exp-hr_assessments-table',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB' => array(
          'module' => 'facetapi',
          'delta' => 'MOMhTUv0Q9alQbixPzg3lFUS6pPxK0rB',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-1HNQlvc1ua7nibn1p0BYfy1NlO1GM326' => array(
          'module' => 'facetapi',
          'delta' => '1HNQlvc1ua7nibn1p0BYfy1NlO1GM326',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6' => array(
          'module' => 'facetapi',
          'delta' => '9sJg2kkCGYsSkbb4gf3WycCePRuSTnD6',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI' => array(
          'module' => 'facetapi',
          'delta' => 'P5hhFJqzUZdQ733kfRm5W7TjJpSOacnI',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-I2F0K0pK8hxp905pSaA5FBI0cS76fOV1' => array(
          'module' => 'facetapi',
          'delta' => 'I2F0K0pK8hxp905pSaA5FBI0cS76fOV1',
          'region' => 'sidebar_first',
          'weight' => '2',
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
