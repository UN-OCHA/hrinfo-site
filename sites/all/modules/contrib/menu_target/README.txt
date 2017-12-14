Menu Target
================================================================================

INTRODUCTION:
--------------------------------------------------------------------------------

Allows privileged users to choose wether or not to open menu items in a new
window. When enabled, users who have access to add or edit menu items, are
provided the possibility to choose if the menu items should be opened in a new
window or in the same window.


REQUIREMENTS:
--------------------------------------------------------------------------------

This module does not depend on other modules, however it would be useless
without core's menu module.


INSTALLATION:
---------------------------------------------------------------------------

Install as usual, see http://drupal.org/node/70151 for further information.


CONFIGURATION:
--------------------------------------------------------------------------------
There are no configuration options for this module.


TECHNICAL DESCRIPTION:
--------------------------------------------------------------------------------

This module basically only serves hook_form_alters in order to change the form
structures build in node_form() and form_menu_configure(). When a menu item is
configured to be opened in a new window, a 'target' attribute with a value of
'_blank' will be added to the rendered menu item.

To avoid XHTML validation errors for the deprecated target attribute, it is also
possible to use an JavaScript equivalent for opening a new window. This can be
configured at admin/structure/menu/settings.
