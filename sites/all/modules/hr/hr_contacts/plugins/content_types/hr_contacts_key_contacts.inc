<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Static'),
  'description' => t('Chose which contacts to display'),
  'category' => t('Contacts'),
  'edit form' => 'hr_contacts_key_contacts_edit_form',
  'render callback' => 'hr_contacts_key_contacts_render',
  'defaults' => array(
    'contacts' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_contacts_key_contacts_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  if (isset($form_state['contacts_count'])) {
    $contacts_count = $form_state['contacts_count'];
  }
  else {
    $contacts_count = count($conf['contacts']);
  }

  // Add a wrapper for the contacts and more button.
  $form['contacts_wrapper'] = array(
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix" id="hr-contacts-key-wrapper">',
    '#suffix' => '</div>',
  );

  // Container for just the contacts.
  $form['contacts_wrapper']['contacts'] = array(
    '#prefix' => '<div id="hr-contacts-key-contacts">',
    '#suffix' => '</div>',
  );

  for ($delta = 0; $delta < $contacts_count; $delta++) {
    $form['contacts_wrapper']['contacts'][$delta] = array(
      '#type' => 'entityreference',
      '#title' => t('Contact'),
      '#era_entity_type' => 'node',
      '#era_bundles' => array('hr_contact'),
      '#era_cardinality' => 1,
      '#default_value' => isset($conf['contacts'][$delta]) ? $conf['contacts'][$delta] : '',
      '#parents' => array('contacts', $delta),
    );
  }

  // We name our button 'hr_contacts_key_list_more' to avoid conflicts with other modules using
  // Ajax-enabled buttons with the id 'more'.
  $form['contacts_wrapper']['hr_contacts_key_list_more'] = array(
    '#type' => 'submit',
    '#value' => t('Add another item'),
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hr_contacts_key_contacts_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  if ($form_state['values']['hr_contacts_key_list_more']) {
    $form_state['contacts_count'] = count($form_state['values']['contacts']) + 1;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_contacts_key_contacts_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $contacts = $conf['contacts'];

  // initial content is blank
  $block->title = '';
  $block->content = '';
  if (!empty($contacts)) {

    foreach ($contacts as $contact) {
      if (isset($contact['entity_id'])) {
        $nid = $contact['entity_id'];
        $node = node_load($nid);
        if ($node != FALSE) {
          $block->content .= drupal_render(node_view($node, 'teaser'));
        }
      }
    }

    if (!empty($block->content)) {
      $block->content = '<div class="fieldable-panels-pane">'.$block->content.'</div>';
    }
  }

  return $block;
}

