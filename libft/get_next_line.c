/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:02:44 by gnicolo           #+#    #+#             */
/*   Updated: 2025/02/01 11:19:10 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strkjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

static char	*ft_subkstr(char *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		sub_str = malloc(sizeof(char));
		return (sub_str);
	}
	if (ft_strlen(s) - start > len)
		sub_str = malloc(sizeof(char) * ((len + 1)));
	else
		sub_str = malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while ((char)s[start] && (size_t)i < len)
	{
		sub_str[i++] = (char)s[start];
		start++;
	}
	sub_str[i] = 0;
	return (sub_str);
}

static char	*ft_cool_line(int fd, char **sub_str, char *buffer)
{
	ssize_t	bt_read;
	char	*temp;

	while (1)
	{
		bt_read = read(fd, buffer, BUFFER_SIZE);
		if (bt_read == 0)
			break ;
		else if (bt_read < 0)
		{
			free(*sub_str);
			*sub_str = NULL;
			return (NULL);
		}
		buffer[bt_read] = '\0';
		if (!*sub_str)
			*sub_str = ft_strdup("");
		temp = *sub_str;
		*sub_str = ft_strkjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*sub_str);
}

static char	*ft_trim_line(char *line_f)
{
	ssize_t	len;
	char	*rest;

	len = 0;
	while (line_f[len] != '\0' && line_f[len] != '\n')
		len++;
	if (line_f[len] == '\0' || line_f[len + 1] == '\0')
		return (NULL);
	rest = ft_subkstr(line_f, len + 1, ft_strlen(line_f) - len);
	if (rest == 0)
		return (free(rest), NULL);
	line_f[len] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*sub_str;
	char		*buffer;
	char		*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	line = ft_cool_line(fd, &sub_str, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	sub_str = ft_trim_line(line);
	return (line);
}
/*
int main (void)
{
	int fd = open("text.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
