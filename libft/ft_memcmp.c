/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:19:21 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/26 18:20:50 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *src, size_t len)
{
	unsigned char		*dest1;
	unsigned char		*src1;
	unsigned int		i;

	if (len == 0)
		return (0);
	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	i = 0;
	while (src1[i] == dest1[i] && i < len - 1)
		i++;
	if (i != len)
		return (dest1[i] - src1[i]);
	return (0);
}
