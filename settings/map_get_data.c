/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:11:35 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/05 02:33:00 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_get_data(t_screen *screen)
{
	screen->map_info.columns = map_count_columns(screen->map);
	screen->map_info.rows = map_count_rows(screen->map);
	screen->map_info.scale = screen->height / sqrt(
		pow(screen->map_info.columns, 2)
		+ pow(screen->map_info.rows, 2));
}
