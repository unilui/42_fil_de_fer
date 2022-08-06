/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:28:41 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/05 21:22:53 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_axis_fast(t_bsh *bsh, t_pixel *start, t_pixel *end, t_img *img);
void	y_axis_fast(t_bsh *bsh, t_pixel *start, t_pixel *end, t_img *img);
void	x_axis_pixel(t_bsh *bsh, t_pixel *start, t_img *img);
void	y_axis_pixel(t_bsh *bsh, t_pixel *start, t_img *img);

void	bresenham_line(t_img *img, t_pixel start, t_pixel end)
{
	t_bsh	bsh;

	bsh.dx = end.x - start.x;
	bsh.dy = end.y - start.y;
	bsh.adx = abs(bsh.dx);
	bsh.ady = abs(bsh.dy);
	bsh.sx = -1;
	if (bsh.dx > 0)
		bsh.sx = 1;
	bsh.sy = -1;
	if (bsh.dy > 0)
		bsh.sy = 1;
	bsh.eps = 0;
	if (bsh.adx > bsh.ady)
		x_axis_fast(&bsh, &start, &end, img);
	else
		y_axis_fast(&bsh, &start, &end, img);
}

void	y_axis_fast(t_bsh *bsh, t_pixel *start, t_pixel *end, t_img *img)
{
	if (bsh->sy < 0)
	{
		while (start->y >= end->y)
		{
			y_axis_pixel(bsh, start, img);
			start->y += bsh->sy;
		}
	}
	else
	{
		while (start->y <= end->y)
		{
			y_axis_pixel(bsh, start, img);
			start->y += bsh->sy;
		}
	}
}

void	x_axis_fast(t_bsh *bsh, t_pixel *start, t_pixel *end, t_img *img)
{
	if (bsh->sx < 0)
	{
		while (start->x >= end->x)
		{
			x_axis_pixel(bsh, start, img);
			start->x += bsh->sx;
		}
	}
	else
	{
		while (start->x <= end->x)
		{
			x_axis_pixel(bsh, start, img);
			start->x += bsh->sx;
		}
	}
}

void	y_axis_pixel(t_bsh *bsh, t_pixel *start, t_img *img)
{
	pixel_put(img, start->x, start->y, start->color);
	bsh->eps += bsh->adx;
	if (bsh->eps * 2 >= bsh->ady)
	{
		start->x += bsh->sx;
		bsh->eps -= bsh->ady;
	}
}

void	x_axis_pixel(t_bsh *bsh, t_pixel *start, t_img *img)
{
	pixel_put(img, start->x, start->y, start->color);
	bsh->eps += bsh->ady;
	if (bsh->eps * 2 >= bsh->adx)
	{
		start->y += bsh->sy;
		bsh->eps -= bsh->adx;
	}
}
