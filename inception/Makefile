all		:	
			docker-compose -f srcs/docker-compose.yml up -d --build

clean	:
			docker-compose -f srcs/docker-compose.yml down

fclean	:
			docker-compose -f srcs/docker-compose.yml down --rmi all

re		:	fclean all

restart	:
			docker-compose -f srcs/docker-compose.yml restart

.PHONY	:	all up down re restart
