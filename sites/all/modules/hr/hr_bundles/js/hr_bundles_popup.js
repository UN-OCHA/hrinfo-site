(function($) {
Drupal.behaviors.hrBundlesPopup = {
  displayed: false,
  attach: function (context, settings) {
    var that = this;
    $('#edit-field-bundles select').change(function() {
      var selected = $(this).find(':selected').length;
      if (selected > 3 && that.displayed == false) {
        $('#hr_bundles_multitagging').modal();
        that.displayed = true;
      }
    });
  }
}
})(jQuery);
