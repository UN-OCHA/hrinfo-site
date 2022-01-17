<?php

/**
 * Defines the container list builder.
 *
 * @todo The parent class combines what in D8 are separate classes
 *   list builder
 *   configuration entity controller
 *   configuration entity form
 *   configuration entity service
 * Is it worth using separate files for the different tasks?
 *
 * @todo Test the other operations: enable, disable, delete, clone, export
 * @todo Test the save operation with form error
 */
class GTMContainerExport extends ctools_export_ui {

  /**
   * {@inheritdoc}
   */
  public function get_page_title($op, $item = NULL) {
    // @todo Modify this to return strings like in D8.
    // Are you sure you want to delete the container configuration Primary?
    // return parent::get_page_title($op, $item);

    // All this code just to use the label not the machine name.
    if (empty($this->plugin['strings']['title'][$op])) {
      return;
    }

    // Replace %title that might be there with the exportable title.
    $title = $this->plugin['strings']['title'][$op];
    if (!empty($item)) {
      $export_key = $this->plugin['export']['admin_title'];
      $title = (str_replace('%title', check_plain($item->{$export_key}), $title));
    }

    return $title;
  }

  /**
   * {@inheritdoc}
   */
  public function load_item($item_name) {
    // @todo See ctools_export_crud_load()
    // This allows for a 'load callback' in which can build the object
    // with default properties if new.
    // ctools_export_load_object()
    // See google_tag_schema() comment.
    //   $defaults = _ctools_export_get_defaults($table, $export);

    // Load with config table name key but return $item_name key.
    // $item = parent::load_item("google_tag.container.$item_name");
    $item = gtag_export_crud_load('gtag_config', "google_tag.container.$item_name");
    return $item;
  }

  // ------------------------------------------------------------------------
  // Menu item manipulation.

  /**
   * {@inheritdoc}
   */
  public function access($op, $item) {
    if (in_array($op, array('import', 'export', 'disable'))) {
      // @todo This does not remove the latter two from the allowed operations
      // in build_operations() as ctools does not respect access there.
      return FALSE;
    }
    return parent::access($op, $item);
  }

  // ------------------------------------------------------------------------
  // These methods are the API for generating the list of exportable items.

  /**
   * {@inheritdoc}
   */
  public function list_form(&$form, &$form_state) {
    parent::list_form($form, $form_state);

    // Copied from OpenlayersObjects::list_form().
    $form['top row'] += $form['bottom row'];

    $form['filters'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Filters'),
    );

    $form['filters']['top row'] = $form['top row'];

    unset($form['bottom row']);
    unset($form['top row']);
  }

  /**
   * {@inheritdoc}
   */
  public function build_operations($item) {
    // @todo This override would not be necessary if ctools respected access.
    $operations = parent::build_operations($item);
    unset($operations['disable'], $operations['export']);
    return $operations;
  }

  /**
   * {@inheritdoc}
   */
  public function list_build_row($item, &$form_state, $operations) {
    // parent::list_build_row($item, $form_state, $operations);

    // Set up sorting
    $name = $item->{$this->plugin['export']['key']};
/*
    $schema = ctools_export_get_schema($this->plugin['schema']);

    // Note: $item->{$schema['export']['export type string']} should have already been set up by export.inc so
    // we can use it safely.
    switch ($form_state['values']['order']) {
      case 'disabled':
        $this->sorts[$name] = empty($item->disabled) . $name;
        break;
      case 'title':
        $this->sorts[$name] = $item->{$this->plugin['export']['admin_title']};
        break;
      case 'name':
        $this->sorts[$name] = $name;
        break;
      case 'storage':
        $this->sorts[$name] = $item->{$schema['export']['export type string']} . $name;
        break;
    }
*/
    // Without this property row is not rendered in parent::list_form_submit().
    $this->sorts[$name] = $item->weight;

    $this->rows[$name]['data'] = array();
    $this->rows[$name]['class'] = !empty($item->disabled) ? array('ctools-export-ui-disabled') : array('ctools-export-ui-enabled');

    $this->rows[$name]['data'][] = array('data' => check_plain($item->{$this->plugin['export']['admin_title']}), 'class' => array('ctools-export-ui-label'));
    $this->rows[$name]['data'][] = array('data' => check_plain($name), 'class' => array('ctools-export-ui-machine-name'));
    $this->rows[$name]['data'][] = array('data' => check_plain($item->container_id), 'class' => array('ctools-export-ui-container-id'));
    $this->rows[$name]['data'][] = array('data' => check_plain($item->weight), 'class' => array('ctools-export-ui-weight'));

    $ops = theme('links__ctools_dropbutton', array('links' => $operations, 'attributes' => array('class' => array('links', 'inline'))));

    $this->rows[$name]['data'][] = array('data' => $ops, 'class' => array('ctools-export-ui-operations'));

    // Add an automatic mouseover of the description if one exists.
    if (!empty($this->plugin['export']['admin_description'])) {
      $this->rows[$name]['title'] = $item->{$this->plugin['export']['admin_description']};
    }
  }

  /**
   * {@inheritdoc}
   */
  public function list_table_header() {
    $header = array();
    $header[] = array('data' => t('Label'), 'class' => array('ctools-export-ui-label'));
    $header[] = array('data' => t('Machine Name'), 'class' => array('ctools-export-ui-machine-name'));
    $header[] = array('data' => t('Container ID'), 'class' => array('ctools-export-ui-container-id'));
    $header[] = array('data' => t('Weight'), 'class' => array('ctools-export-ui-weight'));
    // $header[] = array('data' => t('Storage'), 'class' => array('ctools-export-ui-storage'));
    $header[] = array('data' => t('Operations'), 'class' => array('ctools-export-ui-operations'));

    return $header;
    // return parent::list_table_header();
  }

  // ------------------------------------------------------------------------
  // These methods are the API for adding/editing exportable items

  /**
   * {@inheritdoc}
   */
  public function add_page($js, $input, $step = NULL) {
    // @todo The crumb trail is Home » Administration » Configuration » System
    // Change this.
    return parent::add_page($js, $input, $step);
  }

  /**
   * {@inheritdoc}
   */
  public function clone_page($js, $input, $original, $step = NULL) {
    $original->name = $original->name . '_clone';
    $original->label = 'clone of ' . $original->label;
    $original->export_type = NULL;
    // @todo Want the machine_name element to be enabled; this would happen with
    // the add_page() but can not pass the $item=$original to it
    $this->is_cloning = TRUE;
    // @todo On save the name retains the value above (i.e. is not changed).
    return parent::edit_page($js, $input, $original, $step);
    // return parent::clone_page($js, $input, $original, $step = NULL);
  }

  /**
   * {@inheritdoc}
   */
  public function edit_save_form($form_state) {
    parent::edit_save_form($form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function edit_form(&$form, &$form_state) {
    $item = &$form_state['item'];
    if (empty($item->name)) {
      $item = $this->default_container();
    }

    parent::edit_form($form, $form_state);
    if (!empty($this->is_cloning)) {
      // Handle a clone operation; enable the machine_name element.
      $export_key = $this->plugin['export']['key'];
      $form['info'][$export_key]['#disabled'] = FALSE;
      $this->is_cloning = FALSE;
    }

    $changes = array(
      '#title' => t('Label'),
      '#required' => TRUE,
      '#description' => '',
    );
    $element = &$form['info'][$this->plugin['export']['admin_title']];
    $element = $changes + $element;

    $changes = array(
      '#description' => 'A unique machine-readable name. Can only contain lowercase letters, numbers, and underscores.',
    );
    $element = &$form['info'][$this->plugin['export']['key']];
    $element = $changes + $element;

    // Load the container form elements.
    module_load_include('inc', 'google_tag', 'includes/form/container');
    google_tag_container_form($form, $form_state);
  }

  /**
   * {@inheritdoc}
   *
   * This is NOT the 'final' form submission but a wizard step submit.
   * See edit_save_form() method.
   */
  public function edit_form_submit(&$form, &$form_state) {
    // @todo Just like fields that change the 'value' during load-save,
    // backup the current form_state 'item' and restore it after save?
    // @todo Add the status property to data.
    // @todo ctools stores status in the variable table for all objects.
    // It relies on config.export.status key
    $values = &$form_state['values'];
    $data['name'] = $values['name'];
    $data['label'] = $values['label'];
    $data['status'] = TRUE;
    $data += $this->values_to_data($form_state);
    $values['name'] = "google_tag.container.{$values['name']}";
    $values['data'] = $data;
    // The parent routine adds values to the item.
    // $form_state['item']->{$key} = $form_state['values'][$key];
    parent::edit_form_submit($form, $form_state);
  }

  // ------------------------------------------------------------------------
  // These methods are the API for 'other' stuff with exportables such as
  // enable, disable, import, export, delete

  /**
   * {@inheritdoc}
   */
  public function set_item_state($state, $js, $input, $item) {
    // @todo The config object state is stored in variable table; see the
    // default_config key. Why not in the config object storage?
    return parent::set_item_state($state, $js, $input, $item);
  }

  /**
   * {@inheritdoc}
   */
  public function delete_form_submit(&$form_state) {
    $item = &$form_state['item'];
    $item->name = "google_tag.container.{$item->name}";
    parent::delete_form_submit($form_state);
  }

  /**
   * Returns associative array of default values keyed by variable name.
   *
   * @todo Return values from the _default_container setting as in 8x.
   *
   * @return array
   *   Associative array of default values keyed by variable name.
   */
  public static function variables_get($include_settings = FALSE) {
    static $items;

    if (!isset($items)) {
      module_load_include('inc', 'google_tag', 'includes/variable');
      $defaults = \GTMSettings::getInstance();
      $items = array();
      // @todo Avoid loops by storing in a '__default_container' key?
      $types = google_tag_condition_filter();
      $groups = array_merge(array('general', 'advanced'), array_keys($types));
      $include_settings ? array_unshift($groups, 'settings') : '';
      foreach ($groups as $group) {
        $function = "_google_tag_variable_info_$group";
        $variables = $function(array());
        foreach ($variables as $name => $variable) {
          // The variable definitions hold the initial configuration values
          // and will apply until the settings form is submitted.
          $key = str_replace('google_tag_', '', $name);
          $items[$name] = isset($defaults->$key) ? $defaults->$key : $variable['default'];
        }
      }
    }
    return $items;
  }

  /**
   * Returns associative array of default values keyed by variable name.
   *
   * @return array
   *   Associative array of default values keyed by variable name.
   */
  public function default_container() {
    static $container;
    if (!isset($container)) {
      // The 'after' keys are added by ctools.
      $before = array('name' => '', 'label' => '', 'status' => TRUE);
      $after = array('type' => 'Normal', 'export_type' => NULL);
      $variables = $before + $this->variables_get() + $after;
      $container = (object) $variables;
    }
    return $container;
  }

  /**
   * Returns associative array of submitted values keyed by variable name.
   *
   * @return array
   *   Associative array of submitted values keyed by variable name.
   */
  public function values_to_data(array $form_state) {
    // @todo Add properties that are not defined as variables.
    $variables = $this->variables_get() + array('status' => 1);
    $values = array_intersect_key($form_state['values'], $variables);
    // @todo Add properties that are not defined as variables.
    // $values['status'] = (bool) $variables['status'];
    return $values;
  }

}
