(function ($) {

  /**
   * OneDrive Web picker.
   */
  Drupal.behaviors.FileChooserFieldOneDrivePicker = {
    attach: function (context, settings) {

      $('.form-type-managed-file a.one-drive-picker', context).unbind().click(function(e) {
        var $parent = $(this).parent().parent();

        var _plugin = $(this).data('plugin'); // required
        var _max_filesize = $(this).data('max-filesize');
        var _description = $(this).data('description');
        var _cardinality = $(this).data('cardinality');
        var _multiselect = $(this).data('multiselect');

        // Because there is no max files limit in OneDrive Picker
        // we have to use this fake limitation.
        var _limit = (_cardinality > 0) ? _cardinality : 100;
        if (_limit > 1) {
          _multiselect = true;
        }

        // OneDrive plugin.
        var pickerOptions = {
          success: function(file) {
            var _links = [];
            var _count = 0;
            for (var i = 0; i < file.values.length; i++) {
              if (file.values[i].size > _max_filesize) {
                alert(_description);
              }
              else {
                if (_count < _limit) {
                  _links.push(_plugin + '::::' + file.values[i].link + '@@@' + file.values[i].fileName);
                  _count++;
                }
              }
            }

            // Autosubmit (downloads the file into the file or image field)
            $parent.find('.file-chooser-field-wrapper input[type=hidden]').val(_links.join('|'));
            if (_links.length) {
              $('input.form-submit[value=Upload]', $parent).mousedown();
              $('.button', $parent).unbind().addClass('disabled').click(function(e) {
                e.preventDefault();
              });
            }
            $parent.ajaxComplete(function(event, xhr, settings) {
              $('.button', $parent).removeClass('disabled');
            });

          },

          cancel: function() {
             // handle when the user cancels picking a file
          },

          linkType: "downloadLink",
          multiSelect: (_multiselect > 0) ? true : false
        }

        OneDrive.open(pickerOptions);

        e.preventDefault();

      });

    }
  };

}(jQuery));
