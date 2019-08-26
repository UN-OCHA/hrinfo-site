#!/bin/bash

#
# @TODO: add conditional to see if working tree is clean. only proceed when clean.
#

# configure node/gulp for clean commit
export NODE_ENV='production'

# build assets
gulp build
git add css/styles.css
