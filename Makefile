SRCS = \
fdf.c \
parsing.c \

NAME =		a.out
CFLAGS =	 -g

all:		$(NAME)

parsing:
	gcc -g parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a

$(NAME):	minilibx-linux/libmlx.a $(SRCS)
			cc $(CFLAGS) $(SRCS) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux

fclean:
			rm -f $(NAME)

re:	fclean all
