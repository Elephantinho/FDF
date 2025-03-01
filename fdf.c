/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:58:52 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 12:17:55 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;
	int		byte_per_pixel;
	int		vertical_offset;
	int		horizontal_offset;

	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	byte_per_pixel = data->bits_per_pixel / 8;
	vertical_offset = y * data->line_length;
	horizontal_offset = x * byte_per_pixel;
	dst = data->addr + (vertical_offset + horizontal_offset);
	*(unsigned int *)dst = color;
}

// Funzione per disegnare il punto corrente nella matrice
void	draw_current_point(t_drawing_context *ctx, t_point_3 *p1, t_iter iter)
{
	ft_start_point2(&p1->p1, iter, ctx->scale, ctx->mat->mat[iter.i][iter.j]);
	iso_projection(&p1->p1.x, &p1->p1.y, p1->p1.z, ctx->qwe);
	ft_set(&p1->p1, ctx->qwe->offset_x, ctx->qwe->offset_y);
	my_mlx_pixel_put(ctx->img, p1->p1.x, p1->p1.y, 0x00FFFFFF);
}

// Funzione principale per creare l'immagine
void	create_imagine(t_mat *mat, t_image img, t_window *qwe)
{
	t_iter				iter;
	t_point_3			p1;
	t_drawing_context	ctx;
	int					s;

	ctx.mat = mat;
	ctx.img = &img;
	ctx.qwe = qwe;
	iter.i = 0;
	while (mat->mat[iter.i])
	{
		iter.j = 0;
		while (iter.j < mat->x)
		{
			s = scale(qwe);
			ctx.scale = s;
			draw_current_point(&ctx, &p1, iter);
			draw_horizont_line(&ctx, &p1, iter);
			draw_vertical_line(&ctx, &p1, iter);
			iter.j++;
		}
		iter.i++;
	}
}

int	main(int ac, char **av)
{
	t_window	qwe;

	if (ac == 2)
	{
		parsing(&qwe.mat, av[1]);
		qwe.mlx = mlx_init();
		qwe.win = mlx_new_window(qwe.mlx, WIN_X, WIN_Y, "FDF");
		qwe.img.img = mlx_new_image(qwe.mlx, WIN_X, WIN_Y);
		qwe.img.addr = mlx_get_data_addr(qwe.img.img, &qwe.img.bits_per_pixel,
				&qwe.img.line_length, &qwe.img.endian);
		qwe.zoom = 30;
		qwe.angle_x = 0.523599;
		qwe.angle_y = 0.523599;
		qwe.offset_x = 300;
		qwe.offset_y = 600;
		create_imagine(&qwe.mat, qwe.img, &qwe);
		mlx_put_image_to_window(qwe.mlx, qwe.win, qwe.img.img, 0, 0);
		mlx_hook(qwe.win, 17, 0, close_window, &qwe);
		mlx_key_hook(qwe.win, key_press, &qwe);
		mlx_loop_hook(qwe.mlx, handle_input, &qwe);
		mlx_loop(qwe.mlx);
	}
	return (0);
}
