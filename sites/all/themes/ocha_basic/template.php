<?php

/**
 * @file
 * Template overrides, preprocess, and alter hooks for the OCHA Basic theme.
 */

require_once dirname(__FILE__) . '/includes/structure.inc';
require_once dirname(__FILE__) . '/includes/menu.inc';
require_once dirname(__FILE__) . '/includes/node.inc';
require_once dirname(__FILE__) . '/includes/panel.inc';
require_once dirname(__FILE__) . '/includes/user.inc';
require_once dirname(__FILE__) . '/includes/view.inc';

/**
 * Implements hook_form_alter().
 */
function ocha_basic_form_alter(&$form, &$form_state, $form_id) {

  // This is for Drupal core search block.
  if ($form_id == 'search_block_form') {
    $form['#attributes']['role'] = 'search';
    $form['#attributes']['class'][] = 'cd-search__form';
    $form['#attributes']['aria-labelledby'][] = 'cd-search-btn';
    $form['search_block_form']['#attributes']['placeholder'] = t('What are you looking for?');
    $form['search_block_form']['#attributes']['autocomplete'][] = 'off';
    $form['search_block_form']['#attributes']['class'][] = 'cd-search__input';
    $form['search_block_form']['#attributes']['id'][] = 'cd-search';
    $form['actions']['submit'] = [
      '#type' => 'submit',
      '#prefix' => '<button type="submit" name="op" class="cd-search__submit form-submit"><svg class="icon icon--search"><use xlink:href="#search"></use></svg><span class="element-invisible">Search</span>',
      '#suffix' => '</button>',
      '#markup' => '',
      '#weight' => 1000,
    ];
    $form['actions']['submit']['#attributes']['class'][] = 'element-invisible';
  }

  // This is for a Views exposed form search block.
  if ($form_id == 'views_exposed_form') {
    $form['#attributes']['role'] = 'search';
    $form['#attributes']['class'][] = 'cd-search--inline__form';
    $form['#attributes']['aria-labelledby'][] = 'cd-search-btn';
    $form['#info']['filter-search_api_views_fulltext']['label'] = t('What are you looking for?');
  }
}

/**
 * Implements hook_preprocess_search_block_form().
 */
function ocha_basic_preprocess_search_block_form(&$vars) {
  $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}

/**
 * Implements hook_preprocess_html().
 */
function ocha_basic_preprocess_html(&$vars) {
  $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );

  $apple = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/apple-touch-icon.png',
      'rel' => 'apple-touch-icon',
      'sizes' => '180x180',
    ),
  );

  $fav_32 = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/favicon-32x32.png',
      'rel' => 'icon',
      'sizes' => '32x32',
      'type' => 'image/png',
    ),
  );

  $fav_16 = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/favicon-16x16.png',
      'rel' => 'icon',
      'sizes' => '16x16',
      'type' => 'image/png',
    ),
  );

  $safari_pinned_tab = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => base_path() . path_to_theme() . '/img/safari-pinned-tab.svg',
      'rel' => 'mask-icon',
      'color' => '#5bbad5',
    ),
  );

  drupal_add_html_head($viewport, 'viewport');
  drupal_add_html_head($apple, 'apple-touch-icon');
  drupal_add_html_head($fav_32, 'favicon-32x32');
  drupal_add_html_head($fav_16, 'favicon-16x16');
  drupal_add_html_head($safari_pinned_tab, 'safari_pinned_tab');

  if ($node = menu_get_object()) {
    if (og_is_group('node', $node->nid)) {
      $variables['classes_array'][] = 'hr-group-context';
    }
  }
}
/**
 * Implements template_preprocess_page().
 */
function ocha_basic_preprocess_page(&$vars) {
  // Bail out if function is not available.
  if (!function_exists('language_negotiation_get_switch_links')) {
    return;
  }

  // Add language links.
  global $language;
  $path = drupal_is_front_page() ? '<front>' : $_GET['q'];
  $links = language_negotiation_get_switch_links('language', $path);

  // Bail out if links is not enumerable.
  if (!$links) {
    return;
  }

  $render = array(
    'links' => $links->links,
    'attributes' => array(
      'class' => [
        'cd-global-header__dropdown',
        'cd-dropdown',
        'cd-user-menu__dropdown',
      ],
      'role' => 'menu',
      'id' => 'cd-language',
      'aria-labelledby' => 'cd-language-toggle',
    ),
  );

  $output = '';
  $output .= '<div class="cd-language-switcher">';
  $output .= '<button type="button" class="cd-user-menu__item cd-user-menu__item--small cd-global-header__dropdown-btn" data-toggle="dropdown" id="cd-language-toggle">';
  $output .= $language->language;
  $output .= '<svg class="icon icon--arrow-down"><use xlink:href="#arrow-down"></use></svg>';
  $output .= '</button>';
  $output .= theme('links__locale_block', $render);
  $output .= '</div>';

  $vars['page']['language_switcher'] = $output;


  global $theme_path;

  $variables['hr_tabs'] = array();
  $header_img_path = $theme_path.'/img/headers/general.png';
  if (module_exists('og_context')) {
    $gid = og_context_determine_context('node');
    if (!empty($gid)) {
      $og_group = entity_load('node', array($gid));
      $og_group = $og_group[$gid];
      if ($og_group->type == 'hr_operation') {
        // Salahumanitaria logo
        if ($og_group->nid == 77) { // Nid of the Colombia operation
          $variables['logo'] = '/sites/all/themes/ocha_basic/img/logos/salahumanitaria_logo.png';
        }
        if (!empty($og_group->field_operation_type) && !empty($og_group->field_operation_region) && $og_group->field_operation_type[LANGUAGE_NONE][0]['value'] == 'country') {
          // Determine the region of the operation
          $region_id = $og_group->field_operation_region[LANGUAGE_NONE][0]['target_id'];
          $region = entity_load_single('node', $region_id);
          $region_uri = entity_uri('node', $region);
          $region_status = $region->field_operation_status[LANGUAGE_NONE][0]['value'];
          switch ($region_status) {
            case 'active':
              // Add the region to the tabs
              $variables['hr_tabs'][] = l($region->title, $region_uri['path'], $region_uri['options']);
              break;
            case 'inactive':
              break;
            case 'archived':
              break;
          }
        }
      }
      elseif ($og_group->type == 'hr_disaster') {
        $glide = $og_group->field_glide_number[LANGUAGE_NONE][0]['value'];
        if ($glide == 'EP-2014-000041-GIN') {
          $variables['logo'] = '/sites/all/themes/ocha_basic/img/logos/unmeer_logo.png';
        }
      }
      elseif ($og_group->type == 'hr_bundle') {
        // Get operation from bundle
        $op_gid = _hr_bundles_get_operation($og_group->nid);
        if (!empty($op_gid)) {
          $operation = entity_load_single('node', $op_gid);
          $op_uri = entity_uri('node', $operation);
          $variables['hr_tabs'][] = l($operation->title, $op_uri['path'], $op_uri['options']);
        }
      }
      $uri = entity_uri('node', $og_group);
      if ($og_group->status) { // Group is published
        $variables['hr_tabs'][] = l($og_group->title, $uri['path'], $uri['options']);
      }
      else {
        $variables['hr_tabs'][] = '<a href="#">'.$og_group->title.'</a>';
      }
      $group_img_path = '/img/headers/'.$og_group->type.'/'.strtolower(str_replace(array(' ','/'), '-', $og_group->title)).'.png';
      if (file_exists(dirname(__FILE__).$group_img_path)) {
        $header_img_path = $theme_path.$group_img_path;
      }
    }
  }

  $variables['og_group_header_image'] = theme('image', array(
    'path' => $header_img_path,
    'alt' => 'Header image',
  ));

  $variables['hr_favorite_spaces'] = _ocha_basic_block_render('hr_bookmarks', 'hr_favorite_spaces');

  // Bootstrap CDN.
  drupal_add_js('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js', 'external');

  drupal_add_css('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css', 'external');
}

/**
 * Implements hook_pwa_manifest_alter().
 */
function ocha_basic_pwa_manifest_alter(&$manifest) {
  // Hard-code a theme-color into the manifest.
  $manifest['theme_color'] = '#026CB6';

  // Override the PWA default icons with OCHA defaults.
  //
  // If you are using this theme as a starterkit feel free to manually adjust
  // this code block, otherwise copy this hook into your subtheme and customize
  // to your heart's content.
  $manifest['icons'] = [
    [
      'src' => url(drupal_get_path('theme', 'ocha_basic') . '/img/android-chrome-512x512.png'),
      'sizes' => '512x512',
      'type' => 'image/png',
    ],
    [
      'src' => url(drupal_get_path('theme', 'ocha_basic') . '/img/android-chrome-192x192.png'),
      'sizes' => '192x192',
      'type' => 'image/png',
    ],
  ];
}

// Bootstrap Dropdown menu.
// from https://github.com/drupalprojects/bootstrap/blob/7.x-3.x/templates/menu/menu-link.func.php.
// See https://www.drupalgeeks.com/drupal-blog/how-render-bootstrap-sub-menus for second level dropdown.
function ocha_basic_menu_link__main_menu(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $options = !empty($element['#localized_options']) ? $element['#localized_options'] : array();
  // Check plain title if "html" is not set, otherwise, filter for XSS attacks.
  $title = empty($options['html']) ? check_plain($element['#title']) : filter_xss_admin($element['#title']);
  // Ensure "html" is now enabled so l() doesn't double encode. This is now
  // safe to do since both check_plain() and filter_xss_admin() encode HTML
  // entities. See: https://www.drupal.org/node/2854978
  $options['html'] = TRUE;
  $href = $element['#href'];
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : array();
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $title .= '<svg class="icon icon--arrow-down"><use xlink:href="#arrow-down"></use></svg>';
      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $options['attributes']['data-target'] = '#';
      $options['attributes']['data-toggle'] = 'dropdown';
      $options['attributes']['aria-expanded'] = 'false';
      $options['attributes']['aria-haspopup'] = 'true';
    }
  }

  return '<li' . drupal_attributes($attributes) . '>' . l($title, $href, $options) . $sub_menu . "</li>\n";
}


function ocha_basic_menu_tree__user_menu(&$variables) {
  global $user;
  $before = '<button type="button" class="cd-user-menu__item cd-global-header__dropdown-btn" data-toggle="dropdown"><svg class="icon icon--user"><use xlink:href="#user"></use></svg><span class="cd-user-menu__label">';
  $before .= check_plain(format_username($user));
  $before .= '</span><svg class="icon icon--arrow-down"><use xlink:href="#arrow-down"></use></svg></button><ul class="cd-global-header__dropdown cd-dropdown cd-user-menu__dropdown" role="menu">';
  $after = '</ul>';
  return $before.$variables['tree'].$after;
}


/**
 * Custom function to render a block so I can manually position it in the markup
 */
function _ocha_basic_block_render($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);
  return $block_rendered;
}

/**
 * Implements hook_preprocess_fieldable_panels_pane()
 * Fixes title appearing 2 times in fieldable panels panes
 */
function ocha_basic_preprocess_fieldable_panels_pane(&$variables) {
  if (isset($variables['content']['title'])) {
    unset($variables['content']['title']);
  }
}
