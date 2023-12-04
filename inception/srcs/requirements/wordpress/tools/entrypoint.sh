#!/bin/bash

set -e

sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:$WORDPRESS_PORT/g" /etc/php/7.3/fpm/pool.d/www.conf
mkdir -p /run/php

if [ ! -f /var/www/html/wp-config.php ]; then
wp core download --path=/var/www/html --allow-root
wp core config --path=/var/www/html --dbname=$WORDPRESS_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$WORDPRESS_DB_HOST --allow-root
wp core install --path=/var/www/html --url=https://$DOMAIN_NAME --title=inception \
	--admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASS --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email --allow-root
wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=subscriber --user_pass=$WORDPRESS_USER_PASS --allow-root
fi

exec "$@"
