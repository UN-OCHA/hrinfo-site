<?php
/**
 * @file
 * Theme and preprocess functions for breadcrumbs, messages, tabs..etc
 */

/**
 * Implements theme_views_view_field
 */
function ocha_basic_views_view_field__hr_documents__table__field_files_collection($variables) {
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

function ocha_basic_views_view_field__hr_documents__global_table__field_files_collection($variables) {
  return ocha_basic_views_view_field__hr_documents__table__field_files_collection($variables);
}

function ocha_basic_views_view_field__hr_infographics__table__field_files_collection($variables) {
  return ocha_basic_views_view_field__hr_documents__table__field_files_collection($variables);
}

function ocha_basic_views_view_field__hr_infographics__global_table__field_files_collection($variables) {
  return ocha_basic_views_view_field__hr_documents__table__field_files_collection($variables);
}

/**
 * Theme function for link with icon.
 */
function ocha_basic_link_icons_link($vars) {
  $link_options = array(
    'html' => TRUE,
    'attributes' => array('title' => $vars['item']['title']),
  );

  return l('<i class="' . link_icons_get_icon($vars['item']['url']) . ' fa-2x"></i>', $vars['item']['url'], $link_options);
}


/**
 * Implements theme_pager().
 */
function ocha_basic_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current', 'active'),
            'data' => '<span>' . $i . '</span>',
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<div class="text-center">' . theme('item_list', array(
        'items' => $items,
        'attributes' => array('class' => array('pagination', 'pager')),
      )) . '</div>';
  }
}
