FROM debian:buster

RUN apt-get update && \
    apt-get install -y wget unzip php7.3 php7.3-mysql

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    rm latest.tar.gz

COPY ./conf/wp-config.php /var/www/html/wordpress/

CMD ["php", "-S", "0.0.0.0:9000", "-t", "/var/www/html/wordpress"]
