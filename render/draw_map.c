/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:08:00 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/31 17:08:26 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map(t_img *img, t_pixel **map)
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