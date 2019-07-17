(function ($) {

  /**
   * Box Picker API.
   */
  Drupal.behaviors.FileChooserFieldExample = {
    attach: function (context, settings) {

      $('.form-type-managed-file a.example-picker', context).unbind().click(function(e) {
        var $parent = $(this).parent().parent();

        // Drupal field information.
        var _plugin = $(this).data('plugin'); // required
        var _max_filesize = $(this).data('max-filesize');
        var _description = $(this).data('description');
        var _cardinality = $(this).data('cardinality');
        var _multiselect = $(this).data('multiselect');

        // Some file picker plugins don't have an option to limit number of
        // choosable files. You have to add this to add limitation.
        var _limit = (_cardinality > 0) ? _cardinality : 100;
        if (_limit > 1) {
          _multiselect = true;
        }

        // File objects.
        var files = [{
          name: 'patagonia.jpg',
          url: 'http://www.umag.cl/vcm/wp-content/uploads/2015/02/150953_Courconnect.jpg',
        }];

        var _links = [];
        var _count = 0;

        for (var i = 0; i < files.length; i++) {
          if (files[i].size > _max_filesize) {
            alert(_description);
          }
          else {
            if (_count < _limit) {
              // [phpClassName]:::url@@@filename. See download() method for more details.
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

        e.preventDefault();

      });

    }
  };

}(jQuery));
