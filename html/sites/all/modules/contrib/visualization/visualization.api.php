<?php

/**
 * @file
 * Hooks provided by Visualization.
 */

/**
 * Example page that demonstrates how to use the theme hook to visualize data
 * using the Visualization API. You can also use the Views display plugin if
 * you construct your data queries using Views.
 */
function example_page() {
  $data = array(
    array('fruit' => 'apple', 'votes' => 5),
    array('fruit' => 'mango', 'votes' => 3),
    array('fruit' => 'banana', 'votes' => 4),
  );

  $options = array(
    'title' => 'Favourite fruits',
    'fields' => array(
      'fruit' => array(
        'label' => t('Fruit'),
        'enabled' => FALSE,
      ),
      'votes' => array(
        'label' => t('Votes'),
        'enabled' => TRUE,
      ),
    ),
    'xAxis' => array(
      'labelField' => 'fruit',
    ),
    'data' => $data,
    'type' => 'pie',
  );

  return array(
    '#theme' => 'visualization',
    '#options' => $options,
  );

}