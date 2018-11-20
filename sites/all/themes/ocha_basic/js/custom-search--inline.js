/**
 * @file
 * Bootstrap dropdown on search and inline search.
 */

(function ($, Drupal) {
  Drupal.behaviors.cdSearchInline = {
    attach: function (context, settings) {

      // Apply focus to input when dropdown is shown, remove when closed.
      $('.cd-search--inline').on('shown.bs.dropdown', function () {
        $(this).find('#edit-search-api-views-fulltext').focus();
      }).on('hidden.bs.dropdown', function () {
        $(this).find('#edit-search-api-views-fulltext').blur();
      });

      // Add class on submit button when input has focus, remove on blur.
      $('.cd-search--inline .cd-search--inline__input').on('focus', function(e) {
        $(this).parent().find('.cd-search--inline__submit').addClass('js-has-focus');
        $(this).parent().addClass('js-has-focus');
      }).on('blur', function(e) {
        $(this).parent().find('.cd-search--inline__submit').removeClass('js-has-focus');
        $(this).parent().removeClass('js-has-focus');
      });

    }
  };
}(jQuery, Drupal));
