<?php

/**
 * @file
 * Definition of the 'bootstrap_style' panels style plugin.
 */

$plugin = array(
  'title' => t('Bootstrap Styles'),
  'description' => t('Render using Bootstrap styles'),
  // We offer substyles so provide callbacks to do so.
  'get child' => 'panels_bootstrap_styles_get_substyle',
  'get children' => 'panels_bootstrap_styles_get_substyles',
  'settings form' => 'panels_bootstrap_styles_settings_form',
  'pane settings form' => 'panels_bootstrap_styles_settings_form',
  'defaults' => array(
    'modifier_class' => '',
    'hide_classes' => array(),
    'additional_classes' => array(),
    'collapsible' => FALSE,
    'collapsed' => '',
    'region_title' => '',
  ),
);

/**
 * Callback to provide a single bootstrap style.
 */
function panels_bootstrap_styles_get_substyle($plugin, $style_name, $substyle_name) {
  $substyle = panels_bootstrap_styles_load_substyles($substyle_name);
  return panels_bootstrap_styles_merge_plugin($plugin, $style_name, $substyle);
}

/**
 * Callback to provide all bootstrap styles.
 */
function panels_bootstrap_styles_get_substyles($plugin, $style_name) {
  $data = panels_bootstrap_styles_load_substyles();
  foreach ($data as $id => $substyle) {
    $substyles[$style_name . ':' . $id] = panels_bootstrap_styles_merge_plugin($plugin, $style_name, $substyle);
  }
  return $substyles;
}

/**
 * Merge the main stylizer plugin with a style to create a sub plugin.
 *
 * This is used for both panels_stylizer_get_substyle and
 * panels_stylizer_get_substyles.
 */
function panels_bootstrap_styles_merge_plugin($plugin, $style_name, $substyle) {
  $plugin['name'] = $style_name . ':' . $substyle['name'];
  $plugin['title'] = 'Bootstrap Styles: ' . check_plain($substyle['title']);
  $plugin['description'] = check_plain($substyle['description']);
  $plugin['substyle'] = $substyle;
  if (!empty($substyle['panes'])) {
    $plugin['render pane'] = 'panels_bootstrap_styles_render_pane';
  }
  if (!empty($substyle['regions'])) {
    $plugin['render region'] = 'panels_bootstrap_styles_render_region';
  }
  $plugin['weight'] = 0;
  return $plugin;
}

/**
 * Theme function for the region styles.
 */
function theme_panels_bootstrap_styles_render_region(&$variables) {
  $settings = $variables['settings'];
  $style = $variables['style'];
  $substyle = $style['substyle'];

  // Prepare the classes.
  $base = $substyle['name'];
  $wrapper_classes = array($base);
  if (!empty($substyle['modifier_classes'])) {
    $wrapper_classes[] = !empty($settings['modifier_class']) ? $settings['modifier_class'] : $base . '-default';
  }
  $hide_classes = isset($settings['hide_classes']) ? array_filter($settings['hide_classes']) : array();
  $additional_classes = isset($settings['additional_classes']) ? array_filter($settings['additional_classes']) : array();

  // Combine all wrapper classes together.
  $wrapper_classes = array_merge($wrapper_classes, $hide_classes, $additional_classes);

  $style = array(
    'region_title' => !empty($settings['region_title']) ? $settings['region_title'] : '',
    'wrapper_classes' => $wrapper_classes,
    'header_class' => $base . '-heading',
    'title_class' => $base . '-title',
    'content_class' => $base . '-body',
    'footer_class' => $base . '-footer',
    'wrapper_element' => $substyle['wrapper_element'],
    'header_element' => $substyle['header_element'],
    'title_element' => $substyle['title_element'],
    'content_element' => $substyle['content_element'],
    'footer_element' => $substyle['footer_element'],
    'links_element' => $substyle['links_element'],
  );
  $variables['#collapsible'] = !empty($settings['collapsible']) || $substyle['name'];
  $variables['#collapsed'] = (!empty($settings['collapsible']) || $substyle['name']) && !empty($settings['collapsed']);

  $variables['style_settings'] = $style;
  $output = theme('panels_bootstrap_region', $variables);
  return $output;
}

/**
 * Theme function for the pane style.
 */
function theme_panels_bootstrap_styles_render_pane(&$variables) {
  $settings = $variables['settings'];
  $style = $variables['style'];
  $substyle = $style['substyle'];

  // Prepare the classes.
  $base = ($substyle['name'] == 'accordion' ? 'panel' : $substyle['name']);
  $wrapper_classes = array($base);
  if (!empty($substyle['modifier_classes'])) {
    $wrapper_classes[] = !empty($settings['modifier_class']) ? $settings['modifier_class'] : $base . '-default';
  }
  $hide_classes = isset($settings['hide_classes']) ? array_filter($settings['hide_classes']) : array();
  $additional_classes = isset($settings['additional_classes']) ? array_filter($settings['additional_classes']) : array();

  // Combine all wrapper classes together.
  $wrapper_classes = array_merge($wrapper_classes, $hide_classes, $additional_classes);

  $style = array(
    'wrapper_classes' => $wrapper_classes,
    'header_class' => $base . '-heading',
    'title_class' => $base . '-title',
    'content_class' => $base . '-body',
    'footer_class' => $base . '-footer',
    'wrapper_element' => $substyle['wrapper_element'],
    'header_element' => $substyle['header_element'],
    'title_element' => $substyle['title_element'],
    'content_element' => $substyle['content_element'],
    'footer_element' => $substyle['footer_element'],
    'links_element' => $substyle['links_element'],
  );
  $variables['#collapsible'] = !empty($settings['collapsible'])|| $substyle['name'] == 'accordion';
  $variables['#collapsed'] = (!empty($settings['collapsible'])|| $substyle['name'] == 'accordion') && !empty($settings['collapsed']);

  $variables['style_settings'] = $style;
  $output = theme('panels_bootstrap_pane', $variables);
  return $output;
}

/**
 * Options for the Panels style plugin to help style panes.
 */
function panels_bootstrap_styles_settings_form($settings, $display, $pid, $type, $form_state) {
  $style = $form_state['style'];
  $substyle = $style['substyle'];
  $form = array();

  $base_class = !empty($substyle['class']) ? $substyle['class'] : $substyle['name'];

  if ($type == 'region') {
    $form['region_title'] = array(
      '#title' => t('Region Title'),
      '#type' => 'textfield',
      '#default_value' => $settings['region_title'],
      '#description' => t('Specify an optional title to be displayed at the top of the region.'),
    );
  }

  if (!empty($substyle['modifier_classes'])) {
    // Style provides modifier array.
    if (is_array($substyle['modifier_classes'])) {
      $modifier_options = $substyle['modifier_classes'];
    }
    else {
      $modifier_options = array(
        $base_class . '-primary' => 'Primary',
        $base_class . '-success' => 'Success',
        $base_class . '-info' => 'Info',
        $base_class . '-warning' => 'Warning',
        $base_class . '-danger' => 'Danger',
      );
    }

    $form['modifier_class'] = array(
      '#title' => t('Style Modifier'),
      '#type' => 'select',
      '#options' => $modifier_options,
      '#default_value' => $settings['modifier_class'],
      '#empty_option' => t('Default'),
      '#empty_value' => NULL,
    );
  }

  if (!empty($substyle['collapsible'])) {
    $form['collapsible'] = array(
      '#title' => t('Collapsible'),
      '#type' => 'checkbox',
      '#default_value' => $settings['collapsible'],
      '#description' => t('Choose whether the element is collapsible. Note: This needs a title to be set to work well.'),
    );

    $form['collapsed'] = array(
      '#title' => t('Collapsed'),
      '#type' => 'checkbox',
      '#default_value' => $settings['collapsed'],
      '#description' => t('Choose the default state of the collapsible element.'),
      '#states' => array(
        'visible' => array(
          ':input[name="settings[collapsible]"]' => array('checked' => TRUE),
        ),
      ),
    );
  }

  if (!empty($substyle['hide_classes'])) {
    if (is_array($substyle['hide_classes'])) {
      $hide_options = $substyle['hide_classes'];
    }
    else {
      $hide_options = array(
        'hidden-xs' => t('Phone'),
        'hidden-sm' => t('Tablet'),
        'hidden-md' => t('Desktop'),
        'hidden-lg' => t('Large Desktop'),
      );
    }

    $form['hide_classes'] = array(
      '#type' => 'checkboxes',
      '#options' => $hide_options,
      '#title' => t('Hide this !type on the following devices.', array('!type' => $type)),
      '#default_value' => $settings['hide_classes'],
    );
  }

  if (!empty($substyle['additional_classes'])) {
    if (is_array($substyle['additional_classes'])) {
      $additional_options = $substyle['additional_classes'];
    }
    else {
      $additional_options = array(
        'pull-left' => 'Float Left',
        'pull-right' => 'Float Right',
        'clearfix' => 'Clearfix',
      );
    }

    $form['additional_classes'] = array(
      '#title' => t('Additional Classes'),
      '#type' => 'checkboxes',
      '#options' => $additional_options,
      '#default_value' => $settings['additional_classes'],
    );
  }

  return $form;
}
