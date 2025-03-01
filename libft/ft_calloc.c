/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:48:54 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/25 13:35:20 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, (size * nmemb));
	return (s);
}
/*
int main(void)
{
	char *tmp = "ciao negri";

	char *string;
	printf("%p\n", string);
	string = ft_calloc(sizeof(int), strlen(tmp));
	//string = "fanculo";
	printf("%p\n", string);
	return (0);
}
*/
