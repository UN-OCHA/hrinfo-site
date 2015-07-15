<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Overview Map Behavior.
 */
class openlayers_behavior_overviewmap extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'projection' => array(),
      'maxExtent' => array(),
      'maximized' => 'false',
      'minRectSize' => 0,
      'minRatio' => 8,
      'maxRatio' => 32,
      'mapOptions' => array(
        'numZoomLevels' => 1,
        'zoom' => 1,
      ),
      'size' => array(
        'h' => 100,
        'w' => 150,
      ),
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.OverviewMap');
  }

  function options_form($defaults = array()) {
    $form = array();

    // Projections select.
    $projections = openlayers_ui_get_projection_options();
    $options = array_keys($projections);
    $options = array_combine($options, $options);
    $form['projection'] = array(
      '#title' => t('Projections'),
      '#type' => 'select',
      '#options' => $options,
      '#description' => t('Select the projection of the overview map.'),
      '#default_value' => isset($defaults['projection']) ? $defaults['projection'] : array(),
    );

    $form['size'] = array(
      '#title' => t('Size'),
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#description' => t('Overview map size in pixels.'),
    );

    $form['size']['w'] = array(
      '#title' => t('Width'),
      '#type' => 'textfield',
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => isset($defaults['size']['w']) ? $defaults['size']['w'] : 150,
    );

    $form['size']['h'] = array(
      '#title' => t('Height'),
      '#type' => 'textfield',
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => isset($defaults['size']['h']) ? $defaults['size']['h'] : 100,
    );

    $form['maximized'] = array(
      '#title' => t('Maximized'),
      '#type' => 'radios',
      '#description' => t('Start as maximized (visible).'),
      '#options' => array(
        'true' => t('Yes'),
        'false' => t('No'),
      ),
      '#default_value' => isset($defaults['maximized']) ? $defaults['maximized'] : 'true',
    );

    $form['minRatio'] = array(
      '#title' => t('Minimum ratio'),
      '#type' => 'textfield',
      '#size' => 10,
      '#maxlength' => 10,
      '#description' => t('The ratio of the overview map resolution to the main map resolution at which to zoom farther out on the overview map.'),
      '#default_value' => isset($defaults['minRatio']) ? $defaults['minRatio'] : 8,
    );

    $form['maxRatio'] = array(
      '#title' => t('Maximum ratio'),
      '#type' => 'textfield',
      '#size' => 10,
      '#maxlength' => 10,
      '#description' => t('The ratio of the overview map resolution to the main map resolution at which to zoom farther in on the overview map.'),
      '#default_value' => isset($defaults['maxRatio']) ? $defaults['maxRatio'] : 32,
    );

    $form['mapOptions'] = array(
      '#title' => t('Map options'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t("Any non-default properties to be sent to the overview map's map constructor."),
    );

    $form['mapOptions']['numZoomLevels'] = array(
      '#title' => t('Number of zoom levels'),
      '#type' => 'textfield',
      '#size' => 10,
      '#maxlength' => 10,
      '#description' => t('Set to 1 to disable overview map zooming.'),
      '#default_value' => isset($defaults['mapOptions']['numZoomLevels']) ? $defaults['mapOptions']['numZoomLevels'] : 1,
    );
    $form['mapOptions']['zoom'] = array(
      '#title' => t('Zoom'),
      '#type' => 'textfield',
      '#size' => 10,
      '#maxlength' => 10,
      '#description' => t('The initial zoom level when loading the map.'),
      '#default_value' => isset($defaults['mapOptions']['zoom']) ? $defaults['mapOptions']['zoom'] : 3,
    );

    return $form;
  }


  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') . '/plugins/behaviors/openlayers_behavior_overviewmap.js');
    return $this->options;
  }
}
