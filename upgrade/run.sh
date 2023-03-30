#!/bin/sh

BASE_URL=http://hrinfo.docksal.site

input="./nid.txt"
while read -r line
do
  line="${line//$'\r'/}"
  echo "$line"
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror -r --convert-links --adjust-extension --page-requisites $BASE_URL/node/$line
done < "$input"

input="./extra_urls.txt"
while read -r line
do
  line="${line//$'\r'/}"
  echo "$line"
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --mirror --convert-links --adjust-extension --page-requisites $BASE_URL/$line
done < "$input"

input="./operations.txt"
while read -r line
do
  line="${line//$'\r'/}"
  echo "$line"
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents?page=0
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents?page=1
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents?page=2
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics?page=0
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics?page=1
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics?page=2
done < "$input"

input="./clusters.txt"
while read -r line
do
  line="${line//$'\r'/}"
  echo "$line"
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents?page=0
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents?page=1
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/documents?page=2
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics?page=0
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics?page=1
  wget --exclude-directories=/en --exclude-directories=/operations --exclude-directories=/fr --exclude-directories=/es --exclude-directories=/ru --exclude-directories=/login --mirror --convert-links --adjust-extension --page-requisites --no-parent $BASE_URL/node/$line/infographics?page=2
done < "$input"

echo "Clean up"
rm hrinfo.docksal.site/operations -rf
touch hrinfo.docksal.site/404.html
find . -type f -name "*.html" -exec sed -i'' -e 's#http://hrinfo\.docksal\.site/#/#g' {} +
