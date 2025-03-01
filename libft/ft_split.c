/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:27:49 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/28 12:52:23 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	s_num;

	i = 0;
	s_num = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			s_num++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (s_num);
}

static size_t	ft_superlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**malloc_bigerror(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**main_factory(char **str, int *i, char *s, char c)
{
	while (s[++i[0]] != '\0')
	{
		if (s[i[0]] != c)
		{
			str[i[1]] = ft_substr(s, i[0], ft_superlen(&s[i[0]], c));
			if (!str[i[1]])
				return (malloc_bigerror(str));
			i[0] = i[0] + ft_superlen(&s[i[0]], c);
			break ;
		}
	}
	i[1]++;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		n_str;
	char	**split;
	int		i[2];

	i[1] = 0;
	i[0] = -1;
	n_str = ft_count(s, c);
	split = ft_calloc((n_str + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (n_str--)
	{
		if (main_factory(split, i, (char *)s, c) == NULL)
			return (NULL);
	}
	split[i[1]] = 0;
	return (split);
}
