<?php

/**
 * Callback to prepare row data for later rendering.
 *
 * @param $vars
 */
function template_preprocess_views_view_pivot_table(&$vars) {
  $view     = $vars['view'];

  // We need the raw data for this grouping, which is passed in as $vars['rows'].
  // However, the template also needs to use for the rendered fields.  We
  // therefore swap the raw data out to a new variable and reset $vars['rows']
  // so that it can get rebuilt.
  // Store rows so that they may be used by further preprocess functions.
  $result = $vars['result'] = $vars['rows'];
  $vars['rows'] = array();
  $vars['field_classes'] = array();
  $vars['header'] = array();
  $vars['hide_subheader'] = TRUE;
  $vars['aggregate_columns'] = array();

  /* @var $options array */
  /* @var $handler views_plugin_style_pivot */
  $options  = $view->style_plugin->options;
  $handler  = $view->style_plugin;

  $default_row_class = isset($options['default_row_class']) ? $options['default_row_class'] : TRUE;
  $row_class_special = isset($options['row_class_special']) ? $options['row_class_special'] : TRUE;

  $pivot_col = $options['pivot_col'];
  $pivot_row = $options['pivot_row'];
  $vertical  = ($options['pivot_mode_multi_values'] == VIEWS_PIVOT_MODE_MULTI_VALUE_VERTICAL);

  $fields   = &$view->field;
  $columns  = $handler->sanitize_columns($options['columns'], $fields);

  $active   = !empty($handler->active) ? $handler->active : '';
  $order    = !empty($handler->order) ? $handler->order : 'asc';

  $aggregates = array();
  $pivot_extra = array();
  foreach ($columns as $field => $column) {
    if (!empty($options['info'][$field]['pivot_row_extra'])) {
      if ($column != $pivot_col && $column != $pivot_row) {
        $pivot_extra[] = $column;
      }
    }
  }

  $query    = tablesort_get_query_parameters();
  if (isset($view->exposed_raw_input)) {
    $query += $view->exposed_raw_input;
  }

  // Fields must be rendered in order as of Views 2.3, so we will pre-render
  // everything.
  $renders = $handler->render_fields($result);

  foreach ($result as $num => $row) {
    _views_pivot_add_field_to_row($vars, $options, $renders, $fields, $num, VIEWS_PIVOT_HEADER_KEY, $pivot_col, $renders[$num][$pivot_col], $renders[$num][$pivot_col], FALSE);
    _views_pivot_add_field_to_row($vars, $options, $renders, $fields, $num, $renders[$num][$pivot_row], $pivot_row, $columns[$pivot_row], $columns[$pivot_row], FALSE);
  }
  foreach ($columns as $field => $column) {
    /* @var $field_handler views_handler_field_field */
    $field_handler = $fields[$field];
    // Create a second variable so we can easily find what fields we have and what the
    // CSS classes should be.
    $vars['fields'][$field] = drupal_clean_css_identifier($field);
    if ($active == $field) {
      $vars['fields'][$field] .= ' active';
    }

    // render the header labels
    if ($field == $column && empty($field_handler->options['exclude'])) {
      $label = check_plain(!empty($field_handler) ? $field_handler->label() : '');
      if ($field == $pivot_col) {
        if (!empty($vars['pivotheader'])) {
          foreach ($vars['pivotheader'] as $key => $value) {
            $vars['header'][$key] = $value;
          }
        }
        continue;
      }
      $header_area = 'subheader';
      if ($field == $pivot_row) {
        $header_area = 'header';
      }
      else if (in_array($column, $pivot_extra)) {
        $header_area = 'header';
      }
      if (empty($options['info'][$field]['sortable']) || !$field_handler->click_sortable()) {
        $vars[$header_area][$field] = $label;
      }
      else {
        $initial = !empty($options['info'][$field]['default_sort_order']) ? $options['info'][$field]['default_sort_order'] : 'asc';

        if ($active == $field) {
          $initial = ($order == 'asc') ? 'desc' : 'asc';
        }

        $title = t('sort by @s', array('@s' => $label));
        if ($active == $field) {
          $label .= theme('tablesort_indicator', array('style' => $initial));
        }

        $query['order'] = $field;
        $query['sort'] = $initial;
        $link_options = array(
          'html' => TRUE,
          'attributes' => array('title' => $title),
          'query' => $query,
        );
        $vars[$header_area][$field] = l($label, $_GET['q'], $link_options);
      }

      $vars['header_classes'][$field] = '';
      // Set up the header label class.
      if ($field_handler->options['element_default_classes']) {
        $vars['header_classes'][$field] .= "views-field views-field-" . $vars['fields'][$field];
      }
      $class = $field_handler->element_label_classes(0);
      if ($class) {
        if ($vars['header_classes'][$field]) {
          $vars['header_classes'][$field] .= ' ';
        }
        $vars['header_classes'][$field] .= $class;
      }
      // Add a CSS align class to each field if one was set
      if (!empty($options['info'][$field]['align'])) {
        $vars['header_classes'][$field] .= ' ' . drupal_clean_css_identifier($options['info'][$field]['align']);
      }

      // Add a header label wrapper if one was selected.
      if (!empty($vars['header'][$field])) {
        $element_label_type = $field_handler->element_label_type(TRUE, TRUE);
        if ($element_label_type) {
          $vars['header'][$field] = '<' . $element_label_type . '>' . $vars['header'][$field] . '</' . $element_label_type . '>';
        }
      }

    }

    // Add a CSS align class to each field if one was set
    if (!empty($options['info'][$field]['align'])) {
      $vars['fields'][$field] .= ' ' . drupal_clean_css_identifier($options['info'][$field]['align']);
    }
    if ($field == $pivot_row) {
      continue;
    }

    // Render each field into its appropriate column.
    foreach ($result as $num => $row) {
      if (($column == $pivot_row) || ($column == $pivot_col)) {
        // OK, we will append to one of those columns.
        $column_key = $column;
      }
      else if (in_array($column, $pivot_extra)) {
        $column_key = $column;
      }
      else {
        $column_key = $column . ':' . $renders[$num][$pivot_col];
      }
      $row_key = $renders[$num][$pivot_row];

      // Handle the Pivot aggregates
      $full_field_name = 'field_' . $field;
      $full_field_alias = isset($field_handler->field_alias) ? $field_handler->field_alias : FALSE;
      if (isset($view->result[$num]->{$full_field_name})) {
        if (is_array($view->result[$num]->{$full_field_name})) {
          $value = $view->result[$num]->{$full_field_name}[0]['raw']['value'];
        }
        else {
          $value = $view->result[$num]->{$full_field_name};
        }
      }
      else if (isset($view->result[$num]->{$field})) {
        $value = $view->result[$num]->{$field};
      }
      else if (isset($view->result[$num]->{$full_field_alias})) {
        if (is_array($view->result[$num]->{$full_field_alias})) {
          $value = $view->result[$num]->{$full_field_alias}[0]['raw']['value'];
        }
        else {
          $value = $view->result[$num]->{$full_field_alias};
        }
      }
      else if (isset($view->result[$num]->{$full_field_alias})) {
        $value = $view->result[$num]->{$full_field_alias};
      }
      else {
        $value = 0;
      }

      if (!empty($options['info'][$field]['pivot_row_aggregate'])) {
        $aggregates['row'][$row_key][$field][] = $value;
        $aggregates['overall'][$field][] = $value;
      }
      if (!empty($options['info'][$field]['pivot_col_aggregate'])) {
        $aggregates['col'][$column_key][] = $value;
      }

      _views_pivot_add_field_to_row($vars, $options, $renders, $fields, $num, $row_key, $field, $column_key, $column);
    }
  }

  if (!empty($aggregates['row'])) {
    foreach ($aggregates['row'] as $row_key => $agg_columns) {
      foreach ($agg_columns as $column_key => $values) {
        $agg_key = 'agg:' . $column_key;
        $vars['rows'][VIEWS_PIVOT_HEADER_KEY][$agg_key] = $options['info'][$column_key]['pivot_row_aggregate_label'];
        $vars['aggregate_columns'][$agg_key] = TRUE;
        $renders[$agg_key][$column_key] = _views_pivot_format_aggregate_field($view, $fields, $column_key, $values, $options['info'][$column_key]['pivot_row_aggregate']);
        _views_pivot_add_field_to_row($vars, $options, $renders, $fields, $agg_key, $row_key, $column_key, $agg_key, '');
      }
    }
  }
  if (!empty($aggregates['col'])) {
    foreach ($aggregates['col'] as $column_key => $values) {
      $parts = explode(':', $column_key);
      $field = $parts[0];

      $row_key = 'agg:' . $field;

      $renders[$row_key][$field] = $options['info'][$field]['pivot_col_aggregate_label'];
      _views_pivot_add_field_to_row($vars, $options, $renders, $fields, $row_key, $row_key, $field, $pivot_row, '');

      $renders[$row_key][$field] = _views_pivot_format_aggregate_field($view, $fields, $field, $values, $options['info'][$field]['pivot_col_aggregate']);
      _views_pivot_add_field_to_row($vars, $options, $renders, $fields, $row_key, $row_key, $field, $column_key, '');
    }
  }
  if (!empty($aggregates['overall'])) {
    foreach ($aggregates['overall'] as $field => $values) {
      $agg_key = 'agg:' . $field;
      $renders[$agg_key][$field] = _views_pivot_format_aggregate_field($view, $fields, $field, $values, $options['info'][$field]['pivot_col_aggregate']);
      _views_pivot_add_field_to_row($vars, $options, $renders, $fields, $agg_key, $agg_key, $field, $agg_key, '');
    }
  }

  if (!empty($vars['rows'][VIEWS_PIVOT_HEADER_KEY]) ) {
    foreach ($vars['rows'][VIEWS_PIVOT_HEADER_KEY] as $key => $value) {
      $vars['header'][$key] = $value;
    }
    unset($vars['rows'][VIEWS_PIVOT_HEADER_KEY]);
  }

  // Hide table header if all labels are empty.
  if (!array_filter($vars['header'])) {
    $vars['header'] = array();
  }

  // Show table subheader if labels are not empty.
  if (array_filter($vars['subheader'])) {
    $vars['hide_subheader'] = FALSE;
  }

  $count = 0;
  foreach ($vars['rows'] as $num => $row) {
    $vars['row_classes'][$num] = array();
    if ($row_class_special) {
      $vars['row_classes'][$num][] = ($count++ % 2 == 0) ? 'odd' : 'even';
    }
    if ($row_class = $handler->get_row_class($num)) {
      $vars['row_classes'][$num][] = $row_class;
    }
  }

  if ($row_class_special) {
    $vars['row_classes'][0][] = 'views-row-first';
    $vars['row_classes'][count($vars['row_classes']) - 1][] = 'views-row-last';
  }

  $vars['classes_array'] = array('views-table');
  if (empty($vars['rows']) && !empty($options['empty_table'])) {
    $vars['rows'][0][0] = $view->display_handler->render_area('empty');
    // Calculate the amounts of rows with output.
    $vars['field_attributes'][0][0]['colspan'] = count($vars['header']);
    $vars['field_classes'][0][0] = 'views-empty';
  }


  if (!empty($options['sticky'])) {
    drupal_add_js('misc/tableheader.js');
    $vars['classes_array'][] = "sticky-enabled";
  }
  $vars['classes_array'][] = 'cols-'. count($vars['header']);

  if (!empty($handler->options['summary'])) {
    $vars['attributes_array'] = array('summary' => $handler->options['summary']);
  }

  $c = count($vars['subheader']);
  $row_span_extra_header = $vars['hide_subheader'] ? 1 : ($vertical ? ($c + 1) : 2);
  array_unshift($pivot_extra, $pivot_row);
  foreach ($pivot_extra as $field) {
    $vars['header_attributes'][$field]['rowspan'] = $row_span_extra_header;
    $vars['pivot_rows'][$field] = $vars['header'][$field];
    unset($vars['header'][$field]);
  }

  // Do this for horizontal multi field setting only.
  if ($c > 0) {
    if ($vertical) {
      foreach ($vars['rows'] as $key => $values) {
        $vars['row_attributes'][$key]['rowspan'] = $c;
      }
    }
    else {
      foreach ($vars['header'] as $field) {
        $vars['header_attributes'][$field]['colspan'] = $c;
      }
    }
  }

  $vars['vertical'] = $vertical;
}

/**
 * @param $view
 * @param $fields
 * @param $field
 * @param $values
 * @param $mode
 * @return mixed
 */
function _views_pivot_format_aggregate_field($view, $fields, $field, $values, $mode) {
  /* @var $field_handler views_handler_field_field */
  $field_handler = $fields[$field];
  $value = '';
  switch ($mode) {
    case 'sum':
      $value = array_sum($values);
      break;

    case 'avg':
      $sum = 0.0;
      $count = 0;
      foreach ($values as $value) {
        // Do not count empty or non-numeric cells.
        // Strip out any spaces and thousand makers.
        $stripped = str_replace(array(' ', ','), '', $value);
        $value = preg_match('/[-+]?\d*\.?\d+/', $stripped, $matches) ? (double)$matches[0] : FALSE;
        if ($value !== FALSE) {
          $sum += $value;
          $count++;
        }
      }
      $value = ($count == 0) ? 0.0 : $sum / $count;
      break;

    case 'count':
      // Counting most likely doesn't require the rendering like the field.
      return count($values);
      break;

    case 'max':
      $value = max($values);
      break;

    case 'min':
      $value = min($values);
      break;

  }
  $alias = empty($field_handler->aliases[$field_handler->real_field]) ? $field_handler->real_field : $field_handler->aliases[$field_handler->real_field];

  // Let's "compile" an aggregate that has all the fields with their aliases with an empty value.
  static $aggregate;
  if (!isset($aggregate)) {
    $field_data = NULL;
    $names = array();
    foreach ($view->result as $result) {
      $names += array_keys((array) $result);
      if (!isset($field_data) && isset($result->_field_data)) {
        $field_data = $result->_field_data;
      }
    }
    $aggregate = new stdClass();
    foreach ($names as $name) {
      $aggregate->{$name} = '';
    }
    $aggregate->_field_data = $field_data;
  }

  $aggregate->{$alias} = $value;

  if (method_exists($field_handler, 'set_items')) {
    $rendered = $field_handler->set_items($aggregate, 0);
    return $rendered[0]['rendered']['#markup'];
  }

  if (method_exists($field_handler, 'render')) {
    return $field_handler->render($aggregate);
  }

  return $value;
}

/**
 * Helper function to add field classes, called by _views_pivot_add_field_to_row
 *
 * @param $vars
 * @param $fields
 * @param $num
 * @param $row_key
 * @param $field
 *
 * @see _views_pivot_add_field_to_row
 */
function _views_pivot_add_field_classes(&$vars, $fields, $num, $row_key, $field) {
  /* @var $field_handler views_handler_field_field */
  $field_handler = $fields[$field];
  // Add field classes
  $vars['field_classes'][$field][$row_key] = '';
  if ($field_handler->options['element_default_classes']) {
    $vars['field_classes'][$field][$row_key] = "views-field views-field-" . $field;
  }
  if ($classes = $field_handler->element_classes($num)) {
    if ($vars['field_classes'][$field][$row_key]) {
      $vars['field_classes'][$field][$row_key] .= ' ';
    }

    $vars['field_classes'][$field][$row_key] .= $classes;
  }
  $vars['field_attributes'][$field][$row_key] = array();
}

/**
 * Helper function to add a field to a table row, called by
 * template_preprocess_views_view_pivot_table
 *
 * @param $vars
 * @param $options
 * @param $renders
 * @param $fields
 * @param $num
 * @param $row_key
 * @param $field
 * @param $column_key
 * @param $column
 * @param bool $append
 *
 * @see template_preprocess_views_view_pivot_table
 */
function _views_pivot_add_field_to_row(&$vars, $options, $renders, $fields, $num, $row_key, $field, $column_key, $column, $append = TRUE) {
  if (!isset($fields[$field])) {
    // Maybe no fields defined yet.
    return;
  }

  /* @var $field_handler views_handler_field_field */
  $field_handler = $fields[$field];
  _views_pivot_add_field_classes($vars, $fields, $num, $row_key, $field);

  if (!empty($field_handler) && empty($field_handler->options['exclude'])) {
    $field_output = $renders[$num][$field];
    $element_type = $field_handler->element_type(TRUE, TRUE);
    if ($element_type) {
      $field_output = '<' . $element_type . '>' . $field_output . '</' . $element_type . '>';
    }

    // Don't bother with separators and stuff if the field does not show up.
    if (empty($field_output) && !empty($vars['rows'][$row_key][$column_key])) {
      return;
    }

    // Let's see if we have an aggregated field
    $pivot_agg_mode = (strpos($column_key, 'agg:') === 0 || strpos($row_key, 'agg:') === 0);
    if (!$pivot_agg_mode && $append && !empty($field_handler->options['group_type']) && $field_handler->options['group_type'] == 'count') {
      if (empty($vars['rows'][$row_key][$column_key])) {
        $vars['rows'][$row_key][$column_key] = 0;
      }
      $vars['rows'][$row_key][$column_key]++;
      return;
    }

    // Place the field into the column, along with an optional separator.
    if ($append && !empty($vars['rows'][$row_key][$column_key])) {
      if (strrpos($vars['rows'][$row_key][$column_key], $field_output) !== FALSE) {
        // Ignore it as we seem to have added that already
        return;
      }
      if (!empty($options['info'][$column]['separator'])) {
        $vars['rows'][$row_key][$column_key] .= filter_xss_admin($options['info'][$column]['separator']);
      }
    }
    else {
      $vars['rows'][$row_key][$column_key] = '';
    }

    $vars['rows'][$row_key][$column_key] .= $field_output;
  }
}

/**
 * Theme the form for the pivot table style plugin
 *
 * @param $variables
 * @return string
 */
function theme_views_ui_style_plugin_pivot($variables) {
  $form = $variables['form'];

  $output = drupal_render($form['description_markup']);

  $header = array(
    t('Field'),
    t('Column'),
    t('Align'),
    t('Separator'),
    array(
      'data' => t('Pivot Row'),
      'align' => 'center',
    ),
    array(
      'data' => t('Pivot Extra Rows'),
      'align' => 'center',
    ),
    array(
      'data' => t('Pivot Column'),
      'align' => 'center',
    ),
    array(
      'data' => t('Column Aggregate'),
      'align' => 'center',
    ),
    array(
      'data' => t('Row Aggregate'),
      'align' => 'center',
    ),
    array(
      'data' => t('Sortable'),
      'align' => 'center',
    ),
    array(
      'data' => t('Default order'),
      'align' => 'center',
    ),
    array(
      'data' => t('Default sort'),
      'align' => 'center',
    ),
    array(
      'data' => t('Hide empty column'),
      'align' => 'center',
    ),
  );
  $rows = array();
  foreach (element_children($form['columns']) as $id) {
    $row = array();
    $row[] = drupal_render($form['info'][$id]['name']);
    $row[] = drupal_render($form['columns'][$id]);
    $row[] = drupal_render($form['info'][$id]['align']);
    $row[] = drupal_render($form['info'][$id]['separator']);
    $row[] = array(
      'data' => drupal_render($form['info'][$id]['pivot_row']),
      'align' => 'center',
    );
    $row[] = array(
      'data' => drupal_render($form['info'][$id]['pivot_row_extra']),
      'align' => 'center',
    );
    $row[] = array(
      'data' => drupal_render($form['info'][$id]['pivot_col']),
      'align' => 'center',
    );
    $row[] = array(
      'data' => drupal_render($form['info'][$id]['pivot_col_aggregate']) . drupal_render($form['info'][$id]['pivot_col_aggregate_label']),
      'align' => 'center',
    );
    $row[] = array(
      'data' => drupal_render($form['info'][$id]['pivot_row_aggregate']) . drupal_render($form['info'][$id]['pivot_row_aggregate_label']),
      'align' => 'center',
    );
    if (!empty($form['info'][$id]['sortable'])) {
      $row[] = array(
        'data' => drupal_render($form['info'][$id]['sortable']),
        'align' => 'center',
      );
      $row[] = array(
        'data' => drupal_render($form['info'][$id]['default_sort_order']),
        'align' => 'center',
      );
      $row[] = array(
        'data' => drupal_render($form['default'][$id]),
        'align' => 'center',
      );
    }
    else {
      $row[] = '';
      $row[] = '';
      $row[] = '';
    }
    $row[] = array(
      'data' => drupal_render($form['info'][$id]['empty_column']),
      'align' => 'center',
    );
    $rows[] = $row;
  }

  // Add the special 'None' row.
  $rows[] = array(t('None'), '', '', '', '', '', '', '', '', '', '', array('align' => 'center', 'data' => drupal_render($form['default'][-1])), '');

  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  $output .= drupal_render_children($form);
  return $output;
}
