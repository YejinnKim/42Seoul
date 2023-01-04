NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g 
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =  so_long.c \
		map_utils.c \
		check_map.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

FT_PRINTF = make -C ft_printf

OBJS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME) :	$(OBJS)
			$(FT_PRINTF)
			$(CC) $(MLX_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) ft_printf/libftprintf.a

clean   :
			$(RM) $(OBJS)
			make -C ft_printf clean

fclean  :	clean
			$(RM) so_long ft_printf/libftprintf.a

re  :	fclean all

.PHONY  :	all clean fclean re