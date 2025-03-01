/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:26:54 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/24 14:59:58 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t num)
{
	unsigned const char	*dest;
	unsigned char		val;
	size_t				i;

	dest = (unsigned const char *) str;
	val = (unsigned char) value;
	i = 0;
	while (i < num)
	{
		if (dest[i] == val)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
