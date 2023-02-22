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

NAME	=	pipex

CFLAGS	=	-Wall -Wextra -Werror -g
# export MallocStackLogging=1
# while true; do a.out; sleep 0.4; done

SRCS	=	pipex.c \
			parse_args.c

SRCS_BNS	=	bonus/pipex_bonus.c \
				bonus/parse_args_bonus.c

OBJS 	=	$(SRCS:.c=.o)

OBJS_BNS	=	$(SRCS_BNS:.c=.o)

MKLIB		=	make -C libft

LIBFT 		=	libft/libft.a

ifdef BNS_FLAG
    OBJS = $(OBJS_BNS)
endif

all 	:	$(NAME)

$(NAME) :	$(OBJS)
			$(MKLIB)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean   :	
			$(RM) $(OBJS) $(OBJS_BNS)
			$(MKLIB) clean

fclean  :	clean
			$(RM) $(NAME) $(LIBFT)

re		:	fclean all

bonus	:	
			make BNS_FLAG=1

.PHONY  :	all clean fclean re bonus