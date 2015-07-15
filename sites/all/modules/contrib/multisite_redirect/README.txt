CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Configuration


INTRODUCTION
------------

Current Maintainer: Ian Whitcomb - http://drupal.org/user/771654

Multisite Redirect is a system designed to allow users to create and manage URL redirects across domains in a sort of
multisite configuration. The primary use case for this module is one where a client might have multiple domains that are
being consolidated into a single site. In this scenario not only will the domains be different, but the URLs associated
with them as well. Rather than killing all of the obsolete URLs from an old domain, you can drive all of the SEO juice
to the primary site. With this module you can define rules that will redirect certain patterns of URLs on certain sites
to be redirected somewhere else.


INSTALLATION
------------

1. Download module and copy multisite_redirect folder to sites/all/modules

2. Enable the Multisite Redirect modules.


CONFIGURATION
------------

After enabling the module, you'll need to setup your sites/sites.php file by pointing all of the domains that are to be
managed by this module, at the primary site. In many cases this may just be "default" if you're not running a true
multisite setup.

Example sites.php

$sites['domain1.com'] = 'default';
$sites['domain1.com'] = 'default';
$sites['domain2.com'] = 'default';
$sites['foobar.domain.com'] = 'default';

In this example URLs from domain1.com, domain2.com, domain3.com, and foobar.domain.com will all be managed by the
default site. You can read more about how to setup multisite and your sites.php here.

- https://api.drupal.org/api/drupal/sites!example.sites.php/7