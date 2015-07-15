Search API Saved Searches
-------------------------

This module offers users the ability to save searches executed with the
Search API module and be notified of new results. Notifications are done
via mails with token-replacement, their frequency can be configured both by
admins and/or users and saved searches can also be created without first
executing the search.

Facet, Views or other filters set for the search will also be included in a
saved search, thus reflecting exactly the same search results as displayed.

Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/search_api_saved_searches

Installation
------------

* Install the module as usual.
  See http://drupal.org/documentation/install/modules-themes/modules-7 
  for further information.
* Set the module's permissions (Administer saved searches, Use saved searches).
* You can now configure saved searches for each index by going to its
  "Saved searches" tab.
* For being able to actually save searches, you have to enable the
  "[Index Name]: Save search" block. This block will only appear on pages which
  contain a Search API search and allow users to save the executed search.
