FROM debian:buster

RUN apt-get update && \
    apt-get install -y wget unzip php7.3 php7.3-fpm php7.3-mysql

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    rm latest.tar.gz

COPY ./conf/wp-config.php /var/www/html/wordpress/

COPY ./tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]

CMD ["php-fpm7.3", "--nodaemonize"]
