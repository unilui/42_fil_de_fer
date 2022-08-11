/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:59:47 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 13:07:55 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_map(t_screen *screen, char *file_path)
{
	screen->map = read_map(file_path);
	map_get_data(screen);
	screen->map_view = create_map(
			screen->map_info.rows,
			screen->map_info.columns);
	center_origin(screen->map,
		-(screen->map_info.columns / 2),
		(screen->map_info.rows / 2));
	map_copy(screen->map, screen->map_view);
}
