<?php

/**
 * @file
 * File Chooser Field Plugins class
 */

/**
 * The Box Picker API integration class.
 */
class BoxPickerAPI extends FileChooserFieldPlugin {

  /**
   * {@inheritdoc}
   */
  public function label() {
    return t('Box');
  }

  /**
   * {@inheritdoc}
   */
  public function cssClass() {
    return 'box-picker';
  }

  /**
   * {@inheritdoc}
   */
  public function attributes($info) {
    return array(
      'plugin'       => get_class($this),
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
    $box_client_id = $this->getSetting('box_client_id');
    drupal_add_js(
      array(
        'file_chooser_field' => array(
          'box_client_id' => $box_client_id,
        )
      ),
      'setting'
    );
    drupal_add_js('https://app.box.com/js/static/select.js', array('external' => TRUE));
    drupal_add_js(drupal_get_path('module', 'file_chooser_field') . '/js/file_chooser_field.box.js');
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {

    $form['box_client_id'] = array(
      '#title' => t('Box Client ID'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('box_client_id'),
      '#description' => t('Please <a href="https://app.box.com/developers/services" target="_blank">create a Box Application</a> to get the Client ID.'),
    );

    return $form;

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    $this->setSetting('box_client_id', $form_state['values']['box_client_id']);
  }

  /**
   * {@inheritdoc}
   */
  public function download($destination, $url) {
    $local_file = '';
    list($file_url, $original_name) = explode('@@@', $url);

    if (strpos($file_url, 'https://dl.boxcloud.com/d/1/') === 0) {
      return system_retrieve_file($file_url, $destination . '/' . $original_name);
    }

    return FALSE;
  }
}
