/**
 * @file
 * Bootstrap dropdown on search and inline search.
 */

(function ($, Drupal) {
  Drupal.behaviors.cdSearchInline = {
    attach: function (context, settings) {

      // Media query event handler.
      if (matchMedia) {
        const mq = window.matchMedia("(max-width: 1023px)");
        // Add event listener to media query that fires when a change in viewport width is detected.
        mq.addListener(WidthChange);
        // Call handler to initialise on page load.
        WidthChange(mq);
      }

      function WidthChange(mq) {

        if (mq.matches) {

          $('.cd-search--inline_btn', context).once('cdSearchInline').on('click', function (e) {

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

            // When bootstrap dropdown elements are clicked, close search.
            $('.cd-global-header__dropdown-btn, .cd-site-header__nav-toggle').on('click.bs.dropdown', function (e) {
              $('.cd-search--inline').removeClass('js-open');
            });

          });

        } else {

          // Remove classes on desktop.
          $('.cd-search--inline').removeClass('js-open');
          $('.cd-search--inline__submit').removeClass('js-has-focus');
          $('.cd-search--inline__form-inner').removeClass('js-has-focus');

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
      }
    }

  };
}(jQuery, Drupal));
