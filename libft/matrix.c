/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:48:47 by gnicolo           #+#    #+#             */
/*   Updated: 2025/03/01 12:07:03 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	ft_count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	free_char_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
