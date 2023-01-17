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

## Todo

- disable redirect to response site
- delete unpublished nodes

```bash
drush pm-disable restclient
drush pm-disable restful
drush pm-disable hr_api
drush pm-disable redirect
drush en stage_file_proxy
```

Nodes to delete:

- 69107


On http://hrinfo.docksal.site/en/admin/structure/context disable all tagged contexts

```
wget --exclude-directories=/login --no-clobber --mirror --convert-links --adjust-extension --page-requisites --no-parent http://hrinfo.docksal.site/
```

## Count

Count files by extension.

```bash
find . -type f | sed 's/\//\./g' | sed 's/.*\.//' | sort | uniq -c | sort -rn | head -n 20
```

```
116846 html
12799 feed
1223 feedrw
71 css
48 js
31 png
12 svg
...
```
