/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:54:50 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 12:00:56 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_start_point(t_point *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	ft_start_point2(t_point *p, t_iter iter, int s, int mat)
{
	p->x = iter.j * s;
	p->y = iter.i * s;
	p->z = mat;
}

void	ft_start_point3(t_point *p, t_iter iter, int s, int mat)
{
	iter.j++;
	p->x = iter.j * s;
	p->y = iter.i * s;
	p->z = mat;
}

void	ft_start_point4(t_point *p, t_iter iter, int s, int mat)
{
	iter.i++;
	p->x = iter.j * s;
	p->y = iter.i * s;
	p->z = mat;
}

void	ft_set(t_point *p, int offset_x, int offset_y)
{
	p->x += offset_x;
	p->y += offset_y;
}
