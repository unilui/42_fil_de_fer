/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:57:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/24 11:07:14 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_info(t_pixel **map, int *columns, int *rows)
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
			if ((map[y] + x)->eol)
			{
				x++;
				break ;
			}
			x++;
		}
		y++;
	}
	*rows = y;
	*columns = x;
}

void	put_coordinates(t_pixel **map, int x_start, int y_start)
{
	int	line;
	int	column;
	int	x;

	line = 0;
	column = 0;
	x = x_start;
	while(map[line])
	{
		column = 0;
		x_start = x;
		while(map[line] + column)
		{
			(map[line] + column)->x = x_start * 50;
			(map[line] + column)->y = y_start * 30;
			if ((map[line] + column)->eol)
				break ;
			x_start++;
			column++;
		}
		y_start--;
		line++;
	}
}

void	center_axis(t_pixel **map)
{
	int	columns;
	int	rows;
	int	x_start;
	int	y_start;

	map_info(map, &columns, &rows);
	x_start = -(columns / 2);
	y_start = (rows / 2);
	put_coordinates(map, x_start, y_start);
}

void	map_show(t_pixel **map, char selector)
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
			if (selector == 'x')
				printf("%3d", (map[y] + x)->x);
			if (selector == 'y')
				printf("%3d", (map[y] + x)->y);
			if (selector == 'z')
				printf("%3d", (map[y] + x)->z);
			if ((map[y] + x)->eol)
				break ;
			x++;
		}
		printf("\n");
		y++;
	}
}

void	render_grid(t_screen *screen)
{
	center_axis(screen->map);
	mlx_loop(screen->mlx);
}
