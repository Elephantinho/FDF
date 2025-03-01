/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:42:52 by gnicolo           #+#    #+#             */
/*   Updated: 2025/03/01 11:52:47 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*char_int(char **tmp, int size)
{
	int		i;
	int		*res;

	res = malloc(sizeof(int) * size);
	i = 0;
	while (tmp[i])
	{
		res[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (res);
}

void	*ft_realloc(void *ptr, size_t size_old, size_t size_new)
{
	void	*new_data;

	new_data = NULL;
	if (size_new)
	{
		if (!ptr)
			return (ft_calloc(1, size_new));
		new_data = ft_calloc(1, size_new);
		if (new_data)
		{
			ft_memcpy(new_data, ptr, size_old);
			free(ptr);
		}
	}
	return (new_data);
}

void	parsing(t_mat *mat, char *filename)
{
	int		fd;
	char	*s;
	int		i;
	char	**tmp;
	int		new_size;

	i = 0;
	check_name(filename);
	ft_check_nbr_col(filename);
	fd = open(filename, O_RDONLY);
	mat->mat = ft_calloc(sizeof(int *), 1);
	s = get_next_line(fd);
	while (s)
	{
		new_size = sizeof(int *) * (i + 2);
		mat->mat = ft_realloc(mat->mat, sizeof(int *) * (i), new_size);
		tmp = ft_split(s, ' ');
		mat->x = mat_len(tmp);
		mat->mat[i] = char_int(tmp, mat->x);
		free_char_matrix(tmp);
		free(s);
		s = get_next_line(fd);
		i++;
	}
	mat->mat[i] = NULL;
}
