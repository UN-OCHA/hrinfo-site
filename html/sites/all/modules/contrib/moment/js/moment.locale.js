/**
 * @file
 * Moment.js integration.
 *
 * Override the month and day name translations.
 */

/* global moment: true */

(function (Drupal) {
  'use strict';

  Drupal.behaviors.momentInitialize = {
    attach: function () {
      if (Drupal.moment.initialized) {
        return;
      }

      Drupal.moment.initialized = true;

      moment.defineLocale(
        Drupal.moment.getInterfaceLanguageCode(),
        {
          months: [
            Drupal.t('January', {}, {'context': 'Long month name'}),
            Drupal.t('February', {}, {'context': 'Long month name'}),
            Drupal.t('March', {}, {'context': 'Long month name'}),
            Drupal.t('April', {}, {'context': 'Long month name'}),
            Drupal.t('May', {}, {'context': 'Long month name'}),
            Drupal.t('June', {}, {'context': 'Long month name'}),
            Drupal.t('July', {}, {'context': 'Long month name'}),
            Drupal.t('August', {}, {'context': 'Long month name'}),
            Drupal.t('September', {}, {'context': 'Long month name'}),
            Drupal.t('October', {}, {'context': 'Long month name'}),
            Drupal.t('November', {}, {'context': 'Long month name'}),
            Drupal.t('December', {}, {'context': 'Long month name'})
          ],
          monthsShort: [
            Drupal.t('Jan'),
            Drupal.t('Feb'),
            Drupal.t('Mar'),
            Drupal.t('Apr'),
            Drupal.t('May'),
            Drupal.t('Jun'),
            Drupal.t('Jul'),
            Drupal.t('Aug'),
            Drupal.t('Sep'),
            Drupal.t('Oct'),
            Drupal.t('Nov'),
            Drupal.t('Dec')
          ],
          weekdays: [
            Drupal.t('Sunday'),
            Drupal.t('Monday'),
            Drupal.t('Tuesday'),
            Drupal.t('Wednesday'),
            Drupal.t('Thursday'),
            Drupal.t('Friday'),
            Drupal.t('Saturday')
          ],
          weekdaysShort: [
            Drupal.t('Sun'),
            Drupal.t('Mon'),
            Drupal.t('Tue'),
            Drupal.t('Wed'),
            Drupal.t('Thu'),
            Drupal.t('Fri'),
            Drupal.t('Sat')
          ],
          weekdaysMin: [
            Drupal.t('Su', {}, {'context': 'day_abbr2'}),
            Drupal.t('Mo', {}, {'context': 'day_abbr2'}),
            Drupal.t('Tu', {}, {'context': 'day_abbr2'}),
            Drupal.t('We', {}, {'context': 'day_abbr2'}),
            Drupal.t('Th', {}, {'context': 'day_abbr2'}),
            Drupal.t('Fr', {}, {'context': 'day_abbr2'}),
            Drupal.t('Sa', {}, {'context': 'day_abbr2'})
          ]
        }
      );
    }
  };

  Drupal.moment = Drupal.moment || {};

  Drupal.moment.initialized = false;

}(Drupal));
