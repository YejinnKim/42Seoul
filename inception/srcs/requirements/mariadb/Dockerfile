FROM debian:buster

RUN apt-get update && \
    apt-get install -y mariadb-server

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

EXPOSE 3306

COPY ./tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]

CMD ["mysqld"]
