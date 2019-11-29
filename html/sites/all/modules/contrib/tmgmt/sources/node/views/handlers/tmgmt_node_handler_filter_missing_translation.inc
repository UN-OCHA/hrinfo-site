<?php

/**
 * @file
 * Definition of tmgmt_node_handler_filter_missing_translation.
 */

/**
 * Filter by language.
 *
 * @ingroup views_filter_handlers
 */
class tmgmt_node_handler_filter_missing_translation extends views_handler_filter {

  /**
   * The target status to use for the query.
   *
   * @var string
   */
  protected $target_status = 'untranslated_or_outdated';

  /**
   * {@inheritdoc}
   */
  function query() {
    $this->ensure_my_table();

    // Don't do anything if no language was selected.
    if (!$this->value) {
      return;
    }

    $join = new views_join();
    $join->definition['left_table'] = $this->table_alias;
    $join->definition['left_field'] = $this->real_field;
    $join->definition['table'] = 'node';
    $join->definition['field'] = 'tnid';
    $join->definition['type'] = 'LEFT';
    $join->construct();

    $join->extra = array(array(
      'field' => 'language',
      'value' => $this->value,
    ));

    $table_alias = $this->query->add_table('node', $this->relationship, $join);

    $this->query->add_where_expression($this->options['group'], "{$this->table_alias}.language != :language", array(':language' => $this->value));

    if ($this->target_status == 'untranslated_or_outdated') {
      $this->query->add_where_expression($this->options['group'], "($table_alias.nid IS NULL OR {$this->table_alias}.translate = 1)");
    }
    elseif ($this->target_status == 'outdated') {
      $this->query->add_where_expression($this->options['group'], "{$this->table_alias}.translate = 1");
    }
    elseif ($this->target_status == 'untranslated') {
      $this->query->add_where_expression($this->options['group'], "$table_alias.nid IS NULL");
    }
  }

  /**
   * {@inheritdoc}
   */
  function value_form(&$form, &$form_state) {
    $options = array();
    foreach (language_list() as $langcode => $language) {
      $options[$langcode] = $language->name;
    }

    $identifier = $this->options['expose']['identifier'];

    $form['value'][$identifier] = array(
      '#type' => 'select',
      '#options' => $options,
      '#empty_option' => t('Any'),
      '#id' => 'tmgmt_node_missing_target_language',
      '#element_validate' => array('tmgmt_node_views_exposed_target_language_validate'),
    );
    // Attach css to style the target_status element inline.
    $form['#attached']['css'][] = drupal_get_path('module', 'tmgmt_node_ui') . '/tmgmt_node_ui.source_overview.css';
    $form['value']['target_status'] = array(
      '#type' => 'select',
      '#title' => t('Target status'),
      '#options' => array(
        'untranslated_or_outdated' => t('Untranslated or outdated'),
        'untranslated' => t('Untranslated'),
        'outdated' => t('Outdated'),
      ),
      '#states' => array(
        'invisible' => array(
          ':input[id="tmgmt_node_missing_target_language"]' => array('value' => ''),
        ),
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  function accept_exposed_input($input) {
    $return = parent::accept_exposed_input($input);
    if ($return && isset($input['target_status'])) {
      $this->target_status = $input['target_status'];
    }
    return $return;
  }

}
