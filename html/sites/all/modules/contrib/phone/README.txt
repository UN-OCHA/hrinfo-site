Description
-----------
This module provides a phone field type and FAPI element.

Features:
---------
  - Provides a Phone field type, Phone field widget, and several formatters.
  - Provides a Phone FAPI element which can be used in custom modules.
  - Backports the "tel" input element from D8 as "phone_tel",
    and allows this to be used for number input elements.
  - One field instance can support every country.
  - Limit allowable countries.
  - Includes customisable type/label support (Work, Home, Fax, etc..).
  - Full region level validation for all phone numbers using libphonenumber.
    This supports most if not all known countries, and works for both the
    Phone field widget, and Phone FAPI element.
  - Region specific output formatting using libphonenumber, supporting
    International, National, E.164, and RFC3966 output styles.
  - tel: href support using RFC3966.
  - Full token support.
  - Feeds & Migrate integration.
  - Microdata (itemprop=telephone), RDFa (foaf:phone),
    and microformats hcard (class="tel/type/value") support.
  - Devel Generate support.
  - Views and Entity API integration.
  - Support for countries to be disabled via external
    modules like the Countries module (http://drupal.org/project/countries).

Prerequisites
-------------
  The libraries module >= 7.x-2.x (http://drupal.org/project/libraries)
  The libphonenumber library for php must be installed in your sites
  library path. libphonenumber is available from
  https://github.com/chipperstudios/libphonenumber-for-php

Installation
------------
  To install, download and install the prerequisites, then copy the phone
  directory and all its contents to your modules directory.

Configuration
-------------
  To enable this module, visit administer -> modules, and enable phone.

Bugs/Features/Patches:
----------------------
  If you want to report bugs, feature requests, or submit a patch, please do
  so at the project page on the Drupal web site.
  http://drupal.org/project/phone
