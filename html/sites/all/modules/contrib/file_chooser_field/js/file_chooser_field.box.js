(function ($) {

  /**
   * Box Picker API.
   */
  Drupal.behaviors.FileChooserFieldBoxFilePicker = {
    attach: function (context, settings) {

      $('.form-type-managed-file a.box-picker', context).unbind().click(function(e) {
        var $parent = $(this).parent().parent();

        var _plugin = $(this).data('plugin'); // required
        var _max_filesize = $(this).data('max-filesize');
        var _description = $(this).data('description');
        var _cardinality = $(this).data('cardinality');
        var _multiselect = $(this).data('multiselect');

        // Because there is no max files limit in Box File Picker
        // we have to use this fake limitation.
        var _limit = (_cardinality > 0) ? _cardinality : 100;
        if (_limit > 1) {
          _multiselect = true;
        }

        // Box pluigin.
        var boxSelect = new BoxSelect({
            clientId: Drupal.settings.file_chooser_field.box_client_id,
            linkType: 'direct',
            multiselect: _multiselect
          });

        boxSelect.success(function(files) {
          var _links = [];
          var _count = 0;
          for (var i = 0; i < files.length; i++) {
            if (files[i].size > _max_filesize) {
              alert(_description);
            }
            else {
              if (_count < _limit) {
                _links.push(_plugin + '::::' + files[i].url + '@@@' + files[i].name);
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

        });

        boxSelect.launchPopup();

        e.preventDefault();

      });

    }
  };

}(jQuery));
