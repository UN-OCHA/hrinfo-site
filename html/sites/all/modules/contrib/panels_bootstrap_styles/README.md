-- SUMMARY --

The Panels Bootstrap Styles module provides Bootstrap styles for Panels regions
and panes.

For a full description of the module, visit the project page:
  https://drupal.org/project/panels_bootstrap_styles

To submit bug reports and feature suggestions, or to track changes:
  https://drupal.org/project/issues/panels_bootstrap_styles


-- REQUIREMENTS --

Panels
A Bootstrap theme (with Bootstrap version 3.x)


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/1897420 for further information.


-- CONFIGURATION --

To apply a style to a panel region, click the widget for the region and select
Style > Change

* Supported region styles

  - Accordion

    The accordion wrapper divs and class and will be placed around all panes
    in the region. Each pane will need to be styled as a "Bootstrap Style: Panel"
    and the collapsible option must be set to get the accordion behavior.

  - Tabs

    The title of every pane in the region will become a tab. Options are
    available to select tab or pill style and to display the tabs as the
    default, stacked, or justified.

  - Jumbotron

    Renders region as Bootstrap jumbotron component.

  - Panel

    Renders region as Bootstrap panel component. Style modifiers allow the
    default, primary, success, info, warning, or danger classes.

  - Well

    Renders region as Bootstrap well component.

To apply a style to a panel pane, click the widget for the pane and select
Style > Change

* Supported pane styles

  - Alert

    Renders pane as Bootstrap alert component. Style modifiers allow the default,
    primary, success, info, warning, or danger classes.

  - Jumbotron

    Renders pane as Bootstrap jumbotron component.

  - Panel

    Renders pane as Bootstrap panel component. Style modifiers allow the default,
    primary, success, info, warning, or danger classes. Optional collapsible and
    default collapsed state can be set (these must be set to use region accordion
    style).

  - Well

    Renders pane as Bootstrap well component.

  Additional options can be set to hide regions or panes on device types.
  Additional float classes can be applied.
