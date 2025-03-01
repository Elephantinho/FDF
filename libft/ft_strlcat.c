/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:02:47 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/26 18:09:07 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			d_len;
	size_t			s_len;
	unsigned int	d;
	unsigned int	s;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + s_len);
	d = d_len;
	s = 0;
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (d_len + s_len);
}
