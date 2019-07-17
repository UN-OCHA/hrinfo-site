/**
 * @file
 * Handles filtering and country option interaction on instance settings pages.
 */

(function ($) {
  Drupal.Phone = Drupal.Phone || {};

  /**
   * Filters checkboxes based on their label.
   * This code is shamelessly taken from checkbox_filter.
   */
  Drupal.Phone.filter = function () {
    var $field = $(this);

    // Go over each item looking for a match.
    $field.parent().parent().find('.form-checkboxes .form-item').each(function () {
      var $option = $(this);
      var label = Drupal.Phone.trim($option.text());
      if (label.toUpperCase().indexOf($field.val().toUpperCase()) < 0) {
        $option.hide();
      }
      else {
        $option.show();
      }
    });
  };

  /**
   * Trims whitespace from strings.
   */
  Drupal.Phone.trim = function(str) {
	  var	str = str.replace(/^\s\s*/, ''),
		  ws = /\s/,
		  i = str.length;
	  while (ws.test(str.charAt(--i)));
	  return str.slice(0, i + 1);
  };

  /**
   * Check/Uncheck all checkboxes.
   */
  Drupal.Phone.checkall = function(e) {
    var $field = $(this);
    var $checkboxes = $('.form-checkboxes .form-item:visible .form-checkbox', $field.parent().parent());

    var checked = ($field.text() == Drupal.t('Select all'));
    if (checked) {
      $checkboxes.attr('checked', 'checked');
      $field.text(Drupal.t('Deselect all'));
    }
    else {
      $checkboxes.attr('checked', '');
      $field.parents('.phone-settings')
        .siblings('.form-item-instance-settings-country-options-enable-default-country')
        .find('.form-checkbox')
        .trigger('change');
      $field.text(Drupal.t('Select all'));
    }
  };

  /**
   * Update the flagged default country when it changes.
   */
  Drupal.Phone.defaultCountryChange = function(e) {
    var $this = $(this);
    var $span = $('<span class="phone-default-country-label"></span>').append(Drupal.t('Default'));
    var $fieldset = $this.parents('.form-item:first').siblings('fieldset.phone-settings');

    // Find the checkbox we want to check and flag.
    var $box = $fieldset
      .find('.form-item-instance-settings-country-options-country-codes-country-selection-'
        + $this.val() + ' .form-checkbox');

    // Remove any previously set default country flags.
    $fieldset.find('.phone-default-country')
      .removeClass('phone-default-country')
      .find('span.phone-default-country-label').remove();

    // Check the box, and add the flag.
    $box.attr('checked', 'checked')
      .parents('.form-item:first')
      .addClass('phone-default-country')
      .append($span);
  };

  /**
   * Makes sure the default country stays checked.
   */
  Drupal.Phone.keepDefaultCountry = function () {
    var $this = $(this);

    if ($this.parents('.phone-default-country:first').length) {
      $this.attr('checked', 'checked');
    }
  };

  /**
   * Adds or removes the default country flag based on the state
   * of enable default country.
   */
  Drupal.Phone.defaultCountryEnableToggle = function () {
    var $this = $(this);

    if ($this.is(':checked')) {
      $this
        .parents('.form-item-instance-settings-country-options-enable-default-country:first')
        .siblings('.form-item-instance-settings-country-options-default-country')
        .find('select').trigger('change');
    }
    else {
      $this.parents('.form-item-instance-settings-country-options-enable-default-country:first')
        .siblings('.phone-settings')
        .find('.phone-default-country').removeClass('phone-default-country')
        .find('span.phone-default-country-label').remove();
    }
  };

  /**
   * Attach a filtering textfield to checkboxes
   * and handle setting/unsetting of the default country flag.
   */
  Drupal.behaviors.Phone = {
    attach: function(context) {
      // Add a filter and checko all option for country selection.
      var $form = $('<div class="form-item container-inline">'
          + '  <label>' + Drupal.t('Filter') + ':</label> '
          + '  <input class="phone-filter form-text" type="text" size="30" />'
          + '  <a class="phone-check" style="margin-left: 1em;" href="javascript://">'
          + Drupal.t('Select all') + '</a>'
          + '</div>');

      $('input.phone-filter', $form).bind('keyup', Drupal.Phone.filter);
      $('a.phone-check', $form).bind('click', Drupal.Phone.checkall);
      $('.phone-settings .form-item-instance-settings-country-options-country-codes-country-selection', context)
        .before($form);

      // Update the default country selection in the country selection checkboxes.
      $('.form-item-instance-settings-country-options-default-country select', context)
        .change(Drupal.Phone.defaultCountryChange);

      // Make sure the default country stays checked.
      $('.phone-settings .form-item-instance-settings-country-options-country-codes-country-selection .form-checkbox', context)
        .change(Drupal.Phone.keepDefaultCountry);

      // Handle default country triggers on enable or disable of default country.
      $('.form-item-instance-settings-country-options-enable-default-country .form-checkbox', context)
        .change(Drupal.Phone.defaultCountryEnableToggle);

      if ($('.form-item-instance-settings-country-options-enable-default-country .form-checkbox', context).is(':checked')) {
        $('.form-item-instance-settings-country-options-default-country select', context).trigger('change');
      }
    }
  };
})(jQuery);

