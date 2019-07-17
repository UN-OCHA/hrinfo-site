(function ($) {

  /**
   * Instagram Photo Picker.
   */
  Drupal.behaviors.FileChooserFieldInstagram = {
    attach: function (context, settings) {

      $('.form-type-managed-file a.instagram-picker', context).unbind().click(function(e) {
        var $parent = $(this).parent().parent();

        // Drupal field information.
        var _plugin = $(this).data('plugin'); // required
        var _max_filesize = $(this).data('max-filesize');
        var _description = $(this).data('description');
        var _cardinality = $(this).data('cardinality');
        var _multiselect = $(this).data('multiselect');
        var _picker_url = Drupal.settings.file_chooser_field_instagram.loginUrl;

        // Generate unique window ID.
        var _window_id = Math.floor(
            Math.random() * 0x10000 /* 65536 */
          ).toString(16);

        // Set window ID. This will help me to find this button from a parent window.
        $(this).addClass('popup-opened').addClass('window-id-' + _window_id);

        // Open a new window.
        var InstagramPicker = window.open(_picker_url, _window_id, "directories=no,titlebar=no,toolbar=no,location=no,status=no,menubar=no,width=810,height=650");

        InstagramPicker.onbeforeunload = function (event) {

          // Some file picker plugins don't have an option to limit number of
          // choosable files. You have to add this to add limitation.
          var _limit = (_cardinality > 0) ? _cardinality : 100;
          if (_limit > 1) {
            _multiselect = true;
          }

          // File objects.
          var _file_string = InstagramPicker.document.getElementById('files').innerHTML;
          var files = _file_string.split('|');

          if (_file_string !== undefined && _file_string != '' && _file_string != null) {

            var _links = [];
            var _count = 0;

            for (var i = 0; i < files.length; i++) {
              if (_count < _limit) {
                // [phpClassName]:::url. See download() method for more details.
                _links.push(_plugin + '::::' + files[i]);
                _count++;
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

          }

          // Remove identifier class name from the button.
          $('a.instagram-picker.window-id-' + InstagramPicker.name)
            .removeClass('popup-opened')
            .removeClass('window-id-' + InstagramPicker.name);
          return message;
        }

        e.preventDefault();

      });

    }
  };

}(jQuery));
