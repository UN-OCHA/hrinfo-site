CONTENTS OF THIS FILE
---------------------
 * Introduction
 * Usage
 * Support
 * Compatibility
 * Authors
 * Sponsors


INTRODUCTION
------------

Adds an extra "Cookie" field to the Language Negotiation settings, allowing the
language to be set according to a cookie.

The cookie name & expiration date are configurable in the settings page.


USAGE
------

- Enable the module and go to: Administration » Configuration » Regional and
  language » Languages
- Enable "Cookie" detection method and re-arrange it as you see fit. Recommended
  setup is: URL -> Session -> Cookie
- For the cookie to be set properly on cached pages, the variable
  "page_cache_invoke_hooks" has to be set to TRUE.
  This can be done by adding the following line to your settings.php file:
  $conf['page_cache_invoke_hooks'] = TRUE;


SUPPORT
-------

If you find a bug or have a feature request please file an issue:

http://drupal.org/node/add/project-issue/language_cookie


COMPATIBILITY
-------------

A lot of work has gone into ensuring maximum compatibility with other contrib
modules. If you find a bug please use the issue tracker for support. Thanks!


AUTHORS
--------

* Alex Weber (alexweber)
  http://drupal.org/user/850856 & http://www.alexweber.com.br


SPONSORS
---------

This project is made possible by Webdrop (http://webdrop.net.br)
