/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:06:55 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/26 21:36:00 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (!dest && !src)
		return (NULL);
	else if (!n)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (s <= d)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
