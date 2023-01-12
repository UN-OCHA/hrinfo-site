# Decomission

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

```bash
drush pm-disable restclient
drush pm-disable restful
drush pm-disable hr_api
```

On http://hrinfo.docksal.site/en/admin/structure/context disable all tagged contexts
