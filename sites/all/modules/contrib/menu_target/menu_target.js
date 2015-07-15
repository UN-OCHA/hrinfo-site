
(function ($) {

  /**
   * Attaches 'open in new window' behavior to links with the 'target-blank' class.
   * This is used as a replacement of the regular 'target' attribute which is deprecated
   * since XHTML 1.1.
   */
  Drupal.behaviors.targetBlank = {
    attach: function (context, settings) {

      $('a.target-blank', context).once('target-blank', function () {
        $(this).click(function() {
          window.open(this.href);
          return false;
        });
      });
    }
  };

})(jQuery);
