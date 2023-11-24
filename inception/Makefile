all		:	
			@mkdir -p ./home/yejinkim/data/mariadb # 상대경로 수정
			@mkdir -p ./home/yejinkim/data/wordpress # 상대경로 수정
			docker-compose -f srcs/docker-compose.yml up -d --build

clean	:
			docker-compose -f srcs/docker-compose.yml down

fclean	:
			docker-compose -f srcs/docker-compose.yml down --rmi all
			docker volume rm -f mariadb wordpress
			@rm -rf ./home/yejinkim/data # 상대경로 수정

re		:	fclean all

restart	:
			docker-compose -f srcs/docker-compose.yml restart

.PHONY	:	all up down re restart
