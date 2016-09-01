Maintenance 200 Module

Description
--------------
The Maintenance 200 module allows a site to return a Status code of 200 rather
than the default 503 (Service Unavailable) code.  "But wait," you ask, "why 
would I want that? The site is truly in a 503 state and should report that."  The 
reason you'd want to return a 200 is so that your CDN or caching layer (e.g., Varnish)
will cache the maintenance page and serve it to new requests rather than passing
the request down to your origin server.

Admittedly, this is kind of a double edge sword, since once the page is in cache 
you'll have to flush your cache to bring the site back up, which may incur more origin 
load that is spared by caching the maintenance page, but c'est la vie.

Installation
--------------
Just like any other Drupal module. 

Configuration
-----------------
The module adds a set of radio buttons to the core Maintenance Mode form.  
Simply select the desired HTTP status code and that value will be returned when
the site is in maintenance mode.