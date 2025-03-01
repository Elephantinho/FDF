/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:51:48 by gnicolo           #+#    #+#             */
/*   Updated: 2025/02/27 14:31:02 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <signal.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	void				*content;
	int					nbr;
	int					index;
	struct s_list		*next;
	struct s_list		*prev;
}			t_list;

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				chunk;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(char *str);
int		ft_count_words(char *s, char c);
void	free_char_matrix(char **mat);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_putnbr_u(unsigned int nb);
int		ft_pointer(uintptr_t exa);
int		ft_check_char(char c, va_list params);
int		ft_exa_up(unsigned int exa);
int		ft_exa_low_two(unsigned long exa);
int		ft_exa_low(unsigned int exa);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_start_2link(t_stack **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char *set);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *str);
int		matrix_len(char **matrix);
char	*ft_strtok(char *str, const char *delim);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

#endif
