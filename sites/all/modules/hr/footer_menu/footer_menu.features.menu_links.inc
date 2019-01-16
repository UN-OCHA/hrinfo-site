<?php

/**
 * @file
 * footer_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function footer_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_privacy:https://www.un.org/en/sections/about-website/privacy-notice.
  $menu_links['menu-footer-menu_privacy:https://www.un.org/en/sections/about-website/privacy-notice'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'https://www.un.org/en/sections/about-website/privacy-notice',
    'router_path' => '',
    'link_title' => 'Privacy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-menu_privacy:https://www.un.org/en/sections/about-website/privacy-notice',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu_terms-of-use:https://www.un.org/en/sections/about-website/terms-use.
  $menu_links['menu-footer-menu_terms-of-use:https://www.un.org/en/sections/about-website/terms-use'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'https://www.un.org/en/sections/about-website/terms-use',
    'router_path' => '',
    'link_title' => 'Terms of use',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-menu_terms-of-use:https://www.un.org/en/sections/about-website/terms-use',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Privacy');
  t('Terms of use');

  return $menu_links;
}
