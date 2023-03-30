# Static upgrade

## Delete older content

Goal is to keep last 2 years of content.

```bash
drush sqlq "DELETE FROM node WHERE type NOT IN ('hr_operation', 'hr_bundle') AND created < UNIX_TIMESTAMP('2021-01-01')"
drush sqlq "DELETE FROM node_revision WHERE node_revision.nid NOT IN (SELECT nid from node)"
drush cc all
drush en hr_decommissioner -y
```

## Disable modules and context

See [hr_decommissioner](../html/sites/all/modules/hr/hr_decommissioner/README.md)

```bash
drush pm-disable restclient -y
drush pm-disable restful -y
drush pm-disable hr_api -y
drush pm-disable redirect -y
drush eval "hr_decommissioner_diable_contexts()"
```

## Export mappings

```bash
drush sqlq "SELECT nid FROM node WHERE status = 1 order by nid" > nid.txt
drush sqlq "SELECT alias, source FROM url_alias WHERE substring(source,1,4) = 'node' order by pid" > alias.tsv
awk '{print $1}' < alias.tsv > extra_urls.txt
drush sqlq "SELECT nid FROM node WHERE status = 1 AND type='hr_operation' order by nid" > operations.txt
drush sqlq "SELECT nid FROM node WHERE status = 1 AND type='hr_bundle' order by nid" > clusters.txt
```

## Run export

Set proper BASE_URL in [run.sh](./run.sh)

[Execute run.sh] and get popcorn ...

## Local test

```bash
php -S localhost:8080 -t hrinfo.docksal.site/ router.php
```

## Fix links

```bash
find . -type f -name "*.html" -exec sed -i'' -e 's#http://hrinfo\.docksal\.site/#/#g' {} +
```
