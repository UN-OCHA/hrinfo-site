<?php

function ar_assessments_load_template($file, $id) {
  $template =  DRUPAL_ROOT . '/' . drupal_get_path('module', 'ar_assessments') . '/templates/'.$file.'.html';
  $template = file_get_contents($template);
  $template_elt = array(
    '#tag' => 'script',
    '#attributes' => array(
      'type' => 'text/template',
      'id' => $id,
    ),
    '#value' => $template,
  );
  drupal_add_html_head($template_elt, 'ar_assessments_'.$file);
}

/**
 * Callback function to display the list of assessments for a node.
 *
 * @param node
 *  Operation or Cluster node.
 *
 * @return string
 */
function ar_assessments_page($node) {
  context_set('context', 'hr_space_menu', FALSE);
  $operation = $node->type == 'hr_bundle' ? $op = node_load(_hr_bundles_get_operation($node->nid)) : $node;
  $operation_wrapper = entity_metadata_wrapper('node', $operation);
  $templates = array(
    'ar_assessments_list',
    'ar_assessments_row',
    'ar_assessments_assessment'
  );
  foreach ($templates as $template) {
    ar_assessments_load_template($template, $template);
  }

  $settings = array();
  $settings['operation_id'] = $operation->nid;
  // Get the operation id from the cluster.
  $settings['bundle'] = $node->type == 'hr_bundle' ? $node->nid : '';

  return array(
    '#theme' => 'ar_assessments_assessments',
    '#attached' => array(
      'js' => array(
        '//cdnjs.cloudflare.com/ajax/libs/underscore.js/1.8.3/underscore-min.js' => array('type' => 'external'),
        '//cdnjs.cloudflare.com/ajax/libs/backbone.js/1.3.3/backbone-min.js' => array('type' => 'external'),
        drupal_get_path('module', 'ar_assessments') . '/js/ar_assessments.js',
        array(
          'data' => array('ar_assessments' => $settings),
          'type' => 'setting'
        ),
      ),
      'library' => array(
        array('chosen', 'drupal.chosen'),
        array('system', 'ui.autocomplete'),
      ),
    ),
  );
}
