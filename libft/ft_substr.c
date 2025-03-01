/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:01:04 by gnicolo           #+#    #+#             */
/*   Updated: 2025/02/26 15:32:15 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen((char *)s);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start >= len)
		str = (char *)malloc((len + 1) * sizeof(char));
	else
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
/*int main()
{
    const char *str = "Hello, World!";
    char *substr1, *substr2, *substr3;

    // Test 1: Sottostringa da un punto valido
    substr1 = ft_substr(str, 7, 5);  // "World"
    if (substr1)
    {
        printf("Sottostringa 1: %s\n", substr1);
        free(substr1);  // Non dimenticare di liberare la memoria
    }

    // Test 2: Start oltre la fine della stringa
    substr2 = ft_substr(str, 20, 5);  // ""
    if (substr2)
    {
        printf("Sottostringa 2: %s\n", substr2);  // Dovrebbe essere vuoto
        free(substr2);
    }

    // Test 3: Lunghezza maggiore rispetto alla parte restante della stringa
    substr3 = ft_substr(str, 7, 100);  // "World!"
    if (substr3)
    {
        printf("Sottostringa 3: %s\n", substr3);
        free(substr3);
    }

    return 0;
}*/
