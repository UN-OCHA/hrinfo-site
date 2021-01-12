FROM unocha/php7-k8s:${TAG:-7.3-NR-stable}

ARG VCS_REF
ARG VCS_URL
ARG BUILD_DATE
ARG GITHUB_ACTOR
ARG GITHUB_REPOSITORY
ARG GITHUB_SHA
ARG GITHUB_REF

ENV  NGINX_SERVERNAME=www.humanitarianresponse.info
ENV  PHP_ENVIRONMENT=production
ENV  PHP_MEMORY_LIMIT=512M
ENV  PHP_MAX_CHILDREN=96
ENV  GIT_BLAME=$GITHUB_ACTOR
ENV  GIT_REPO=$GITHUB_REPOSITORY
ENV  GIT_SHA=$GITHUB_SHA
ENV  GIT_REF=$GITHUB_REF
LABEL info.humanitarianresponse.build.date=$BUILD_DATE \
      info.humanitarianresponse.build.vcs-url=$VCS_URL \
      info.humanitarianresponse.build.vcs-ref=$VCS_REF

COPY ./html /srv/www/html
COPY ./composer.json /srv/www/composer.json
COPY ./composer.lock /srv/www/composer.lock
COPY ./composer.patches.json /srv/www/composer.patches.json
COPY ./docker/custom /etc/nginx/custom
# Hotfix for https://humanitarian.atlassian.net/browse/HRINFO-1019
COPY ./docker/policy.xml /etc/ImageMagick-7/policy.xml

RUN  cd /srv/www/html/sites && \
       rm -f www.humanitarianresponse.info && \
       ln -s default www.humanitarianresponse.info && \
