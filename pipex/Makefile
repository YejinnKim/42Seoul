# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 15:56:29 by yejinkim          #+#    #+#              #
#    Updated: 2023/02/13 15:56:29 by yejinkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror -g
# export MallocStackLogging=1

SRCS =  pipex.c \
		parse_args.c

OBJS = $(SRCS:.c=.o)

LIBFT = make -C libft

all 	:	$(NAME)

$(NAME) :	$(OBJS)
			$(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a
			
clean   :	
			$(RM) $(OBJS)
			$(LIBFT) clean

fclean  :	clean
			$(RM) $(NAME) libft/libft.a

re		:	fclean all

.PHONY  :	all clean fclean re