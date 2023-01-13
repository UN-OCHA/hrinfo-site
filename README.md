# Humanitarian Response - [![Dev branch Build Status](https://travis-ci.com/UN-OCHA/hrinfo-site.svg?branch=dev)](https://travis-ci.com/UN-OCHA/hrinfo-site) [![Master branch Build Status](https://travis-ci.com/UN-OCHA/hrinfo-site.svg?branch=master)](https://travis-ci.com/UN-OCHA/hrinfo-site)

This is the humanitarianresponse.info Drupal 7 web site repository.

Composer is now working for core and module updates (there were some issues,
previously). Pinned modules should be checked before updating them. Some
modules don't have recent releases, so we're on the dev branch. Watch out for
unintended updates for those.

Composer isn't handling libraries at the moment - there is a w.i.p branch for
this: HRINFO-1067-remove-contrib-modules-from-repo.
To update CKeditor library see build-config.js. The linkit module plugin is
copied over from the module, but may not need to be. Test this.

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

## Decomission

`select type, count(*) from node where created > 1609455600 group by type;`

+----------------+----------+
| type           | count(*) |
+----------------+----------+
| hr_assessment  |      380 |
| hr_bundle      |       99 |
| hr_disaster    |      169 |
| hr_document    |    14578 |
| hr_event       |     6479 |
| hr_infographic |     4814 |
| hr_office      |       25 |
| hr_operation   |        8 |
| hr_page        |      273 |
+----------------+----------+
9 rows in set (0.288 sec)

`select type, count(*) from node where changed > 1609455600 group by type;`
+---------------------+----------+
| type                | count(*) |
+---------------------+----------+
| hr_assessment       |      402 |
| hr_bundle           |      805 |
| hr_disaster         |      741 |
| hr_document         |    15329 |
| hr_event            |     6740 |
| hr_infographic      |     5359 |
| hr_office           |       81 |
| hr_operation        |      241 |
| hr_page             |      582 |
| hr_space            |       14 |
| hr_toolbox_category |        5 |
| hr_toolbox_item     |      133 |
+---------------------+----------+
12 rows in set (0.095 sec)
