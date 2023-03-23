INTRODUCTION
------------
Allows you to override solr connection settings on an environment (site) basis,
via your settings.php without editing servers managed in features.

REQUIREMENTS
------------
* search_api_solr module

CONFIGURATION
-------------
The module has no menu or modifiable settings. There is no configuration. When
enabled, you can set your override values in your settings.php file.
Search api will automatically pick up your values, but make sure to clear your
cache first.

EXAMPLE
-------
You can add following example to your settings.php file.

$conf['search_api_solr_overrides'] = array(
  'solr-server-id' => array(
    'name' => 'Solr Server (Overridden)',
    'options' => array(
      'host' => '127.0.0.1',
      'port' => 8983,
      'path' => '/solr',
    ),
  ),
);

MAINTAINERS
-----------
Current maintainers:
* nick_schuch - https://www.drupal.org/u/nick_schuch
* cafuego - https://www.drupal.org/u/cafuego

This project has been sponsored by:
* PreviousNext - http://www.previousnext.com.au
