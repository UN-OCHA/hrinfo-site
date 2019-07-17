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

    $mlid = $node_form ? $form['menu']['link']['mlid']['#value'] : $form['mlid']['#value'];

    // Has this setting been enabled for this content?
    $default = ($mlid == 0) ? 0 : (bool) _menu_target_retarget_link($mlid);

    // Create the form array.
    $target = array(
      '#type' => 'checkbox',
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
    array_unshift($form['#submit'], '_menu_target_edit_form_extra_elements_submit');
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
    '#description' => t("Here you can choose which behavior is used to open links in new windows. If you choose 'Degradable', the HTML !link1 attribute will be used. Since this attribute does not validate for XHTML doctypes since version 1.1, you can also choose to use the 'XHTML valid' option. This will use JavaScript to open links in a new window", array('!link1' => l(t('target'), 'http://www.w3.org/TR/html4/present/frames.html#adef-target'))),
  );
  $form['#submit'][] = '_menu_target_menu_configure_extra_elements_submit';
}

/**
 * Implements hook_form_submit().
 * Saves the Menu Target settings.
 */
function _menu_target_menu_configure_extra_elements_submit($form, &$form_state) {
  $values = $form_state['values'];
  variable_set('menu_target_enabled', $values['menu_target_enabled']);
  variable_set('menu_target_type', $values['menu_target_type']);
}
