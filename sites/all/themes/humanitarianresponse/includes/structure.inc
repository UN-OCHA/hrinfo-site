<?php
/**
 * @file
 * Theme and preprocess functions for breadcrumbs, messages, tabs..etc
 */

function _humanitarianresponse_get_file_properties($item) {
  $return = array();
  if (isset($item['field_file'])) {
    $file = $item['field_file']['#items'][0];
    $language = isset($item['field_language']) ? $item['field_language']['#items'][0] : NULL;
    $return['path'] = file_create_url($file['uri']);
    $return['title'] = empty($file['title']) ? $file['filename'] : $file['title'];
    $return['language'] = !empty($language) ? '(' . $language['name_native'] . ')' : '';
    $return['options'] =  array('attributes' => array('target'=>'_blank'));
  }
  return $return;
}

/**
 * Implements theme_field()
 */
function humanitarianresponse_field__field_files_collection($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  if ($variables['element']['#field_type'] == 'field_collection' && $variables['element']['#view_mode'] == '_custom_display') {
      $output .= '<div class="btn-group">';
      $output .= '<button type="button" class="btn btn-primary btn-sm dropdown-toggle" data-toggle="dropdown">
        <i class="fa fa-download"></i> download <span class="caret"></span>
      </button>';
      $output .= '<ul class="dropdown-menu">';
      foreach ($variables['items'] as $delta => $item) {
        $id = $variables['element']['#items'][$delta]['value'];
        $props = _humanitarianresponse_get_file_properties($item['entity']['field_collection_item'][$id]);
        if (!empty($props)) {
          $output .= '<li>'.l($props['title'].' '.$props['language'], $props['path'],array('attributes' => array('target'=>'_blank'))).'</li>';
        }
      }
      $output .= '</ul>';
      $output .= '</div>';
  }
  else {
    foreach ($variables['items'] as $delta => $item) {
      $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
    }
  }

  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Implements theme_views_view_field
 */
function humanitarianresponse_views_view_field__hr_documents__table__field_files_collection($variables) {
  $output = '';
  try {
    $doc = entity_metadata_wrapper('node', $variables['row']->_entity_properties['entity object']);
      $output .= '<div class="btn-group">';
      $output .= '<button type="button" class="btn btn-primary btn-sm dropdown-toggle" data-toggle="dropdown">
        download <span class="caret"></span>
      </button>';
      $output .= '<ul class="dropdown-menu">';
      foreach ($doc->field_files_collection as $fc_collection) {
        $file_url = $fc_collection->field_file->file->url->value();
        $file_title = $fc_collection->field_file->file->name->value();
        $file_language = $fc_collection->field_language->value();
        $file_language = empty($file_language['name_native']) ? '' : '('.$file_language['name_native'].')';
        $output .= '<li>'.l($file_title.' '.$file_language, $file_url).'</li>';
      }
      $output .= '</ul>';
      $output .= '</div>';
  }
  catch (Exception $e) {
  }
  return $output;
}

function humanitarianresponse_views_view_field__hr_documents__global_table__field_files_collection($variables) {
  return humanitarianresponse_views_view_field__hr_documents__table__field_files_collection($variables);
}

function humanitarianresponse_views_view_field__hr_infographics__table__field_files_collection($variables) {
  return humanitarianresponse_views_view_field__hr_documents__table__field_files_collection($variables);
}

function humanitarianresponse_views_view_field__hr_infographics__global_table__field_files_collection($variables) {
  return humanitarianresponse_views_view_field__hr_documents__table__field_files_collection($variables);
}

/**
 * Theme function for link with icon.
 */
function humanitarianresponse_link_icons_link($vars) {
  $link_options = array(
    'html' => TRUE,
    'attributes' => array('title' => $vars['item']['title']),
  );

  return l('<i class="' . link_icons_get_icon($vars['item']['url']) . ' fa-2x"></i>', $vars['item']['url'], $link_options);
}

