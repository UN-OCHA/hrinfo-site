<?php

/**
 * @file
 * Provides integration functions with the libraries API and libphonenumber.
 */

/**
 * Creates and returns a libphonenumber phonenumber object.
 *
 * @param string $number
 *   The raw phone number we are working with.
 * @param string $countrycode
 *   The selected countrycode for this number.
 * @param string $extension
 *   An extension number.
 * @param bool $allow_alpha
 *   When set to TRUE, and $number contains alpha characters,
 *   i.e. is a vanity number, then retain the alpha formatting,
 *   and do not convert the number to its numeric equivalent.
 *
 * @return array
 *   An array with two items, the $phoneutil object, and the
 *   parsed $phonenumber object.
 *
 * @throws libphonenumber\NumberParseException on error.
 */
function _phone_libphonenumber($number, $countrycode, $extension, $allow_alpha = FALSE) {
  // Get the PhoneNumberUtil object instance.
  $phoneutil = libphonenumber\PhoneNumberUtil::getInstance();

  // If we don't allow alpha characters, then strip them here.
  if (!$allow_alpha) {
    $number = libphonenumber\PhoneNumberUtil::convertAlphaCharactersInNumber($number);
  }

  // Let libphonenumber handle the extension.
  if (!empty($extension)) {
    $number .= ';ext=' . $extension;
  }

  // Parse the number into a phonenumber object.
  $phonenumber = $phoneutil->parse($number, $countrycode, NULL, TRUE);

  return array($phoneutil, $phonenumber);
}

/**
 * Validates a phone number with libphonenumber.
 *
 * @param string $number
 *   The raw phone number we are working with.
 * @param string $countrycode
 *   The selected countrycode for this number.
 * @param string $extension
 *   An extension number.
 * @param bool $all_countries
 *   When TRUE, all countries are allowed,
 *   when FALSE, supply $allowed_countries to
 *   perform extra validation.
 * @param array $allowed_countries
 *   An array of allowed countries. When empty,
 *   this check will be ignored.
 *
 * @return string
 *   Returns boolean TRUE when the number is valid,
 *   a formatted error message otherwise.
 */
function phone_libphonenumber_valid($number, $countrycode, $extension, $all_countries = TRUE, $allowed_countries = array()) {
  try {
    // Get the parsed phone objects.
    // Allow alpha characters, in case $number contains an extension that we need to parse.
    list($phoneutil, $phonenumber) = _phone_libphonenumber($number, $countrycode, $extension, TRUE);

    // If this is an alpha number and it has an extension, inform the user that this is not supported.
    if ($phonenumber->hasExtension() && $phoneutil->isAlphaNumber($number)) {
      return t('Vanity numbers do not support extensions. Input the real number if you wish to use an extension.');
    }

    // Get the actual countrycode used, in case we didn't have one before,
    // and libphonenumber was able to detect one from a country code.
    if ($phonenumber->getCountryCodeSource() != libphonenumber\CountryCodeSource::FROM_DEFAULT_COUNTRY) {
      $new_countrycode = $phoneutil->getRegionCodeForCountryCode($phonenumber->getCountryCode());

      // If the country code is empty, then set the new one,
      // if the country code is different, lets see if they have the same
      // calling code, if they do, use our original country code.
      // i.e. Calling Code of +1 is always the US, but the user might have
      // input Barbados for example.
      if (empty($countrycode) || ($countrycode != $new_countrycode && $phonenumber->getCountryCode() != $phoneutil->getMetadataForRegion($countrycode)->getCountryCode())) {
        $countrycode = $new_countrycode;
      }
    }

    // Check if this number is actually valid.
    if (!$phoneutil->isValidNumber($phonenumber)) {
      $error = t('The number "%number" is not a valid phone number for @country.',
        array(
          '%number' => $number,
          '@country' => phone_countries($countrycode, 'country'),
        )
      );

      $example = $phoneutil->getExampleNumber($countrycode);
      if (!empty($example)) {
        $error .= ' ' . t('The expected format is %example.', array('%example' => $phoneutil->format($example, libphonenumber\PhoneNumberFormat::NATIONAL)));
      }

      return $error;
    }

    if (!$all_countries && !empty($allowed_countries) && !isset($allowed_countries[$countrycode])) {
      return t('Numbers from %country are not allowed.',
        array(
          '%country' => phone_countries($countrycode, 'country'),
        )
      );
    }

    if (!empty($extension) && preg_match('/[^0-9]/', $extension)) {
      return t('Phone extensions can only contain digits.');
    }
  }
  catch (libphonenumber\NumberParseException $e) {
    // Various error reasons why the number parsing might have failed.
    // Return a meaningful message.
    switch ($e->getErrorType()) {
      case libphonenumber\NumberParseException::TOO_SHORT_AFTER_IDD:
        return t('The number "%number" appears to include an International Direct Dialing Code, but is not long enough after this code to be a viable phone number.', array('%number' => $number));

      case libphonenumber\NumberParseException::NOT_A_NUMBER:
        return t('The supplied number "%number" does not seem to be a phone number.', array('%number' => $number));

      case libphonenumber\NumberParseException::TOO_SHORT_NSN:
        return t('The number "%number" is too short to be a phone number.', array('%number' => $number));

      case libphonenumber\NumberParseException::TOO_LONG:
        return t('The number "%number" is too long to be a phone number.', array('%number' => $number));

      case libphonenumber\NumberParseException::INVALID_COUNTRY_CODE:
        return t('Invalid country code. Be sure to prefix the number with the plus sign and the direct dial country code you wish to use.');
    }
  }

  // All went well. Hooray.
  return TRUE;
}

/**
 * Formats a phone number using libphonenumber.
 *
 * @param string $number
 *   The raw phone number we are working with.
 * @param string $countrycode
 *   The selected countrycode for this number.
 * @param string $extension
 *   An extension number.
 * @param string $format
 *   The format to return the number in.
 *   Can be one of:
 *     o phone_national
 *     o phone_e164
 *     o phone_rfc3966
 *     o phone_international
 *   Defaults to phone_international when an unrecognised format
 *   is provided.
 *   NB: If $allow_alpha is TRUE, and the number contains alpha
 *       characters, then the number will be returned as it
 *       was entered, and will ignore this format option.
 * @param bool $allow_alpha
 *   When set to TRUE, and $number contains alpha characters,
 *   i.e. is a vanity number, then retain the alpha formatting,
 *   and do not convert the number to its numeric equivalent.
 * @param bool $extension_prefix
 *   When set, allows adjusting the extension prefix.
 *   This option is ignored when $format is phone_rfc3966.
 *
 * @return string
 *   Return the formatted number, or FALSE on error.
 */
function phone_libphonenumber_format($number, $countrycode, $extension, $format, $allow_alpha = FALSE, $extension_prefix = '') {
  try {
    // Get the parsed phone objects.
    list($phoneutil, $phonenumber) = _phone_libphonenumber($number, $countrycode, $extension, $allow_alpha);
  }
  catch (libphonenumber\NumberParseException $e) {
    // Uh oh... What can we do?
    return FALSE;
  }

  // If we allow alpha characters, and have some, then output the number as is.
  if ($allow_alpha && $phoneutil->isAlphaNumber($number)) {
    // We put this through check plain for extra safety. We could probably get
    // away without it, unless libphonenumber was installed after data had
    // already been entered.
    return check_plain($phoneutil->formatOutOfCountryKeepingAlphaChars($phonenumber, $countrycode));
  }

  $add_extension = '';
  if ($format != 'phone_rfc3966' && !empty($extension_prefix) && $extension_prefix != libphonenumber\PhoneNumberUtil::DEFAULT_EXTN_PREFIX && $phonenumber->hasExtension()) {
    $add_extension = check_plain($extension_prefix) . $phonenumber->getExtension();
    $phonenumber->clearExtension();
  }

  // Get the right libphonenumber format option.
  switch ($format) {
    case 'phone_national':
      $format = libphonenumber\PhoneNumberFormat::NATIONAL;
      break;

    case 'phone_e164':
      $format = libphonenumber\PhoneNumberFormat::E164;
      break;

    case 'phone_rfc3966':
      $format = libphonenumber\PhoneNumberFormat::RFC3966;
      break;

    case 'phone_international':
    default:
      $format = libphonenumber\PhoneNumberFormat::INTERNATIONAL;
      break;
  }

  // As above, we probably don't need to put this though check plain,
  // but short of checking all the possible output options from libphonenumber.
  return check_plain($phoneutil->format($phonenumber, $format)) . $add_extension;
}

/**
 * Cleans up phone number components for saving into the database.
 *
 * @param string $number
 *   The raw phone number we are working with.
 * @param sring $countrycode
 *   The selected countrycode for this number.
 * @param string $extension
 *   An extension number.
 *
 * @return array
 *   An array with the number, countrycode, and extension properties,
 *   or an empty array if there is an error.
 */
function phone_libphonenumber_clean($number, $countrycode, $extension) {
  try {
    // Get the parsed phone objects, preserving the alpha characers.
    // Also, don't initialise the extension, otherwise it will be included in
    // the output below, which is wrong.
    list($phoneutil, $phonenumber) = _phone_libphonenumber($number, $countrycode, '', TRUE);

    // Get the actual countrycode used, in case we didn't have one before,
    // and libphonenumber was able to detect one from a country code.
    if ($phonenumber->getCountryCodeSource() != libphonenumber\CountryCodeSource::FROM_DEFAULT_COUNTRY) {
      $new_countrycode = $phoneutil->getRegionCodeForCountryCode($phonenumber->getCountryCode());

      // If the country code is empty, then set the new one,
      // if the country code is different, lets see if they have the same
      // calling code, if they do, use our original country code.
      // i.e. Calling Code of +1 is always the US, but the user might have
      // input Barbados for example.
      if (empty($countrycode) || ($countrycode != $new_countrycode && $phonenumber->getCountryCode() != $phoneutil->getMetadataForRegion($countrycode)->getCountryCode())) {
        $countrycode = $new_countrycode;
      }
    }

    // Extensions should only ever be digits.
    $force_non_alpha = FALSE;
    if ($phonenumber->hasExtension()) {
      $extension = preg_replace('/[^0-9]/', '', $phonenumber->getExtension());
      $phonenumber->clearExtension();
      $force_non_alpha = TRUE;
    }
    else {
      $extension = '';
    }

    // Numbers that have alpha characters are returned as is.
    // Otherwise store the national formatted number with all spaces stripped.
    if ($force_non_alpha || !$phoneutil->isAlphaNumber($number)) {
      $number = $phonenumber->getNationalNumber();
    }

    return array(
      'countrycode' => $countrycode,
      'number' => $number,
      'extension' => $extension,
    );
  }
  catch (libphonenumber\NumberParseException $e) {
    // Uh oh. Do nothing in effect.
    return array();
  }
}

/**
 * Function to get a list of supported countries and calling codes.
 *
 * @return array
 *   An array with the keys 'country', 'calling_code', and 'combined',
 *   with each one being indexed by the country code, and containg
 *   either the country name, the calling code, or a combination of both.
 */
function phone_libphonenumber_get_supported_country_lists() {
  // The locale.inc file is loaded by the locale module in locale_init().
  if (!module_exists('locale')) {
    include_once DRUPAL_ROOT . '/includes/locale.inc';
  }

  // Lib phone number does not include friendly names, only country codes.
  // This will also invoke hook_countries_alter().
  $countries = country_get_list();

  $phoneutil = libphonenumber\PhoneNumberUtil::getInstance();

  // Get the country code information.
  $supported = $phoneutil->getSupportedRegions();
  $calling_codes = array();
  $combined = array();
  foreach ($countries as $region_code => $country_name) {
    // If libphonenumber does not support this country, do not include it.
    if (!in_array($region_code, $supported)) {
      unset($countries[$region_code]);
      continue;
    }

    $calling_code = $phoneutil->getMetadataForRegion($region_code)->getCountryCode();

    $calling_codes[$region_code] = $calling_code;
    $combined[$region_code] = $country_name . ' (+' . $calling_code . ')';
  }

  return array(
    'country' => $countries,
    'calling_code' => $calling_codes,
    'combined' => $combined,
  );
}
