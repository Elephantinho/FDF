/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:15 by gnicolo           #+#    #+#             */
/*   Updated: 2025/01/17 10:53:14 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
		{
			i++;
		}
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)ft_calloc(sizeof(char), (j - i + 1));
		if (str == NULL)
			return (NULL);
		if (str)
		{
			ft_strlcpy(str, &s1[i], j - i + 1);
		}
	}
	return (str);
}
/*
int main(void)
{
    char *miao = " n\ \t  Please\n Trim me\n  \t\t\t\t  ";
    char *bau = " \n\t\t    H";
    char *crac = ft_strtrim(miao,bau);
    if(crac != NULL)
    {
		printf("%s\n", crac);
	free (crac);
    }
    return (0);
}*/
