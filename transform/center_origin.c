/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_origin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:09:44 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/03 01:38:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_coordinates(t_pixel **map, int x_start, int y_start);

void	center_origin(t_pixel **map)
{
	t_pixel	*line;
	t_pixel	**tmp;
	int	x_start;
	int	y_start;
	
	x_start = 0;
	y_start = 0;
	tmp = map;
	line = *map;
	while (!line[x_start].eol)
		x_start++;
	x_start++;
	while (*tmp++)
		y_start++;
	x_start = -(x_start / 2);
	y_start = (y_start / 2);
	put_coordinates(map, x_start, y_start);
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
