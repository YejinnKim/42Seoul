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

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	pipex.c \
			parse_args.c

SRCS_BNS	=	bonus/pipex_bonus.c \
				bonus/parse_args_bonus.c \
				bonus/get_next_line/get_next_line.c \
				bonus/get_next_line/get_next_line_utils.c

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