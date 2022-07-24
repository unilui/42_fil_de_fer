/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:27:39 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/24 11:17:53 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	dda_line(t_img *img, t_pixel start, t_pixel end)
{
	float	slope;
	int		x;
	int		y;

	x = start.x;
	y = start.y;
	slope = 1;
	if (start.x != end.x)
		slope = (end.y - y) / (end.x - x);
	// Tá pulando 1
	if (slope < 1)
	{
		while (x < end.x)
		{
			img_pixel_put(img,
				((WINDOW_WIDTH / 2) + x),
				((WINDOW_HEIGHT / 2) + y),
				rgb_encode(255, 140, 190));
			x += 1;
			y += roundf(slope);
			img_pixel_put(img,
				((WINDOW_WIDTH / 2) + x),
				((WINDOW_HEIGHT / 2) + y),
				rgb_encode(255, 140, 190));
			x++;
		}
	}
	else
		while (y < end.y)
		{
			img_pixel_put(img,
				((WINDOW_WIDTH / 2) + x),
				((WINDOW_HEIGHT / 2) + y),
				rgb_encode(255, 140, 190));
			if (start.x != end.x)
				x += roundf(slope);
			y += 1;
			img_pixel_put(img,
				((WINDOW_WIDTH / 2) + x),
				((WINDOW_HEIGHT / 2) + y),
				rgb_encode(255, 140, 190));
			y++;
		}
}

void	render_map(t_img *img, t_pixel **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while(map[y])
	{
		x = 0;
		while(map[y] + x)
		{
			if (!(map[y] + x)->eol)
				dda_line(img, map[y][x], map[y][x + 1]);
			if (map[y + 1])
				dda_line(img, map[y + 1][x], map[y][x]);
			if ((map[y] + x)->eol)
				break ;
			x++;
		}
		y++;
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