<?php

/**
 * @file
 * File Chooser Field.
 */

/**
 * Implements hook_field_info_alter().
 */
function file_chooser_field_field_info_alter(&$info) {
  foreach (array('file', 'image') as $type) {
    if (isset($info[$type])) {
      $info[$type]['instance_settings'] += array(
        'file_chooser_field_enabled' => FALSE,
      );
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for field_ui_field_edit_form().
 */
function file_chooser_field_form_field_ui_field_edit_form_alter(&$form, &$form_state, $form_id) {
  if (file_chooser_field_field_widget_support($form['#instance']['widget']['type'])) {
    $settings = $form['#instance']['settings'];

    $additions['file_chooser_field_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable third party file uploads'),
      '#default_value' => $settings['file_chooser_field_enabled'],
      '#description' => t('Enable file uploads from Dropbox, Box, Google Drive'),
      '#prefix' => '<div><strong>' . t('File Chooser Field') . '</strong></div>',
      '#weight' => 100,
    );

    $form['instance']['settings'] += $additions;
  }
}

/**
 * Implements hook_field_widget_form_alter().
 */
function file_chooser_field_field_widget_form_alter(&$element, &$form_state, $context) {
  $instance = $context['instance'];
  if (!empty($instance['settings']['file_chooser_field_enabled']) && file_chooser_field_field_widget_support($instance['widget']['type'])) {
    $keys = element_children($element);
    $delta = end($keys);

    $cardinality = $context['field']['cardinality'];
    $element[$delta]['#file_chooser_field_max_files'] = $cardinality != FIELD_CARDINALITY_UNLIMITED ? $cardinality - $delta : -1;

    $upload_validators = $element[$delta]['#upload_validators'];
    $upload_validators['file_validate_size'] = array(file_chooser_field_max_filesize($instance));
    $element[$delta]['#file_chooser_field_upload_validators'] = $upload_validators;

    $element[$delta]['#process'][] = 'file_chooser_field_field_widget_process';
    $element[$delta]['#file_value_callbacks'][] = 'file_chooser_field_field_widget_value';
  }
}

/**
 * #process callback for the field widget element.
 */
function file_chooser_field_field_widget_process($element, &$form_state, $form) {
  module_load_include('inc', 'file_chooser_field');
  $path = drupal_get_path('module', 'file_chooser_field');
  $max_files = $element['#file_chooser_field_max_files'];

  // Get the upload validators and build a new description.
  $field = field_widget_field($element, $form_state);
  $instance = field_widget_instance($element, $form_state);
  $description = $field['cardinality'] == 1 ? field_filter_xss($instance['description']) : '';
  $upload_validators = $element['#file_chooser_field_upload_validators'];
  $description = theme('file_upload_help', array('description' => $description, 'upload_validators' => $upload_validators));
  $cardinality = $field['cardinality'];
  $multiselect = ($cardinality == FIELD_CARDINALITY_UNLIMITED);

  $chooser = array();

  // Add main JS helper file.
  drupal_add_js($path . '/js/file_chooser_field.js');

  $info = array(
    'cardinality'       => $cardinality,
    'description'       =>  $description,
    'upload_validators' => $upload_validators,
    'multiselect'       => $multiselect,
  );

  $plugins = file_chooser_field_load_plugins();
  foreach ($plugins as $name => $plugin) {
    $status = file_chooser_field_plugin_method($plugin['phpClassName'], 'getStatus');
    if ($status && user_access('upload files from ' . $name)) {
      // Button attributes.
      $attributes = file_chooser_field_plugin_method($plugin['phpClassName'], 'attributes', array($info));
      // Button label.
      $label = file_chooser_field_plugin_method($plugin['phpClassName'], 'label');
      // Button CSS class.
      $cssClass = file_chooser_field_plugin_method($plugin['phpClassName'], 'cssClass');
      // Load all requried assets.
      file_chooser_field_plugin_method($plugin['phpClassName'], 'assets');
      $chooser[] = theme('file_chooser_field', array(
          'label' => $label,
          'class' => $cssClass,
          'attributes' => $attributes,
        )
      );
    }
  }

  $element['file_chooser_field'] = array(
    '#type' => 'hidden',
    '#value_callback' => 'file_chooser_field_value',
    '#field_name' => $element['#field_name'],
    '#field_parents' => $element['#field_parents'],
    '#upload_location' => $element['#upload_location'],
    '#file_chooser_field_upload_validators' => $upload_validators,
    '#prefix' => '<div class="file-chooser-field-wrapper">' . theme('file_chooser_field', array(
        'label' => t('Browse your computer'),
        'class' => 'browse',
        'attributes' => array(),
      ))
      . join(' ', $chooser),
    '#suffix' => '</div>',
    '#attached' => array(
      'css' => array($path . '/css/file_chooser_field.css'),
    ),
  );

  // Add the maximum number of files as a data attribute.
  if ($max_files > -1) {
    $element['file_chooser_field']['#attributes']['data-max-files'] = $max_files;
  }

  $element['upload_button']['#submit'][] = 'file_chooser_field_field_widget_submit';
  $element['#pre_render'][] = 'file_chooser_field_field_widget_pre_render';

  return $element;
}

/**
 * #file_value_callbacks callback for the field widget element.
 */
function file_chooser_field_field_widget_value($element, &$input, $form_state) {
  if (!empty($input['file_chooser_field'])) {
    $file_urls = explode('|', $input['file_chooser_field']);
    $file_url = reset($file_urls);
    if ($file = file_chooser_field_save_upload($element, $file_url)) {
      $input['fid'] = $file->fid;
    }
  }
}

/**
 * #value_callback callback for the file_chooser_field element.
 */
function file_chooser_field_value($element, $input = FALSE, $form_state = array()) {
  $fids = array();
  if ($input) {
    $file_urls = explode('|', $input);
    array_shift($file_urls);
    if (isset($element['#attributes']['data-max-files'])) {
      $file_urls = array_slice($file_urls, 0, max(0, $element['#attributes']['data-max-files'] - 1));
    }
    foreach ($file_urls as $file_url) {
      if ($file = file_chooser_field_save_upload($element, $file_url)) {
        $fids[] = $file->fid;
      }
    }
  }
  return implode(',', $fids);
}

/**
 * #submit callback for the upload button of the field widget element.
 */
function file_chooser_field_field_widget_submit($form, &$form_state) {
  $button = $form_state['triggering_element'];
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -1));
  $field_name = $element['#field_name'];
  $langcode = $element['#language'];
  $parents = $element['#field_parents'];
  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);
  $items = $field_state['items'];

  // Remove possible duplicate items.
  $fids = array();
  foreach ($items as $delta => $item) {
    if (in_array($item['fid'], $fids)) {
      unset($items[$delta]);
    }
    else {
      $fids[] = $item['fid'];
    }
  }
  $items = array_values($items);

  // Append our items.
  if (!empty($element['file_chooser_field']['#value'])) {
    $fids = array_diff(explode(',', $element['file_chooser_field']['#value']), $fids);
    foreach ($fids as $fid) {
      $items[] = array('fid' => $fid);
    }
  }

  drupal_array_set_nested_value($form_state['values'], array_slice($button['#array_parents'], 0, -2), $items);
  $field_state['items'] = $items;
  field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);
}

/**
 * #pre_render callback for the field widget element.
 */
function file_chooser_field_field_widget_pre_render($element) {
  if (!empty($element['#value']['fid'])) {
    $element['file_chooser_field']['#access'] = FALSE;
  }
  return $element;
}

/**
 * Get the file size limit for a field instance.
 */
function file_chooser_field_max_filesize($instance) {
  $max_filesize = file_upload_max_size();

  if (!empty($instance['settings']['max_filesize'])) {
    $size = parse_size($instance['settings']['max_filesize']);
    if ($size < $max_filesize) {
      $max_filesize = $size;
    }
  }

  return $max_filesize;
}

/**
 * Check whether our module has support for a widget type.
 */
function file_chooser_field_field_widget_support($widget_type) {
  return $widget_type == 'file_generic' || $widget_type == 'image_image';
}


/**
 * Get file information and its contents to upload.
 */
function file_chooser_field_file_info($path) {
  $file = pathinfo($path);

  $finfo = @finfo_open(FILEINFO_MIME_TYPE);
  $mimetype = @finfo_file($finfo, $path);
  $contents = file_get_contents($path);

  $info = array(
    'filename'  => $file['basename'],
    'extension' => $file['extension'],
    'mimetype'  => $mimetype,
    'filesize'  => strlen($contents)
  );
  return (object) $info;
}

/**
 * Save a completed upload.
 */
function file_chooser_field_save_upload($element, $file_url) {
  global $user;

  if (empty($file_url)) {
    return FALSE;
  }

  // Ensure the destination is still valid.
  $destination = $element['#upload_location'];
  $destination_scheme = file_uri_scheme($destination);
  if (!$destination_scheme) {
    return FALSE;
  }

  file_prepare_directory($element['#upload_location'], FILE_CREATE_DIRECTORY);

  module_load_include('inc', 'file_chooser_field');

  // Download remote file.
  if (strstr($file_url, '::::')) {
    list($phpClassName, $remote_file) = explode("::::", $file_url);
    $local_file = file_chooser_field_plugin_method($phpClassName, 'download', array($destination, $remote_file));
    // Invoke hook_file_chooser_field_download() when remote file gets downloaded.
    module_invoke_all('file_chooser_field_download', $phpClassName, $remote_file, $local_file);
  }
  else {
    $local_file = system_retrieve_file($file_url, $destination);
  }

  $upload = file_chooser_field_file_info(drupal_realpath($local_file));

  // Begin building the file object.
  $file = new stdClass();
  $file->uid = $user->uid;
  $file->status = 0;
  $file->filename = trim(drupal_basename($upload->filename), '.');
  $file->uri = $local_file;
  $file->filemime = file_get_mimetype($file->filename);
  $file->filesize = $upload->filesize;

  // Support Transliteration.
  if (module_exists('transliteration') && variable_get('transliteration_file_uploads', TRUE)) {
    $orig_filename = $file->filename;
    $file->filename = transliteration_clean_filename($file->filename);
  }

  // Munge the filename.
  $validators = $element['#file_chooser_field_upload_validators'];
  $extensions = '';
  if (isset($validators['file_validate_extensions'])) {
    if (isset($validators['file_validate_extensions'][0])) {
      $extensions = $validators['file_validate_extensions'][0];
    }
    else {
      unset($validators['file_validate_extensions']);
    }
  }
  else {
    $extensions = 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp';
    $validators['file_validate_extensions'][] = $extensions;
  }
  if (!empty($extensions)) {
    $file->filename = file_munge_filename($file->filename, $extensions);
  }

  // Rename potentially executable files.
  if (!variable_get('allow_insecure_uploads', 0) && preg_match('/\.(php|pl|py|cgi|asp|js)(\.|$)/i', $file->filename) && (substr($file->filename, -4) != '.txt')) {
    $file->filemime = 'text/plain';
    $file->uri .= '.txt';
    $file->filename .= '.txt';
    if (!empty($extensions)) {
      $validators['file_validate_extensions'][0] .= ' txt';
      drupal_set_message(t('For security reasons, your upload has been renamed to %filename.', array('%filename' => $file->filename)));
    }
  }

  // Get the upload element name.
  $element_parents = $element['#parents'];
  if (end($element_parents) == 'file_chooser_field') {
    unset($element_parents[key($element_parents)]);
  }
  $form_field_name = implode('_', $element_parents);

  // Run validators.
  $validators['file_validate_name_length'] = array();
  $errors = file_validate($file, $validators);
  if ($errors) {
    $message = t('The specified file %name could not be uploaded.', array('%name' => $file->filename));
    if (count($errors) > 1) {
      $message .= theme('item_list', array('items' => $errors));
    }
    else {
      $message .= ' ' . array_pop($errors);
    }
    form_set_error($form_field_name, $message);
    return FALSE;
  }

  // Prepare the destination directory.
  if (!file_prepare_directory($destination, FILE_CREATE_DIRECTORY)) {
    watchdog('file_chooser_field', 'The upload directory %directory for the file field !name could not be created or is not accessible. A newly uploaded file could not be saved in this directory as a consequence, and the upload was canceled.', array('%directory' => $destination, '!name' => $element['#field_name']));
    form_set_error($form_field_name, t('The file could not be uploaded.'));
    return FALSE;
  }

  // Complete the destination.
  if (substr($destination, -1) != '/') {
    $destination .= '/';
  }
  $destination = file_destination($destination . $file->filename, FILE_EXISTS_RENAME);

  // Move the uploaded file.
  $file->uri = $destination;
  if (!rename($local_file, $file->uri)) {
    form_set_error($form_field_name, t('File upload error. Could not move uploaded file.'));
    watchdog('file_chooser_field', 'Upload error. Could not move uploaded file %file to destination %destination.', array('%file' => $file->filename, '%destination' => $file->uri));
    return FALSE;
  }

  // Set the permissions on the new file.
  drupal_chmod($file->uri);

  // Transliteration support: restore the original filename if configured so.
  if (isset($orig_filename) && !variable_get('transliteration_file_uploads_display_name', TRUE)) {
    $file->filename = $orig_filename;
  }

  // Save the file object to the database.
  $file = file_save($file);
  if (!$file) {
    return FALSE;
  }

  return $file;
}
