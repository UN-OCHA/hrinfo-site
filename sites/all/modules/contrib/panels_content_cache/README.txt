Panels Content Cache
--------------------
This module provides a cache plugin for Panels, Panelizer and other
CTools-based display systems. The primary goal of the module is to cache panes
and pages indefinitely until content belonging to one of the selected content
types is either created, modified or deleted, at which point that pane is
reloaded.

This version of the module only works with Panels 7.x-3.4 and newer.


Features
------------------------------------------------------------------------------
The primary features include:

* Support for all Page Manager (CTools), Panels and Panelizer displays.

* Clear the cache for the configured pane when content belonging to selected
  content types is created, modified or deleted.

* Supports the core Comment module, so comments posted to one of the configured
  content types will also clear the caches.

* Additional options to fine tune the cache granularity:

  * Current URL.
    * Provides several options to accommodate different scenarios.

  * Page arguments.

  * Panels contexts.

  * Active user.
    * This will create a separate cache object for each user and is usually
      unnecessary.

  * Active user's roles.
    * This allows for creating a separate cache instance based upon the current
      user's roles. This is particularly useful when using the Contextual
      module, to avoid the context menus showing for the wrong users.
    * It is possible to select which roles will be given the same cached object
      as the anonymous user; it is suggested to select the "Authenticated user"
      role on scenarios when a "normal" logged in user would not gain any extra
      access to the content.
    * In the interest of performance, it is possible to trigger caching based
      on a complete list of all a given user's roles, just the first one or
      just the last one; the default is to consider all of a user's roles.

  * The current domain, as configured through Domain Access.


Related modules
------------------------------------------------------------------------------
Some available modules are similar or related to Panels Content Cache:

* Cache Consistency
  https://www.drupal.org/project/cache_consistent
  Sites using something other than the database for cache storage, e.g.
  memcached, may run into a bug in Drupal core that triggers a race condition
  in the cache_field bin. This module provides a work-around and is in use
  on drupal.org. See https://www.drupal.org/node/1679344 for further details.

* Panels Hash Cache
  https://www.drupal.org/project/panels_hash_cache


Credits / Contact
------------------------------------------------------------------------------
Currently maintained by Damien McKenna [1]. Originally written by Graham Taylor [2].

Ongoing development is sponsored by Mediacurrent [3].

The best way to contact the maintainers is to submit an issue, be it a support
request, a feature request or a bug report, in the project issue queue:
  http://drupal.org/project/issues/panels_content_cache


References
------------------------------------------------------------------------------
1: https://www.drupal.org/u/DamienMcKenna
2: https://www.drupal.org/u/tayzlor
3: http://www.mediacurrent.com/
