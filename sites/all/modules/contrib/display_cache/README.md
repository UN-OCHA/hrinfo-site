# SUMMARY
Display Cache provides a simple way to cache the html of a specific entity rendered in a specific view mode.
The cache entry will only be flushed if the entity is changed.

For a full description of the module, visit the [display cache project page](https://drupal.org/project/display_cache)
Please submit bug reports and feature suggestions to the modules issue queue.

# REQUIREMENTS
  * [Entity API](http://drupal.org/project/entity)

# INSTALLATION
Install as usual, see [drupal.org](http://drupal.org/node/70151) for further information.

# CONFIGURATION

## Administer Display Cache
Configure user permissions in Administration » People » Permissions.
Grants the permission to administer display cache settings for displays and
to flush the display cache caches.

    Note that the menu items displayed in the administration menu depend on the
    actual permissions of the viewing user. For example, the "People" menu item
    is not displayed to a user who is not a member of a role with the "Administer
    users" permission.

## Customize the display cache settings for displays.

  * Call a display settings page. For example:
    Home » Administration » Structure » Content types » Article » Manage Display

  * Display Cache Display Settings
    Configure the caching method for this display.

  * Display Cache Field Settings
    Configure the caching mechanism for each field. You can only choose lower
    granularity than configured in Display Cache Display Settings.

## Flush Display Cache

  * Call Home » Administration » Configuration » Development » Display Cache
    and submit the form.

## Circumvent the display cache (Programmatically)

There might be some cases where you do not want the cached entity in your module
or theme or wherever.

There is a programmatically way to prevent display cache from fetching the
cached version of an entity view.

Simply attach the constant `DISPLAY_CACHE_VIEW_MODE_CACHE_IGNORE_SUFFIX` to your
required view mode and display cache will not interfere.

Please be aware that this feature should only be used by programmers INSIDE the
code.

*Do not try to use this feature via the admin interface.*

## Pitfalls

Please be aware that JS, CSS and libraries attached in view hooks via
drupal_add_js(), drupal_add_css() or drupal_add_library() are not reattached
if the entity view is served from display cache.
To accomplish this, you need to attach it to the node render array directly via
the '#attached' key. That way the JS, CSS and libraries are stored along with
the rendered view mode's HTML.

Setting the granularity to a very high level for example "Cache per URL and per
User" can lead to useless caching for big sites, because depending on the
caching mechanismens the lookup gets really slow or older cached items get
thrown away.
