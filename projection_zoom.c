/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_zoom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:56:05 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 12:01:11 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(int *x, int *y, int z, t_window *qwe)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(qwe->angle_x);
	*y = ((prev_x + prev_y) * sin(qwe->angle_y)) - z;
}

int	scale(t_window *qwe)
{
	if (qwe->zoom < 1)
		return (1);
	return (qwe->zoom);
}
