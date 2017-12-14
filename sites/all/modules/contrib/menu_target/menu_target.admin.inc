<?php

/**
 * @file
 * Allows content editors to choose wether or not to open menu items in a new
 * window
 */

/**
 * Adds extra form elements to either node_form or menu_item_edit_form.
 *
 * @see menu_target_form_alter()
 */
function menu_target_edit_form_extra_elements(&$form, $node_form) {

  if ($node_form) {
    $type = $form['#node']->type;
    $enabled_menus = variable_get('menu_options_' . $type, array('main-menu' => 'main-menu'));
    if (empty($enabled_menus)) {
      return;
    }
  }

  // Only add extra form elements if the menu target functionality is enabled.
  if (variable_get('menu_target_enabled', 1)) {

    // The achor (<a>) attribute is configurable in the menu configuration
    // form
    // (admin/structure/menu/settings).
    // If it is chosen to use valid XHTML, we will use class="target-blank" and
    // JavaScript will open the link in a
    // new window. If it us chosen to use a degradable workflow, we will
    // use target="_blank".
    $attribute = (variable_get('menu_target_type', 'html') == 'html' ? 'target' : 'class');
    $attribute_value = ($attribute == 'target' ? '_blank' : 'target-blank');

    // Get the currently stored menu options array.
    $options = $node_form ? $form['menu']['link']['options']['#value'] : $form['options']['#value'];

    $default = 0;
    if (isset($options['attributes']) && isset($options['attributes'][$attribute])) {
      if (in_array($attribute_value, $options['attributes'][$attribute])) {
        $default = 1;
      }
    }

    // Create the form array.
    $target = array(
      '#type' => ($attribute == 'html' ? 'select' : 'checkbox'),
      '#title' => t('Open this link in a new window'),
      '#default_value' => $default
    );

    // Depanding on the form type, this element is placed in the
    // appropriate place in the form tree.
    if ($node_form) {
      $form['menu']['link']['target'] = $target;
    }
    else {
      // This is the menu item edit form.
      // Restructure the form in order to place the new target form element
      // just below the 'expanded' checkbox.
      $_form = $form;
      $form = array();
      foreach ($_form as $key => $element) {
        $form[$key] = $_form[$key];
        if ($key == 'expanded') {
          $form['target'] = $target;
        }
      }
    }
    // Add our own submit callback to the form.
    array_unshift($form['#submit'], 'menu_target_edit_form_extra_elements_submit');
  }
}

/**
 * Implements hook_form_submit().
 */
function _menu_target_edit_form_extra_elements_submit($form, &$form_state) {

  // Determine the attribute and the right attribute
  // value.
  $attribute = (variable_get('menu_target_type', 'html') == 'html' ? 'target' : 'class');
  $attribute_value = ($attribute == 'target' ? '_blank' : 'target-blank');

  // Depending on whether we're in a node form or a menu item form, the
  // 'menu link' values are stored in a diffrent place of the form state values
  // tree.
  if (isset($form['#node'])) {
    $values = &$form_state['values']['menu'];
  }
  else {
    $values = &$form_state['values'];
  }

  // If the user has checked the 'open in new window' checkbox,
  // we'll add the right attribute and it's value to the menu's options array.
  if ($values['target'] != 0) {
    if (!isset($values['options']['attributes'])) {
      $values['options']['attributes'] = array($attribute => array($attribute_value));
    }
    elseif (!isset($values['options']['attributes'][$attribute])) {
      $values['options']['attributes'][$attribute] = array($attribute_value);
    }
    elseif (!in_array($attribute_value, $values['options']['attributes'][$attribute])) {
      $values['options']['attributes'][$attribute] = $attribute_value;
    }
  }
  else {
    // Clean up the attributes class array.
    unset($values['options']['attributes'][$attribute]);
  }
}

/**
 * Allows users to enable or disable the Menu target functionality on menu base.
 * @see menu_target_form_menu_configure_alter()
 */
function menu_target_menu_configure_extra_elements(&$form) {
  $form['menu_target'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu target'),
  );
  $form['menu_target']['menu_target_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Menu target enabled'),
    '#default_value' => variable_get('menu_target_enabled', 1),
  );
  $form['menu_target']['menu_target_settings'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        'input[name="menu_target_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['menu_target']['menu_target_settings']['menu_target_type'] = array(
    '#type' => 'radios',
    '#title' => t('Type'),
    '#options' => array('html' => t('Degradable'), 'javascript' => t('XHTML Valid')),
    '#default_value' => variable_get('menu_target_type', 'html'),
    '#description' => t("Here you can choose which behavior is used to open links in new windows. If you choose 'Degradable', the HTML !link1 attribute will be used. While this attribute does not validate for XHTML doctypes since version 1.1, you can also choose to use the 'XHTML valid' option. This will use JavaScript to open links in a new window", array('!link1' => l(t('target'), 'http://www.w3.org/TR/html4/present/frames.html#adef-target'))),
  );
  $form['#submit'][] = 'menu_target_menu_configure_extra_elements_submit';
}

/**
 * Saves the Menu Target settings for a menu.
 */
function menu_target_menu_configure_extra_elements_submit($form, &$form_state) {
  $values = $form_state['values'];

  $old_target_type = variable_get('menu_target_type', 'html');

  variable_set('menu_target_enabled', $values['menu_target_enabled']);
  variable_set('menu_target_type', $values['menu_target_type']);

  if ($old_target_type !== $values['menu_target_type']) {
    _menu_target_menu_links_update_target($values['menu_target_type']);
  }
}

/**
 * Helper function for updating all menu link target or class attributes.
 */
function _menu_target_menu_links_update_target($menu_target_type) {
  $old_attribute = ($menu_target_type == 'html' ? 'class' : 'target');
  $old_value = ($menu_target_type == 'html' ? 'target-blank' : '_blank');
  $new_attribute = ($menu_target_type == 'html' ? 'target' : 'class');
  $new_value = ($menu_target_type == 'html' ? '_blank' : 'target-blank');

  foreach (db_query("SELECT mlid, options FROM {menu_links} WHERE options <> ''") as $menu_item) {
    $menu_item->options = unserialize($menu_item->options);

    if (isset($menu_item->options['attributes'])) {
      $attributes = &$menu_item->options['attributes'];
    }

    if (isset($attributes[$old_attribute]) && in_array($old_value, $attributes[$old_attribute])) {
      unset($attributes[$old_attribute][array_search($old_value, $attributes[$old_attribute])]);
      if (empty($attributes[$old_attribute])) {
        unset($attributes[$old_attribute]);
      }
      $attributes[$new_attribute][] = $new_value;
    }

    db_update('menu_links')
      ->fields(array('options' => serialize($menu_item->options)))
      ->condition('mlid', $menu_item->mlid)
      ->execute();
  }
}
