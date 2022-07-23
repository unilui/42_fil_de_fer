/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:57:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 10:01:36 by lufelip2         ###   ########.fr       */
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
				break ;
			x++;
		}
		y++;
	}
	*rows = y;
	*columns = ++x;
}

void	render_grid(t_screen *screen)
{
	int	columns;
	int	rows;

	map_info(screen->map, &columns, &rows);
	printf("%d x %d\n", columns, rows);
	mlx_loop(screen->mlx);
}
