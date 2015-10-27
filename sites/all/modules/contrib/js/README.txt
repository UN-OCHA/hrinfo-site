------------------------------------------------------------------------------
  js module Readme
  http://drupal.org/project/js
------------------------------------------------------------------------------

Contents:
=========
1. ABOUT
2. TECHNICAL
3. INSTALLATION
4. MODULE INTEGRATION API
5. CREDITS

1. ABOUT
========

JavaScript callback handler is an interim solution for high-performance server 
requests including (but not limited to) AHAH, AJAX, JSON, XML, etc.

Note that this module does nothing on itself, only install it if another module 
leverages its functionality and instructs you so.

By copying the included js.php front controller to Drupal's root directory, 
setting up clean URLs, and adding an Apache RewriteRule (see README for full 
installation instructions), any JavaScript code is able to retrieve information 
from Drupal at lightning speed.

2. PERFORMANCE
==============

JavaScript callback handler is an interim solution for high-performance querying
of contents including (but not limited to) AHAH, AJAX, JSON, XML, etc.

Apache benchmarks speak for itself:

Using index.php as usual:
  ab -n20 -c1 http://example.com/index.php?q=js/mymodule/callback
  Requests per second: 2.24 [#/sec] (mean)
  Time per request:    446.846 [ms] (mean)

Using js.php:
  ab -n20 -c1 http://example.com/js.php?q=js/mymodule/callback
  Requests per second: 16.84 [#/sec] (mean)
  Time per request:    59.371 [ms] (mean)

Note that this module does nothing on itself.

For a full description visit the project page:
  http://drupal.org/project/js
Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/js

3. TECHNICAL
============

This module is not really one. Actually it is mainly a conditional replacement
for Drupal's index.php based on Apache .htaccess directives.

With mod_rewrite enabled ("clean urls"), it catches all calls to callback
paths starting with "js/" and passes them to a reduced loader instead of
the default index.php file. Invoking only the explicitely defined dependencies
instead of a complete Drupal load, it saves lots of processing time and thus
speeds up small Ajax requests.

4. INSTALLATION
===============

* Install as usual, see http://drupal.org/node/70151 for further information.

* Copy the js.php file from the module to the root directory 
  of your Drupal installation (the place where your Drupal .htaccess and 
  index.php is located).

To enable clean URL support (optional):

* Enable clean URLs in drupal at admin/settings/clean-urls

For Apache:
* Goto the configuration page: admin/config/development/performance/js.

* Add the lines of .htaccess code from the configuration page in front of the 
  existing RewriteRules in your .htaccess file.

For nginx:
* The JS module is supported out of the box via http://drupal.org/node/1876418

Any other server:
* Make sure any request starting with /js/ is forwarded to js.php.

5. MODULE INTEGRATION API
=========================

This module requires your server to point all paths starting with js/ to js.php
rather than index.php. See above for how to do this in apache.

To integrate your modules, they must point to specific callback paths:
The 2nd argument after the mandatory initial js/ determines the implementing
module, which must implement hook_js() for security reasons.

Apart from security, modules may also specify additionally required includes 
files and module dependencies to load. Apart from security, modules may also 
specify another bootstrap level than the default DRUPAL_BOOTSTRAP_DATABASE, 
and additionally required includes files and module dependencies to load.

As an example, we'll let example.module expose its function
example_somefunction() to js.php. Its hook_js() implementation might look like
this (see the api documentation for a full explanation):

<code>
  function example_js() {
    return array(
      'path' => array(
        'callback'     => 'example_somefunction',
        'includes'     => array('theme', 'unicode'),
        'dependencies' => array('locale', 'filter', 'user'),
        'bootstrap'    => DRUPAL_BOOTSTRAP_CONSTANT,
        'file'         => 'includes/example.inc',
        'access arguments' => array('e.g. permission'),
        'access callback'  => 'callback function',
        'page arguments'  => array(),
        'skip_hook_init' => FALSE,
      ),
    );
  }
</code>

- Handling -

The hook_js() implementation above makes JS accept the following URL:
  http://example.com/js/example/somefunction.
                        ^       ^
           module name -|       |
                info array key -|

When called, it loads the requested include files and modules and calls the
callback function.

You can optionaly set the page arguments which are to be passed to the callback.
It only support parts of the path (integer, starting with 0). If no page 
arguments are passed all the arguments that are left after the valid callback \
are passed as arguments. IE: when you have a callback of 'example/dosomething' 
and the url for this is /js/example/example/dosomething/further/arguments the 
callback will receive 'further' and 'arguments' as the values for the first and 
second parameter.

The path can be a complex path, containing simple wildcards (no auto loading 
support though) and slashes. It follows the same logic as the 
As stated above, js.php bootstraps Drupal to DRUPAL_BOOTSTRAP_DATABASE and 
includes the following inc files: bootstrap.inc, common.inc, locale.inc, 
module.inc, path.inc, unicode.inc, this means that url(), l(), and t() functions 
are available (t() lacks translation though, since that would require 
locale.module to be loaded. This can be easily "fixed" by adding locale to the 
dependencies array). Theme functions and potentially required functions of other 
modules, however, are not available by default, which is the main reason for the 
speed gain of js.php. 

- includes and dependencies -

The js handler loads the least amount of code to function. This has the 
effect that not all modules are loaded that might be required to make your 
callback work. For example, when the overlay module is enabled the user module 
needs to be enabled because it uses the user_access method.
This can be fixed using the option dependencies or includes. If your callback 
throws an error indicating it's missing a function, include the module or 
include file in these options and do this untill all errors are resolved.

- Access checks -

By default the js module doesn't peform any kind of access check. 
Limited access checks are supported by adding the access arguments and the 
access callback (optional) to the js callback.

The access arguments are passed to the access callback. The access arguments 
implementation is very basic and does not support dynamic arguments. The 
variables here are passed through as provided. The access callback is the 
function that will be called to verify if the user has access to the callback. 
The access callback is optional and defaults to user_access.

Note on performance:
The js module automatically bootstraps to DRUPAL_BOOTSTRAP_SESSION 
when an access callback or access arguments are provided. This has a negative 
impact on the performance. If you don't need access checks, don't provide the
options in the callback.

- Internationalization -
The JS module support internationalization. When using a path prefix it's
automatically detected. When not using a path prefix you can set, for each
callback, that it uses internationalization (using the i18n option).

It does come at a cost though. Because it's required to boot to 
DRUPAL_BOOTSTRAP_LANGUAGE almost all of the bootstrap logic is executed again, 
severely reducing the effect of the JS module. The only gain that is left is 
that not all the modules are loaded. Be carefull when using this and only enable 
it when you must.

- Output -

js.php outputs the return value of the callback function using drupal_to_js().
To use a custom output format, output the data on your own and exit()
afterwards, or simply return nothing.

- Fallback - 

Note that it is wise to also register a corresponding menu path in hook_menu()
to provide fallback functionality when js.php is not available:

<code>
  $items[] = array(
    'path' => 'js/example/somefunction',
    'callback' => 'example_somefunction',
    'type' => MENU_CALLBACK,
  );
</code>

6. NOTES
========

Due to the nature of the way this module works not all modules that are active
are included. Sometimes this may cause an error while processing a callback and
sometimes this will result in a hook that is normally called, not beeing called
in a js callback. Be carefull about which logic you implement in a js callback.

If you encounter any problems with the default set of include files and modules
please create an issue in the queue and we'll look at including it by default.

7. CREDITS
==========

Project page: http://drupal.org/project/js

- Drupal 7 -

Authors:
* David Herminghaus (doitDave) - http://drupal.org/user/833794
* Michiel Nugter (michielnugter) - http://drupal.org/user/1023784

The Drupal 7 update has been sponsored by SYNETIC
Full service Drupal specialist. From custom made webapplications to content 
management systems, intranet and e-commerce shops. Visit http://www.synetic.nl 
for more information.

- Drupal 6 -

Authors:
* Daniel F. Kudwien (sun) - http://drupal.org/user/54136
* Stefan M. Kudwien (smk-ka) - http://drupal.org/user/48898

The Drupal 6 version has been sponsored by UNLEASHED MIND
Specialized in consulting and development of Drupal powered sites, our services 
include installation, development, theming, customization, and hosting to 
get you started. 
