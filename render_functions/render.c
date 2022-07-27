/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:27:39 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/27 07:56:01 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_swap(int *a, int *b)
{
	int	hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

void	bresenham_line(t_img *img, t_pixel start, t_pixel end)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	if (start.x > end.x || start.y > end.y)
	{
		ft_swap(&start.x, &end.x);
		ft_swap(&start.y, &end.y);
	}
	dx = end.x - start.x;
	dy = end.y - start.y;
	x = start.x;
	y = start.y;
	p = 2 * dy - dx;
	img_pixel_put(img, x, y, rgb_encode(255, 140, 190));
	while (x < end.x || y < end.y)
	{
		if (p >= 0)
		{
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			x = x + 1;
			p = p + 2 * dy;
		}
		img_pixel_put(img, x, y, rgb_encode(255, 140, 190));
	}
}

void	render_map(t_img *img, t_pixel **map)
{
	int	line;
	int	column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line] + column)
		{
			if (!(map[line] + column)->eol)
				bresenham_line(img,
					map[line][column],
					map[line][column + 1]);
			if (map[line + 1])
				bresenham_line(img,
					map[line][column],
					map[line + 1][column]);
			if ((map[line] + column)->eol)
				break ;
			column++;
		}
		line++;
	}
}

int	render(t_screen *screen)
{
	render_background(&screen->img, rgb_encode(255, 255, 255));
	render_map(&screen->img, screen->map);
	mlx_put_image_to_window(
		screen->mlx,
		screen->window,
		screen->img.mlx_img, 0, 0);
	return (0);
}
