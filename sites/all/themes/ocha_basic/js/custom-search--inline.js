/**
 * @file
 * Bootstrap dropdown on search and inline search.
 */

(function ($, Drupal) {
  Drupal.behaviors.cdSearchInline = {
    attach: function (context, settings) {

      $('html').on('click', function(e) {
        //if clicked element is not your element and parents aren't your div
        if (e.target.id != 'cd-search-btn' && $(e.target).parents('.cd-search--inline').length == 0) {
          $('.cd-search--inline').removeClass('js-open');

        } else {

          $('.cd-search--inline').toggleClass('js-open');

          if ($('.cd-search--inline').hasClass('js-open')) {
            $('#edit-search-api-views-fulltext').focus();
            $('.cd-search--inline__submit').addClass('js-has-focus');
            $('.cd-search--inline__form-inner').addClass('js-has-focus');
          } else {
            $('#edit-search-api-views-fulltext').blur();
            $('.cd-search--inline__submit').removeClass('js-has-focus');
            $('.cd-search--inline__form-inner').removeClass('js-has-focus');
          }
        }
      });

    }
  };
}(jQuery, Drupal));
