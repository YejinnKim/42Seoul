NAME = libftprintf.a

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c print_hex.c print_num.c print_str.c

OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(OBJS)

all : $(NAME)
%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
$(NAME) : $(OBJ_FILES)
	ar crs $(NAME) $(OBJ_FILES)
clean : 
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean $(NAME)
.PHONY : all clean fclean re