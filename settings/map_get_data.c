/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:11:35 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:50:42 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_count_columns(t_pixel **map);
int	map_count_rows(t_pixel **map);

void	map_get_data(t_screen *screen)
{
	screen->map_info.columns = map_count_columns(screen->map);
	screen->map_info.rows = map_count_rows(screen->map);
	screen->map_info.scale = screen->height / sqrt(
			pow(screen->map_info.columns, 2)
			+ pow(screen->map_info.rows, 2));
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
