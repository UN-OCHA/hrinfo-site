<?php

/**
 * Admin forms for SearchAPI Sorts Widget.
 */

/**
 * Displays a form for configuring the sort widget.
 *
 * @param SearchApiIndex $index
 *   The index for which to display the settings.
 */
function search_api_sorts_widget_settings_form(array $form, array &$form_state, SearchApiIndex $index) {
  module_load_include('admin.inc', 'search_api');
  drupal_set_title(search_api_admin_item_title($index));
  $form_state['index'] = $index;

  if (!$index->server() || !$index->server()->supportsFeature('search_api_facets')) {
    drupal_set_message(t("The server this index currently lies on doesn't support sorts. " .
        'To use sorts, you will have to move this index to a server supporting this feature.'), 'error');
    return $form;
  }

  // Get the sorts ordered by weight using EntityFieldQuery.
  $query = new EntityFieldQuery;
  $results = $query
    ->entityCondition('entity_type', 'search_api_sort')
    ->propertyCondition('index_id', $index->machine_name)
    ->propertyCondition('enabled', TRUE)
    ->propertyOrderBy('weight', 'ASC')
    ->execute();

  $sort_ids = array();
  if (isset($results['search_api_sort'])) {
    foreach ($results['search_api_sort'] as $result) {
      $sort_ids[] = $result->id;
    }
  }
  $sorts = search_api_sorts_load_multiple($sort_ids);

  $index_settings = $index->options['sorts_widget'];

  $form['widget'] = array(
    '#type' => 'fieldset',
    '#title' => t('Widget Settings'),
    '#tree' => TRUE,
  );

  $form['widget']['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use form widget'),
    '#default_value' => $index_settings['enabled'],
  );

  $form['widget']['autosubmit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Autosubmit'),
    '#description' => t('Automatically submit the form once an element is changed.'),
    '#default_value' => $index_settings['autosubmit'],
  );

  if (!module_exists('ctools')) {
    $form['widget']['autosubmit']['#disabled'] = TRUE;
    $form['widget']['autosubmit']['#description'] .= ' <strong>' . t('Requires ctools.') . '</strong>';
  }

  $form['widget']['autosubmit_hide'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide submit button'),
    '#description' => t('Hide submit button if javascript is enabled.'),
    '#default_value' => $index_settings['autosubmit_hide'],
  );

  $form['sorts'] = array(
    '#tree' => TRUE,
    '#theme' => 'search_api_sorts_widget_form_table',
    '#table_header' => array(
      t('Name'),
      t('Label: Ascending'),
      t('Label: Descending'),
      t('Orders'),
    ),
    '#table_empty' => t('There are currently no fields for which sorts can be displayed.'),
  );

  $fields = $index->getFields();

  if (!empty($fields)) {
    if ($disabled = empty($index->enabled)) {
      drupal_set_message(t('Since this index is at the moment disabled, no sorts can be activated.'), 'warning');
    }
    foreach ($sorts as $sort) {
      $sorts[$sort->field][] = $sort;
    }

    $types = search_api_field_types();

    // Need to get the index fields ordered by sort's weight.
    $index_fields = $fields;
    foreach ($sorts as $key => $sort) {
      if (isset($fields[$key])) {
        $fields[$key]['weight'] = isset($sorts[$key][0]->weight) ? $sorts[$key][0]->weight : 0;
        $index_fields[$key] = $fields[$key];
      }
    }

    // Order fields according to sorts weight.
    $new_fields = array();
    foreach ($sorts as $key => $sort) {
      if (!empty($fields[$key])) {
        $new_fields[$key] = $fields[$key];
      }
    }
    $fields = $new_fields;

    foreach ($fields as $key => $field) {
      if (!$field['indexed']) {
        continue;
      }
      // Skip fulltext or multi-value, you cannot sort them.
      if ($field['type'] == 'text' || strpos($field['type'], 'list<') !== FALSE) {
        continue;
      }
      $type = search_api_extract_inner_type($field['type']);
      $type = isset($types[$type]) ? $types[$type] : $type;

      foreach ($sorts[$key] as $i => $sort) {
        $settings = search_api_sorts_widget_load_sort_settings($sort);

        $k = $i ? "$key-$i" : $key;

        $form['sorts'][$k]['sort'] = array(
          '#type' => 'value',
          '#value' => $sort,
        );
        $form['sorts'][$k]['settings'] = array(
          '#type' => 'value',
          '#value' => $settings,
        );

        $form['sorts'][$k]['name'] = array(
          '#markup' => check_plain($sort->name),
        );
        $form['sorts'][$k]['label_asc'] = array(
          '#type' => 'textfield',
          '#default_value' => $settings['label_asc'],
        );
        $form['sorts'][$k]['label_desc'] = array(
          '#type' => 'textfield',
          '#default_value' => $settings['label_desc'],
        );
        $form['sorts'][$k]['orders'] = array(
          '#type' => 'select',
          '#options' => array(
            'both' => t('Both'),
            'asc' => t('Ascending'),
            'desc' => t('Descending'),
          ),
          '#default_value' => $settings['orders'],
        );
      }
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  return $form;
}

/**
 * Validation callback for search_api_sorts_index_select().
 */
function search_api_sorts_widget_settings_form_validate(array $form, array &$form_state) {
  foreach ($form_state['values']['sorts'] as $key => $v) {
    if (in_array($v['orders'], array('both', 'asc')) && !$v['label_asc']) {
      form_set_error("sorts][$key][label_asc", t('%sort: Ascending label required.', array('%sort' => $v['sort']->name)));
    }

    if (in_array($v['orders'], array('both', 'desc')) && !$v['label_desc']) {
      form_set_error("sorts][$key][label_desc", t('%sort: Descending label required.', array('%sort' => $v['sort']->name)));
    }
  }
}

/**
 * Submit callback for search_api_sorts_index_select().
 */
function search_api_sorts_widget_settings_form_submit(array $form, array &$form_state) {
  $index = $form_state['index'];

  $changed =
    ($index->options['sorts_widget']['enabled'] != $form_state['values']['widget']['enabled'])
    || ($index->options['sorts_widget']['autosubmit'] != $form_state['values']['widget']['autosubmit'])
    || ($index->options['sorts_widget']['autosubmit_hide'] != $form_state['values']['widget']['autosubmit_hide']);

  if ($changed) {
    $index->options['sorts_widget'] = $form_state['values']['widget'];
    $index->save();

    drupal_set_message(t('Sorts widget settings for index %index updated.', array('%index' => $index->name)));
  }

  $count = 0;

  foreach ($form_state['values']['sorts'] as $key => $value) {
    $field = $value['sort']->field;
    $sort = $value['sort'];
    $old_settings = $value['settings'];
    $new_settings = array_intersect_key($value, drupal_map_assoc(array('label_asc', 'label_desc', 'orders')));

    $update =
      $old_settings['label_asc'] != $new_settings['label_asc'] ||
      $old_settings['label_desc'] != $new_settings['label_desc'] ||
      $old_settings['orders'] != $new_settings['orders'];

    if ($update) {
      variable_set(
        'search_api_sorts_widget_settings__' . $sort->index_id . '__' . $sort->field,
        $new_settings
      );
      ++$count;
    }
  }

  if ($count) {
    drupal_set_message(format_plural($count, '1 sort was successfully updated.', '@count sorts were successfully updated.'));
  }
  else {
    drupal_set_message(t('No values were changed.'));
  }
}

/**
 * Theming function for rendering a form as a table.
 *
 * @param array $variables
 *   An array of variables to use, containing only one entry:
 *   - element: The sub-form to render as a table.
 *
 * @return string
 *   HTML displaying the specified sub-form as a table.
 */
function theme_search_api_sorts_widget_form_table(array $variables) {
  $form = $variables['element'];

  $rows = array();
  foreach (element_children($form) as $id) {
    $row = array();
    foreach (element_children($form[$id]) as $field) {
      if ($cell = render($form[$id][$field])) {
        $row[] = $cell;
      }
    }
    $rows[] = array(
      'data' => $row,
    );
  }

  $vars['rows'] = $rows;
  if (isset($form['#table_header'])) {
    $vars['header'] = $form['#table_header'];
  }
  if (isset($form['#table_empty'])) {
    $vars['empty'] = $form['#table_empty'];
  }
  $vars['attributes']['id'] = 'search-api-sorts-widget-table';

  return theme('table', $vars);
}
