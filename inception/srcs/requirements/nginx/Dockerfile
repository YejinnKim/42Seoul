FROM debian:buster

RUN apt-get update && \
    apt-get install -y nginx openssl gettext

COPY ./conf/default /default.template

COPY ./tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]

CMD ["nginx", "-g", "daemon off;"]
