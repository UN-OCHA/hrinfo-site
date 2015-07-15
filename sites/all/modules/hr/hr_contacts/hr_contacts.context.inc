<?php
/**
 * @file
 * hr_contacts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_contacts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_contacts_space';
  $context->description = 'Contacts page per space';
  $context->tag = 'Contacts';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_contacts:master' => 'hr_contacts:master',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_contacts-master' => array(
          'module' => 'views',
          'delta' => '-exp-hr_contacts-master',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU' => array(
          'module' => 'facetapi',
          'delta' => 'hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  t('Contacts page per space');
  $export['hr_contacts_space'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_contacts_space_graphs';
  $context->description = '';
  $context->tag = 'Contacts';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_contacts:graphs' => 'hr_contacts:graphs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ba6eb27d208223b4acf02c1aeaf3d8bf' => array(
          'module' => 'views',
          'delta' => 'ba6eb27d208223b4acf02c1aeaf3d8bf',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-hr_contacts_graphs-by_cluster' => array(
          'module' => 'views',
          'delta' => 'hr_contacts_graphs-by_cluster',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-1426dd669d8b297763db81dc0d387a17' => array(
          'module' => 'views',
          'delta' => '1426dd669d8b297763db81dc0d387a17',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-hr_contacts_graphs-by_location' => array(
          'module' => 'views',
          'delta' => 'hr_contacts_graphs-by_location',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-d808a6a03dfc7b1b01187f1c4b62ed38' => array(
          'module' => 'views',
          'delta' => 'd808a6a03dfc7b1b01187f1c4b62ed38',
          'region' => 'content',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  $export['hr_contacts_space_graphs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_contacts_space_list';
  $context->description = '';
  $context->tag = 'Contacts';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_contacts:list' => 'hr_contacts:list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_contacts-list' => array(
          'module' => 'views',
          'delta' => '-exp-hr_contacts-list',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-uuAHMfunWRhIHXFBp9OKWcEAqAfNQ0Pu' => array(
          'module' => 'facetapi',
          'delta' => 'uuAHMfunWRhIHXFBp9OKWcEAqAfNQ0Pu',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU' => array(
          'module' => 'facetapi',
          'delta' => 'hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  $export['hr_contacts_space_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hr_contacts_space_map';
  $context->description = '';
  $context->tag = 'Contacts';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hr_contacts:map' => 'hr_contacts:map',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-hr_contacts-map' => array(
          'module' => 'views',
          'delta' => '-exp-hr_contacts-map',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'current_search-hr_current_search' => array(
          'module' => 'current_search',
          'delta' => 'hr_current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ' => array(
          'module' => 'facetapi',
          'delta' => 'ZXNTNWz3w05hh3aLGFw0ofPRZUa5biIZ',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-sp6ljjoCBKBVws0uia1DCKcDmln6TeUq' => array(
          'module' => 'facetapi',
          'delta' => 'sp6ljjoCBKBVws0uia1DCKcDmln6TeUq',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-uuAHMfunWRhIHXFBp9OKWcEAqAfNQ0Pu' => array(
          'module' => 'facetapi',
          'delta' => 'uuAHMfunWRhIHXFBp9OKWcEAqAfNQ0Pu',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17' => array(
          'module' => 'facetapi',
          'delta' => 'uulIYjH3ZtSu9hhI5ARgBYQeEUNqWe17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU' => array(
          'module' => 'facetapi',
          'delta' => 'hSnBts4Ap4yrSjQu7LKhsVdrHxAjyYKU',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z' => array(
          'module' => 'facetapi',
          'delta' => '9ew5LitJZ6pWU71gbHp1XW9oAOBwV11z',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  $export['hr_contacts_space_map'] = $context;

  return $export;
}
