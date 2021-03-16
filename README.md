# Humanitarian Response - [![Dev branch Build Status](https://travis-ci.com/UN-OCHA/hrinfo-site.svg?branch=dev)](https://travis-ci.com/UN-OCHA/hrinfo-site) [![Master branch Build Status](https://travis-ci.com/UN-OCHA/hrinfo-site.svg?branch=master)](https://travis-ci.com/UN-OCHA/hrinfo-site)

This is the humanitarianresponse.info Drupal 7 web site repository.

Composer is now working for core and module updates (there were some issues,
previously). Pinned modules should be checked before updating them. Some
modules don't have recent releases, so we're on the dev branch. Watch out for
unintended updates for those.

16/03/2021 Pinned Date and Redirect modules during a composer update. Date
because there's a warning to wait till version 2.12
https://www.drupal.org/project/date/releases/7.x-2.11
and Redirect because there are a lot of changes and it would be better to test
more thoroughly before the deployment.

Known issues:
Previews disappear without explanation:
https://humanitarian.atlassian.net/browse/OPS-7319
Clearing the cache brings them back.

Content disappears from spaces and pages on saving:
https://humanitarian.atlassian.net/browse/HRINFO-1034
Appears to happen after modules are enabled/ disabled. Run `drush rr` after
any work on the servers.
