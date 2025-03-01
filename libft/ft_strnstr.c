/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:38:29 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/26 22:05:28 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (j < len && big[j] != '\0')
	{
		k = 0;
		while (big[j + k] == little[k] && little[k] != '\0'
			&& (j + k) < len)
			k++;
		if (little[k] == '\0')
			return ((char *)(&big[j]));
		j++;
	}
	return (NULL);
}
/*int	main(int argc, char *argv[])
{
	if (argc == 4)
		printf("%s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("%s\n", ft_strnstr("aaabcabcd", "aabc", -1));
	printf("%s\n", ft_strnstr("aaabcabcd", "abcd", 9));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	return (0);
}
*/
