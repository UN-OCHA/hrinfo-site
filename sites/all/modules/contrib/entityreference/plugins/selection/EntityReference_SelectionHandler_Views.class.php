<?php

/**
 * Entity handler for Views.
 */
class EntityReference_SelectionHandler_Views implements EntityReference_SelectionHandler {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new EntityReference_SelectionHandler_Views($field, $instance, $entity_type, $entity);
  }

  protected function __construct($field, $instance, $entity_type, $entity) {
    $this->field = $field;
    $this->instance = $instance;
    $this->entity = $entity;
    // Get the entity token type of the entity type.
    $entity_info = entity_get_info($entity_type);
    $this->entity_type_token = isset($entity_info['token type']) ? $entity_info['token type'] : $entity_type;
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $view_settings = empty($field['settings']['handler_settings']['view']) ? '' : $field['settings']['handler_settings']['view'];
    $displays = views_get_applicable_views('entityreference display');
    // Filter views that list the entity type we want, and group the separate
    // displays by view.
    $entity_info = entity_get_info($field['settings']['target_type']);
    $options = array();
    foreach ($displays as $data) {
      list($view, $display_id) = $data;
      if ($view->base_table == $entity_info['base table']) {
        $options[$view->name . ':' . $display_id] = $view->name . ' - ' . $view->display[$display_id]->display_title;
      }
    }

    // The value of the 'view_and_display' select below will need to be split
    // into 'view_name' and 'view_display' in the final submitted values, so
    // we massage the data at validate time on the wrapping element (not
    // ideal).
    $form['view']['#element_validate'] = array('entityreference_view_settings_validate');

    if ($options) {
      $default = !empty($view_settings['view_name']) ? $view_settings['view_name'] . ':' . $view_settings['display_name'] : NULL;
      $form['view']['view_and_display'] = array(
        '#type' => 'select',
        '#title' => t('View used to select the entities'),
        '#required' => TRUE,
        '#options' => $options,
        '#default_value' => $default,
        '#description' => '<p>' . t('Choose the view and display that select the entities that can be referenced.<br />Only views with a display of type "Entity Reference" are eligible.') . '</p>',
      );

      $default = !empty($view_settings['args']) ? implode(', ', $view_settings['args']) : '';
      $description = t('Provide a comma separated list of arguments to pass to the view.') . '<br />' . t('This field supports tokens.');

      if (!module_exists('token')) {
        $description .= '<br>' . t('Install the <a href="@url">token module</a> to get more tokens and display available once.', array('@url' => 'http://drupal.org/project/token'));
      }

      $form['view']['args'] = array(
        '#type' => 'textfield',
        '#title' => t('View arguments'),
        '#default_value' => $default,
        '#required' => FALSE,
        '#description' => $description,
        '#maxlength' => '512',
      );
      if (module_exists('token')) {
        // Get the token type for the entity type our field is in (a type 'taxonomy_term' has a 'term' type token).
        $instance_entity_info = entity_get_info($instance['entity_type']);
        $token_type = isset($instance_entity_info['token type']) ? $instance_entity_info['token type'] : $instance['entity_type'];

        $form['view']['tokens'] = array(
          '#theme' => 'token_tree',
          // The token types that have specific context. Can be multiple token types like 'term' and/or 'user'.
          '#token_types' => array($token_type),
          // A boolean TRUE or FALSE whether to include 'global' context tokens like [current-user:*]
          // or [site:*]. Defaults to TRUE.
          '#global_types' => TRUE,
          // A boolean whether to include the 'Click this token to insert in into the the focused textfield'
          // JavaScript functionality. Defaults to TRUE.
          '#click_insert' => TRUE,
        );
      }
    }
    else {
      $form['view']['no_view_help'] = array(
        '#markup' => '<p>' . t('No eligible views were found. <a href="@create">Create a view</a> with an <em>Entity Reference</em> display, or add such a display to an <a href="@existing">existing view</a>.', array(
          '@create' => url('admin/structure/views/add'),
          '@existing' => url('admin/structure/views'),
        )) . '</p>',
      );
    }
    return $form;
  }

  protected function initializeView($match = NULL, $match_operator = 'CONTAINS', $limit = 0, $ids = NULL) {
    $view_name = $this->field['settings']['handler_settings']['view']['view_name'];
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = $this->field['settings']['handler_settings']['view']['args'];
    $entity_type = $this->field['settings']['target_type'];

    // Check that the view is valid and the display still exists.
    $this->view = views_get_view($view_name);
    if (!$this->view || !isset($this->view->display[$display_name]) || !$this->view->access($display_name)) {
      watchdog('entityreference', 'The view %view_name is no longer eligible for the %field_name field.', array('%view_name' => $view_name, '%field_name' => $this->instance['label']), WATCHDOG_WARNING);
      return FALSE;
    }
    $this->view->set_display($display_name);

    // Make sure the query is not cached.
    $this->view->is_cacheable = FALSE;

    // Pass options to the display handler to make them available later.
    $entityreference_options = array(
      'match' => $match,
      'match_operator' => $match_operator,
      'limit' => $limit,
      'ids' => $ids,
    );
    $this->view->display_handler->set_option('entityreference_options', $entityreference_options);
    return TRUE;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = $this->handleArgs($this->field['settings']['handler_settings']['view']['args']);
    $result = array();
    if ($this->initializeView($match, $match_operator, $limit)) {
      // Get the results.
      $result = $this->view->execute_display($display_name, (!array_filter($args) ? array() : $args));
    }

    $return = array();
    if ($result) {
      $target_type = $this->field['settings']['target_type'];
      $entities = entity_load($target_type, array_keys($result));
      foreach($entities as $entity) {
        list($id,, $bundle) = entity_extract_ids($target_type, $entity);
        $return[$bundle][$id] = $result[$id];
      }
    }
    return $return;
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {
    $this->getReferencableEntities($match, $match_operator);
    return $this->view->total_items;
  }

  function validateReferencableEntities(array $ids) {
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = $this->handleArgs($this->field['settings']['handler_settings']['view']['args']);
    $result = array();
    if ($this->initializeView(NULL, 'CONTAINS', 0, $ids)) {
      // Get the results.
      $entities = $this->view->execute_display($display_name, $args);
      $result = array_keys($entities);
    }
    return $result;
  }

  /**
   * Implements EntityReferenceHandler::validateAutocompleteInput().
   */
  public function validateAutocompleteInput($input, &$element, &$form_state, $form) {
    return NULL;
  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    return entity_label($this->field['settings']['target_type'], $entity);
  }

  /**
   * Implements EntityReferenceHandler::entityFieldQueryAlter().
   */
  public function entityFieldQueryAlter(SelectQueryInterface $query) {

  }

  /**
   * Handles arguments for views.
   *
   * Replaces tokens using token_replace().
   *
   * @param array $args
   *   Usually $this->field['settings']['handler_settings']['view']['args'].
   *
   * @return array
   *   The arguments to be send to the View.
   */
  protected function handleArgs($args) {
    // Parameters for token_replace().
    $data = array();
    $options = array('clear' => TRUE);

    // Check if the entity has an ID. If not, don't pass the entity to token_replace().
    if ($this->entity) {
      list($id, $vid, $bundle) = entity_extract_ids($this->instance['entity_type'], $this->entity);
      if (!empty($id)) {
        // Only pass the entity to token_replace() if it has a valid ID.
        $data = array($this->entity_type_token => $this->entity);
      }
    }
    // Replace tokens for each argument.
    foreach ($args as $key => $arg) {
      $args[$key] = token_replace($arg, $data, $options);
    }
    return array_filter($args);
  }
}

function entityreference_view_settings_validate($element, &$form_state, $form) {
  // Split view name and display name from the 'view_and_display' value.
  if (!empty($element['view_and_display']['#value'])) {
    list($view, $display) = explode(':', $element['view_and_display']['#value']);
  }
  else {
    form_error($element, t('The views entity selection mode requires a view.'));
    return;
  }

  // Explode the 'args' string into an actual array. Beware, explode() turns an
  // empty string into an array with one empty string. We'll need an empty array
  // instead.
  $args_string = trim($element['args']['#value']);
  if ($args_string === '') {
    $args = array();
  }
  else {
    // array_map is called to trim whitespaces from the arguments.
    $args = array_map('trim', explode(',', $args_string));
  }

  $value = array('view_name' => $view, 'display_name' => $display, 'args' => $args);
  form_set_value($element, $value, $form_state);
}
