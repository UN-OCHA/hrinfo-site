FROM public.ecr.aws/unocha/php-k8s:8.0-stable as builder

ARG  BRANCH_ENVIRONMENT
COPY . /srv/www
WORKDIR /srv/www
RUN composer self-update && \
    composer install --quiet --no-dev --prefer-dist

FROM public.ecr.aws/unocha/php-k8s:8.0-stable

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

COPY --from=builder /srv/www/html /srv/www/html
COPY --from=builder /srv/www/vendor /srv/www/vendor
COPY --from=builder /srv/www/composer.json /srv/www/composer.json
COPY --from=builder /srv/www/composer.lock /srv/www/composer.lock
COPY --from=builder /srv/www/composer.patches.json /srv/www/composer.patches.json
COPY --from=builder /srv/www/docker/custom /etc/nginx/custom
COPY --from=builder /srv/www/docker/99-elastic-apm-custom.ini /tmp/99-elastic-apm-custom.ini

RUN  curl -L -o /tmp/apm-agent-php_1.6.1_all.apk https://github.com/elastic/apm-agent-php/releases/download/v1.6.1/apm-agent-php_1.6.1_all.apk && \
     apk add --allow-untrusted /tmp/apm-agent-php_1.6.1_all.apk && \
     rm -f /tmp/apm-agent-php_1.6.1_all.apk && \
     mv -f /tmp/99-elastic-apm-custom.ini /etc/php8/conf.d/99-elastic-apm-custom.ini

RUN  cd /srv/www/html/sites && \
       rm -f www.humanitarianresponse.info && \
       ln -s default www.humanitarianresponse.info
