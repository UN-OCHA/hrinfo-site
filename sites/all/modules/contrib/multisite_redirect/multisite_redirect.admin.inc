<?php
/**
 * @file
 * Contains admin form callbacks.
 */

/**
 * Settings form callback.
 */
function multisite_redirect_settings_form($form, &$form_state) {
  global $base_url;
  $current = parse_url($base_url);
  $form['multisite_redirect_primary_site'] = array(
    '#type' => 'select',
    '#title' => t('Primary Site'),
    '#options' => multisite_redirect_get_sites(TRUE, FALSE),
    '#description' => t('Select the site to use when an absolute URL is not used in the redirect path.'),
    '#default_value' => variable_get('multisite_redirect_primary_site', $current['host']),
  );
  $form['multisite_redirect_exclusions'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Exclusions'),
    '#options' => multisite_redirect_get_sites(TRUE, FALSE),
    '#description' => t('Select which sites to exclude from redirects list.'),
    '#default_value' => variable_get('multisite_redirect_exclusions', array($current['host'])),
  );
  return system_settings_form($form);
}

/**
 * Delete form callback.
 */
function multisite_redirect_delete_form($form, &$form_state, $redirect) {
  $form['#redirect'] = $redirect;
  return confirm_form($form, 'Are you sure you want to delete this redirect?', 'admin/config/search/multisite-redirect/' . $redirect->rid);
}

/**
 * Administrative form callback.
 */
function multisite_redirect_admin_form($form, &$form_state) {
  $form['multisite_redirect_rules_table'] = array(
    '#tree' => TRUE,
    '#theme' => 'multisite_redirect_rules_table',
  );
  $form['#rules'] = multisite_redirect_load_multiple();
  if (!empty($form['#rules'])) {
    $status_codes = array(0 => t('Default (@default)', array('@default' => variable_get('redirect_default_status_code', 301)))) + redirect_status_code_options();
    $form['multisite_redirect_rules_table'] = array(
      '#tree' => TRUE,
      '#theme' => 'multisite_redirect_rules_table',
    );
    foreach ($form['#rules'] as $n => $rule) {
      $form['multisite_redirect_rules_table'][$rule->rid] = array(
        'source_site' => array('#markup' => $rule->source_site),
        'source_path' => array('#markup' => nl2br($rule->source_path)),
        'redirect' => array('#markup' => check_plain($rule->redirect)),
        'status_code' => array('#markup' => $status_codes[$rule->status_code]),
        'edit' => array('#markup' => l(t('edit'), 'admin/config/search/multisite-redirect/' . $rule->rid)),
        'access' => array('#markup' => ($rule->access != 0) ? format_date($rule->access) : t('Never')),
        'count' => array('#markup' => $rule->count),
        'delete' => array('#markup' => l(t('delete'), 'admin/config/search/multisite-redirect/' . $rule->rid . '/delete', array(
            'query' => array(
              'destination' => 'admin/config/search/multisite-redirect',
            ),
          ))),
        'weight' => array(
          '#type' => 'textfield',
          '#default_value' => $rule->weight | 0,
          '#size' => 3,
          '#attributes' => array('class' => array('attribute-weight')),
        ),
        '#weight' => $rule->weight | 0,
      );
    }
  }
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Edit form callback.
 */
function multisite_redirect_edit_form($form, &$form_state, $redirect = NULL) {
  global $base_url;
  if (empty($redirect)) {
    $redirect = new stdClass();
  }
  multisite_redirect_object_prepare($redirect, array(
    'source_site' => isset($_GET['source_site']) ? urldecode($_GET['source_site']) : 'any',
    'source_path' => isset($_GET['source_path']) ? urldecode($_GET['source_path']) : '',
    'redirect' => isset($_GET['redirect']) ? urldecode($_GET['redirect']) : '',
    'language' => isset($_GET['language']) ? urldecode($_GET['language']) : LANGUAGE_NONE,
  ));
  $form['#redirect'] = $redirect;
  $form['source'] = array(
    '#type' => 'fieldset',
    '#title' => t('From'),
  );
  $form['source']['site'] = array(
    '#type' => 'select',
    '#title' => t('Site'),
    '#options' => multisite_redirect_get_sites(),
    '#default_value' => $redirect->source_site,
    '#required' => TRUE,
    '#description' => t('Select the source site from which to redirect.'),
  );
  $form['source']['path'] = array(
    '#type' => 'textarea',
    '#title' => t('Path'),
    '#default_value' => $redirect->source_path,
    '#required' => TRUE,
    '#description' => t("Enter an internal Drupal path or path alias to redirect (e.g., %example1 or %example2). Fragment anchors (e.g., %anchor) are <strong>not</strong> allowed. You may also use the wildcards to cover a broader range on URLs (e.g., %example3).", array('%example1' => 'node/123', '%example2' => 'taxonomy/term/123', '%example3' => 'node/*', '%anchor' => '#anchor')),
  );
  $form['redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('To'),
    '#default_value' => $redirect->redirect,
    '#required' => TRUE,
    '#description' => t('Enter an internal Drupal path, path alias, or complete external URL (like http://example.com/) to redirect to. Use %front to redirect to the front page. Use a wildcard(*) to redirect to the primary domain with the current path appended to the end.', array('%front' => '<front>')),
  );
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced']['status_code'] = array(
    '#type' => 'select',
    '#title' => t('Redirect status'),
    '#description' => t('You can find more information about HTTP redirect status codes at <a href="@status-codes">@status-codes</a>.', array('@status-codes' => 'http://en.wikipedia.org/wiki/List_of_HTTP_status_codes#3xx_Redirection')),
    '#default_value' => $redirect->status_code,
    '#required' => TRUE,
    '#options' => array(0 => t('Default (@default)', array('@default' => variable_get('redirect_default_status_code', 301)))) + redirect_status_code_options(),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  if ($redirect->rid != 0) {
    $form['actions']['cancel'] = array(
      '#type' => 'link',
      '#title' => t('Cancel'),
      '#href' => isset($_GET['destination']) ? $_GET['destination'] : 'admin/config/search/multisite-redirect',
    );
    $form['actions']['delete'] = array(
      '#type' => 'link',
      '#title' => t('Delete'),
      '#href' => isset($_GET['destination']) ? $_GET['destination'] : 'admin/config/search/multisite-redirect/' . $redirect->rid . '/delete',
    );
  }
  return $form;
}