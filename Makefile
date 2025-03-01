SRCS = \
fdf.c \
parsing.c \
bresenham.c \
close.c \
utils.c \
point.c \
drawline.c \
projection_zoom.c \

OBJ_DIR = obj
NAME =		fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Aggiungere i file oggetto
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Target principale
all: $(NAME)

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux

# Compilazione dell'eseguibile
$(NAME): minilibx-linux/libmlx.a libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -lm  -o $(NAME)


# Regola per creare i file .o del progetto principale
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file oggetto
clean:
	rm -rf $(OBJ_DIR)

# Pulizia totale (incluso l'eseguibile)
fclean: clean
	rm -f $(NAME)

# Ricostruzione completa
re: fclean all

# Regola per il libft
libft/libft.a:
	make -C libft

.PHONY: all clean fclean re


