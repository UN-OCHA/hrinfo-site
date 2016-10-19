<?php

/**
 * @file
 * File Chooser Field Plugins class
 */

/**
 * Dropbox Chooser API integration class.
 */
class DropboxChooserAPI extends FileChooserFieldPlugin {

  /**
   * {@inheritdoc}
   */
  public function label() {
    return t('Select from Dropbox');
  }

  /**
   * {@inheritdoc}
   */
  public function cssClass() {
    return 'dropbox-chooser';
  }

  /**
   * {@inheritdoc}
   */
  public function attributes($info) {
    // Add the extension list as a data attribute.
    $extensions = array();
    if (isset($info['upload_validators']['file_validate_extensions'][0])) {
      foreach (array_filter(explode(' ', $info['upload_validators']['file_validate_extensions'][0])) as $ext) {
        $extensions[] = '.' . $ext;
      }
    }
    return array(
      'plugin'          => get_class($this),
      'cardinality'     => $info['cardinality'],
      'description'     => strip_tags($info['description']),
      'max-filesize'    => $info['upload_validators']['file_validate_size'][0],
      'multiselect'     => $info['multiselect'],
      'file-extentions' => join(",", $extensions),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function assets() {
    $dropbox_app_key = $this->getSetting('dropbox_app_key');
    $html_element = array(
      '#type' => 'markup',
      '#markup' => '<script type="text/javascript" src="https://www.dropbox.com/static/api/2/dropins.js" id="dropboxjs" data-app-key="' . $dropbox_app_key . '"></script>' . "\r\n",
    );
    drupal_add_html_head($html_element, 'dropbox_dropin');
    drupal_add_js(drupal_get_path('module', 'file_chooser_field') . '/js/file_chooser_field.dropbox.js');
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {

    $form['dropbox_app_key'] = array(
      '#title' => t('Dropbox App Key'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('dropbox_app_key'),
      '#description' => t('Please <a href="https://www.dropbox.com/developers/apps" target="_blank">create a Drop-in app</a> to get the App Key.')
    );

    return $form;

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    $this->setSetting('dropbox_app_key', $form_state['values']['dropbox_app_key']);
  }

  /**
   * {@inheritdoc}
   */
  public function download($destination, $url) {
    return system_retrieve_file($url, $destination);
  }

}
