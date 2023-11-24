FROM debian:buster

RUN apt-get update && \
    apt-get install -y nginx openssl

COPY ./conf/default /etc/nginx/sites-available/

COPY ./tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]

CMD ["nginx", "-g", "daemon off;"]
