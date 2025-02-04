#include "fdf.h"

void	free_mat_char(char **mat)
{
	int		i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	print_mat(t_mat mat)
{
	int		i;
	int		j;

	i = 0;
	while (mat.mat[i])
	{
		j = 0;
		while (j < mat.x)
		{
			printf("%d", mat.mat[i][j]);
			printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

int	mat_len(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

int	*fun(char **tmp, int size)
{
	int		i;
	int		*res;

	res = malloc(sizeof(int *) * size);
	i = 0;
	while (tmp[i])
	{
		res[i] = atoi(tmp[i]);
		i++;
	}
	return (res);
}

void	parsing(t_mat *mat)
{
	int		fd;
	char	*s;
	int		i;
	char	**tmp;

	i = 0;
	fd = open("maps/42.fdf", O_RDONLY);
	mat->mat = malloc(sizeof(char *) * 2);
	while ((s = get_next_line(fd)))
	{
		if (i > 0)
			mat->mat = realloc(mat->mat, sizeof(int *) * (i + 2));
		tmp = ft_split(s, ' ');
		mat->x = mat_len(tmp);
		mat->mat[i] = fun(tmp, mat->x);
		i++;
	}
	mat->mat[i] = NULL;
}

/*
int	main()
{
	//char	**mat;
	t_mat	mat;

	parsing(&mat);
	print_mat(mat);
}
*/
