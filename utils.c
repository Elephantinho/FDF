/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:37:37 by gnicolo           #+#    #+#             */
/*   Updated: 2025/03/01 12:06:19 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_name(char *filename)
{
	if (!ft_strnstr(filename, ".fdf", ft_strlen(filename)))
	{
		perror("Error nell'apertura del file");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_line_columns(int fd, int first_line)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (first_line != ft_count_words(line, ' '))
		{
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			perror("Error: numero di colonne diverso\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	ft_check_nbr_col(char *filename)
{
	int		fd;
	char	*line;
	int		first_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		perror("Error: file vuoto");
		exit(EXIT_FAILURE);
	}
	first_line = ft_count_words(line, ' ');
	free(line);
	ft_check_line_columns(fd, first_line);
	close(fd);
}

int	mat_len(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

void	free_int_matrix(int **mat)
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
