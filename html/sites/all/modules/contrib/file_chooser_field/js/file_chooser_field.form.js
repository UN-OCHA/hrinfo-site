(function ($) {

  /**
   * File Chooser Field Config Form helper.
   */
  Drupal.behaviors.FileChooserFieldConfigForm = {
    attach: function (context, settings) {

      var _enabled_plugins = Drupal.settings.file_chooser_field.enabled_plugins;

      for (var i = 0; i < _enabled_plugins.length; i++) {

        var _plugin_name = _enabled_plugins[i].replace('_', '-');

        $('fieldset#edit-' + _plugin_name, context).drupalSetSummary(function (context) {
          if ($('.form-item input[id^="edit-"][id$="-status"]:checked', context).length) {
            return Drupal.t('Enabled');
          }
          else {
            return Drupal.t('Disabled');
          }
        });

      }

    }
  };

}(jQuery));
