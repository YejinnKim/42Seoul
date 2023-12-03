FROM debian:buster

RUN apt-get update && \
    apt-get install -y mariadb-server

COPY ./tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/entrypoint.sh"]

CMD ["mysqld"]
