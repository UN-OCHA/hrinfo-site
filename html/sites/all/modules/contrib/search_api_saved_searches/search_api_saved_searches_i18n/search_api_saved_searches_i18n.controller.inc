<?php

/**
 * @file
 * Contains the SearchApiSavedSearchesSettingsI18nStringObjectWrapper class.
 */

/**
 * Customized i18n string integration controller.
 */
class SearchApiSavedSearchesSettingsI18nController extends EntityDefaultI18nStringController {

  /**
   * Overriddes EntityDefaultI18nStringController::hook_object_info() to include a custom object wrapper.
   */
  public function hook_object_info() {
    $info = parent::hook_object_info();
    $info['search_api_saved_searches_settings']['class'] = 'SearchApiSavedSearchesSettingsI18nStringObjectWrapper';
    return $info;
  }

  /**
   * Overrides EntityDefaultI18nStringController::translatableProperties() to define our custom ones.
   */
  protected function translatableProperties() {
    $properties = array();
    $properties['description'] = t('Description');
    $properties['mail.activate.title'] = t('Activation mail, subject');
    $properties['mail.activate.body'] = t('Activation mail, body');
    $properties['mail.notify.title'] = t('Notification mail, subject');
    $properties['mail.notify.body'] = t('Notification mail, body');
    $properties['mail.notify.results'] = t('Notification mail, results replacement');
    $properties['mail.notify.result'] = t('Notification mail, result item replacement');
    $properties['mail.notify.results_capped'] = t('Notification mail, "Not all results" message');
    return $properties;
  }

}
