# Static upgrade

## Aliases

```bash
drush sqlq "select nid from node where status = 1 order by nid" > nid.txt
drush sqlq "select alias, source from url_alias where substring(source,1,4) = 'node' order by pid" > alias.tsv
```

## Local test

```bash
php -S localhost:8080 -t hrinfo.docksal.site/ router.php
```

## Fix links

```bash
find . -type f -name "*.html" -exec sed -i'' -e 's#http://hrinfo\.docksal\.site/#/#g' {} +
```
