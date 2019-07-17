/**
 * @file
 * Bootstrap dropdown on main menu.
 */

(function ($, Drupal) {
  Drupal.behaviors.cdMenu = {
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

          // Toggle mobile menu.
          $('.cd-site-header__nav-toggle', context).once('cdMenu').on('click', function() {
            $('.cd-site-header__nav-holder').toggleClass('open');
          });

          // When bootstrap dropdown elements are clicked, close mobile menu.
          $('.cd-global-header__dropdown-btn, .cd-search_btn, .cd-search--inline_btn').on('click.bs.dropdown', function(e) {
            $('.cd-site-header__nav-holder').removeClass('open');
          });

        } else {

          // Remove class on desktop.
          $('.cd-site-header__nav-holder').removeClass('open');
        }
      }

    }
  };
}(jQuery, Drupal));
