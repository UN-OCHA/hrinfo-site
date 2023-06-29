Redirect 404

Introduction
==========================
Redirect 404 allows you to specify a number of servers that should be 
attempted to be redirected to if a 404 (Page not found) error is encountered. 
This module is useful when you are doing a gradual migration to Drupal from 
another system (Drupal-based or not).

Description
==========================
Let's say you have a legacy system which contains most of your web presence 
and decide to migrate to Drupal, starting with the home page, but didn't 
want to orphan the legacy site. 

So, URL such as http://www.example.com/department would stop working 
and would return 404 to users visiting the site.

With mod_rewrite in Apache, it is possible to redirect 404 to an external URL, 
but it does not preserve the full request path nor support multiple 
destination servers.

If you specify legacy1.example.com and legacy2.example.com as your possible 
destinations for your Drupal site on www.example.com and a user visited 
http://www.example.com/department, which hadn't existed, Multiple 404 Redirect 
would then try legacy1.example.com/department if found, the user would be 
redirected. If not found, legacy2.example.com/department would be tried, 
and if found, the user would be redirected to that URL instead. If still 
not found, a custom 404 error page may be specified or a user message 
defined. You could also specify a site search URL as an option, so if you 
try to go to www.example.com/department and no servers are found that know 
what to do with the request, the user is taken to the search results page 
for department (example: www.example.com/search/department)

Incompatibilities
==========================
- Requests which are handled with the Fast 404 module are not be handled by 
Redirects 404. Fast 404 "runs first" and the handles the requests on its own.