/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_origin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:09:44 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/05 02:04:20 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_coordinates(t_pixel **map, int x_start, int y_start);
int	map_count_columns(t_pixel **map);
int	map_count_rows(t_pixel **map);

void	center_origin(t_pixel **map)
{

	int		x_start;
	int		y_start;

	x_start = map_count_columns(map);
	y_start = map_count_rows(map);
	x_start = -(x_start / 2);
	y_start = (y_start / 2);
	put_coordinates(map, x_start, y_start);
}

int	map_count_columns(t_pixel **map)
{
	t_pixel	*line;
	int		x;

	x = 0;
	line = *map;
	while (!line[x].eol)
		x++;
	x++;
	return (x);
}

int	map_count_rows(t_pixel **map)
{
	int		y;

	y = 0;
	while (*map++)
		y++;
	return (y);
}

static void	put_coordinates(t_pixel **map, int x_start, int y_start)
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
