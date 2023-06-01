(function ($) {

  /**
   * File Chooser Field helper.
   */
  Drupal.behaviors.FileChooserField = {
    attach: function (context, settings) {

      // Hide Upload element. Replace it with custom options.
      $('.form-type-managed-file', context).each(function() {
        if ($(this).find('.file-chooser-field-wrapper').length) {
          $(this).find('input[type=file]').hide();
          $(this).find('input[type=submit]').hide();
          $(this).find('input[name*=remove]').show();
        }
      });

      // Trigger file upload browser
      $('.form-type-managed-file a.browse', context).unbind().click(function(e) {
        var $parent = $(this).closest('.form-managed-file');
        $parent.find('input[type=file]').click();
        e.preventDefault();
      });

      $('.form-type-managed-file input.form-file', context).change(function() {
        var $parent = $(this).parent().parent();
        if ($parent.find('.file-chooser-field-wrapper').length) {
          setTimeout(function() {
            if(!$('.error', $parent).length) {
              $('input.form-submit[value=Upload]', $parent).mousedown();
              $('.button', $parent).unbind().addClass('disabled');
            }
          }, 100);
        }
      });

    }
  };

}(jQuery));
