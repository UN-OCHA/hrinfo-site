/**
 * @file
 * Behaviors and utility functions for administrative pages.
 *
 * @author Jim Berry ("solotandem", http://drupal.org/user/240748)
 */

(function ($) {

/**
 * Provides summary information for the vertical tabs.
 */
Drupal.behaviors.gtmInsertionSettings = {
  attach: function (context) {
    if (typeof jQuery.fn.drupalSetSummary == 'undefined') {
      // This behavior only applies if drupalSetSummary is defined.
      return;
    }

    // Pass context parameters to outer function.
    function toggleValuesSummary(element, plural, adjective) {
      // Return a callback function as expected by drupalSetSummary().
      return function (context) {
        var str = '';
        var toggle = $('input[type="radio"]:checked', context).val();
        var values;
        if (element == 'checkbox') {
          values = $('input[type="checkbox"]:checked + label', context).length;
        }
        else {
          var values = $('textarea', context).val();
        }
        if (toggle == 'exclude listed') {
          if (!values) {
            str = 'All !plural';
          }
          else {
            str = 'All !plural except !adjective !plural';
          }
        }
        else {
          if (!values) {
            str = 'No !plural';
          }
          else {
            str = 'Only !adjective !plural';
          }
        }
        const args = {'!plural': plural, '!adjective': adjective};
        return Drupal.t(Drupal.formatString(str, args));
      }
    }

    var element, plural, adjective;

    element = 'checkbox';
    adjective = 'selected';
    var selectors = ['role', 'domain', 'language', 'realm'];
    for (const selector of selectors) {
      plural = selector + 's';
      $('fieldset#edit-' + selector, context).drupalSetSummary(toggleValuesSummary(element, plural, adjective));
    }

    element = 'textarea';
    adjective = 'listed';
    selectors = ['path', 'status'];
    for (const selector of selectors) {
      plural = selector.replace('status', 'statuse') + 's';
      $('fieldset#edit-' + selector, context).drupalSetSummary(toggleValuesSummary(element, plural, adjective));
    }
  }
};

})(jQuery);
