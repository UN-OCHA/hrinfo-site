(function ($) {

  // The Client ID obtained from the Google Developers Console. Replace with your own Client ID.
  var clientId = Drupal.settings.file_chooser_field.google_client_id;

  // Replace with your own App ID. (Its the first number in your Client ID)
  var appId = Drupal.settings.file_chooser_field.google_app_id;

  // Scope to use to access user's Drive items.
  var scope = Drupal.settings.file_chooser_field.google_scope;

  var pickerApiLoaded = false;
  var oauthToken;
  var _parent_container;

  function onAuthApiLoad() {
    window.gapi.auth.authorize({
        'client_id' : clientId,
        'scope'     : scope,
        'immediate' : false
      },
      handleAuthResult
    );
  }

  function onPickerApiLoad() {
    pickerApiLoaded = true;
    createPicker();
  }

  function handleAuthResult(authResult) {
    if (authResult && !authResult.error) {
      oauthToken = authResult.access_token;
    }
    createPicker();
  }

  // Create and render a Picker object for searching images.
  function createPicker() {
    if (pickerApiLoaded && oauthToken) {
      var view = new google.picker.View(google.picker.ViewId.DOCS);

      var _plugin = _parent_container.find('a.google-picker').data('plugin'); // required
      var _max_filesize = _parent_container.find('a.google-picker').data('max-filesize');
      var _description = _parent_container.find('a.google-picker').data('description');
      var _extensions = _parent_container.find('a.google-picker').data('file-extentions');
      var _cardinality = _parent_container.find('a.google-picker').data('cardinality');

      view.setMimeTypes(_extensions);
      var picker = new google.picker.PickerBuilder()
        .enableFeature(google.picker.Feature.NAV_HIDDEN)
        .enableFeature(google.picker.Feature.MULTISELECT_ENABLED)
        .setAppId(appId)
        .setOAuthToken(oauthToken)
        .addView(view)
        // Respect Drupal field `Number of values` value.
        .setMaxItems((_cardinality > 0) ? _cardinality : 100)
        .addView(new google.picker.DocsUploadView())
        .setCallback(function(data) {
          if (data.action == google.picker.Action.PICKED) {
            var _links = [];
            for (var i = 0; i < data.docs.length; i++) {
              if (data.docs[i].sizeBytes > _max_filesize) {
                alert(_description);
              }
              else {
                _links.push(_plugin + '::::' + data.docs[i].id + '@@@' + data.docs[i].name + '@@@' + oauthToken);
              }
            }

            // Autosubmit (downloads the file into the file or image field)
            _parent_container.find('.file-chooser-field-wrapper input[type=hidden]').val(_links.join('|'));
            if (_links.length) {
              $('input.form-submit[value=Upload]', _parent_container).mousedown();
              $('.button', _parent_container).unbind().addClass('disabled');
            }
            _parent_container.ajaxComplete(function(event, xhr, settings) {
              $('.button', _parent_container).removeClass('disabled');
            });

          }
        })
        .build();
      picker.setVisible(true);
    }
  }

  /**
   * Google Picker API
   */
  Drupal.behaviors.FileChooserFieldGoogleDriveAPI = {
    attach: function (context, settings) {

      $('.form-type-managed-file a.google-picker', context).unbind().click(function(e) {
        var $parent = $(this).parent().parent();
        _parent_container = $parent;

        // Google Drive plugin.
        gapi.load('auth', {'callback': onAuthApiLoad});
        if (pickerApiLoaded === false) {
          gapi.load('picker', {'callback': onPickerApiLoad});
        }

        e.preventDefault();

      });

    }
  };

}(jQuery));
