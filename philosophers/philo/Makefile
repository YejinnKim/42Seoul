# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 16:52:18 by yejinkim          #+#    #+#              #
#    Updated: 2023/03/27 16:19:47 by yejinkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRCS =  main.c \
		init.c \
		philo.c \
		check_print.c

OBJS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			
clean   :	
			$(RM) $(OBJS)

fclean  :	clean
			$(RM) $(NAME)

re  :	fclean all

.PHONY  :	all clean fclean re