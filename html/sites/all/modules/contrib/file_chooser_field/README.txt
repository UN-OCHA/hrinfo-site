This module extends File and Image fields by adding ability to upload files from third-party services such as Dropbox, Box, OneDrive, Google Drive and Instagram. The module built-in plugin API allows developers extend functionality of the module by integrating other service providers.

The module respects Drupal field settings such as file size limit, extensions, cardinality.

You have to note that this module downloads remote files and stores them in the Drupal field.

Requirements

No other dependencies all required modules are in core.

Quick Start

1. Enable the module.
2. Configure File Chooser Field settings (open admin/config/media/file-chooser-field).
3. Edit your File and Image fields and enable "Enable third party file uploads" checkbox.
4. Configure permissions.

Plugin API

1. Implement hook_file_chooser_field_plugins().
2. Create a new class by extending FileChooserFieldPlugin class (see plugins/PluginBase.php).
3. Enable the plugin (open admin/config/media/file-chooser-field).

See file_chooser_field.api.php file for all available hooks.

Note from a Developer

You might hit a wall with configuring some third-party services.
I personally hit a wall with the Google Drive and this could be a little challenging, but after researching I was able to get the right credentials.
Please if you could document Google Drive configuration I would really appreciate.

If you don't see Google Drive picker you probably missing some required steps.

- Make sure you enabled Picker API.
- Make sure you enabled Drive API.
- See README.txt for more information.

OneDrive configuration is also tricky. Please read more about it on the File Chooser Filed OneDrive plugin page.

I will try update information about plugin configuration as it comes.

And please report if you see any third-party API integration changes.

Thank you

This project is not affiliated with or otherwise sponsored by Dropbox, Google, Microsoft (OneDrive), Box or Instagram.
