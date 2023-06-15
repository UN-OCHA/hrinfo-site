<?php

/**
 * @file
 * The taxonomy specific translation functions and hook implementations.
 */

/**
 * Returns whether the given taxonomy vocabulary has support for translations.
 *
 * @return bool
 *   TRUE if translation is enabled, FALSE otherwise.
 */
function entity_translation_taxonomy_term_enabled_vocabulary($vocabulary_name) {
  $info = variable_get('entity_translation_taxonomy', array());
  return !empty($info[$vocabulary_name]);
}

/**
 * Taxonomy-term-specific menu alterations.
 */
function entity_translation_taxonomy_term_menu_alter(&$items, $backup) {
  if (isset($backup['taxonomy_term'])) {
    $item = $backup['taxonomy_term'];
    // Preserve the menu router item defined by other modules.
    $callback['page callback'] = $item['page callback'];
    $callback['file'] = $item['file'];
    $callback['module'] = $item['module'];
    $access_arguments = array_merge(array(2, $item['access callback']), $item['access arguments']);
    $page_arguments = array_merge(array('taxonomy_term', 2, $callback), $item['page arguments']);
  }
  else {
    $access_arguments = array(2);
    $page_arguments = array('taxonomy_term', 2);
  }

  $items['taxonomy/term/%taxonomy_term/translate']['page callback'] = 'entity_translation_overview';
  $items['taxonomy/term/%taxonomy_term/translate']['page arguments'] = $page_arguments;
  $items['taxonomy/term/%taxonomy_term/translate']['access arguments'] = $access_arguments;
  $items['taxonomy/term/%taxonomy_term/translate']['access callback'] = 'entity_translation_taxonomy_term_tab_access';
  $items['taxonomy/term/%taxonomy_term/translate']['file'] = 'entity_translation.admin.inc';
  $items['taxonomy/term/%taxonomy_term/translate']['module'] = 'entity_translation';

  // Delete translation callback.
  $items['taxonomy/term/%taxonomy_term/translate/delete/%entity_translation_language']['access arguments'] = $access_arguments;
}

/**
 * Taxonomy term specific access callback.
 */
function entity_translation_taxonomy_term_tab_access() {
  $args = func_get_args();
  $term = array_shift($args);
  if (entity_translation_enabled('taxonomy_term', $term)) {
    return entity_translation_tab_access('taxonomy_term', $term);
  }
  else {
    $function = array_shift($args);
    return $function ? call_user_func_array($function, $args) : FALSE;
  }
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function entity_translation_form_taxonomy_form_vocabulary_alter(&$form, &$form_state) {
  if (entity_translation_enabled('taxonomy_term')) {
    $name = $form_state['vocabulary']->machine_name;
    if (isset($form['i18n_translation']['i18n_mode'])) {
      $args = array('!url' => url('admin/config/regional/entity_translation'));
      $form['i18n_translation']['i18n_mode']['#options'][I18N_MODE_ENTITY_TRANSLATION] = t('Field translation. Term fields will be translated through the <a href="!url">Entity translation</a> module.', $args);
      if (entity_translation_enabled_bundle('taxonomy_term', $name)) {
        $form['i18n_translation']['i18n_mode']['#default_value'] = I18N_MODE_ENTITY_TRANSLATION;
      }
    }
    else {
      $form['entity_translation_taxonomy'] = array(
        '#title' => t('Enable field translation'),
        '#type' => 'checkbox',
        '#prefix' => '<label>' . t('Translation') . '</label>',
        '#default_value' => entity_translation_enabled('taxonomy_term', $name),
      );
    }
    $form['#submit'][] = 'entity_translation_form_taxonomy_form_vocabulary_submit';
  }
}

/**
 * Submit handler for the taxonomy vocabulary form.
 */
function entity_translation_form_taxonomy_form_vocabulary_submit($form, &$form_state) {
  if (!empty($form_state['values']['i18n_mode']) && $form_state['values']['i18n_mode'] == I18N_MODE_ENTITY_TRANSLATION) {
    $form_state['values']['entity_translation_taxonomy'] = TRUE;
  }
  $info = variable_get('entity_translation_taxonomy', array());
  $info[$form_state['vocabulary']->machine_name] = !empty($form_state['values']['entity_translation_taxonomy']);
  variable_set('entity_translation_taxonomy', $info);
}

/**
 * Returns a translated label for the specified taxonomy term.
 *
 * @param object $term
 *   A taxonomy term object.
 * @param string $langcode
 *   The language the label should be translated in.
 *
 * @return string
 *   The translated taxonomy term label.
 *
 * @internal This is supposed to be used only by the ET taxonomy integration
 *   code, as it might be removed/replaced in any moment of the ET lifecycle.
 */
function _entity_translation_taxonomy_label($term, $langcode) {
  $entity_type = 'taxonomy_term';
  if (function_exists('title_entity_label')) {
    $label = title_entity_label($term, $entity_type, $langcode);
  }
  else {
    $label = entity_label($entity_type, $term);
  }
  return (string) $label;
}

/**
 * Implements entity_translation_form_field_ui_field_edit_WIDGET_TYPE_form_alter().
 *
 * {@inheritdoc}
 */
function entity_translation_form_field_ui_field_edit_taxonomy_autocomplete_form_alter(&$form, &$form_state) {
  $key = 'entity_translation_taxonomy_autocomplete_translate';
  $instance = $form['#instance'];
  $field_name = $instance['field_name'];
  $entity_type = $instance['entity_type'];
  $field = field_info_field($field_name);
  $translatable = field_is_translatable($entity_type, $field);
  $bundle = !empty($field['settings']['allowed_values'][0]['vocabulary']) ? $field['settings']['allowed_values'][0]['vocabulary'] : NULL;
  $access = variable_get('entity_translation_taxonomy_autocomplete', FALSE);

  // Add a checkbox to toggle in-place translation for autocomplete widgets.
  $form['instance']['settings'][$key] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable in-place translation of terms'),
    '#description' => t('Check this option if you wish to use translation forms to perform in-place translation for terms entered in the original language.'),
    '#default_value' => !$translatable && !empty($form['#instance']['settings'][$key]),
    '#access' => $access && (!$form_state['field_has_data'] || !$translatable) && entity_translation_enabled('taxonomy_term', $bundle),
    '#states' => array(
      'visible' => array(':input[name="field[translatable]"]' => array('checked' => FALSE)),
    ),
    '#weight' => -8,
  );
}

/**
 * Checks whether in-place translation is enabled for the autocomplete widget.
 *
 * @param array $element
 *   The widget form element.
 * @param array $form_state
 *   The form state array.
 *
 * @return bool
 *   TRUE if in-place translation is enabled, FALSE otherwise.
 */
function _entity_translation_taxonomy_autocomplete_translation_enabled($element, $form_state) {
  $field = field_info_field($element['#field_name']);
  if (field_is_translatable($element['#entity_type'], $field)) {
    return FALSE;
  }

  list($id, , $bundle) = entity_extract_ids($element['#entity_type'], $element['#entity']);
  if (!$id) {
    return FALSE;
  }

  $entity_type = 'taxonomy_term';
  $parent_handler = entity_translation_get_handler($element['#entity_type'], $element['#entity']);
  $active_langcode = $parent_handler->getActiveLanguage();
  $translations = $parent_handler->getTranslations();
  $entity_langcode = isset($translations->original) ? $translations->original : LANGUAGE_NONE;
  $instance = field_info_instance($element['#entity_type'], $field['field_name'], $bundle);

  // We need to make sure that we are not dealing with a translation form.
  // However checking the active language is not enough, because the user may
  // have changed the entity language.
  return
    (isset($form_state['entity_translation']['is_translation']) ?
      $form_state['entity_translation']['is_translation'] : ($active_langcode != $entity_langcode)) &&
    !empty($instance['settings']['entity_translation_taxonomy_autocomplete_translate']) &&
    (user_access('translate any entity') || user_access("translate $entity_type entities"));
}

/**
 * Implements hook_field_widget_WIDGET_TYPE_form_alter().
 *
 * {@inheritdoc}
 */
function entity_translation_field_widget_taxonomy_autocomplete_form_alter(&$element, &$form_state, $context) {
  // The autocomplete widget is also displayed in the field configuration form,
  // in which case we do not need to perform any alteration. To preserve BC, by
  // default we enable our taxonomy autocomplete override only on new sites.
  if (!isset($element['#entity']) || !variable_get('entity_translation_taxonomy_autocomplete', FALSE)) {
    return;
  }

  // We will need to translate term names, if Title is enabled and configured
  // for this vocabulary.
  $entity_type = 'taxonomy_term';
  $field = field_widget_field($element, $form_state);
  $bundle = !empty($field['settings']['allowed_values'][0]['vocabulary']) ? $field['settings']['allowed_values'][0]['vocabulary'] : NULL;
  if ($bundle && entity_translation_enabled($entity_type, $bundle)) {
    $parent_handler = entity_translation_get_handler($element['#entity_type'], $element['#entity']);
    $langcode = $parent_handler->getActiveLanguage();
    $terms = array_values(_entity_translation_taxonomy_autocomplete_widget_get_terms($element));

    // If we are using the regular autocomplete behavior also in translation
    // forms, we need to set our custom callback.
    if (!_entity_translation_taxonomy_autocomplete_translation_enabled($element, $form_state)) {
      $element['#autocomplete_path'] = 'entity_translation/' . $entity_type . '/autocomplete/' . $langcode . '/' . $element['#field_name'];
      $translations = $parent_handler->getTranslations();
      if (isset($translations->original) && $translations->original != $langcode) {
        $labels = array();
        foreach ($terms as $delta => $term) {
          $labels[] = _entity_translation_taxonomy_label($term, $langcode);
        }
        $element['#default_value'] = implode(', ', $labels);
      }
    }
    // Otherwise we just provide the in-place translation widget.
    else {
      $element['#type'] = 'fieldset';
      $element['#description'] = t('Enter one translation for each term');
      $element['#access'] = (bool) $terms;
      foreach ($terms as $delta => $term) {
        $element[$delta] = array(
          '#type' => 'textfield',
          '#default_value' => _entity_translation_taxonomy_label($term, $langcode),
          '#required' => TRUE,
          '#tid' => $term->tid,
        );
      }
      $element['#process'][] = 'entity_translation_taxonomy_autocomplete_process';
    }

    // The native term save logic is performed at widget validation level, so we
    // just replace the validation handler to provide our logic instead.
    $element['#element_validate'] = array_values(array_diff($element['#element_validate'], array('taxonomy_autocomplete_validate')));
    $element['#element_validate'][] = 'entity_translation_taxonomy_autocomplete_validate';
  }
}

/**
 * Returns the terms referenced by the taxonomy autocomplete widget field.
 *
 * @param array $element
 *   The taxonomy autocomplete form element.
 *
 * @return object[]
 *   An associative array of taxonomy term object keyed by their identifiers.
 */
function _entity_translation_taxonomy_autocomplete_widget_get_terms($element) {
  $items = isset($element['#entity']->{$element['#field_name']}[$element['#language']]) ?
    $element['#entity']->{$element['#field_name']}[$element['#language']] : array();
  $tids = array_map(function ($item) { return $item['tid']; }, $items);
  return taxonomy_term_load_multiple($tids);
}

/**
 * Process callback for the ET taxonomy autocomplete widget.
 *
 * {@inheritdoc}
 */
function entity_translation_taxonomy_autocomplete_process($element) {
  // The in-place translation widget makes sense only for untranslatable field,
  // which may have the "(all languages)" label suffix. In this case it would be
  // confusing so we need to revert that.
  $instance = field_info_instance($element['#entity_type'], $element['#field_name'], $element['#bundle']);
  $element['#title'] = check_plain($instance['label']);
  return $element;
}

/**
 * Entity translation taxonomy autocomplete callback.
 *
 * @param string $langcode
 *   The input language.
 * @param string $field_name
 *   The name of the term reference field.
 * @param string $tags_typed
 *   (optional) A comma-separated list of term names entered in the
 *   autocomplete form element. Only the last term is used for autocompletion.
 *   Defaults to an empty string.
 *
 * @see taxonomy_autocomplete()
 */
function entity_translation_taxonomy_term_autocomplete($langcode = NULL, $field_name = '', $tags_typed = '') {
  // If the request has a '/' in the search text, then the menu system will have
  // split it into multiple arguments, recover the intended $tags_typed.
  $args = func_get_args();
  // Shift off the $langcode and $field_name arguments.
  array_shift($args);
  array_shift($args);
  $tags_typed = implode('/', $args);

  // Make sure the field exists and is a taxonomy field.
  if (!($field = field_info_field($field_name)) || $field['type'] !== 'taxonomy_term_reference') {
    // Error string. The JavaScript handler will realize this is not JSON and
    // will display it as debugging information.
    print t('Taxonomy field @field_name not found.', array('@field_name' => $field_name));
    exit;
  }

  // The user enters a comma-separated list of tags. We only autocomplete the
  // last tag.
  $tags_typed = drupal_explode_tags($tags_typed);
  $tag_last = drupal_strtolower(array_pop($tags_typed));

  $term_matches = array();
  if ($tag_last != '') {
    if (!isset($langcode) || $langcode == LANGUAGE_NONE) {
      $langcode = $GLOBALS['language_content']->language;
    }

    // Part of the criteria for the query come from the field's own settings.
    $vocabulary = _entity_translation_taxonomy_reference_get_vocabulary($field);

    $entity_type = 'taxonomy_term';
    $query = new EntityFieldQuery();
    $query->addTag('taxonomy_term_access');
    $query->entityCondition('entity_type', $entity_type);

    // If the Title module is enabled and the taxonomy term name is replaced for
    // the current bundle, we can look for translated names, otherwise we fall
    // back to the regular name property.
    if (module_invoke('title', 'field_replacement_enabled', $entity_type, $vocabulary->machine_name, 'name')) {
      $name_field = 'name_field';
      $language_group = 0;
      // Do not select already entered terms.
      $column = 'value';
      if (!empty($tags_typed)) {
        $query->fieldCondition($name_field, $column, $tags_typed, 'NOT IN', NULL, $language_group);
      }
      $query->fieldCondition($name_field, $column, $tag_last, 'CONTAINS', NULL, $language_group);
      $query->fieldLanguageCondition($name_field, array($langcode, LANGUAGE_NONE), NULL, NULL, $language_group);
    }
    else {
      $name_field = 'name';
      // Do not select already entered terms.
      if (!empty($tags_typed)) {
        $query->propertyCondition($name_field, $tags_typed, 'NOT IN');
      }
      $query->propertyCondition($name_field, $tag_last, 'CONTAINS');
    }

    // Select rows that match by term name.
    $query->propertyCondition('vid', $vocabulary->vid);
    $query->range(0, 10);
    $result = $query->execute();

    // Populate the results array.
    $prefix = count($tags_typed) ? drupal_implode_tags($tags_typed) . ', ' : '';
    $terms = !empty($result[$entity_type]) ? taxonomy_term_load_multiple(array_keys($result[$entity_type])) : array();
    foreach ($terms as $tid => $term) {
      $name = _entity_translation_taxonomy_label($term, $langcode);
      $n = $name;
      // Term names containing commas or quotes must be wrapped in quotes.
      if (strpos($name, ',') !== FALSE || strpos($name, '"') !== FALSE) {
        $n = '"' . str_replace('"', '""', $name) . '"';
      }
      $term_matches[$prefix . $n] = check_plain($name);
    }
  }

  drupal_json_output($term_matches);
}

/**
 * Returns the vocabulary enabled for the specified taxonomy reference field.
 *
 * @param array $field
 *   A field definition.
 *
 * @return object|null
 *   A vocabulary object or NULL if none is found.
 */
function _entity_translation_taxonomy_reference_get_vocabulary($field) {
  $vocabulary = NULL;
  if (!empty($field['settings']['allowed_values'])) {
    $vids = array();
    $vocabularies = taxonomy_vocabulary_get_names();
    foreach ($field['settings']['allowed_values'] as $tree) {
      $vids[] = $vocabularies[$tree['vocabulary']]->vid;
    }
    $vocabulary = taxonomy_vocabulary_load(reset($vids));
  }
  return $vocabulary;
}

/**
 * Form element validate handler for taxonomy term autocomplete element.
 *
 * {@inheritdoc}
 *
 * @see taxonomy_autocomplete_validate()
 */
function entity_translation_taxonomy_autocomplete_validate($element, &$form_state) {
  $value = array();
  list($id) = entity_extract_ids($element['#entity_type'], $element['#entity']);
  $is_new = !isset($id);

  // This is the language of the parent entity, that we will be applying to new
  // terms.
  $parent_handler = entity_translation_get_handler($element['#entity_type'], $element['#entity']);
  $langcode = !empty($form_state['entity_translation']['form_langcode']) ?
    $form_state['entity_translation']['form_langcode'] : $parent_handler->getActiveLanguage();

  // Handle in-place translation.
  if (_entity_translation_taxonomy_autocomplete_translation_enabled($element, $form_state)) {
    // The referenced terms cannot change, so we just need to collect their term
    // identifiers. We also build a map of the corresponding deltas for later
    // use.
    $deltas = array();
    foreach (element_children($element) as $delta) {
      $tid = $element[$delta]['#tid'];
      $deltas[$tid] = $delta;
      $value[$delta]['tid'] = $tid;
    }

    // Save term translations.
    $entity_type = 'taxonomy_term';
    $name_field = 'name_field';
    $source_langcode = $parent_handler->getSourceLanguage();
    // This is a validation handler, so we must defer the actual save to the
    // submit phase.
    $terms_to_save = &$form_state['entity_translation']['taxonomy_autocomplete'][$element['#entity_type']][$id][$element['#field_name']];
    foreach (taxonomy_term_load_multiple(array_keys($deltas)) as $term) {
      // This is also the right context to perform validation.
      $term_translation = $element[$deltas[$term->tid]]['#value'];
      if (!$term_translation) {
        $instance = field_info_instance($element['#entity_type'], $element['#field_name'], $element['#bundle']);
        drupal_set_message(t('The translations for %field_label cannot be empty.', array('%field_label' => $instance['label'])), 'error', FALSE);
        continue;
      }

      $handler = entity_translation_get_handler($entity_type, $term);
      $translations = $handler->getTranslations();
      $term_langcode = $handler->getLanguage();
      $typed_langcode = $term_langcode != LANGUAGE_NONE ? $langcode : $term_langcode;

      // Create a new translation in the active language, if it is missing.
      if (!isset($translations->data[$typed_langcode]) && $typed_langcode != LANGUAGE_NONE) {
        $translation = array(
          'language' => $typed_langcode,
          'source' => $source_langcode,
          'uid' => $GLOBALS['user']->uid,
          'status' => 1,
          'created' => REQUEST_TIME,
          'changed' => REQUEST_TIME,
        );
        $translation_values = array(
          $name_field => array($typed_langcode => array(array('value' => $term_translation))),
        );
        $handler->setTranslation($translation, $translation_values);
        $terms_to_save[] = $term;
      }
      // Otherwise we just update the existing translation, if it has changed.
      // If the term is language-neutral, we just update its main value. This is
      // expected to happen normally, but could when referencing existing terms.
      elseif ($term_translation != _entity_translation_taxonomy_label($term, $typed_langcode)) {
        $term->{$name_field}[$typed_langcode][0]['value'] = $term_translation;
        $terms_to_save[] = $term;
      }
    }
  }
  // Autocomplete widgets do not send their tids in the form, so we must detect
  // them here and process them independently.
  elseif ($tags = $element['#value']) {
    $entity_type = 'taxonomy_term';
    $field = field_widget_field($element, $form_state);
    $vocabulary = _entity_translation_taxonomy_reference_get_vocabulary($field);
    $typed_tags = drupal_explode_tags($tags);

    // Collect existing terms by name.
    $existing_terms = array();
    foreach (_entity_translation_taxonomy_autocomplete_widget_get_terms($element) as $term) {
      $name = _entity_translation_taxonomy_label($term, $langcode);
      $existing_terms[$name] = $term;
    }

    // Select terms that match by the (translated) name.
    $query = new EntityFieldQuery();
    $query->addTag('taxonomy_term_access');
    $query->entityCondition('entity_type', $entity_type);
    $query->propertyCondition('vid', $vocabulary->vid);
    if ($langcode != LANGUAGE_NONE && module_invoke('title', 'field_replacement_enabled', $entity_type, $vocabulary->machine_name, 'name')) {
      $language_group = 0;
      // Do not select already entered terms.
      $name_field = 'name_field';
      $column = 'value';
      $query->fieldCondition($name_field, $column, $typed_tags, NULL, NULL, $language_group);
      // When we are creating a new entity, we cannot filter by active language,
      // as that may have not be applied to the autocomplete query.
      if (!$is_new) {
        $query->fieldLanguageCondition($name_field, array($langcode, LANGUAGE_NONE), NULL, NULL, $language_group);
      }
    }
    else {
      $query->propertyCondition('name', $typed_tags);
    }
    $result = $query->execute();

    // When we are creating a new entity, the language used for the autocomplete
    // query is the current content language, so we should use that to update
    // the map of existing terms.
    if (!empty($result[$entity_type])) {
      $typed_langcode = !$is_new ? $langcode : $GLOBALS['language_content']->language;
      foreach (taxonomy_term_load_multiple(array_keys($result[$entity_type])) as $term) {
        $name = _entity_translation_taxonomy_label($term, $typed_langcode);
        $existing_terms[$name] = $term;
      }
    }

    // Now collect the identifiers for the various terms and update the taxonomy
    // reference field values.
    foreach ($typed_tags as $delta => $typed_tag) {
      // See if the term exists in the chosen vocabulary and return the tid.
      // Otherwise create a new 'autocreate' term for insert/update.
      if (isset($existing_terms[$typed_tag])) {
        $term = $existing_terms[$typed_tag];
      }
      else {
        $term = (object) array(
          'tid' => 'autocreate',
          'vid' => $vocabulary->vid,
          'name' => $typed_tag,
          'vocabulary_machine_name' => $vocabulary->machine_name,
        );
        $handler = entity_translation_get_handler($entity_type, $term);
        $handler->setOriginalLanguage($langcode);
        $handler->initTranslations();
      }
      $value[] = (array) $term;
    }
  }

  form_set_value($element, $value, $form_state);
}

/**
 * Term-specific implementation of hook_field_attach_submit().
 */
function entity_translation_taxonomy_term_field_attach_submit($entity_type, $entity, $form, &$form_state) {
  // Finally save in-place translations
  if (!empty($form_state['entity_translation']['taxonomy_autocomplete'])) {
    foreach ($form_state['entity_translation']['taxonomy_autocomplete'] as $entity_type => $entity_type_data) {
      foreach ($entity_type_data as $id => $field_name_data) {
        foreach ($field_name_data as $field_name => $term_data) {
          if (!is_array($term_data)) {
            continue;
          }
          foreach ($term_data as $term) {
            entity_translation_entity_save('taxonomy_term', $term);
          }
        }
      }
    }
  }
}
