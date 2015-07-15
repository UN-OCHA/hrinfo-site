<?php

/**
 * @file
 * Provides page callbacks and form functions for the Translation Management
 * Tool User Interface module.
 */

/**
 * Form callback for the settings form.
 *
 * @see system_settings_form()
 */
function tmgmt_ui_settings_form($form, &$form_state) {
  $form['workflow'] = array(
    '#type' => 'fieldset',
    '#title' => t('Workflow settings'),
  );
  $form['workflow']['tmgmt_quick_checkout'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow quick checkout'),
    '#description' => t("Enabling this will skip the checkout form and instead directly process the translation request in cases where there is only one translator available which doesn't provide any additional configuration options."),
    '#default_value' => variable_get('tmgmt_quick_checkout', TRUE),
  );
  $form['performance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Performance settings'),
  );
  $form['performance']['tmgmt_purge_finished'] = array(
    '#type' => 'select',
    '#title' => t('Purge finished jobs'),
    '#description' => t('If configured, translation jobs that have been marked as finished will be purged after a given time. The translations itself will not be deleted.'),
    '#options' => array('_never' => t('Never'), '0' => t('Immediately'), '86400' => t('After 24 hours'), '604800' => t('After 7 days'), '2592000' => t('After 30 days'), '31536000' => t('After 365 days')),
    '#default_value' => variable_get('tmgmt_purge_finished', '_never'),
  );
  return system_settings_form($form);
}

/**
 * Simple page callback for viewing a job.
 *
 * @param TMGMTJob $job
 *   The viewed job.
 *
 * @return array
 *   A renderable array.
 */
function tmgmt_ui_job_view(TMGMTJob $job) {
  return entity_view($job->entityType(), array($job), 'full', NULL, TRUE);
}

/**
 * Simple page callback for viewing a job item.
 *
 * @param TMGMTJobItem $item
 *   The viewed job item.
 *
 * @return array
 *   A renderable array.
 */
function tmgmt_ui_job_item_view(TMGMTJobItem $item) {
  // Update the breadcrumb to include the job path.
  _tmgmt_ui_breadcrumb($item);
  return entity_view($item->entityType(), array($item), 'full', NULL, TRUE);
}

/**
 * Simple page callback for reviewing a job item.
 *
 * @param TMGMTJobItem $job
 *   The job item to be reviewed
 *
 * @return array
 *   A renderable array.
 */
function tmgmt_ui_job_item_review(TMGMTJobItem $item) {
  if ($controller = $item->getSourceController()) {
    $plugin = $controller->pluginType();
    return drupal_get_form('tmgmt_ui_' . $plugin . '_translation_review_form', $item);
  }
  drupal_access_denied();
  exit;
}

/**
 * Entity API form for the translator entity.
 */
function tmgmt_translator_form($form, &$form_state, TMGMTTranslator $translator, $op = 'edit') {
  // Check if the translator entity is completely new or not.
  $old = empty($translator->is_new) && $op != 'clone';
  // Build up the stored entity from the last (failed) form submit.
  if (!empty($form_state['values'])) {
    $translator = entity_ui_form_submit_build_entity($form, $form_state);
  }
  // We don't want the terrible long title that Entity API generates for us.
  if (in_array($op, array('import', 'add'))) {
    drupal_set_title($op == 'import' ? t('Import Translator') : t('Add Translator'), PASS_THROUGH);
  }
  // Check if the translator is currently in use.
  if ($busy = $old ? tmgmt_translator_busy($translator->name) : FALSE) {
    drupal_set_message(t("This translator is currently in use. It cannot be deleted. The chosen Translation Plugin cannot be changed."), 'warning');
  }
  $available = tmgmt_translator_plugin_labels();
  // If the translator plugin is not set, pick the first available plugin as the
  // default.
  $translator->plugin = empty($translator->plugin) ? key($available) : $translator->plugin;
  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('The label of the translator.'),
    '#default_value' => $translator->label,
    '#required' => TRUE,
    '#size' => 32,
    '#maxlength' => 64,
  );
  $form['name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#description' => t('The machine readable name of this translator. It must be unique, and it must contain only alphanumeric characters and underscores. Once created, you will not be able to change this value!'),
    '#default_value' => $translator->name,
    '#machine_name' => array(
      'exists' => 'tmgmt_translator_exists',
      'source' => array('label'),
    ),
    '#disabled' => $old,
    '#size' => 32,
    '#maxlength' => 64,
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('The description of the translator.'),
    '#default_value' => $translator->description,
    '#size' => 32,
    '#maxlength' => 255,
  );
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Translator settings'),
    '#tree' => TRUE,
  );
  $form['settings']['auto_accept'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto accept finished translations'),
    '#description' => t('This skips the reviewing process and automatically accepts all translations as soon as they are returned by the translation provider.'),
    '#default_value' => $translator->getSetting('auto_accept'),
    '#weight' => -1,
  );
  if (!element_children($form['settings'])) {
    unset($form['settings']);
  }
  $form['plugin_wrapper'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="tmgmt-plugin-wrapper">',
    '#suffix' => '</div>',
  );
  // Pull the translator plugin info if any.
  if ($translator->plugin) {
    $info = tmgmt_translator_plugin_info($translator->plugin);
    $form['plugin_wrapper']['plugin'] = array(
      '#type' => 'select',
      '#title' => t('Translator plugin'),
      '#description' => isset($info['description']) ? filter_xss($info['description']) : '',
      '#options' => $available,
      '#default_value' => $translator->plugin,
      '#required' => TRUE,
      '#disabled' => $busy,
      '#ajax' => array(
        'callback' => 'tmgmt_ui_ajax_callback_translator_plugin_select',
        'wrapper' => 'tmgmt-plugin-wrapper',
      ),
    );
    $form['plugin_wrapper']['settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('@plugin plugin settings', array('@plugin' => $info['label'])),
      '#tree' => TRUE,
    );
    // Add the translator plugin settings form.
    $form['plugin_wrapper']['settings'] += tmgmt_ui_plugin_settings_form($form_state, $translator, $busy);
  }
  // Add a submit button and a cancel link to the form.
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save translator'),
    '#disabled' => empty($available),
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array('tmgmt_ui_submit_redirect'),
    '#redirect' => 'admin/config/regional/tmgmt_translator/manage/' . $translator->name . '/delete',
    '#access' => $old,
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'admin/config/regional/tmgmt_translator',
  );
  return $form;
}

/**
 * Form validator for the translator entity form.
 */
function tmgmt_translator_form_validate($form, &$form_state) {
  // We need to clone this here so we don't change the translator entity in the
  // form state. Otherwise the form will break.
  $backup = clone $form_state[$form_state['entity_type']];
  $translator = entity_ui_form_submit_build_entity($form, $form_state);
  $form_state[$form_state['entity_type']] = $backup;
  if (empty($translator->plugin)) {
    form_set_error('plugin', t('You have to select a translator plugin.'));
  }
}

/**
 * Submit handler for the translator entity form.
 *
 * Populates and stores the submitted values for the translator entity via
 * entity_ui_form_submit_build_entity().
 *
 * @see entity_ui_form_submit_build_entity()
 */
function tmgmt_translator_form_submit($form, &$form_state) {
  entity_ui_form_submit_build_entity($form, $form_state)->save();
  drupal_set_message(t('The configuration options have been saved.'));
  $form_state['redirect'] = 'admin/config/regional/tmgmt_translator';
}

/**
 * Entity API form the job entity.
 */
function tmgmt_job_form($form, &$form_state, TMGMTJob $job, $op = 'edit') {
  // Get the job metadata wrapper so we can display the current status nicely.
  $wrapper = entity_metadata_wrapper('tmgmt_job', $job);
  // Check if the translator entity is completely new or not.
  $old = empty($job->is_new) && $op != 'clone';
  // Handle source language.
  $available['source_language'] = tmgmt_available_languages();
  $job->source_language = isset($form_state['values']['source_language']) ? $form_state['values']['source_language'] : $job->source_language;

  // Handle target language.
  $available['target_language'] = tmgmt_available_languages();
  $job->target_language = isset($form_state['values']['target_language']) ? $form_state['values']['target_language'] : $job->target_language;

  // Remove impossible combinations so we don't end up with the same source and
  // target language in the dropdowns.
  foreach (array('source_language' => 'target_language', 'target_language' => 'source_language') as $key => $opposite) {
    if (!empty($job->{$key})) {
      unset($available[$opposite][$job->{$key}]);
    }
  }

  $source = $wrapper->source_language->label();
  if (empty($job->source_language)) {
    $source = '?';
  }

  $target = $wrapper->target_language->label();
  if (empty($job->target_language)) {
    $job->target_language = key($available['target_language']);
    $target = '?';
  }

  // Set the title of the page to the label and the current state of the job.
  drupal_set_title(t('@title (@source to @target, @state)', array(
    '@title' => $job->label(),
    '@source' => $source,
    '@target' => $target,
    '@state' => $wrapper->state->label(),
  )));

  $form['info'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('tmgmt-ui-job-info', 'clearfix')),
    '#weight' => 0,
  );

  // Check for label value and set for dynamically change.
  if (isset($form_state['values']['label']) && $form_state['values']['label'] == $job->label()) {
    $job->label = NULL;
    $form_state['values']['label'] = $job->label = $job->label();
  }
  $form['info']['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('You can provide a label for this job in order to identify it easily later on. Or leave it empty to use default one.'),
    '#default_value' => $job->label(),
    '#prefix' => '<div id="tmgmt-ui-label">',
    '#suffix' => '</div>',
  );

  // Make the source and target language flexible by showing either a select
  // dropdown or the plain string (if preselected).
  if (!empty($job->source_language) || !$job->isSubmittable()) {
    $form['info']['source_language'] = array(
      '#title' => t('Source language'),
      '#type' =>  'item',
      '#markup' => isset($available['source_language'][$job->source_language]) ? $available['source_language'][$job->source_language] : '',
      '#prefix' => '<div id="tmgmt-ui-source-language" class="tmgmt-ui-source-language tmgmt-ui-info-item">',
      '#suffix' => '</div>',
    );
  }
  else {
    $form['info']['source_language'] = array(
      '#title' => t('Source language'),
      '#type' => 'select',
      '#options' => $available['source_language'],
      '#default_value' => $job->source_language,
      '#required' => TRUE,
      '#prefix' => '<div id="tmgmt-ui-source-language" class="tmgmt-ui-source-language tmgmt-ui-info-item">',
      '#suffix' => '</div>',
      '#ajax' => array(
        'callback' => 'tmgmt_ui_ajax_callback_language_select',
      ),
    );
  }
  if (!$job->isSubmittable()) {
    $form['info']['target_language'] = array(
      '#title' => t('Target language'),
      '#type' => 'item',
      '#markup' => isset($available['target_language'][$job->target_language]) ? $available['target_language'][$job->target_language] : '',
      '#prefix' => '<div id="tmgmt-ui-target-language" class="tmgmt-ui-target-language tmgmt-ui-info-item">',
      '#suffix' => '</div>',
    );
  }
  else {
    $form['info']['target_language'] = array(
      '#title' => t('Target language'),
      '#type' => 'select',
      '#options' => $available['target_language'],
      '#default_value' => $job->target_language,
      '#required' => TRUE,
      '#prefix' => '<div id="tmgmt-ui-target-language" class="tmgmt-ui-target-language tmgmt-ui-info-item">',
      '#suffix' => '</div>',
      '#ajax' => array(
        'callback' => 'tmgmt_ui_ajax_callback_language_select',
        'wrapper' => 'tmgmt-ui-target-language',
      ),
    );
  }

  // Display selected translator for already submitted jobs.
  if (!$job->isSubmittable()) {
    $translators = tmgmt_translator_labels();
    $form['info']['translator'] = array(
      '#type' => 'item',
      '#title' => t('Translator'),
      '#markup' => isset($translators[$job->translator]) ? check_plain($translators[$job->translator]) : t('Missing translator'),
      '#prefix' => '<div class="tmgmt-ui-translator tmgmt-ui-info-item">',
      '#suffix' => '</div>',
    );
  }

  $form['info']['word_count'] = array(
    '#type' => 'item',
    '#title' => t('Total word count'),
    '#markup' => number_format($job->getWordCount()),
    '#prefix' => '<div class="tmgmt-ui-word-count tmgmt-ui-info-item">',
    '#suffix' => '</div>',
  );

  // Display created time only for jobs that are not new anymore.
  if (!$job->isUnprocessed()) {
    $form['info']['created'] = array(
      '#type' => 'item',
      '#title' => t('Created'),
      '#markup' => format_date($job->created),
      '#prefix' => '<div class="tmgmt-ui-created tmgmt-ui-info-item">',
      '#suffix' => '</div>',
    );
  }

  if ($view = views_get_view('tmgmt_ui_job_items')) {
    $form['job_items_wrapper'] = array(
      '#type' => 'fieldset',
      '#title' => t('Job items'),
      '#collapsible' => TRUE,
      '#weight' => 10,
      '#prefix' => '<div class="tmgmt-ui-job-checkout-fieldset">',
      '#suffix' => '</div>',
    );

    // Translation jobs.
    $form['job_items_wrapper']['items'] = array(
      '#type' => 'markup',
      '#markup' => $view->preview($job->isSubmittable() ? 'submit' : 'block', array($job->tjid)),
      '#prefix' => '<div class="' . 'tmgmt-ui-job-items ' . ($job->isSubmittable() ? 'tmgmt-ui-job-submit' : 'tmgmt-ui-job-manage') . '">',
      '#attributes' => array('class' => array('tmgmt-ui-job-items', $job->isSubmittable() ? 'tmgmt-ui-job-submit' : 'tmgmt-ui-job-manage')),
      '#suffix' => '</div>',
    );

    // A Wrapper for a button and a table with all suggestions.
    $form['job_items_wrapper']['suggestions'] = array(
      '#type' => 'container',
      '#access' => $job->isSubmittable(),
    );

    // Button to load all translation suggestions with AJAX.
    $form['job_items_wrapper']['suggestions']['load'] = array(
      '#type' => 'submit',
      '#value' => t('Load suggestions'),
      '#submit' => array('tmgmt_ui_ajax_submit_load_suggestions'),
      '#limit_validation_errors' => array(),
      '#attributes' => array(
        'class' => array('tmgmt-ui-job-suggestions-load'),
      ),
      '#ajax' => array(
        'callback' => 'tmgmt_ui_ajax_callback_load_suggestions',
        'wrapper' => 'tmgmt-ui-job-items-suggestions',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );

    $form['job_items_wrapper']['suggestions']['container'] = array(
      '#type' => 'container',
      '#prefix' => '<div id="tmgmt-ui-job-items-suggestions">',
      '#suffix' => '</div>',
    );

    // Create the suggestions table.
    $suggestions_table = array(
      '#type' => 'tableselect',
      '#header' => array(),
      '#options' => array(),
      '#multiple' => TRUE,
    );

    // If this is an AJAX-Request, load all related nodes and fill the table.
    if ($form_state['rebuild'] && !empty($form_state['rebuild_suggestions'])) {
      _tmgmt_ui_translation_suggestions($suggestions_table, $form_state);

      // A save button on bottom of the table is needed.
      $suggestions_table = array(
        'suggestions_table' => $suggestions_table,
        'suggestions_add' => array(
          '#type' => 'submit',
          '#value' => t('Add suggestions'),
          '#submit' => array('tmgmt_ui_submit_add_suggestions'),
          '#limit_validation_errors' => array(array('suggestions_table')),
          '#attributes' => array(
            'class' => array('tmgmt-ui-job-suggestions-add'),
          ),
          '#access' => !empty($suggestions_table['#options']),
        ),
      );
      $form['job_items_wrapper']['suggestions']['container']['suggestions_list'] = array(
          '#type' => 'fieldset',
          '#title' => t('Suggestions'),
          '#prefix' => '<div id="tmgmt-ui-job-items-suggestions">',
          '#suffix' => '</div>',
        ) + $suggestions_table;
    }

  }

  // Display the checkout settings form if the job can be checked out.
  if ($job->isSubmittable()) {

    $form['translator_wrapper'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure translator'),
      '#collapsible' => FALSE,
      '#weight' => 20,
    );

    // Show a list of translators tagged by availability for the selected source
    // and target language combination.
    if (!$translators = tmgmt_translator_labels_flagged($job)) {
      drupal_set_message(t('There are no translators available. Before you can checkout you need to !configure at least one translator.', array('!configure' => l(t('configure'), 'admin/config/regional/tmgmt_translator'))), 'warning');
    }
    $preselected_translator = !empty($job->translator) && isset($translators[$job->translator]) ? $job->translator : key($translators);
    $job->translator = isset($form_state['values']['translator']) ? $form_state['values']['translator'] : $preselected_translator;

    $form['translator_wrapper']['translator'] = array(
      '#type' => 'select',
      '#title' => t('Translator'),
      '#description' => t('The configured translator plugin that will process of the translation.'),
      '#options' => $translators,
      '#default_value' => $job->translator,
      '#required' => TRUE,
      '#ajax' => array(
        'callback' => 'tmgmt_ui_ajax_callback_translator_select',
        'wrapper' => 'tmgmt-ui-translator-settings',
      ),
    );

    $settings = tmgmt_ui_checkout_settings_form($form_state, $job);
    if(!is_array($settings)){
      $settings = array();
    }
    $form['translator_wrapper']['settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Checkout settings'),
      '#prefix' => '<div id="tmgmt-ui-translator-settings">',
      '#suffix' => '</div>',
      '#tree' => TRUE,
    ) + $settings;
  }
  // Otherwise display the checkout info.
  elseif (!empty($job->translator)) {

    $form['translator_wrapper'] = array(
      '#type' => 'fieldset',
      '#title' => t('Translator information'),
      '#collapsible' => TRUE,
      '#weight' => 20,
    );

    $form['translator_wrapper']['info'] = tmgmt_ui_checkout_info($job);
  }

  if (!$job->isSubmittable() && empty($form['translator_wrapper']['info'])) {
    $form['translator_wrapper']['info'] = array(
      '#type' => 'markup',
      '#markup' => t('The translator does not provide any information.'),
    );
  }

  $form['clearfix'] = array(
    '#markup' => '<div class="clearfix"></div>',
    '#weight' => 45,
  );

  if ($output = tmgmt_ui_embed_view('tmgmt_ui_job_messages', 'block', array($job->tjid))) {
    $form['messages'] = array(
      '#type' => 'fieldset',
      '#title' => t('Messages'),
      '#collapsible' => TRUE,
      '#weight' => 50,
    );
    $form['messages']['view'] = array(
      '#type' => 'markup',
      '#markup' => $output,
    );
  }

  // Add the buttons and action links.
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save job'),
  );
  if (entity_access('submit', 'tmgmt_job', $job)) {
    $form['actions']['checkout'] = array(
      '#type' => 'submit',
      '#value' => tmgmt_ui_redirect_queue_count() == 0 ? t('Submit to translator') : t('Submit to translator and continue'),
      '#access' => $job->isSubmittable(),
      '#disabled' => empty($job->translator),
    );
    $form['actions']['resubmit_job'] = array(
      '#type' => 'submit',
      '#submit' => array('tmgmt_ui_submit_redirect'),
      '#redirect' => 'admin/tmgmt/jobs/' . $job->tjid . '/resubmit',
      '#value' => t('Resubmit'),
      '#access' => $job->isAborted(),
    );
    $form['actions']['abort_job'] = array(
      '#type' => 'submit',
      '#value' => t('Abort job'),
      '#redirect' => 'admin/tmgmt/jobs/' . $job->tjid . '/abort',
      '#submit' => array('tmgmt_ui_submit_redirect'),
      '#access' => $job->isAbortable(),
    );
  }
  if ($old) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('tmgmt_ui_submit_redirect'),
      '#redirect' => 'admin/tmgmt/jobs/' . $job->tjid . '/delete',
      // Don't run validations, so the user can always delete the job.
      '#limit_validation_errors' => array(),
      '#access' => user_access('administer tmgmt'),
    );
  }
  // Only show the 'Cancel' button if the job has been submitted to the
  // translator.
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'admin/tmgmt/jobs',
    '#weight' => 10,
  );

  $form['#attached']['css'][] = drupal_get_path('module', 'tmgmt_ui') . '/css/tmgmt_ui.admin.css';
  return $form;
}

/**
 * Set a value in form_state to rebuild the form and fill with data.
 */
function tmgmt_ui_ajax_submit_load_suggestions(array $form, array &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['rebuild_suggestions'] = TRUE;
}

/**
 * Adds selected suggestions to the job.
 */
function tmgmt_ui_submit_add_suggestions($form, &$form_state) {
  // Save all selected suggestion items.
  if (isset($form_state['values']['suggestions_table']) && is_array($form_state['values']['suggestions_table'])) {
    foreach ($form_state['values']['suggestions_table'] as $id) {
      $key = (int)$id - 1; // Because in the tableselect we need an idx > 0.
      if (isset($form_state['tmgmt_suggestions'][$key]['job_item'])) {
        $item = $form_state['tmgmt_suggestions'][$key]['job_item'];
        $form_state['tmgmt_job']->addExistingItem($item);
      }
    }
  }

  // Force a rebuild of the form.
  $form_state['rebuild'] = TRUE;
  unset($form_state['tmgmt_suggestions']);
}

/**
 * Returns the suggestions table for an AJAX-Call.
 */
function tmgmt_ui_ajax_callback_load_suggestions($form, &$form_state) {
  return $form['job_items_wrapper']['suggestions']['container']['suggestions_list'];
}

/**
 * Fills the tableselect with all translation suggestions.
 *
 * Calls hook_tmgmt_source_suggestions(TMGMTJob) and creates the resulting list
 * based on the results from all modules.
 *
 * @param array $suggestions_table
 *   Tableselect part for a $form array where the #options should be inserted.
 * @param array $form_state
 *   The main form_state.
 */
function _tmgmt_ui_translation_suggestions(array &$suggestions_table, array &$form_state) {
  $options = array();
  $job = $form_state['tmgmt_job'];
  if ($job instanceof TMGMTJob) {
    // Get all suggestions from all modules which implements
    // 'hook_tmgmt_source_suggestions' and cache them in $form_state.
    if (!isset($form_state['tmgmt_suggestions'])) {
      $form_state['tmgmt_suggestions'] = $job->getSuggestions();
    }

    // Remove suggestions which are already processed, translated, ...
    $job->cleanSuggestionsList($form_state['tmgmt_suggestions']);

    // Process all valid entries.
    foreach ($form_state['tmgmt_suggestions'] as $k => $result) {
      if (is_array($result) && isset($result['job_item']) && ($result['job_item'] instanceof TMGMTJobItem)) {
        $options[$k + 1] = _tmgmt_ui_add_suggestion_item($result);
      }
    }

    $suggestions_table['#options'] = $options;
    $suggestions_table['#empty'] = t('No related suggestions available.');
    $suggestions_table['#header'] = array(
      'title' => t('Label'),
      'plugin' => t('Type'),
      'reason' => t('Reason'),
      'words' => t('Word count'),
    );
  }
}

/**
 * Create a Suggestion-Table entry based on a TMGMTJob and a title.
 *
 * @param array $result
 *   Suggestion array with the keys job_item, reason and from_item.
 *
 * @return array
 *   Options-Entry for a tableselect array.
 */
function _tmgmt_ui_add_suggestion_item(array $result) {
  $item = $result['job_item'];

  $reason = isset($result['reason']) ? $result['reason'] : NULL;
  $option = array(
    'title' => $item->label(),
    'plugin' => $item->getSourceType(),
    'words' => $item->getWordCount(),
    'reason' => $reason,
  );

  if (!empty($result['from_item'])) {
    $from_item = tmgmt_job_item_load($result['from_item']);
    if ($from_item) {
      $option['reason'] = t('%reason in %job', array('%reason' => $option['reason'], '%job' => $from_item->label()));
    }
  }
  return $option;
}

/**
 * Submit callback for the job checkout form.
 */
function tmgmt_job_form_submit($form, &$form_state) {
  // Build up the job from the submitted form values and save here so we got the
  // plain 'Submit' case covered. Also, if the translator fails it won't save on
  // its own.
  $job = entity_ui_form_submit_build_entity($form, $form_state);

  // If requested custom job settings handling, copy values from original job.
  if (tmgmt_job_settings_custom_handling($job->getTranslator())) {
    $original_job = entity_load_unchanged('tmgmt_job', $job->tjid);
    $job->settings = $original_job->settings;
  }

  // Make sure that we always store a label as it can be a slow operation to
  // generate the default label.
  if (empty($job->label)) {
    $job->label = $job->label();
  }
  $job->save();
  // Per default we want to redirect the user to the overview.
  $form_state['redirect'] = 'admin/tmgmt';
  // Everything below this line is only invoked if the 'Submit to translator'
  // button was clicked.
  if ($form_state['triggering_element']['#value'] == $form['actions']['checkout']['#value']) {
    if (!tmgmt_ui_job_request_translation($job)) {
      // Don't redirect the user if the translation request failed but retain
      // existing destination parameters so we can redirect once the request
      // finished successfully.
      // @todo: Change this to stay on the form in case of an error instead of
      // doing a redirect.
      $form_state['redirect'] = array(current_path(), array('query' => drupal_get_destination()));
      unset($_GET['destination']);
    }
    else if ($redirect = tmgmt_ui_redirect_queue_dequeue()) {
      // Proceed to the next redirect queue item, if there is one.
      $form_state['redirect'] = $redirect;
    }
    else {
      // Proceed to the defined destination if there is one.
      $form_state['redirect'] = tmgmt_ui_redirect_queue_destination($form_state['redirect']);
    }
  }
}

/**
 * Validation callback for the job checkout form.
 *
 * @todo Make use of the response object here.
 */
function tmgmt_job_form_validate($form, &$form_state) {
  // We need to clone this here so we don't change the job entity in the form
  // state. Otherwise the form will break.
  $backup = clone $form_state[$form_state['entity_type']];
  $job = entity_ui_form_submit_build_entity($form, $form_state);
  $form_state[$form_state['entity_type']] = $backup;
  // Load the selected translator.
  $translator = tmgmt_translator_load($job->translator);
  // Load the metadata wrapper so we can display the selected language.
  $wrapper = entity_metadata_wrapper('tmgmt_job', $job);
  // Check translator availability.
  if (!$translator->isAvailable()) {
    form_set_error('translator', $translator->getNotAvailableReason());
  }
  elseif (!$translator->canTranslate($job)) {
    form_set_error('translator', $translator->getNotCanTranslateReason($job));
  }
}

/**
 * Helper function for retrieving the job settings form.
 *
 * @todo Make use of the response object here.
 */
function tmgmt_ui_checkout_settings_form(&$form_state, TMGMTJob $job) {
  $form = array();
  $translator = $job->getTranslator();
  if (!$translator) {
    return $form;
  }
  if (!$translator->isAvailable()) {
    $form['#description'] = filter_xss($job->getTranslator()->getNotAvailableReason());
  }
  // @todo: if the target language is not defined, the check will not work if the first language in the list is not available.
  elseif ($job->target_language && !$translator->canTranslate($job)) {
    $form['#description'] = filter_xss($job->getTranslator()->getNotCanTranslateReason($job));
  }
  else {
    $controller = tmgmt_translator_ui_controller($translator->plugin);
    $form = $controller->checkoutSettingsForm($form, $form_state, $job);
  }
  return $form;
}

/**
 * Helper function for retrieving the translator settings form.
 */
function tmgmt_ui_plugin_settings_form(&$form_state, TMGMTTranslator $translator, $busy = FALSE) {
  $form = array();
  $controller = tmgmt_translator_ui_controller($translator->plugin);
  return $controller->pluginSettingsForm($form, $form_state, $translator, $busy);
}

/**
 * Helper function for retrieving the rendered job checkout information.
 */
function tmgmt_ui_checkout_info(TMGMTJob $job) {
  $translator = $job->getTranslator();
  // The translator might have been disabled or removed.
  if (!$translator) {
    return array();
  }
  $controller = tmgmt_translator_ui_controller($translator->plugin);
  return $controller->checkoutInfo($job);
}

/**
 * Helper function for redirecting a form after a button has been clicked.
 */
function tmgmt_ui_submit_redirect($form, &$form_state){
  if (isset($form_state['triggering_element']['#redirect'])) {
    $form_state['redirect'] = $form_state['triggering_element']['#redirect'];
  }
}

/**
 * Ajax callback for loading the translator plugin settings form for the
 * currently selected translator plugin.
 */
function tmgmt_ui_ajax_callback_translator_plugin_select($form, &$form_state) {
  return $form['plugin_wrapper'];
}

/**
 * Ajax callback to fetch the supported translator services and rebuild the
 * target / source language dropdowns.
 */
function tmgmt_ui_ajax_callback_language_select($form, &$form_state) {
  $replace = $form_state['input']['_triggering_element_name'] == 'source_language' ? 'target_language' : 'source_language';
  $commands[] = ajax_command_replace('#tmgmt-ui-translator-wrapper', drupal_render($form['translator_wrapper']));
  $commands[] = ajax_command_replace('#tmgmt-ui-' . str_replace('_', '-', $replace), drupal_render($form['info'][$replace]));

  // Replace value of the label field with ajax on language change.
  // @todo This manual overwrite is necessary because somehow an old job entity seems to be used.
  $form['info']['label']['#value'] = $form_state['values']['label'];
  $commands[] = ajax_command_replace('#tmgmt-ui-label', drupal_render($form['info']['label']));

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Ajax callback to fetch the options provided by a translator.
 */
function tmgmt_ui_ajax_callback_translator_select($form, &$form_state) {
  return $form['translator_wrapper']['settings'];
}

/**
 * @addtogroup tmgmt_ui_cart
 * @{
 */

/**
 * Form constructor for cart form.
 *
 * @param array $form
 * @param array $form_state
 *
 * @return array $form
 */
function tmgmt_ui_cart_content($form, &$form_state) {

  $languages = tmgmt_available_languages();
  $options = array();
  foreach (tmgmt_ui_cart_get()->getJobItemsFromCart() as $item) {
    $uri = $item->getSourceUri();
    $options[$item->tjiid] = array(
        $item->getSourceType(),
        (!empty($uri['path']) ? l($item->label(), $uri['path']) : $item->label()),
        isset($languages[$item->getSourceLangCode()]) ? $languages[$item->getSourceLangCode()] : t('Unknown'),
    );
  }

  $form['items'] = array(
    '#type' => 'tableselect',
    '#header' => array(t('Type'), t('Content'), t('Language')),
    '#empty' => t('There are no items in your cart.'),
    '#options' => $options,
  );

  $form['target_language'] = array(
    '#type' => 'select',
    '#title' => t('Request translation into language/s'),
    '#multiple' => TRUE,
    '#options' => $languages,
    '#description' => t('If the item\'s source language will be the same as the target language the item will be ignored.'),
  );

  $form['empty_cart'] = array(
    '#type' => 'submit',
    '#value' => t('Empty cart'),
    '#submit' => array('tmgmt_ui_cart_empty_cart_form_submit'),
  );

  $form['remove_selected'] = array(
    '#type' => 'submit',
    '#value' => t('Remove selected'),
    '#submit' => array('tmgmt_ui_cart_remove_selected_form_submit'),
    '#validate' => array('tmgmt_ui_cart_source_overview_validate'),
  );

  $form['request_translation'] = array(
    '#type' => 'submit',
    '#value' => t('Request translation'),
    '#submit' => array('tmgmt_ui_cart_request_translation_form_submit'),
    '#validate' => array('tmgmt_ui_cart_source_overview_validate'),
  );

  return $form;

}

/**
 * Custom form submit callback for tmgmt_ui_cart_cart_form().
 */
function tmgmt_ui_cart_remove_selected_form_submit($form, &$form_state) {
  $job_item_ids = array_filter($form_state['values']['items']);
  tmgmt_ui_cart_get()->removeJobItems($job_item_ids);
  entity_delete_multiple('tmgmt_job_item', $job_item_ids);
  drupal_set_message(t('Job items were removed from the cart.'));
}

/**
 * Custom form submit callback for tmgmt_ui_cart_cart_form().
 */
function tmgmt_ui_cart_empty_cart_form_submit($form, &$form_state) {
  entity_delete_multiple('tmgmt_job_item', array_keys(tmgmt_ui_cart_get()->getJobItemsFromCart()));
  tmgmt_ui_cart_get()->emptyCart();
  drupal_set_message(t('All job items were removed from the cart.'));
}

/**
 * Custom form submit callback for tmgmt_ui_cart_cart_form().
 */
function tmgmt_ui_cart_request_translation_form_submit($form, &$form_state) {
  global $user;

  $target_languages = array_filter($form_state['values']['target_language']);

  $job_items_by_source_language = array();
  // Group the selected items by source language.
  foreach (tmgmt_job_item_load_multiple(array_filter($form_state['values']['items'])) as $job_item) {
    $job_items_by_source_language[$job_item->getSourceLangCode()][$job_item->tjiid] = $job_item;
  }

  $jobs = array();
  $remove_job_item_ids = array();
  // Loop over all target languages, create a job for each source and target
  // language combination add add the relevant job items to it.
  foreach ($target_languages as $target_language) {
    foreach ($job_items_by_source_language as $source_language => $job_items) {
      // Skip in case the source language is the same as the target language.
      if ($source_language == $target_language) {
        continue;
      }


      $job = tmgmt_job_create($source_language, $target_language, $user->uid);
      $job_empty = TRUE;
      /** @var TMGMTJobItem $job_item */
      foreach ($job_items as $id => $job_item) {
        try {
          // As the same item might be added to multiple jobs, we need to
          // re-create them and delete the old ones, after removing them from
          // the cart.
          $job->addItem($job_item->plugin, $job_item->item_type, $job_item->item_id);
          $remove_job_item_ids[$job_item->tjiid] = $job_item->tjiid;
          $job_empty = FALSE;
        }
        catch (Exception $e) {
          // If an item fails for one target language, then it is also going
          // to fail for others, so remove it from the array.
          unset($job_items_by_source_language[$source_language][$id]);
          drupal_set_message($e->getMessage(), 'error');
        }
      }

      if (!$job_empty) {
        $jobs[] = $job;
      }
    }
  }

  // Remove job items from the cart.
  if ($remove_job_item_ids) {
    tmgmt_ui_cart_get()->removeJobItems($remove_job_item_ids);
    entity_delete_multiple('tmgmt_job_item', $remove_job_item_ids);
  }

  // Start the checkout process if any jobs were created.
  if ($jobs) {
    tmgmt_ui_job_checkout_and_redirect($form_state, $jobs);
  }
}

/**
 * @} End of "addtogroup tmgmt_ui_cart".
 */

/**
 * Helper function for appending the parent job path to the breadcrumb of a job
 * item menu path.
 */
function _tmgmt_ui_breadcrumb(TMGMTJobItem $item) {
  $breadcrumb = drupal_get_breadcrumb();
  $menu = menu_get_item('admin/tmgmt/jobs/' . $item->tjid);
  $breadcrumb[] = l($menu['title'], 'admin/tmgmt/jobs/' . $item->tjid);
  drupal_set_breadcrumb($breadcrumb);
}
