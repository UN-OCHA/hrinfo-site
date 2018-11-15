<?php

/**
 * @file
 * Template overrides, preprocess, and alter hooks for the OCHA Basic theme.
 */

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


  // Set variable based on path alias to include inline-search.
  $path = drupal_get_path_alias();
  if ($path == 'inline-search') {
    $inline_search = TRUE;
    $vars['inline_search'] = $inline_search;
  }

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
function ocha_basic_menu_link(array $variables) {
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
