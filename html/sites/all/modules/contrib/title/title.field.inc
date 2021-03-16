<?php

/**
 * @file
 * Implement a title field formater.
 */

/**
 * Implements hook_field_formatter_info().
 */
function title_field_formatter_info() {
  return array(
    'title_linked' => array(
      'label' => t('Linked and wrapped'),
      'field types' => array('text'),
      'settings' => array(
        'title_style' => '',
        'title_link' => '',
        'title_class' => '',
        'enable_trim' => FALSE,
        'trim_length' => 50,
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function title_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();

  $wrap_tags = array(
    '_none' => t('- None -'),
    'div' => t('DIV'),
    'h1' => t('H1'),
    'h2' => t('H2'),
    'h3' => t('H3'),
    'h4' => t('H4'),
    'h5' => t('H5'),
    'h6' => t('H6'),
    'span' => t('SPAN'),
  );
  $element['title_style'] = array(
    '#title' => t('Wrap title in tag'),
    '#type' => 'select',
    '#default_value' => !empty($settings['title_style']) ? $settings['title_style'] : '_none',
    '#options' => $wrap_tags,
  );

  $link_types = array(
    'content' => t('Content (relative url)'),
    'content_absolute' => t('Content (absolute url)'),
  );
  $element['title_link'] = array(
    '#title' => t('Link title to'),
    '#type' => 'select',
    '#default_value' => $settings['title_link'],
    '#empty_option' => t('Nothing'),
    '#options' => $link_types,
  );

  $element['enable_trim'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable trimming?'),
    '#default_value' => $settings['enable_trim'],
  );

  $element['trim_length'] = array(
    '#title' => t('Trim length'),
    '#type' => 'textfield',
    '#size' => 10,
    '#default_value' => $settings['trim_length'],
    '#element_validate' => array('element_validate_integer_positive'),
    '#states' => array(
      'visible' => array(
        ':input[name*="enable_trim"]' => array('checked' => TRUE),
      ),
    ),
  );

  $element['title_class'] = array(
    '#title' => t('Tag classes'),
    '#type' => 'textfield',
    '#description' => t('A CSS class to use in the wrapper tag for the title.'),
    '#default_value' => $settings['title_class'],
    '#element_validate' => array('_title_validate_class'),
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function title_field_formatter_settings_summary($field, $instance, $view_mode) {
  $settings = $instance['display'][$view_mode]['settings'];
  $summary = array();

  $tag = isset($settings['title_style']) && $settings['title_style'] != '' && $settings['title_style'] != '_none' ? $settings['title_style'] : t('- None -');
  $summary[] = t('Title wrap tag: @tag', array('@tag' => $tag));

  $link_types = array(
    'content' => t('Linked to content'),
    'content_absolute' => t('Linked to content(absolute url)'),
  );
  // Display this setting only if field is linked.
  if (isset($link_types[$settings['title_link']])) {
    $summary[] = $link_types[$settings['title_link']];
  }

  // Display this setting only if wrapper has a class.
  if (isset($settings['title_class']) && $settings['title_class'] != '_none' && $settings['title_class'] != '') {
    $summary[] = t('Wrap tag classes: @classes', array('@classes' => $settings['title_class']));
  }

  // Display this setting only if trim is enabled.
  if (!empty($settings['enable_trim'])) {
    $summary[] = t('Trim length: @length', array('@length' => $settings['trim_length']));
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 */
function title_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = '';
  if (isset($items[0]['safe_value'])) {
    $output = $items[0]['safe_value'];
  }
  elseif (isset($items[0]['value'])) {
    $output = _text_sanitize($instance, $langcode, $items[0], 'value');
  }
  $element = array();

  if (!empty($output)) {
    if (in_array($settings['title_link'], array(
      'content',
      'content_absolute',
    ))) {
      $uri = entity_uri($entity_type, $entity);
      // If trimmed is enabled.
      if (!empty($settings['enable_trim'])) {
        $trimmed_output = text_summary($output, $instance['settings']['text_processing'] ? $items[0]['format'] : NULL, $display['settings']['trim_length']);
        // If we performed trimmed, add ellipsis in the end.
        if (drupal_strlen($output) != drupal_strlen($trimmed_output)) {
          $output = $trimmed_output . '&hellip;';
        }
      }
      $options = array(
        'html' => TRUE,
        'absolute' => $settings['title_link'] === 'content_absolute',
      );
      if (!empty($uri['options'])) {
        $options = array_merge($options, $uri['options']);
      }
      $output = l($output, $uri['path'], $options);
    }

    $wrap_tag = empty($settings['title_style']) ? '_none' : $settings['title_style'];

    if ($wrap_tag != '_none') {
      $variables = array(
        'element' => array(
          '#tag' => $wrap_tag,
          '#value' => $output,
        ),
      );

      if (!empty($settings['title_class'])) {
        $variables['element']['#attributes'] = array('class' => $settings['title_class']);
      }

      $output = theme('html_tag', $variables);
    }

    $element = array(
      array(
        '#markup' => $output,
      ),
    );
  }
  return $element;
}

/**
 * Validate the list of values.
 *
 * Validate that a space-separated list of values are lowercase and appropriate
 * for use as HTML classes.
 *
 * @see title_field_formatter_settings_form()
 */
function _title_validate_class($element, &$form_state) {
  static $validated_class = array();
  $value = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  $classes = explode(' ', $value);

  foreach ($classes as $class) {
    if (!isset($validated_class[$class])) {
      // Using drupal_clean_css_identifier() directly to allow a double
      // underscore in addition to core defaults.
      // @see: https://www.drupal.org/node/2009584.
      $validated_class[$class] = drupal_clean_css_identifier(
        drupal_strtolower($class),
        array(
          ' ' => '-',
          '__' => '__',
          '_' => '-',
          '/' => '-',
          '[' => '-',
          ']' => '',
        )
      );
    }

    if ($class !== $validated_class[$class]) {
      form_error($element, t('Wrapper classes contain illegal characters; classes should be lowercase and may contain letters, numbers, dashes and double underscores.'));
      return;
    }
  }
}
