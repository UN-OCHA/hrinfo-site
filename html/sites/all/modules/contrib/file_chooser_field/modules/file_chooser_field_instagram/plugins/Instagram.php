<?php

/**
 * @file
 * File Chooser Field Instagram class
 */

/**
 * File Chooser Field plugin example.
 */
class InstagramPhotoPicker extends FileChooserFieldPlugin {

  /**
   * {@inheritdoc}
   */
  public function label() {
    return t('Instagram');
  }

  /**
   * {@inheritdoc}
   */
  public function cssClass() {
    return 'instagram-picker';
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
    drupal_add_js(drupal_get_path('module', 'file_chooser_field_instagram') . '/js/file_chooser_field.instagram.js');
    drupal_add_js(
      array(
        'file_chooser_field_instagram' => array(
          'loginUrl' => $this->getLoginUrl(),
        )
      ),
      'setting'
    );
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {

    $form['warning'] = array(
      '#markup' => '<div><p>' . t('<strong>Note:</strong> Please note you might need to re-open Instagram file picker popup after you first time login.')
        . '<br/>' . t('Please also note that users only can chooser their own photos.') . '</p></div><hr/><br/>',
      '#weight' => -10,
    );

    $form['instagram_client_id'] = array(
      '#title' => t('Client ID'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('instagram_client_id'),
      '#description' => t('Instagram Client ID. <a href="https://instagram.com/developer/clients/manage/" target="_blank">Set up a client for use with Instagram\'s API</a>'),
    );

    $form['instagram_client_secret'] = array(
      '#title' => t('Client Secret'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('instagram_client_secret'),
      '#description' => t('Instagram Client Secret.'),
    );

    $form['instagram_redirect_uri'] = array(
      '#title' => t('Redirect URI'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('instagram_redirect_uri',
        url('redirectCallback/InstagramPhotoPicker',
          array('absolute' => TRUE)
        )
      ),
      '#description' => t('Please use values of the <em>Redirect URL</em> address. If you need to pass more parameters,
        read about it <a href="https://instagram.com/developer/authentication/" target="_blank">here</a>.'),
    );

    return $form;

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    $this->setSetting('instagram_client_id', $form_state['values']['instagram_client_id']);
    $this->setSetting('instagram_client_secret', $form_state['values']['instagram_client_secret']);
    $this->setSetting('instagram_redirect_uri', $form_state['values']['instagram_redirect_uri']);
  }

  /**
   * {@inheritdoc}
   */
  public function download($destination, $url) {
    return system_retrieve_file($url, $destination);
  }

  /**
   * Get Instagram login URL.
   */
  private function getLoginUrl() {
    return 'https://api.instagram.com/oauth/authorize/?'
      . 'client_id=' . $this->getSetting('instagram_client_id')
      . '&redirect_uri=' . $this->getSetting('instagram_redirect_uri')
      . '&response_type=code';
  }

  /**
   * {@inheritdoc}
   */
  public function redirectCallback() {
    $code = isset($_GET['code']) ? $_GET['code'] : FALSE;
    $error = isset($_GET['error']) ? $_GET['error'] : FALSE;
    if ($code) {
      // Get OAuth token.
      $options = array(
        'data' => 
          'client_id=' . $this->getSetting('instagram_client_id')
          . '&client_secret=' . $this->getSetting('instagram_client_secret')
          . '&grant_type=authorization_code'
          . '&redirect_uri=' . $this->getSetting('instagram_redirect_uri')
          . '&code=' . $code,
        'method' => 'POST',
      );
      $request = drupal_http_request('https://api.instagram.com/oauth/access_token', $options);
      if ($request->code == 200) {
        $info = drupal_json_decode($request->data);
        // Redirect to photos w/ access token in the URL.
        drupal_goto('file-chooser-field-instagram/photos', array('query' => array('access_token' => $info['access_token'])));
      }
      drupal_exit();
    }
    if ($error) {
      print isset($_GET['error_reason']) ? filter_xss($_GET['error_reason'] . ': ' . $_GET['error_description']) : '';
      drupal_exit();
    }
  }

}
