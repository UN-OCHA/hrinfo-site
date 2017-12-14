<?php

/**
 * @file
 * Definition of languagefield_handler_filter_locale_language.
 */

/**
 * Filter by language.
 *
 * @ingroup views_filter_handlers
 */
class languagefield_handler_filter_locale_language extends views_handler_filter_in_operator {

  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }

    $field_info = field_info_field($this->definition['field_name']);

    $this->value_title = t('Language');

    // $output_languages = array(
    //   '***CURRENT_LANGUAGE***' => t("Current user's language"),
    //   '***DEFAULT_LANGUAGE***' => t("Default site language"),
    //   LANGUAGE_NONE => t('No language'),
    // );
    // foreach(_languagefield_options($field_info['settings']['enabled']) as $langcode => $language) {
    //   $output_languages[$langcode] = $language['name'];
    // }
    // $this->value_options = $output_languages;

    $this->value_options = languagefield_options_list($field_info, NULL, NULL, NULL);
//    $this->value_options[''] = t('No language');

    return $this->value_options;
  }

}
