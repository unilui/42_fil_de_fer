/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:57:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/28 06:02:07 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_info(t_pixel **map, int *columns, int *rows)
{
	t_pixel	*line;

	line = *map;
	while (!line[(*columns)++].eol)
		(*columns)++;
	while (*map++)
		(*rows)++;
}

void	put_coordinates(t_pixel **map, int x_start, int y_start)
{
	t_pixel	*line;
	int		column;
	int		x;

	x = x_start;
	while (*map)
	{
		line = *map;
		column = 0;
		x_start = x;
		while (line)
		{
			line[column].x = x_start;
			line[column].y = y_start;
			if (line[column].eol)
				break ;
			x_start++;
			column++;
		}
		y_start--;
		map++;
	}
}

void	center_axis(t_pixel **map)
{
	int	columns;
	int	rows;
	int	x_start;
	int	y_start;

	columns = 0;
	rows = 0;
	map_info(map, &columns, &rows);
	x_start = -(columns / 2);
	y_start = (rows / 2);
	put_coordinates(map, x_start, y_start);
}

void	render_grid(t_screen *screen)
{
	int	nbr;
	int	nb1;

	nbr = 30;
	nb1 = 90;
	center_axis(screen->map);
	map_iterator(screen->map, &scale, &nbr);
	map_iterator(screen->map, &rotate, &nb1);
	mlx_loop(screen->mlx);
}
