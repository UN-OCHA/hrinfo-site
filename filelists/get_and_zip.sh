#!/bin/sh

for d in */ ; do
    echo "$d"
    cd "$d"
    wget -nc -i filelist.txt
    cd ..
done

find * -type d -execdir zip -r -0 '{}.zip' '{}' \;
