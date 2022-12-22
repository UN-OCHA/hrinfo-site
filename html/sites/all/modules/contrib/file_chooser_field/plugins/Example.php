<?php

/**
 * @file
 * File Chooser Field Plugins class
 */

/**
 * File Chooser Field plugin example.
 */
class Example extends FileChooserFieldPlugin {

  /**
   * {@inheritdoc}
   */
  public function label() {
    return t('Example');
  }

  /**
   * {@inheritdoc}
   */
  public function cssClass() {
    return 'example-picker';
  }

  /**
   * {@inheritdoc}
   */
  public function attributes($info) {
    return array(
      'plugin'       => get_class($this), // Required
      'cardinality'  => $info['cardinality'],
      'description'  => strip_tags($info['description']),
      'max-filesize' => $info['upload_validators']['file_validate_size'][0],
      'multiselect'  => $info['multiselect'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function assets() {
    drupal_add_js(drupal_get_path('module', 'file_chooser_field') . '/js/file_chooser_field.example.js');
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {

    $form['example_client_id'] = array(
      '#title' => t('Example variable'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('example_client_id'),
      '#description' => t('Description of the configraiont option.'),
    );

    return $form;

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    $this->setSetting('example_client_id', $form_state['values']['example_client_id']);
  }

  /**
   * {@inheritdoc}
   */
  public function download($destination, $url) {
    $local_file = '';
    list($file_url, $orignal_name) = explode('@@@', $url);
    $local_file = system_retrieve_file($file_url, $destination  . '/' . $orignal_name);
    return $local_file;
  }

}
