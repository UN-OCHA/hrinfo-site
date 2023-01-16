!#/bin/sh

input="./nid.txt"
while read -r line
do
  line="${line//$'\r'/}"
  echo "$line"
  wget --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent http://hrinfo.docksal.site/node/$line
done < "$input"

