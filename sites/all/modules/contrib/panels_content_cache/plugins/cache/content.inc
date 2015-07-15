<?php
/**
 * @file
 * Provides a content-based caching option for panel panes.
 */

// Plugin definition.
$plugin = array(
  'title' => t("Content cache"),
  'description' => t('Content based caching allows panel caches to be expired based on content creation / updates.'),
  'cache get' => 'panels_content_cache_get_cache',
  'cache set' => 'panels_content_cache_set_cache',
  'cache clear' => 'panels_content_cache_clear_cache',
  'settings form' => 'panels_content_cache_settings_form',
  'settings form submit' => 'panels_content_cache_settings_form_submit',
  'defaults' => array(
    'lifetime' => 'none',
    'granularity' => 'none',
  ),
);

/**
 * Get cached content.
 */
function panels_content_cache_get_cache($conf, $display, $args, $contexts, $pane = NULL) {
  $cid = panels_content_cache_get_cid($conf, $display, $args, $contexts, $pane);
  $cache = cache_get($cid, 'cache_panels');
  if (!$cache) {
    return FALSE;
  }

  if ($conf['lifetime'] != 'none' && (time() - $cache->created) > $conf['lifetime']) {
    return FALSE;
  }

  return $cache->data;
}

/**
 * Set cached content.
 */
function panels_content_cache_set_cache($conf, $content, $display, $args, $contexts, $pane = NULL) {
  $cid = panels_content_cache_get_cid($conf, $display, $args, $contexts, $pane);
  cache_set($cid, $content, 'cache_panels');
}

/**
 * Clear cached content.
 *
 * Cache clears are always for an entire display, regardless of arguments.
 *
 * Have not altered this function to take into account pane IDs (so we can
 * clear individual panes) because all the other panels caching plugins I
 * looked at did not do this either, so have left this for now as it requires
 * further investigation.
 */
function panels_content_cache_clear_cache($display) {
  $cid = panels_content_cache_get_base_cid($display);

  cache_clear_all(implode(':', $cid), 'cache_panels', TRUE);
}

/**
 * Figure out a cache id for our cache based upon input and settings.
 */
function panels_content_cache_get_cid($conf, $display, $args, $contexts, $pane) {
  $cid = panels_content_cache_get_base_cid($display);

  if ($pane) {
    $cid[] = 'pid_' . $pane->pid;
  }

  // Backwards compatibility for the old single selector on the granularity
  // option.
  if (empty($conf['granularity'])) {
    $conf['granularity'] = array();
  }
  if (!empty($conf['granularity']) && !is_array($conf['granularity'])) {
    $conf['granularity'] = array($conf['granularity'] => $conf['granularity']);
  }

  // Granularity: Page arguments.
  if (!empty($conf['granularity']['args'])) {
    foreach ($args as $pos => $arg) {
      $cid[] = 'arg_' . $pos . '_' . $arg;
    }
  }

  // Granularity: Page context.
  if (!empty($conf['granularity']['context'])) {
    if (!is_array($contexts)) {
      $contexts = array($contexts);
    }
    // Loop through each context.
    foreach ($contexts as $context) {
      // Add the plugin name.
      $plugin_pieces = array();
      if (isset($context->plugin)) {
        $cid[] = 'ctxplugin_' . $context->plugin;
        // If this is an entity, the plugin should be in the format
        // 'entity:[entity_type]', e.g. 'entity:node'. Extract this for later.
        $plugin_pieces = explode(':', $context->plugin);
      }

      // Add the argument, which is often a numeric ID.
      if (isset($context->argument)) {
        $cid[] = 'ctxarg_' . $context->argument;

        // If this is an entity, try looking for a revision_id too.
        if (!empty($plugin_pieces[0]) && $plugin_pieces[0] == 'entity' && !empty($plugin_pieces[1])) {
          if (isset($context->data) && is_object($context->data)) {
            list($entity_id, $revision_id, $bundle) = entity_extract_ids($plugin_pieces[1], $context->data);
            if (!empty($revision_id)) {
              $cid[] = 'ctxrev_' . $revision_id;
            }
          }
        }
      }
    }
  }

  // Granularity: Current page's user.
  if (!empty($conf['granularity']['user'])) {
    global $user;
    $cid[] = 'uid_' . $user->uid;
  }

  // Granularity: Current page's user roles.
  if (!empty($conf['granularity']['user_role'])) {
    global $user;

    // Anonymous.
    if (isset($user->roles[DRUPAL_ANONYMOUS_RID])) {
      $cid[] = 'anon';
    }

    // Admin.
    elseif ($user->uid == 1) {
      $cid[] = 'admin';
    }

    // Authenticated roles.
    else {
      // Clean up the settings.
      if (!empty($conf['granularity_roles_as_anon']) && is_array($conf['granularity_roles_as_anon'])) {
        // Filter out the empty values.
        $conf['granularity_roles_as_anon'] = array_filter($conf['granularity_roles_as_anon']);
      }

      // User only has one role, i.e. 'authenticated user'.
      if (count($user->roles) == 1) {
        // Optionally consider authenticated users who have no other roles to be
        // the same as anonymous users.
        if (!empty($conf['granularity_roles_as_anon'][DRUPAL_AUTHENTICATED_RID])) {
          $cid[] = 'anon';
        }
        else {
          $cid[] = 'auth';
        }
      }
      // The user has more than one role.
      else {
        $users_roles = $user->roles;

        // Make sure the "authenticated user" role isn't caught by mistake.
        unset($users_roles[DRUPAL_AUTHENTICATED_RID]);
        $users_roles = array_keys($users_roles);
        // Check if one of the user's other roles is flagged as anonymous.
        if (array_intersect($users_roles, $conf['granularity_roles_as_anon'])) {
          $cid[] = 'anon';
        }
         // The user has more than one role and none of them are marked as
        // 'anonymous'.
        else {
          // Optionally index against the first role.
          if (isset($conf['granularity_role_selection']) && $conf['granularity_role_selection'] == 'all') {
            $cid[] = 'role_' . array_shift($users_roles);
          }
          // Optionally index against the last role.
          elseif (isset($conf['granularity_role_selection']) && $conf['granularity_role_selection'] == 'last') {
            $cid[] = 'role_' . array_pop($users_roles);
          }
          // By default index against the user's concatenated roles.
          else {
            $cid[] = 'roles_' . implode(',', $users_roles);
          }
        }
      }
    }
  }

  if (module_exists('locale')) {
    global $language;
    $cid[] = 'lang_' . $language->language;
  }

  if (isset($pane->configuration, $pane->configuration['use_pager']) && $pane->configuration['use_pager'] == 1) {
    $cid[] = 'page_' . check_plain($_GET['page']);
  }

  // Take into consideration all configuration values, to avoid multiple panes
  // stomping on each other.
  if (!empty($pane->configuration)) {
    $options = _array_flatten($pane->configuration);

    // The pager was already accounted for.
    unset($options['use_pager']);

    // Remove empty values.
    $cid = array_merge($cid, array_filter($options));
  }

  return implode(':', $cid);
}

/**
 * Construct base cid for display.
 */
function panels_content_cache_get_base_cid($display) {
  $cid = array('panels_content_cache');

  // This is used in case this is an in-code display, which means did will be
  // something like 'new-1'.
  if (isset($display->owner) && isset($display->owner->id)) {
    $cid[] = 'owner_' . $display->owner->id;
  }

  $cid[] = 'did_' . $display->did;

  return $cid;
}

function panels_content_cache_settings_form($conf, $display, $pid) {
  ctools_include('dependent');

  $options = array_merge(array('none' => 'none'), drupal_map_assoc(array(15, 30, 60, 120, 180, 240, 300, 600, 900, 1200, 1800, 3600, 7200, 14400, 28800, 43200, 86400, 172800, 259200, 345600, 604800), 'format_interval'));
  $form['lifetime'] = array(
    '#title' => t('Lifetime'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => isset($conf['lifetime']) ? $conf['lifetime'] : 'none',
    '#description' => t('The cache lifetime is the minimum amount of time that will elapse before the cache is emptied and recreated. If set to none the cache will not be recreated unless a content update triggers a rebuild.')
  );

  $form['content_types'] = array(
    '#title' => t('Node types'),
    '#description' => t('Checks for new or updated nodes of any of the selected types.'),
    '#type' => 'checkboxes',
    '#options' => node_type_get_names(),
    '#default_value' => isset($conf['content_types']) ? $conf['content_types'] : array(),
    '#required' => TRUE,
  );

  if (!isset($conf['granularity'])) {
    $conf['granularity'] = array();
  }
  elseif (!is_array($conf['granularity'])) {
    $conf['granularity'] = array($conf['granularity'] => $conf['granularity']);
  }
  $form['granularity'] = array(
    '#title' => t('Granularity'),
    '#type' => 'checkboxes',
    '#options' => array(
      'args' => t('Arguments'),
      'context' => t('Context'),
      'user' => t('Active User'),
      'user_role' => t("Active user's role(s)"),
    ),
    '#description' => t('If "arguments" are selected, this content will be cached per individual argument to the entire display; if "contexts" are selected, this content will be cached per unique context in the pane or display; if "neither" there will be only one cache for this pane.'),
    '#default_value' => $conf['granularity'],
  );

  $roles = user_roles(TRUE);
  $roles[DRUPAL_AUTHENTICATED_RID] .= ' ' . t('(all logged in users with no additional roles)');
  $form['granularity_roles_as_anon'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Treat users with these role(s) as anonymous'),
    '#options' => $roles,
    '#default_value' => !empty($conf['granularity_roles_as_anon']) ? $conf['granularity_roles_as_anon'] : array(),
    '#description' => t("If the user is logged in and has one of these roles, cache the pane as if the user is anonymous. The 'authenticated user' role is only used if the user does not have any other role."),
    '#dependency' => array(
      'edit-settings-granularity-user-role' => array(1),
    ),
  );
  $form['granularity_role_selection'] = array(
    '#type' => 'radios',
    '#title' => t('How to handle multiple roles:'),
    '#options' => array(
      'all' => t('Use all matching roles; this can lead to a huge number of cache objects due to the possible combinations of roles.'),
      'first' => t('Only use first matching role; useful when roles decrease in permissiveness, e.g. Admin, Editor, Author.'),
      'last' => t('Only use last matching role; useful when roles increase in permissiveness, e.g. Author, Editor, Admin.'),
    ),
    '#default_value' => !empty($conf['granularity_role_selection']) ? $conf['granularity_role_selection'] : 'all',
    '#description' => t('If the user has more than one role, control how the additional roles are considered. This selection does not take into consideration the automatic "authenticated user" role.'),
    '#dependency' => array(
      'edit-settings-granularity-user-role' => array(1),
    ),
  );

  return $form;
}

/**
 * A copy of options_array_flatten() that doesn't rely on the Options module,
 * adjusted to properly handle objects and avoid collisions in nested arrays.
 *
 * @param array @array
 *   The array to be flattened.
 * @param string $namespace
 *   Optional prefix used to avoid array elements being overridden, thus avoid
 *   collisions.
 *
 * @return array
 *   The argument flattened into a single level.
 */
function _array_flatten($array, $namespace = NULL) {
  // Each dimension of an array will be prefixed by the parent's value.
  if (isset($namespace)) {
    $namespace .= '_';
  }

  $result = array();
  if (is_array($array)) {
    foreach ($array as $key => $value) {
      if (is_array($value) || is_object($value)) {
        $result += _array_flatten((array) $value, $namespace . $key);
      }
      else {
        $result[$namespace . $key] = $value;
      }
    }
  }
  return $result;
}
