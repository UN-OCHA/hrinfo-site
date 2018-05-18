<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\Field\ResourceFieldEntityText.Custom
 */

namespace Drupal\hr_api\Plugin\resource\Field;

use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;
use Drupal\restful\Plugin\resource\Field\ResourceFieldEntityText;
use Drupal\restful\Plugin\resource\Field\ResourceFieldEntityInterface;

class ResourceFieldEntityTextCustom extends ResourceFieldEntityText implements ResourceFieldEntityInterface {

  /**
   * {@inheritdoc}
   */
  public function preprocess($value) {
    // Text field. Check if field has an input format.

    $field_info = field_info_field($this->getProperty());
    // If there was no bundle that had the field instance, then return NULL.
    if (!$instance = field_info_instance($this->getEntityType(), $this->getProperty(), $this->getBundle())) {
      return NULL;
    }

    $return = NULL;
    if ($field_info['cardinality'] == 1) {
      // Single value.
      if (!$instance['settings']['text_processing']) {
        return $value;
      }

      return array(
        'value' => $value,
        // TODO: This is hardcoded! Fix it.
        'format' => 'full_html',
      );
    }

    // Multiple values.
    foreach ($value as $delta => $single_value) {
      if (!$instance['settings']['text_processing']) {
        $return[$delta] = $single_value;
      }
      else {
        $return[$delta] = array(
          'value' => $single_value,
          'format' => 'filtered_html',
        );
      }
    }
    return $return;
  }

}
