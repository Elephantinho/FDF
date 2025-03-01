/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:57:27 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/24 15:00:10 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
