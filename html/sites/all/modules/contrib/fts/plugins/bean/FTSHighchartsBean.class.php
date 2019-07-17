<?php
/**
 * @file
 * Listing bean plugin.
 */

class FTSHighchartsBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(
        'type' => 'pie',
        'appeal' => FALSE,
        'groupby' => '',
      ),
    );

    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Settings'),
    );
    
    $type_options = array(
      'pie' => t('Pie'),
      'bar' => t('Bar'),
    );
    
    if (!isset($bean->settings['type'])) {
      $default_type = 'pie';
    }
    else {
      $default_type = $bean->settings['type'];
    }
    
    $form['settings']['type'] = array(
      '#type' => 'select',
      '#title' => t('Type'),
      '#options' => $type_options,
      '#default_value' => $default_type,
      '#required' => TRUE,
      '#multiple' => FALSE,
    );
    
    if (!isset($bean->settings['appeal'])) {
      $default_appeal = '';
    }
    else {
      $default_appeal = $bean->settings['appeal'];
    }
    
    $form['settings']['appeal'] = array(
      '#type' => 'textfield',
      '#title' => t('Appeal ID'),
      '#required' => TRUE,
      '#default_value' => $default_appeal,
    );
    
    $groupby_options = array(
      '' => t('None'),
      'cluster' => t('Cluster'),
      'donor' => t('Donor'),
    );
    
    if (!isset($bean->settings['groupby'])) {
      $default_groupby = '';
    }
    else {
      $default_groupby = $bean->settings['groupby'];
    }
    
    $form['settings']['groupby'] = array(
      '#type' => 'select',
      '#title' => t('Group By'),
      '#options' => $groupby_options,
      '#default_value' => $default_groupby,
      '#required' => FALSE,
      '#multiple' => FALSE,
    );
    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $settings = $bean->settings;
    $settings['title'] = $bean->title;
    $options = fts_highcharts_render($settings);
    $attributes = array();
    $content = highcharts_render($options, $attributes);
    return $content;
  }
}
