FROM debian:buster

RUN apt-get update && \
    apt-get install -y nginx

COPY ./conf/default /etc/nginx/sites-available/

CMD ["nginx", "-g", "daemon off;"]
