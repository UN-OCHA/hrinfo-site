<?php

/**
 * @file
 * hr_core.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_core_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'seven';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chosen_jquery_selector';
  $strongarm->value = 'select:visible,.page-admin-missing-disaster-terms-on-nodes select,select.form-control,select:not("element-invisible")';
  $export['chosen_jquery_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chosen_minimum_multiple';
  $strongarm->value = '0';
  $export['chosen_minimum_multiple'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chosen_minimum_single';
  $strongarm->value = '0';
  $export['chosen_minimum_single'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone';
  $strongarm->value = 'UTC';
  $export['date_default_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_first_day';
  $strongarm->value = '1';
  $export['date_first_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_hr_1';
  $strongarm->value = 'd M Y';
  $export['date_format_hr_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_hr_2';
  $strongarm->value = 'd M Y - H:i';
  $export['date_format_hr_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'empty_timezone_message';
  $strongarm->value = 0;
  $export['empty_timezone_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_entity_types';
  $strongarm->value = array(
    'bean' => 0,
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'file' => 0,
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
    'user' => 0,
  );
  $export['entity_translation_entity_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_default_export_path';
  $strongarm->value = 'sites/all/modules/hr';
  $export['features_default_export_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_private_path';
  $strongarm->value = 'sites/www.humanitarianresponse.info/private/files';
  $export['file_private_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagemagick_convert';
  $strongarm->value = '/usr/bin/convert';
  $export['imagemagick_convert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_toolkit';
  $strongarm->value = 'imagemagick';
  $export['image_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.9';
  $export['jquery_update_jquery_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language';
  $strongarm->value = array(
    'language-default' => array(
      'callbacks' => array(
        'language' => 'language_from_default',
      ),
    ),
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
  );
  $export['language_negotiation_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_content';
  $strongarm->value = array(
    'language-default' => array(
      'callbacks' => array(
        'language' => 'language_from_default',
      ),
    ),
    'locale-interface' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_interface',
      ),
      'file' => 'includes/locale.inc',
    ),
  );
  $export['language_negotiation_language_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_url';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'locale-url-fallback' => array(
      'callbacks' => array(
        'language' => 'locale_language_url_fallback',
      ),
      'file' => 'includes/locale.inc',
    ),
  );
  $export['language_negotiation_language_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_create_by_default';
  $strongarm->value = 1;
  $export['og_menu_create_by_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_page_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:11:"panels_page";s:23:"allowed_layout_settings";a:35:{s:8:"flexible";b:0;s:6:"onecol";b:0;s:17:"threecol_33_34_33";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;s:13:"twocol_bricks";b:0;s:24:"bootstrap_twocol_stacked";b:0;s:26:"bootstrap_threecol_stacked";b:0;s:12:"radix_boxton";b:1;s:11:"radix_sutro";b:1;s:20:"radix_bryant_flipped";b:1;s:10:"radix_burr";b:1;s:21:"radix_brenham_flipped";b:1;s:20:"radix_taylor_flipped";b:1;s:13:"radix_moscone";b:1;s:12:"radix_whelan";b:1;s:23:"radix_sanderson_flipped";b:0;s:21:"radix_hewston_flipped";b:0;s:11:"radix_geary";b:1;s:12:"radix_taylor";b:1;s:21:"radix_moscone_flipped";b:1;s:13:"radix_hewston";b:0;s:11:"radix_brown";b:0;s:12:"radix_harris";b:1;s:12:"radix_phelan";b:1;s:22:"radix_bartlett_flipped";b:0;s:13:"radix_brenham";b:1;s:18:"radix_burr_flipped";b:1;s:14:"radix_bartlett";b:0;s:15:"radix_sanderson";b:0;s:12:"radix_bryant";b:1;s:14:"radix_mccoppin";b:1;}s:10:"form_state";N;}';
  $export['panels_page_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_page_default';
  $strongarm->value = array(
    'block' => 'block',
    'custom' => 'custom',
    'entity_field' => 'entity_field',
    'entity_field_extra' => 'entity_field_extra',
    'entity_form_field' => 'entity_form_field',
    'entity_view' => 'entity_view',
    'other' => 'other',
    'token' => 'token',
  );
  $export['panels_page_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_advanced';
  $strongarm->value = array(
    'csp_limits' => array(
      'flood' => array(
        'limit_global' => '1000',
        'limit_user' => '100',
        'window_global' => '3600',
        'window_user' => '900',
      ),
      'max_size' => '4096',
    ),
    'disable_seckit' => 0,
    'unlimited_csp_reports' => 1,
  );
  $export['seckit_advanced'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_clickjacking';
  $strongarm->value = array(
    'js_css_noscript' => 0,
    'noscript_message' => 'Sorry, you need to enable JavaScript to visit this website.',
    'x_frame' => '1',
    'x_frame_allow_from' => '',
  );
  $export['seckit_clickjacking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_csrf';
  $strongarm->value = array(
    'origin' => 1,
    'origin_whitelist' => 'https://fonts.gstatic.com',
  );
  $export['seckit_csrf'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_ct';
  $strongarm->value = array(
    'enforce' => 0,
    'expect_ct' => 0,
    'max_age' => '1000',
    'report-uri' => '',
  );
  $export['seckit_ct'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_fp';
  $strongarm->value = array(
    'feature_policy' => 0,
    'feature_policy_policy' => '',
  );
  $export['seckit_fp'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_ssl';
  $strongarm->value = array(
    'hsts' => 0,
    'hsts_max_age' => 1000,
    'hsts_preload' => 0,
    'hsts_subdomains' => 0,
  );
  $export['seckit_ssl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_various';
  $strongarm->value = array(
    'disable_autocomplete' => 0,
    'from_origin' => 0,
    'from_origin_destination' => 'same',
    'referrer_policy' => 0,
    'referrer_policy_policy' => 'no-referrer',
  );
  $export['seckit_various'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_xss';
  $strongarm->value = array(
    'csp' => array(
      'checkbox' => 1,
      'child-src' => '',
      'connect-src' => '\'self\' https://www.googletagmanager.com https://stats.g.doubleclick.net',
      'default-src' => '\'self\' https://fonts.googleapis.com',
      'font-src' => 'https://fonts.gstatic.com https://maxcdn.bootstrapcdn.com https://stackpath.bootstrapcdn.com',
      'frame-ancestors' => '',
      'frame-src' => 'https://static.addtoany.com',
      'img-src' => '\'self\' data:',
      'media-src' => '',
      'object-src' => '',
      'policy-uri' => '',
      'report-only' => 1,
      'report-uri' => 'report-csp-violation',
      'script-src' => '\'self\' \'unsafe-inline\' https://www.gstatic.com https://www.google.com https://www.google-analytics.com https://app.powerbi.com https://content.powerapps.com https://www.googletagmanager.com https://platform.twitter.com https://maxcdn.bootstrapcdn.com https://static.addtoany.com https://code.highcharts.com https://cdn.jsdelivr.net',
      'style-src' => '\'self\' \'unsafe-inline\'  https://fonts.googleapis.com https://maxcdn.bootstrapcdn.com https://stackpath.bootstrapcdn.com',
      'upgrade-req' => 0,
      'vendor-prefix' => array(
        'webkit' => 0,
        'x' => 0,
      ),
    ),
    'x_xss' => array(
      'select' => '0',
    ),
  );
  $export['seckit_xss'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_default_country';
  $strongarm->value = 'CH';
  $export['site_default_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'ocha_basic';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_admin_role';
  $strongarm->value = '30037204';
  $export['user_admin_role'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_default_timezone';
  $strongarm->value = '2';
  $export['user_default_timezone'] = $strongarm;

  return $export;
}
