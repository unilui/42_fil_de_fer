/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_origin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:09:44 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 10:34:17 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_origin(t_pixel **map, int x_start, int y_start)
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
