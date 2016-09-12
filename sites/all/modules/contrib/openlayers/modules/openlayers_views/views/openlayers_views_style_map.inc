<?php

/**
 * @file
 * This file holds style plugin for OpenLayers Views
 *
 * @ingroup openlayers
 */

/**
 * @class
 * Extension of the Views Plugin Syle for OpenLayers
 *
 * This class extended the default views plugin class to provide
 * a style plugin for the Open Layers module.
 */
class openlayers_views_style_map extends views_plugin_style {
  /**
   * @var string $map
   *   Rendered map.
   */
  public $map = '';

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['map'] = array(
        'default' => variable_get('openlayers_default_map', 'default'));
    return $options;
  }

  /**
   * Options form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Map
    $form['map'] = array(
      '#type' => 'select',
      '#title' => t('Map'),
      '#description' => t('This is map that will be used to render the view.'),
      '#options' => openlayers_map_options(),
      '#default_value' => $this->options['map'] ?
        $this->options['map'] :
        variable_get('openlayers_default_map', 'default'),
    );
  }

  /**
   * Query - override to make sure this doesn't get run
   */
  function query() {
    if (isset($this->view->query->fields)) {
      $this->view->query->fields = array();
    }
    $this->view->executed = TRUE;

    $map = openlayers_map_load($this->options['map']);
    $render = openlayers_render_map($map);
    if ($render || !$map->data['hide_empty_map']) {
      $this->map = $render;
      // Map display doesn't contain the view results, layer displays do.
      // Fill view result with a pseudo value so it is not empty.
      $this->view->result = array(array());
    }
  }

  /**
   * Renders views (map)
   */
  function render() {
    return theme($this->theme_functions(), array(
      'view' => $this->view,
      'options' => $this->options,
      'map' => $this->map
    ));
  }
}
