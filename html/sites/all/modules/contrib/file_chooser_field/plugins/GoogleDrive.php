<?php

/**
 * @file
 * File Chooser Field Plugins class
 */

/**
 * Google Picker API integration class.
 */
class GooglePickerAPI extends FileChooserFieldPlugin {

  /**
   * {@inheritdoc}
   */
  public function label() {
    return t('Google Drive');
  }

  /**
   * {@inheritdoc}
   */
  public function cssClass() {
    return 'google-picker';
  }

  /**
   * {@inheritdoc}
   */
  public function attributes($info) {

    $extensions = array();
    if (isset($info['upload_validators']['file_validate_extensions'][0])) {
      foreach (array_filter(explode(' ', $info['upload_validators']['file_validate_extensions'][0])) as $ext) {
        $mime = file_chooser_field_mime_by_extension($ext);
        if (is_array($mime)) {
          foreach ($mime as $mime_item) {
            $extensions[] = $mime_item;
          }
        }
        else {
          $extensions[] = $mime;
        }
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
    $google_scope = $this->getSetting('google_scope', 'https://www.googleapis.com/auth/photos');
    drupal_add_js(
      array(
        'file_chooser_field' => array(
          'google_client_id' => $this->getSetting('google_client_id'),
          'google_app_id'    => $this->getSetting('google_app_id'),
          'google_scope'     => explode("\n", $google_scope),
        )
      ),
      'setting'
    );
    drupal_add_js('https://apis.google.com/js/api.js', array('external' => TRUE, 'scope' => 'footer'));
    drupal_add_js(drupal_get_path('module', 'file_chooser_field') . '/js/file_chooser_field.google.js', array('scope' => 'footer'));
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {

    $form['google_client_id'] = array(
      '#title' => t('Client ID'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('google_client_id'),
      '#description' => t('The Client ID obtained from the Google Developers Console. e.g. <em>886162316824-pfrtpjns2mqnek6e35gv321tggtmp8vq.apps.googleusercontent.com</em>')
    );

    $form['google_app_id'] = array(
      '#title' => t('Application ID'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('google_app_id'),
      '#description' => t('Its the first number in your Client ID. e.g. <em>886162316824</em>')
    );

    $form['google_scope'] = array(
      '#title' => t('Scope'),
      '#type' => 'textarea',
      '#default_value' => $this->getSetting('google_scope', 'https://www.googleapis.com/auth/photos'),
      '#description' => t('Scope to use to access user\'s Drive items. Please put each scope in it is own line. <a href="https://developers.google.com/picker/docs/#otherviews" target="_blank">See available scopes</a>.')
    );

    $form['google_instructions'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configuration instructions'),
    );

    $form['google_instructions']['info'] = array(
      '#markup' => '<p>To get started using Google Picker API, you need to first '
        . '<a href="https://console.developers.google.com/flows/enableapi?apiid=picker" target="_blank">'
        . 'create or select a project in the Google Developers Console and enable the API</a>.</p>'
        . '<ul><li>Enable <strong>Google Picker API</strong> <em>(required)</em></li>'
        . '<li>Enable <strong>Drive API</strong> <em>(required)</em></li></ul>'
        . '<p>Read more about <em>Scopes</em> and more details about how to get credentials on the '
        . '<a href="https://developers.google.com/picker/docs/" target="_blank">documentaion page</a>.',
    );

    return $form;

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($config, &$form_state) {
    $this->setSetting('google_client_id', $form_state['values']['google_client_id']);
    $this->setSetting('google_app_id', $form_state['values']['google_app_id']);
    $this->setSetting('google_scope', $form_state['values']['google_scope']);
  }

  /**
   * {@inheritdoc}
   */
  public function download($destination, $url) {
    $local_file = '';
    list($id, $orignal_name, $google_token) = explode('@@@', $url);
    $remote_url = 'https://www.googleapis.com/drive/v2/files/' . $id . '?alt=media';
    $options = array(
      'headers' => array(
        'Authorization' => 'Bearer ' . $google_token,
      ),
    );
    $request = drupal_http_request($remote_url, $options);
    if ($request->code == 200) {
      $local_file = file_unmanaged_save_data($request->data, $destination . '/' . $orignal_name);
    }
    return $local_file;
  }

  /**
   * {@inheritdoc}
   */
  public function redirectCallback() {
    $this->assets();
    return ' ';
  }

}
