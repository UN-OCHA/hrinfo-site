/**
 * @file
 * Bootstrap dropdown on search.
 */

(function ($, Drupal) {
  Drupal.behaviors.cdSearch = {
    attach: function (context, settings) {

      // Apply focus to input when dropdown is shown.
      $('.cd-search').on('shown.bs.dropdown', function () {
        $(this).find('#cd-search').focus();
      }).on('hidden.bs.dropdown', function () {
        $(this).find('#cd-search').blur();
      });

      $('.cd-search__input').on('focus', function (e) {
        $(this).parents('.cd-search__form-inner').find('.cd-search__submit').addClass('js-has-focus');
      }).on('blur', function (e) {
        $(this).parents('.cd-search__form-inner').find('.cd-search__submit').removeClass('js-has-focus');
      });

    }
  };
}(jQuery, Drupal));
