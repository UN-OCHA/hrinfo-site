
-- SUMMARY --

Allows entities to be translated into different languages.

For a full description of the module, visit the project page:
  http://drupal.org/project/entity_translation
To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/entity_translation


-- REQUIREMENTS --

None.


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* @todo


-- USAGE --

* @todo


-- DEVELOPERS --

--- PHP7 Compatibility detection ---

Use PHP Code Sniffer (via coder) with the PHPCompatibility sniffs installed.

* https://www.drupal.org/project/coder
* https://github.com/PHPCompatibility/PHPCompatibility

Once phpcs is installed, a simple way to add PHPCompatibility is:

* Run 'phpcs -i' to confirm the current recognised coding standards.
  Assuming that PHPCompatibility is not already listed...

* Run 'phpcs --config-show' and take note of the "installed_paths" value.

* Run 'composer require phpcompatibility/php-compatibility'

* Establish the absolute /path/to/vendor/phpcompatibility/php-compatibility
  which you should now have somewhere.

* Run 'phpcs --config-set installed_paths OLD,NEW' where OLD is the original
  value, and NEW is the php-compatibility path.

* Run 'phpcs -i' to confirm that PHPCompatibility has been added to the list
  of coding standards.

* Run 'phpcs --standard=PHPCompatibility <files>' to check <files>


--- PHP7 Compatibility hints ---

func_get_args() should be placed at the beginning of a method or function,
  before any modifications to the function's arguments take place. Its value
  should be assigned to a locally scoped variable - usually named $args by
  convention - to be used inside the function as needed. This is due to
  changes in PHP 7.0 and onwards.
  @see http://php.net/manual/en/function.func-get-args.php#refsect1-function.func-get-args-notes


-- CONTACT --

Current maintainers:
* Francesco Placella (plach) - http://drupal.org/user/183211
* Daniel F. Kudwien (sun) - http://drupal.org/user/54136
* Stefanos Petrakis (stefanos.petrakis) - https://www.drupal.org/u/stefanospetrakis

