/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:53:56 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 12:17:11 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Funzione per disegnare la linea orizzontale
void	draw_horizont_line(t_drawing_context *ctx, t_point_3 *p1, t_iter iter)
{
	if (iter.j + 1 < ctx->mat->x)
	{
		ft_start_point3(&p1->p2, iter, ctx->scale,
			ctx->mat->mat[iter.i][iter.j + 1]);
		iso_projection(&p1->p2.x, &p1->p2.y, p1->p2.z, ctx->qwe);
		ft_set(&p1->p2, ctx->qwe->offset_x, ctx->qwe->offset_y);
		draw_line(ctx->img, p1->p1, p1->p2, 0x00FFFFFF);
	}
}

// Funzione per disegnare la linea verticale
void	draw_vertical_line(t_drawing_context *ctx, t_point_3 *p1, t_iter iter)
{
	if (ctx->mat->mat[iter.i + 1])
	{
		ft_start_point4(&p1->p3, iter, ctx->scale,
			ctx->mat->mat[iter.i + 1][iter.j]);
		iso_projection(&p1->p3.x, &p1->p3.y, p1->p3.z, ctx->qwe);
		ft_set(&p1->p3, ctx->qwe->offset_x, ctx->qwe->offset_y);
		draw_line(ctx->img, p1->p1, p1->p3, 0x00FFFFFF);
	}
}
