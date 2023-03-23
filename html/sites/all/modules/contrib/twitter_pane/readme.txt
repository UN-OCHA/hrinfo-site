CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Usage
 * Theming

INTRODUCTION
------------

Twitter Pane is a lightweight module which allows administrators to create
panes which display embedded timelines.

This module is a fork of the Twitter Block
(http://drupal.org/project/twitter_block) module which uses the Drupal core
block module for embedding timelines.

Twitter Pane will never provide advanced Twitter integration such as OAuth
user authentication or the ability to tweet from Drupal. These capabilities are
provided by other modules such as Twitter (http://drupal.org/project/twitter).

REQUIREMENTS
------------

Twitter Pane has one dependency, Panels: http://drupal.org/project/panels.


INSTALLATION
------------

Twitter Pane can be installed via the standard Drupal installation process
(http://drupal.org/documentation/install/modules-themes/modules-7).


USAGE
-----

Each Twitter pane requires a unique widget ID which determines, among
other things, the source (user timeline, favourites, list or search) of the
tweets to display.

You can view a list of your existing embedded timeline widgets (and their
widget IDs) or create new embedded timeline widgets by visiting
https://twitter.com/settings/widgets (make sure that you're logged in).

You can determine a widget's ID by editing it and inspecting the URL (which
should be in the form of https://twitter.com/settings/widgets/WIDGET_ID/edit)
or by looking at the widget's embed code (look for
data-widget-id="WIDGET_ID").

Theming
-------

Embedded Timelines offer a number of customization options such as theme, layout
and border color but, due to the way embedded timelines are implemented, custom
theming using CSS can be difficult.

To add custom CSS to embedded timelines check out the
(http://github.com/kevinburke/customize-twitter-1.1) Customize Twitter project.
