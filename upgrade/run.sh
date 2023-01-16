!#/bin/sh

input="./nid.txt"
while read -r line
do
  line="${line//$'\r'/}"
  echo "$line"
  wget --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent http://hrinfo.docksal.site/node/$line
done < "$input"

input="./extra_urls.txt"
while read -r line
do
  line="${line//$'\r'/}"
  echo "$line"
  wget --exclude-directories=/en --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --mirror --convert-links --adjust-extension --page-requisites --no-parent http://hrinfo.docksal.site/$line
done < "$input"

rm hrinfo.docksal.site/operations -rf
touch hrinfo.docksal.site/404.html

