NAME = so_long

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L ./mlx -lmlx -framework OpenGL -framework Appkit

SRCS =  so_long.c \
		map_utils.c \
		check_map.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME) :	$(OBJS)
			make -C mlx
			make -C ft_printf
			$(CC) $(MLX_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) ft_printf/libftprintf.a

clean   :
			$(RM) $(OBJS)
			$(RM) mlx/*.o
			make -C ft_printf clean

fclean  :	clean
			make -C mlx clean
			$(RM) so_long ft_printf/libftprintf.a

re  :	fclean all

.PHONY  :	all clean fclean re
