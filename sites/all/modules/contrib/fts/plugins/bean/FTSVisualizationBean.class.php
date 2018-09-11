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
        'event' => 'change',
        'wrapper' => 'clusters-wrapper',
        'callback' => 'fts_visualization_ajax_clusters',
        'method' => 'replace',
      ),
    );

    $appeals = isset($bean->settings['appeals']) ? $bean->settings['appeals'] : '';
    if (empty($appeals)) {
      $appeals = isset($form_state['values']['settings']['appeals']) ? $form_state['values']['settings']['appeals'] : '';
    }

    $form['settings']['clusters_wrapper'] = array('#prefix' => '<div id="clusters-wrapper">', '#suffix' => '</div>');
    $form['settings']['clusters_wrapper']['cluster'] = array(
      '#type' => 'select',
      '#title' => t('Cluster'),
      '#description' => t('Not all clusters might have data available.'),
      '#required' => FALSE,
      '#default_value' => isset($bean->settings['clusters_wrapper']['cluster']) ? $bean->settings['clusters_wrapper']['cluster'] : '',
      '#options' => !empty($appeals) ? _fts_visualization_get_cluster_options(reset($appeals)) : array(),
    );

    $groupby_options = array(
      '' => t('None'),
      'Organization' => t('Organization'),
      'Cluster' => t('Cluster'),
      'GlobalCluster' => t('Global cluster'),
    );

    $form['settings']['groupby'] = array(
      '#type' => 'select',
      '#title' => t('Group By'),
      '#options' => $groupby_options,
      '#default_value' => isset($bean->settings['groupby']) ? $bean->settings['groupby'] : '',
      '#required' => FALSE,
      '#multiple' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name="settings[cluster]"]' => array('value' => ""),
        ),
      ),
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
