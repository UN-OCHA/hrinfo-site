<?php
/**
 * @file
 * Theme and preprocess functions for breadcrumbs, messages, tabs..etc
 */

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

