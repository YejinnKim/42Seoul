all		:	
			@if ! grep "127\.0\.0\.1[[:space:]]yejinkim.42.fr" "/etc/hosts"; then \
				echo "127.0.0.1	yejinkim.42.fr" >> /etc/hosts; \
			fi
			@mkdir -p /home/yejinkim/data/mariadb
			@mkdir -p /home/yejinkim/data/wordpress
			docker-compose -f ./srcs/docker-compose.yml up -d --build

clean	:
			docker-compose -f ./srcs/docker-compose.yml down

fclean	:
			docker-compose -f ./srcs/docker-compose.yml down --rmi all
			docker volume rm -f mariadb wordpress
			@rm -rf /home/yejinkim/data

re		:	fclean all


up		:
			docker-compose -f ./srcs/docker-compose.yml up -d

down	:
			docker-compose -f ./srcs/docker-compose.yml down

restart	:
			docker-compose -f ./srcs/docker-compose.yml restart


.PHONY	:	all clean fclean re up down restart
