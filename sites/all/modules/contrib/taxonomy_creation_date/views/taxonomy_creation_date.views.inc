<?php
/**
 * Implements hook_views_data()
 */
function taxonomy_creation_date_views_data() {

  $data['taxonomy_term_data']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the term was last created'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
      ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['taxonomy_term_data']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the term was last updated'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
      ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );


  return $data;
}
