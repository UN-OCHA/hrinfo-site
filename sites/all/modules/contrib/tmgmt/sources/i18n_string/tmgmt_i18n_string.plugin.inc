<?php

/**
 * @file
 * Provides the i18n string source controller.
 */

/**
 * Translation plugin controller for i18n strings.
 */
class TMGMTI18nStringSourcePluginController extends TMGMTDefaultSourcePluginController {

  /**
   * {@inheritdoc}
   */
  public function getData(TMGMTJobItem $job_item) {
    $i18n_object = $this->getI18nObjectWrapper($job_item);
    $structure = array();
    $languages = language_list();

    if ($i18n_object instanceof i18n_string_object_wrapper) {
      $i18n_strings = $i18n_object->get_strings();
      $source_language = $job_item->getJob()->source_language;
      foreach ($i18n_strings as $string_id => $string) {
        // If the job source language is different from the i18n source language
        // try to load an existing translation for the language and use it as
        // the source.
        if ($source_language != i18n_string_source_language()) {
          $translation = $string->get_translation($source_language);

          if (empty($translation)) {
            throw new TMGMTException(t('Unable to load %language translation for the string %title',
              array('%language' => $languages[$source_language]->name, '%title' => $string->title)));
          }
          // If '#label' is empty theme_tmgmt_ui_translator_review_form() fails.
          $structure[$string_id] = array(
            '#label' => !empty($string->title) ? $string->title : $string->property,
            '#text' => $translation,
            '#translate' => TRUE
          );
        }
        else {
          // If '#label' is empty theme_tmgmt_ui_translator_review_form() fails.
          $structure[$string_id] = array(
            '#label' => !empty($string->title) ? $string->title : $string->property,
            '#text' => $string->string,
            '#translate' => TRUE
          );
        }
      }
    }
    return $structure;
  }

  /**
   * {@inheritdoc}
   */
  public function saveTranslation(TMGMTJobItem $job_item) {
    $job = tmgmt_job_load($job_item->tjid);
    $data = array_filter(tmgmt_flatten_data($job_item->getData()), '_tmgmt_filter_data');
    foreach ($data as $i18n_string => $item) {
      if (isset($item['#translation']['#text'])) {
        i18n_string_translation_update($i18n_string, $item['#translation']['#text'], $job->target_language);
      }
    }

    // We just saved the translation, set the state of the job item to
    // 'finished'.
    $job_item->accepted();
  }

  /**
   * {@inheritdoc}
   */
  public function getLabel(TMGMTJobItem $job_item) {
    if ($i18n_object = $this->getI18nObjectWrapper($job_item)) {
      // Get the label, default to the get_title() method, fall back to the
      // first string if that is empty.
      $title = t('Unknown');
      if ($i18n_object->get_title()) {
        $title = $i18n_object->get_title();
      }
      elseif ($strings = $i18n_object->get_strings(array('empty' => TRUE))) {
        $title = reset($strings)->get_string();
      }
      return t('@title (@id)', array('@title' => strip_tags(drupal_substr($title, 0, 64)), '@id' => $job_item->item_id));
    }
    return parent::getLabel($job_item);
  }

  /**
   * {@inheritdoc}
   */
  public function getUri(TMGMTJobItem $job_item) {
    if ($wrapper = $this->getI18nObjectWrapper($job_item)) {
      return array(
        'path' => $wrapper->get_path(),
        'options' => array(),
      );
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getType(TMGMTJobItem $job_item) {
    if ($label = $this->getItemTypeLabel($job_item->item_type)) {
      return $label;
    }
    return parent::getType($job_item);
  }

  /**
   * {@inheritdoc}
   */
  public function getSourceLangCode(TMGMTJobItem $job_item) {
    return i18n_string_source_language();
  }

  /**
   * {@inheritdoc}
   */
  public function getExistingLangCodes(TMGMTJobItem $job_item) {
    $existing_lang_codes = array();
    $languages = language_list();

    if ($object = $this->getI18nObjectWrapper($job_item)) {
      $existing_lang_codes = array_keys($languages);
      foreach ($object->load_strings() as $string) {
        foreach ($languages as $language) {
          if ($language->language == $this->getSourceLangCode($job_item)) {
            continue;
          }
          // Remove languages for which we fail to find translation.
          if (in_array($language->language, $existing_lang_codes) && !$string->get_translation($language->language)) {
            $existing_lang_codes = array_diff($existing_lang_codes, array($language->language));
          }
        }
      }
    }

    return $existing_lang_codes;
  }

  /**
   * Helper function to get i18n_object_wrapper for given job item.
   *
   * @param TMGMTJobItem $job_item
   *
   * @return i18n_string_object_wrapper
   */
  protected function getI18nObjectWrapper(TMGMTJobItem $job_item) {
    list(, $type, $object_id) = explode(':', $job_item->item_id, 3);
    return tmgmt_i18n_string_get_wrapper($job_item->item_type, (object) array('type' => $type, 'objectid' => $object_id));
  }

}
