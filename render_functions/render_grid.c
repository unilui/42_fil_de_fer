/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:57:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/27 07:58:54 by lufelip2         ###   ########.fr       */
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
	t_pixel *line;
	int		column;
	int		x;

	x = x_start;
	while(*map)
	{
		line = *map;
		column = 0;
		x_start = x;
		while(line)
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

void	map_iterator(t_pixel **map, void (*funct)(t_pixel*, void*), void *args)
{
	t_pixel	*line;
	int		column;

	while (*map)
	{
		line = *map;
		column = 0;
		while (line)
		{
			funct((line + column), args);
			if (line[column].eol)
				break;
			column++;
		}
		map++;
	}
}

void	scale(t_pixel *pixel, void *args)
{
	int	*scale;

	scale = (int *)args;
	pixel->x *= *scale;
	pixel->y *= *scale;
}

void	rotate_90(t_pixel *pixel, void *args)
{
	int	*scale;
	int	x;
	int	y;

	scale = (int *)args;
	x = ((pixel->x * 0) + (pixel->y * -1));
	y = ((pixel->x * 1) + (pixel->y * 0));
	pixel->x = x;
	pixel->y = y;
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
	int nbr;

	nbr = 40;
	center_axis(screen->map);
	map_iterator(screen->map, &scale, &nbr);
	map_iterator(screen->map, &rotate_90, &nbr);
	mlx_loop(screen->mlx);
}
