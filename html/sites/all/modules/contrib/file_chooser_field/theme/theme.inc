<?php

/**
 * @file
 * Theme preprocess functions for the File Chooser Field module.
 */

/**
 * Preprocess function for the file-chooser-field.tpl.php.
 */
function file_chooser_field_preprocess_file_chooser_field(&$vars) {

  $vars['attributes_array'] = array();
  $vars['title_attributes_array'] = array();
  $vars['content_attributes_array'] = array();
  $vars['classes_array'] = array('');

  $data_attributes = array();

  if (count($vars['attributes'])) {
    foreach ($vars['attributes'] as $data => $value) {
      $data_attributes[] = ' data-' . $data . '="' . $value . '"';
    }
  }

  $vars['data_attributes'] = join(" ", $data_attributes);

}
