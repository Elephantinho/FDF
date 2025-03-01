SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strtok.c\
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c  matrix.c\
       ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_lstadd_back.c ft_strrchr.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c get_next_line.c ft_lstclear.c  ft_start_2link.c\
       ft_putchar_fd.c printf_tools.c ft_printf.c ft_listsize.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
       ft_lstadd_front.c ft_lstlast.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fPIC

# Aggiungi @ per nascondere il comando di compilazione
.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS} ; clear

all: ${NAME} ; clear

clean:
	${RM} ${OBJS} ; clear

fclean: clean
	${RM} ${NAME} ; clear

re: fclean all

.PHONY : all clean fclean re
