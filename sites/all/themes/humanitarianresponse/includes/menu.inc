<?php
/**
 * @file
 * Theme and preprocess functions for menus
 */

function _humanitarianresponse_menu_main_menu(&$variables) {
  return '<nav class="navbar navbar-default" role="navigation">
        <!-- Brand and toggle get grouped for better mobile display -->
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
            <span class="sr-only">'.t("Toggle navigation").'</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div> <!-- /.navbar-header -->

        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse" id="navbar-collapse">
          <ul class="menu nav nav-pills">'.$variables["tree"].'</ul>
        </div><!-- /.navbar-collapse -->
      </nav>';
}

/**
 * Implements theme_menu_tree().
 */
function humanitarianresponse_menu_tree__main_menu(&$variables) {
  return _humanitarianresponse_menu_main_menu($variables);
}

function humanitarianresponse_menu_tree__user_menu(&$variables) {
  global $user;
  $before = '<div class="btn-group">
  <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">';
  $before .= check_plain(format_username($user));
  $before .= ' <span class="caret"></span>
  </button>
  <ul class="dropdown-menu" role="menu">';
  $after = '</ul>
    </div>';
  return $before.$variables['tree'].$after;
} 

/**
 * Implements theme_menu_tree__menu_block().
 */
function humanitarianresponse_menu_tree__menu_block(&$variables) {
  return '<ul class="menu nav nav-pills">' . $variables['tree'] . '</ul>';
}

function humanitarianresponse_menu_tree__og_menu_single(&$variables) {
  return _humanitarianresponse_menu_main_menu($variables);
}

function humanitarianresponse_links__locale_block(&$variables) {
  global $language;
  unset($variables['links'][$language->language]);
  $before = '<div class="btn-group">
  <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">';
  $before .= strtoupper($language->language).' <span class="caret"></span>
  </button>
  <ul class="dropdown-menu" role="menu">';
  $after = '</ul>
    </div>';

  foreach ($variables['links'] as &$link) {
    $link['title'] = strtoupper($link['language']->language);
  }

  return $before.theme_links($variables).$after;
}

/**
 * Implements theme_menu_link().
 */
function humanitarianresponse_menu_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if (!empty($element['#below'])) {
    // Wrap in dropdown-menu.
    unset($element['#below']['#theme_wrappers']);
    $item_id = humanitarianresponse_menu_unique_id();
    $sub_menu = '<ul class="collapse in" id="'.$item_id.'">' . drupal_render($element['#below']) . '</ul>';
    //$element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
    //$element['#localized_options']['attributes']['data-toggle'] = 'dropdown';

    // Check if element is nested.
    if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
      $element['#attributes']['class'][] = 'dropdown-submenu';
    }
    else {
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;
      $element['#title'] .= '<span class="caret"></span>';
    }

    $element['#localized_options']['attributes']['data-target'] = '#'.$item_id;
    $element['#localized_options']['attributes']['data-toggle'] = 'collapse';
  }

  // Fix for active class.
  if (($element['#href'] == current_path() || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']) || $element['#localized_options']['language']->language == $language_url->language)) {
    $element['#attributes']['class'][] = 'active';
  }

  // Add active class to li if active trail.
  if (in_array('active-trail', $element['#attributes']['class'])) {
    $element['#attributes']['class'][] = 'active';
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function humanitarianresponse_menu_unique_id() {
  static $item_id = 0;
  $item_id += 1;
  return 'hr-menu-item-custom-id-' . $item_id;
}  

/**
 * Implements theme_menu_link().
 */
function humanitarianresponse_menu_link__main_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if (!empty($element['#below'])) {
    // Wrap in dropdown-menu.
    unset($element['#below']['#theme_wrappers']);
    $sub_menu = '<ul class="nav nav-pills">' . drupal_render($element['#below']) . '</ul>';
    //$element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
    //$element['#localized_options']['attributes']['data-toggle'] = 'dropdown';

    // Check if element is nested.
    if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
      $element['#attributes']['class'][] = 'dropdown-submenu';
    }

    $element['#localized_options']['attributes']['data-target'] = '#';
  }

  // Fix for active class.
  if (($element['#href'] == current_path() || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']) || $element['#localized_options']['language']->language == $language_url->language)) {
    $element['#attributes']['class'][] = 'active';
  }

  // Add active class to li if active trail.
  if (in_array('active-trail', $element['#attributes']['class'])) {
    $element['#attributes']['class'][] = 'active';
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

