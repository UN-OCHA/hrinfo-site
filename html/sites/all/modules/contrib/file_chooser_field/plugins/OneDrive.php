<?php

/**
 * @file
 * File Chooser Field Plugins class
 */

/**
 * The OneDrive API integration class.
 */
class OneDriveAPI extends FileChooserFieldPlugin {

  /**
   * {@inheritdoc}
   */
  public function label() {
    return t('OneDrive');
  }

  /**
   * {@inheritdoc}
   */
  public function cssClass() {
    return 'one-drive-picker';
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
    $onedrive_app_id = $this->getSetting('onedrive_app_id');
    $html_element = array(
      '#type' => 'markup',
      '#markup' => '<script type="text/javascript" src="https://js.live.net/v5.0/OneDrive.js" id="onedrive-js" client-id="' . $onedrive_app_id . '"></script>' . "\r\n",
    );
    drupal_add_html_head($html_element, 'onedrive_web_picker');
    drupal_add_js(drupal_get_path('module', 'file_chooser_field') . '/js/file_chooser_field.onedrive.js');
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {

    $form['warning'] = array(
      '#markup' => '<div><p>' . t('<strong>Warning:</strong> OneDrive button doesn\'t always trigger the popup. You have to keep pressing the button until the popup shows up. '
        . 'It behaves the same even on the MS\'s website. See <a href="https://dev.onedrive.com/sdk/javascript-picker-saver.htm" target="_blank">https://dev.onedrive.com/sdk/javascript-picker-saver.htm</a> '
        . 'It might start working well once they fixe the issue.'
        ) . '</p></div><hr/><br/>',
      '#weight' => -10,
    );

    $form['onedrive_app_id'] = array(
      '#title' => t('OneDrive App ID/Client ID'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('onedrive_app_id'),
      '#description' => t('Please <a href="https://account.live.com/developers/applications" target="_blank">Register your app</a> to get an app ID (client ID), if you haven\'t already done so. '
        . 'Ensure that the web page that is going to reference the SDK is a <em>Redirect URL</em> under <strong>Application Settings</strong>.'
      )
    );

    $form['onedrive_instructions'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configuration instructions'),
    );

    $form['onedrive_instructions']['info'] = array(
      '#markup' => '<p>Most people have problems with properly configuring the OneDrive app.'
        . ' First of all make sure you <a href="https://account.live.com/developers/applications" target="_blank">register your app</a>.'
        . ' Set <strong>Mobile or desktop client app</strong> to <strong>No</strong>. Leave Target domain empty.'
        . ' Set <strong>Restrict JWT issuing</strong> to <strong>Yes</strong>.'
        . ' No goes the tricky part - You have to add your node/add/edit page paths as <strong>Redirect URLs</strong>.'
        . ' For instance: http://example.com/node/add/article, http://example.com/node/add/page. <br/><strong>However</strong>'
        . ' the plugin won\'t work on node edit pages. I <a href="http://stackoverflow.com/a/32492185/258899" target="_blank"> told the lead developer of the plugin about this problem</a>, let\'s see what he says.</p>',
    );

    return $form;

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    $this->setSetting('onedrive_app_id', $form_state['values']['onedrive_app_id']);
  }

  /**
   * {@inheritdoc}
   */
  public function download($destination, $url) {
    $local_file = '';
    list($file_url, $orignal_name) = explode('@@@', $url);
    $local_file = system_retrieve_file($file_url, $destination . '/' . $orignal_name);
    return $local_file;
  }

}
