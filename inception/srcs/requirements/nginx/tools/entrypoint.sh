#!/bin/bash

set -e

cat /default.template \
	| envsubst '$NGINX_PORT $DOMAIN_NAME $SSL_CERT $SSL_KEY $NGINX_WP_HOST $WORDPRESS_PORT' \
	> /etc/nginx/sites-available/default

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout $SSL_KEY -out $SSL_CERT \
	-subj "/C=$CTY/L=$LOC/O=$ORG/CN=$DOMAIN_NAME"

exec "$@"
