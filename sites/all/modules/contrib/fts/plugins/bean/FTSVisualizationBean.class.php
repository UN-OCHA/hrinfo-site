<?php
/**
 * @file
 * Listing bean plugin.
 */

class FTSVisualizationBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(
        'type' => 'pie',
        'appeal' => FALSE,
        'groupby' => '',
        'howmany_select' => '1',
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
      'line' =>t('Line'),
      'column' => t('Column'),
      'bar' => t('Bar'),
      'table' => t('Table'),
    );
    
    $form['settings']['type'] = array(
      '#type' => 'select',
      '#title' => t('Type'),
      '#options' => $type_options,
      '#default_value' => isset($bean->settings['type']) ? $bean->settings['type'] : 'pie',
      '#required' => TRUE,
    );
	
    $form['settings']['appeals'] = array(
      '#type' => 'select',
      '#title' => t('Appeal(s)'),
      '#multiple' => TRUE,
      '#options' => _fts_visualization_get_appeal_options(),    
      '#default_value' => isset($bean->settings['appeals']) ? $bean->settings['appeals'] : '',
      '#ajax' => array(
        'callback' => '_fts_visualization_appeals_callback',
        'wrapper' => 'cluster'
      ),
    );
    
    $selected = '';
    // If only one appeal is selected
    if (isset($form_state['input']['settings']['appeals']) && count($form_state['input']['settings']['appeals']) == 1) {
      $selected = $form_state['input']['settings']['appeals'][0];
    }
    
    $form['settings']['cluster'] = array(
      '#type' => 'select',
      '#title' => t('Cluster'),
      '#required' => FALSE,
      '#default_value' => isset($bean->settings['cluster']) ? $bean->settings['cluster'] : '',
      '#prefix' => '<div id="cluster">',
      '#suffix' => '</div>',
      '#options' => _fts_visualization_get_cluster_options_by_appeal($selected),
    );
    
    $form['settings']['countries'] = array(
      '#type' => 'select',
      '#title' => t('Countries'),
      '#multiple' => TRUE,
      '#options' => _fts_visualization_get_countries_options(),    
      '#default_value' => isset($bean->settings['countries']) ? $bean->settings['countries'] : '',
    );
    
    $groupby_options = array(
      '' => t('None'),
      'cluster' => t('Cluster'),
      'donor' => t('Donor'),
    );
    
    $form['settings']['groupby'] = array(
      '#type' => 'select',
      '#title' => t('Group By'),
      '#options' => $groupby_options,
      '#default_value' => isset($bean->settings['groupby']) ? $bean->settings['groupby'] : '',
      '#required' => FALSE,
      '#multiple' => FALSE,
      /*'#states' => array(
        'visible' => array(
          ':input[name="settings[cluster]"]' => array('value' => ""),
        ),
      )*/
    );


    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    drupal_add_css(drupal_get_path('module', 'fts_visualization').'/fts_visualization.css');
    $settings = $bean->settings;
    $settings['title'] = $bean->title;
    $render = array();
    $render[] = fts_visualization_render_chart($settings);
    $render[] = array('#markup' => '<p class="fts_visualization_source">'.l('Funding figures as reported to FTS. Funding is the sum of commitments and paid contributions.', 'http://fts.unocha.org/').'</p>');
    return $render;
  }
}
