/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:12:03 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 11:28:44 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_dx_dy(t_point p1, t_point p2, t_bresenham *bresenham)
{
	bresenham->dx = abs(p2.x - p1.x);
	bresenham->dy = abs(p2.y - p1.y);
}

void	calculate_step(t_point p1, t_point p2, t_bresenham *bresenham)
{
	if (p1.x < p2.x)
		bresenham->sx = 1;
	else
		bresenham->sx = -1;
	if (p1.y < p2.y)
		bresenham->sy = 1;
	else
		bresenham->sy = -1;
}

void	calculate_error(t_bresenham *bresenham)
{
	bresenham->err = bresenham->dx - bresenham->dy;
}

void	draw_point(t_image *img, t_point p, int color)
{
	my_mlx_pixel_put(img, p.x, p.y, color);
}

void	draw_line(t_image *img, t_point p1, t_point p2, int color)
{
	t_bresenham	bresenham;

	calculate_dx_dy(p1, p2, &bresenham);
	calculate_step(p1, p2, &bresenham);
	calculate_error(&bresenham);
	while (1)
	{
		draw_point(img, p1, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		bresenham.e2 = 2 * bresenham.err;
		if (bresenham.e2 > -bresenham.dy)
		{
			bresenham.err -= bresenham.dy;
			p1.x += bresenham.sx;
		}
		if (bresenham.e2 < bresenham.dx)
		{
			bresenham.err += bresenham.dx;
			p1.y += bresenham.sy;
		}
	}
}
