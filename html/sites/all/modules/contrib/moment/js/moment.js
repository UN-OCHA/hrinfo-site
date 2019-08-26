/**
 * @file
 * Moment.js integration.
 */

(function ($, Drupal) {
  'use strict';

  Drupal.moment = Drupal.moment || {};

  /**
   * Interface language code.
   *
   * @return {string}
   *   Language code.
   */
  Drupal.moment.getInterfaceLanguageCode = function () {
    var $html = $('html');

    return $html.attr('lang') || $html.attr('xml:lang') || 'en';
  };

  /**
   * Supported formats are very limited.
   *
   * @todo Improve.
   *
   * @param {string} format
   *   Date format.
   *
   * @return {string}
   *   Limited date format.
   */
  Drupal.moment.dateLimitFormatDate = function (format) {
    return format
      .replace(/h|H|m|s/g, '')
      .replace(/^[\s,'"\.:;\-]+/g, '')
      .replace(/[\s,'"\.:;\-]+$/g, '');
  };

}(jQuery, Drupal));
